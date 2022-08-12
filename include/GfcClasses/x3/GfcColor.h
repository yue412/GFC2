#ifndef GFCCOLOR_H
#define GFCCOLOR_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcColor: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcColor, gfc::engine::CEntity)
public:
    GfcColor();
    GfcColor(bool bSetSchema);
    void setRed(const GfcInteger& nValue);
    GfcInteger getRed() const;
    bool hasRed() const;
    void setGreen(const GfcInteger& nValue);
    GfcInteger getGreen() const;
    bool hasGreen() const;
    void setBlue(const GfcInteger& nValue);
    GfcInteger getBlue() const;
    bool hasBlue() const;
    void setAlpha(const GfcInteger& nValue);
    GfcInteger getAlpha() const;
    bool hasAlpha() const;

};

GFCCLASSES_NAMESPACE_END

#endif
