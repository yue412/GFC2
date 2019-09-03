#include "StdAfx.h"
#include "Gfc2BooleanPropertyTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2BooleanProperty.h"

OBJECTBUF_IMP_OBJECT(Gfc2BooleanPropertyTextSerializer,"Gfc2BooleanPropertyT",0)

std::string Gfc2BooleanPropertyTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BooleanProperty* pEnt = (Gfc2BooleanProperty*)pEntity;
    std::string sResult = Gfc2PropertyTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasValue())
        stream<<(pEnt->getValue() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2BooleanPropertyTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2BooleanProperty* pEnt = (Gfc2BooleanProperty*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PropertyTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 1:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
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

