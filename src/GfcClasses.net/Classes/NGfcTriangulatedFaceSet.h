#ifndef NGFCTRIANGULATEDFACESET_H
#define NGFCTRIANGULATEDFACESET_H

#include "NGfcRepresentationItem.h"
#include "GfcClasses\x3\GfcTriangulatedFaceSet.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcTriangulatedFaceSet: public NGfcRepresentationItem
{
public:
    NGfcTriangulatedFaceSet();
    NGfcTriangulatedFaceSet(bool bNoCreate);
    void setExtension(NGfcString sValue);
    NGfcString getExtension();
    bool hasExtension();
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(NGfcDouble dValue);
    NGfcDouble getVertexes(int nIndex);
    int getNormalsCount();
    void clearNormals();
    void addNormals(NGfcDouble dValue);
    NGfcDouble getNormals(int nIndex);
    int getVertexIndexCount();
    void clearVertexIndex();
    void addVertexIndex(NGfcInteger nValue);
    NGfcInteger getVertexIndex(int nIndex);
    int getNormalIndexCount();
    void clearNormalIndex();
    void addNormalIndex(NGfcInteger nValue);
    NGfcInteger getNormalIndex(int nIndex);

};
#endif
