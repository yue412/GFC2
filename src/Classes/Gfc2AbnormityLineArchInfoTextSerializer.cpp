#include "StdAfx.h"
#include "Gfc2AbnormityLineArchInfoTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2AbnormityLineArchInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2AbnormityLineArchInfoTextSerializer,"Gfc2AbnormityLineArchInfoT",0)

std::string Gfc2AbnormityLineArchInfoTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AbnormityLineArchInfo* pEnt = (Gfc2AbnormityLineArchInfo*)pEntity;
    std::string sResult = Gfc2BaseLineArcInfoTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasTopArchStartT())
        stream<<","<<pEnt->getTopArchStartT();
    else
        stream<<",$";

    if (pEnt->hasTopArchEndT())
        stream<<","<<pEnt->getTopArchEndT();
    else
        stream<<",$";

    if (pEnt->hasTopDefineByRadius())
        stream<<(pEnt->getTopDefineByRadius() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasTopArchHeight())
        stream<<","<<pEnt->getTopArchHeight();
    else
        stream<<",$";

    if (pEnt->hasTopArchRadius())
        stream<<","<<pEnt->getTopArchRadius();
    else
        stream<<",$";

    if (pEnt->hasDownArchStartT())
        stream<<","<<pEnt->getDownArchStartT();
    else
        stream<<",$";

    if (pEnt->hasDownArchEndT())
        stream<<","<<pEnt->getDownArchEndT();
    else
        stream<<",$";

    if (pEnt->hasDownDefineByRadius())
        stream<<(pEnt->getDownDefineByRadius() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasDownArchHeight())
        stream<<","<<pEnt->getDownArchHeight();
    else
        stream<<",$";

    if (pEnt->hasDownArchRadius())
        stream<<","<<pEnt->getDownArchRadius();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2AbnormityLineArchInfoTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AbnormityLineArchInfo* pEnt = (Gfc2AbnormityLineArchInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2BaseLineArcInfoTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setTopArchStartT(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTopArchEndT(value);
        }
        break;
    case 2:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setTopDefineByRadius(value);
        }
        break;
    case 3:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTopArchHeight(value);
        }
        break;
    case 4:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTopArchRadius(value);
        }
        break;
    case 5:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setDownArchStartT(value);
        }
        break;
    case 6:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setDownArchEndT(value);
        }
        break;
    case 7:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setDownDefineByRadius(value);
        }
        break;
    case 8:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setDownArchHeight(value);
        }
        break;
    case 9:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setDownArchRadius(value);
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

