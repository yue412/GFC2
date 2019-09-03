#include "StdAfx.h"
#include "Gfc2EntityShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2EntityShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2EntityShapeBinarySerializer,"Gfc2EntityShapeB",0)

int Gfc2EntityShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EntityShape* pEnt = (Gfc2EntityShape*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasIdentifier())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIdentifier());
    }

    if (pEnt->hasShape())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getShape());
    }

    return total_size;
}

void Gfc2EntityShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EntityShape* pEnt = (Gfc2EntityShape*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasIdentifier())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getIdentifier(), output);
    }

    if (pEnt->hasShape())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getShape(), output);
    }

}

google::protobuf::uint8* Gfc2EntityShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EntityShape* pEnt = (Gfc2EntityShape*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasIdentifier())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getIdentifier(), target);
    }

    if (pEnt->hasShape())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getShape(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2EntityShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2EntityShape* pEnt = (Gfc2EntityShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2EntityShape_Identifier)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setIdentifier(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2EntityShape_Shape)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setShape(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

