#ifndef GFC2SURFACETEXTURE_H
#define GFC2SURFACETEXTURE_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "Gfc2Matrix.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SurfaceTexture: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2SurfaceTexture, gfc2::engine::Entity)
public:
    Gfc2SurfaceTexture();
    Gfc2SurfaceTexture(bool bSetSchema);
    void setRepeatS(const Gfc2Boolean& bValue);
    Gfc2Boolean getRepeatS() const;
    bool hasRepeatS() const;
    void setRepeatT(const Gfc2Boolean& bValue);
    Gfc2Boolean getRepeatT() const;
    bool hasRepeatT() const;
    void setImageFileName(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getImageFileName() const;
    bool hasImageFileName() const;
    std::shared_ptr<Gfc2String> getImageFileNamePtr();
    void setTranfromsMatirx(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getTranfromsMatirx() const;
    bool hasTranfromsMatirx() const;
    std::shared_ptr<Gfc2Matrix> getTranfromsMatirxPtr();
    int getParameterCount() const;
    void clearParameter();
    void addParameter(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getParameter(int nIndex) const;
    std::shared_ptr<Gfc2String> getParameterPtr(int nIndex);

};
#endif
