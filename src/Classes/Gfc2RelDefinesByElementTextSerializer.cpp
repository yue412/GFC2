#include "StdAfx.h"
#include "Gfc2RelDefinesByElementTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2RelDefinesByElement.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByElementTextSerializer,"Gfc2RelDefinesByElementT",0)

std::string Gfc2RelDefinesByElementTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByElement* pEnt = (Gfc2RelDefinesByElement*)pEntity;
    std::string sResult = Gfc2RelDefinesTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRelatingElement())
        stream<<",#"<<pEnt->getRelatingElement();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2RelDefinesByElementTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RelDefinesByElement* pEnt = (Gfc2RelDefinesByElement*)pEntity;
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
            pEnt->setRelatingElement(value);
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

