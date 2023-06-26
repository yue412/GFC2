
#ifndef OB_OBJECT_H
#define OB_OBJECT_H
#pragma warning( push ,1)
#pragma warning( pop )  
#pragma warning( disable: 4251 )

#include <assert.h>
#include "GfcEngine/GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

class GFCENGINE_API CObject
{
public:
    CObject(){};
    virtual ~CObject(){};
};

typedef CObject* (*CREATETHIS)();

GFCENGINE_NAMESPACE_END

#endif
