#ifndef NGFCTEXTURECOORDLIST_H
#define NGFCTEXTURECOORDLIST_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcTextureCoordList.h"
#include "NTypeDef.h"

public ref class NGfcTextureCoordList: public NGfcRoot
{
public:
    NGfcTextureCoordList();
    NGfcTextureCoordList(bool bNoCreate);
    int getTexCoordsCount();
    void clearTexCoords();
    void addTexCoords(NGfcDouble dValue);
    NGfcDouble getTexCoords(int nIndex);
    int getTexCoordIndexCount();
    void clearTexCoordIndex();
    void addTexCoordIndex(NGfcInteger nValue);
    NGfcInteger getTexCoordIndex(int nIndex);

};
#endif
