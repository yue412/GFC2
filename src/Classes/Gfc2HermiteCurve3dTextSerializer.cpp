#include "StdAfx.h"
#include "Gfc2HermiteCurve3dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2HermiteCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCurve3dTextSerializer,"Gfc2HermiteCurve3dT",0)

std::string Gfc2HermiteCurve3dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCurve3d* pEnt = (Gfc2HermiteCurve3d*)pEntity;
    std::string sResult = Gfc2Curve3dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    {
        stream<<",(";
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getCtrlPts(i);
            else
                stream<<",#"<<pEnt->getCtrlPts(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2HermiteCurve3dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2HermiteCurve3d* pEnt = (Gfc2HermiteCurve3d*)pEntity;
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
            pEnt->addCtrlPts(value);
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

