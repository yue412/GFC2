#include <iostream>
#include "umlreader.h"
#include "EntityClass.h"
#include "TypeDefine.h"
#include "enumtype.h"
#include "model.h"
#include "EntityAttribute.h"
#include "tinyxml.h"
#include "common.h"

CUMLReader::CUMLReader(CModel *pModel): m_pModel(pModel)
{
}

void CUMLReader::load(const std::wstring &sFileName)
{
    _ASSERT(m_pModel);
    if (sFileName.empty())
    {
        _ASSERT(false);
        return;
    }

    //QFile oFile(QString::fromStdWString(sFileName));
    //if (!oFile.open(QFile::ReadOnly | QFile::Text))
    //{
    //    std::wcout << L"文件打开失败!" << std::endl;
    //    return;
    //}
    // 预处理
    initial();
    TiXmlDocument oDoc;
    if (oDoc.LoadFile(toString(sFileName)))
    {
        TiXmlElement* pElement = oDoc.RootElement()->FirstChildElement();
        while (pElement)
        {
            if (pElement->ValueStr().compare("XPD:BODY") == 0)
            {
                loadBody(pElement->FirstChildElement()); //obj
            }
            pElement = pElement->NextSiblingElement();
        }
        // 后处理
    }
    finalize();
}

void CUMLReader::initial()
{
    m_oAttributeList.clear();
    m_oTypedefList.clear();
    m_oTypeObjectMap.clear();
    m_oGeneralizationList.clear();
    m_oAssociationList.clear();
}

void CUMLReader::finalize()
{
    for(CAttributeList::iterator itr = m_oAttributeList.begin(); itr != m_oAttributeList.end(); ++itr)
    {
        std::wstring sName = itr->second;
        CTypeObject* pTypeObject = m_pModel->findTypeObject(sName);
        if (pTypeObject)
        {
            itr->first->SetType(pTypeObject);
        }
        else
        {
            std::wcout << L"Attribute: " << itr->first->getName() << L" miss type: " << sName <<std::endl;
            _ASSERT(pTypeObject);
        }
    }

    for(CTypeDefList::iterator itr = m_oTypedefList.begin(); itr != m_oTypedefList.end(); ++itr)
    {
        CTypeObject* pTypeObject = m_pModel->findTypeObject(itr->second);
        _ASSERT(pTypeObject);
        itr->first->SetRefType(pTypeObject);
    }

    for (CGeneralizationList::iterator itr = m_oGeneralizationList.begin();
         itr != m_oGeneralizationList.end(); ++itr)
    {
        // 添加父子关系
        CTypeObject* pChild = findTypeObjectByGUID(itr->first);
        CTypeObject* pParent = findTypeObjectByGUID(itr->second);
        if (pChild && pParent && pChild->getType() == TOE_CLASS && pParent->getType() == TOE_CLASS)
        {
            CClass* pChildClass = dynamic_cast<CClass*>(pChild);
            CClass* pParentClass = dynamic_cast<CClass*>(pParent);
            if (!pChildClass->getParent())
            {
                pChildClass->setParent(pParentClass);
                pParentClass->addChild(pChildClass);
            }
            else
            {
                _ASSERT(false);
            }
        }
        else
        {
            _ASSERT(false);
        }
    }

    for (CAssociationList::iterator itr = m_oAssociationList.begin(); itr != m_oAssociationList.end(); ++itr)
    {
        CTypeObject* pOwner = findTypeObjectByGUID(itr->OwnerTypeName);
        CTypeObject* pType = findTypeObjectByGUID(itr->TypeName);
        if (pOwner && pType && pOwner->getType() == TOE_CLASS)
        {
            CAttribute* pAttribute = new CAttribute();
            pAttribute->SetName(itr->FieldName);
            pAttribute->SetType(pType);
            pAttribute->SetRepeatFlag(itr->IsMultiplicity);
            pAttribute->SetOptionalFlag(itr->IsOptional);
            pAttribute->setDocument(itr->Document);
            ((CClass*)pOwner)->addAttribute(pAttribute);
        }
        else
        {
			std::wcout << L"Owner: " << itr->OwnerTypeName 
				<< L" Attribute: " << itr->FieldName 
				<< L" type: " << itr->TypeName;
            _ASSERT(false);
        }
    }
}

void CUMLReader::loadBody(TiXmlElement * pBody)
{
    TiXmlElement* pChild = pBody->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:OBJ")
        {
            std::string sTypeValue;
            if (pChild->QueryStringAttribute("type", &sTypeValue) == TIXML_SUCCESS && sTypeValue == "UMLModel")
            {
                loadModel(pChild);
            }
        }
        pChild = pChild->NextSiblingElement();
    }
}

void CUMLReader::loadModel(TiXmlElement * pModel)
{
    TiXmlElement* pChild = pModel->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:OBJ")
        {
            std::string sTypeValue;
            if (pChild->QueryStringAttribute("type", &sTypeValue) == TIXML_SUCCESS)
            {
                if (sTypeValue == "UMLClass")
                {
                    loadClass(pChild);
                }
                else if (sTypeValue == "UMLGeneralization")
                {
                    doneGeneralization(pChild);
                }
                else if (sTypeValue == "UMLAssociation")
                {
                    doneAssociation(pChild);
                }
                else if (sTypeValue == "UMLPackage")
                {
                    loadModel(pChild); // recursion
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
}

void CUMLReader::loadClass(TiXmlElement * pClass)
{
    CTypeObject* pTypeObject = createClass(pClass);
    std::string sGuidValue;
    if (pClass->QueryStringAttribute("guid", &sGuidValue) != TIXML_SUCCESS)
        return;
    std::wstring sGuid = Utf8ToUnicode(sGuidValue);
    m_pModel->addTypeObject(pTypeObject);
    m_oTypeObjectMap.insert(std::make_pair(sGuid, pTypeObject));

    TiXmlElement* pChild = pClass->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:OBJ")
        {
            std::string sTypeValue;
            if (pChild->QueryStringAttribute("type", &sTypeValue) == TIXML_SUCCESS)
            {
                if (sTypeValue == "UMLAttribute")
                {
                    CClass* pClass = dynamic_cast<CClass*>(pTypeObject);
                    if (pClass)
                    {
                        pClass->addAttribute(getAttribute(pChild));
                    }
                    else
                    {
                        CTypeDef* pTypeDef = dynamic_cast<CTypeDef*>(pTypeObject);
                        if (pTypeDef)
                        {
                            std::wstring sTypeName = getAttributeName(pChild);
                            CTypeObject* pTypeObject = m_pModel->findTypeObject(sTypeName);
                            if (pTypeObject)
                            {
                                pTypeDef->SetRefType(pTypeObject);
                            }
                            else
                            {
                                // 延后关联
                                m_oTypedefList.push_back(std::make_pair(pTypeDef, sTypeName));
                            }
                        }
                        else
                        {
                            CEnumType* pEnumType = dynamic_cast<CEnumType*>(pTypeObject);
                            if (pEnumType)
                            {
                                pEnumType->addEnum(getAttributeName(pChild), getAttributeDocument(pChild));
                            }
                        }
                    }
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
}

CTypeObject * CUMLReader::createClass(TiXmlElement * pClass)
{
    std::string sClassName, sDocument;
    bool bIsAbstract = false;
    CTypeObject* pTypeObject = nullptr;
    TiXmlElement* pChild = pClass->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:ATTR")
        {
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Name")
                {
                    sClassName = pChild->GetText();
                }
                else if (sNameValue == "IsAbstract")
                {
                    std::string sTemp = pChild->GetText();
                    bIsAbstract = sTemp == "True";
                }
                else if (sNameValue == "Documentation")
                {
                    sDocument = pChild->GetText();
                }
                else if (sNameValue == "StereotypeName")
                {
                    std::wstring sText = Utf8ToUnicode(pChild->GetText());
                    if (sText == L"type")
                    {
                        pTypeObject = new CTypeDef();
                    }
                    else if (sText == L"enum")
                    {
                        pTypeObject = new CEnumType();
                    }
                    else if (sText == L"record")
                    {
                        pTypeObject = new CClass();
                        //((CClass*)pTypeObject)->setIsValueType(true);
                    }
                    else
                    {
                        _ASSERT(false);
                    }
                }
            }

        }
        pChild = pChild->NextSiblingElement();
    }
    if (pTypeObject == nullptr)
    {
        pTypeObject = new CClass();
        ((CClass*)pTypeObject)->setIsAbstract(bIsAbstract);
    }
    pTypeObject->SetName(Utf8ToUnicode(sClassName));
    pTypeObject->setDocument(Utf8ToUnicode(sDocument));
    return  pTypeObject;
}

void CUMLReader::doneGeneralization(TiXmlElement * pGeneralization)
{
    std::wstring sChildGUID;
    std::wstring sParentGUID;
    TiXmlElement* pChild = pGeneralization->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:REF")
        {
            //
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Child")
                {
                    sChildGUID = Utf8ToUnicode(pChild->GetText());
                }
                else if (sNameValue == "Parent")
                {
                    sParentGUID = Utf8ToUnicode(pChild->GetText());
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
    if (!sChildGUID.empty() && !sParentGUID.empty())
    {
        m_oGeneralizationList.push_back(std::make_pair(sChildGUID, sParentGUID));
    }
}

void CUMLReader::doneAssociation(TiXmlElement * pAssociation)
{
    std::wstring sDocument;
    CAssociationEnd oAssociationEndArray[2];
    int nIndex = 0;
    TiXmlElement* pChild = pAssociation->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:OBJ")
        {
            std::string sTypeValue;
            if (pChild->QueryStringAttribute("type", &sTypeValue) == TIXML_SUCCESS)
            {
                if (sTypeValue == "UMLAssociationEnd" && nIndex < 2)
                {
                    oAssociationEndArray[nIndex] = getAssociationEnd(pChild);
                    //if (oAssociationEndArray[nIndex].TypeName == L"")
                    //{
                    //	qDebug() << "UMLAssociationEnd" << endl;
                    //	qDebug() << "Name: " << std::wstring::fromStdWString(oAssociationEndArray[nIndex].Name) << endl;
                    //	qDebug() << "TypeName: " << std::wstring::fromStdWString(oAssociationEndArray[nIndex].TypeName) << endl;
                    //	qDebug() << "Multiplicity: " << std::wstring::fromStdWString(oAssociationEndArray[nIndex].Multiplicity) << endl;
                    //}
                    //if (oAssociationEndArray[nIndex].Name == L"Plane")
                    //{
                    //	qDebug() << "UMLAssociationEnd" << endl;
                    //	qDebug() << "Name: " << std::wstring::fromStdWString(oAssociationEndArray[nIndex].Name) << endl;
                    //	qDebug() << "TypeName: " << std::wstring::fromStdWString(oAssociationEndArray[nIndex].TypeName) << endl;
                    //	qDebug() << "Multiplicity: " << std::wstring::fromStdWString(oAssociationEndArray[nIndex].Multiplicity) << endl;
                    //}
                    ++nIndex;
                }
            }
        }
        else if (pChild->ValueStr() == "XPD:ATTR")
        {
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Documentation")
                {
                    sDocument = Utf8ToUnicode(pChild->GetText());
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
    CAssociation oAssociation;
    oAssociation.Document = sDocument;
    if (initAssociation(oAssociationEndArray[0], oAssociationEndArray[1], oAssociation))
    {
        m_oAssociationList.push_back(oAssociation);
    }
    if (initAssociation(oAssociationEndArray[1], oAssociationEndArray[0], oAssociation))
    {
        m_oAssociationList.push_back(oAssociation);
    }
}

bool CUMLReader::initAssociation(CAssociationEnd &oEnd1, CAssociationEnd &oEnd2, CAssociation &oAssociation)
{
    if (oEnd1.Name.empty())
    {
        return false;
    }
	if (oEnd2.TypeName == L"")
	{
		_ASSERT(false);
	}
    oAssociation.OwnerTypeName = oEnd2.TypeName;
    oAssociation.FieldName = oEnd1.Name;
    oAssociation.TypeName = oEnd1.TypeName;
    if (oEnd1.Multiplicity.empty() || oEnd1.Multiplicity == L"0..1" || oEnd1.Multiplicity == L"1")
        oAssociation.IsMultiplicity = false;
    else
        oAssociation.IsMultiplicity = true;
    return true;
}

CAssociationEnd CUMLReader::getAssociationEnd(TiXmlElement * pAssociationEnd)
{
    CAssociationEnd oResult;
    TiXmlElement* pChild = pAssociationEnd->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:ATTR")
        {
            //
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Name")
                {
                    oResult.Name = Utf8ToUnicode(pChild->GetText());
                }
                else if (sNameValue == "Multiplicity")
                {
                    oResult.Multiplicity = Utf8ToUnicode(pChild->GetText());
                }
            }
        }
        else if (pChild->ValueStr() == "XPD:REF")
        {
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Participant")
                {
                    oResult.TypeName = Utf8ToUnicode(pChild->GetText());
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
    return oResult;
}

CTypeObject *CUMLReader::findTypeObjectByGUID(const std::wstring &sGUID)
{
    CGuidTypeObjectMap::iterator itr = m_oTypeObjectMap.find(sGUID);
    if (itr != m_oTypeObjectMap.end())
    {
        return itr->second;
    }
    else
    {
        return NULL;
    }
}

CAttribute * CUMLReader::getAttribute(TiXmlElement * pAttribute)
{
    std::wstring sAttributeName;
    bool bOptional = false;
    bool bRepeated = false;
    std::wstring sAttributeType;
    std::wstring sAttributeDocument;
    TiXmlElement* pChild = pAttribute->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:ATTR")
        {
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Name")
                {
                    sAttributeName = Utf8ToUnicode(pChild->GetText());
                }
                else if (sNameValue == "StereotypeName")
                {
                    std::wstring sTemp = Utf8ToUnicode(pChild->GetText());
                    bOptional = sTemp.compare(L"OPTIONAL") == 0;
                    bRepeated = sTemp.compare(L"REPEATED") == 0;
                }
                else if (sNameValue == "TypeExpression")
                {
                    sAttributeType = Utf8ToUnicode(pChild->GetText());
                }
                else if (sNameValue == "Documentation")
                {
                    sAttributeDocument = Utf8ToUnicode(pChild->GetText());
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
    return createAttribute(sAttributeName, sAttributeType, sAttributeDocument, bOptional, bRepeated);
}

std::wstring CUMLReader::getAttributeName(TiXmlElement * pAttribute)
{
    std::wstring sAttributeName;
    TiXmlElement* pChild = pAttribute->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:ATTR")
        {
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Name")
                {
                    sAttributeName = Utf8ToUnicode(pChild->GetText());
                    break;
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
    return sAttributeName;
}

std::wstring CUMLReader::getAttributeDocument(TiXmlElement * pAttribute)
{
    std::wstring sAttributeDocument;
    TiXmlElement* pChild = pAttribute->FirstChildElement();
    while (pChild)
    {
        if (pChild->ValueStr() == "XPD:ATTR")
        {
            std::string sNameValue;
            if (pChild->QueryStringAttribute("name", &sNameValue) == TIXML_SUCCESS)
            {
                if (sNameValue == "Documentation")
                {
                    sAttributeDocument = Utf8ToUnicode(pChild->GetText());
                    break;
                }
            }
        }
        pChild = pChild->NextSiblingElement();
    }
    return sAttributeDocument;
}

CAttribute *CUMLReader::createAttribute(const std::wstring &sAttributeName, const std::wstring &sAttributeType, const std::wstring& sAttributeDocument, bool bOptional, bool bRepeated)
{
    CAttribute* pAttribute = new CAttribute();
    pAttribute->SetName(sAttributeName);
    pAttribute->SetOptionalFlag(bOptional);
    pAttribute->SetRepeatFlag(bRepeated);
    pAttribute->setDocument(sAttributeDocument);
    CTypeObject* pTypeObject = m_pModel->findTypeObject(sAttributeType);
    if (pTypeObject)
    {
        pAttribute->SetType(pTypeObject);
    }
    else
    {
        // 延迟处理
        m_oAttributeList.push_back(std::make_pair(pAttribute, sAttributeType));
    }
    return pAttribute;
}
