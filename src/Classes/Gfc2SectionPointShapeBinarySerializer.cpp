#include "StdAfx.h"
#include "Gfc2SectionPointShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SectionPointShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2SectionPointShapeBinarySerializer,"Gfc2SectionPointShapeB",0)

int Gfc2SectionPointShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionPointShape* pEnt = (Gfc2SectionPointShape*)pEntity;
    int total_size = Gfc2CustomPointShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPoly())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoly());
    }

    return total_size;
}

void Gfc2SectionPointShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionPointShape* pEnt = (Gfc2SectionPointShape*)pEntity;
    Gfc2CustomPointShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPoly())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getPoly(), output);
    }

}

google::protobuf::uint8* Gfc2SectionPointShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SectionPointShape* pEnt = (Gfc2SectionPointShape*)pEntity;
    target = Gfc2CustomPointShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPoly())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getPoly(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SectionPointShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SectionPointShape* pEnt = (Gfc2SectionPointShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CustomPointShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SectionPointShape_Poly)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoly(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

