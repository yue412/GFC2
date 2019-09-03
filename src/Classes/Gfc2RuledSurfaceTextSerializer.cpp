#include "StdAfx.h"
#include "Gfc2RuledSurfaceTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2RuledSurface.h"

OBJECTBUF_IMP_OBJECT(Gfc2RuledSurfaceTextSerializer,"Gfc2RuledSurfaceT",0)

std::string Gfc2RuledSurfaceTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RuledSurface* pEnt = (Gfc2RuledSurface*)pEntity;
    std::string sResult = Gfc2SurfaceTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasApexIndex())
        stream<<","<<pEnt->getApexIndex();
    else
        stream<<",$";

    if (pEnt->hasRangeV())
        stream<<",#"<<pEnt->getRangeV();
    else
        stream<<",$";

    if (pEnt->hasRangeU())
        stream<<",#"<<pEnt->getRangeU();
    else
        stream<<",$";

    if (pEnt->hasDirectrix1())
        stream<<",#"<<pEnt->getDirectrix1();
    else
        stream<<",$";

    if (pEnt->hasDirectrix2())
        stream<<",#"<<pEnt->getDirectrix2();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2RuledSurfaceTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RuledSurface* pEnt = (Gfc2RuledSurface*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setApexIndex(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRangeV(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRangeU(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirectrix1(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirectrix2(value);
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

