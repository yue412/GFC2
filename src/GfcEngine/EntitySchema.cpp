#include "glodon/objectbuf/EntitySchema.h"

namespace glodon {
namespace objectbuf {

EntitySchema::EntitySchema(void)
{
    m_pParent = NULL;
    m_nId = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

EntitySchema::~EntitySchema(void)
{
//    优化读取GFC文件效率，Schema不需要每次都创建,在Document中统一析构，这里不再进行析构 ,lit,xuxp
//    delete m_pParent;
}

bool EntitySchema::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int EntitySchema::typeId() const
{
    return 1;
}

string EntitySchema::entityName() const
{
    return "EntitySchema";
}

}
}