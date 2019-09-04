#include "StdAfx.h"
#include "Gfc2Line2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Line2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Line2dTextSerializer,"Gfc2Line2dT",0)

std::string Gfc2Line2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Line2d* pEnt = (Gfc2Line2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasStartPt())
        stream<<",#"<<pEnt->getStartPt();
    else
        stream<<",$";

    if (pEnt->hasEndPt())
        stream<<",#"<<pEnt->getEndPt();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2Line2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Line2d* pEnt = (Gfc2Line2d*)pEntity;
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
            pEnt->setStartPt(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setEndPt(value);
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
