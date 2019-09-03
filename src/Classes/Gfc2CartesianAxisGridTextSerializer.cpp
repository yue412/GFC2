#include "StdAfx.h"
#include "Gfc2CartesianAxisGridTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CartesianAxisGrid.h"

OBJECTBUF_IMP_OBJECT(Gfc2CartesianAxisGridTextSerializer,"Gfc2CartesianAxisGridT",0)

std::string Gfc2CartesianAxisGridTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CartesianAxisGrid* pEnt = (Gfc2CartesianAxisGrid*)pEntity;
    std::string sResult = Gfc2AxisGridTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasInsertPt())
        stream<<",#"<<pEnt->getInsertPt();
    else
        stream<<",$";

    if (pEnt->hasAxisAngle())
        stream<<","<<pEnt->getAxisAngle();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getSKJCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getSKJ(i);
            else
                stream<<",#"<<pEnt->getSKJ(i);
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

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getYJSCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getYJS(i);
            else
                stream<<",#"<<pEnt->getYJS(i);
        }
        stream<<")";
    }

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

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CartesianAxisGridTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CartesianAxisGrid* pEnt = (Gfc2CartesianAxisGrid*)pEntity;
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
            pEnt->setAxisAngle(value);
        }
        break;
    case 7:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addSKJ(value);
        }
        break;
    case 8:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addZJS(value);
        }
        break;
    case 9:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addYJS(value);
        }
        break;
    case 10:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addXKJ(value);
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

