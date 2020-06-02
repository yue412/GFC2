#ifndef GFC2INTERNALCHART_H
#define GFC2INTERNALCHART_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2InternalPt.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2InternalChart: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2InternalChart,gfc2::engine::EntityFactory)
public:
    Gfc2InternalChart();
    Gfc2InternalChart(bool bSetSchema);
    void setTra1(const Gfc2Double& dValue);
    Gfc2Double getTra1() const;
    bool hasTra1() const;
    void setTra2(const Gfc2Double& dValue);
    Gfc2Double getTra2() const;
    bool hasTra2() const;
    void setTra3(const Gfc2Double& dValue);
    Gfc2Double getTra3() const;
    bool hasTra3() const;
    int getIPSCount() const;
    void clearIPS();
    void addIPS(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getIPS(int nIndex) const;
    std::shared_ptr<Gfc2InternalPt> getIPSPtr(int nIndex);

};
#endif
