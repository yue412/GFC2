#include "StdAfx.h"
#include "Gfc2PointShape2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PointShape2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointShape2dTextSerializer,"Gfc2PointShape2dT",0)

std::string Gfc2PointShape2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape2d* pEnt = (Gfc2PointShape2d*)pEntity;
    std::string sResult = Gfc2Shape2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasInsertPt())
        stream<<",#"<<pEnt->getInsertPt();
    else
        stream<<",$";

    if (pEnt->hasAngle())
        stream<<","<<pEnt->getAngle();
    else
        stream<<",$";

    if (pEnt->hasMirrorFlag())
        stream<<(pEnt->getMirrorFlag() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PointShape2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PointShape2d* pEnt = (Gfc2PointShape2d*)pEntity;
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
            pEnt->setInsertPt(value);
        }
        break;
    case 4:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setAngle(value);
        }
        break;
    case 5:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setMirrorFlag(value);
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

