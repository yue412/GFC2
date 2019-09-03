#include "StdAfx.h"
#include "Gfc2RelDecomposesTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2RelDecomposes.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDecomposesTextSerializer,"Gfc2RelDecomposesT",0)

std::string Gfc2RelDecomposesTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDecomposes* pEnt = (Gfc2RelDecomposes*)pEntity;
    std::string sResult = Gfc2RelationShipTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRelatingObject())
        stream<<",#"<<pEnt->getRelatingObject();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getRelatedObjectsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getRelatedObjects(i);
            else
                stream<<",#"<<pEnt->getRelatedObjects(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2RelDecomposesTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RelDecomposes* pEnt = (Gfc2RelDecomposes*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RelationShipTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setRelatingObject(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addRelatedObjects(value);
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

