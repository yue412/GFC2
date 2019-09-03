#include "getopt.h"
#include <iostream>
#include <windows.h>
#include "umltranslator.h"

void parseTranslateInfo(int argc, char *argv[], CTranslateInfo& oInfo);

int main(int argc, char *argv[])
{
    CTranslateInfo oInfo;
    parseTranslateInfo(argc, argv, oInfo);
    CUMLTranslator().done(oInfo);
    return 0;
}

std::wstring charToWString(char* str)
{
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
}

void parseTranslateInfo(int argc, char *argv[], CTranslateInfo& oInfo)
{
    char opt;
    while ((opt = getopt(argc, argv, "h:c:n:e:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            oInfo.sHeadPath = charToWString(optarg);
            break;
        case 'c':
            oInfo.sCPPPath = charToWString(optarg);
            break;
        case 'n':
            oInfo.sNETPath = charToWString(optarg);
            break;
        case 'e':
            oInfo.sExpressFile = charToWString(optarg);
            break;
        default:
            std::wcout << L"未识别命令行选项" << std::endl;
            break;
        }
    }
    if (optind < argc)
    {
        // 还有参数
        oInfo.sUMLFile = charToWString(argv[optind]);
    }
}
