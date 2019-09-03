
#ifndef OB_REG_HELPER_H
#define OB_REG_HELPER_H

#include <stdint.h>
#include "OBObject.h"
#include "OBObjectFactory.h"

namespace glodon {
	namespace objectbuf {

template<typename Type> 
class OBJECTBUF_API OBRegHelper
{
public:
    virtual ~OBRegHelper()
    {
    }

    OBRegHelper(const OBRegItem<Type>& regItem,CREATETHIS funPtr,OBObjectFactory<Type>* pFactory)
    {
        if(pFactory != NULL)
        {
            pFactory->RegisterCreateHelper(regItem.unObjType,OBRegObjInfo<Type>(funPtr,regItem));
        }
    }
};

}
}

#endif