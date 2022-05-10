#ifndef GFCSURFACETEXTURE_H
#define GFCSURFACETEXTURE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcMatrix.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSurfaceTexture: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcSurfaceTexture, gfc::engine::CEntity)
public:
    GfcSurfaceTexture();
    GfcSurfaceTexture(bool bSetSchema);
    void setRepeatS(const GfcBoolean& bValue);
    GfcBoolean getRepeatS() const;
    bool hasRepeatS() const;
    void setRepeatT(const GfcBoolean& bValue);
    GfcBoolean getRepeatT() const;
    bool hasRepeatT() const;
    void setImageFileName(const GfcString& sValue);
    GfcString getImageFileName() const;
    bool hasImageFileName() const;
    void setTranfromsMatirx(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTranfromsMatirx() const;
    bool hasTranfromsMatirx() const;
    std::shared_ptr<GfcMatrix> getTranfromsMatirxPtr();
    int getParameterCount() const;
    void clearParameter();
    void addParameter(const GfcString& sValue);
    GfcString getParameter(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
