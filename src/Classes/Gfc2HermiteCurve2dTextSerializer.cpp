#include "StdAfx.h"
#include "Gfc2HermiteCurve2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2HermiteCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCurve2dTextSerializer,"Gfc2HermiteCurve2dT",0)

std::string Gfc2HermiteCurve2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCurve2d* pEnt = (Gfc2HermiteCurve2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

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

glodon::objectbuf::EnParseFieldState Gfc2HermiteCurve2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2HermiteCurve2d* pEnt = (Gfc2HermiteCurve2d*)pEntity;
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

