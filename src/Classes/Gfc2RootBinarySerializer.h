#ifndef GFC2ROOTBINARYSERIALIZER_H
#define GFC2ROOTBINARYSERIALIZER_H

#include "glodon/objectbuf/EntityBinarySerializer.h"

class Gfc2RootBinarySerializer: public glodon::objectbuf::EntityBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2RootBinarySerializer,glodon::objectbuf::EntitySerializer)
};
#endif
