#ifndef GLODON_OBJECTBUF_FIELDCACHEINITIALIZER_H
#define GLODON_OBJECTBUF_FIELDCACHEINITIALIZER_H

#include <map>
#include <string>
#include "glodon/objectbuf/Objectbuf.h"
#include "glodon/framework/OBSysMarco.h"
#include "glodon/framework/OBObject.h"
using namespace std;
namespace glodon {
namespace objectbuf {

class FieldCacheInitializer: public OBObject
{
    OBJECTBUF_DEC_FACTORY(FieldCacheInitializer, 0, string)
public:
    FieldCacheInitializer(void);
    ~FieldCacheInitializer(void);
    int getFieldId(const std::map<string, int>& oFieldIdMap, const string& sName)
    {
        auto oItr = oFieldIdMap.find(sName);
        return oItr == oFieldIdMap.end() ? 0 : oItr->second;
    }
    virtual void init(const std::map<string, int>& oFieldIdMap) = 0;
};

}
}

#endif