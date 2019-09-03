#include "StdAfx.h"
#include "Gfc2ShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Shape.h"

OBJECTBUF_IMP_OBJECT(Gfc2ShapeTextSerializer,"Gfc2ShapeT",0)

std::string Gfc2ShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape* pEnt = (Gfc2Shape*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasLocalCoordinate())
        stream<<",#"<<pEnt->getLocalCoordinate();
    else
        stream<<",$";

    if (pEnt->hasBoundingBox())
        stream<<",#"<<pEnt->getBoundingBox();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2ShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Shape* pEnt = (Gfc2Shape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setLocalCoordinate(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setBoundingBox(value);
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

