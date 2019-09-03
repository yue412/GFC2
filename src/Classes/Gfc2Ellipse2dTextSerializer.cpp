#include "StdAfx.h"
#include "Gfc2Ellipse2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Ellipse2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Ellipse2dTextSerializer,"Gfc2Ellipse2dT",0)

std::string Gfc2Ellipse2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Ellipse2d* pEnt = (Gfc2Ellipse2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCenterPt())
        stream<<",#"<<pEnt->getCenterPt();
    else
        stream<<",$";

    if (pEnt->hasMajorAxis())
        stream<<",#"<<pEnt->getMajorAxis();
    else
        stream<<",$";

    if (pEnt->hasdMajorRad())
        stream<<","<<pEnt->getdMajorRad();
    else
        stream<<",$";

    if (pEnt->hasdMinorRad())
        stream<<","<<pEnt->getdMinorRad();
    else
        stream<<",$";

    if (pEnt->hasRange())
        stream<<",#"<<pEnt->getRange();
    else
        stream<<",$";

    if (pEnt->hasClockSign())
        stream<<","<<pEnt->getClockSign();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2Ellipse2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Ellipse2d* pEnt = (Gfc2Ellipse2d*)pEntity;
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
            pEnt->setCenterPt(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setMajorAxis(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setdMajorRad(value);
        }
        break;
    case 3:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setdMinorRad(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRange(value);
        }
        break;
    case 5:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setClockSign(value);
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

