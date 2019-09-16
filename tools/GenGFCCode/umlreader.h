#ifndef UMLREADER_H
#define UMLREADER_H

#include <list>
#include <map>
#include <string>

class CModel;
class CAttribute;
class CTypeDef;
class CTypeObject;

struct CAssociation
{
    std::wstring OwnerTypeName;
	std::wstring FieldName;
	std::wstring TypeName;
    std::wstring Document;
    bool IsMultiplicity;
    bool IsOptional;
    CAssociation(): IsMultiplicity(false), IsOptional(false) {}
};

struct CAssociationEnd
{
    std::wstring Name;
	std::wstring TypeName;
	std::wstring Multiplicity;
};

class TiXmlElement;

class CUMLReader
{
public:
    CUMLReader(CModel* pModel);
    void load(const std::wstring& sFileName);
private:
    void initial();
    void finalize();
    void loadBody(TiXmlElement* pBody);
    void loadModel(TiXmlElement* pModel);
    void loadClass(TiXmlElement* pClass);
    void doneGeneralization(TiXmlElement* pGeneralization);
    void doneAssociation(TiXmlElement* pAssociation);
    bool initAssociation(CAssociationEnd& oEnd1, CAssociationEnd& oEnd2, CAssociation& oAssociation);
    CTypeObject* createClass(TiXmlElement* pClass);
    CAssociationEnd getAssociationEnd(TiXmlElement* pAssociationEnd);
    CTypeObject* findTypeObjectByGUID(const std::wstring& sGUID);
    CAttribute* getAttribute(TiXmlElement* pAttribute);
    std::wstring getAttributeName(TiXmlElement* pAttribute);
    std::wstring getAttributeDocument(TiXmlElement* pAttribute);
    CAttribute* createAttribute(const std::wstring& sAttributeName, const std::wstring& sAttributeType, const std::wstring& sAttributeDocument,
                                bool bOptional, bool bRepeated);
private:
    CModel* m_pModel;
    typedef std::list<std::pair<CAttribute*, std::wstring>> CAttributeList;
    CAttributeList m_oAttributeList;
    typedef std::list<std::pair<CTypeDef*, std::wstring>> CTypeDefList;
    CTypeDefList m_oTypedefList;
    typedef std::map<std::wstring, CTypeObject*> CGuidTypeObjectMap;
    CGuidTypeObjectMap m_oTypeObjectMap;
    typedef std::list<std::pair<std::wstring, std::wstring>> CGeneralizationList;
    CGeneralizationList m_oGeneralizationList;
    typedef std::list<CAssociation> CAssociationList;
    CAssociationList m_oAssociationList;
};

#endif // UMLREADER_H
