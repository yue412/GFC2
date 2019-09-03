#include "StdAfx.h"
#include "Gfc2PropertyBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Property.h"

OBJECTBUF_IMP_OBJECT(Gfc2PropertyBinarySerializer,"Gfc2PropertyB",0)

int Gfc2PropertyBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Property* pEnt = (Gfc2Property*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasName())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getName());
    }

    return total_size;
}

void Gfc2PropertyBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Property* pEnt = (Gfc2Property*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasName())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getName(), output);
    }

}

google::protobuf::uint8* Gfc2PropertyBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Property* pEnt = (Gfc2Property*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasName())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getName(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PropertyBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Property* pEnt = (Gfc2Property*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Property_Name)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setName(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

