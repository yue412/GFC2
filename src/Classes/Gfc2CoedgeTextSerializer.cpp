#include "StdAfx.h"
#include "Gfc2CoedgeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Coedge.h"

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeTextSerializer,"Gfc2CoedgeT",0)

std::string Gfc2CoedgeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coedge* pEnt = (Gfc2Coedge*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCurve())
        stream<<",#"<<pEnt->getCurve();
    else
        stream<<",$";

    if (pEnt->hasEdgeIndex())
        stream<<","<<pEnt->getEdgeIndex();
    else
        stream<<",$";

    if (pEnt->hasEdgeSameDir())
        stream<<(pEnt->getEdgeSameDir() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CoedgeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Coedge* pEnt = (Gfc2Coedge*)pEntity;
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
            pEnt->setCurve(value);
        }
        break;
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setEdgeIndex(value);
        }
        break;
    case 2:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setEdgeSameDir(value);
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

