#include "StdAfx.h"
#include "Gfc2InternalPtTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2InternalPt.h"

OBJECTBUF_IMP_OBJECT(Gfc2InternalPtTextSerializer,"Gfc2InternalPtT",0)

std::string Gfc2InternalPtTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalPt* pEnt = (Gfc2InternalPt*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasP())
        stream<<",#"<<pEnt->getP();
    else
        stream<<",$";

    if (pEnt->hasTVec())
        stream<<",#"<<pEnt->getTVec();
    else
        stream<<",$";

    if (pEnt->hasT())
        stream<<","<<pEnt->getT();
    else
        stream<<",$";

    if (pEnt->hasUV())
        stream<<",#"<<pEnt->getUV();
    else
        stream<<",$";

    if (pEnt->hasST())
        stream<<",#"<<pEnt->getST();
    else
        stream<<",$";

    if (pEnt->hasUVDir())
        stream<<",#"<<pEnt->getUVDir();
    else
        stream<<",$";

    if (pEnt->hasSTDir())
        stream<<",#"<<pEnt->getSTDir();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2InternalPtTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2InternalPt* pEnt = (Gfc2InternalPt*)pEntity;
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
            pEnt->setP(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setTVec(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setT(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setUV(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setST(value);
        }
        break;
    case 5:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setUVDir(value);
        }
        break;
    case 6:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setSTDir(value);
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

