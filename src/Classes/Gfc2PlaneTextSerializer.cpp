#include "StdAfx.h"
#include "Gfc2PlaneTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Plane.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneTextSerializer,"Gfc2PlaneT",0)

std::string Gfc2PlaneTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Plane* pEnt = (Gfc2Plane*)pEntity;
    std::string sResult = Gfc2SurfaceTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPos())
        stream<<",#"<<pEnt->getPos();
    else
        stream<<",$";

    if (pEnt->hasDirU())
        stream<<",#"<<pEnt->getDirU();
    else
        stream<<",$";

    if (pEnt->hasDirV())
        stream<<",#"<<pEnt->getDirV();
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

glodon::objectbuf::EnParseFieldState Gfc2PlaneTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Plane* pEnt = (Gfc2Plane*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setPos(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirU(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirV(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRangeU(value);
        }
        break;
    case 4:
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

