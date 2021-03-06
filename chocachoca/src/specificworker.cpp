/*
 *    Copyright (C)2018 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(TuplePrx tprx) : GenericWorker(tprx)
{
	std::cout << std::boolalpha;   
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
	std::cout << "Destroying SpecificWorker" << std::endl;
	emit computetofinalize();
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{
	try
	{
		RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
		innerModel = std::make_shared<InnerModel>(par.value);
		int xmin = std::stoi(params.at("xmin").value);
		int xmax = std::stoi(params.at("xmax").value);
		int ymin = std::stoi(params.at("ymin").value);
		int ymax = std::stoi(params.at("ymax").value);
		tilesize = std::stoi(params.at("tilesize").value);

		qDebug() << __FILE__ ;
	
		// Scene
		//scene.setSceneRect(-12000, -6000, 38000, 16000);
		scene.setSceneRect(xmin, ymin, fabs(xmin)+fabs(xmax), fabs(ymin)+fabs(ymax));
		view.setScene(&scene);
		view.scale(1, -1);
		view.setParent(scrollArea);
		//view.setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
		view.fitInView(scene.sceneRect(), Qt::KeepAspectRatio );

		//grid.initialize( TDim{ tilesize, -12000, 25000, -6000, 10000}, TCell{0, true, false, nullptr, 0.} );
		grid.initialize( TDim{ tilesize, xmin, xmax, ymin, ymax}, TCell{0, true, false, nullptr, 0.} );
		
		for(auto &[key, value] : grid)
		{
			auto tile = scene.addRect(-tilesize/2,-tilesize/2, 100,100, QPen(Qt::NoPen));
			tile->setPos(key.x,key.z);
			value.rect = tile;
		}

		robot = scene.addRect(QRectF(-200, -200, 400, 400), QPen(), QBrush(Qt::blue));
		noserobot = new QGraphicsEllipseItem(-50,100, 100,100, robot);
		noserobot->setBrush(Qt::magenta);

		target = QVec::vec3(0,0,0);
		
		//qDebug() << __FILE__ << __FUNCTION__ << "CPP " << __cplusplus;
		
		connect(buttonSave, SIGNAL(clicked()), this, SLOT(saveToFile()));
		connect(buttonRead, SIGNAL(clicked()), this, SLOT(readFromFile()));
		
		view.show();

		defaultMachine.start();
		
		return true;
	}
	catch(const std::exception &e) { qFatal("Error reading config params"); }
}

void SpecificWorker::initialize(int period)
{
    std::cout << "Initialize worker" << std::endl;
	this->Period = period;
	timer.start(Period);
	emit this->initializetocompute();
}

void SpecificWorker::sm_compute()
{
	std::cout<<"Entered state compute"<<std::endl;
	compute();
}

void SpecificWorker::sm_initialize()
{
	std::cout<<"Entered initial state initialize"<<std::endl;
}

void SpecificWorker::sm_finalize()
{
	std::cout<<"Entered final state finalize"<<std::endl;
}

void SpecificWorker::compute()
{
	static RoboCompGenericBase::TBaseState bState;
 	try
 	{
 		differentialrobot_proxy->getBaseState(bState);
		innerModel->updateTransformValues("base", bState.x, 0, bState.z, 0, bState.alpha, 0);
		RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData();
		
		//draw robot
		robot->setPos(bState.x, bState.z);
		robot->setRotation(-180.*bState.alpha/M_PI);
		
		//updateVisitedCells(bState.x, bState.z);
		updateOccupiedCells(bState, ldata);
		
		if(targetReady)
		{
			if(planReady)
			{
				if(path.empty())
				{
					qDebug() << "Arrived to target";
					targetReady = false; 
				}
				else
						if((QVec::vec2(bState.x, bState.z) - currentPoint).norm2() < 50)
						{
							currentPoint = path.front();
							path.pop_front();
						}
						else
						{
							//GOTO Point
						}
			}
			else
			{
				qDebug() << bState.x << bState.z << target.x() << target.z() ;
				path = grid.getOptimalPath(QVec::vec3(bState.x,0,bState.z), target);
				for(auto &p: path)
					greenPath.push_back(scene.addEllipse(p.x(),p.z(), 100, 100, QPen(Qt::green), QBrush(Qt::green)));
				planReady = true;
			}
		}
	}
 	catch(const Ice::Exception &e)
	{	std::cout  << e << std::endl; }
	
	//Resize world widget if necessary, and render the world
	if (view.size() != scrollArea->size())
			view.setFixedSize(scrollArea->width(), scrollArea->height());
	//draw();
	
}

void SpecificWorker::saveToFile()
{
	grid.saveToFile(fileName);
}

void SpecificWorker::readFromFile()
{
	std::ifstream myfile;
	myfile.open(fileName, std::ifstream::in);
	
	if(!myfile.fail())
	{
		//grid.initialize( TDim{ tilesize, -2500, 2500, -2500, 2500}, TCell{true, false, nullptr} );
		for( auto &[k,v] : grid)
			delete v.rect;
		grid.clear();
		Grid<TCell>::Key key; 
		TCell value;
		int libres= 0;
		int k=0;
		while(!myfile.eof()) 
		{
			myfile >> key >> value;
			auto tile = scene.addRect(-tilesize/2,-tilesize/2, 100,100, QPen(Qt::NoPen));;
			tile->setPos(key.x,key.z);
			value.rect = tile;
			value.id = k;
			value.cost = 1;
			if(value.free) 
				libres++;
			grid.insert<TCell>(key,value);
			k++;
		}
		myfile.close();	
		robot->setZValue(1);
		std::cout << grid.size() << " elements read to grid " << "frees " << libres << " " << fileName << std::endl;
	}
	else
		throw std::runtime_error("Cannot open file");
}

void SpecificWorker::checkTransform(const RoboCompGenericBase::TBaseState &bState)
{
	auto r = innerModel->transform("base", target, "world");		// using InnerModel
	
	Rot2D rot(bState.alpha);																		// create a 2D clockwise rotation matrix
	QVec t = QVec::vec2(bState.x, bState.z);									  // create a 2D vector for robot translation
	QVec t2 = QVec::vec2(target.x(), target.z());								// create a 2D vector from the 3D target
	QVec q = rot.transpose() * ( t2 - t);												// multiply R_t * (y - T)
	qDebug() << target << r << q;
}

void SpecificWorker::updateOccupiedCells(const RoboCompGenericBase::TBaseState &bState, const RoboCompLaser::TLaserData &ldata)
{
	InnerModelLaser *n = innerModel->getNode<InnerModelLaser>(QString("laser"));
	for(auto l: ldata)
	{
		auto r = n->laserTo(QString("world"), l.dist, l.angle);	// r is in world reference system
		// we set the cell corresponding to r as occupied 
		auto [valid, cell] = grid.getCell(r.x(), r.z()); 
		if(valid)
		{
			cell.free = false;
			cell.rect->setBrush(Qt::darkRed);
		}
	}
}

void SpecificWorker::updateVisitedCells(int x, int z)
{
	static unsigned int cont = 0;
	auto [valid, cell] = grid.getCell(x, z); 
	if(valid)
	{
		auto &occupied = cell.visited;
		if(occupied)
		{
			occupied = false;
			cont++;
		}
		float percentOccupacy = 100. * cont / grid.size();
	}
}

void SpecificWorker::draw()
{
	for(auto &[key, value] : grid)
	{
// 		if(value.visited == false)
// 			value.rect->setBrush(Qt::lightGray);
		if(value.free == false)
			value.rect->setBrush(Qt::darkRed);
	}
	view.show();
}

/////////////// PATH PLANNING /////7




/////////////////////////////////////////////////////////77
/////////
//////////////////////////////////////////////////////////

void SpecificWorker::RCISMousePicker_setPick(Pick myPick)
{
	target[0] = myPick.x;
	target[2] = myPick.z;
	target[1] = 0;
	qDebug() << __FILE__ << __FUNCTION__ << myPick.x << myPick.z ;
	targetReady = true;
	planReady = false;
	for(auto gp: greenPath)
		delete gp;
	greenPath.clear();
	
}
