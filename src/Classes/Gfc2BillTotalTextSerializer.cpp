#include "StdAfx.h"
#include "Gfc2BillTotalTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2BillTotal.h"

OBJECTBUF_IMP_OBJECT(Gfc2BillTotalTextSerializer,"Gfc2BillTotalT",0)

std::string Gfc2BillTotalTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BillTotal* pEnt = (Gfc2BillTotal*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCode())
        stream<<",#"<<pEnt->getCode();
    else
        stream<<",$";

    if (pEnt->hasName())
        stream<<",#"<<pEnt->getName();
    else
        stream<<",$";

    if (pEnt->hasAttr())
        stream<<",#"<<pEnt->getAttr();
    else
        stream<<",$";

    if (pEnt->hasQuantityType())
        stream<<","<<pEnt->getQuantityType();
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

glodon::objectbuf::EnParseFieldState Gfc2BillTotalTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2BillTotal* pEnt = (Gfc2BillTotal*)pEntity;
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
            pEnt->setName(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setAttr(value);
        }
        break;
    case 3:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setQuantityType(value);
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

