#include "StdAfx.h"
#include "Gfc2FaceShape2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceShape2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceShape2dTextSerializer,"Gfc2FaceShape2dT",0)

std::string Gfc2FaceShape2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape2d* pEnt = (Gfc2FaceShape2d*)pEntity;
    std::string sResult = Gfc2Shape2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPoly())
        stream<<",#"<<pEnt->getPoly();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceShape2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceShape2d* pEnt = (Gfc2FaceShape2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Shape2dTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setPoly(value);
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

