#include "StdAfx.h"
#include "Gfc2FloorBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Floor.h"

OBJECTBUF_IMP_OBJECT(Gfc2FloorBinarySerializer,"Gfc2FloorB",0)

int Gfc2FloorBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Floor* pEnt = (Gfc2Floor*)pEntity;
    int total_size = Gfc2SpatialStructureEntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasFirstFloorFlag())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasStdFloorCount())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getStdFloorCount());
    }

    if (pEnt->hasStructuralElevation())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasStartFloorNo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getStartFloorNo());
    }

    if (pEnt->hasRemark())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRemark());
    }

    return total_size;
}

void Gfc2FloorBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Floor* pEnt = (Gfc2Floor*)pEntity;
    Gfc2SpatialStructureEntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasFirstFloorFlag())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(3, pEnt->getFirstFloorFlag(), output);
    }

    if (pEnt->hasHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(4, pEnt->getHeight(), output);
    }

    if (pEnt->hasStdFloorCount())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getStdFloorCount(), output);
    }

    if (pEnt->hasStructuralElevation())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(6, pEnt->getStructuralElevation(), output);
    }

    if (pEnt->hasStartFloorNo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getStartFloorNo(), output);
    }

    if (pEnt->hasRemark())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(8, pEnt->getRemark(), output);
    }

}

google::protobuf::uint8* Gfc2FloorBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Floor* pEnt = (Gfc2Floor*)pEntity;
    target = Gfc2SpatialStructureEntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasFirstFloorFlag())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, pEnt->getFirstFloorFlag(), target);
    }

    if (pEnt->hasHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, pEnt->getHeight(), target);
    }

    if (pEnt->hasStdFloorCount())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getStdFloorCount(), target);
    }

    if (pEnt->hasStructuralElevation())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(6, pEnt->getStructuralElevation(), target);
    }

    if (pEnt->hasStartFloorNo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getStartFloorNo(), target);
    }

    if (pEnt->hasRemark())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, pEnt->getRemark(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2FloorBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Floor* pEnt = (Gfc2Floor*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SpatialStructureEntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Floor_FirstFloorFlag)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setFirstFloorFlag(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Floor_Height)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Floor_StdFloorCount)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStdFloorCount(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Floor_StructuralElevation)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setStructuralElevation(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Floor_StartFloorNo)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStartFloorNo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Floor_Remark)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRemark(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

