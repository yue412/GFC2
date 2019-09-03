#include "glodon/objectbuf/EntityBinarySerializer.h"
#include "glodon/objectbuf/Entity.h"
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/stubs/common.h>

namespace glodon {
namespace objectbuf {

using namespace google::protobuf;
using namespace internal;

// When serializing, we first compute the byte size, then serialize the message.
// If serialization produces a different number of bytes than expected, we
// call this function, which crashes.  The problem could be due to a bug in the
// protobuf implementation but is more likely caused by concurrent modification
// of the message.  This function attempts to distinguish between the two and
// provide a useful error message.
void byteSizeConsistencyError(int byte_size_before_serialization,
    int byte_size_after_serialization,
    int bytes_produced_by_serialization) {
        GOOGLE_CHECK_EQ(byte_size_before_serialization, byte_size_after_serialization)
            << "Protocol message was modified concurrently during serialization.";
        GOOGLE_CHECK_EQ(bytes_produced_by_serialization, byte_size_before_serialization)
            << "Byte size calculation and serialization were inconsistent.  This "
            "may indicate a bug in protocol buffers or it may be caused by "
            "concurrent modification of the message.";
        GOOGLE_LOG(FATAL) << "This shouldn't be called if all the sizes are equal.";
}

EntityBinarySerializer::EntityBinarySerializer(void)
{
}


EntityBinarySerializer::~EntityBinarySerializer(void)
{
}

bool EntityBinarySerializer::serialize( google::protobuf::io::CodedOutputStream* output, Entity* pEntity ) const
{
    GOOGLE_DCHECK(pEntity->isInitialized());
    const int size = byteSize(pEntity);  // Force size to be cached.
    google::protobuf::uint8* buffer = output->GetDirectBufferForNBytesAndAdvance(size);
    if (buffer != NULL) {
        google::protobuf::uint8* end = serializeWithCachedSizesToArray(buffer, pEntity);
        if (end - buffer != size) {
            byteSizeConsistencyError(size, byteSize(pEntity), end - buffer);
        }
        return true;
    } else {
        int original_byte_count = output->ByteCount();
        serializeWithCachedSizes(output, pEntity);
        if (output->HadError()) {
            return false;
        }
        int final_byte_count = output->ByteCount();

        if (final_byte_count - original_byte_count != size) {
            byteSizeConsistencyError(size, byteSize(pEntity),
                final_byte_count - original_byte_count);
        }

        return true;
    }
}

void EntityBinarySerializer::serializeWithCachedSizes( google::protobuf::io::CodedOutputStream* output, Entity* pEntity ) const
{

}

google::protobuf::uint8* EntityBinarySerializer::serializeWithCachedSizesToArray( google::protobuf::uint8* target, Entity* pEntity ) const
{
    return target;
}

bool EntityBinarySerializer::parse( google::protobuf::io::CodedInputStream* input, Entity* pEntity )
{
    bool bResult = true;
    while (!input->ExpectAtEnd())
    {
        ::google::protobuf::uint32 tag = input->ReadTag();
        int nFieldNum = ::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag);
        bResult = parseField(input, nFieldNum, pEntity) != PFS_FAIL;
        if (!bResult)
            break;
    }
    return bResult;
}

EnParseFieldState EntityBinarySerializer::parseField( google::protobuf::io::CodedInputStream* input, int nFieldNum, Entity* pEntity ) 
{
    return PFS_IGNORE;
}

int EntityBinarySerializer::byteSize(Entity* pEntity) const
{
    return 0;
}

// void EntityBinarySerializer::WriteEntityMaybeToArray( int field_number, const Entity& value, google::protobuf::io::CodedOutputStream* output ) const
// {
//     WireFormatLite::WriteTag(field_number, WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
//     const int size = value.byteSize();//GetCachedSize();
//     //output->WriteVarint32(size);
//     uint8* target = output->GetDirectBufferForNBytesAndAdvance(size);
//     if (target != NULL) {
//         uint8* end = value.serializeWithCachedSizesToArray(target);
//         GOOGLE_DCHECK_EQ(end - target, size);
//     } else {
//         value.serializeWithCachedSizes(output);
//     }
// }
// 
// uint8* EntityBinarySerializer::WriteEntityNoVirtualToArray( int field_number, const Entity& value, uint8* target ) const
// {
//     target = WireFormatLite::WriteTagToArray(field_number, WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
//     //     target = io::CodedOutputStream::WriteVarint32ToArray(
//     //         value.byteSize(), target);
//     return value.serializeWithCachedSizesToArray(target);
// }
// 
// bool EntityBinarySerializer::ReadEntityNoVirtual( google::protobuf::io::CodedInputStream* input, Entity* value )
// {
//     uint32 length;
//     //if (!input->ReadVarint32(&length)) return false;
//     //if (!input->IncrementRecursionDepth()) return false;
//     //io::CodedInputStream::Limit limit = input->PushLimit(length);
//     if (!value->parse(input))
//         return false;
//     // Make sure that parsing stopped when the limit was hit, not at an endgroup
//     // tag.
//     //if (!input->ConsumedEntireMessage()) return false;
//     //input->PopLimit(limit);
//     //input->DecrementRecursionDepth();
//     return true;
// }
// 
// void EntityBinarySerializer::WriteEntityMaybeToArrayNoTag( const Entity& value, google::protobuf::io::CodedOutputStream* output ) const
// {
//     //WireFormatLite::WriteTag(field_number, WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
//     const int size = value.byteSize();//GetCachedSize();
//     //    output->WriteVarint32(size);
//     uint8* target = output->GetDirectBufferForNBytesAndAdvance(size);
//     if (target != NULL) {
//         uint8* end = value.serializeWithCachedSizesToArray(target);
//         GOOGLE_DCHECK_EQ(end - target, size);
//     } else {
//         value.serializeWithCachedSizes(output);
//     }
// }
// 
// google::protobuf::uint8* EntityBinarySerializer::WriteEntityNoVirtualNoTagToArray( const Entity& value, google::protobuf::uint8* target ) const
// {
//     //target = WireFormatLite::WriteTagToArray(field_number, WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
//     //     target = io::CodedOutputStream::WriteVarint32ToArray(
//     //         value.byteSize(), target);
//     return value.serializeWithCachedSizesToArray(target);
// }

}
}
