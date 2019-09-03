#include "StdAfx.h"
#include "Gfc2RelDefinesByPropertiesTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2RelDefinesByProperties.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByPropertiesTextSerializer,"Gfc2RelDefinesByPropertiesT",0)

std::string Gfc2RelDefinesByPropertiesTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByProperties* pEnt = (Gfc2RelDefinesByProperties*)pEntity;
    std::string sResult = Gfc2RelDefinesTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRelatingPropertySet())
        stream<<",#"<<pEnt->getRelatingPropertySet();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2RelDefinesByPropertiesTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RelDefinesByProperties* pEnt = (Gfc2RelDefinesByProperties*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RelDefinesTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRelatingPropertySet(value);
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

