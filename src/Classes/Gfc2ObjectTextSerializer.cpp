#include "StdAfx.h"
#include "Gfc2ObjectTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Object.h"

OBJECTBUF_IMP_OBJECT(Gfc2ObjectTextSerializer,"Gfc2ObjectT",0)

std::string Gfc2ObjectTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Object* pEnt = (Gfc2Object*)pEntity;
    std::string sResult = Gfc2RootTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasID())
        stream<<",'"<<pEnt->getID()<<"'";
    else
        stream<<",$";

    if (pEnt->hasName())
        stream<<",#"<<pEnt->getName();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2ObjectTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Object* pEnt = (Gfc2Object*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RootTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Identity value;
            DO_((readStringField(input, value)));
            pEnt->setID(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setName(value);
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

