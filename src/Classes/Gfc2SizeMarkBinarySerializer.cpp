#include "StdAfx.h"
#include "Gfc2SizeMarkBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SizeMark.h"

OBJECTBUF_IMP_OBJECT(Gfc2SizeMarkBinarySerializer,"Gfc2SizeMarkB",0)

int Gfc2SizeMarkBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SizeMark* pEnt = (Gfc2SizeMark*)pEntity;
    int total_size = Gfc2EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasSizeMarkType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getSizeMarkType());
    }

    if (pEnt->hasStartLine())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getStartLine());
    }

    if (pEnt->hasEndLine())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEndLine());
    }

    return total_size;
}

void Gfc2SizeMarkBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SizeMark* pEnt = (Gfc2SizeMark*)pEntity;
    Gfc2EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasSizeMarkType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, (int)pEnt->getSizeMarkType(), output);
    }

    if (pEnt->hasStartLine())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getStartLine(), output);
    }

    if (pEnt->hasEndLine())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(8, pEnt->getEndLine(), output);
    }

}

google::protobuf::uint8* Gfc2SizeMarkBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SizeMark* pEnt = (Gfc2SizeMark*)pEntity;
    target = Gfc2EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasSizeMarkType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, (int)pEnt->getSizeMarkType(), target);
    }

    if (pEnt->hasStartLine())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getStartLine(), target);
    }

    if (pEnt->hasEndLine())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, pEnt->getEndLine(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SizeMarkBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SizeMark* pEnt = (Gfc2SizeMark*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SizeMark_SizeMarkType)
    {
        Gfc2SizeMarkType value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setSizeMarkType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SizeMark_StartLine)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStartLine(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SizeMark_EndLine)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEndLine(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

