#include "StdAfx.h"
#include "Gfc2NurbsCtrlPt2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2NurbsCtrlPt2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCtrlPt2dBinarySerializer,"Gfc2NurbsCtrlPt2dB",0)

int Gfc2NurbsCtrlPt2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCtrlPt2d* pEnt = (Gfc2NurbsCtrlPt2d*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoint());
    }

    if (pEnt->hasWeight())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2NurbsCtrlPt2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCtrlPt2d* pEnt = (Gfc2NurbsCtrlPt2d*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getPoint(), output);
    }

    if (pEnt->hasWeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getWeight(), output);
    }

}

google::protobuf::uint8* Gfc2NurbsCtrlPt2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCtrlPt2d* pEnt = (Gfc2NurbsCtrlPt2d*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getPoint(), target);
    }

    if (pEnt->hasWeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getWeight(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2NurbsCtrlPt2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2NurbsCtrlPt2d* pEnt = (Gfc2NurbsCtrlPt2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsCtrlPt2d_Point)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsCtrlPt2d_Weight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setWeight(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

