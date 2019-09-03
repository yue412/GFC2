#include "StdAfx.h"
#include "Gfc2CircleAssitAxisTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CircleAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2CircleAssitAxisTextSerializer,"Gfc2CircleAssitAxisT",0)

std::string Gfc2CircleAssitAxisTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CircleAssitAxis* pEnt = (Gfc2CircleAssitAxis*)pEntity;
    std::string sResult = Gfc2AssitAxisTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCenter())
        stream<<",#"<<pEnt->getCenter();
    else
        stream<<",$";

    if (pEnt->hasRadius())
        stream<<","<<pEnt->getRadius();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CircleAssitAxisTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CircleAssitAxis* pEnt = (Gfc2CircleAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 8:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setCenter(value);
        }
        break;
    case 9:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setRadius(value);
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

