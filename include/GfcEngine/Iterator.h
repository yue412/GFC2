#ifndef ITERATOR_H
#define ITERATOR_H

#include "GfcEngine\GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

template<class T>
class CIterator
{
public:
    virtual ~CIterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual T current() = 0;
};

GFCENGINE_NAMESPACE_END

#endif // !ITERATOR_H
