#include "StdAfx.h"
#include "Gfc2PointShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PointShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointShapeBinarySerializer,"Gfc2PointShapeB",0)

int Gfc2PointShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape* pEnt = (Gfc2PointShape*)pEntity;
    int total_size = Gfc2SectionPointShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasObliqueDir())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getObliqueDir());
    }

    if (pEnt->hasTopPoly())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getTopPoly());
    }

    return total_size;
}

void Gfc2PointShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape* pEnt = (Gfc2PointShape*)pEntity;
    Gfc2SectionPointShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(10, pEnt->getHeight(), output);
    }

    if (pEnt->hasObliqueDir())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(11, pEnt->getObliqueDir(), output);
    }

    if (pEnt->hasTopPoly())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(12, pEnt->getTopPoly(), output);
    }

}

google::protobuf::uint8* Gfc2PointShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape* pEnt = (Gfc2PointShape*)pEntity;
    target = Gfc2SectionPointShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, pEnt->getHeight(), target);
    }

    if (pEnt->hasObliqueDir())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, pEnt->getObliqueDir(), target);
    }

    if (pEnt->hasTopPoly())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, pEnt->getTopPoly(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PointShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PointShape* pEnt = (Gfc2PointShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SectionPointShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointShape_Height)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointShape_ObliqueDir)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setObliqueDir(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointShape_TopPoly)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setTopPoly(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

