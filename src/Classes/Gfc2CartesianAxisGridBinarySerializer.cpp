#include "StdAfx.h"
#include "Gfc2CartesianAxisGridBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CartesianAxisGrid.h"

OBJECTBUF_IMP_OBJECT(Gfc2CartesianAxisGridBinarySerializer,"Gfc2CartesianAxisGridB",0)

int Gfc2CartesianAxisGridBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CartesianAxisGrid* pEnt = (Gfc2CartesianAxisGrid*)pEntity;
    int total_size = Gfc2AxisGridBinarySerializer::byteSize(pEnt);

    if (pEnt->hasInsertPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getInsertPt());
    }

    if (pEnt->hasAxisAngle())
    {
        total_size += 1 + 8;
    }

    if (pEnt->getSKJCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSKJCount());
    for (int i = 0; i < pEnt->getSKJCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSKJ(i));
    }

    if (pEnt->getZJSCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getZJSCount());
    for (int i = 0; i < pEnt->getZJSCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getZJS(i));
    }

    if (pEnt->getYJSCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getYJSCount());
    for (int i = 0; i < pEnt->getYJSCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getYJS(i));
    }

    if (pEnt->getXKJCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getXKJCount());
    for (int i = 0; i < pEnt->getXKJCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getXKJ(i));
    }

    return total_size;
}

void Gfc2CartesianAxisGridBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CartesianAxisGrid* pEnt = (Gfc2CartesianAxisGrid*)pEntity;
    Gfc2AxisGridBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasInsertPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getInsertPt(), output);
    }

    if (pEnt->hasAxisAngle())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(7, pEnt->getAxisAngle(), output);
    }

    if (pEnt->getSKJCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(8, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getSKJCount(), output);
        for (int i = 0; i < pEnt->getSKJCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getSKJ(i), output);
        }
    }

    if (pEnt->getZJSCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(9, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getZJSCount(), output);
        for (int i = 0; i < pEnt->getZJSCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getZJS(i), output);
        }
    }

    if (pEnt->getYJSCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(10, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getYJSCount(), output);
        for (int i = 0; i < pEnt->getYJSCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getYJS(i), output);
        }
    }

    if (pEnt->getXKJCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(11, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getXKJCount(), output);
        for (int i = 0; i < pEnt->getXKJCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getXKJ(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2CartesianAxisGridBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CartesianAxisGrid* pEnt = (Gfc2CartesianAxisGrid*)pEntity;
    target = Gfc2AxisGridBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasInsertPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getInsertPt(), target);
    }

    if (pEnt->hasAxisAngle())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(7, pEnt->getAxisAngle(), target);
    }

    if (pEnt->getSKJCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(8, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getSKJCount(), target);
        for (int i = 0; i < pEnt->getSKJCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getSKJ(i), target);
        }
    }

    if (pEnt->getZJSCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(9, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getZJSCount(), target);
        for (int i = 0; i < pEnt->getZJSCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getZJS(i), target);
        }
    }

    if (pEnt->getYJSCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(10, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getYJSCount(), target);
        for (int i = 0; i < pEnt->getYJSCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getYJS(i), target);
        }
    }

    if (pEnt->getXKJCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(11, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getXKJCount(), target);
        for (int i = 0; i < pEnt->getXKJCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getXKJ(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CartesianAxisGridBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CartesianAxisGrid* pEnt = (Gfc2CartesianAxisGrid*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AxisGridBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CartesianAxisGrid_InsertPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setInsertPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CartesianAxisGrid_AxisAngle)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setAxisAngle(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CartesianAxisGrid_SKJ)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addSKJ(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CartesianAxisGrid_ZJS)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addZJS(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CartesianAxisGrid_YJS)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addYJS(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CartesianAxisGrid_XKJ)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addXKJ(value);
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

