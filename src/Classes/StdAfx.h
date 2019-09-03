// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#ifndef STDAFX_H
#define STDAFX_H

//#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
// #include <windows.h>
// 
// // C 运行时头文件
// #include <stdlib.h>
// #include <malloc.h>
// #include <memory.h>
// #include <tchar.h>

#include <google/protobuf/wire_format_lite.h>
//#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/stubs/common.h>

// TODO: 在此处引用程序需要的其他头文件
#include "glodon/objectbuf/EntitySchema.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/EntityTextSerializer.h"
#include "glodon/objectbuf/EntityBinarySerializer.h"
#include "FieldCache.h"

#include <vector>
#include <sstream>
#include <string>
#include <limits>
using namespace std;
#endif

