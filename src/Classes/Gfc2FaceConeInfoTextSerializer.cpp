#include "StdAfx.h"
#include "Gfc2FaceConeInfoTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceConeInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceConeInfoTextSerializer,"Gfc2FaceConeInfoT",0)

std::string Gfc2FaceConeInfoTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceConeInfo* pEnt = (Gfc2FaceConeInfo*)pEntity;
    std::string sResult = Gfc2FaceInfoTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasHeight())
        stream<<","<<pEnt->getHeight();
    else
        stream<<",$";

    if (pEnt->hasChord())
        stream<<","<<pEnt->getChord();
    else
        stream<<",$";

    if (pEnt->hasCenterPoint())
        stream<<",#"<<pEnt->getCenterPoint();
    else
        stream<<",$";

    if (pEnt->hasCheckInnerChord())
        stream<<(pEnt->getCheckInnerChord() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceConeInfoTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceConeInfo* pEnt = (Gfc2FaceConeInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2FaceInfoTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setHeight(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setChord(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setCenterPoint(value);
        }
        break;
    case 3:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setCheckInnerChord(value);
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

