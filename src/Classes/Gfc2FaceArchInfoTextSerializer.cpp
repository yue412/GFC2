#include "StdAfx.h"
#include "Gfc2FaceArchInfoTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceArchInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceArchInfoTextSerializer,"Gfc2FaceArchInfoT",0)

std::string Gfc2FaceArchInfoTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceArchInfo* pEnt = (Gfc2FaceArchInfo*)pEntity;
    std::string sResult = Gfc2FaceInfoTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasAxialLine())
        stream<<",#"<<pEnt->getAxialLine();
    else
        stream<<",$";

    if (pEnt->hasHeight())
        stream<<","<<pEnt->getHeight();
    else
        stream<<",$";

    if (pEnt->hasChord())
        stream<<","<<pEnt->getChord();
    else
        stream<<",$";

    if (pEnt->hasRadius())
        stream<<","<<pEnt->getRadius();
    else
        stream<<",$";

    if (pEnt->hasDefineByRadius())
        stream<<(pEnt->getDefineByRadius() ? ",.T." : ",.F.");
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

glodon::objectbuf::EnParseFieldState Gfc2FaceArchInfoTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceArchInfo* pEnt = (Gfc2FaceArchInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2FaceInfoTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setAxialLine(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setHeight(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setChord(value);
        }
        break;
    case 3:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setRadius(value);
        }
        break;
    case 4:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setDefineByRadius(value);
        }
        break;
    case 5:
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

