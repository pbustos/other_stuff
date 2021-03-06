//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.3
//
// <auto-generated>
//
// Generated from file `SimpleArm.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <SimpleArm.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 3
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

const ::std::string iceC_RoboCompSimpleArm_SimpleArm_ids[2] =
{
    "::Ice::Object",
    "::RoboCompSimpleArm::SimpleArm"
};
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_ops[] =
{
    "closeFingers",
    "home",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "moveTo",
    "openFingers",
    "stop"
};
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_closeFingers_name = "closeFingers";
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_home_name = "home";
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_moveTo_name = "moveTo";
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_openFingers_name = "openFingers";
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_stop_name = "stop";

}

bool
RoboCompSimpleArm::SimpleArm::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompSimpleArm_SimpleArm_ids, iceC_RoboCompSimpleArm_SimpleArm_ids + 2, s);
}

::std::vector<::std::string>
RoboCompSimpleArm::SimpleArm::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_RoboCompSimpleArm_SimpleArm_ids[0], &iceC_RoboCompSimpleArm_SimpleArm_ids[2]);
}

::std::string
RoboCompSimpleArm::SimpleArm::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompSimpleArm::SimpleArm::ice_staticId()
{
    static const ::std::string typeId = "::RoboCompSimpleArm::SimpleArm";
    return typeId;
}

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_closeFingers(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    float iceP_d;
    istr->readAll(iceP_d);
    inS.endReadParams();
    this->closeFingers(iceP_d, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_home(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    inS.readEmptyParams();
    this->home(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_moveTo(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    Pose6D iceP_pose;
    istr->readAll(iceP_pose);
    inS.endReadParams();
    this->moveTo(::std::move(iceP_pose), current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_openFingers(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    float iceP_d;
    istr->readAll(iceP_d);
    inS.endReadParams();
    this->openFingers(iceP_d, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_stop(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    inS.readEmptyParams();
    this->stop(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompSimpleArm_SimpleArm_ops, iceC_RoboCompSimpleArm_SimpleArm_ops + 9, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompSimpleArm_SimpleArm_ops)
    {
        case 0:
        {
            return _iceD_closeFingers(in, current);
        }
        case 1:
        {
            return _iceD_home(in, current);
        }
        case 2:
        {
            return _iceD_ice_id(in, current);
        }
        case 3:
        {
            return _iceD_ice_ids(in, current);
        }
        case 4:
        {
            return _iceD_ice_isA(in, current);
        }
        case 5:
        {
            return _iceD_ice_ping(in, current);
        }
        case 6:
        {
            return _iceD_moveTo(in, current);
        }
        case 7:
        {
            return _iceD_openFingers(in, current);
        }
        case 8:
        {
            return _iceD_stop(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond INTERNAL
void
RoboCompSimpleArm::SimpleArmPrx::_iceI_closeFingers(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, float iceP_d, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompSimpleArm_SimpleArm_closeFingers_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_d);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompSimpleArm::SimpleArmPrx::_iceI_home(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompSimpleArm_SimpleArm_home_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        nullptr,
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompSimpleArm::SimpleArmPrx::_iceI_moveTo(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const Pose6D& iceP_pose, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompSimpleArm_SimpleArm_moveTo_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_pose);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompSimpleArm::SimpleArmPrx::_iceI_openFingers(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, float iceP_d, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompSimpleArm_SimpleArm_openFingers_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_d);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompSimpleArm::SimpleArmPrx::_iceI_stop(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompSimpleArm_SimpleArm_stop_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        nullptr,
        nullptr);
}
/// \endcond

/// \cond INTERNAL
::std::shared_ptr<::Ice::ObjectPrx>
RoboCompSimpleArm::SimpleArmPrx::_newInstance() const
{
    return ::IceInternal::createProxy<SimpleArmPrx>();
}
/// \endcond

const ::std::string&
RoboCompSimpleArm::SimpleArmPrx::ice_staticId()
{
    return SimpleArm::ice_staticId();
}

namespace Ice
{
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_RoboCompSimpleArm_SimpleArm_closeFingers_name = "closeFingers";

const ::std::string iceC_RoboCompSimpleArm_SimpleArm_home_name = "home";

const ::std::string iceC_RoboCompSimpleArm_SimpleArm_moveTo_name = "moveTo";

const ::std::string iceC_RoboCompSimpleArm_SimpleArm_openFingers_name = "openFingers";

const ::std::string iceC_RoboCompSimpleArm_SimpleArm_stop_name = "stop";

}

/// \cond INTERNAL
::IceProxy::Ice::Object* ::IceProxy::RoboCompSimpleArm::upCast(SimpleArm* p) { return p; }

void
::IceProxy::RoboCompSimpleArm::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< SimpleArm>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new SimpleArm;
        v->_copyFrom(proxy);
    }
}
/// \endcond

::Ice::AsyncResultPtr
IceProxy::RoboCompSimpleArm::SimpleArm::_iceI_begin_closeFingers(::Ice::Float iceP_d, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompSimpleArm_SimpleArm_closeFingers_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompSimpleArm_SimpleArm_closeFingers_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_d);
        result->endWriteParams();
        result->invoke(iceC_RoboCompSimpleArm_SimpleArm_closeFingers_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompSimpleArm::SimpleArm::end_closeFingers(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompSimpleArm_SimpleArm_closeFingers_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompSimpleArm::SimpleArm::_iceI_begin_home(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompSimpleArm_SimpleArm_home_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompSimpleArm_SimpleArm_home_name, ::Ice::Normal, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompSimpleArm_SimpleArm_home_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompSimpleArm::SimpleArm::end_home(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompSimpleArm_SimpleArm_home_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompSimpleArm::SimpleArm::_iceI_begin_moveTo(const ::RoboCompSimpleArm::Pose6D& iceP_pose, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompSimpleArm_SimpleArm_moveTo_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompSimpleArm_SimpleArm_moveTo_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_pose);
        result->endWriteParams();
        result->invoke(iceC_RoboCompSimpleArm_SimpleArm_moveTo_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompSimpleArm::SimpleArm::end_moveTo(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompSimpleArm_SimpleArm_moveTo_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompSimpleArm::SimpleArm::_iceI_begin_openFingers(::Ice::Float iceP_d, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompSimpleArm_SimpleArm_openFingers_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompSimpleArm_SimpleArm_openFingers_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_d);
        result->endWriteParams();
        result->invoke(iceC_RoboCompSimpleArm_SimpleArm_openFingers_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompSimpleArm::SimpleArm::end_openFingers(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompSimpleArm_SimpleArm_openFingers_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompSimpleArm::SimpleArm::_iceI_begin_stop(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompSimpleArm_SimpleArm_stop_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompSimpleArm_SimpleArm_stop_name, ::Ice::Normal, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompSimpleArm_SimpleArm_stop_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompSimpleArm::SimpleArm::end_stop(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompSimpleArm_SimpleArm_stop_name);
}

/// \cond INTERNAL
::IceProxy::Ice::Object*
IceProxy::RoboCompSimpleArm::SimpleArm::_newInstance() const
{
    return new SimpleArm;
}
/// \endcond

const ::std::string&
IceProxy::RoboCompSimpleArm::SimpleArm::ice_staticId()
{
    return ::RoboCompSimpleArm::SimpleArm::ice_staticId();
}

RoboCompSimpleArm::SimpleArm::~SimpleArm()
{
}

/// \cond INTERNAL
::Ice::Object* RoboCompSimpleArm::upCast(SimpleArm* p) { return p; }

/// \endcond

namespace
{
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_ids[2] =
{
    "::Ice::Object",
    "::RoboCompSimpleArm::SimpleArm"
};

}

bool
RoboCompSimpleArm::SimpleArm::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompSimpleArm_SimpleArm_ids, iceC_RoboCompSimpleArm_SimpleArm_ids + 2, s);
}

::std::vector< ::std::string>
RoboCompSimpleArm::SimpleArm::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_RoboCompSimpleArm_SimpleArm_ids[0], &iceC_RoboCompSimpleArm_SimpleArm_ids[2]);
}

const ::std::string&
RoboCompSimpleArm::SimpleArm::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompSimpleArm::SimpleArm::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::RoboCompSimpleArm::SimpleArm";
    return typeId;
#else
    return iceC_RoboCompSimpleArm_SimpleArm_ids[1];
#endif
}

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_closeFingers(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Float iceP_d;
    istr->read(iceP_d);
    inS.endReadParams();
    this->closeFingers(iceP_d, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_home(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    inS.readEmptyParams();
    this->home(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_moveTo(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    Pose6D iceP_pose;
    istr->read(iceP_pose);
    inS.endReadParams();
    this->moveTo(iceP_pose, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_openFingers(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Float iceP_d;
    istr->read(iceP_d);
    inS.endReadParams();
    this->openFingers(iceP_d, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceD_stop(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    inS.readEmptyParams();
    this->stop(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

namespace
{
const ::std::string iceC_RoboCompSimpleArm_SimpleArm_all[] =
{
    "closeFingers",
    "home",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "moveTo",
    "openFingers",
    "stop"
};

}

/// \cond INTERNAL
bool
RoboCompSimpleArm::SimpleArm::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompSimpleArm_SimpleArm_all, iceC_RoboCompSimpleArm_SimpleArm_all + 9, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompSimpleArm_SimpleArm_all)
    {
        case 0:
        {
            return _iceD_closeFingers(in, current);
        }
        case 1:
        {
            return _iceD_home(in, current);
        }
        case 2:
        {
            return _iceD_ice_id(in, current);
        }
        case 3:
        {
            return _iceD_ice_ids(in, current);
        }
        case 4:
        {
            return _iceD_ice_isA(in, current);
        }
        case 5:
        {
            return _iceD_ice_ping(in, current);
        }
        case 6:
        {
            return _iceD_moveTo(in, current);
        }
        case 7:
        {
            return _iceD_openFingers(in, current);
        }
        case 8:
        {
            return _iceD_stop(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond STREAM
void
RoboCompSimpleArm::SimpleArm::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    ::Ice::StreamWriter< SimpleArm, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
RoboCompSimpleArm::SimpleArm::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< SimpleArm, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
void
RoboCompSimpleArm::_icePatchObjectPtr(SimpleArmPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = SimpleArmPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(SimpleArm::ice_staticId(), v);
    }
}
/// \endcond

namespace Ice
{
}

#endif
