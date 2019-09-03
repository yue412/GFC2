#include "StdAfx.h"
#include "Gfc2NurbsCurve2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2NurbsCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCurve2dTextSerializer,"Gfc2NurbsCurve2dT",0)

std::string Gfc2NurbsCurve2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCurve2d* pEnt = (Gfc2NurbsCurve2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasDegree())
        stream<<","<<pEnt->getDegree();
    else
        stream<<",$";

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

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getKnotsCount(); i++)
        {
            if(0==i)
                stream<<""<<pEnt->getKnots(i);
            else
                stream<<","<<pEnt->getKnots(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2NurbsCurve2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2NurbsCurve2d* pEnt = (Gfc2NurbsCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setDegree(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addCtrlPts(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->addKnots(value);
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

