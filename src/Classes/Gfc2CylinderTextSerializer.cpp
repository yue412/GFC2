#include "StdAfx.h"
#include "Gfc2CylinderTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Cylinder.h"

OBJECTBUF_IMP_OBJECT(Gfc2CylinderTextSerializer,"Gfc2CylinderT",0)

std::string Gfc2CylinderTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Cylinder* pEnt = (Gfc2Cylinder*)pEntity;
    std::string sResult = Gfc2SurfaceTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRangeV())
        stream<<",#"<<pEnt->getRangeV();
    else
        stream<<",$";

    if (pEnt->hasCurve())
        stream<<",#"<<pEnt->getCurve();
    else
        stream<<",$";

    if (pEnt->hasDirX())
        stream<<",#"<<pEnt->getDirX();
    else
        stream<<",$";

    if (pEnt->hasDirY())
        stream<<",#"<<pEnt->getDirY();
    else
        stream<<",$";

    if (pEnt->hasDirZ())
        stream<<",#"<<pEnt->getDirZ();
    else
        stream<<",$";

    if (pEnt->hasPos())
        stream<<",#"<<pEnt->getPos();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CylinderTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Cylinder* pEnt = (Gfc2Cylinder*)pEntity;
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
            pEnt->setRangeV(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setCurve(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirX(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirY(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirZ(value);
        }
        break;
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setPos(value);
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

