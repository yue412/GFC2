#include "StdAfx.h"
#include "Gfc2StateSetTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2StateSet.h"

OBJECTBUF_IMP_OBJECT(Gfc2StateSetTextSerializer,"Gfc2StateSetT",0)

std::string Gfc2StateSetTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2StateSet* pEnt = (Gfc2StateSet*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasAmbient())
        stream<<","<<pEnt->getAmbient();
    else
        stream<<",$";

    if (pEnt->hasDiffuse())
        stream<<","<<pEnt->getDiffuse();
    else
        stream<<",$";

    if (pEnt->hasSourceBlendFactor())
        stream<<","<<Gfc2SceneBlendFactorToString(pEnt->getSourceBlendFactor());
    else
        stream<<",$";

    if (pEnt->hasDestBlendFactor())
        stream<<","<<Gfc2SceneBlendFactorToString(pEnt->getDestBlendFactor());
    else
        stream<<",$";

    if (pEnt->hasDepthTestEnabled())
        stream<<(pEnt->getDepthTestEnabled() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasDepthWriteEnabled())
        stream<<(pEnt->getDepthWriteEnabled() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasDepthTestFunction())
        stream<<","<<Gfc2FragTestFuncToString(pEnt->getDepthTestFunction());
    else
        stream<<",$";

    if (pEnt->hasPolygonOffsetFactor())
        stream<<","<<pEnt->getPolygonOffsetFactor();
    else
        stream<<",$";

    if (pEnt->hasPolygonOffsetUnits())
        stream<<","<<pEnt->getPolygonOffsetUnits();
    else
        stream<<",$";

    if (pEnt->hasPolygonStipple())
        stream<<",#"<<pEnt->getPolygonStipple();
    else
        stream<<",$";

    if (pEnt->hasLineStipplePattern())
        stream<<","<<pEnt->getLineStipplePattern();
    else
        stream<<",$";

    if (pEnt->hasLineStippleFactor())
        stream<<","<<pEnt->getLineStippleFactor();
    else
        stream<<",$";

    if (pEnt->hasFaceMode())
        stream<<","<<Gfc2FaceModeToString(pEnt->getFaceMode());
    else
        stream<<",$";

    if (pEnt->hasLightingEnabled())
        stream<<(pEnt->getLightingEnabled() ? ",.T." : ",.F.");
    else
        stream<<",$";

    if (pEnt->hasLightModelTwoSided())
        stream<<(pEnt->getLightModelTwoSided() ? ",.T." : ",.F.");
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2StateSetTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2StateSet* pEnt = (Gfc2StateSet*)pEntity;
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
            pEnt->setAmbient(value);
        }
        break;
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setDiffuse(value);
        }
        break;
    case 2:
        {
            Gfc2SceneBlendFactor value;
            DO_((StringToGfc2SceneBlendFactor(input, value)));
            pEnt->setSourceBlendFactor(value);
        }
        break;
    case 3:
        {
            Gfc2SceneBlendFactor value;
            DO_((StringToGfc2SceneBlendFactor(input, value)));
            pEnt->setDestBlendFactor(value);
        }
        break;
    case 4:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setDepthTestEnabled(value);
        }
        break;
    case 5:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setDepthWriteEnabled(value);
        }
        break;
    case 6:
        {
            Gfc2FragTestFunc value;
            DO_((StringToGfc2FragTestFunc(input, value)));
            pEnt->setDepthTestFunction(value);
        }
        break;
    case 7:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setPolygonOffsetFactor(value);
        }
        break;
    case 8:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setPolygonOffsetUnits(value);
        }
        break;
    case 9:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setPolygonStipple(value);
        }
        break;
    case 10:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setLineStipplePattern(value);
        }
        break;
    case 11:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setLineStippleFactor(value);
        }
        break;
    case 12:
        {
            Gfc2FaceMode value;
            DO_((StringToGfc2FaceMode(input, value)));
            pEnt->setFaceMode(value);
        }
        break;
    case 13:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setLightingEnabled(value);
        }
        break;
    case 14:
        {
            Gfc2Boolean value;
            DO_((readBooleanField(input, value)));
            pEnt->setLightModelTwoSided(value);
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

