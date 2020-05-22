#ifndef ENTITYATTRIBUTEDATAHANDLER_H
#define ENTITYATTRIBUTEDATAHANDLER_H

#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Entity.h"
#include "EntityAttribute.h"

GFCENGINE_NAMESPACE_BEGIN

class EntityAttributeDataHandler: public gfc2::schema::CAttributeDataHandler
{
public:
    EntityAttributeDataHandler(gfc2::schema::CAttribute* pOwner);
    virtual ~EntityAttributeDataHandler();
public:
    bool isNull(char* pData) const;
    void setIsNull(char* pData, bool bIsNull);

    virtual std::string asString(char* pData) const;
    virtual int asInteger(char* pData) const;
    virtual double asDouble(char* pData) const;
    virtual bool asBoolean(char* pData) const;
    virtual EntityRef asEntityRef(char* pData) const;

    virtual void setAsString(char* pData, const std::string& sValue);
    virtual void setAsInteger(char* pData, const int& nValue);
    virtual void setAsDouble(char* pData, const double& dValue);
    virtual void setAsBoolean(char* pData, const bool& bValue);
    virtual void setAsEntityRef(char* pData, const EntityRef& nValue);

    virtual std::vector<std::string>& asStringList(char* pData) const;
    virtual std::vector<int>& asIntegerList(char* pData) const;
    virtual std::vector<double>& asDoubleList(char* pData) const;
    virtual std::vector<bool>& asBooleanList(char* pData) const;
    virtual std::vector<EntityRef>& asEntityRefList(char* pData) const;
protected:
    char* getNullDataPtr(char* pData) const;
    char* getDataPtr(char* pData) const;
};

class BooleanAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    BooleanAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    //virtual std::string asString(char* pData) const;
    virtual int asInteger(char* pData) const;
    virtual double asDouble(char* pData) const;
    virtual bool asBoolean(char* pData) const;

    //virtual void setAsString(char* pData, const std::string& sValue);
    virtual void setAsInteger(char* pData, const int& nValue);
    virtual void setAsBoolean(char* pData, const bool& bValue);
protected:
    virtual int getRawDataSize() { return sizeof(bool); }
};

class BooleanListAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    BooleanListAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    virtual std::vector<bool>& asBooleanList(char* pData) const;
public:
    virtual void init(char* pData);
    virtual void free(char* pData);
protected:
    virtual int getRawDataSize() { return sizeof(std::vector<bool>); }
};

class IntegerAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    IntegerAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    //virtual std::string asString(char* pData) const;
    virtual int asInteger(char* pData) const;
    virtual double asDouble(char* pData) const;
    virtual bool asBoolean(char* pData) const;

    //virtual void setAsString(char* pData, const std::string& sValue);
    virtual void setAsInteger(char* pData, const int& nValue);
    virtual void setAsBoolean(char* pData, const bool& bValue);
protected:
    virtual int getRawDataSize() { return sizeof(int); }
};

class IntegerListAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    IntegerListAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    virtual std::vector<int>& asIntegerList(char* pData) const;
public:
    virtual void init(char* pData);
    virtual void free(char* pData);
protected:
    virtual int getRawDataSize() { return sizeof(std::vector<int>); }
};

class DoubleAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    DoubleAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    //virtual std::string asString(char* pData) const;
    virtual double asDouble(char* pData) const;

    //virtual void setAsString(char* pData, const std::string& sValue);
    virtual void setAsInteger(char* pData, const int& nValue);
    virtual void setAsDouble(char* pData, const double& dValue);
    virtual void setAsBoolean(char* pData, const bool& bValue);
protected:
    virtual int getRawDataSize() { return sizeof(double); }
};

class DoubleListAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    DoubleListAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    virtual std::vector<double>& asDoubleList(char* pData) const;
public:
    virtual void init(char* pData);
    virtual void free(char* pData);
protected:
    virtual int getRawDataSize() { return sizeof(std::vector<double>); }
};

class StringAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    StringAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    virtual std::string asString(char* pData) const;

    virtual void setAsString(char* pData, const std::string& sValue);
    virtual void setAsInteger(char* pData, const int& nValue);
    virtual void setAsDouble(char* pData, const double& dValue);
    virtual void setAsBoolean(char* pData, const bool& bValue);
public:
    virtual void init(char* pData);
    virtual void free(char* pData);
protected:
    virtual int getRawDataSize() { return sizeof(std::string); }
};

class StringListAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    StringListAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    virtual std::vector<std::string>& asStringList(char* pData) const;
public:
    virtual void init(char* pData);
    virtual void free(char* pData);
protected:
    virtual int getRawDataSize() { return sizeof(std::vector<std::string>); }
};

class EntityRefAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    EntityRefAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    virtual EntityRef asEntityRef(char* pData) const;

    virtual void setAsEntityRef(char* pData, const EntityRef& nValue);
protected:
    virtual int getRawDataSize() { return sizeof(EntityRef); }
};

class EntityRefListAttributeDataHandler : public EntityAttributeDataHandler
{
public:
    EntityRefListAttributeDataHandler(gfc2::schema::CAttribute* pOwner) : EntityAttributeDataHandler(pOwner) { }
public:
    virtual std::vector<EntityRef>& asEntityRefList(char* pData) const;
public:
    virtual void init(char* pData);
    virtual void free(char* pData);
protected:
    virtual int getRawDataSize() { return sizeof(std::vector<EntityRef>); }
};

GFCENGINE_NAMESPACE_END

#endif // !ENTITYATTRIBUTEDATAHANDLER_H

