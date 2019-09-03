#ifndef GLODON_OBJECTBUF_ENTITY_H
#define GLODON_OBJECTBUF_ENTITY_H

#include <vector>
//#include <google/protobuf/io/coded_stream.h>
#include <string>
#include "glodon/objectbuf/Objectbuf.h"
#include "glodon/framework/OBSysMarco.h"
using namespace std;
//using namespace google::protobuf;

namespace glodon {
namespace objectbuf {

extern OBJECTBUF_API std::map<std::string, int> g_oOBObjCount;
extern OBJECTBUF_API std::map<std::string, std::map<int, int> > g_nOBObjSize;

OBJECTBUF_API std::map<std::string, int>* getOBObjCount();
OBJECTBUF_API std::map<std::string, std::map<int, int> >* getOBObjSize();

class EntitySchema;

// enum EnParseFieldState {
//     PFS_FAIL,
//     PFS_SUCCESS,
//     PFS_IGNORE
// };

class EMissMatchProperty : public exception
{
public:
    EMissMatchProperty() {}
public:
    virtual char const* what() const { return "Miss Match Property exception"; }  //获取具体的错误信息
};

class Document;

typedef int EntityRef;

class OBJECTBUF_API Entity: public OBObject
{
    OBJECTBUF_DEC_FACTORY(Entity, 0, string)
public:
    Entity(void);
    virtual ~Entity(void);
    void setDocument(Document* pDocument);

    bool isInherited(int nTypeId);
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual string entityName() const;
    virtual int typeId() const = 0;
    virtual bool isInitialized() const;
	static std::string Version();
public:
    virtual string asString(const std::string& sPropName) const { throw EMissMatchProperty(); };
    virtual int asInteger(const std::string& sPropName) const { throw EMissMatchProperty(); };
    virtual double asDouble(const std::string& sPropName) const { throw EMissMatchProperty(); };
    virtual bool asBoolean(const std::string& sPropName) const { throw EMissMatchProperty(); };
    virtual glodon::objectbuf::EntityRef asEntityRef(const std::string& sPropName) const { throw EMissMatchProperty(); };
    virtual glodon::objectbuf::Entity* asEntity(const std::string& sPropName) const { throw EMissMatchProperty(); };

    virtual void setAsString(const std::string& sPropName, const std::string& sValue) { throw EMissMatchProperty(); };
    virtual void setAsInteger(const std::string& sPropName, const int& nValue) { throw EMissMatchProperty(); };
    virtual void setAsDouble(const std::string& sPropName, const double& dValue) { throw EMissMatchProperty(); };
    virtual void setAsBoolean(const std::string& sPropName, const bool& bValue) { throw EMissMatchProperty(); };
    virtual void setAsEntityRef(const std::string& sPropName, const glodon::objectbuf::EntityRef& nValue) { throw EMissMatchProperty(); };

    virtual int getArrayCount(const std::string& sPropName) const { throw EMissMatchProperty(); };
    virtual void clearArray(const std::string& sPropName) { throw EMissMatchProperty(); };

    virtual void addEntityRef(const std::string& sPropName, const glodon::objectbuf::EntityRef& nValue) { throw EMissMatchProperty(); };
    virtual void addString(const std::string& sPropName, const std::string& sValue) { throw EMissMatchProperty(); };
    virtual void addInteger(const std::string& sPropName, const int& nValue) { throw EMissMatchProperty(); };
    virtual void addDouble(const std::string& sPropName, const double& dValue) { throw EMissMatchProperty(); };
    virtual void addBoolean(const std::string& sPropName, const bool& bValue) { throw EMissMatchProperty(); };

    virtual string getString(const std::string& sPropName, int nIndex) const { throw EMissMatchProperty(); };
    virtual int getInteger(const std::string& sPropName, int nIndex) const { throw EMissMatchProperty(); };
    virtual double getDouble(const std::string& sPropName, int nIndex) const { throw EMissMatchProperty(); };
    virtual bool getBoolean(const std::string& sPropName, int nIndex) const { throw EMissMatchProperty(); };
    virtual glodon::objectbuf::EntityRef getEntityRef(const std::string& sPropName, int nIndex) const { throw EMissMatchProperty(); };
    virtual glodon::objectbuf::Entity* getEntity(const std::string& sPropName, int nIndex) const { throw EMissMatchProperty(); };
protected:
    Document* m_pDocument;
};

}
}

#endif
