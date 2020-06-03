#ifndef GFC2COLOR_H
#define GFC2COLOR_H

#include "GfcClasses.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Color: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Color, gfc2::engine::Entity)
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
#endif
