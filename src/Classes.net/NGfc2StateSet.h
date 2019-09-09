#ifndef NGFC2STATESET_H
#define NGFC2STATESET_H

#include "Gfc2StateSet.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2StateSet: public glodon::objectbufnet::Entity
{
public:
    NGfc2StateSet();
    NGfc2StateSet(void* pEntity, bool bOwner);
    void setAmbient(NGfc2Integer nValue);
    NGfc2Integer getAmbient();
    bool hasAmbient();
    void setDiffuse(NGfc2Integer nValue);
    NGfc2Integer getDiffuse();
    bool hasDiffuse();
    void setSourceBlendFactor(NGfc2SceneBlendFactor nValue);
    NGfc2SceneBlendFactor getSourceBlendFactor();
    bool hasSourceBlendFactor();
    void setDestBlendFactor(NGfc2SceneBlendFactor nValue);
    NGfc2SceneBlendFactor getDestBlendFactor();
    bool hasDestBlendFactor();
    void setDepthTestEnabled(NGfc2Boolean bValue);
    NGfc2Boolean getDepthTestEnabled();
    bool hasDepthTestEnabled();
    void setDepthWriteEnabled(NGfc2Boolean bValue);
    NGfc2Boolean getDepthWriteEnabled();
    bool hasDepthWriteEnabled();
    void setDepthTestFunction(NGfc2FragTestFunc nValue);
    NGfc2FragTestFunc getDepthTestFunction();
    bool hasDepthTestFunction();
    void setPolygonOffsetFactor(NGfc2Double dValue);
    NGfc2Double getPolygonOffsetFactor();
    bool hasPolygonOffsetFactor();
    void setPolygonOffsetUnits(NGfc2Double dValue);
    NGfc2Double getPolygonOffsetUnits();
    bool hasPolygonOffsetUnits();
    void setPolygonStipple(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPolygonStipple();
    bool hasPolygonStipple();
    NGfc2String^ getPolygonStipplePtr();
    void setLineStipplePattern(NGfc2Integer nValue);
    NGfc2Integer getLineStipplePattern();
    bool hasLineStipplePattern();
    void setLineStippleFactor(NGfc2Integer nValue);
    NGfc2Integer getLineStippleFactor();
    bool hasLineStippleFactor();
    void setFaceMode(NGfc2FaceMode nValue);
    NGfc2FaceMode getFaceMode();
    bool hasFaceMode();
    void setLightingEnabled(NGfc2Boolean bValue);
    NGfc2Boolean getLightingEnabled();
    bool hasLightingEnabled();
    void setLightModelTwoSided(NGfc2Boolean bValue);
    NGfc2Boolean getLightModelTwoSided();
    bool hasLightModelTwoSided();

};
#endif
