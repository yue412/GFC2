
#ifndef OB_OBJECT_FACTORY_H
#define OB_OBJECT_FACTORY_H

#include <map> 
#include <utility>
#include <string>
#include <stdint.h>
#include "GfcEngine\Object.h"

#pragma warning(disable : 4251)

GFCENGINE_NAMESPACE_BEGIN

#define    END_REG_ITEM        -1

    template<typename Type> 
    struct GFCENGINE_API RegItem
    {
        RegItem()
        {
            unMode = END_REG_ITEM;
        }

        RegItem(const Type& objType,int64_t mode)
        {
            unObjType = objType;
            unMode = mode;
        }

        Type unObjType;   //注册键值
        int64_t unMode;   //对应的扩展数据
    };

    template<typename Type> 
    class GFCENGINE_API RegObjInfo
    {
    public:
        RegObjInfo()
        {
            m_pCreateFunPtr = NULL;
            m_pUserData = NULL;
        }

        RegObjInfo(CREATETHIS i_pThisFun,const RegItem<Type>& i_regItem)
        {
            m_pCreateFunPtr = i_pThisFun;
            regItem = i_regItem;
            m_pUserData = NULL;
        }

        RegObjInfo(const RegObjInfo<Type>& i_regObjInfo)
        {
            m_pCreateFunPtr = i_regObjInfo.m_pCreateFunPtr;
            regItem = i_regObjInfo.regItem;
            m_pUserData = i_regObjInfo.m_pUserData;
        }

        ~RegObjInfo()
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
        RegItem<Type> regItem;       //注册输入数据
        void* m_pUserData;            //用户数据
    };


    template<typename Type>
    class GFCENGINE_API ObjectFactory
    {
    public:
        ObjectFactory(unsigned int type)
        {
            m_type = type;
            //确保内部没有任何遗留注册项
            m_regHelperMap.clear();
        }

        unsigned int GetType() const
        {
            return m_type;
        }

        virtual Object* Create(const Type& unObjType)
        {
            const RegObjInfo<Type>* pRegObjInfo = FindCreateHelper(unObjType);
            if(pRegObjInfo == NULL)
            {
                return NULL;
            }

            if(pRegObjInfo->GetFunPtr()!=NULL)
            {
                Object* pObj = dynamic_cast<Object*> (pRegObjInfo->GetFunPtr()());
                return pObj;
            }
            else
            {
                return NULL;
            }
        }

        bool IsExist(const Type& unObjType) const
        {
            typename std::map<Type, RegObjInfo<Type> *>::const_iterator iterator;
            iterator = m_regHelperMap.find(unObjType);
            return (iterator == m_regHelperMap.end()) ? false : true;
        }

        bool RegisterCreateHelper(const Type& unObjType,const RegObjInfo<Type>& regInfo) 
        {
            //输入参数判断，避免加入空指针
            if(regInfo.GetFunPtr() == NULL)
            {
                return false;
            }

            //进行注册,如果已经存在，则覆盖以前的注册信息，进行覆盖
            typename std::map<Type,RegObjInfo<Type>* >::const_iterator iterator = m_regHelperMap.find(unObjType);
            if(iterator != m_regHelperMap.end())
            {
                UnRegisterCreateHelper(unObjType);
            }
            RegObjInfo<Type>* pNewObjInfo = new RegObjInfo<Type>;
            *pNewObjInfo = regInfo;

            m_regHelperMap.insert(std::make_pair(unObjType,pNewObjInfo));
            return true;
        }

        bool UnRegisterCreateHelper(const Type& unObjType) 
        {
            typename std::map<Type,RegObjInfo<Type>*>::const_iterator iterator = m_regHelperMap.find(unObjType);
            if(iterator == m_regHelperMap.end())
            {
                return false;
            }
            else
            {
                RegObjInfo<Type>* pObjInfo = (*iterator).second;
                m_regHelperMap.erase(iterator);
                if(pObjInfo != NULL)
                {
                    delete pObjInfo;
                }

                return true;
            }
        }


        const RegObjInfo<Type>* FindCreateHelper(const Type& unObjType) const
        {
            typename std::map<Type,RegObjInfo<Type>*>::const_iterator iterator = m_regHelperMap.find(unObjType);
            if(iterator == m_regHelperMap.end())
            {
                return NULL;
            }
            else
            {
                return (*iterator).second;
            }
        }

        virtual ~ObjectFactory()
        {
            typename std::map<Type,RegObjInfo<Type>*>::iterator iterator;
            typename std::map<Type,RegObjInfo<Type>*>::iterator endIterator = m_regHelperMap.end();
            for(iterator = m_regHelperMap.begin(); iterator != endIterator; iterator++ )
            {
                RegObjInfo<Type>* pObjInfo = (*iterator).second;
                if(pObjInfo != NULL)
                {
                    delete pObjInfo;
                }
            }

            //清空所有注册项
            m_regHelperMap.clear();
        }

        typename std::map<Type, RegObjInfo<Type>*>::iterator begin()
        {
            return m_regHelperMap.begin();
        }

        typename std::map<Type, RegObjInfo<Type>*>::iterator end()
        {
            return m_regHelperMap.end();
        }

    private:
        std::map<Type,RegObjInfo<Type>*> m_regHelperMap;  //子类注册信息表
        unsigned int m_type;                               //类厂的类型

    };

GFCENGINE_NAMESPACE_END

#endif