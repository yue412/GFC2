#ifndef OB_SYS_MACRO_H
#define OB_SYS_MACRO_H

#include <math.h>
#include <map>
#include <string>
#include "GfcEngine\RegHelper.h"

//namespace glodon
//{
//    namespace objectbuf
//    {
//        extern GFCENGINE_API std::map<std::string, int> g_oOBObjCount;
//        extern GFCENGINE_API std::map<std::string, std::map<int, int> > g_nOBObjSize;
//    }
//}

#define GFCENGINE_DEC_FACTORY(className,factoryType,classKeyType) \
public: \
    typedef classKeyType RegKeyType;\
	typedef CObjectFactory<RegKeyType> CObjectFactory;\
    class CRegClearHelper \
    {\
    public:\
        CRegClearHelper()\
        {\
        }\
        virtual ~CRegClearHelper()\
        {\
            if(className::s_pClassFactory != NULL)\
            {\
                delete className::s_pClassFactory;\
                className::s_pClassFactory = NULL;\
             }\
        }\
     };\
protected:\
    static CObjectFactory* s_pClassFactory;\
    static CRegClearHelper m_autoRegClear;\
public:\
    static CObjectFactory* GetFactory()\
    {\
        if(s_pClassFactory == NULL)\
        {\
            s_pClassFactory = new CObjectFactory(factoryType);\
        }\
        return s_pClassFactory;\
    }

#define GFCENGINE_IMP_FACTORY(className,factoryType) \
className::CObjectFactory* className::s_pClassFactory = NULL;\
className::CRegClearHelper className::m_autoRegClear;


#define GFCENGINE_DEC_OBJECT(className,factoryClassName) \
public:\
    typedef className thisClass;\
    typedef factoryClassName baseClassName;\
    typedef gfc::engine::CRegItem<baseClassName::RegKeyType> ClassRegItem; \
    typedef gfc::engine::CRegHelper<baseClassName::RegKeyType> ClassRegHelper; \
public:\
    static ClassRegHelper s_##className##RegHelper; \
    static gfc::engine::CObject* CreateInstance()\
    { \
        return dynamic_cast<gfc::engine::CObject*> (new className); \
    }\
    static baseClassName::CObjectFactory* GetFactory() \
    {\
        return baseClassName::GetFactory();\
    }

#define GFCENGINE_IMP_OBJECT(className,objType,mode)\
className::ClassRegHelper className::s_##className##RegHelper(className::ClassRegItem(objType,mode),className::CreateInstance,className::baseClassName::GetFactory());

    /*
    replace line 65 to output memory size
        std::string sClassName = typeid(className).name(); \
        glodon::objectbuf::g_oOBObjCount[sClassName]++; \
        className* pResult = new className; \
        glodon::objectbuf::g_nOBObjSize[sClassName][sizeof(className)]++; \
        return dynamic_cast<baseClassName*>(pResult); \
    */

#endif
