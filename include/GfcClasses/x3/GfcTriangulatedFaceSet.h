#ifndef GFCTRIANGULATEDFACESET_H
#define GFCTRIANGULATEDFACESET_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRepresentationItem.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcTriangulatedFaceSet: public GfcRepresentationItem
{
GFCENGINE_DEC_OBJECT(GfcTriangulatedFaceSet, gfc::engine::CEntity)
public:
    GfcTriangulatedFaceSet();
    GfcTriangulatedFaceSet(bool bSetSchema);
    void setExtension(const GfcString& sValue);
    GfcString getExtension() const;
    bool hasExtension() const;
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const GfcDouble& dValue);
    GfcDouble getVertexes(int nIndex) const;
    int getNormalsCount() const;
    void clearNormals();
    void addNormals(const GfcDouble& dValue);
    GfcDouble getNormals(int nIndex) const;
    int getVertexIndexCount() const;
    void clearVertexIndex();
    void addVertexIndex(const GfcInteger& nValue);
    GfcInteger getVertexIndex(int nIndex) const;
    int getNormalIndexCount() const;
    void clearNormalIndex();
    void addNormalIndex(const GfcInteger& nValue);
    GfcInteger getNormalIndex(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
