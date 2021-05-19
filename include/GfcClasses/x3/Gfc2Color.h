#ifndef GFC2COLOR_H
#define GFC2COLOR_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Color: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2Color, gfc::engine::CEntity)
public:
    Gfc2Color();
    Gfc2Color(bool bSetSchema);
    void setRed(const Gfc2Integer& nValue);
    Gfc2Integer getRed() const;
    bool hasRed() const;
    void setGreen(const Gfc2Integer& nValue);
    Gfc2Integer getGreen() const;
    bool hasGreen() const;
    void setBlue(const Gfc2Integer& nValue);
    Gfc2Integer getBlue() const;
    bool hasBlue() const;
    void setAlpha(const Gfc2Integer& nValue);
    Gfc2Integer getAlpha() const;
    bool hasAlpha() const;

};

GFCCLASSES_NAMESPACE_END

#endif
