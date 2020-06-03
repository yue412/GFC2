#ifndef GLODON_OBJECTBUF_DOCUMENT_H
#define GLODON_OBJECTBUF_DOCUMENT_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include "GfcEngine/Entity.h"
#include "GfcEngine/GfcEngine.h"
#include "GfcEngine\Container.h"
#include <functional>

namespace gfc {
    namespace schema {
        class CClass;
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class DocumentIterator;

typedef std::function<bool (Document*, EntityRef, Entity*)> needAddEntityFunc;
typedef std::function<void (Document*)> afterReadDocFunc;

template<class T> class ContainerImp;

struct __declspec(dllexport) std::_Container_base12;
template class __declspec(dllexport) std::function<void(gfc::engine::Document *)>;
template class __declspec(dllexport) std::function<bool(gfc::engine::Document *, EntityRef, gfc::engine::Entity *)>;
template class __declspec(dllexport) std::_Tree_val<std::_Tree_simple_types<std::wstring>>;
template class __declspec(dllexport) std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::_Tree_node<std::wstring, void *>>>, std::_Tree_val<std::_Tree_simple_types<std::wstring>>, true>;
template class __declspec(dllexport) std::_Compressed_pair<std::less<std::wstring>, std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::_Tree_node<std::wstring, void *>>>, std::_Tree_val<std::_Tree_simple_types<std::wstring>>, true>, true>;
template class __declspec(dllexport) std::set<std::wstring, std::less<std::wstring>, std::allocator<std::wstring>>;


class GFCENGINE_API Document: public IContainer
{
public:
    Document(gfc::schema::CModel* pModel, int nEntityInitCount = 1000000);
    ~Document(void);
    void add(EntityRef nId, Entity* pEntity);
    gfc::schema::CModel* model() const;

    virtual EntityPtr getEntity(EntityRef nId);
    virtual EntityIteratorPtr getEntities(const std::wstring& nType, bool bIncludeSubType = false);
    virtual EntityIteratorPtr getIterator();

    //void linkSchemaByParent();
    //bool schemaFilter(gfc::schema::CClass* pSchema, const std::string& nFilterType, bool bIncludeSubType);
    void setNeedAddEntityFunc(needAddEntityFunc pFunc){m_pNeedAddEntityFunc = pFunc;}
    needAddEntityFunc getNeedAddEntityFunc(){return m_pNeedAddEntityFunc;}
    void setAfterReadDocFunc(afterReadDocFunc pFunc){m_pAfterReadDocFunc = pFunc;}
    afterReadDocFunc getAfterReadDocFunc(){return m_pAfterReadDocFunc;}
private:
    //std::string normalizeTypeName(const std::string& sTypeName);
    ContainerImp<EntityPtr>* m_pContainer;
    //std::set<std::string> m_oSchemaInheritSet; //parent, child
    needAddEntityFunc m_pNeedAddEntityFunc;
    afterReadDocFunc m_pAfterReadDocFunc;
};

GFCENGINE_NAMESPACE_END

#endif

