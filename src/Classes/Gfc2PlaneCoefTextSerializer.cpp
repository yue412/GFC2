#include "StdAfx.h"
#include "Gfc2PlaneCoefTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PlaneCoef.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneCoefTextSerializer,"Gfc2PlaneCoefT",0)

std::string Gfc2PlaneCoefTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneCoef* pEnt = (Gfc2PlaneCoef*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasA())
        stream<<","<<pEnt->getA();
    else
        stream<<",$";

    if (pEnt->hasB())
        stream<<","<<pEnt->getB();
    else
        stream<<",$";

    if (pEnt->hasC())
        stream<<","<<pEnt->getC();
    else
        stream<<",$";

    if (pEnt->hasD())
        stream<<","<<pEnt->getD();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PlaneCoefTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PlaneCoef* pEnt = (Gfc2PlaneCoef*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setA(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setB(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setC(value);
        }
        break;
    case 3:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setD(value);
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

