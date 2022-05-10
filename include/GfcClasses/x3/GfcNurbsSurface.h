#ifndef GFCNURBSSURFACE_H
#define GFCNURBSSURFACE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcNurbsCtrlPt3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcNurbsSurface: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcNurbsSurface, gfc::engine::CEntity)
public:
    GfcNurbsSurface();
    GfcNurbsSurface(bool bSetSchema);
    void setDegreeU(const GfcInteger& nValue);
    GfcInteger getDegreeU() const;
    bool hasDegreeU() const;
    void setDegreeV(const GfcInteger& nValue);
    GfcInteger getDegreeV() const;
    bool hasDegreeV() const;
    void setCtrlPtCountU(const GfcInteger& nValue);
    GfcInteger getCtrlPtCountU() const;
    bool hasCtrlPtCountU() const;
    void setCtrlPtCountV(const GfcInteger& nValue);
    GfcInteger getCtrlPtCountV() const;
    bool hasCtrlPtCountV() const;
    int getCtrlPtsCount() const;
    void clearCtrlPts();
    void addCtrlPts(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex) const;
    std::shared_ptr<GfcNurbsCtrlPt3d> getCtrlPtsPtr(int nIndex);
    int getKnotsUCount() const;
    void clearKnotsU();
    void addKnotsU(const GfcDouble& dValue);
    GfcDouble getKnotsU(int nIndex) const;
    int getKnotsVCount() const;
    void clearKnotsV();
    void addKnotsV(const GfcDouble& dValue);
    GfcDouble getKnotsV(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
