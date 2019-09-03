#include "StdAfx.h"
#include "Gfc2IntervaldTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Intervald.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntervaldTextSerializer,"Gfc2IntervaldT",0)

std::string Gfc2IntervaldTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Intervald* pEnt = (Gfc2Intervald*)pEntity;
    std::string sResult = Gfc2GeometryTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasMin())
        stream<<","<<pEnt->getMin();
    else
        stream<<",$";

    if (pEnt->hasMax())
        stream<<","<<pEnt->getMax();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2IntervaldTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Intervald* pEnt = (Gfc2Intervald*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setMin(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setMax(value);
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

