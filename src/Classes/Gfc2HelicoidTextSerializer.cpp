#include "StdAfx.h"
#include "Gfc2HelicoidTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Helicoid.h"

OBJECTBUF_IMP_OBJECT(Gfc2HelicoidTextSerializer,"Gfc2HelicoidT",0)

std::string Gfc2HelicoidTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Helicoid* pEnt = (Gfc2Helicoid*)pEntity;
    std::string sResult = Gfc2SurfaceTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCoord())
        stream<<",#"<<pEnt->getCoord();
    else
        stream<<",$";

    if (pEnt->hasRadius())
        stream<<","<<pEnt->getRadius();
    else
        stream<<",$";

    if (pEnt->hasRangeV())
        stream<<",#"<<pEnt->getRangeV();
    else
        stream<<",$";

    if (pEnt->hasClockSign())
        stream<<","<<pEnt->getClockSign();
    else
        stream<<",$";

    if (pEnt->hasHeightCoef())
        stream<<","<<pEnt->getHeightCoef();
    else
        stream<<",$";

    if (pEnt->hasRadiusCoef())
        stream<<","<<pEnt->getRadiusCoef();
    else
        stream<<",$";

    if (pEnt->hasCurve())
        stream<<",#"<<pEnt->getCurve();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2HelicoidTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Helicoid* pEnt = (Gfc2Helicoid*)pEntity;
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
            pEnt->setCoord(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setRadius(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRangeV(value);
        }
        break;
    case 3:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setClockSign(value);
        }
        break;
    case 4:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setHeightCoef(value);
        }
        break;
    case 5:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setRadiusCoef(value);
        }
        break;
    case 6:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setCurve(value);
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

