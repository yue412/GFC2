#include "StdAfx.h"
#include "Gfc2SteelDetailTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SteelDetail.h"

OBJECTBUF_IMP_OBJECT(Gfc2SteelDetailTextSerializer,"Gfc2SteelDetailT",0)

std::string Gfc2SteelDetailTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelDetail* pEnt = (Gfc2SteelDetail*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasEntityID())
        stream<<","<<pEnt->getEntityID();
    else
        stream<<",$";

    if (pEnt->hasName())
        stream<<",#"<<pEnt->getName();
    else
        stream<<",$";

    if (pEnt->hasDesc())
        stream<<",#"<<pEnt->getDesc();
    else
        stream<<",$";

    if (pEnt->hasLevel())
        stream<<",#"<<pEnt->getLevel();
    else
        stream<<",$";

    if (pEnt->hasDia())
        stream<<","<<pEnt->getDia();
    else
        stream<<",$";

    if (pEnt->hasNum())
        stream<<","<<pEnt->getNum();
    else
        stream<<",$";

    if (pEnt->hasLength())
        stream<<","<<pEnt->getLength();
    else
        stream<<",$";

    if (pEnt->hasSingleWeight())
        stream<<","<<pEnt->getSingleWeight();
    else
        stream<<",$";

    if (pEnt->hasTotalWeight())
        stream<<","<<pEnt->getTotalWeight();
    else
        stream<<",$";

    if (pEnt->hasTieinNum())
        stream<<","<<pEnt->getTieinNum();
    else
        stream<<",$";

    if (pEnt->hasTieinType())
        stream<<",#"<<pEnt->getTieinType();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SteelDetailTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SteelDetail* pEnt = (Gfc2SteelDetail*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setEntityID(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setName(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDesc(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setLevel(value);
        }
        break;
    case 4:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setDia(value);
        }
        break;
    case 5:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setNum(value);
        }
        break;
    case 6:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setLength(value);
        }
        break;
    case 7:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setSingleWeight(value);
        }
        break;
    case 8:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTotalWeight(value);
        }
        break;
    case 9:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setTieinNum(value);
        }
        break;
    case 10:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setTieinType(value);
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

