#include "StdAfx.h"
#include "Gfc2SweepTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Sweep.h"

OBJECTBUF_IMP_OBJECT(Gfc2SweepTextSerializer,"Gfc2SweepT",0)

std::string Gfc2SweepTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sweep* pEnt = (Gfc2Sweep*)pEntity;
    std::string sResult = Gfc2SurfaceTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasProfile())
        stream<<",#"<<pEnt->getProfile();
    else
        stream<<",$";

    if (pEnt->hasSpine3d())
        stream<<",#"<<pEnt->getSpine3d();
    else
        stream<<",$";

    if (pEnt->hasReferenceVector())
        stream<<",#"<<pEnt->getReferenceVector();
    else
        stream<<",$";

    if (pEnt->hasSweepType())
        stream<<","<<Gfc2SweepTypeToString(pEnt->getSweepType());
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SweepTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Sweep* pEnt = (Gfc2Sweep*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setProfile(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setSpine3d(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setReferenceVector(value);
        }
        break;
    case 3:
        {
            Gfc2SweepType value;
            DO_((StringToGfc2SweepType(input, value)));
            pEnt->setSweepType(value);
        }
        break;
    default:
        return glodon::objectbuf::PFS_IGNORE;
    }
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

