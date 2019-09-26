#include "StdAfx.h"
#include "Gfc2CoedgeListTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CoedgeList.h"

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeListTextSerializer,"Gfc2CoedgeListT",0)

std::string Gfc2CoedgeListTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CoedgeList* pEnt = (Gfc2CoedgeList*)pEntity;
    std::string sResult = Gfc2GeometryTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    {
        stream<<",(";
        for (int i = 0; i < pEnt->getCoedgesCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getCoedges(i);
            else
                stream<<",#"<<pEnt->getCoedges(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CoedgeListTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CoedgeList* pEnt = (Gfc2CoedgeList*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->addCoedges(value);
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

