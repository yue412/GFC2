#include "StdAfx.h"
#include "Gfc2PreimageCurve2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PreimageCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2PreimageCurve2dTextSerializer,"Gfc2PreimageCurve2dT",0)

std::string Gfc2PreimageCurve2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PreimageCurve2d* pEnt = (Gfc2PreimageCurve2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRange())
        stream<<",#"<<pEnt->getRange();
    else
        stream<<",$";

    if (pEnt->hasReversed())
        stream<<(pEnt->getReversed() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasBase())
        stream<<",#"<<pEnt->getBase();
    else
        stream<<",$";

    if (pEnt->hasCurve())
        stream<<",#"<<pEnt->getCurve();
    else
        stream<<",$";

    if (pEnt->hasTolerance())
        stream<<","<<pEnt->getTolerance();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PreimageCurve2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PreimageCurve2d* pEnt = (Gfc2PreimageCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setRange(value);
        }
        break;
    case 1:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setReversed(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setBase(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setCurve(value);
        }
        break;
    case 4:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setTolerance(value);
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

