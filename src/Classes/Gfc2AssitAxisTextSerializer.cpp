#include "StdAfx.h"
#include "Gfc2AssitAxisTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2AssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2AssitAxisTextSerializer,"Gfc2AssitAxisT",0)

std::string Gfc2AssitAxisTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AssitAxis* pEnt = (Gfc2AssitAxis*)pEntity;
    std::string sResult = Gfc2EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasAxisNo())
        stream<<",#"<<pEnt->getAxisNo();
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

glodon::objectbuf::EnParseFieldState Gfc2AssitAxisTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AssitAxis* pEnt = (Gfc2AssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2EntityTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setAxisNo(value);
        }
        break;
    case 6:
        {
            Gfc2AxisNoPosEnum value;
            DO_((StringToGfc2AxisNoPosEnum(input, value)));
            pEnt->setAxisNoPos(value);
        }
        break;
    case 7:
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

