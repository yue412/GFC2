#include "StdAfx.h"
#include "Gfc2StringTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2String.h"

OBJECTBUF_IMP_OBJECT(Gfc2StringTextSerializer,"Gfc2StringT",0)

std::string Gfc2StringTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2String* pEnt = (Gfc2String*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasValue())
        stream<<",'"<<pEnt->getValue()<<"'";
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2StringTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2String* pEnt = (Gfc2String*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            std::string value;
            DO_((readStringField(input, value)));
            pEnt->setValue(value);
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

