#include "StdAfx.h"
#include "Gfc2SectionLineShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SectionLineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2SectionLineShapeBinarySerializer,"Gfc2SectionLineShapeB",0)

int Gfc2SectionLineShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionLineShape* pEnt = (Gfc2SectionLineShape*)pEntity;
    int total_size = Gfc2CustomLineShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPoly())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoly());
    }

    if (pEnt->hasBaseInsertPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBaseInsertPt());
    }

    if (pEnt->hasAngle())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasMirrorFlag())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasArcInfo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getArcInfo());
    }

    if (pEnt->hasIsSpiral())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2SectionLineShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionLineShape* pEnt = (Gfc2SectionLineShape*)pEntity;
    Gfc2CustomLineShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPoly())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getPoly(), output);
    }

    if (pEnt->hasBaseInsertPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(10, pEnt->getBaseInsertPt(), output);
    }

    if (pEnt->hasAngle())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(11, pEnt->getAngle(), output);
    }

    if (pEnt->hasMirrorFlag())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(12, pEnt->getMirrorFlag(), output);
    }

    if (pEnt->hasArcInfo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(13, pEnt->getArcInfo(), output);
    }

    if (pEnt->hasIsSpiral())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(14, pEnt->getIsSpiral(), output);
    }

}

google::protobuf::uint8* Gfc2SectionLineShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionLineShape* pEnt = (Gfc2SectionLineShape*)pEntity;
    target = Gfc2CustomLineShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPoly())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getPoly(), target);
    }

    if (pEnt->hasBaseInsertPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, pEnt->getBaseInsertPt(), target);
    }

    if (pEnt->hasAngle())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(11, pEnt->getAngle(), target);
    }

    if (pEnt->hasMirrorFlag())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(12, pEnt->getMirrorFlag(), target);
    }

    if (pEnt->hasArcInfo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(13, pEnt->getArcInfo(), target);
    }

    if (pEnt->hasIsSpiral())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(14, pEnt->getIsSpiral(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SectionLineShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SectionLineShape* pEnt = (Gfc2SectionLineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CustomLineShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SectionLineShape_Poly)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoly(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SectionLineShape_BaseInsertPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBaseInsertPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SectionLineShape_Angle)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setAngle(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SectionLineShape_MirrorFlag)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setMirrorFlag(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SectionLineShape_ArcInfo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setArcInfo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SectionLineShape_IsSpiral)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setIsSpiral(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

