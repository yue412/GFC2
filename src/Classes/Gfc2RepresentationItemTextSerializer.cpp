#include "StdAfx.h"
#include "Gfc2RepresentationItemTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2RepresentationItem.h"

OBJECTBUF_IMP_OBJECT(Gfc2RepresentationItemTextSerializer,"Gfc2RepresentationItemT",0)

std::string Gfc2RepresentationItemTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RepresentationItem* pEnt = (Gfc2RepresentationItem*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPrimitiveType())
        stream<<","<<Gfc2PrimitiveTypeToString(pEnt->getPrimitiveType());
    else
        stream<<",$";

    if (pEnt->hasGeometryDataType())
        stream<<","<<Gfc2GeometryDataTypeToString(pEnt->getGeometryDataType());
    else
        stream<<",$";

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

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getNormalsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getNormals(i);
            else
                stream<<",#"<<pEnt->getNormals(i);
        }
        stream<<")";
    }

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getIndexesCount(); i++)
        {
            if(0==i)
                stream<<""<<pEnt->getIndexes(i);
            else
                stream<<","<<pEnt->getIndexes(i);
        }
        stream<<")";
    }

    if (pEnt->hasStateSet())
        stream<<",#"<<pEnt->getStateSet();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2RepresentationItemTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RepresentationItem* pEnt = (Gfc2RepresentationItem*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2PrimitiveType value;
            DO_((StringToGfc2PrimitiveType(input, value)));
            pEnt->setPrimitiveType(value);
        }
        break;
    case 1:
        {
            Gfc2GeometryDataType value;
            DO_((StringToGfc2GeometryDataType(input, value)));
            pEnt->setGeometryDataType(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addVertexes(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addNormals(value);
        }
        break;
    case 4:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->addIndexes(value);
        }
        break;
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setStateSet(value);
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

