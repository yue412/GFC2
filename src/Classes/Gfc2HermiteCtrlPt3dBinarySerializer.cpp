#include "StdAfx.h"
#include "Gfc2HermiteCtrlPt3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2HermiteCtrlPt3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCtrlPt3dBinarySerializer,"Gfc2HermiteCtrlPt3dB",0)

int Gfc2HermiteCtrlPt3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCtrlPt3d* pEnt = (Gfc2HermiteCtrlPt3d*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoint());
    }

    if (pEnt->hasTangent())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getTangent());
    }

    if (pEnt->hasParameter())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2HermiteCtrlPt3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCtrlPt3d* pEnt = (Gfc2HermiteCtrlPt3d*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getPoint(), output);
    }

    if (pEnt->hasTangent())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getTangent(), output);
    }

    if (pEnt->hasParameter())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getParameter(), output);
    }

}

google::protobuf::uint8* Gfc2HermiteCtrlPt3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCtrlPt3d* pEnt = (Gfc2HermiteCtrlPt3d*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getPoint(), target);
    }

    if (pEnt->hasTangent())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getTangent(), target);
    }

    if (pEnt->hasParameter())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getParameter(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2HermiteCtrlPt3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2HermiteCtrlPt3d* pEnt = (Gfc2HermiteCtrlPt3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2HermiteCtrlPt3d_Point)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2HermiteCtrlPt3d_Tangent)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setTangent(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2HermiteCtrlPt3d_Parameter)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setParameter(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

