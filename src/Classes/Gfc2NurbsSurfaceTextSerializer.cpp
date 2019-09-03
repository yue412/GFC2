#include "StdAfx.h"
#include "Gfc2NurbsSurfaceTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2NurbsSurface.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsSurfaceTextSerializer,"Gfc2NurbsSurfaceT",0)

std::string Gfc2NurbsSurfaceTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsSurface* pEnt = (Gfc2NurbsSurface*)pEntity;
    std::string sResult = Gfc2SurfaceTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasDegreeU())
        stream<<","<<pEnt->getDegreeU();
    else
        stream<<",$";

    if (pEnt->hasDegreeV())
        stream<<","<<pEnt->getDegreeV();
    else
        stream<<",$";

    if (pEnt->hasCtrlPtCountU())
        stream<<","<<pEnt->getCtrlPtCountU();
    else
        stream<<",$";

    if (pEnt->hasCtrlPtCountV())
        stream<<","<<pEnt->getCtrlPtCountV();
    else
        stream<<",$";

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getCtrlPtsCount(); i++)
        {
            if(0==i)
                stream<<"#"<<pEnt->getCtrlPts(i);
            else
                stream<<",#"<<pEnt->getCtrlPts(i);
        }
        stream<<")";
    }

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getKnotsUCount(); i++)
        {
            if(0==i)
                stream<<""<<pEnt->getKnotsU(i);
            else
                stream<<","<<pEnt->getKnotsU(i);
        }
        stream<<")";
    }

    {
        stream<<",(";
        for (int i = 0; i < pEnt->getKnotsVCount(); i++)
        {
            if(0==i)
                stream<<""<<pEnt->getKnotsV(i);
            else
                stream<<","<<pEnt->getKnotsV(i);
        }
        stream<<")";
    }

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2NurbsSurfaceTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2NurbsSurface* pEnt = (Gfc2NurbsSurface*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setDegreeU(value);
        }
        break;
    case 1:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setDegreeV(value);
        }
        break;
    case 2:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setCtrlPtCountU(value);
        }
        break;
    case 3:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setCtrlPtCountV(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->addCtrlPts(value);
        }
        break;
    case 5:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->addKnotsU(value);
        }
        break;
    case 6:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->addKnotsV(value);
        }
        break;
    default:
        return glodon::objectbuf::PFS_IGNORE;
    }
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

