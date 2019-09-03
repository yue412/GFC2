#include "StdAfx.h"
#include "Gfc2RepresentationTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Representation.h"

OBJECTBUF_IMP_OBJECT(Gfc2RepresentationTextSerializer,"Gfc2RepresentationT",0)

std::string Gfc2RepresentationTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Representation* pEnt = (Gfc2Representation*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasIdentifier())
        stream<<",#"<<pEnt->getIdentifier();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getitemsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getitems(i);
            else
                stream<<",#"<<pEnt->getitems(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2RepresentationTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Representation* pEnt = (Gfc2Representation*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->additems(value);
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

