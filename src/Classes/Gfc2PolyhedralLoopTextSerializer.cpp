#include "StdAfx.h"
#include "Gfc2PolyhedralLoopTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PolyhedralLoop.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralLoopTextSerializer,"Gfc2PolyhedralLoopT",0)

std::string Gfc2PolyhedralLoopTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralLoop* pEnt = (Gfc2PolyhedralLoop*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    {
        stream<<",(";
        for (int i = 0; i < pEnt->getEdgesCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getEdges(i);
            else
                stream<<",#"<<pEnt->getEdges(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PolyhedralLoopTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolyhedralLoop* pEnt = (Gfc2PolyhedralLoop*)pEntity;
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
            pEnt->addEdges(value);
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

