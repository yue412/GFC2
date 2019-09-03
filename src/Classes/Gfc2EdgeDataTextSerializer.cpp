#include "StdAfx.h"
#include "Gfc2EdgeDataTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2EdgeData.h"

OBJECTBUF_IMP_OBJECT(Gfc2EdgeDataTextSerializer,"Gfc2EdgeDataT",0)

std::string Gfc2EdgeDataTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EdgeData* pEnt = (Gfc2EdgeData*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasEdgeIndex())
        stream<<","<<pEnt->getEdgeIndex();
    else
        stream<<",$";

    if (pEnt->hasLoopIndex())
        stream<<","<<pEnt->getLoopIndex();
    else
        stream<<",$";

    if (pEnt->hasType())
        stream<<","<<pEnt->getType();
    else
        stream<<",$";

    if (pEnt->hasEdgeInfo())
        stream<<",#"<<pEnt->getEdgeInfo();
    else
        stream<<",$";

    if (pEnt->hasParam())
        stream<<",#"<<pEnt->getParam();
    else
        stream<<",$";

    if (pEnt->hasBaseType())
        stream<<","<<pEnt->getBaseType();
    else
        stream<<",$";

    if (pEnt->hasSlopePoly())
        stream<<",#"<<pEnt->getSlopePoly();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2EdgeDataTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2EdgeData* pEnt = (Gfc2EdgeData*)pEntity;
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
            pEnt->setEdgeIndex(value);
        }
        break;
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setLoopIndex(value);
        }
        break;
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
            pEnt->setEdgeInfo(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setParam(value);
        }
        break;
    case 5:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setBaseType(value);
        }
        break;
    case 6:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setSlopePoly(value);
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

