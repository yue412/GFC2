
#ifndef OB_REG_HELPER_H
#define OB_REG_HELPER_H

#include <stdint.h>
#include "GfcEngine/Object.h"
#include "GfcEngine/ObjectFactory.h"

GFCENGINE_NAMESPACE_BEGIN

template<typename Type> 
class GFCENGINE_API CRegHelper
{
public:
    virtual ~CRegHelper()
    {
    }

    CRegHelper(const CRegItem<Type>& regItem,CREATETHIS funPtr,CObjectFactory<Type>* pFactory)
    {
        if(pFactory != NULL)
        {
            pFactory->RegisterCreateHelper(regItem.unObjType,CRegObjInfo<Type>(funPtr,regItem));
        }
    }
};

GFCENGINE_NAMESPACE_END

#endif