#ifndef ENTITYTEXTSERIALIZER_H
#define ENTITYTEXTSERIALIZER_H

#include "glodon/objectbuf/EntitySerializer.h"
#include "glodon/objectbuf/Objectbuf.h"
#include "glodon/objectbuf/Entity.h"

namespace glodon {
namespace objectbuf {

class OBJECTBUF_API EntityTextSerializer : public EntitySerializer
{
public:
    EntityTextSerializer(void);
    virtual ~EntityTextSerializer(void);
    virtual string serialize(Entity* pEntity) const;
    bool parse(const string& input, Entity* pEntity,std::string& error);
protected:
    virtual EnParseFieldState parseField(const string& input, int nFieldNum, Entity* pEntity);
    bool getNextValue(const string& input, int nStartPos, string& sValue);
    bool readBooleanField(const string& input, bool& value);
    bool readIntField(const string& input, int& value);
    bool readFloatField(const string& input, double& value);
    bool readStringField(const string& input, string& value);
    bool readEntityField(const string& input, EntityRef& value);
};

}
}

#endif
