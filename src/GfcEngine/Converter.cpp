#include "GfcEngine\Converter.h"
#include "GfcSchema\EnumType.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Property.h"

GFCENGINE_NAMESPACE_BEGIN

CConverter::~CConverter()
{
    delete m_pNext;
}

void CConverter::transform(CPropValue* pFrom, CPropValue* pTo)
{
    // 为空不用转换
    if (pFrom->isNull())
        return;
    if (m_pNext)
        m_pNext->transform(pFrom, pTo);
    doTransform(pFrom, pTo);
}

void CConverter::setNext(CConverter * pNext)
{
    delete m_pNext;
    m_pNext = pNext;
}

void CConverter::init(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    m_pFrom = pFrom;
    m_pTo = pTo;
    if (m_pNext)
        m_pNext->init(pFrom, pTo);
}

void CEntityRefConverter::doTransform(CPropValue * pFrom, CPropValue * pTo)
{
    pTo->setAsEntityRef(pFrom->asEntityRef());
}

GFCENGINE_NAMESPACE_END