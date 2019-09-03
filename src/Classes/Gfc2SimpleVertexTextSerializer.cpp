#include "StdAfx.h"
#include "Gfc2SimpleVertexTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SimpleVertex.h"

OBJECTBUF_IMP_OBJECT(Gfc2SimpleVertexTextSerializer,"Gfc2SimpleVertexT",0)

std::string Gfc2SimpleVertexTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimpleVertex* pEnt = (Gfc2SimpleVertex*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPoint())
        stream<<",#"<<pEnt->getPoint();
    else
        stream<<",$";

    if (pEnt->hasRadius())
        stream<<","<<pEnt->getRadius();
    else
        stream<<",$";

    if (pEnt->hasArcType())
        stream<<","<<Gfc2ArcTypeToString(pEnt->getArcType());
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SimpleVertexTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SimpleVertex* pEnt = (Gfc2SimpleVertex*)pEntity;
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
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setRadius(value);
        }
        break;
    case 2:
        {
            Gfc2ArcType value;
            DO_((StringToGfc2ArcType(input, value)));
            pEnt->setArcType(value);
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

