#include "StdAfx.h"
#include "Gfc2VariableSectionLineShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2VariableSectionLineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2VariableSectionLineShapeTextSerializer,"Gfc2VariableSectionLineShapeT",0)

std::string Gfc2VariableSectionLineShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2VariableSectionLineShape* pEnt = (Gfc2VariableSectionLineShape*)pEntity;
    std::string sResult = Gfc2SectionLineShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasEndPoly())
        stream<<",#"<<pEnt->getEndPoly();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2VariableSectionLineShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2VariableSectionLineShape* pEnt = (Gfc2VariableSectionLineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SectionLineShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 14:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setEndPoly(value);
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

