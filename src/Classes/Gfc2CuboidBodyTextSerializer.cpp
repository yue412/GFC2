#include "StdAfx.h"
#include "Gfc2CuboidBodyTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CuboidBody.h"

OBJECTBUF_IMP_OBJECT(Gfc2CuboidBodyTextSerializer,"Gfc2CuboidBodyT",0)

std::string Gfc2CuboidBodyTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CuboidBody* pEnt = (Gfc2CuboidBody*)pEntity;
    std::string sResult = Gfc2PrimitiveBodyTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCoordinate())
        stream<<",#"<<pEnt->getCoordinate();
    else
        stream<<",$";

    if (pEnt->hasDimension())
        stream<<",#"<<pEnt->getDimension();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CuboidBodyTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CuboidBody* pEnt = (Gfc2CuboidBody*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PrimitiveBodyTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setCoordinate(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDimension(value);
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

