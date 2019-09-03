#include "StdAfx.h"
#include "Gfc2HermiteCurve2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2HermiteCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCurve2dBinarySerializer,"Gfc2HermiteCurve2dB",0)

int Gfc2HermiteCurve2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCurve2d* pEnt = (Gfc2HermiteCurve2d*)pEntity;
    int total_size = Gfc2Curve2dBinarySerializer::byteSize(pEnt);

    if (pEnt->getCtrlPtsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPtsCount());
    for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPts(i));
    }

    return total_size;
}

void Gfc2HermiteCurve2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCurve2d* pEnt = (Gfc2HermiteCurve2d*)pEntity;
    Gfc2Curve2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->getCtrlPtsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCtrlPtsCount(), output);
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCtrlPts(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2HermiteCurve2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2HermiteCurve2d* pEnt = (Gfc2HermiteCurve2d*)pEntity;
    target = Gfc2Curve2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->getCtrlPtsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCtrlPtsCount(), target);
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCtrlPts(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2HermiteCurve2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2HermiteCurve2d* pEnt = (Gfc2HermiteCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2HermiteCurve2d_CtrlPts)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addCtrlPts(value);
        }
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

