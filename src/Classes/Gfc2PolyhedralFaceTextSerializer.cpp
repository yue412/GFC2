#include "StdAfx.h"
#include "Gfc2PolyhedralFaceTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PolyhedralFace.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralFaceTextSerializer,"Gfc2PolyhedralFaceT",0)

std::string Gfc2PolyhedralFaceTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralFace* pEnt = (Gfc2PolyhedralFace*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

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

    if (pEnt->hasPlane())
        stream<<",#"<<pEnt->getPlane();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PolyhedralFaceTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolyhedralFace* pEnt = (Gfc2PolyhedralFace*)pEntity;
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
            pEnt->addLoops(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setPlane(value);
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

