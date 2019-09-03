#include "StdAfx.h"
#include "Gfc2SimpleLoopTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SimpleLoop.h"

OBJECTBUF_IMP_OBJECT(Gfc2SimpleLoopTextSerializer,"Gfc2SimpleLoopT",0)

std::string Gfc2SimpleLoopTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimpleLoop* pEnt = (Gfc2SimpleLoop*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    {
        stream<<",(";
        for (int i = 0; i < pEnt->getVertexesCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getVertexes(i);
            else
                stream<<",#"<<pEnt->getVertexes(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SimpleLoopTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SimpleLoop* pEnt = (Gfc2SimpleLoop*)pEntity;
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
            pEnt->addVertexes(value);
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

