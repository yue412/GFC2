#include "StdAfx.h"
#include "NGfc2EdgeData.h"
NGfc2EdgeData::NGfc2EdgeData()
{
    m_pEntity = new Gfc2EdgeData;
    m_bOwner = true;
}

NGfc2EdgeData::NGfc2EdgeData(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2EdgeData::setEdgeIndex(NGfc2Integer nValue)
{
    ((Gfc2EdgeData*)m_pEntity)->setEdgeIndex(nValue);
}

NGfc2Integer NGfc2EdgeData::getEdgeIndex()
{
    return ((Gfc2EdgeData*)m_pEntity)->getEdgeIndex();
}

bool NGfc2EdgeData::hasEdgeIndex()
{
    return ((Gfc2EdgeData*)m_pEntity)->hasEdgeIndex();
}

void NGfc2EdgeData::setLoopIndex(NGfc2Integer nValue)
{
    ((Gfc2EdgeData*)m_pEntity)->setLoopIndex(nValue);
}

NGfc2Integer NGfc2EdgeData::getLoopIndex()
{
    return ((Gfc2EdgeData*)m_pEntity)->getLoopIndex();
}

bool NGfc2EdgeData::hasLoopIndex()
{
    return ((Gfc2EdgeData*)m_pEntity)->hasLoopIndex();
}

void NGfc2EdgeData::setType(NGfc2Integer nValue)
{
    ((Gfc2EdgeData*)m_pEntity)->setType(nValue);
}

NGfc2Integer NGfc2EdgeData::getType()
{
    return ((Gfc2EdgeData*)m_pEntity)->getType();
}

bool NGfc2EdgeData::hasType()
{
    return ((Gfc2EdgeData*)m_pEntity)->hasType();
}

void NGfc2EdgeData::setEdgeInfo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2EdgeData*)m_pEntity)->setEdgeInfo(nValue);
}

glodon::objectbuf::EntityRef NGfc2EdgeData::getEdgeInfo()
{
    return ((Gfc2EdgeData*)m_pEntity)->getEdgeInfo();
}

bool NGfc2EdgeData::hasEdgeInfo()
{
    return ((Gfc2EdgeData*)m_pEntity)->hasEdgeInfo();
}

NGfc2String^ NGfc2EdgeData::getEdgeInfoPtr()
{
    return gcnew NGfc2String(((Gfc2EdgeData*)m_pEntity)->getEdgeInfoPtr(), false);
}

void NGfc2EdgeData::setParam(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2EdgeData*)m_pEntity)->setParam(nValue);
}

glodon::objectbuf::EntityRef NGfc2EdgeData::getParam()
{
    return ((Gfc2EdgeData*)m_pEntity)->getParam();
}

bool NGfc2EdgeData::hasParam()
{
    return ((Gfc2EdgeData*)m_pEntity)->hasParam();
}

NGfc2String^ NGfc2EdgeData::getParamPtr()
{
    return gcnew NGfc2String(((Gfc2EdgeData*)m_pEntity)->getParamPtr(), false);
}

void NGfc2EdgeData::setBaseType(NGfc2Integer nValue)
{
    ((Gfc2EdgeData*)m_pEntity)->setBaseType(nValue);
}

NGfc2Integer NGfc2EdgeData::getBaseType()
{
    return ((Gfc2EdgeData*)m_pEntity)->getBaseType();
}

bool NGfc2EdgeData::hasBaseType()
{
    return ((Gfc2EdgeData*)m_pEntity)->hasBaseType();
}

void NGfc2EdgeData::setSlopePoly(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2EdgeData*)m_pEntity)->setSlopePoly(nValue);
}

glodon::objectbuf::EntityRef NGfc2EdgeData::getSlopePoly()
{
    return ((Gfc2EdgeData*)m_pEntity)->getSlopePoly();
}

bool NGfc2EdgeData::hasSlopePoly()
{
    return ((Gfc2EdgeData*)m_pEntity)->hasSlopePoly();
}

NGfc2Polygon^ NGfc2EdgeData::getSlopePolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2EdgeData*)m_pEntity)->getSlopePolyPtr(), false);
}

