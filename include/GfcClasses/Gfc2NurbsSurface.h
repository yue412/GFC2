#ifndef GFC2NURBSSURFACE_H
#define GFC2NURBSSURFACE_H

#include "GfcClasses.h"
#include "Gfc2Surface.h"
#include "Gfc2NurbsCtrlPt3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2NurbsSurface: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2NurbsSurface, gfc::engine::CEntity)
public:
    Gfc2NurbsSurface();
    Gfc2NurbsSurface(bool bSetSchema);
    void setDegreeU(const Gfc2Integer& nValue);
    Gfc2Integer getDegreeU() const;
    bool hasDegreeU() const;
    void setDegreeV(const Gfc2Integer& nValue);
    Gfc2Integer getDegreeV() const;
    bool hasDegreeV() const;
    void setCtrlPtCountU(const Gfc2Integer& nValue);
    Gfc2Integer getCtrlPtCountU() const;
    bool hasCtrlPtCountU() const;
    void setCtrlPtCountV(const Gfc2Integer& nValue);
    Gfc2Integer getCtrlPtCountV() const;
    bool hasCtrlPtCountV() const;
    int getCtrlPtsCount() const;
    void clearCtrlPts();
    void addCtrlPts(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2NurbsCtrlPt3d> getCtrlPtsPtr(int nIndex);
    int getKnotsUCount() const;
    void clearKnotsU();
    void addKnotsU(const Gfc2Double& dValue);
    Gfc2Double getKnotsU(int nIndex) const;
    int getKnotsVCount() const;
    void clearKnotsV();
    void addKnotsV(const Gfc2Double& dValue);
    Gfc2Double getKnotsV(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
