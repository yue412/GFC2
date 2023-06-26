#ifndef SCHEMAMACRO_H
#define SCHEMAMACRO_H
#if (defined _WIN32 || defined _WIN64)
    #ifdef GFCSCHEMA_EXPORTS
    #define GFCSCHEMA_API __declspec(dllexport)
    #else
    #define GFCSCHEMA_API __declspec(dllimport)
    #endif
#else
    #ifdef GFCSCHEMA_EXPORTS
    #define GFCSCHEMA_API 
    #else
    #define GFCSCHEMA_API 
    #endif
#endif


#define GFC_NAMESPACE_BEGIN namespace gfc { namespace schema {
#define GFC_NAMESPACE_END }}

#pragma warning(disable:4251)

#include <string>
#include <vector>

#endif // !SCHEMAMACRO_H