#include "StdAfx.h"
#include "Gfc2ThreePointArcAssitAxisTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2ThreePointArcAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2ThreePointArcAssitAxisTextSerializer,"Gfc2ThreePointArcAssitAxisT",0)

std::string Gfc2ThreePointArcAssitAxisTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ThreePointArcAssitAxis* pEnt = (Gfc2ThreePointArcAssitAxis*)pEntity;
    std::string sResult = Gfc2AssitAxisTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasRefPoint1())
        stream<<",#"<<pEnt->getRefPoint1();
    else
        stream<<",$";

    if (pEnt->hasRefPoint2())
        stream<<",#"<<pEnt->getRefPoint2();
    else
        stream<<",$";

    if (pEnt->hasRefPoint3())
        stream<<",#"<<pEnt->getRefPoint3();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2ThreePointArcAssitAxisTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ThreePointArcAssitAxis* pEnt = (Gfc2ThreePointArcAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 8:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRefPoint1(value);
        }
        break;
    case 9:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRefPoint2(value);
        }
        break;
    case 10:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRefPoint3(value);
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

