#ifndef EXPENGINEEXCEPTION_H
#define EXPENGINEEXCEPTION_H

#include <exception>
#include "GfcEngine\GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

class EMissMatchProperty : public std::exception
{
public:
    EMissMatchProperty() {}
public:
    virtual char const* what() const { return "Miss Match Property exception"; }  //获取具体的错误信息
};

class ETypeMatchError : public std::exception
{
public:
    ETypeMatchError() {}
public:
    virtual char const* what() const { return "Type match error"; }  //获取具体的错误信息
};

GFCENGINE_NAMESPACE_END

#endif // !EXPENGINEEXCEPTION_H

