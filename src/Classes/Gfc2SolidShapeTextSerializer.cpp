#include "StdAfx.h"
#include "Gfc2SolidShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SolidShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2SolidShapeTextSerializer,"Gfc2SolidShapeT",0)

std::string Gfc2SolidShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SolidShape* pEnt = (Gfc2SolidShape*)pEntity;
    std::string sResult = Gfc2Shape3dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasBody())
        stream<<",#"<<pEnt->getBody();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getEdgeDatasCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getEdgeDatas(i);
            else
                stream<<",#"<<pEnt->getEdgeDatas(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SolidShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SolidShape* pEnt = (Gfc2SolidShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Shape3dTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setBody(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addEdgeDatas(value);
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

