#include "StdAfx.h"
#include "Gfc2EdgeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Edge.h"

OBJECTBUF_IMP_OBJECT(Gfc2EdgeTextSerializer,"Gfc2EdgeT",0)

std::string Gfc2EdgeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Edge* pEnt = (Gfc2Edge*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCurve())
        stream<<",#"<<pEnt->getCurve();
    else
        stream<<",$";

    if (pEnt->hasFaceIndex1())
        stream<<","<<pEnt->getFaceIndex1();
    else
        stream<<",$";

    if (pEnt->hasFaceIndex2())
        stream<<","<<pEnt->getFaceIndex2();
    else
        stream<<",$";

    if (pEnt->hasLoopIndex1())
        stream<<","<<pEnt->getLoopIndex1();
    else
        stream<<",$";

    if (pEnt->hasLoopIndex2())
        stream<<","<<pEnt->getLoopIndex2();
    else
        stream<<",$";

    if (pEnt->hasCoedgeIndex1())
        stream<<","<<pEnt->getCoedgeIndex1();
    else
        stream<<",$";

    if (pEnt->hasCoedgeIndex2())
        stream<<","<<pEnt->getCoedgeIndex2();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2EdgeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Edge* pEnt = (Gfc2Edge*)pEntity;
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
            pEnt->setCurve(value);
        }
        break;
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setFaceIndex1(value);
        }
        break;
    case 2:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setFaceIndex2(value);
        }
        break;
    case 3:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setLoopIndex1(value);
        }
        break;
    case 4:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setLoopIndex2(value);
        }
        break;
    case 5:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setCoedgeIndex1(value);
        }
        break;
    case 6:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setCoedgeIndex2(value);
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

