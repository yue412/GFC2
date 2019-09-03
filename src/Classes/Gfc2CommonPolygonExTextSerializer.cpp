#include "StdAfx.h"
#include "Gfc2CommonPolygonExTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CommonPolygonEx.h"

OBJECTBUF_IMP_OBJECT(Gfc2CommonPolygonExTextSerializer,"Gfc2CommonPolygonExT",0)

std::string Gfc2CommonPolygonExTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CommonPolygonEx* pEnt = (Gfc2CommonPolygonEx*)pEntity;
    std::string sResult = Gfc2PolygonTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    {
        stream<<",(";
        for (int i = 0; i < pEnt->getLoopExsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getLoopExs(i);
            else
                stream<<",#"<<pEnt->getLoopExs(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CommonPolygonExTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CommonPolygonEx* pEnt = (Gfc2CommonPolygonEx*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PolygonTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->addLoopExs(value);
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

