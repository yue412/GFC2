#include "StdAfx.h"
#include "Gfc2SphereTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Sphere.h"

OBJECTBUF_IMP_OBJECT(Gfc2SphereTextSerializer,"Gfc2SphereT",0)

std::string Gfc2SphereTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sphere* pEnt = (Gfc2Sphere*)pEntity;
    std::string sResult = Gfc2SurfaceTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRadius())
        stream<<","<<pEnt->getRadius();
    else
        stream<<",$";

    if (pEnt->hasCoords())
        stream<<",#"<<pEnt->getCoords();
    else
        stream<<",$";

    if (pEnt->hasRangeU())
        stream<<",#"<<pEnt->getRangeU();
    else
        stream<<",$";

    if (pEnt->hasRangeV())
        stream<<",#"<<pEnt->getRangeV();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SphereTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Sphere* pEnt = (Gfc2Sphere*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setRadius(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setCoords(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRangeU(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRangeV(value);
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

