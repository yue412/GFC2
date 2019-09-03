#include "StdAfx.h"
#include "Gfc2SteelTotalTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SteelTotal.h"

OBJECTBUF_IMP_OBJECT(Gfc2SteelTotalTextSerializer,"Gfc2SteelTotalT",0)

std::string Gfc2SteelTotalTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelTotal* pEnt = (Gfc2SteelTotal*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCompType())
        stream<<",#"<<pEnt->getCompType();
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

    if (pEnt->hasWeight())
        stream<<","<<pEnt->getWeight();
    else
        stream<<",$";

    if (pEnt->hasUnit())
        stream<<",#"<<pEnt->getUnit();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SteelTotalTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SteelTotal* pEnt = (Gfc2SteelTotal*)pEntity;
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
            pEnt->setCompType(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setLevel(value);
        }
        break;
    case 2:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setDia(value);
        }
        break;
    case 3:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setWeight(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setUnit(value);
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

