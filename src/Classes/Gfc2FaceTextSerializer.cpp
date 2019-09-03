#include "StdAfx.h"
#include "Gfc2FaceTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Face.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceTextSerializer,"Gfc2FaceT",0)

std::string Gfc2FaceTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Face* pEnt = (Gfc2Face*)pEntity;
    std::string sResult = Gfc2CommonPolygonExTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasSurface())
        stream<<",#"<<pEnt->getSurface();
    else
        stream<<",$";

    if (pEnt->hasBox())
        stream<<",#"<<pEnt->getBox();
    else
        stream<<",$";

    if (pEnt->hasSameDir())
        stream<<(pEnt->getSameDir() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasIndex())
        stream<<","<<pEnt->getIndex();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Face* pEnt = (Gfc2Face*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CommonPolygonExTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setSurface(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setBox(value);
        }
        break;
    case 3:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setSameDir(value);
        }
        break;
    case 4:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setIndex(value);
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

