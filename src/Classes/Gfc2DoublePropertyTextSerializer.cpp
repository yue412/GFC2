#include "StdAfx.h"
#include "Gfc2DoublePropertyTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2DoubleProperty.h"

OBJECTBUF_IMP_OBJECT(Gfc2DoublePropertyTextSerializer,"Gfc2DoublePropertyT",0)

std::string Gfc2DoublePropertyTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2DoubleProperty* pEnt = (Gfc2DoubleProperty*)pEntity;
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

glodon::objectbuf::EnParseFieldState Gfc2DoublePropertyTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2DoubleProperty* pEnt = (Gfc2DoubleProperty*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PropertyTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
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

