#ifndef NGFC2ABNORMITYLINEARCHINFO_H
#define NGFC2ABNORMITYLINEARCHINFO_H

#include "NGfc2BaseLineArcInfo.h"
#include "Gfc2AbnormityLineArchInfo.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2AbnormityLineArchInfo: public NGfc2BaseLineArcInfo
{
public:
    NGfc2AbnormityLineArchInfo();
    NGfc2AbnormityLineArchInfo(void* pEntity, bool bOwner);
    void setTopArchStartT(NGfc2Double dValue);
    NGfc2Double getTopArchStartT();
    bool hasTopArchStartT();
    void setTopArchEndT(NGfc2Double dValue);
    NGfc2Double getTopArchEndT();
    bool hasTopArchEndT();
    void setTopDefineByRadius(NGfc2Boolean bValue);
    NGfc2Boolean getTopDefineByRadius();
    bool hasTopDefineByRadius();
    void setTopArchHeight(NGfc2Double dValue);
    NGfc2Double getTopArchHeight();
    bool hasTopArchHeight();
    void setTopArchRadius(NGfc2Double dValue);
    NGfc2Double getTopArchRadius();
    bool hasTopArchRadius();
    void setDownArchStartT(NGfc2Double dValue);
    NGfc2Double getDownArchStartT();
    bool hasDownArchStartT();
    void setDownArchEndT(NGfc2Double dValue);
    NGfc2Double getDownArchEndT();
    bool hasDownArchEndT();
    void setDownDefineByRadius(NGfc2Boolean bValue);
    NGfc2Boolean getDownDefineByRadius();
    bool hasDownDefineByRadius();
    void setDownArchHeight(NGfc2Double dValue);
    NGfc2Double getDownArchHeight();
    bool hasDownArchHeight();
    void setDownArchRadius(NGfc2Double dValue);
    NGfc2Double getDownArchRadius();
    bool hasDownArchRadius();

};
#endif
