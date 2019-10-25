
#ifndef OB_OBJECT_H
#define OB_OBJECT_H
#pragma warning( push ,1)
#pragma warning( pop )  
#pragma warning( disable: 4251 )

#include <assert.h>
#include "glodon\objectbuf\Objectbuf.h"

namespace glodon {
	namespace objectbuf
{
    class  OBJECTBUF_API OBObject
    {
    public:
        OBObject(){};
        virtual ~OBObject(){};
    };

    typedef OBObject* (*CREATETHIS)();
}
}

#endif
