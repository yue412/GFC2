#include "StdAfx.h"
#include "Gfc2PropertySetBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PropertySet.h"

OBJECTBUF_IMP_OBJECT(Gfc2PropertySetBinarySerializer,"Gfc2PropertySetB",0)

int Gfc2PropertySetBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PropertySet* pEnt = (Gfc2PropertySet*)pEntity;
    int total_size = Gfc2RootBinarySerializer::byteSize(pEnt);

    if (pEnt->hasIdentifier())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIdentifier());
    }

    if (pEnt->getHasPropertiesCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getHasPropertiesCount());
    for (int i = 0; i < pEnt->getHasPropertiesCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getHasProperties(i));
    }

    return total_size;
}

void Gfc2PropertySetBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PropertySet* pEnt = (Gfc2PropertySet*)pEntity;
    Gfc2RootBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasIdentifier())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getIdentifier(), output);
    }

    if (pEnt->getHasPropertiesCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getHasPropertiesCount(), output);
        for (int i = 0; i < pEnt->getHasPropertiesCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getHasProperties(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2PropertySetBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PropertySet* pEnt = (Gfc2PropertySet*)pEntity;
    target = Gfc2RootBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasIdentifier())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getIdentifier(), target);
    }

    if (pEnt->getHasPropertiesCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getHasPropertiesCount(), target);
        for (int i = 0; i < pEnt->getHasPropertiesCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getHasProperties(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PropertySetBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PropertySet* pEnt = (Gfc2PropertySet*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RootBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PropertySet_Identifier)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setIdentifier(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PropertySet_HasProperties)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addHasProperties(value);
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

