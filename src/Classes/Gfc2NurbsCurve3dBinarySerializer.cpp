#include "StdAfx.h"
#include "Gfc2NurbsCurve3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2NurbsCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCurve3dBinarySerializer,"Gfc2NurbsCurve3dB",0)

int Gfc2NurbsCurve3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCurve3d* pEnt = (Gfc2NurbsCurve3d*)pEntity;
    int total_size = Gfc2Curve3dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasDegree())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDegree());
    }

    if (pEnt->getCtrlPtsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPtsCount());
    for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPts(i));
    }

    if (pEnt->getKnotsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getKnotsCount());
    for (int i = 0; i < pEnt->getKnotsCount(); i++)
    {
        total_size += 8;
    }

    return total_size;
}

void Gfc2NurbsCurve3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCurve3d* pEnt = (Gfc2NurbsCurve3d*)pEntity;
    Gfc2Curve3dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasDegree())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getDegree(), output);
    }

    if (pEnt->getCtrlPtsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCtrlPtsCount(), output);
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCtrlPts(i), output);
        }
    }

    if (pEnt->getKnotsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(3, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getKnotsCount(), output);
        for (int i = 0; i < pEnt->getKnotsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteDoubleNoTag(pEnt->getKnots(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2NurbsCurve3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCurve3d* pEnt = (Gfc2NurbsCurve3d*)pEntity;
    target = Gfc2Curve3dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasDegree())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getDegree(), target);
    }

    if (pEnt->getCtrlPtsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCtrlPtsCount(), target);
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCtrlPts(i), target);
        }
    }

    if (pEnt->getKnotsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(3, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getKnotsCount(), target);
        for (int i = 0; i < pEnt->getKnotsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteDoubleNoTagToArray(pEnt->getKnots(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2NurbsCurve3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2NurbsCurve3d* pEnt = (Gfc2NurbsCurve3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve3dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsCurve3d_Degree)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDegree(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsCurve3d_CtrlPts)
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

    if (nFieldNum == _FieldCache->_Gfc2NurbsCurve3d_Knots)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            Gfc2Double value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
            pEnt->addKnots(value);
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

