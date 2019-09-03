#ifndef GLODON_OBJECTBUF_ENTITYSCHEMA_H
#define GLODON_OBJECTBUF_ENTITYSCHEMA_H

#include <vector>
#include <string>
#include "Entity.h"
#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

class OBJECTBUF_API EntitySchema: public glodon::objectbuf::Entity
{
public:
    EntitySchema(void);
    ~EntitySchema(void);
    bool isInitialized() const;
    int typeId() const;
    virtual string entityName() const;

    void setName(const string& sValue)
    {
        m_sName = sValue;
        setHasName();
    }
    string getName() const {return m_sName;}
    bool hasName() const {return (_has_bits_[0] & 0x1u) != 0;}

    void setId(const int& nValue)
    {
        m_nId = nValue;
        setHasId();
    }
    int getId() const {return m_nId;}
    bool hasId() const {return (_has_bits_[0] & 0x2u) != 0;}

    int getAttribNamesCount() const {return (int)m_oAttribNames.size();}
    void clearAttribNames() {m_oAttribNames.clear();}
    void addAttribNames(const string& sValue) {m_oAttribNames.push_back(sValue);}
    string getAttribNames(int nIndex) const {return m_oAttribNames[nIndex];}

    int getAttribIdsCount() const {return (int)m_oAttribIds.size();}
    void clearAttribIds() {m_oAttribIds.clear();}
    void addAttribIds(const int& nValue) {m_oAttribIds.push_back(nValue);}
    int getAttribIds(int nIndex) const {return m_oAttribIds[nIndex];}

    void setParent(EntitySchema* pParent) {m_pParent = pParent;}
    EntitySchema* getParent() {return m_pParent;}
    void addChild(EntitySchema* pChild) {m_oChildren.push_back(pChild);}
    void getChildren(std::vector<EntitySchema*>& oChildren) {oChildren = m_oChildren;}

// protected:
//     virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output) const;
//     virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target) const;
//     virtual EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum);

protected:
    unsigned int _has_bits_[1];

private:
    void setHasName() {_has_bits_[0] |= 0x1u;}
    void setHasId() {_has_bits_[0] |= 0x2u;}

    string m_sName;
    int m_nId;
    std::vector<string> m_oAttribNames;
    std::vector<int> m_oAttribIds;
    EntitySchema* m_pParent;
    std::vector<EntitySchema*> m_oChildren;
};

}
}

#endif