#ifndef GFCTEXTURECOORDLIST_H
#define GFCTEXTURECOORDLIST_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcTextureCoordList: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcTextureCoordList, gfc::engine::CEntity)
public:
    GfcTextureCoordList();
    GfcTextureCoordList(bool bSetSchema);
    int getTexCoordsCount() const;
    void clearTexCoords();
    void addTexCoords(const GfcDouble& dValue);
    GfcDouble getTexCoords(int nIndex) const;
    int getTexCoordIndexCount() const;
    void clearTexCoordIndex();
    void addTexCoordIndex(const GfcInteger& nValue);
    GfcInteger getTexCoordIndex(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
