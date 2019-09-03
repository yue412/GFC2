#include "StdAfx.h"
#include "Gfc2CommonPolygonTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2CommonPolygon.h"

OBJECTBUF_IMP_OBJECT(Gfc2CommonPolygonTextSerializer,"Gfc2CommonPolygonT",0)

std::string Gfc2CommonPolygonTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CommonPolygon* pEnt = (Gfc2CommonPolygon*)pEntity;
    std::string sResult = Gfc2PolygonTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    {
        stream<<",(";
        for (int i = 0; i < pEnt->getLoopsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getLoops(i);
            else
                stream<<",#"<<pEnt->getLoops(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2CommonPolygonTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CommonPolygon* pEnt = (Gfc2CommonPolygon*)pEntity;
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
            pEnt->addLoops(value);
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

