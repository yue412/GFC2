#ifndef GFCENGINE_H
#define GFCENGINE_H


#if (defined _WIN32 || defined _WIN64)
    #ifdef GFCENGINE_EXPORTS
    #define GFCENGINE_API __declspec(dllexport)
    #else
    #define GFCENGINE_API __declspec(dllimport)
    #endif
#else
    #ifdef GFCENGINE_EXPORTS
    #define GFCENGINE_API 
    #else
    #define GFCENGINE_API 
    #endif
	#define CP_UTF8                   65001       // UTF-8 translation
#endif

#define GFCENGINE_NAMESPACE_BEGIN namespace gfc { namespace engine {
#define GFCENGINE_NAMESPACE_END } }

GFCENGINE_NAMESPACE_BEGIN

typedef int EntityRef;

GFCENGINE_NAMESPACE_END

#pragma warning(disable:4251)

#endif