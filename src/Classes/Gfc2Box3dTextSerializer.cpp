#include "StdAfx.h"
#include "Gfc2Box3dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Box3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Box3dTextSerializer,"Gfc2Box3dT",0)

std::string Gfc2Box3dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Box3d* pEnt = (Gfc2Box3d*)pEntity;
    std::string sResult = Gfc2GeometryTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasMin())
        stream<<",#"<<pEnt->getMin();
    else
        stream<<",$";

    if (pEnt->hasMax())
        stream<<",#"<<pEnt->getMax();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2Box3dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Box3d* pEnt = (Gfc2Box3d*)pEntity;
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
            pEnt->setMin(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setMax(value);
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

