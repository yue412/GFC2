#include "StdAfx.h"
#include "Gfc2CenterStartEndArcAssitAxisTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CenterStartEndArcAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2CenterStartEndArcAssitAxisTextSerializer,"Gfc2CenterStartEndArcAssitAxisT",0)

std::string Gfc2CenterStartEndArcAssitAxisTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CenterStartEndArcAssitAxis* pEnt = (Gfc2CenterStartEndArcAssitAxis*)pEntity;
    std::string sResult = Gfc2AssitAxisTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCenter())
        stream<<",#"<<pEnt->getCenter();
    else
        stream<<",$";

    if (pEnt->hasStartPoint())
        stream<<",#"<<pEnt->getStartPoint();
    else
        stream<<",$";

    if (pEnt->hasEndPoint())
        stream<<",#"<<pEnt->getEndPoint();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CenterStartEndArcAssitAxisTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CenterStartEndArcAssitAxis* pEnt = (Gfc2CenterStartEndArcAssitAxis*)pEntity;
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
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setStartPoint(value);
        }
        break;
    case 10:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setEndPoint(value);
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

