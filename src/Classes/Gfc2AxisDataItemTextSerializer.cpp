#include "StdAfx.h"
#include "Gfc2AxisDataItemTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2AxisDataItem.h"

OBJECTBUF_IMP_OBJECT(Gfc2AxisDataItemTextSerializer,"Gfc2AxisDataItemT",0)

std::string Gfc2AxisDataItemTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisDataItem* pEnt = (Gfc2AxisDataItem*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasAxisNo())
        stream<<",#"<<pEnt->getAxisNo();
    else
        stream<<",$";

    if (pEnt->hasDistance())
        stream<<","<<pEnt->getDistance();
    else
        stream<<",$";

    if (pEnt->hasLevel())
        stream<<","<<pEnt->getLevel();
    else
        stream<<",$";

    if (pEnt->hasAxisNoPos())
        stream<<","<<Gfc2AxisNoPosEnumToString(pEnt->getAxisNoPos());
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getTrimPointsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getTrimPoints(i);
            else
                stream<<",#"<<pEnt->getTrimPoints(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2AxisDataItemTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AxisDataItem* pEnt = (Gfc2AxisDataItem*)pEntity;
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
            pEnt->setAxisNo(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setDistance(value);
        }
        break;
    case 2:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setLevel(value);
        }
        break;
    case 3:
        {
            Gfc2AxisNoPosEnum value;
            DO_((StringToGfc2AxisNoPosEnum(input, value)));
            pEnt->setAxisNoPos(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addTrimPoints(value);
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

