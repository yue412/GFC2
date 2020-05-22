#include "EntityAttributeDataHandler.h"
#include "GfcEngine\EngineException.h"

GFCENGINE_NAMESPACE_BEGIN

EntityAttributeDataHandler::EntityAttributeDataHandler(gfc2::schema::CAttribute* pOwner): CAttributeDataHandler(pOwner)
{
}


EntityAttributeDataHandler::~EntityAttributeDataHandler()
{
}

bool EntityAttributeDataHandler::isNull(char * pData) const
{
    return *(getNullDataPtr(pData)) == 0;
}

void EntityAttributeDataHandler::setIsNull(char * pData, bool bIsNull)
{
    *(getNullDataPtr(pData)) = bIsNull ? 0 : 1;
}

std::string EntityAttributeDataHandler::asString(char * pData) const
{
    throw ETypeMatchError();
}

int EntityAttributeDataHandler::asInteger(char * pData) const
{
    throw ETypeMatchError();
}

double EntityAttributeDataHandler::asDouble(char * pData) const
{
    throw ETypeMatchError();
}

bool EntityAttributeDataHandler::asBoolean(char * pData) const
{
    throw ETypeMatchError();
}

EntityRef EntityAttributeDataHandler::asEntityRef(char * pData) const
{
    throw ETypeMatchError();
}

void EntityAttributeDataHandler::setAsString(char * pData, const std::string & sValue)
{
    throw ETypeMatchError();
}

void EntityAttributeDataHandler::setAsInteger(char * pData, const int & nValue)
{
    throw ETypeMatchError();
}

void EntityAttributeDataHandler::setAsDouble(char * pData, const double & dValue)
{
    throw ETypeMatchError();
}

void EntityAttributeDataHandler::setAsBoolean(char * pData, const bool & bValue)
{
    throw ETypeMatchError();
}

void EntityAttributeDataHandler::setAsEntityRef(char * pData, const EntityRef & nValue)
{
    throw ETypeMatchError();
}

std::vector<std::string>& EntityAttributeDataHandler::asStringList(char * pData) const
{
    throw ETypeMatchError();
}

std::vector<int>& EntityAttributeDataHandler::asIntegerList(char * pData) const
{
    throw ETypeMatchError();
}

std::vector<double>& EntityAttributeDataHandler::asDoubleList(char * pData) const
{
    throw ETypeMatchError();
}

std::vector<bool>& EntityAttributeDataHandler::asBooleanList(char * pData) const
{
    throw ETypeMatchError();
}

std::vector<EntityRef>& EntityAttributeDataHandler::asEntityRefList(char * pData) const
{
    throw ETypeMatchError();
}

char* EntityAttributeDataHandler::getNullDataPtr(char* pData) const 
{ 
    auto nOffset = getOffset();
    return pData + nOffset;
}

char* EntityAttributeDataHandler::getDataPtr(char* pData) const { 
    return getNullDataPtr(pData) + 1; 
}

int BooleanAttributeDataHandler::asInteger(char * pData) const
{
    return asBoolean(pData);
}

double BooleanAttributeDataHandler::asDouble(char * pData) const
{
    return asInteger(pData);;
}

bool BooleanAttributeDataHandler::asBoolean(char * pData) const
{
    return *(getDataPtr(pData)) != 0;
}

void BooleanAttributeDataHandler::setAsInteger(char * pData, const int & nValue)
{
    setAsBoolean(pData, nValue != 0);
}

void BooleanAttributeDataHandler::setAsBoolean(char * pData, const bool & bValue)
{
    auto p = getDataPtr(pData);
    *(p) = bValue;
    setIsNull(pData, false);
}

std::vector<bool>& BooleanListAttributeDataHandler::asBooleanList(char * pData) const
{
    return *(std::vector<bool>*)getDataPtr(pData);
}

void BooleanListAttributeDataHandler::init(char * pData)
{
    auto p = getDataPtr(pData);
    new (p) std::vector<bool>();
}

void BooleanListAttributeDataHandler::free(char * pData)
{
    auto p = (std::vector<bool>*)getDataPtr(pData);
    p->~vector();
}

int IntegerAttributeDataHandler::asInteger(char * pData) const
{
    return *(int*)getDataPtr(pData);
}

double IntegerAttributeDataHandler::asDouble(char * pData) const
{
    return asInteger(pData);
}

bool IntegerAttributeDataHandler::asBoolean(char * pData) const
{
    return asInteger(pData) != 0;
}

void IntegerAttributeDataHandler::setAsInteger(char * pData, const int & nValue)
{
    *(int*)getDataPtr(pData) = nValue;
    setIsNull(pData, false);
}

void IntegerAttributeDataHandler::setAsBoolean(char * pData, const bool & bValue)
{
    setAsInteger(pData, bValue);
}

std::vector<int>& IntegerListAttributeDataHandler::asIntegerList(char * pData) const
{
    return *(std::vector<int>*)getDataPtr(pData);
}

void IntegerListAttributeDataHandler::init(char * pData)
{
    auto p = getDataPtr(pData);
    new (p) std::vector<int>();
}

void IntegerListAttributeDataHandler::free(char * pData)
{
    auto p = (std::vector<int>*)getDataPtr(pData);
    p->~vector();
}

double DoubleAttributeDataHandler::asDouble(char * pData) const
{
    return *(double*)getDataPtr(pData);
}

void DoubleAttributeDataHandler::setAsInteger(char * pData, const int & nValue)
{
    setAsDouble(pData, nValue);
}

void DoubleAttributeDataHandler::setAsDouble(char * pData, const double & dValue)
{
    *(double*)getDataPtr(pData) = dValue;
    setIsNull(pData, false);
}

void DoubleAttributeDataHandler::setAsBoolean(char * pData, const bool & bValue)
{
    setAsDouble(pData, bValue);
}

std::vector<double>& DoubleListAttributeDataHandler::asDoubleList(char * pData) const
{
    return *(std::vector<double>*)getDataPtr(pData);
}

void DoubleListAttributeDataHandler::init(char * pData)
{
    auto p = getDataPtr(pData);
    new (p) std::vector<double>();
}

void DoubleListAttributeDataHandler::free(char * pData)
{
    auto p = (std::vector<double>*)getDataPtr(pData);
    p->~vector();
}

std::string StringAttributeDataHandler::asString(char * pData) const
{
    return *(std::string*)getDataPtr(pData);
}

void StringAttributeDataHandler::setAsString(char * pData, const std::string & sValue)
{
    *(std::string*)getDataPtr(pData) = sValue;
    setIsNull(pData, false);
}

void StringAttributeDataHandler::setAsInteger(char * pData, const int & nValue)
{
    setAsString(pData, std::to_string(nValue));
}

void StringAttributeDataHandler::setAsDouble(char * pData, const double & dValue)
{
    setAsString(pData, std::to_string(dValue));
}

void StringAttributeDataHandler::setAsBoolean(char * pData, const bool & bValue)
{
    setAsString(pData, std::to_string(bValue));
}

void StringAttributeDataHandler::init(char * pData)
{
    auto p = getDataPtr(pData);
    new (p) std::string();
}

void StringAttributeDataHandler::free(char * pData)
{
    auto p = (std::string*)getDataPtr(pData);
    p->~basic_string();
}

std::vector<std::string>& StringListAttributeDataHandler::asStringList(char * pData) const
{
    return *(std::vector<std::string>*)getDataPtr(pData);
}

void StringListAttributeDataHandler::init(char * pData)
{
    auto p = getDataPtr(pData);
    new (p) std::vector<std::string>();
}

void StringListAttributeDataHandler::free(char * pData)
{
    auto p = (std::vector<std::string>*)getDataPtr(pData);
    p->~vector();
}

EntityRef EntityRefAttributeDataHandler::asEntityRef(char * pData) const
{
    return *(EntityRef*)getDataPtr(pData);
}

void EntityRefAttributeDataHandler::setAsEntityRef(char * pData, const EntityRef & nValue)
{
    *(EntityRef*)getDataPtr(pData) = nValue;
    setIsNull(pData, false);
}

std::vector<EntityRef>& EntityRefListAttributeDataHandler::asEntityRefList(char * pData) const
{
    return *(std::vector<EntityRef>*)getDataPtr(pData);
}

void EntityRefListAttributeDataHandler::init(char * pData)
{
    auto p = getDataPtr(pData);
    new (p) std::vector<EntityRef>();
}

void EntityRefListAttributeDataHandler::free(char * pData)
{
    auto p = (std::vector<EntityRef>*)getDataPtr(pData);
    p->~vector();
}

GFCENGINE_NAMESPACE_END
