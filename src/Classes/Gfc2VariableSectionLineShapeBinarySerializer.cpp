#include "StdAfx.h"
#include "Gfc2VariableSectionLineShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2VariableSectionLineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2VariableSectionLineShapeBinarySerializer,"Gfc2VariableSectionLineShapeB",0)

int Gfc2VariableSectionLineShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2VariableSectionLineShape* pEnt = (Gfc2VariableSectionLineShape*)pEntity;
    int total_size = Gfc2SectionLineShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasEndPoly())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEndPoly());
    }

    return total_size;
}

void Gfc2VariableSectionLineShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2VariableSectionLineShape* pEnt = (Gfc2VariableSectionLineShape*)pEntity;
    Gfc2SectionLineShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasEndPoly())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(15, pEnt->getEndPoly(), output);
    }

}

google::protobuf::uint8* Gfc2VariableSectionLineShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2VariableSectionLineShape* pEnt = (Gfc2VariableSectionLineShape*)pEntity;
    target = Gfc2SectionLineShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasEndPoly())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(15, pEnt->getEndPoly(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2VariableSectionLineShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2VariableSectionLineShape* pEnt = (Gfc2VariableSectionLineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SectionLineShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2VariableSectionLineShape_EndPoly)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEndPoly(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

