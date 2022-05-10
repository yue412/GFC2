#ifndef GFCMATRIX_H
#define GFCMATRIX_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcMatrix: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcMatrix, gfc::engine::CEntity)
public:
    GfcMatrix();
    GfcMatrix(bool bSetSchema);
    void setDim(const GfcInteger& nValue);
    GfcInteger getDim() const;
    bool hasDim() const;
    int getDataCount() const;
    void clearData();
    void addData(const GfcDouble& dValue);
    GfcDouble getData(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
