#ifndef ENTITYWRAPPTR_H
#define ENTITYWRAPPTR_H

#include "GfcEngine\GfcEngine.h"
#include <memory>

GFCENGINE_NAMESPACE_BEGIN

template<class T>
class CEntityWrapPtr
{
public:
    CEntityWrapPtr() : m_nRef(-1), m_pEntity(nullptr)
    {
    }
    CEntityWrapPtr(EntityRef nRef, T* pEntity) : m_nRef(nRef), m_pEntity(pEntity)
    {
    }
    CEntityWrapPtr(EntityRef nRef, std::shared_ptr<T> pEntity) : m_nRef(nRef), m_pEntity(pEntity)
    {
    }
    constexpr CEntityWrapPtr(nullptr_t): m_nRef(-1), m_pEntity(nullptr)
    {	// construct empty shared_ptr
    }
    T* get() const { return m_pEntity.get(); }
    std::shared_ptr<T> getPtr() const { return m_pEntity; }
    EntityRef ref() const { return m_nRef; }
    T* operator->()
    {	// return pointer to resource
        return get();
    }
private:
    EntityRef m_nRef;
    std::shared_ptr<T> m_pEntity;
};

template<class _Ty1, class _Ty2>
bool operator==(const CEntityWrapPtr<_Ty1>& _Left,
    const CEntityWrapPtr<_Ty2>& _Right)
{	// test if shared_ptr == shared_ptr
    return (_Left.get() == _Right.get());
}
template<class _Ty1, class _Ty2>
bool operator!=(const CEntityWrapPtr<_Ty1>& _Left,
    const CEntityWrapPtr<_Ty2>& _Right)
{	// test if shared_ptr != shared_ptr
    return (!(_Left == _Right));
}
template<class _Ty>
bool operator==(const CEntityWrapPtr<_Ty>& _Left,
    nullptr_t)
{	// test if shared_ptr == nullptr
    return (_Left.get() == (_Ty *)0);
}

template<class _Ty>
bool operator==(nullptr_t,
    const CEntityWrapPtr<_Ty>& _Right)
{	// test if nullptr == shared_ptr
    return ((_Ty *)0 == _Right.get());
}

template<class _Ty>
bool operator!=(const CEntityWrapPtr<_Ty>& _Left,
    nullptr_t _Right)
{	// test if shared_ptr != nullptr
    return (!(_Left == _Right));
}

template<class _Ty>
bool operator!=(nullptr_t _Left,
    const CEntityWrapPtr<_Ty>& _Right)
{	// test if nullptr != shared_ptr
    return (!(_Left == _Right));
}

template<class _Ty1,
    class _Ty2>
    CEntityWrapPtr<_Ty1>
    dynamic_entity_cast(const CEntityWrapPtr<_Ty2>& _Other) _NOEXCEPT
{	// return shared_ptr object holding dynamic_cast<_Ty1 *>(_Other.get())
//    typedef typename shared_ptr<_Ty1>::element_type _Elem1;
    std::shared_ptr<_Ty1> _Ptr = std::dynamic_pointer_cast<_Ty1>(_Other.getPtr());
    if (_Ptr)
        return (CEntityWrapPtr<_Ty1>(_Other.ref(), _Ptr));
    else
        return (CEntityWrapPtr<_Ty1>());
}

GFCENGINE_NAMESPACE_END

#endif // !ENTITYWRAPPTR_H

