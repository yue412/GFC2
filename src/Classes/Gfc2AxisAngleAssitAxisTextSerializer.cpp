#include "StdAfx.h"
#include "Gfc2AxisAngleAssitAxisTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2AxisAngleAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2AxisAngleAssitAxisTextSerializer,"Gfc2AxisAngleAssitAxisT",0)

std::string Gfc2AxisAngleAssitAxisTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisAngleAssitAxis* pEnt = (Gfc2AxisAngleAssitAxis*)pEntity;
    std::string sResult = Gfc2AssitAxisTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRefAxisNo())
        stream<<",#"<<pEnt->getRefAxisNo();
    else
        stream<<",$";

    if (pEnt->hasRefPoint())
        stream<<",#"<<pEnt->getRefPoint();
    else
        stream<<",$";

    if (pEnt->hasAngle())
        stream<<","<<pEnt->getAngle();
    else
        stream<<",$";

    if (pEnt->hasRefAxisIndex())
        stream<<","<<pEnt->getRefAxisIndex();
    else
        stream<<",$";

    if (pEnt->hasRefAxisType())
        stream<<","<<Gfc2AxisTypeToString(pEnt->getRefAxisType());
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2AxisAngleAssitAxisTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AxisAngleAssitAxis* pEnt = (Gfc2AxisAngleAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 8:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRefAxisNo(value);
        }
        break;
    case 9:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRefPoint(value);
        }
        break;
    case 10:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setAngle(value);
        }
        break;
    case 11:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setRefAxisIndex(value);
        }
        break;
    case 12:
        {
            Gfc2AxisType value;
            DO_((StringToGfc2AxisType(input, value)));
            pEnt->setRefAxisType(value);
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

