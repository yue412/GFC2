#ifndef EXPENGINEEXCEPTION_H
#define EXPENGINEEXCEPTION_H

#include <exception>
#include "GfcEngine/GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

#if (defined _WIN32 || defined _WIN64)
#define _GLIBCXX_USE_NOEXCEPT
#endif

class EMissMatchProperty : public std::exception
{
public:
    EMissMatchProperty() {}
public:
    virtual char const* what() const _GLIBCXX_USE_NOEXCEPT { return "Miss Match Property exception"; }  //获取具体的错误信息
};

class ETypeMatchError : public std::exception
{
public:
    ETypeMatchError() {}
public:
    virtual char const* what() const _GLIBCXX_USE_NOEXCEPT { return "Type match error"; }  //获取具体的错误信息
};

GFCENGINE_NAMESPACE_END

#endif // !EXPENGINEEXCEPTION_H

