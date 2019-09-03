#include "StdAfx.h"
#include "Gfc2ParallelAssitAxisTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2ParallelAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2ParallelAssitAxisTextSerializer,"Gfc2ParallelAssitAxisT",0)

std::string Gfc2ParallelAssitAxisTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ParallelAssitAxis* pEnt = (Gfc2ParallelAssitAxis*)pEntity;
    std::string sResult = Gfc2AssitAxisTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRefAxisNo())
        stream<<",#"<<pEnt->getRefAxisNo();
    else
        stream<<",$";

    if (pEnt->hasOffset())
        stream<<","<<pEnt->getOffset();
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

glodon::objectbuf::EnParseFieldState Gfc2ParallelAssitAxisTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ParallelAssitAxis* pEnt = (Gfc2ParallelAssitAxis*)pEntity;
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
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setOffset(value);
        }
        break;
    case 10:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setRefAxisIndex(value);
        }
        break;
    case 11:
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

