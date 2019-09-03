#include "StdAfx.h"
#include "Gfc2PlaneCoefBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PlaneCoef.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneCoefBinarySerializer,"Gfc2PlaneCoefB",0)

int Gfc2PlaneCoefBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneCoef* pEnt = (Gfc2PlaneCoef*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasA())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasB())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasC())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasD())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2PlaneCoefBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneCoef* pEnt = (Gfc2PlaneCoef*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasA())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getA(), output);
    }

    if (pEnt->hasB())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getB(), output);
    }

    if (pEnt->hasC())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getC(), output);
    }

    if (pEnt->hasD())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(4, pEnt->getD(), output);
    }

}

google::protobuf::uint8* Gfc2PlaneCoefBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneCoef* pEnt = (Gfc2PlaneCoef*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasA())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getA(), target);
    }

    if (pEnt->hasB())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getB(), target);
    }

    if (pEnt->hasC())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getC(), target);
    }

    if (pEnt->hasD())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, pEnt->getD(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PlaneCoefBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PlaneCoef* pEnt = (Gfc2PlaneCoef*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneCoef_A)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setA(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneCoef_B)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setB(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneCoef_C)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setC(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneCoef_D)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setD(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

