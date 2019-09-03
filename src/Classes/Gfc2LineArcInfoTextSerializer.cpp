#include "StdAfx.h"
#include "Gfc2LineArcInfoTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2LineArcInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineArcInfoTextSerializer,"Gfc2LineArcInfoT",0)

std::string Gfc2LineArcInfoTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineArcInfo* pEnt = (Gfc2LineArcInfo*)pEntity;
    std::string sResult = Gfc2BaseLineArcInfoTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasBasePoint())
        stream<<",#"<<pEnt->getBasePoint();
    else
        stream<<",$";

    if (pEnt->hasArchHeight())
        stream<<","<<pEnt->getArchHeight();
    else
        stream<<",$";

    if (pEnt->hasHalfChordLength())
        stream<<","<<pEnt->getHalfChordLength();
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

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2LineArcInfoTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2LineArcInfo* pEnt = (Gfc2LineArcInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2BaseLineArcInfoTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setBasePoint(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setArchHeight(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setHalfChordLength(value);
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
    default:
        return glodon::objectbuf::PFS_IGNORE;
    }
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

