#include "SerializerManager.h"
#include "Common.h"
#include "tinyxml.h"
#include <algorithm>
#include <iostream>

namespace glodon {
namespace objectbuf {

typedef ReaderImp* (*CreateReaderImpFunc)(TiXmlElement*);
typedef WriterImp* (*CreateWriterImpFunc)(TiXmlElement*);
typedef void (*FreeWriterImpFunc)(WriterImp*);
typedef void (*FreeReaderImpFunc)(ReaderImp*);

std::weak_ptr<SerializerManager> SerializerManager::m_pSerializerManager;

SerializerManager::SerializerManager()
{
}


SerializerManager::~SerializerManager()
{
    free();
}

void SerializerManager::init()
{
    TiXmlDocument oConfig;
    if (oConfig.LoadFile(toString(getExePath() + L"\\EngineConfig.xml").c_str()))
    {
        auto pSerializerNode = oConfig.RootElement()->FirstChildElement();
        while (pSerializerNode)
        {
            SerializerInfo oInfo;
            auto sFileName = getFullPath(toWstring(pSerializerNode->Attribute("dll")));
            auto nHandle = LoadLibrary(sFileName.c_str());
            if (nHandle)
            {
                oInfo.handle = nHandle;
                oInfo.type = pSerializerNode->Attribute("type");
                auto pCreateReaderImp = (CreateReaderImpFunc)GetProcAddress(nHandle, "CreateReaderImp");
                if (pCreateReaderImp)
                    oInfo.readerImp = pCreateReaderImp(pSerializerNode);
                auto pCreateWriterImp = (CreateWriterImpFunc)GetProcAddress(nHandle, "CreateWriterImp");
                if (pCreateWriterImp)
                    oInfo.writerImp = pCreateWriterImp(pSerializerNode);
                m_oSerializerList.push_back(oInfo);
            }
            else
            {
                auto nError = GetLastError();
                std::cerr << "LoadLibrary Error: " << nError << std::endl;
            }
            pSerializerNode = pSerializerNode->NextSiblingElement();
        }
    }
}

void SerializerManager::free()
{
    for each (auto oInfo in m_oSerializerList)
    {
        auto pFreeReaderImp = (FreeReaderImpFunc)GetProcAddress(oInfo.handle, "FreeReaderImp");
        if (pFreeReaderImp)
            pFreeReaderImp(oInfo.readerImp);
        auto pFreeWriterImp = (FreeWriterImpFunc)GetProcAddress(oInfo.handle, "FreeWriterImp");
        if (pFreeWriterImp)
            pFreeWriterImp(oInfo.writerImp);
        FreeLibrary(oInfo.handle);
    }
}

int SerializerManager::getCount()
{
    return (int)m_oSerializerList.size();
}

ReaderImp * SerializerManager::getReaderImp(int nIndex)
{
    return m_oSerializerList[nIndex].readerImp;
}

WriterImp * SerializerManager::getWriterImp(const std::string & sType)
{
    auto itr = std::find_if(m_oSerializerList.begin(), m_oSerializerList.end(), [sType](SerializerInfo& oInfo) { return oInfo.type == sType; });
    return itr == m_oSerializerList.end() ? nullptr : itr->writerImp;
}

SerializerManagerPtr SerializerManager::getInstance()
{
    auto sp = m_pSerializerManager.lock();
    if (sp == nullptr)
    {
        sp = SerializerManagerPtr(new SerializerManager);
        sp->init();
        m_pSerializerManager = sp;
    }
    return sp;
}

}
}
