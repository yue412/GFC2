#include "StdAfx.h"
#include "Gfc2StringBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2String.h"

OBJECTBUF_IMP_OBJECT(Gfc2StringBinarySerializer,"Gfc2StringB",0)

int Gfc2StringBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2String* pEnt = (Gfc2String*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasValue())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(pEnt->getValue());
    }

    return total_size;
}

void Gfc2StringBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2String* pEnt = (Gfc2String*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasValue())
    {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(1, pEnt->getValue(), output);
    }

}

google::protobuf::uint8* Gfc2StringBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2String* pEnt = (Gfc2String*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasValue())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteStringToArray(1, pEnt->getValue(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2StringBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2String* pEnt = (Gfc2String*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2String_Value)
    {
        std::string value;
        DO_((google::protobuf::internal::WireFormatLite::ReadString(input, &value)));
        pEnt->setValue(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

