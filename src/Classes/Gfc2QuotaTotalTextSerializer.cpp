#include "StdAfx.h"
#include "Gfc2QuotaTotalTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2QuotaTotal.h"

OBJECTBUF_IMP_OBJECT(Gfc2QuotaTotalTextSerializer,"Gfc2QuotaTotalT",0)

std::string Gfc2QuotaTotalTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2QuotaTotal* pEnt = (Gfc2QuotaTotal*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCode())
        stream<<",#"<<pEnt->getCode();
    else
        stream<<",$";

    if (pEnt->hasSubCode())
        stream<<",#"<<pEnt->getSubCode();
    else
        stream<<",$";

    if (pEnt->hasName())
        stream<<",#"<<pEnt->getName();
    else
        stream<<",$";

    if (pEnt->hasContent())
        stream<<",#"<<pEnt->getContent();
    else
        stream<<",$";

    if (pEnt->hasUnit())
        stream<<",#"<<pEnt->getUnit();
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

glodon::objectbuf::EnParseFieldState Gfc2QuotaTotalTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2QuotaTotal* pEnt = (Gfc2QuotaTotal*)pEntity;
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
            pEnt->setCode(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setSubCode(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setName(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setContent(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setUnit(value);
        }
        break;
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setQuantity(value);
        }
        break;
    case 6:
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

