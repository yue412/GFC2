#include "StdAfx.h"
#include "Gfc2RelDefinesByPropertiesBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2RelDefinesByProperties.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByPropertiesBinarySerializer,"Gfc2RelDefinesByPropertiesB",0)

int Gfc2RelDefinesByPropertiesBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByProperties* pEnt = (Gfc2RelDefinesByProperties*)pEntity;
    int total_size = Gfc2RelDefinesBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRelatingPropertySet())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRelatingPropertySet());
    }

    return total_size;
}

void Gfc2RelDefinesByPropertiesBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByProperties* pEnt = (Gfc2RelDefinesByProperties*)pEntity;
    Gfc2RelDefinesBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRelatingPropertySet())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getRelatingPropertySet(), output);
    }

}

google::protobuf::uint8* Gfc2RelDefinesByPropertiesBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RelDefinesByProperties* pEnt = (Gfc2RelDefinesByProperties*)pEntity;
    target = Gfc2RelDefinesBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRelatingPropertySet())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getRelatingPropertySet(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2RelDefinesByPropertiesBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RelDefinesByProperties* pEnt = (Gfc2RelDefinesByProperties*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RelDefinesBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2RelDefinesByProperties_RelatingPropertySet)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRelatingPropertySet(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

