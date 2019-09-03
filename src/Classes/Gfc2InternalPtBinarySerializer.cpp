#include "StdAfx.h"
#include "Gfc2InternalPtBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2InternalPt.h"

OBJECTBUF_IMP_OBJECT(Gfc2InternalPtBinarySerializer,"Gfc2InternalPtB",0)

int Gfc2InternalPtBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalPt* pEnt = (Gfc2InternalPt*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasP())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getP());
    }

    if (pEnt->hasTVec())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getTVec());
    }

    if (pEnt->hasT())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasUV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getUV());
    }

    if (pEnt->hasST())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getST());
    }

    if (pEnt->hasUVDir())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getUVDir());
    }

    if (pEnt->hasSTDir())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSTDir());
    }

    return total_size;
}

void Gfc2InternalPtBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalPt* pEnt = (Gfc2InternalPt*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasP())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getP(), output);
    }

    if (pEnt->hasTVec())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getTVec(), output);
    }

    if (pEnt->hasT())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getT(), output);
    }

    if (pEnt->hasUV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getUV(), output);
    }

    if (pEnt->hasST())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getST(), output);
    }

    if (pEnt->hasUVDir())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getUVDir(), output);
    }

    if (pEnt->hasSTDir())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getSTDir(), output);
    }

}

google::protobuf::uint8* Gfc2InternalPtBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalPt* pEnt = (Gfc2InternalPt*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasP())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getP(), target);
    }

    if (pEnt->hasTVec())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getTVec(), target);
    }

    if (pEnt->hasT())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getT(), target);
    }

    if (pEnt->hasUV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getUV(), target);
    }

    if (pEnt->hasST())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getST(), target);
    }

    if (pEnt->hasUVDir())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getUVDir(), target);
    }

    if (pEnt->hasSTDir())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getSTDir(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2InternalPtBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2InternalPt* pEnt = (Gfc2InternalPt*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalPt_P)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setP(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalPt_TVec)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setTVec(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalPt_T)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setT(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalPt_UV)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setUV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalPt_ST)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setST(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalPt_UVDir)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setUVDir(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalPt_STDir)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSTDir(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

