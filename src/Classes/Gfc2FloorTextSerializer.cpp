#include "StdAfx.h"
#include "Gfc2FloorTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Floor.h"

OBJECTBUF_IMP_OBJECT(Gfc2FloorTextSerializer,"Gfc2FloorT",0)

std::string Gfc2FloorTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Floor* pEnt = (Gfc2Floor*)pEntity;
    std::string sResult = Gfc2SpatialStructureEntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasFirstFloorFlag())
        stream<<(pEnt->getFirstFloorFlag() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasHeight())
        stream<<","<<pEnt->getHeight();
    else
        stream<<",$";

    if (pEnt->hasStdFloorCount())
        stream<<","<<pEnt->getStdFloorCount();
    else
        stream<<",$";

    if (pEnt->hasStructuralElevation())
        stream<<","<<pEnt->getStructuralElevation();
    else
        stream<<",$";

    if (pEnt->hasStartFloorNo())
        stream<<","<<pEnt->getStartFloorNo();
    else
        stream<<",$";

    if (pEnt->hasRemark())
        stream<<",#"<<pEnt->getRemark();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2FloorTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Floor* pEnt = (Gfc2Floor*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SpatialStructureEntityTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 2:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setFirstFloorFlag(value);
        }
        break;
    case 3:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setHeight(value);
        }
        break;
    case 4:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setStdFloorCount(value);
        }
        break;
    case 5:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setStructuralElevation(value);
        }
        break;
    case 6:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setStartFloorNo(value);
        }
        break;
    case 7:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRemark(value);
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

