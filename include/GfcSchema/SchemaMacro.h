#ifndef SCHEMAMACRO_H
#define SCHEMAMACRO_H

#ifdef GFCSCHEMA_EXPORTS
#define GFCSCHEMA_API __declspec(dllexport)
#else
#define GFCSCHEMA_API __declspec(dllimport)
#endif


#define GFC_NAMESPACE_BEGIN namespace gfc { namespace schema {
#define GFC_NAMESPACE_END }}

//#pragma warning(disable:4251)

#include <string>
#include <vector>

struct __declspec(dllexport) std::_Container_base12;
template union __declspec(dllexport) std::_String_val<std::_Simple_types<wchar_t>>::_Bxty;
template class __declspec(dllexport) std::_String_val<std::_Simple_types<wchar_t>>;
template class __declspec(dllexport) std::_Compressed_pair<std::_Wrap_alloc<std::allocator<wchar_t>>, std::_String_val<std::_Simple_types<wchar_t>>, true>;
template class __declspec(dllexport) std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>;
template class __declspec(dllexport) std::_Vector_val<std::_Simple_types<std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>>>;
template class __declspec(dllexport) std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::wstring>>, std::_Vector_val<std::_Simple_types<std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>>>, true>;
template class __declspec(dllexport) std::vector<std::wstring, std::allocator<std::wstring>>;

#endif // !SCHEMAMACRO_H

