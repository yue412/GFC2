#include "StdAfx.h"
#include "Gfc2PlaneInfoTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PlaneInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneInfoTextSerializer,"Gfc2PlaneInfoT",0)

std::string Gfc2PlaneInfoTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneInfo* pEnt = (Gfc2PlaneInfo*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasDirX())
        stream<<",#"<<pEnt->getDirX();
    else
        stream<<",$";

    if (pEnt->hasDirY())
        stream<<",#"<<pEnt->getDirY();
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

glodon::objectbuf::EnParseFieldState Gfc2PlaneInfoTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PlaneInfo* pEnt = (Gfc2PlaneInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setDirX(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirY(value);
        }
        break;
    case 2:
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

