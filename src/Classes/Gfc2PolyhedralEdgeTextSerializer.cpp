#include "StdAfx.h"
#include "Gfc2PolyhedralEdgeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PolyhedralEdge.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralEdgeTextSerializer,"Gfc2PolyhedralEdgeT",0)

std::string Gfc2PolyhedralEdgeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralEdge* pEnt = (Gfc2PolyhedralEdge*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasStartVertexIndex())
        stream<<","<<pEnt->getStartVertexIndex();
    else
        stream<<",$";

    if (pEnt->hasEndVertexIndex())
        stream<<","<<pEnt->getEndVertexIndex();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PolyhedralEdgeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolyhedralEdge* pEnt = (Gfc2PolyhedralEdge*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setStartVertexIndex(value);
        }
        break;
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setEndVertexIndex(value);
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

