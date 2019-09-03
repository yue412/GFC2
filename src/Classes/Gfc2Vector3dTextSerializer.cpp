#include "StdAfx.h"
#include "Gfc2Vector3dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Vector3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Vector3dTextSerializer,"Gfc2Vector3dT",0)

std::string Gfc2Vector3dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Vector3d* pEnt = (Gfc2Vector3d*)pEntity;
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

    if (pEnt->hasZ())
        stream<<","<<pEnt->getZ();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2Vector3dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Vector3d* pEnt = (Gfc2Vector3d*)pEntity;
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
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setZ(value);
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

