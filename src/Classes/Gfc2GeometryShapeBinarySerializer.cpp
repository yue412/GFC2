#include "StdAfx.h"
#include "Gfc2GeometryShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2GeometryShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2GeometryShapeBinarySerializer,"Gfc2GeometryShapeB",0)

int Gfc2GeometryShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2GeometryShape* pEnt = (Gfc2GeometryShape*)pEntity;
    int total_size = Gfc2ShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasGeo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getGeo());
    }

    return total_size;
}

void Gfc2GeometryShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2GeometryShape* pEnt = (Gfc2GeometryShape*)pEntity;
    Gfc2ShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasGeo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getGeo(), output);
    }

}

google::protobuf::uint8* Gfc2GeometryShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2GeometryShape* pEnt = (Gfc2GeometryShape*)pEntity;
    target = Gfc2ShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasGeo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getGeo(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2GeometryShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2GeometryShape* pEnt = (Gfc2GeometryShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2ShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2GeometryShape_Geo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setGeo(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

