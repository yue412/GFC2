#include <QXmlStreamReader>
#include <QFile>
#include <iostream>
#include "umlreader.h"
#include "class.h"
#include "type.h"
#include "enumtype.h"
#include "model.h"
#include "attribute.h"

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

    QFile oFile(QString::fromStdWString(sFileName));
    if (!oFile.open(QFile::ReadOnly | QFile::Text))
    {
        std::wcout << L"文件打开失败!" << std::endl;
        return;
    }
    // 预处理
    initial();
    QXmlStreamReader reader(&oFile);
    while (!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();
        //QStringRef sTemp = reader.name();
        if (nTokenType == QXmlStreamReader::StartElement && reader.name().compare("BODY", Qt::CaseInsensitive) == 0)
        {
            //nTokenType = reader.readNextStartElement();
            if (reader.readNextStartElement() && reader.name() == "OBJ")
            {
                loadBody(reader);
            }
            else
            {
                _ASSERT(false);
            }
        }
    }
    oFile.close();
    // 后处理
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
            std::wcout << L"Attribute " << itr->first->getName() << L" miss type: " << sName;
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

void CUMLReader::loadBody(QXmlStreamReader &reader)
{
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();

        if (nTokenType == QXmlStreamReader::EndElement && reader.name() == "OBJ")
        {
            return;
        }

        if (nTokenType == QXmlStreamReader::StartElement && reader.name() == "OBJ")
        {
            QStringRef oAttributeValue = reader.attributes().value("type");
            if (!oAttributeValue.isNull() && oAttributeValue == "UMLModel")
            {
                loadModel(reader);
            }
            else
            {
                _ASSERT(false);
            }
        }
    }
}

void CUMLReader::loadModel(QXmlStreamReader &reader)
{
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();

        // 匹配外面的XPD:OBJ
        if (nTokenType == QXmlStreamReader::EndElement && reader.name() == "OBJ")
        {
            return;
        }

        if (nTokenType == QXmlStreamReader::StartElement && reader.name() == "OBJ")
        {
            QStringRef oAttributeValue = reader.attributes().value("type");
            if (!oAttributeValue.isNull())
            {
                if (oAttributeValue == "UMLClass")
                {
                    loadClass(reader);
                }
                else if (oAttributeValue == "UMLGeneralization")
                {
                    doneGeneralization(reader);
                }
                else if (oAttributeValue == "UMLAssociation")
                {
                    doneAssociation(reader);
                }
                else
                {
                    reader.skipCurrentElement();
                }
            }
            else
            {
                _ASSERT(false);
            }
        }
    }
}

void CUMLReader::loadClass(QXmlStreamReader &reader)
{
    std::wstring sClassName;
    bool bIsAbstract = false;
    CTypeObject* pTypeObject = NULL;
    QStringRef sGuidValue = reader.attributes().value("guid");
    _ASSERT(!sGuidValue.isNull());
    std::wstring sGuid = sGuidValue.toString().toStdWString();
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();

        // 匹配外面的XPD:OBJ
        if (nTokenType == QXmlStreamReader::EndElement && reader.name() == "OBJ")
        {
            if (pTypeObject == NULL && !sClassName.empty())
            {
                pTypeObject = new CClass();
                pTypeObject->SetName(sClassName);
                ((CClass*)pTypeObject)->setIsAbstract(bIsAbstract);
                m_pModel->addTypeObject(pTypeObject);
                m_oTypeObjectMap.insert(std::make_pair(sGuid, pTypeObject));
            }
            return;
        }

        if (nTokenType == QXmlStreamReader::StartElement && reader.name() == "ATTR")
        {
            QStringRef oAttributeValue = reader.attributes().value("name");
            if (!oAttributeValue.isNull())
            {
                if (oAttributeValue == "Name")
                {
                    sClassName = reader.readElementText().toStdWString();
					auto pTypeObject = m_pModel->findTypeObject(sClassName);
					if (pTypeObject)
					{
						reader.skipCurrentElement();
						reader.skipCurrentElement();
						m_oTypeObjectMap.insert(std::make_pair(sGuid, pTypeObject));
						break;//返回
					}
                }
                else if (oAttributeValue == "StereotypeName")
                {
                    std::wstring sText = reader.readElementText().toStdWString();
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
                    pTypeObject->SetName(sClassName);
                    m_pModel->addTypeObject(pTypeObject);
                    m_oTypeObjectMap.insert(std::make_pair(sGuid, pTypeObject));
                }
                else if (oAttributeValue == "IsAbstract")
                {
                    std::wstring sTemp = reader.readElementText().toStdWString();
                    bIsAbstract = sTemp == L"True";
                }
                else
                {
                    reader.skipCurrentElement();
                }
            }
            else
            {
                _ASSERT(false);
            }
        }
        else if (nTokenType == QXmlStreamReader::StartElement && reader.name() == "OBJ")
        {
            QStringRef oAttributeValue = reader.attributes().value("type");
            if (!oAttributeValue.isNull())
            {
                if (oAttributeValue == "UMLAttribute")
                {
                    if (pTypeObject == NULL)
                    {
                        _ASSERT(!sClassName.empty());
                        pTypeObject = new CClass();
                        pTypeObject->SetName(sClassName);
                        ((CClass*)pTypeObject)->setIsAbstract(bIsAbstract);
                        m_pModel->addTypeObject(pTypeObject);
                        m_oTypeObjectMap.insert(std::make_pair(sGuid, pTypeObject));
                    }
                    CClass* pClass = dynamic_cast<CClass*>(pTypeObject);
                    if (pClass)
                    {
                        pClass->addAttribute(getAttribute(reader));
                    }
                    else
                    {
                        CTypeDef* pTypeDef = dynamic_cast<CTypeDef*>(pTypeObject);
                        if (pTypeDef)
                        {
                            std::wstring sTypeName = getAttributeName(reader);
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
                                pEnumType->addEnum(getAttributeName(reader));
                            }
                        }
                    }
                }
                else
                {
                    reader.skipCurrentElement();
                }
            }
            else
            {
                _ASSERT(false);
            }
        }
    }
}

void CUMLReader::doneGeneralization(QXmlStreamReader &reader)
{
    std::wstring sChildGUID;
    std::wstring sParentGUID;
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();

        // 匹配外面的XPD:OBJ
        if (nTokenType == QXmlStreamReader::EndElement && reader.name() == "OBJ")
        {
            if (!sChildGUID.empty() && !sParentGUID.empty())
            {
                m_oGeneralizationList.push_back(std::make_pair(sChildGUID, sParentGUID));
                /*
                // 添加父子关系
                CTypeObject* pChild = findTypeObjectByGUID(sChildGUID);
                CTypeObject* pParent = findTypeObjectByGUID(sChildGUID);
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
                */
            }
            else
            {
                _ASSERT(false);
            }
            return;
        }

        if (nTokenType == QXmlStreamReader::StartElement)
        {
            if (reader.name() == "REF")
            {
                //
                QStringRef oAttributeValue = reader.attributes().value("name");
                if (!oAttributeValue.isNull())
                {
                    if (oAttributeValue == "Child")
                    {
                        sChildGUID = reader.readElementText().toStdWString();
                    }
                    else if (oAttributeValue == "Parent")
                    {
                        sParentGUID = reader.readElementText().toStdWString();
                    }
                    else
                    {
                        reader.skipCurrentElement();
                    }
                }
                else
                {
                    _ASSERT(false);
                }
            }
            else
            {
                reader.skipCurrentElement();
            }
        }
    }
    _ASSERT(false);
}

void CUMLReader::doneAssociation(QXmlStreamReader &reader)
{
    CAssociationEnd oAssociationEndArray[2];
    int nIndex = 0;
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();
		std::wstring sName = reader.name().toString().toStdWString();

        // 匹配外面的XPD:OBJ
        if (nTokenType == QXmlStreamReader::EndElement && sName == L"OBJ")
        {
            /*
            if (!sChildGUID.isEmpty() && !sParentGUID.isEmpty())
            {
                m_oGeneralizationList.push_back(std::make_pair(sChildGUID, sParentGUID));
            }
            else
            {
                _ASSERT(false);
            }
            */
            CAssociation oAssociation;
            if (initAssociation(oAssociationEndArray[0], oAssociationEndArray[1], oAssociation))
            {
                m_oAssociationList.push_back(oAssociation);
            }
            if (initAssociation(oAssociationEndArray[1], oAssociationEndArray[0], oAssociation))
            {
                m_oAssociationList.push_back(oAssociation);
            }
            return;
        }

        if (nTokenType == QXmlStreamReader::StartElement)
        {
            if (sName == L"OBJ")
            {
                //
                QStringRef oAttributeValue = reader.attributes().value("type");
                if (!oAttributeValue.isNull())
                {
                    if (oAttributeValue == "UMLAssociationEnd" && nIndex < 2)
                    {
                        oAssociationEndArray[nIndex] = getAssociationEnd(reader);
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
                    else
                    {
                        reader.skipCurrentElement();
                    }
                }
                else
                {
                    _ASSERT(false);
                }
            }
            else
            {
                reader.skipCurrentElement();
            }
        }
    }
    _ASSERT(false);
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

CAssociationEnd CUMLReader::getAssociationEnd(QXmlStreamReader &reader)
{
    CAssociationEnd oResult;
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();

        // 匹配外面的XPD:OBJ
        if (nTokenType == QXmlStreamReader::EndElement && reader.name() == "OBJ")
        {
            return oResult;
        }

        if (nTokenType == QXmlStreamReader::StartElement)
        {
            if (reader.name() == "ATTR")
            {
                //
                QStringRef oAttributeValue = reader.attributes().value("name");
                if (!oAttributeValue.isNull())
                {
                    if (oAttributeValue == "Name")
                    {
                        oResult.Name = reader.readElementText().toStdWString();
                    }
                    else if (oAttributeValue == "Multiplicity")
                    {
                        oResult.Multiplicity = reader.readElementText().toStdWString();
                    }
                    else
                    {
                        reader.skipCurrentElement();
                    }
                }
                else
                {
                    _ASSERT(false);
                }
            }
            else if (reader.name() == "REF")
            {
                QStringRef oAttributeValue = reader.attributes().value("name");
                if (!oAttributeValue.isNull())
                {
                    if (oAttributeValue == "Participant")
                    {
                        oResult.TypeName = reader.readElementText().toStdWString();
                    }
                    else
                    {
                        reader.skipCurrentElement();
                    }
                }
                else
                {
                    _ASSERT(false);
                }
            }
            else
            {
                reader.skipCurrentElement();
            }
        }
    }
    _ASSERT(false);
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

CAttribute *CUMLReader::getAttribute(QXmlStreamReader &reader)
{
    std::wstring sAttributeName;
    bool bOptional = false;
    bool bRepeated = false;
    std::wstring sAttributeType;
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();

        // 匹配外面的XPD:OBJ
        if (nTokenType == QXmlStreamReader::EndElement && reader.name() == "OBJ")
        {
            return createAttribute(sAttributeName, sAttributeType, bOptional, bRepeated);
        }

        if (nTokenType == QXmlStreamReader::StartElement)
        {
            if (reader.name() == "ATTR")
            {
                QStringRef oAttributeValue = reader.attributes().value("name");
                if (!oAttributeValue.isNull())
                {
                    if (oAttributeValue == "Name")
                    {
                        sAttributeName = reader.readElementText().toStdWString();
                    }
                    else if (oAttributeValue == "StereotypeName")
                    {
                        std::wstring sTemp = reader.readElementText().toStdWString();
                        bOptional = sTemp.compare(L"OPTIONAL") == 0;
                        bRepeated = sTemp.compare(L"REPEATED") == 0;
                    }
                    else if (oAttributeValue == "TypeExpression")
                    {
                        sAttributeType = reader.readElementText().toStdWString();
                    }
                    else
                    {
                        reader.skipCurrentElement(); // 其他跳过
                    }
                }
                else
                {
                    _ASSERT(false);
                }
            }
            else
            {
                reader.skipCurrentElement(); // 其他跳过
            }
        }
    }
    return createAttribute(sAttributeName, sAttributeType, bOptional, bRepeated);

}

std::wstring CUMLReader::getAttributeName(QXmlStreamReader &reader)
{
    std::wstring sAttributeName;
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType nTokenType = reader.readNext();

        // 匹配外面的XPD:OBJ
        if (nTokenType == QXmlStreamReader::EndElement && reader.name() == "OBJ")
        {
            return sAttributeName;
        }

        if (nTokenType == QXmlStreamReader::StartElement)
        {
            if (reader.name() == "ATTR")
            {
                QStringRef oAttributeValue = reader.attributes().value("name");
                if (!oAttributeValue.isNull())
                {
                    if (oAttributeValue == "Name")
                    {
                        sAttributeName = reader.readElementText().toStdWString();
                    }
                    else
                    {
                        reader.skipCurrentElement(); // 其他跳过
                    }
                }
                else
                {
                    _ASSERT(false);
                }
            }
            else
            {
                reader.skipCurrentElement(); // 其他跳过
            }
        }
    }
    return sAttributeName;
}

CAttribute *CUMLReader::createAttribute(const std::wstring &sAttributeName, const std::wstring &sAttributeType, bool bOptional, bool bRepeated)
{
    CAttribute* pAttribute = new CAttribute();
    pAttribute->SetName(sAttributeName);
    pAttribute->SetOptionalFlag(bOptional);
    pAttribute->SetRepeatFlag(bRepeated);
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
