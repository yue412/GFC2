#include "StdAfx.h"
#include "Gfc2PropertySetTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PropertySet.h"

OBJECTBUF_IMP_OBJECT(Gfc2PropertySetTextSerializer,"Gfc2PropertySetT",0)

std::string Gfc2PropertySetTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PropertySet* pEnt = (Gfc2PropertySet*)pEntity;
    std::string sResult = Gfc2RootTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasIdentifier())
        stream<<",#"<<pEnt->getIdentifier();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getHasPropertiesCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getHasProperties(i);
            else
                stream<<",#"<<pEnt->getHasProperties(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PropertySetTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PropertySet* pEnt = (Gfc2PropertySet*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RootTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setIdentifier(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addHasProperties(value);
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

