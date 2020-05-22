
#ifndef OB_REG_HELPER_H
#define OB_REG_HELPER_H

#include <stdint.h>
#include "GfcEngine/Object.h"
#include "GfcEngine/ObjectFactory.h"

GFCENGINE_NAMESPACE_BEGIN

template<typename Type> 
class GFCENGINE_API RegHelper
{
public:
    virtual ~RegHelper()
    {
    }

    RegHelper(const RegItem<Type>& regItem,CREATETHIS funPtr,ObjectFactory<Type>* pFactory)
    {
        if(pFactory != NULL)
        {
            pFactory->RegisterCreateHelper(regItem.unObjType,RegObjInfo<Type>(funPtr,regItem));
        }
    }
};

GFCENGINE_NAMESPACE_END

#endif