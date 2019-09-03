#include "StdAfx.h"
#include "Gfc2GeometryShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2GeometryShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2GeometryShapeTextSerializer,"Gfc2GeometryShapeT",0)

std::string Gfc2GeometryShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2GeometryShape* pEnt = (Gfc2GeometryShape*)pEntity;
    std::string sResult = Gfc2ShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasGeo())
        stream<<",#"<<pEnt->getGeo();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2GeometryShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2GeometryShape* pEnt = (Gfc2GeometryShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2ShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setGeo(value);
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

