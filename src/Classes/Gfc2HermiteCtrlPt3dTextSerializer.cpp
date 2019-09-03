#include "StdAfx.h"
#include "Gfc2HermiteCtrlPt3dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2HermiteCtrlPt3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCtrlPt3dTextSerializer,"Gfc2HermiteCtrlPt3dT",0)

std::string Gfc2HermiteCtrlPt3dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCtrlPt3d* pEnt = (Gfc2HermiteCtrlPt3d*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPoint())
        stream<<",#"<<pEnt->getPoint();
    else
        stream<<",$";

    if (pEnt->hasTangent())
        stream<<",#"<<pEnt->getTangent();
    else
        stream<<",$";

    if (pEnt->hasParameter())
        stream<<","<<pEnt->getParameter();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2HermiteCtrlPt3dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2HermiteCtrlPt3d* pEnt = (Gfc2HermiteCtrlPt3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setPoint(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setTangent(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setParameter(value);
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

