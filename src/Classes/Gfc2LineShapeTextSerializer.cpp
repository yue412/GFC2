#include "StdAfx.h"
#include "Gfc2LineShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2LineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineShapeTextSerializer,"Gfc2LineShapeT",0)

std::string Gfc2LineShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineShape* pEnt = (Gfc2LineShape*)pEntity;
    std::string sResult = Gfc2CustomLineShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasTilt())
        stream<<","<<pEnt->getTilt();
    else
        stream<<",$";

    if (pEnt->hasStartPtHeight())
        stream<<","<<pEnt->getStartPtHeight();
    else
        stream<<",$";

    if (pEnt->hasEndPtHeight())
        stream<<","<<pEnt->getEndPtHeight();
    else
        stream<<",$";

    if (pEnt->hasArcInfo())
        stream<<",#"<<pEnt->getArcInfo();
    else
        stream<<",$";

    if (pEnt->hasIsSpiralTop())
        stream<<(pEnt->getIsSpiralTop() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasIsSpiralBtm())
        stream<<(pEnt->getIsSpiralBtm() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2LineShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2LineShape* pEnt = (Gfc2LineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CustomLineShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 8:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTilt(value);
        }
        break;
    case 9:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setStartPtHeight(value);
        }
        break;
    case 10:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setEndPtHeight(value);
        }
        break;
    case 11:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setArcInfo(value);
        }
        break;
    case 12:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setIsSpiralTop(value);
        }
        break;
    case 13:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setIsSpiralBtm(value);
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

