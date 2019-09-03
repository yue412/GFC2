#include "StdAfx.h"
#include "FieldCache.h"

FieldCache* _FieldCache = 0;

void initFieldCache()
{
    if (_FieldCache)
        freeFieldCache();
    _FieldCache = new FieldCache();
}

void freeFieldCache()
{
    delete _FieldCache;
    _FieldCache = 0;
}
