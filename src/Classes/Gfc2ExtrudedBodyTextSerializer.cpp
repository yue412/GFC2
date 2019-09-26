#include "StdAfx.h"
#include "Gfc2ExtrudedBodyTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2ExtrudedBody.h"

OBJECTBUF_IMP_OBJECT(Gfc2ExtrudedBodyTextSerializer,"Gfc2ExtrudedBodyT",0)

std::string Gfc2ExtrudedBodyTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ExtrudedBody* pEnt = (Gfc2ExtrudedBody*)pEntity;
    std::string sResult = Gfc2PrimitiveBodyTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCoordinate())
        stream<<",#"<<pEnt->getCoordinate();
    else
        stream<<",$";

    if (pEnt->hasLength())
        stream<<","<<pEnt->getLength();
    else
        stream<<",$";

    if (pEnt->hasSection())
        stream<<",#"<<pEnt->getSection();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2ExtrudedBodyTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ExtrudedBody* pEnt = (Gfc2ExtrudedBody*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PrimitiveBodyTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setCoordinate(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setLength(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setSection(value);
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

