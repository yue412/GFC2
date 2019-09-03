#include "StdAfx.h"
#include "Gfc2InternalChartTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2InternalChart.h"

OBJECTBUF_IMP_OBJECT(Gfc2InternalChartTextSerializer,"Gfc2InternalChartT",0)

std::string Gfc2InternalChartTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalChart* pEnt = (Gfc2InternalChart*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasTra1())
        stream<<","<<pEnt->getTra1();
    else
        stream<<",$";

    if (pEnt->hasTra2())
        stream<<","<<pEnt->getTra2();
    else
        stream<<",$";

    if (pEnt->hasTra3())
        stream<<","<<pEnt->getTra3();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getIPSCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getIPS(i);
            else
                stream<<",#"<<pEnt->getIPS(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2InternalChartTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2InternalChart* pEnt = (Gfc2InternalChart*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTra1(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTra2(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTra3(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addIPS(value);
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

