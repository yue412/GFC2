#include "StdAfx.h"
#include "Gfc2CustomPointShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CustomPointShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2CustomPointShapeTextSerializer,"Gfc2CustomPointShapeT",0)

std::string Gfc2CustomPointShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomPointShape* pEnt = (Gfc2CustomPointShape*)pEntity;
    std::string sResult = Gfc2SolidShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasInsertPt())
        stream<<",#"<<pEnt->getInsertPt();
    else
        stream<<",$";

    if (pEnt->hasBaseInsertPt())
        stream<<",#"<<pEnt->getBaseInsertPt();
    else
        stream<<",$";

    if (pEnt->hasAngle())
        stream<<","<<pEnt->getAngle();
    else
        stream<<",$";

    if (pEnt->hasMirrorFlag())
        stream<<(pEnt->getMirrorFlag() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CustomPointShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CustomPointShape* pEnt = (Gfc2CustomPointShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SolidShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setInsertPt(value);
        }
        break;
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setBaseInsertPt(value);
        }
        break;
    case 6:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setAngle(value);
        }
        break;
    case 7:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setMirrorFlag(value);
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

