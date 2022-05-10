#ifndef _GFC_SCHEMA_H
#define _GFC_SCHEMA_H

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

