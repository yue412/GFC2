#include "StdAfx.h"
#include "Gfc2EntityTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Entity.h"

OBJECTBUF_IMP_OBJECT(Gfc2EntityTextSerializer,"Gfc2EntityT",0)

std::string Gfc2EntityTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Entity* pEnt = (Gfc2Entity*)pEntity;
    std::string sResult = Gfc2ObjectTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasType())
        stream<<","<<pEnt->getType();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getRepresentationsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getRepresentations(i);
            else
                stream<<",#"<<pEnt->getRepresentations(i);
        }
        stream<<")";
    }

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getShapesCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getShapes(i);
            else
                stream<<",#"<<pEnt->getShapes(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2EntityTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Entity* pEnt = (Gfc2Entity*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2ObjectTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 2:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setType(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addRepresentations(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addShapes(value);
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

