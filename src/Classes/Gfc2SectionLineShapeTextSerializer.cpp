#include "StdAfx.h"
#include "Gfc2SectionLineShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SectionLineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2SectionLineShapeTextSerializer,"Gfc2SectionLineShapeT",0)

std::string Gfc2SectionLineShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionLineShape* pEnt = (Gfc2SectionLineShape*)pEntity;
    std::string sResult = Gfc2CustomLineShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPoly())
        stream<<",#"<<pEnt->getPoly();
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

    if (pEnt->hasArcInfo())
        stream<<",#"<<pEnt->getArcInfo();
    else
        stream<<",$";

    if (pEnt->hasIsSpiral())
        stream<<(pEnt->getIsSpiral() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SectionLineShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SectionLineShape* pEnt = (Gfc2SectionLineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CustomLineShapeTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setPoly(value);
        }
        break;
    case 9:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setBaseInsertPt(value);
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
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setMirrorFlag(value);
        }
        break;
    case 12:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setArcInfo(value);
        }
        break;
    case 13:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setIsSpiral(value);
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

