#include "StdAfx.h"
#include "Gfc2Vector2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Vector2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Vector2dTextSerializer,"Gfc2Vector2dT",0)

std::string Gfc2Vector2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Vector2d* pEnt = (Gfc2Vector2d*)pEntity;
    std::string sResult = Gfc2GeometryTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasX())
        stream<<","<<pEnt->getX();
    else
        stream<<",$";

    if (pEnt->hasY())
        stream<<","<<pEnt->getY();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2Vector2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Vector2d* pEnt = (Gfc2Vector2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setX(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setY(value);
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

