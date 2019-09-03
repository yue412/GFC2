#include "StdAfx.h"
#include "Gfc2CustomPointShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CustomPointShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2CustomPointShapeBinarySerializer,"Gfc2CustomPointShapeB",0)

int Gfc2CustomPointShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomPointShape* pEnt = (Gfc2CustomPointShape*)pEntity;
    int total_size = Gfc2SolidShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasInsertPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getInsertPt());
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

    return total_size;
}

void Gfc2CustomPointShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomPointShape* pEnt = (Gfc2CustomPointShape*)pEntity;
    Gfc2SolidShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasInsertPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getInsertPt(), output);
    }

    if (pEnt->hasBaseInsertPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getBaseInsertPt(), output);
    }

    if (pEnt->hasAngle())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(7, pEnt->getAngle(), output);
    }

    if (pEnt->hasMirrorFlag())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(8, pEnt->getMirrorFlag(), output);
    }

}

google::protobuf::uint8* Gfc2CustomPointShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomPointShape* pEnt = (Gfc2CustomPointShape*)pEntity;
    target = Gfc2SolidShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasInsertPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getInsertPt(), target);
    }

    if (pEnt->hasBaseInsertPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getBaseInsertPt(), target);
    }

    if (pEnt->hasAngle())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(7, pEnt->getAngle(), target);
    }

    if (pEnt->hasMirrorFlag())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, pEnt->getMirrorFlag(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CustomPointShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CustomPointShape* pEnt = (Gfc2CustomPointShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SolidShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomPointShape_InsertPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setInsertPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomPointShape_BaseInsertPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBaseInsertPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomPointShape_Angle)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setAngle(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomPointShape_MirrorFlag)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setMirrorFlag(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

