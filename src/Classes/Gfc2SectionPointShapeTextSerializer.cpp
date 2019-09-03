#include "StdAfx.h"
#include "Gfc2SectionPointShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SectionPointShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2SectionPointShapeTextSerializer,"Gfc2SectionPointShapeT",0)

std::string Gfc2SectionPointShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionPointShape* pEnt = (Gfc2SectionPointShape*)pEntity;
    std::string sResult = Gfc2CustomPointShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPoly())
        stream<<",#"<<pEnt->getPoly();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SectionPointShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SectionPointShape* pEnt = (Gfc2SectionPointShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CustomPointShapeTextSerializer::parseField(input, nFieldNum, pEnt);
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
    default:
        return glodon::objectbuf::PFS_IGNORE;
    }
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

