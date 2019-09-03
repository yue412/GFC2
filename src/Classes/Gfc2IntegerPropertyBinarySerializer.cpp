#include "StdAfx.h"
#include "Gfc2IntegerPropertyBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2IntegerProperty.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntegerPropertyBinarySerializer,"Gfc2IntegerPropertyB",0)

int Gfc2IntegerPropertyBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntegerProperty* pEnt = (Gfc2IntegerProperty*)pEntity;
    int total_size = Gfc2PropertyBinarySerializer::byteSize(pEnt);

    if (pEnt->hasValue())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getValue());
    }

    return total_size;
}

void Gfc2IntegerPropertyBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntegerProperty* pEnt = (Gfc2IntegerProperty*)pEntity;
    Gfc2PropertyBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasValue())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getValue(), output);
    }

}

google::protobuf::uint8* Gfc2IntegerPropertyBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntegerProperty* pEnt = (Gfc2IntegerProperty*)pEntity;
    target = Gfc2PropertyBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasValue())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getValue(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2IntegerPropertyBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2IntegerProperty* pEnt = (Gfc2IntegerProperty*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PropertyBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2IntegerProperty_Value)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
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

