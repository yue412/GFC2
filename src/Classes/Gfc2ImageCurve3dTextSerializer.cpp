#include "StdAfx.h"
#include "Gfc2ImageCurve3dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2ImageCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2ImageCurve3dTextSerializer,"Gfc2ImageCurve3dT",0)

std::string Gfc2ImageCurve3dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ImageCurve3d* pEnt = (Gfc2ImageCurve3d*)pEntity;
    std::string sResult = Gfc2Curve3dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCurve())
        stream<<",#"<<pEnt->getCurve();
    else
        stream<<",$";

    if (pEnt->hasSurface())
        stream<<",#"<<pEnt->getSurface();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2ImageCurve3dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ImageCurve3d* pEnt = (Gfc2ImageCurve3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve3dTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setCurve(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setSurface(value);
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

