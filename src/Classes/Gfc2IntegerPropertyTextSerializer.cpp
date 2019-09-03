#include "StdAfx.h"
#include "Gfc2IntegerPropertyTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2IntegerProperty.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntegerPropertyTextSerializer,"Gfc2IntegerPropertyT",0)

std::string Gfc2IntegerPropertyTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntegerProperty* pEnt = (Gfc2IntegerProperty*)pEntity;
    std::string sResult = Gfc2PropertyTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasValue())
        stream<<","<<pEnt->getValue();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2IntegerPropertyTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2IntegerProperty* pEnt = (Gfc2IntegerProperty*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PropertyTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
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

