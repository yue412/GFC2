#include "StdAfx.h"
#include "Gfc2QuotaDetailTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2QuotaDetail.h"

OBJECTBUF_IMP_OBJECT(Gfc2QuotaDetailTextSerializer,"Gfc2QuotaDetailT",0)

std::string Gfc2QuotaDetailTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2QuotaDetail* pEnt = (Gfc2QuotaDetail*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasFloorNum())
        stream<<","<<pEnt->getFloorNum();
    else
        stream<<",$";

    if (pEnt->hasEntityID())
        stream<<","<<pEnt->getEntityID();
    else
        stream<<",$";

    if (pEnt->hasUnit())
        stream<<",#"<<pEnt->getUnit();
    else
        stream<<",$";

    if (pEnt->hasExpress())
        stream<<",#"<<pEnt->getExpress();
    else
        stream<<",$";

    if (pEnt->hasQuantity())
        stream<<",#"<<pEnt->getQuantity();
    else
        stream<<",$";

    if (pEnt->hasMemo())
        stream<<",#"<<pEnt->getMemo();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2QuotaDetailTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2QuotaDetail* pEnt = (Gfc2QuotaDetail*)pEntity;
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
            pEnt->setFloorNum(value);
        }
        break;
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setEntityID(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setUnit(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setExpress(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setQuantity(value);
        }
        break;
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setMemo(value);
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

