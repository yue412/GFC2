#include "StdAfx.h"
#include "Gfc2AbnormityLineArchInfoBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2AbnormityLineArchInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2AbnormityLineArchInfoBinarySerializer,"Gfc2AbnormityLineArchInfoB",0)

int Gfc2AbnormityLineArchInfoBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AbnormityLineArchInfo* pEnt = (Gfc2AbnormityLineArchInfo*)pEntity;
    int total_size = Gfc2BaseLineArcInfoBinarySerializer::byteSize(pEnt);

    if (pEnt->hasTopArchStartT())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasTopArchEndT())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasTopDefineByRadius())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasTopArchHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasTopArchRadius())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasDownArchStartT())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasDownArchEndT())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasDownDefineByRadius())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasDownArchHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasDownArchRadius())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2AbnormityLineArchInfoBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AbnormityLineArchInfo* pEnt = (Gfc2AbnormityLineArchInfo*)pEntity;
    Gfc2BaseLineArcInfoBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasTopArchStartT())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getTopArchStartT(), output);
    }

    if (pEnt->hasTopArchEndT())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getTopArchEndT(), output);
    }

    if (pEnt->hasTopDefineByRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(3, pEnt->getTopDefineByRadius(), output);
    }

    if (pEnt->hasTopArchHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(4, pEnt->getTopArchHeight(), output);
    }

    if (pEnt->hasTopArchRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(5, pEnt->getTopArchRadius(), output);
    }

    if (pEnt->hasDownArchStartT())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(6, pEnt->getDownArchStartT(), output);
    }

    if (pEnt->hasDownArchEndT())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(7, pEnt->getDownArchEndT(), output);
    }

    if (pEnt->hasDownDefineByRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(8, pEnt->getDownDefineByRadius(), output);
    }

    if (pEnt->hasDownArchHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(9, pEnt->getDownArchHeight(), output);
    }

    if (pEnt->hasDownArchRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(10, pEnt->getDownArchRadius(), output);
    }

}

google::protobuf::uint8* Gfc2AbnormityLineArchInfoBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AbnormityLineArchInfo* pEnt = (Gfc2AbnormityLineArchInfo*)pEntity;
    target = Gfc2BaseLineArcInfoBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasTopArchStartT())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getTopArchStartT(), target);
    }

    if (pEnt->hasTopArchEndT())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getTopArchEndT(), target);
    }

    if (pEnt->hasTopDefineByRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, pEnt->getTopDefineByRadius(), target);
    }

    if (pEnt->hasTopArchHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, pEnt->getTopArchHeight(), target);
    }

    if (pEnt->hasTopArchRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, pEnt->getTopArchRadius(), target);
    }

    if (pEnt->hasDownArchStartT())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(6, pEnt->getDownArchStartT(), target);
    }

    if (pEnt->hasDownArchEndT())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(7, pEnt->getDownArchEndT(), target);
    }

    if (pEnt->hasDownDefineByRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, pEnt->getDownDefineByRadius(), target);
    }

    if (pEnt->hasDownArchHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(9, pEnt->getDownArchHeight(), target);
    }

    if (pEnt->hasDownArchRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, pEnt->getDownArchRadius(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2AbnormityLineArchInfoBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AbnormityLineArchInfo* pEnt = (Gfc2AbnormityLineArchInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2BaseLineArcInfoBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchStartT)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTopArchStartT(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchEndT)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTopArchEndT(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_TopDefineByRadius)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setTopDefineByRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchHeight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTopArchHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchRadius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTopArchRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchStartT)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setDownArchStartT(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchEndT)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setDownArchEndT(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_DownDefineByRadius)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setDownDefineByRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchHeight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setDownArchHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchRadius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setDownArchRadius(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

