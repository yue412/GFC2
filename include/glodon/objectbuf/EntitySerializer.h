#ifndef ENTITYSERIALIZER_H
#define ENTITYSERIALIZER_H

#include "glodon/objectbuf/Objectbuf.h"
#include "glodon/framework/OBObject.h"
#include "glodon/framework/OBSysMarco.h"
#include <string>
using namespace std;
namespace glodon {
namespace objectbuf {

class Entity;

enum EnParseFieldState {
    PFS_FAIL,
    PFS_SUCCESS,
    PFS_IGNORE
};

class OBJECTBUF_API EntitySerializer: public OBObject
{
    OBJECTBUF_DEC_FACTORY(EntitySerializer, 0, string)
public:
    EntitySerializer();
    virtual ~EntitySerializer(void);
};

}
}

#endif