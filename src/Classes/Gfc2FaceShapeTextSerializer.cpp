#include "StdAfx.h"
#include "Gfc2FaceShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceShapeTextSerializer,"Gfc2FaceShapeT",0)

std::string Gfc2FaceShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape* pEnt = (Gfc2FaceShape*)pEntity;
    std::string sResult = Gfc2SolidShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasThickness())
        stream<<","<<pEnt->getThickness();
    else
        stream<<",$";

    if (pEnt->hasPoly())
        stream<<",#"<<pEnt->getPoly();
    else
        stream<<",$";

    if (pEnt->hasMirrorFlag())
        stream<<(pEnt->getMirrorFlag() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasFaceInfo())
        stream<<",#"<<pEnt->getFaceInfo();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceShape* pEnt = (Gfc2FaceShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SolidShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 4:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setThickness(value);
        }
        break;
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setPoly(value);
        }
        break;
    case 6:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setMirrorFlag(value);
        }
        break;
    case 7:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setFaceInfo(value);
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

