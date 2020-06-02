#ifndef GFC2MATRIX_H
#define GFC2MATRIX_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Geometry.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Matrix: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Matrix,gfc2::engine::EntityFactory)
public:
    Gfc2Matrix();
    Gfc2Matrix(bool bSetSchema);
    void setDim(const Gfc2Integer& nValue);
    Gfc2Integer getDim() const;
    bool hasDim() const;
    int getDataCount() const;
    void clearData();
    void addData(const Gfc2Double& dValue);
    Gfc2Double getData(int nIndex) const;

};
#endif
