
#ifndef OB_OBJECT_FACTORY_H
#define OB_OBJECT_FACTORY_H

#include <map> 
#include <utility>
#include <string>
#include <stdint.h>
#include "OBObject.h"

#pragma warning(disable : 4251)

namespace glodon {
	namespace objectbuf {

#define    END_REG_ITEM        -1

    template<typename Type> 
    struct OBJECTBUF_API OBRegItem
    {
        OBRegItem()
        {
            unMode = END_REG_ITEM;
        }

        OBRegItem(const Type& objType,int64_t mode)
        {
            unObjType = objType;
            unMode = mode;
        }

        Type unObjType;   //注册键值
        int64_t unMode;   //对应的扩展数据
    };

    template<typename Type> 
    class OBJECTBUF_API OBRegObjInfo
    {
    public:
        OBRegObjInfo()
        {
            m_pCreateFunPtr = NULL;
            m_pUserData = NULL;
        }

        OBRegObjInfo(CREATETHIS i_pThisFun,const OBRegItem<Type>& i_regItem)
        {
            m_pCreateFunPtr = i_pThisFun;
            regItem = i_regItem;
            m_pUserData = NULL;
        }

        OBRegObjInfo(const OBRegObjInfo<Type>& i_regObjInfo)
        {
            m_pCreateFunPtr = i_regObjInfo.m_pCreateFunPtr;
            regItem = i_regObjInfo.regItem;
            m_pUserData = i_regObjInfo.m_pUserData;
        }

        ~OBRegObjInfo()
        {
        }

        const Type& GetType() const
        {
            return regItem.unObjType;
        }

        int64_t GetMode() const
        {
            return regItem.unMode;
        }

        void SetUserData(void* pUserData)
        {
            m_pUserData = pUserData;
        }

        void* GetUserData() const
        {
            return m_pUserData;
        }

        CREATETHIS GetFunPtr() const
        {
            return m_pCreateFunPtr;
        }
    private:
        CREATETHIS m_pCreateFunPtr;   //函数指针
        OBRegItem<Type> regItem;       //注册输入数据
        void* m_pUserData;            //用户数据
    };


    template<typename Type>
    class OBJECTBUF_API OBObjectFactory
    {
    public:
        OBObjectFactory(unsigned int type)
        {
            m_type = type;
            //确保内部没有任何遗留注册项
            m_regHelperMap.clear();
        }

        unsigned int GetType() const
        {
            return m_type;
        }

        virtual OBObject* Create(const Type& unObjType)
        {
            const OBRegObjInfo<Type>* pRegObjInfo = FindCreateHelper(unObjType);
            if(pRegObjInfo == NULL)
            {
                return NULL;
            }

            if(pRegObjInfo->GetFunPtr()!=NULL)
            {
                OBObject* pObj = dynamic_cast<OBObject*> (pRegObjInfo->GetFunPtr()());
                return pObj;
            }
            else
            {
                return NULL;
            }
        }

        bool IsExist(const Type& unObjType) const
        {
            typename std::map<Type, OBRegObjInfo<Type> *>::const_iterator iterator;
            iterator = m_regHelperMap.find(unObjType);
            return (iterator == m_regHelperMap.end()) ? false : true;
        }

        bool RegisterCreateHelper(const Type& unObjType,const OBRegObjInfo<Type>& regInfo) 
        {
            //输入参数判断，避免加入空指针
            if(regInfo.GetFunPtr() == NULL)
            {
                return false;
            }

            //进行注册,如果已经存在，则覆盖以前的注册信息，进行覆盖
            typename std::map<Type,OBRegObjInfo<Type>* >::const_iterator iterator = m_regHelperMap.find(unObjType);
            if(iterator != m_regHelperMap.end())
            {
                UnRegisterCreateHelper(unObjType);
            }
            OBRegObjInfo<Type>* pNewObjInfo = new OBRegObjInfo<Type>;
            *pNewObjInfo = regInfo;

            m_regHelperMap.insert(std::make_pair(unObjType,pNewObjInfo));
            return true;
        }

        bool UnRegisterCreateHelper(const Type& unObjType) 
        {
            typename std::map<Type,OBRegObjInfo<Type>*>::const_iterator iterator = m_regHelperMap.find(unObjType);
            if(iterator == m_regHelperMap.end())
            {
                return false;
            }
            else
            {
                OBRegObjInfo<Type>* pObjInfo = (*iterator).second;
                m_regHelperMap.erase(iterator);
                if(pObjInfo != NULL)
                {
                    delete pObjInfo;
                }

                return true;
            }
        }


        const OBRegObjInfo<Type>* FindCreateHelper(const Type& unObjType) const
        {
            typename std::map<Type,OBRegObjInfo<Type>*>::const_iterator iterator = m_regHelperMap.find(unObjType);
            if(iterator == m_regHelperMap.end())
            {
                return NULL;
            }
            else
            {
                return (*iterator).second;
            }
        }

        virtual ~OBObjectFactory()
        {
            typename std::map<Type,OBRegObjInfo<Type>*>::iterator iterator;
            typename std::map<Type,OBRegObjInfo<Type>*>::iterator endIterator = m_regHelperMap.end();
            for(iterator = m_regHelperMap.begin(); iterator != endIterator; iterator++ )
            {
                OBRegObjInfo<Type>* pObjInfo = (*iterator).second;
                if(pObjInfo != NULL)
                {
                    delete pObjInfo;
                }
            }

            //清空所有注册项
            m_regHelperMap.clear();
        }


    private:
        std::map<Type,OBRegObjInfo<Type>*> m_regHelperMap;  //子类注册信息表
        unsigned int m_type;                               //类厂的类型

    };

}
}
#endif