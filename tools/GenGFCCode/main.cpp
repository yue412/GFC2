#include "getopt.h"
#include <iostream>
#if (defined _WIN32 || defined _WIN64)
#include <windows.h>
#endif
#include "umltranslator.h"
#include "common.h"
#include <stdarg.h>

void parseTranslateInfo(int argc, char *argv[], CTranslateInfo& oInfo);

int main(int argc, char *argv[])
{
    std::locale::global(std::locale("zh_CN.UTF-8"));
    CTranslateInfo oInfo;
    parseTranslateInfo(argc, argv, oInfo);
    CUMLTranslator().done(oInfo);
    return 0;
}

std::wstring charToWString(char* str)
{
    return ACPToUnicode(str);
    /*
    int size = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    wchar_t* ch = new wchar_t[size + 1];
    if (MultiByteToWideChar(CP_ACP, 0, str, -1, ch, size))
    {
        std::wstring s = ch;
        delete[] ch;
        return s;
    }
    else
    {
        return L"";
    }
    */
}

void parseTranslateInfo(int argc, char *argv[], CTranslateInfo& oInfo)
{
    char opt;
    while ((opt = getopt(argc, argv, "h:r:c:t:b:n:e:d:v:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            oInfo.sHeadPath = getFullPath(charToWString(optarg));
            break;
        case 'r':
            oInfo.sHeadRelativePath = charToWString(optarg);
            break;
        case 'c':
            oInfo.sCPPPath = getFullPath(charToWString(optarg));
            break;
        //case 't':
        //    oInfo.sTextPath = getFullPath(charToWString(optarg));
        //    break;
        //case 'b':
        //    oInfo.sBinPath = getFullPath(charToWString(optarg));
        //    break;
        case 'n':
            oInfo.sNETPath = getFullPath(charToWString(optarg));
            break;
        case 'e':
            oInfo.sExpressFile = getFullPath(charToWString(optarg));
            break;
        case 'd':
            oInfo.sHtmlPath = getFullPath(charToWString(optarg));
            break;
        case 'v':
            oInfo.sVersion = charToWString(optarg);
            break;
        default:
            std::wcout << L"未识别命令行选项" << std::endl;
            break;
        }
    }
    if (optind < argc)
    {
        // 还有参数
        oInfo.sUMLFile = getFullPath(charToWString(argv[optind]));
    }
}
