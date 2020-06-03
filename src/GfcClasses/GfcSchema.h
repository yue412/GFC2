#ifndef GFCSCHEMA_H
#define GFCSCHEMA_H

#include <string>

namespace gfc {
    namespace schema {
        class CModel;
        class CTypeObject;
    }
}

extern gfc::schema::CModel* g_pModel;

gfc::schema::CTypeObject* findSchema(const std::wstring& sName);

#endif // !GFCSCHEMA_H

