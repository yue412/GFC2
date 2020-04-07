#ifndef GFC2MATRIX_H
#define GFC2MATRIX_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Geometry.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Matrix: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Matrix,glodon::objectbuf::Entity)
public:
    Gfc2Matrix();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setDim(const Gfc2Integer& nValue)
    {
        m_nDim = nValue;
        setHasDim();
    }
    Gfc2Integer getDim() const {return m_nDim;}
    bool hasDim() const {return (_has_bits_[0] & 0x1u) != 0;}
    int getDataCount() const {return (int)m_oData.size();}
    void clearData() {m_oData.clear();}
    void addData(const Gfc2Double& dValue) {m_oData.push_back(dValue);}
    Gfc2Double getData(int nIndex) const {return m_oData[nIndex];}

private:
    void setHasDim() {_has_bits_[0] |= 0x1u;}

    Gfc2Integer m_nDim;
    std::vector<Gfc2Double> m_oData;
};
#endif
