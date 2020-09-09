#ifndef GFC2SURFACETEXTURE_H
#define GFC2SURFACETEXTURE_H

#include "GfcClasses.h"
#include "Gfc2Matrix.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SurfaceTexture: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2SurfaceTexture, gfc::engine::CEntity)
public:
    Gfc2SurfaceTexture();
    Gfc2SurfaceTexture(bool bSetSchema);
    void setRepeatS(const Gfc2Boolean& bValue);
    Gfc2Boolean getRepeatS() const;
    bool hasRepeatS() const;
    void setRepeatT(const Gfc2Boolean& bValue);
    Gfc2Boolean getRepeatT() const;
    bool hasRepeatT() const;
    void setImageFileName(const Gfc2String& sValue);
    Gfc2String getImageFileName() const;
    bool hasImageFileName() const;
    void setTranfromsMatirx(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTranfromsMatirx() const;
    bool hasTranfromsMatirx() const;
    gfc::engine::CEntityWrapPtr<Gfc2Matrix> getTranfromsMatirxPtr();
    int getParameterCount() const;
    void clearParameter();
    void addParameter(const Gfc2String& sValue);
    Gfc2String getParameter(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
