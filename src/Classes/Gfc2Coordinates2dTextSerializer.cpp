#include "StdAfx.h"
#include "Gfc2Coordinates2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Coordinates2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Coordinates2dTextSerializer,"Gfc2Coordinates2dT",0)

std::string Gfc2Coordinates2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coordinates2d* pEnt = (Gfc2Coordinates2d*)pEntity;
    std::string sResult = Gfc2GeometryTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasOrigin())
        stream<<",#"<<pEnt->getOrigin();
    else
        stream<<",$";

    if (pEnt->hasX())
        stream<<",#"<<pEnt->getX();
    else
        stream<<",$";

    if (pEnt->hasY())
        stream<<",#"<<pEnt->getY();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2Coordinates2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Coordinates2d* pEnt = (Gfc2Coordinates2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setOrigin(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setX(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
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

