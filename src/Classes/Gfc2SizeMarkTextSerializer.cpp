#include "StdAfx.h"
#include "Gfc2SizeMarkTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SizeMark.h"

OBJECTBUF_IMP_OBJECT(Gfc2SizeMarkTextSerializer,"Gfc2SizeMarkT",0)

std::string Gfc2SizeMarkTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SizeMark* pEnt = (Gfc2SizeMark*)pEntity;
    std::string sResult = Gfc2EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasSizeMarkType())
        stream<<","<<Gfc2SizeMarkTypeToString(pEnt->getSizeMarkType());
    else
        stream<<",$";

    if (pEnt->hasStartLine())
        stream<<",#"<<pEnt->getStartLine();
    else
        stream<<",$";

    if (pEnt->hasEndLine())
        stream<<",#"<<pEnt->getEndLine();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SizeMarkTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SizeMark* pEnt = (Gfc2SizeMark*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2EntityTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 5:
        {
            Gfc2SizeMarkType value;
            DO_((StringToGfc2SizeMarkType(input, value)));
            pEnt->setSizeMarkType(value);
        }
        break;
    case 6:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setStartLine(value);
        }
        break;
    case 7:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setEndLine(value);
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

