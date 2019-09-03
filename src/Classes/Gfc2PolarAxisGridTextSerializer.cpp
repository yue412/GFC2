#include "StdAfx.h"
#include "Gfc2PolarAxisGridTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PolarAxisGrid.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolarAxisGridTextSerializer,"Gfc2PolarAxisGridT",0)

std::string Gfc2PolarAxisGridTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolarAxisGrid* pEnt = (Gfc2PolarAxisGrid*)pEntity;
    std::string sResult = Gfc2AxisGridTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasInsertPt())
        stream<<",#"<<pEnt->getInsertPt();
    else
        stream<<",$";

    if (pEnt->hasStartRadius())
        stream<<","<<pEnt->getStartRadius();
    else
        stream<<",$";

    if (pEnt->hasClockwise())
        stream<<(pEnt->getClockwise() ? ",.T." : ",.F.");
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getXKJCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getXKJ(i);
            else
                stream<<",#"<<pEnt->getXKJ(i);
        }
        stream<<")";
    }

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getZJSCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getZJS(i);
            else
                stream<<",#"<<pEnt->getZJS(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PolarAxisGridTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolarAxisGrid* pEnt = (Gfc2PolarAxisGrid*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AxisGridTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setInsertPt(value);
        }
        break;
    case 6:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setStartRadius(value);
        }
        break;
    case 7:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setClockwise(value);
        }
        break;
    case 8:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addXKJ(value);
        }
        break;
    case 9:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addZJS(value);
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

