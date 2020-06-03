#ifndef GFCENGINE_H
#define GFCENGINE_H

#ifdef GFCENGINE_EXPORTS
#define GFCENGINE_API __declspec(dllexport)
#else
#define GFCENGINE_API __declspec(dllimport)
#endif

#define GFCENGINE_NAMESPACE_BEGIN namespace gfc { namespace engine {
#define GFCENGINE_NAMESPACE_END } }

GFCENGINE_NAMESPACE_BEGIN

typedef int EntityRef;

GFCENGINE_NAMESPACE_END

//#pragma warning(disable:4251)

#endif