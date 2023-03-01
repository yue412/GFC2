#include "GfcUtils/GfcGeometryImporter.h"
#include "Geometry/Surface.h"
//#include "TypeConsts.h"
#include "Algorithm/algpolygon.h"
#include "Algorithm\algPolygonFix.h"
#include "GfcEngine\Entity.h"

using namespace ggp;

ggp::CVector2d GfcGeometryImporter::importVector2d(gfc::engine::CEntity* pSrc )
{
    ggp::CVector2d oResult;
    if (pSrc)
    {
        oResult.X = pSrc->asDouble(L"X");
        oResult.Y = pSrc->asDouble(L"Y");
    }
    return oResult;
}

ggp::CVector3d GfcGeometryImporter::importVector3d(gfc::engine::CEntity* pSrc )
{
    ggp::CVector3d oResult;
    if (pSrc)
    {
        oResult.X = pSrc->asDouble(L"X");
        oResult.Y = pSrc->asDouble(L"Y");
        oResult.Z = pSrc->asDouble(L"Z");
    }
    return oResult;
}

ggp::CIntervald GfcGeometryImporter::importIntervald(gfc::engine::CEntity* pSrc )
{
    ggp::CIntervald oResult;
    if (pSrc)
    {
        oResult.SetMin(pSrc->asDouble(L"Min"));
        oResult.SetMax(pSrc->asDouble(L"Max"));
    }
    return oResult;
}

ggp::CCoordinates3d GfcGeometryImporter::importCoordinates3d(gfc::engine::CEntity* pSrc )
{
    ggp::CCoordinates3d oResult;
    if (pSrc)
    {
        oResult.Origin = importVector3d(pSrc->asEntity(L"Origin").get());
        oResult.X = importVector3d(pSrc->asEntity(L"X").get());
        oResult.Y = importVector3d(pSrc->asEntity(L"Y").get());
        oResult.Z = importVector3d(pSrc->asEntity(L"Z").get());
    }
    return oResult;
}

ggp::CCoordinates2d GfcGeometryImporter::importCoordinates2d(gfc::engine::CEntity* pSrc )
{
    ggp::CCoordinates2d oResult;
    if (pSrc)
    {
        oResult.Origin = importVector2d(pSrc->asEntity(L"Origin").get());
        oResult.X = importVector2d(pSrc->asEntity(L"X").get());
        oResult.Y = importVector2d(pSrc->asEntity(L"Y").get());
    }
    return oResult;
}

ggp::CBox3d GfcGeometryImporter::importBox3d(gfc::engine::CEntity* pSrc )
{
    ggp::CBox3d oResult;
    if (pSrc)
    {
        oResult.Set(importVector3d(pSrc->asEntity(L"Min").get()), importVector3d(pSrc->asEntity(L"Max").get()));
    }
    return oResult;
}

ggp::CLine2d* GfcGeometryImporter::importLine2d(gfc::engine::CEntity* pSrc )
{
    ggp::CLine2d* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CLine2d(importVector2d(pSrc->asEntity(L"StartPt").get()), 
            importVector2d(pSrc->asEntity(L"EndPt").get()));
    }
    return pResult;
}

ggp::CArc2d* GfcGeometryImporter::importArc2d(gfc::engine::CEntity* pSrc )
{
    ggp::CArc2d* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CArc2d(importVector2d(pSrc->asEntity(L"CenterPt").get()), 
            pSrc->asDouble(L"Radius"),
            importIntervald(pSrc->asEntity(L"Range").get()),
            pSrc->asInteger(L"ClockSign"));
    }
    return pResult;
}

ggp::CEllipse2d* GfcGeometryImporter::importEllipse2d(gfc::engine::CEntity* pSrc )
{
    ggp::CEllipse2d* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CEllipse2d(importVector2d(pSrc->asEntity(L"CenterPt").get()), 
            importVector2d(pSrc->asEntity(L"MajorAxis").get()), 
            pSrc->asDouble(L"dMajorRad"),
            pSrc->asDouble(L"dMinorRad"),
            importIntervald(pSrc->asEntity(L"Range").get()),
            pSrc->asInteger(L"ClockSign"));
    }
    return pResult;
}

ggp::CNurbsCurve2d* GfcGeometryImporter::importNurbsCurve2d(gfc::engine::CEntity* pSrc )
{
    ggp::CNurbsCurve2d* pResult = NULL;
    if (pSrc)
    {
        int nCount = pSrc->getArrayCount(L"CtrlPts");
        pResult = new ggp::CNurbsCurve2d(pSrc->asInteger(L"Degree"), nCount);
        pResult->SetCtrlPtCount(nCount);
        for (int i = 0; i < nCount; ++i)
        {
            pResult->SetCtrlPt(i, importNurbsCtrlPt2d(pSrc->getEntity(L"CtrlPts", i).get()));
        }
        int nKnotsCount = pSrc->getArrayCount(L"Knots");
        for (int i = 0; i < nKnotsCount; ++i)
        {
            pResult->SetKnot(i, pSrc->getDouble(L"Knots", i));
        }
		pResult->ReParameterize();
    }
    return pResult;
}

ggp::CNurbsCurve2d* GfcGeometryImporter::importHermiteCurve2d(gfc::engine::CEntity* pSrc)
{
	if(pSrc)
	{
		 int nCount = pSrc->getArrayCount(L"CtrlPts");
		 if (nCount < 1)
		 {
			 return NULL;
		 }
		 CVector2d pt[1000];
		 CVector2d tangent[1000];
		 double parameter[1000];
		 for(int i = 0; i < nCount; ++i)
		 {
			 auto pCtrlPt = pSrc->getEntity(L"CtrlPts", i);
			 pt[i] = importVector2d(pCtrlPt->asEntity(L"Point").get());
			 tangent[i] = importVector2d(pCtrlPt->asEntity(L"Tangent").get());
			 parameter[i] = pCtrlPt->asDouble(L"Parameter");
		 }
		 CNurbsCurve2d *pResult = new ggp::CNurbsCurve2d(nCount, &pt[0],&tangent[0],&parameter[0]);
		 pResult->ReParameterize();
		 return pResult;
	}
	return NULL;
}

ggp::CPreimageCurve2d* GfcGeometryImporter::importPreimageCurve2d(gfc::engine::CEntity* pSrc )
{
    ggp::CPreimageCurve2d* pResult = NULL;
    if (pSrc)
    {
        ggp::CSurface* pSurface = importSurface(pSrc->asEntity(L"Base").get());
        ggp::CCurve3d* pCurve = importCurve3d(pSrc->asEntity(L"Curve").get());
        if (pSurface && pCurve)
        {
            pResult = new ggp::CPreimageCurve2d(ggp::CSurfacePtr(pSurface), ggp::CCurve3dPtr(pCurve), pSrc->asDouble(L"Tolerance"));
			//不需要设置Range，构造函数会设置Range，而且如果走下面的反向方法，会把Range反向，解决JLBIM-88
			//同时解决BIMGFC-701、BIMGFC-1343、BIMGFC-1501的异形体丢失问题 dongc-b	2018.1.29
			//pResult->SetRange(importIntervald(pSrc->asEntity(L"Range").get()));
			if (pSrc->asBoolean(L"Reversed") ^ pResult->Reversed())
			{
				pResult->Reverse();
			}
        }
        else
        {
            if (pSurface)
                pSurface->Free();
            if (pCurve)
                pCurve->Free();
        }
    }
    return pResult;
}

ggp::CSinCurve2d* GfcGeometryImporter::importSinCurve2d(gfc::engine::CEntity* pSrc )
{
    ggp::CSinCurve2d* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CSinCurve2d(importVector2d(pSrc->asEntity(L"Pos").get()), 
            importVector2d(pSrc->asEntity(L"DirX").get()),
            pSrc->asDouble(L"A"),
            pSrc->asDouble(L"B"),
            importIntervald(pSrc->asEntity(L"Range").get()),
            pSrc->asInteger(L"ClockSign"));
    }
    return pResult;
}

ggp::CSpiralLine2d* GfcGeometryImporter::importSpiralLine2d(gfc::engine::CEntity* pSrc )
{
    ggp::CSpiralLine2d* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CSpiralLine2d(importCoordinates2d(pSrc->asEntity(L"Coord").get()),
            pSrc->asDouble(L"Radius"),
            importIntervald(pSrc->asEntity(L"Range").get()),
            pSrc->asInteger(L"ClockSign"),
            pSrc->asDouble(L"RadiusCoef"));
    }
    return pResult;
}

ggp::COffsetCurve2d* GfcGeometryImporter::importOffsetCurve2d(gfc::engine::CEntity* pSrc )
{
    ggp::COffsetCurve2d* pResult = NULL;
    if (pSrc)
    {
        ggp::CCurve2d* pCurve = importCurve2d(pSrc->asEntity(L"InitCurve").get());
        if (pCurve)
            pResult = new ggp::COffsetCurve2d(pCurve, pSrc->asDouble(L"OffDist"));
    }
    return pResult;
}

ggp::CCurve2d* GfcGeometryImporter::importCurve2d(gfc::engine::CEntity* pSrc )
{
    if(pSrc->entityName().find(L"Line2d") != std::wstring::npos)
        return importLine2d(pSrc);
    else if (pSrc->entityName().find(L"Arc2d") != std::wstring::npos)
        return importArc2d(pSrc);
    else if (pSrc->entityName().find(L"NurbsCurve2d") != std::wstring::npos)
        return importNurbsCurve2d(pSrc);
    else if (pSrc->entityName().find(L"Ellipse2d") != std::wstring::npos)
        return importEllipse2d(pSrc);
    else if (pSrc->entityName().find(L"SinCurve2d") != std::wstring::npos)
        return importSinCurve2d(pSrc);
    else if (pSrc->entityName().find(L"SpiralLine2d") != std::wstring::npos)
        return importSpiralLine2d(pSrc);
    else if (pSrc->entityName().find(L"PreimageCurve2d") != std::wstring::npos)
        return importPreimageCurve2d(pSrc);
    else if (pSrc->entityName().find(L"OffsetCurve2d") != std::wstring::npos)
        return importOffsetCurve2d(pSrc);
    else if (pSrc->entityName().find(L"HermiteCurve2d") != std::wstring::npos)
		return importHermiteCurve2d(pSrc);
    else
    {
        assert(false);
        return NULL;
    }
}

ggp::CLine3d* GfcGeometryImporter::importLine3d(gfc::engine::CEntity* pSrc )
{
    ggp::CLine3d* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CLine3d(importVector3d(pSrc->asEntity(L"StartPt").get()), 
            importVector3d(pSrc->asEntity(L"EndPt").get()));
    }
    return pResult;
}

ggp::CArc3d* GfcGeometryImporter::importArc3d(gfc::engine::CEntity* pSrc)
{
    ggp::CArc3d* pResult = NULL;
    if (pSrc)
    {
        auto pPlaneInfo = pSrc->asEntity(L"Plane");
        if (pPlaneInfo)
        {
            auto pCurve = importCurve2d(pSrc->asEntity(L"PlaneCurve").get());
            if (pCurve)
            {
                if (pCurve->Type() == ggp::Arc2dType)
                {
                    auto pArc2d = (ggp::CArc2d*)pCurve;
                    pResult = new ggp::CArc3d(importVector3d(pPlaneInfo->asEntity(L"Pos").get()),
                        importVector3d(pPlaneInfo->asEntity(L"DirX").get()),
                        importVector3d(pPlaneInfo->asEntity(L"DirY").get()),
                        pArc2d);
                }
                pCurve->Free();
            }
        }
    }
    return pResult;
}

ggp::CEllipse3d* GfcGeometryImporter::importEllipse3d(gfc::engine::CEntity* pSrc)
{
    ggp::CEllipse3d* pResult = NULL;
    if (pSrc)
    {
        auto pPlaneInfo = pSrc->asEntity(L"Plane");
        if (pPlaneInfo)
        {
            auto pCurve = importCurve2d(pSrc->asEntity(L"PlaneCurve").get());
            if (pCurve)
            {
                if (pCurve->Type() == ggp::Ellipse2dType)
                {
                    auto pEllipse2d = (ggp::CEllipse2d*)pCurve;
                    pResult = new ggp::CEllipse3d(importVector3d(pPlaneInfo->asEntity(L"Pos").get()),
                        importVector3d(pPlaneInfo->asEntity(L"DirX").get()),
                        importVector3d(pPlaneInfo->asEntity(L"DirY").get()),
                        pEllipse2d);
                }
                pCurve->Free();
            }
        }
    }
    return pResult;
}

ggp::CPlaneCurve3d* GfcGeometryImporter::importPlaneCurve3d(gfc::engine::CEntity* pSrc )
{
	ggp::CPlaneCurve3d* pResult = NULL;
	if (pSrc)
	{
		auto pPlaneInfo = pSrc->asEntity(L"Plane");
		if (pPlaneInfo)
		{
			ggp::CCurve2d* pCurve = importCurve2d(pSrc->asEntity(L"PlaneCurve").get());
			if (pCurve)
			{
				pResult = new ggp::CPlaneCurve3d(importVector3d(pPlaneInfo->asEntity(L"Pos").get()), 
					importVector3d(pPlaneInfo->asEntity(L"DirX").get()), 
					importVector3d(pPlaneInfo->asEntity(L"DirY").get()), 
					pCurve);
				pCurve->Free();
			}
		}
	}
	return pResult;
}

ggp::CNurbsCurve3d* GfcGeometryImporter::importNurbsCurve3d(gfc::engine::CEntity* pSrc )
{
    ggp::CNurbsCurve3d* pResult = NULL;
    if (pSrc)
    {
        int nCount = pSrc->getArrayCount(L"CtrlPts");
        pResult = new ggp::CNurbsCurve3d(pSrc->asInteger(L"Degree"), nCount);
        pResult->SetCtrlPtCount(nCount);
        for (int i = 0; i < nCount; ++i)
        {
            pResult->SetCtrlPt(i, importNurbsCtrlPt3d(pSrc->getEntity(L"CtrlPts", i).get()));
        }
        int nKnotsCount = pSrc->getArrayCount(L"Knots");
        for (int i = 0; i < nKnotsCount; ++i)
        {
            pResult->SetKnot(i, pSrc->getDouble(L"Knots", i));
        }
		pResult->ReParameterize();
    }
    return pResult;
}

ggp::CIntersectionCurve3d* GfcGeometryImporter::importIntersectionCurve3d(gfc::engine::CEntity* pSrc )
{
    ggp::CIntersectionCurve3d* pResult = NULL;
    if (pSrc)
    {
        ggp::CSurface* pBase1 = importSurface(pSrc->asEntity(L"Bases1").get());
        ggp::CSurface* pBase2 = importSurface(pSrc->asEntity(L"Bases2").get());
        if (pBase1 && pBase2)
        {
            pResult = new ggp::CIntersectionCurve3d(ggp::CSurfacePtr(pBase1),
                ggp::CSurfacePtr(pBase2),
                importInternalChart(pSrc->asEntity(L"Chart").get())
                );
            const_cast<ggp::CIntervald&>(pResult->Range()) = importIntervald(pSrc->asEntity(L"Range").get());
        }
        else
        {
            if (pBase1)
                pBase1->Free();
            if (pBase2)
                pBase2->Free();
        }
    }
    return pResult;
}

ggp::CSpiralLine* GfcGeometryImporter::importSpiralLine3d(gfc::engine::CEntity* pSrc )
{
    ggp::CSpiralLine* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CSpiralLine(importCoordinates3d(pSrc->asEntity(L"Coord").get()),
            pSrc->asDouble(L"Radius"),
            importIntervald(pSrc->asEntity(L"Range").get()),
            pSrc->asInteger(L"ClockSign"),
            pSrc->asDouble(L"HeightCoef"),
            pSrc->asDouble(L"RadiusCoef"));
    }
    return pResult;
}

ggp::CSweepCurve3d* GfcGeometryImporter::importSweepCurve3d(gfc::engine::CEntity* pSrc )
{
    ggp::CSweepCurve3d* pResult = NULL;
    if (pSrc)
    {
        ggp::CCurve3d* pCurve = importCurve3d(pSrc->asEntity(L"Spine3d").get());
        if (pCurve)
        {
            pResult = new ggp::CSweepCurve3d(pCurve, 
                importVector3d(pSrc->asEntity(L"ReferenceVector").get()),
                importVector2d(pSrc->asEntity(L"Point").get()));
            pCurve->Free();
        }
    }
    return pResult;
}

ggp::CImageCurve3d* GfcGeometryImporter::importImageCurve3d(gfc::engine::CEntity* pSrc )
{
    ggp::CImageCurve3d* pResult = NULL;
    if (pSrc)
    {
        ggp::CCurve2d* pCurve = importCurve2d(pSrc->asEntity(L"Curve").get());
        ggp::CSurface* pSurface = importSurface(pSrc->asEntity(L"Surface").get());
        if (pCurve && pSurface)
        {
            pResult = dynamic_cast<ggp::CImageCurve3d*>(ggp::CImageCurve3d::CreateImageCurve(
                pCurve, pSurface, true));
        }
        if (pCurve)
            pCurve->Free();
        if (pSurface)
            pSurface->Free();
    }
    return pResult;
}

ggp::CCurve3d* GfcGeometryImporter::importCurve3d(gfc::engine::CEntity* pSrc )
{
    if(pSrc->entityName().find(L"Line3d") != std::wstring::npos)
        return importLine3d(pSrc);
    else if (pSrc->entityName().find(L"NurbsCurve3d") != std::wstring::npos)
        return importNurbsCurve3d(pSrc);
    else if (pSrc->entityName().find(L"PlaneCurve3d") != std::wstring::npos)
		return importPlaneCurve3d(pSrc);
    else if (pSrc->entityName().find(L"Arc3d") != std::wstring::npos)
        return importArc3d(pSrc);
    else if (pSrc->entityName().find(L"Ellipse3d") != std::wstring::npos)
        return importEllipse3d(pSrc);
    if (pSrc->entityName().find(L"SpiralLine3d") != std::wstring::npos)
        return importSpiralLine3d(pSrc);
    else if (pSrc->entityName().find(L"SweepCurve3d") != std::wstring::npos)
        return importSweepCurve3d(pSrc);
    else if (pSrc->entityName().find(L"IntersectionCurve3d") != std::wstring::npos)
        return importIntersectionCurve3d(pSrc);
    else if (pSrc->entityName().find(L"ImageCurve3d") != std::wstring::npos)
        return importImageCurve3d(pSrc);
    else
    {
        assert(false);
        return NULL;
    }

}

ggp::CBevel* GfcGeometryImporter::importBevel(gfc::engine::CEntity* pSrc )
{
    ggp::CBevel* pResult = NULL;
    if (pSrc)
    {
        ggp::CCurve2d* pCurve = importCurve2d(pSrc->asEntity(L"Curve").get());
        if (pCurve)
        {
            pResult = new ggp::CBevel(importCoordinates3d(pSrc->asEntity(L"Coord").get()),
                pSrc->asDouble(L"Height"),
                importIntervald(pSrc->asEntity(L"RangeV").get()),
                pCurve);
            pCurve->Free();
        }
    }
    return pResult;
}

ggp::CCylinder* GfcGeometryImporter::importCylinder(gfc::engine::CEntity* pSrc )
{
    ggp::CCylinder* pResult = NULL;
    if (pSrc)
    {
        //ggp::CCoordinates3d oCoord = importCoordinates3d(pSrc->asEntity(L"Coord").get());
        auto oDirX = importVector3d(pSrc->asEntity(L"DirX").get());
        auto oDirY = importVector3d(pSrc->asEntity(L"DirY").get());
        auto oDirZ = importVector3d(pSrc->asEntity(L"DirZ").get());
        auto oPos = importVector3d(pSrc->asEntity(L"Pos").get());
        auto oRangeV = importIntervald(pSrc->asEntity(L"RangeV").get());
        ggp::CCurve2d* pCurve = importCurve2d(pSrc->asEntity(L"Curve").get());
        if (pCurve)
        {
            pResult = new ggp::CCylinder(oDirX, oDirY, oDirZ, oPos, oRangeV, pCurve);
            pCurve->Free();
        }
    }
    return pResult;
}

ggp::CHelicoid* GfcGeometryImporter::importHelicoid(gfc::engine::CEntity* pSrc )
{
    ggp::CHelicoid* pResult = NULL;
    if (pSrc)
    {
        ggp::CCurve2d* pCurve = importCurve2d(pSrc->asEntity(L"Curve").get());
        if (pCurve)
        {
            pResult = new ggp::CHelicoid(importCoordinates3d(pSrc->asEntity(L"Coord").get()),
                pSrc->asDouble(L"Radius"),
                importIntervald(pSrc->asEntity(L"RangeV").get()),
                pSrc->asInteger(L"ClockSign"),
                pSrc->asDouble(L"HeightCoef"),
                pSrc->asDouble(L"RadiusCoef"),
                pCurve);
            pCurve->Free();
        }
    }
    return pResult;
}

ggp::CNurbsSurface* GfcGeometryImporter::importNurbsSurface(gfc::engine::CEntity* pSrc )
{
    ggp::CNurbsSurface* pResult = NULL;
    if (pSrc)
    {
        int nCountU = pSrc->asInteger(L"CtrlPtCountU");
        int nCountV = pSrc->asInteger(L"CtrlPtCountV");
        pResult = new ggp::CNurbsSurface(pSrc->asInteger(L"DegreeU"), pSrc->asInteger(L"DegreeV"), nCountU, nCountV);
        pResult->SetCtrlPtCountU(nCountU);
        pResult->SetCtrlPtCountV(nCountV);
		for(int i = 0; i < nCountU * nCountV; ++i)
		{
			pResult->CtrlPts()[i] = importNurbsCtrlPt3d(pSrc->getEntity(L"CtrlPts", i).get());
		}
        int nKnotsCountU = pSrc->getArrayCount(L"KnotsU");
        for (int i = 0; i < nKnotsCountU; ++i)
        {
            pResult->SetKnotU(i, pSrc->getDouble(L"KnotsU", i));
        }
        int nKnotsCountV = pSrc->getArrayCount(L"KnotsV");
        for (int i = 0; i < nKnotsCountV; ++i)
        {
            pResult->SetKnotV(i, pSrc->getDouble(L"KnotsV", i));
        }
    }
    return pResult;
}

ggp::CPlane* GfcGeometryImporter::importPlane(gfc::engine::CEntity* pSrc )
{
    ggp::CPlane* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CPlane(importVector3d(pSrc->asEntity(L"Pos").get()),
            importVector3d(pSrc->asEntity(L"DirU").get()),
            importVector3d(pSrc->asEntity(L"DirV").get()),
            importIntervald(pSrc->asEntity(L"RangeU").get()),
            importIntervald(pSrc->asEntity(L"RangeV").get())
            );
    }
    return pResult;
}

ggp::CSphere* GfcGeometryImporter::importSphere(gfc::engine::CEntity* pSrc )
{
    ggp::CSphere* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CSphere();
        pResult->SetCoord(importCoordinates3d(pSrc->asEntity(L"Coords").get()));
        pResult->Stru()->radius = pSrc->asDouble(L"Radius");
        pResult->SetRangeU(importIntervald(pSrc->asEntity(L"RangeU").get()));
        pResult->SetRangeV(importIntervald(pSrc->asEntity(L"RangeV").get()));
    }
    return pResult;
}

ggp::CSweep* GfcGeometryImporter::importSweep(gfc::engine::CEntity* pSrc )
{
    ggp::CSweep* pResult = NULL;
    if (pSrc)
    {
        ggp::CCurve3d* pSpine = importCurve3d(pSrc->asEntity(L"Spine3d").get());
        ggp::CCurve2d* pProfile = importCurve2d(pSrc->asEntity(L"Profile").get());
        if (pSpine && pProfile)
        {
            pResult = new ggp::CSweep(pSpine, pProfile,
                importVector3d(pSrc->asEntity(L"ReferenceVector").get()));
        }
        if (pSpine)
            pSpine->Free();
        if (pProfile)
            pProfile->Free();
    }
    return pResult;
}

ggp::CTorus* GfcGeometryImporter::importTorus(gfc::engine::CEntity* pSrc )
{
    ggp::CTorus* pResult = NULL;
    if (pSrc)
    {
        ggp::CTorus::TorusStru oStru;
        oStru.Coord = importCoordinates3d(pSrc->asEntity(L"Coord").get());
        oStru.Radius = pSrc->asDouble(L"Radius");
        oStru.ClockSign = pSrc->asInteger(L"ClockSign");
        oStru.RangeV = importIntervald(pSrc->asEntity(L"RangeV").get());
        ggp::CCurve2d* pCurve = importCurve2d(pSrc->asEntity(L"Curve").get());
        if (pCurve)
        {
            pResult = new ggp::CTorus(oStru, pCurve);
            pCurve->Free();
        }
    }
    return pResult;
}

ggp::CRuledSurface* GfcGeometryImporter::importRuledSurface(gfc::engine::CEntity* pSrc )
{
    ggp::CRuledSurface* pResult = NULL;
    if (pSrc)
    {
        ggp::CCurve3d* pDirectrix1 = importCurve3d(pSrc->asEntity(L"Directrix1").get());
        ggp::CCurve3d* pDirectrix2 = importCurve3d(pSrc->asEntity(L"Directrix2").get());
        ggp::CIntervald oRangeV = importIntervald(pSrc->asEntity(L"RangeV").get());
        // rangeU no used
        if (pDirectrix1 && pDirectrix2)
        {
            switch (pSrc->asInteger(L"ApexIndex"))
            {
            case 0: pResult = new ggp::CRuledSurface(pDirectrix1, pDirectrix2, oRangeV);
                break;
            case 1: pResult = new ggp::CRuledSurface(pDirectrix1->GetPoint(0), pDirectrix2, oRangeV);
                break;
            case 2: pResult = new ggp::CRuledSurface(pDirectrix1, pDirectrix2->GetPoint(0), oRangeV);
                break;
            default:
                assert(false);
            }
        }
        if (pDirectrix1)
            pDirectrix1->Free();
        if (pDirectrix2)
            pDirectrix2->Free();  
    }
    return pResult;
}

ggp::CSurface* GfcGeometryImporter::importSurface(gfc::engine::CEntity* pSrc )
{
    if(pSrc->entityName().find(L"Plane") != std::wstring::npos)
        return importPlane(pSrc);
    else if(pSrc->entityName().find(L"Cylinder") != std::wstring::npos)
        return importCylinder(pSrc);
    else if (pSrc->entityName().find(L"NurbsSurface") != std::wstring::npos)
        return importNurbsSurface(pSrc);
    else if (pSrc->entityName().find(L"Bevel") != std::wstring::npos)
        return importBevel(pSrc);
    else if (pSrc->entityName().find(L"Torus") != std::wstring::npos)
        return importTorus(pSrc);
    else if (pSrc->entityName().find(L"Sphere") != std::wstring::npos)
        return importSphere(pSrc);
    else if (pSrc->entityName().find(L"Helicoid") != std::wstring::npos)
        return importHelicoid(pSrc);
    else if (pSrc->entityName().find(L"Sweep") != std::wstring::npos)
        return importSweep(pSrc);
    else if (pSrc->entityName().find(L"RuledSurface") != std::wstring::npos)
        return importRuledSurface(pSrc);
    else {
        assert(false);
        return NULL;
    }
}

ggp::CBrepBody* GfcGeometryImporter::importBrepBody(gfc::engine::CEntity* pSrc )
{
    ggp::CBrepBody* pResult = NULL;
    if (pSrc)
    {
		pResult = new ggp::CBrepBody;
		int nFaceCount = pSrc->getArrayCount(L"Faces");
		for (int i = 0; i < nFaceCount; ++i)
		{
			ggp::CFace* pFace = importFace(pSrc->getEntity(L"Faces", i).get());
			if (pFace)
			{
				pFace->CalLoopDistEpsilon();
				pResult->AddFace(pFace);
			}
		}
		int nEdgeCount = pSrc->getArrayCount(L"Edges");
		for (int i = 0; i < nEdgeCount; ++i)
		{
			ggp::CEdge* pEdge = importEdge(pSrc->getEntity(L"Edges", i).get());
			if (pEdge)
				pResult->AddEdge(pEdge);
		}
		pResult->CalDisEpsilon();
		if(pResult->DistEpsilon() > 1)
			pResult->Clear();
    }
    return pResult;
}

ggp::CCuboidBody* GfcGeometryImporter::importCuboidBody(gfc::engine::CEntity* pSrc )
{
    ggp::CCuboidBody* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CCuboidBody(importCoordinates3d(pSrc->asEntity(L"Coordinate").get()), importVector3d(pSrc->asEntity(L"Dimension").get()));
    }
    return pResult;
}

ggp::CExtrudedBody* GfcGeometryImporter::importExtrudedBody(gfc::engine::CEntity* pSrc )
{
    ggp::CExtrudedBody* pResult = NULL;
    if (pSrc)
    {
        ggp::CPolygon* pPoly = importPolygon(pSrc->asEntity(L"Section").get());
        if (pPoly)
        {
            pResult = new ggp::CExtrudedBody(importCoordinates3d(pSrc->asEntity(L"Coordinate").get()), 
                pSrc->asDouble(L"Len"), pPoly);
        }
    }
    return pResult;
}

ggp::CPolyhedronBody* GfcGeometryImporter::importPolyhedronBody(gfc::engine::CEntity* pSrc )
{
    ggp::CPolyhedronBody* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CPolyhedronBody;
        int nVertexesCount = pSrc->getArrayCount(L"Vertexes");
        for (int i = 0; i < nVertexesCount; ++i)
        {
            pResult->AddVertex(importVector3d(pSrc->getEntity(L"Vertexes", i).get()));
        }
        int nFaceCount = pSrc->getArrayCount(L"Faces");
        for (int i = 0; i < nFaceCount; ++i)
        {
            ggp::CPolyhedralFace* pFace = importPolyhedralFace(pSrc->getEntity(L"Faces", i).get(), pResult);
            if (pFace)
                pResult->AddFace(pFace);
        }
    }
    return pResult;
}

ggp::CBody* GfcGeometryImporter::importBody(gfc::engine::CEntity* pSrc )
{
    if (pSrc->entityName().find(L"BrepBody") != std::wstring::npos)
        return importBrepBody(pSrc);
    else if (pSrc->entityName().find(L"CuboidBody") != std::wstring::npos)
        return importCuboidBody(pSrc);
    else if (pSrc->entityName().find(L"ExtrudedBody") != std::wstring::npos)
        return importExtrudedBody(pSrc);
    else if (pSrc->entityName().find(L"PolyhedronBody") != std::wstring::npos)
        return importPolyhedronBody(pSrc);
        //     case TinyPolyhedronType:
        //         return exportBrepBody(pSrc);
    else{
        assert(false);
        return NULL;
    }
}

ggp::CPolygon* GfcGeometryImporter::importPolygon(gfc::engine::CEntity* pSrc )
{
    ggp::CPolygon* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CPolygon;
        innerImportPolygon(pSrc, pResult);

		//若多边形非法，则尝试修复
		if (!pResult->IsValid())
		{
			//由于多个环时，无法便捷获取环是外环还是内环，也就无法判断其正确的方向，故只处理只有一个环的情况
			if (pResult->LoopCount() == 1)
			{
				//环的方向错误，则反向
				if (pResult->GetLoop(0)->ClockSign() != ggp::csAnticlockwise)
				{
					pResult->Reverse();
				}
			}
			
			//环应闭合
			bool isClosed = true;
			for (int i = 0; i < pResult->LoopCount(); ++i)
			{
				if (!pResult->GetLoop(i)->IsClosed())
				{
					isClosed = false;
					break;
				}
			}
			if (!isClosed)
			{
				//因实际容差大于使用容差导致环被判断为不闭合，则修复多边形，减小实际容差
				pResult->CalLoopDistEpsilon();
				double dDistEps = pResult->DistEpsilon();
				if (ggp::IsGreaterThan(dDistEps, ggp::g_DistEpsilon, ggp::g_DoubleResolution))
				{
					ggp::PolygonErrorCorrect(pResult);
					assert(ggp::IsLessEqualThan(pResult->DistEpsilon(), ggp::g_DistEpsilon, ggp::g_DoubleResolution));
				}
			}
		}
    }
    return pResult;
}

ggp::NurbsCtrlPt2d GfcGeometryImporter::importNurbsCtrlPt2d(gfc::engine::CEntity* pSrc )
{
    ggp::NurbsCtrlPt2d oResult;
    if (pSrc)
    {
        oResult.Point = importVector2d(pSrc->asEntity(L"Point").get());
        oResult.Weight = pSrc->asDouble(L"Weight");
    }
    return oResult;
}

ggp::NurbsCtrlPt3d GfcGeometryImporter::importNurbsCtrlPt3d(gfc::engine::CEntity* pSrc )
{
    ggp::NurbsCtrlPt3d oResult;
    if (pSrc)
    {
        oResult.Point = importVector3d(pSrc->asEntity(L"Point").get());
        oResult.Weight = pSrc->asDouble(L"Weight");
    }
    return oResult;
}

ggp::CInternalChart GfcGeometryImporter::importInternalChart(gfc::engine::CEntity* pSrc )
{
    ggp::CInternalChart oResult;
    if (pSrc)
    {
        oResult.tra[0] = pSrc->asDouble(L"Tra1");
        oResult.tra[1] = pSrc->asDouble(L"Tra2");
        oResult.tra[2] = pSrc->asDouble(L"Tra3");
        int nCount = pSrc->getArrayCount(L"IPS");
        for (int i = 0; i < nCount; ++i)
        {
            oResult.ips.push_back(importInternalPt(pSrc->getEntity(L"IPS", i).get()));
        }
    }
    return oResult;
}

ggp::CInternalPt GfcGeometryImporter::importInternalPt(gfc::engine::CEntity* pSrc )
{
    ggp::CInternalPt oResult;
    if (pSrc)
    {
        oResult.p = importVector3d(pSrc->asEntity(L"P").get());
        oResult.tvec = importVector3d(pSrc->asEntity(L"TVec").get());
        oResult.t = pSrc->asDouble(L"T");
        oResult.uv = importVector2d(pSrc->asEntity(L"UV").get());
        oResult.uvdir = importVector2d(pSrc->asEntity(L"UVDir").get());
        oResult.st = importVector2d(pSrc->asEntity(L"ST").get());
        oResult.stdir = importVector2d(pSrc->asEntity(L"STDir").get());
    }
    return oResult;
}

ggp::CFace* GfcGeometryImporter::importFace(gfc::engine::CEntity* pSrc )
{
    ggp::CFace* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CFace(importSurface(pSrc->asEntity(L"Surface").get()));
        //pResult->SetBox3d(importBox3d(pSrc->asEntity(L"Box").get()));
        pResult->SetSameDir(pSrc->asBoolean(L"SameDir"));
        pResult->SetIndex(pSrc->asInteger(L"Index"));
        innerImportCommonPolygonEx(pSrc, pResult);
    }
    return pResult;
}

ggp::CEdge* GfcGeometryImporter::importEdge(gfc::engine::CEntity* pSrc )
{
    ggp::CEdge* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CEdge(importCurve3d(pSrc->asEntity(L"Curve").get()));
        pResult->SetFaceIndex(0, pSrc->asInteger(L"FaceIndex1"));
        pResult->SetFaceIndex(1, pSrc->asInteger(L"FaceIndex2"));
        pResult->SetLoopIndex(0, pSrc->asInteger(L"LoopIndex1"));
        pResult->SetLoopIndex(1, pSrc->asInteger(L"LoopIndex2"));
        pResult->SetCoedgeIndex(0, pSrc->asInteger(L"CoedgeIndex1"));
        pResult->SetCoedgeIndex(1, pSrc->asInteger(L"CoedgeIndex2"));
    }
    return pResult;
}

ggp::CPolyhedralFace* GfcGeometryImporter::importPolyhedralFace(gfc::engine::CEntity* pSrc, ggp::CPolyhedronBody* pBody )
{
    ggp::CPolyhedralFace* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CPolyhedralFace(pBody);
        pResult->SetPlaneCoef(importPlaneCoef(pSrc->asEntity(L"Plane").get()));
        int nCount = pSrc->getArrayCount(L"Loops");
        for (int i = 0; i < nCount; ++i)
        {
            ggp::CPolyhedralLoop* pLoop = importPolyhedralLoop(pSrc->getEntity(L"Loops", i).get(), pResult);
            if (pLoop)
                pResult->AddLoop(pLoop);
        }
    }
    return pResult;
}

ggp::CPlaneCoef GfcGeometryImporter::importPlaneCoef(gfc::engine::CEntity* pSrc )
{
    ggp::CPlaneCoef oResult;
    if (pSrc)
    {
        oResult.A = pSrc->asDouble(L"A");
        oResult.B = pSrc->asDouble(L"B");
        oResult.C = pSrc->asDouble(L"C");
        oResult.D = pSrc->asDouble(L"D");
    }
    return oResult;
}

ggp::CPolyhedralLoop* GfcGeometryImporter::importPolyhedralLoop(gfc::engine::CEntity* pSrc, ggp::CPolyhedralFace* pFace )
{
    ggp::CPolyhedralLoop* pResult = NULL;
    if (pSrc)
    {
        pResult = new ggp::CPolyhedralLoop(pFace);
        int nCount = pSrc->getArrayCount(L"Edges");
        for (int i = 0; i < nCount; ++i)
        {
            ggp::CPolyhedralEdge* pEdge = importPolyhedralEdge(pSrc->getEntity(L"Edges", i).get(), pResult);

            if (pEdge)
                pResult->AddEdge(pEdge);
        }
    }
    return pResult;
}

ggp::CPolyhedralEdge* GfcGeometryImporter::importPolyhedralEdge(gfc::engine::CEntity* pSrc, ggp::CPolyhedralLoop* pLoop )
{
    ggp::CPolyhedralEdge* pResult = NULL;
    if (pSrc)
    {
        ggp::CPolyhedralVertex* pStart = pLoop->Face()->Body()->GetVertex(pSrc->asInteger(L"StartVertexIndex"));
        ggp::CPolyhedralVertex* pEnd = pLoop->Face()->Body()->GetVertex(pSrc->asInteger(L"EndVertexIndex"));
        pResult = new ggp::CPolyhedralEdge(pStart, pEnd);
        //pResult->SetLoop(pLoop);//by ligy-a 2016.06.30 重复将边加入到环，用在importPolyhedralLoop()中用CPolyhedralLoop->AddEdge()添加一次就行
    }
    return pResult;
}

void GfcGeometryImporter::innerImportPolygon(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest )
{
    if(pSrc->entityName().find(L"SimplePolygon") != std::wstring::npos)
        innerImportSimplePolygon(pSrc, pDest);
    else if(pSrc->entityName().find(L"CommonPolygon") != std::wstring::npos)
        innerImportCommonPolygon(pSrc, pDest);
    else
        assert(false);
}

void GfcGeometryImporter::innerImportSimplePolygon(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest )
{
    int nLoopCount = pSrc->getArrayCount(L"Loops");
    for (int i = 0; i < nLoopCount; ++i)
    {
        ggp::CLoop* pLoop = new ggp::CLoop();
        auto pList = pSrc->getEntity(L"Loops", i);
        if (pList)
        {
            int nCount = pList->getArrayCount(L"Vertexes");
            for (int j = 0; j < nCount; ++j)
            {
                auto pVertex = pList->getEntity(L"Vertexes", j);
                int k = (j == nCount - 1) ? 0 : j + 1;
                auto pNextVertex = pList->getEntity(L"Vertexes", k);
                if (pVertex && pNextVertex)
                {
                    ggp::CCurve2d* pCurve = NULL;
                    if (!pVertex->isNull(L"ArcType"))
                    {
                        pCurve = new ggp::CArc2d(importVector2d(pVertex->asEntity(L"Point").get()), 
                            importVector2d(pNextVertex->asEntity(L"Point").get()),
                            pVertex->asDouble(L"Radius"),
                            (ggp::CArc2d::ArcType)pVertex->asInteger(L"ArcType"));
                    }
                    else
                    {
                        pCurve = new ggp::CLine2d(importVector2d(pVertex->asEntity(L"Point").get()), 
                            importVector2d(pNextVertex->asEntity(L"Point").get()));
                    }
                    pLoop->AddCurve(pCurve);
                }
            }
            pDest->AddLoop(pLoop);
        }
    }
}

void GfcGeometryImporter::innerImportCommonPolygon(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest )
{
    int nLoopCount = pSrc->getArrayCount(L"Loops");
    for (int i = 0; i < nLoopCount; ++i)
    {
        ggp::CLoop* pLoop = new ggp::CLoop();
        auto pList = pSrc->getEntity(L"Loops", i);
        if (pList)
        {
            int nCount = pList->getArrayCount(L"Coedges");
            for (int j = 0; j < nCount; ++j)
            {
                ggp::CCurve2d* pCurve = importCurve2d(pList->getEntity(L"Coedges", j).get());
                if (pCurve)
                    pLoop->AddCurve(pCurve);
            }
            pDest->AddLoop(pLoop);
        }
    }
}

void GfcGeometryImporter::innerImportCommonPolygonEx(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest)
{
	int nLoopCount = pSrc->getArrayCount(L"LoopExs");
	for (int i = 0; i < nLoopCount; ++i)
	{
		ggp::CLoopEx* pLoop = new ggp::CLoopEx();
		auto pList = pSrc->getEntity(L"LoopExs", i);
		if (pList)
		{
			int nCount = pList->getArrayCount(L"CoedgeExs");
			for (int j = 0; j < nCount; ++j)
			{
				auto pCoedge = pList->getEntity(L"CoedgeExs", j);
				ggp::CCoedgeEx* pCoedgeEx = new ggp::CCoedgeEx(importCurve2d(pCoedge->asEntity(L"Curve").get()));
				if (pCoedgeEx)
				{
					pCoedgeEx->SetEdgeIndex(pCoedge->asInteger(L"EdgeIndex"));
					pCoedgeEx->SetEdgeSameDir(pCoedge->asBoolean(L"EdgeSameDir"));
					pLoop->AddCoedge(pCoedgeEx);
				}
			}
			pDest->AddLoop(pLoop);
		}				
	}
}
