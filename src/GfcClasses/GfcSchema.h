#ifndef GFCSCHEMA_H
#define GFCSCHEMA_H

#include <string>

namespace gfc2 {
    namespace schema {
        class CModel;
        class CTypeObject;
    }
}

extern gfc2::schema::CModel* g_pModel;

gfc2::schema::CTypeObject* findSchema(const std::wstring& sName);

#endif // !GFCSCHEMA_H

