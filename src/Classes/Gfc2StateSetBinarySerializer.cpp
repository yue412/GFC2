#include "StdAfx.h"
#include "Gfc2StateSetBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2StateSet.h"

OBJECTBUF_IMP_OBJECT(Gfc2StateSetBinarySerializer,"Gfc2StateSetB",0)

int Gfc2StateSetBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2StateSet* pEnt = (Gfc2StateSet*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasAmbient())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getAmbient());
    }

    if (pEnt->hasDiffuse())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDiffuse());
    }

    if (pEnt->hasSourceBlendFactor())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getSourceBlendFactor());
    }

    if (pEnt->hasDestBlendFactor())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getDestBlendFactor());
    }

    if (pEnt->hasDepthTestEnabled())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasDepthWriteEnabled())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasDepthTestFunction())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getDepthTestFunction());
    }

    if (pEnt->hasPolygonOffsetFactor())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasPolygonOffsetUnits())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasPolygonStipple())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPolygonStipple());
    }

    if (pEnt->hasLineStipplePattern())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLineStipplePattern());
    }

    if (pEnt->hasLineStippleFactor())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLineStippleFactor());
    }

    if (pEnt->hasFaceMode())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getFaceMode());
    }

    if (pEnt->hasLightingEnabled())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasLightModelTwoSided())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2StateSetBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2StateSet* pEnt = (Gfc2StateSet*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasAmbient())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getAmbient(), output);
    }

    if (pEnt->hasDiffuse())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getDiffuse(), output);
    }

    if (pEnt->hasSourceBlendFactor())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, (int)pEnt->getSourceBlendFactor(), output);
    }

    if (pEnt->hasDestBlendFactor())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, (int)pEnt->getDestBlendFactor(), output);
    }

    if (pEnt->hasDepthTestEnabled())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(5, pEnt->getDepthTestEnabled(), output);
    }

    if (pEnt->hasDepthWriteEnabled())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(6, pEnt->getDepthWriteEnabled(), output);
    }

    if (pEnt->hasDepthTestFunction())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, (int)pEnt->getDepthTestFunction(), output);
    }

    if (pEnt->hasPolygonOffsetFactor())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(8, pEnt->getPolygonOffsetFactor(), output);
    }

    if (pEnt->hasPolygonOffsetUnits())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(9, pEnt->getPolygonOffsetUnits(), output);
    }

    if (pEnt->hasPolygonStipple())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(10, pEnt->getPolygonStipple(), output);
    }

    if (pEnt->hasLineStipplePattern())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(11, pEnt->getLineStipplePattern(), output);
    }

    if (pEnt->hasLineStippleFactor())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(12, pEnt->getLineStippleFactor(), output);
    }

    if (pEnt->hasFaceMode())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(13, (int)pEnt->getFaceMode(), output);
    }

    if (pEnt->hasLightingEnabled())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(14, pEnt->getLightingEnabled(), output);
    }

    if (pEnt->hasLightModelTwoSided())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(15, pEnt->getLightModelTwoSided(), output);
    }

}

google::protobuf::uint8* Gfc2StateSetBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2StateSet* pEnt = (Gfc2StateSet*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasAmbient())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getAmbient(), target);
    }

    if (pEnt->hasDiffuse())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getDiffuse(), target);
    }

    if (pEnt->hasSourceBlendFactor())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, (int)pEnt->getSourceBlendFactor(), target);
    }

    if (pEnt->hasDestBlendFactor())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, (int)pEnt->getDestBlendFactor(), target);
    }

    if (pEnt->hasDepthTestEnabled())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, pEnt->getDepthTestEnabled(), target);
    }

    if (pEnt->hasDepthWriteEnabled())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, pEnt->getDepthWriteEnabled(), target);
    }

    if (pEnt->hasDepthTestFunction())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, (int)pEnt->getDepthTestFunction(), target);
    }

    if (pEnt->hasPolygonOffsetFactor())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(8, pEnt->getPolygonOffsetFactor(), target);
    }

    if (pEnt->hasPolygonOffsetUnits())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(9, pEnt->getPolygonOffsetUnits(), target);
    }

    if (pEnt->hasPolygonStipple())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, pEnt->getPolygonStipple(), target);
    }

    if (pEnt->hasLineStipplePattern())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, pEnt->getLineStipplePattern(), target);
    }

    if (pEnt->hasLineStippleFactor())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, pEnt->getLineStippleFactor(), target);
    }

    if (pEnt->hasFaceMode())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(13, (int)pEnt->getFaceMode(), target);
    }

    if (pEnt->hasLightingEnabled())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(14, pEnt->getLightingEnabled(), target);
    }

    if (pEnt->hasLightModelTwoSided())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(15, pEnt->getLightModelTwoSided(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2StateSetBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2StateSet* pEnt = (Gfc2StateSet*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_Ambient)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setAmbient(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_Diffuse)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDiffuse(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_SourceBlendFactor)
    {
        Gfc2SceneBlendFactor value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setSourceBlendFactor(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_DestBlendFactor)
    {
        Gfc2SceneBlendFactor value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setDestBlendFactor(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_DepthTestEnabled)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setDepthTestEnabled(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_DepthWriteEnabled)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setDepthWriteEnabled(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_DepthTestFunction)
    {
        Gfc2FragTestFunc value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setDepthTestFunction(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_PolygonOffsetFactor)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setPolygonOffsetFactor(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_PolygonOffsetUnits)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setPolygonOffsetUnits(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_PolygonStipple)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPolygonStipple(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_LineStipplePattern)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLineStipplePattern(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_LineStippleFactor)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLineStippleFactor(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_FaceMode)
    {
        Gfc2FaceMode value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setFaceMode(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_LightingEnabled)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setLightingEnabled(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2StateSet_LightModelTwoSided)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setLightModelTwoSided(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

