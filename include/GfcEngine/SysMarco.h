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
	typedef ObjectFactory<RegKeyType> ObjectFactory;\
    class RegClearHelper \
    {\
    public:\
        RegClearHelper()\
        {\
        }\
        virtual ~RegClearHelper()\
        {\
            if(className::s_pClassFactory != NULL)\
            {\
                delete className::s_pClassFactory;\
                className::s_pClassFactory = NULL;\
             }\
        }\
     };\
protected:\
    static ObjectFactory* s_pClassFactory;\
    static RegClearHelper m_autoRegClear;\
public:\
    static ObjectFactory* GetFactory()\
    {\
        if(s_pClassFactory == NULL)\
        {\
            s_pClassFactory = new ObjectFactory(factoryType);\
        }\
        return s_pClassFactory;\
    }

#define GFCENGINE_IMP_FACTORY(className,factoryType) \
className::ObjectFactory* className::s_pClassFactory = NULL;\
className::RegClearHelper className::m_autoRegClear;


#define GFCENGINE_DEC_OBJECT(className,factoryClassName) \
public:\
    typedef className thisClass;\
    typedef factoryClassName baseClassName;\
    typedef gfc2::engine::RegItem<baseClassName::RegKeyType> ClassRegItem; \
    typedef gfc2::engine::RegHelper<baseClassName::RegKeyType> ClassRegHelper; \
public:\
    static ClassRegHelper s_##className##RegHelper; \
    static gfc2::engine::Object* CreateInstance()\
    { \
        return dynamic_cast<gfc2::engine::Object*> (new className); \
    }\
    static baseClassName::ObjectFactory* GetFactory() \
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
