#include "StdAfx.h"
#include "Gfc2EntityShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2EntityShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2EntityShapeTextSerializer,"Gfc2EntityShapeT",0)

std::string Gfc2EntityShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EntityShape* pEnt = (Gfc2EntityShape*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasIdentifier())
        stream<<",#"<<pEnt->getIdentifier();
    else
        stream<<",$";

    if (pEnt->hasShape())
        stream<<",#"<<pEnt->getShape();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2EntityShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2EntityShape* pEnt = (Gfc2EntityShape*)pEntity;
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
            pEnt->setShape(value);
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

