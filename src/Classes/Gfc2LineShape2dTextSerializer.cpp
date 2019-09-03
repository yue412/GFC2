#include "StdAfx.h"
#include "Gfc2LineShape2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2LineShape2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineShape2dTextSerializer,"Gfc2LineShape2dT",0)

std::string Gfc2LineShape2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineShape2d* pEnt = (Gfc2LineShape2d*)pEntity;
    std::string sResult = Gfc2Shape2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasLine())
        stream<<",#"<<pEnt->getLine();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2LineShape2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2LineShape2d* pEnt = (Gfc2LineShape2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Shape2dTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setLine(value);
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

