#ifndef GFCINTERNALCHART_H
#define GFCINTERNALCHART_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcInternalPt.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcInternalChart: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcInternalChart, gfc::engine::CEntity)
public:
    GfcInternalChart();
    GfcInternalChart(bool bSetSchema);
    void setTra1(const GfcDouble& dValue);
    GfcDouble getTra1() const;
    bool hasTra1() const;
    void setTra2(const GfcDouble& dValue);
    GfcDouble getTra2() const;
    bool hasTra2() const;
    void setTra3(const GfcDouble& dValue);
    GfcDouble getTra3() const;
    bool hasTra3() const;
    int getIPSCount() const;
    void clearIPS();
    void addIPS(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getIPS(int nIndex) const;
    std::shared_ptr<GfcInternalPt> getIPSPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
