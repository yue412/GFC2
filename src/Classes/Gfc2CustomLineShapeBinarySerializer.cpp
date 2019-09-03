#include "StdAfx.h"
#include "Gfc2CustomLineShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CustomLineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2CustomLineShapeBinarySerializer,"Gfc2CustomLineShapeB",0)

int Gfc2CustomLineShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomLineShape* pEnt = (Gfc2CustomLineShape*)pEntity;
    int total_size = Gfc2SolidShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasWidth())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasLeftWidth())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasLine())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLine());
    }

    if (pEnt->hasE_S_Elevation())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2CustomLineShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomLineShape* pEnt = (Gfc2CustomLineShape*)pEntity;
    Gfc2SolidShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasWidth())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(5, pEnt->getWidth(), output);
    }

    if (pEnt->hasLeftWidth())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(6, pEnt->getLeftWidth(), output);
    }

    if (pEnt->hasLine())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getLine(), output);
    }

    if (pEnt->hasE_S_Elevation())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(8, pEnt->getE_S_Elevation(), output);
    }

}

google::protobuf::uint8* Gfc2CustomLineShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CustomLineShape* pEnt = (Gfc2CustomLineShape*)pEntity;
    target = Gfc2SolidShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasWidth())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, pEnt->getWidth(), target);
    }

    if (pEnt->hasLeftWidth())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(6, pEnt->getLeftWidth(), target);
    }

    if (pEnt->hasLine())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getLine(), target);
    }

    if (pEnt->hasE_S_Elevation())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(8, pEnt->getE_S_Elevation(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CustomLineShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CustomLineShape* pEnt = (Gfc2CustomLineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SolidShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomLineShape_Width)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setWidth(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomLineShape_LeftWidth)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setLeftWidth(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomLineShape_Line)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLine(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CustomLineShape_E_S_Elevation)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setE_S_Elevation(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

