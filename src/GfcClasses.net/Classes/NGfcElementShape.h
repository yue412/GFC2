#ifndef NGFCELEMENTSHAPE_H
#define NGFCELEMENTSHAPE_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcElementShape.h"
#include "NGfcShape.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcElementShape: public NGfcRoot
{
public:
    NGfcElementShape();
    NGfcElementShape(bool bNoCreate);
    void setIdentifier(NGfcString sValue);
    NGfcString getIdentifier();
    bool hasIdentifier();
    void setShape(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getShape();
    bool hasShape();

};
#endif
