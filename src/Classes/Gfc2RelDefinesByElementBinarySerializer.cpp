#include "StdAfx.h"
#include "Gfc2RelDefinesByElementBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2RelDefinesByElement.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByElementBinarySerializer,"Gfc2RelDefinesByElementB",0)

int Gfc2RelDefinesByElementBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByElement* pEnt = (Gfc2RelDefinesByElement*)pEntity;
    int total_size = Gfc2RelDefinesBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRelatingElement())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRelatingElement());
    }

    return total_size;
}

void Gfc2RelDefinesByElementBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByElement* pEnt = (Gfc2RelDefinesByElement*)pEntity;
    Gfc2RelDefinesBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRelatingElement())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getRelatingElement(), output);
    }

}

google::protobuf::uint8* Gfc2RelDefinesByElementBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByElement* pEnt = (Gfc2RelDefinesByElement*)pEntity;
    target = Gfc2RelDefinesBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRelatingElement())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getRelatingElement(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2RelDefinesByElementBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RelDefinesByElement* pEnt = (Gfc2RelDefinesByElement*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RelDefinesBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2RelDefinesByElement_RelatingElement)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRelatingElement(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

