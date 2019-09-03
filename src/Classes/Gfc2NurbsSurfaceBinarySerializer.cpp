#include "StdAfx.h"
#include "Gfc2NurbsSurfaceBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2NurbsSurface.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsSurfaceBinarySerializer,"Gfc2NurbsSurfaceB",0)

int Gfc2NurbsSurfaceBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsSurface* pEnt = (Gfc2NurbsSurface*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasDegreeU())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDegreeU());
    }

    if (pEnt->hasDegreeV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDegreeV());
    }

    if (pEnt->hasCtrlPtCountU())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPtCountU());
    }

    if (pEnt->hasCtrlPtCountV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPtCountV());
    }

    if (pEnt->getCtrlPtsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPtsCount());
    for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCtrlPts(i));
    }

    if (pEnt->getKnotsUCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getKnotsUCount());
    for (int i = 0; i < pEnt->getKnotsUCount(); i++)
    {
        total_size += 8;
    }

    if (pEnt->getKnotsVCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getKnotsVCount());
    for (int i = 0; i < pEnt->getKnotsVCount(); i++)
    {
        total_size += 8;
    }

    return total_size;
}

void Gfc2NurbsSurfaceBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsSurface* pEnt = (Gfc2NurbsSurface*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasDegreeU())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getDegreeU(), output);
    }

    if (pEnt->hasDegreeV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getDegreeV(), output);
    }

    if (pEnt->hasCtrlPtCountU())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getCtrlPtCountU(), output);
    }

    if (pEnt->hasCtrlPtCountV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getCtrlPtCountV(), output);
    }

    if (pEnt->getCtrlPtsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCtrlPtsCount(), output);
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCtrlPts(i), output);
        }
    }

    if (pEnt->getKnotsUCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(6, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getKnotsUCount(), output);
        for (int i = 0; i < pEnt->getKnotsUCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteDoubleNoTag(pEnt->getKnotsU(i), output);
        }
    }

    if (pEnt->getKnotsVCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(7, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getKnotsVCount(), output);
        for (int i = 0; i < pEnt->getKnotsVCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteDoubleNoTag(pEnt->getKnotsV(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2NurbsSurfaceBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsSurface* pEnt = (Gfc2NurbsSurface*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasDegreeU())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getDegreeU(), target);
    }

    if (pEnt->hasDegreeV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getDegreeV(), target);
    }

    if (pEnt->hasCtrlPtCountU())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getCtrlPtCountU(), target);
    }

    if (pEnt->hasCtrlPtCountV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getCtrlPtCountV(), target);
    }

    if (pEnt->getCtrlPtsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCtrlPtsCount(), target);
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCtrlPts(i), target);
        }
    }

    if (pEnt->getKnotsUCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(6, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getKnotsUCount(), target);
        for (int i = 0; i < pEnt->getKnotsUCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteDoubleNoTagToArray(pEnt->getKnotsU(i), target);
        }
    }

    if (pEnt->getKnotsVCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(7, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getKnotsVCount(), target);
        for (int i = 0; i < pEnt->getKnotsVCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteDoubleNoTagToArray(pEnt->getKnotsV(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2NurbsSurfaceBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2NurbsSurface* pEnt = (Gfc2NurbsSurface*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsSurface_DegreeU)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDegreeU(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsSurface_DegreeV)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDegreeV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsSurface_CtrlPtCountU)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCtrlPtCountU(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsSurface_CtrlPtCountV)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCtrlPtCountV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsSurface_CtrlPts)
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

    if (nFieldNum == _FieldCache->_Gfc2NurbsSurface_KnotsU)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            Gfc2Double value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
            pEnt->addKnotsU(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2NurbsSurface_KnotsV)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            Gfc2Double value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
            pEnt->addKnotsV(value);
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

