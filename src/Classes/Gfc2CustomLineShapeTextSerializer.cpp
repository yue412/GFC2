#include "StdAfx.h"
#include "Gfc2CustomLineShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CustomLineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2CustomLineShapeTextSerializer,"Gfc2CustomLineShapeT",0)

std::string Gfc2CustomLineShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomLineShape* pEnt = (Gfc2CustomLineShape*)pEntity;
    std::string sResult = Gfc2SolidShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasWidth())
        stream<<","<<pEnt->getWidth();
    else
        stream<<",$";

    if (pEnt->hasLeftWidth())
        stream<<","<<pEnt->getLeftWidth();
    else
        stream<<",$";

    if (pEnt->hasLine())
        stream<<",#"<<pEnt->getLine();
    else
        stream<<",$";

    if (pEnt->hasE_S_Elevation())
        stream<<","<<pEnt->getE_S_Elevation();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CustomLineShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CustomLineShape* pEnt = (Gfc2CustomLineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SolidShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 4:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setWidth(value);
        }
        break;
    case 5:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setLeftWidth(value);
        }
        break;
    case 6:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setLine(value);
        }
        break;
    case 7:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setE_S_Elevation(value);
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

