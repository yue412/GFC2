#include "GfcUtils/GfcGeometryExporter.h"
#include "GMath/GMathNurbs.h"
#include "Geometry/Loop.h"
#include "Geometry/Coedge.h"
#include "Geometry/CoedgeEx.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcCoordinates2d.h"
#include "GfcClasses/x3/GfcBox3d.h"
#include "GfcClasses/x3/GfcLine2d.h"
#include "GfcClasses/x3/GfcArc2d.h"
#include "GfcClasses/x3/GfcNurbsCurve2d.h"
#include "GfcClasses/x3/GfcNurbsCtrlPt2d.h"
#include "GfcClasses/x3/GfcEllipse2d.h"
#include "GfcClasses/x3/GfcPreimageCurve2d.h"
#include "GfcClasses/x3/GfcSinCurve2d.h"
#include "GfcClasses/x3/GfcSpiralLine2d.h"
#include "GfcClasses/x3/GfcLine3d.h"
#include "GfcClasses/x3/GfcArc3d.h"
#include "GfcClasses/x3/GfcEllipse3d.h"
#include "GfcClasses/x3/GfcNurbsCtrlPt3d.h"
#include "GfcClasses/x3/GfcNurbsCurve3d.h"
#include "GfcClasses/x3/GfcIntersectionCurve3d.h"
#include "GfcClasses/x3/GfcSpiralLine3d.h"
#include "GfcClasses/x3/GfcSweepCurve3d.h"
#include "GfcClasses/x3/GfcBevel.h"
#include "GfcClasses/x3/GfcCylinder.h"
#include "GfcClasses/x3/GfcHelicoid.h"
#include "GfcClasses/x3/GfcNurbsSurface.h"
#include "GfcClasses/x3/GfcPlane.h"
#include "GfcClasses/x3/GfcSphere.h"
#include "GfcClasses/x3/GfcSweep.h"
#include "GfcClasses/x3/GfcTorus.h"
#include "GfcClasses/x3/GfcBrepBody.h"
#include "GfcClasses/x3/GfcCuboidBody.h"
#include "GfcClasses/x3/GfcExtrudedBody.h"
#include "GfcClasses/x3/GfcPolyhedronBody.h"
#include "GfcClasses/x3/GfcFace.h"
#include "GfcClasses/x3/GfcEdge.h"
#include "GfcClasses/x3/GfcPolygon.h"
#include "GfcClasses/x3/GfcCoedgeList.h"
#include "GfcClasses/x3/GfcPolyhedralFace.h"
#include "GfcClasses/x3/GfcPlaneCoef.h"
#include "GfcClasses/x3/GfcPolyhedralLoop.h"
#include "GfcClasses/x3/GfcPolyhedralEdge.h"
#include "GfcClasses/x3/GfcOffsetCurve2d.h"
#include "GfcClasses/x3/GfcImageCurve3d.h"
#include "GfcClasses/x3/GfcRuledSurface.h"
#include "GfcClasses/x3/GfcSimplePolygon.h"
#include "GfcClasses/x3/GfcPlaneCurve3d.h"
#include "GfcClasses/x3/GfcCoedgeListEx.h"
#include "GfcClasses/x3/GfcCoedge.h"
#include "GfcEngine/Writer.h"
#include "GfcClasses/x3/GfcCommonPolygonEx.h"
#include "GfcClasses/x3/GfcCommonPolygon.h"

using namespace gfc::classes::x3;

ggp::CArc2d::ArcType _getArcType( double dBulge )
{
    if (dBulge > 1)
    {
        return ggp::CArc2d::atACL;
    }
    else if (dBulge > 0)
    {
        return ggp::CArc2d::atACS;
    }
    else if (dBulge == 0)
    {
        assert(false);
        return ggp::CArc2d::atACS;
    }
    else if (dBulge >= -1)
    {
        return ggp::CArc2d::atCS;
    }
    else
    {
        return ggp::CArc2d::atCL;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::m_nVec3d100 = -1;
gfc::engine::EntityRef GfcGeometryExporter::m_nVec3d010 = -1;
gfc::engine::EntityRef GfcGeometryExporter::m_nVec3d001 = -1;
gfc::engine::EntityRef GfcGeometryExporter::m_nVec3d000 = -1;

gfc::engine::EntityRef GfcGeometryExporter::exportVector2d( gfc::engine::CWriter* pWriter, ggp::CVector2d* pSrc )
{
    assert(pSrc);
    GfcVector2d oVector2d;
    oVector2d.setX(pSrc->X);
    oVector2d.setY(pSrc->Y);
    return pWriter->writeEntity(&oVector2d);
}

// void GfcGeometryExporter::exportVector2d( ggp::CVector2d* pSrc, GfcVector2d* pDest )
// {
//     pDest->setX(pSrc->X);
//     pDest->setY(pSrc->Y);
// }

gfc::engine::EntityRef GfcGeometryExporter::exportVector3d( gfc::engine::CWriter* pWriter, ggp::CVector3d* pSrc )
{
    assert(pSrc);
    GfcVector3d oVector;
    oVector.setX(pSrc->X);
    oVector.setY(pSrc->Y);
    oVector.setZ(pSrc->Z);
    return pWriter->writeEntity(&oVector);
}

gfc::engine::EntityRef GfcGeometryExporter::exportIntervald( gfc::engine::CWriter* pWriter, ggp::CIntervald* pSrc )
{
    assert(pSrc);
    GfcIntervald oDest;
    oDest.setMin(pSrc->Min);
    oDest.setMax(pSrc->Max);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCoordinates3d( gfc::engine::CWriter* pWriter, ggp::CCoordinates3d* pSrc )
{
    assert(pSrc);
    GfcCoordinates3d oDest;
    oDest.setOrigin(exportVector3dCompact(pWriter, &pSrc->Origin));
    oDest.setX(exportVector3dCompact(pWriter, &pSrc->X));
    oDest.setY(exportVector3dCompact(pWriter, &pSrc->Y));
    oDest.setZ(exportVector3dCompact(pWriter, &pSrc->Z));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCoordinates2d( gfc::engine::CWriter* pWriter, ggp::CCoordinates2d* pSrc )
{
    assert(pSrc);
    GfcCoordinates2d oDest;
    oDest.setOrigin(exportVector2d(pWriter, &pSrc->Origin));
    oDest.setX(exportVector2d(pWriter, &pSrc->X));
    oDest.setY(exportVector2d(pWriter, &pSrc->Y));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportBox3d( gfc::engine::CWriter* pWriter, ggp::CBox3d* pSrc )
{
    assert(pSrc);
    GfcBox3d oDest;
    auto oMinPt = pSrc->MinPt();
    auto oMaxPt = pSrc->MaxPt();
    oDest.setMin(exportVector3d(pWriter, &oMinPt));
    oDest.setMax(exportVector3d(pWriter, &oMaxPt));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportLine2d( gfc::engine::CWriter* pWriter, ggp::CLine2d* pSrc )
{
    assert(pSrc);
    GfcLine2d oDest;
    auto oStartPt = pSrc->StartPoint();
    auto oEndPt = pSrc->EndPoint();
    oDest.setStartPt(exportVector2d(pWriter, &oStartPt));
    oDest.setEndPt(exportVector2d(pWriter, &oEndPt));
//    oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportArc2d( gfc::engine::CWriter* pWriter, ggp::CArc2d* pSrc )
{
    assert(pSrc);
    GfcArc2d oDest;
    auto oCenterPt = pSrc->CenterPt();
    oDest.setCenterPt(exportVector2d(pWriter, &oCenterPt));
    oDest.setRadius(pSrc->Radius());
    auto oRange = pSrc->Range();
    oDest.setRange(exportIntervald(pWriter, &oRange));
    oDest.setClockSign(pSrc->ClockSign());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportEllipse2d( gfc::engine::CWriter* pWriter, ggp::CEllipse2d* pSrc )
{
    assert(pSrc);
    GfcEllipse2d oDest;
    auto oCenterPt = pSrc->CenterPt();
    auto oMajorAxis = pSrc->MajorAxis();
    oDest.setCenterPt(exportVector2d(pWriter, &oCenterPt));
    oDest.setMajorAxis(exportVector2d(pWriter, &oMajorAxis));
    oDest.setdMajorRad(pSrc->MajorRadius());
    oDest.setdMinorRad(pSrc->MinorRadius());
    auto oRange = pSrc->Range();
    oDest.setRange(exportIntervald(pWriter, &oRange));
    oDest.setClockSign(pSrc->ClockSign());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsCurve2d( gfc::engine::CWriter* pWriter, ggp::CNurbsCurve2d* pSrc )
{
    assert(pSrc);
    GfcNurbsCurve2d oDest;
    oDest.setDegree(pSrc->Degree());
    int nCount = pSrc->CtrlPtCount();
    for (int i = 0; i < nCount; ++i)
    {
        auto oCtrlPt = pSrc->CtrlPt(i);
        oDest.addCtrlPts(exportNurbsCtrlPt2d(pWriter, &oCtrlPt));
    }
    int nKCount = ggp::getKnotCount(pSrc->Degree(), pSrc->CtrlPtCount());
    for (int i = 0; i < nKCount; ++i)
    {
        oDest.addKnots(pSrc->Knot(i));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsCtrlPt2d( gfc::engine::CWriter* pWriter, ggp::NurbsCtrlPt2d* pSrc )
{
    assert(pSrc);
    GfcNurbsCtrlPt2d oDest;
    oDest.setPoint(exportVector2d(pWriter, &pSrc->Point));
    oDest.setWeight(pSrc->Weight);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPreimageCurve2d( gfc::engine::CWriter* pWriter, ggp::CPreimageCurve2d* pSrc )
{
    assert(pSrc);
    GfcPreimageCurve2d oDest;
    auto oRange = pSrc->Range();
    oDest.setRange(exportIntervald(pWriter, &oRange));
    oDest.setReversed(pSrc->Reversed());
    oDest.setBase(exportSurface(pWriter, pSrc->GetBaseSurface().get()));
    oDest.setCurve(exportCurve3d(pWriter, pSrc->GetBaseCurve().get()));
    oDest.setTolerance(pSrc->Tolerance()); // can not get
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSinCurve2d( gfc::engine::CWriter* pWriter, ggp::CSinCurve2d* pSrc )
{
    assert(pSrc);
    GfcSinCurve2d oDest;
    auto oPos = pSrc->Pos();
    auto oDirX = pSrc->DirX();
    oDest.setPos(exportVector2d(pWriter, &oPos));
    oDest.setDirX(exportVector2d(pWriter, &oDirX));
    oDest.setA(pSrc->A());
    oDest.setB(pSrc->B());
    auto oRange = pSrc->Range();
    oDest.setRange(exportIntervald(pWriter, &oRange));
    oDest.setClockSign(pSrc->ClockSign());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSpiralLine2d( gfc::engine::CWriter* pWriter, ggp::CSpiralLine2d* pSrc )
{
    assert(pSrc);
    GfcSpiralLine2d oDest;
    auto oCoord = pSrc->Coord();
    oDest.setCoord(exportCoordinates2d(pWriter, &oCoord));
    oDest.setRadius(pSrc->Radius());
    auto oRange = pSrc->Range();
    oDest.setRange(exportIntervald(pWriter, &oRange));
    oDest.setClockSign(pSrc->ClockSign());
    oDest.setRadiusCoef(pSrc->RadiusCoef());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCurve2d( gfc::engine::CWriter* pWriter, ggp::CCurve2d* pSrc )
{
	//pSrc有可能存在为null的情况
	if (nullptr == pSrc)
	{
		return -1;
	}
    switch (pSrc->Type())
    {
    case ggp::Line2dType:
        return exportLine2d(pWriter, dynamic_cast<ggp::CLine2d*>(pSrc));
    case ggp::Arc2dType:
        return exportArc2d(pWriter, dynamic_cast<ggp::CArc2d*>(pSrc));
    case ggp::NurbsCurve2dType:
        return exportNurbsCurve2d(pWriter, dynamic_cast<ggp::CNurbsCurve2d*>(pSrc));
    case ggp::Ellipse2dType:
        return exportEllipse2d(pWriter, dynamic_cast<ggp::CEllipse2d*>(pSrc));
    case ggp::SinCurve2dType:
        return exportSinCurve2d(pWriter, dynamic_cast<ggp::CSinCurve2d*>(pSrc));
    case ggp::SpiralLine2dType:
        return exportSpiralLine2d(pWriter, dynamic_cast<ggp::CSpiralLine2d*>(pSrc));
    case ggp::PreimageCurve2dType:
        return exportPreimageCurve2d(pWriter, dynamic_cast<ggp::CPreimageCurve2d*>(pSrc));
    case ggp::OffsetCurve2dType:
        return exportOffsetCurve2d(pWriter, dynamic_cast<ggp::COffsetCurve2d*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportLine3d( gfc::engine::CWriter* pWriter, ggp::CLine3d* pSrc )
{
    assert(pSrc);
    GfcLine3d oDest;
    auto oStartPt = pSrc->StartPoint();
    auto oEndPt = pSrc->EndPoint();
    oDest.setStartPt(exportVector3d(pWriter, &oStartPt));
    oDest.setEndPt(exportVector3d(pWriter, &oEndPt));
    //oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    return pWriter->writeEntity(&oDest);
}

//gfc::engine::EntityRef GfcGeometryExporter::exportArc3d( gfc::engine::Writer* pWriter, ggp::CArc3d* pSrc )
//{
//	assert(pSrc);
//	GfcArc3d oDest;
//	oDest.setArc(exportCurve2d(pWriter, pSrc->Curve2d()));    
//	oDest.setPlane(exportPlaneInfo(pWriter, &pSrc->DirX(), &pSrc->DirY(), &pSrc->Pos()));
//	return pWriter->writeEntity(&oDest);
//}
//
//gfc::engine::EntityRef GfcGeometryExporter::exportEllipse3d( gfc::engine::Writer* pWriter, ggp::CEllipse3d* pSrc )
//{
//	assert(pSrc);
//	GfcEllipse3d oDest;
//	oDest.setEllipse(exportCurve2d(pWriter, pSrc->Curve2d()));    
//	oDest.setPlane(exportPlaneInfo(pWriter, &pSrc->DirX(), &pSrc->DirY(), &pSrc->Pos()));
//	return pWriter->writeEntity(&oDest);
//}

gfc::engine::EntityRef GfcGeometryExporter::exportPlaneCurve3d( gfc::engine::CWriter* pWriter, ggp::CPlaneCurve3d* pSrc )
{
	assert(pSrc);
	GfcPlaneCurve3d oDest;
	oDest.setPlaneCurve(exportCurve2d(pWriter, pSrc->Curve2d()));    
    auto oDirX = pSrc->DirX();
    auto oDirY = pSrc->DirY();
    auto oPos = pSrc->Pos();
	oDest.setPlane(exportPlaneInfo(pWriter, &oDirX, &oDirY, &oPos));
	return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsCurve3d( gfc::engine::CWriter* pWriter, ggp::CNurbsCurve3d* pSrc )
{
    assert(pSrc);
    GfcNurbsCurve3d oDest;
    oDest.setDegree(pSrc->Degree());
    int nCount = pSrc->CtrlPtCount();
    for (int i = 0; i < nCount; ++i)
    {
        auto oCtrlPt = pSrc->CtrlPt(i);
        oDest.addCtrlPts(exportNurbsCtrlPt3d(pWriter, &oCtrlPt));
    }
    int nKCount = ggp::getKnotCount(pSrc->Degree(), pSrc->CtrlPtCount());
    for (int i = 0; i < nKCount; ++i)
    {
        oDest.addKnots(pSrc->Knot(i));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportIntersectionCurve3d( gfc::engine::CWriter* pWriter, ggp::CIntersectionCurve3d* pSrc )
{
    assert(pSrc);
    GfcIntersectionCurve3d oDest;
    ggp::CSurfacePtr pBases[2];
    pSrc->GetBaseSurfaces(pBases);
    oDest.setBases1(exportSurface(pWriter, pBases[0].get()));
    oDest.setBases2(exportSurface(pWriter, pBases[1].get()));
    auto oRange = pSrc->Range();
    auto oChart = pSrc->Chart();
    oDest.setRange(exportIntervald(pWriter, &oRange));
    oDest.setChart(exportInternalChart(pWriter, &oChart));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSpiralLine3d( gfc::engine::CWriter* pWriter, ggp::CSpiralLine* pSrc )
{
    assert(pSrc);
    GfcSpiralLine3d oDest;
    auto oCoord = pSrc->Coord();
    oDest.setCoord(exportCoordinates3d(pWriter, &oCoord));
    oDest.setRadius(pSrc->Radius());
    auto oRange = pSrc->Range();
    oDest.setRange(exportIntervald(pWriter, &oRange));
    oDest.setClockSign(pSrc->ClockSign());
    oDest.setRadiusCoef(pSrc->RadiusCoef());
    oDest.setHeightCoef(pSrc->HeightCoef());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSweepCurve3d( gfc::engine::CWriter* pWriter, ggp::CSweepCurve3d* pSrc )
{
    assert(pSrc);
    GfcSweepCurve3d oDest;
    oDest.setSpine3d(exportCurve3d(pWriter, pSrc->Spine()));
    auto oReferenceVector = pSrc->GetReferenceVector();
    oDest.setReferenceVector(exportVector3d(pWriter, &oReferenceVector));
    auto oProfile = pSrc->Profile();
    oDest.setPoint(exportVector2d(pWriter, &oProfile));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCurve3d( gfc::engine::CWriter* pWriter, ggp::CCurve3d* pSrc )
{
    switch (pSrc->Type())
    {
    case ggp::Line3dType:
        return exportLine3d(pWriter, dynamic_cast<ggp::CLine3d*>(pSrc));
    case ggp::NurbsCurve3dType:
        return exportNurbsCurve3d(pWriter, dynamic_cast<ggp::CNurbsCurve3d*>(pSrc));
    case ggp::PlaneCurve3dType:
		return exportPlaneCurve3d(pWriter, dynamic_cast<ggp::CPlaneCurve3d*>(pSrc));
    case ggp::SpiralLineType:
        return exportSpiralLine3d(pWriter, dynamic_cast<ggp::CSpiralLine*>(pSrc));
    case ggp::SweepCurve3dType:
        return exportSweepCurve3d(pWriter, dynamic_cast<ggp::CSweepCurve3d*>(pSrc));
    case ggp::IntersectionCurve3dType:
        return exportIntersectionCurve3d(pWriter, dynamic_cast<ggp::CIntersectionCurve3d*>(pSrc));
    case ggp::ImageCurve3dType:
        return exportImageCurve3d(pWriter, dynamic_cast<ggp::CImageCurve3d*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsCtrlPt3d( gfc::engine::CWriter* pWriter, ggp::NurbsCtrlPt3d* pSrc )
{
    assert(pSrc);
    GfcNurbsCtrlPt3d oDest;
    oDest.setPoint(exportVector3d(pWriter, &pSrc->Point));
    oDest.setWeight(pSrc->Weight);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportInternalChart( gfc::engine::CWriter* pWriter, ggp::CInternalChart* pSrc )
{
    assert(pSrc);
    GfcInternalChart oDest;
    oDest.setTra1(pSrc->tra[0]);
    oDest.setTra2(pSrc->tra[1]);
    oDest.setTra3(pSrc->tra[2]);
    
    for (auto itr = pSrc->ips.begin(); itr != pSrc->ips.end(); ++itr )
    {
        oDest.addIPS(exportInternalPt(pWriter, &(*itr)));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportInternalPt( gfc::engine::CWriter* pWriter, ggp::CInternalPt* pSrc )
{
    assert(pSrc);
    GfcInternalPt oDest;
    oDest.setP(exportVector3d(pWriter, &pSrc->p));
    oDest.setTVec(exportVector3d(pWriter, &pSrc->tvec));
    oDest.setT(pSrc->t);
    oDest.setUV(exportVector2d(pWriter, &pSrc->uv));
    oDest.setST(exportVector2d(pWriter, &pSrc->st));
    oDest.setUVDir(exportVector2d(pWriter, &pSrc->uvdir));
    oDest.setSTDir(exportVector2d(pWriter, &pSrc->stdir));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPlaneInfo( gfc::engine::CWriter* pWriter, ggp::CVector3d* pDirX, ggp::CVector3d* pDirY, ggp::CVector3d* pPos )
{
    assert(pDirX);
    assert(pDirY);
    assert(pPos);
    GfcPlaneInfo oDest;
    oDest.setDirX(exportVector3d(pWriter, pDirX));
    oDest.setDirY(exportVector3d(pWriter, pDirY));
    oDest.setPos(exportVector3d(pWriter, pPos));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportBevel( gfc::engine::CWriter* pWriter, ggp::CBevel* pSrc )
{
    assert(pSrc);
    GfcBevel oDest;
    ggp::CCoordinates3d pSrc1 = pSrc->Coord();
    oDest.setCoord(exportCoordinates3d(pWriter, &pSrc1));
    oDest.setHeight(pSrc->Height());
    auto oRangeV = pSrc->RangeV();
    oDest.setRangeV(exportIntervald(pWriter, &oRangeV));
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCylinder( gfc::engine::CWriter* pWriter, ggp::CCylinder* pSrc )
{
    assert(pSrc);
    GfcCylinder oDest;
    //GfcCoordinates3d oCoord;
    auto oDirX = pSrc->DirX();
    auto oDirY = pSrc->DirY();
    auto oDirZ = pSrc->DirZ();
    auto oPos = pSrc->Pos();
    oDest.setDirX(exportVector3d(pWriter, &oDirX));
    oDest.setDirY(exportVector3d(pWriter, &oDirY));
    oDest.setDirZ(exportVector3d(pWriter, &oDirZ));
    oDest.setPos(exportVector3d(pWriter, &oPos));
    //oDest.setCoord(pWriter->writeEntity(&oCoord));
    auto oRangeV = pSrc->RangeV();
    oDest.setRangeV(exportIntervald(pWriter, &oRangeV));
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportHelicoid( gfc::engine::CWriter* pWriter, ggp::CHelicoid* pSrc )
{
    assert(pSrc);
    GfcHelicoid oDest;
    auto oCoord = pSrc->Coord();
    oDest.setCoord(exportCoordinates3d(pWriter, &oCoord));
    oDest.setRadius(pSrc->Radius());
    auto oRangeV = pSrc->RangeV();
    oDest.setRangeV(exportIntervald(pWriter, &oRangeV));
    oDest.setClockSign(pSrc->ClockSign());
    oDest.setHeightCoef(pSrc->HeightCoef());
    oDest.setRadiusCoef(pSrc->RadiusCoef());
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsSurface( gfc::engine::CWriter* pWriter, ggp::CNurbsSurface* pSrc )
{
    assert(pSrc);
    GfcNurbsSurface oDest;
    oDest.setDegreeU(pSrc->DegreeU());
    oDest.setDegreeV(pSrc->DegreeV());
    oDest.setCtrlPtCountU(pSrc->CtrlPtCountU());
    oDest.setCtrlPtCountV(pSrc->CtrlPtCountV());
    int nCount = pSrc->CtrlPtCountU() * pSrc->CtrlPtCountV();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addCtrlPts(exportNurbsCtrlPt3d(pWriter, pSrc->CtrlPts() + i));
    }
    int nKnotCountU = ggp::getKnotCount(pSrc->DegreeU(), pSrc->CtrlPtCountU());
    for (int i = 0; i < nKnotCountU; ++i)
    {
        oDest.addKnotsU(pSrc->KnotU(i));
    }
    int nKnotCountV = ggp::getKnotCount(pSrc->DegreeV(), pSrc->CtrlPtCountV());
    for (int i = 0; i < nKnotCountV; ++i)
    {
        oDest.addKnotsV(pSrc->KnotV(i));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPlane( gfc::engine::CWriter* pWriter, ggp::CPlane* pSrc )
{
    assert(pSrc);
    GfcPlane oDest;
    auto oDirU = pSrc->DirU();
    auto oDirV = pSrc->DirV();
    auto oPos = pSrc->Pos();
    auto oRangeU = pSrc->RangeU();
    auto oRangeV = pSrc->RangeV();
    oDest.setDirU(exportVector3d(pWriter, &oDirU));
    oDest.setDirV(exportVector3d(pWriter, &oDirV));
    oDest.setPos(exportVector3d(pWriter, &oPos));
    oDest.setRangeU(exportIntervald(pWriter, &oRangeU));
    oDest.setRangeV(exportIntervald(pWriter, &oRangeV));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSphere( gfc::engine::CWriter* pWriter, ggp::CSphere* pSrc )
{
    assert(pSrc);
    GfcSphere oDest;
    auto oCoord = pSrc->Coord();
    oDest.setCoords(exportCoordinates3d(pWriter, const_cast<ggp::CCoordinates3d*>(&oCoord)));
    oDest.setRadius(pSrc->Radius());
    auto oRangeV = pSrc->RangeV();
    auto oRangeU = pSrc->RangeU();
    oDest.setRangeV(exportIntervald(pWriter, &oRangeV));
    oDest.setRangeU(exportIntervald(pWriter, &oRangeU));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSweep( gfc::engine::CWriter* pWriter, ggp::CSweep* pSrc )
{
    assert(pSrc);
    GfcSweep oDest;
    oDest.setProfile(exportCurve2d(pWriter, pSrc->Profile()));
    oDest.setSpine3d(exportCurve3d(pWriter, pSrc->Spine()));
    auto oReferenceVector = pSrc->GetReferenceVector();
    oDest.setReferenceVector(exportVector3d(pWriter, &oReferenceVector));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportTorus( gfc::engine::CWriter* pWriter, ggp::CTorus* pSrc )
{
    assert(pSrc);
    GfcTorus oDest;
    auto oCoord = pSrc->Coord();
    oDest.setCoord(exportCoordinates3d(pWriter, &oCoord));
    oDest.setRadius(pSrc->Radius());
    oDest.setClockSign(pSrc->ClockSign());
    auto oRangeV = pSrc->RangeV();
    oDest.setRangeV(exportIntervald(pWriter, &oRangeV));
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSurface( gfc::engine::CWriter* pWriter, ggp::CSurface* pSrc )
{
    switch (pSrc->Type())
    {
    case ggp::PlaneType:
        return exportPlane(pWriter, dynamic_cast<ggp::CPlane*>(pSrc));
    case ggp::CylinderType:
        return exportCylinder(pWriter, dynamic_cast<ggp::CCylinder*>(pSrc));
    case ggp::NurbsSurfaceType:
        return exportNurbsSurface(pWriter, dynamic_cast<ggp::CNurbsSurface*>(pSrc));
    case ggp::BevelType:
        return exportBevel(pWriter, dynamic_cast<ggp::CBevel*>(pSrc));
    case ggp::TorusType:
        return exportTorus(pWriter, dynamic_cast<ggp::CTorus*>(pSrc));
    case ggp::SphereType:
        return exportSphere(pWriter, dynamic_cast<ggp::CSphere*>(pSrc));
    case ggp::HelicoidType:
        return exportHelicoid(pWriter, dynamic_cast<ggp::CHelicoid*>(pSrc));
    case ggp::SweepType:
        return exportSweep(pWriter, dynamic_cast<ggp::CSweep*>(pSrc));
    case ggp::RuledSurfaceType:
        return exportRuledSurface(pWriter, dynamic_cast<ggp::CRuledSurface*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportBrepBody( gfc::engine::CWriter* pWriter, ggp::CBrepBody* pSrc )
{
    assert(pSrc);
    GfcBrepBody oDest;
    int nFaceCount = pSrc->FaceCount();
    for (int i = 0; i < nFaceCount; ++i)
    {
        oDest.addFaces(exportFace(pWriter, pSrc->GetFace(i)));
    }
    int nEdgeCount = pSrc->EdgeCount();
    for (int i = 0; i < nEdgeCount; ++i)
    {
        oDest.addEdges(exportEdge(pWriter, pSrc->GetEdge(i)));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCuboidBody( gfc::engine::CWriter* pWriter, ggp::CCuboidBody* pSrc )
{
    assert(pSrc);
    GfcCuboidBody oDest;
    auto oCoordinate = pSrc->GetCoordinate();
    oDest.setCoordinate(exportCoordinates3d(pWriter, &oCoordinate));
    auto oDimension = pSrc->GetDimension();
    oDest.setDimension(exportVector3d(pWriter, &oDimension));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportExtrudedBody( gfc::engine::CWriter* pWriter, ggp::CExtrudedBody* pSrc )
{
    assert(pSrc);
    GfcExtrudedBody oDest;
    auto oCoordinate = pSrc->GetCoordinate();
    oDest.setCoordinate(exportCoordinates3d(pWriter, &oCoordinate));
    oDest.setLen(pSrc->GetLength());
    oDest.setSection(exportPolygon(pWriter, pSrc->Section()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPolyhedronBody( gfc::engine::CWriter* pWriter, ggp::CPolyhedronBody* pSrc )
{
    assert(pSrc);
    GfcPolyhedronBody oDest;
    int nFaceCount = pSrc->FaceCount();
    for (int i = 0; i < nFaceCount; ++i)
    {
        oDest.addFaces(exportPolyhedralFace(pWriter, pSrc->GetFace(i)));
    }
    int nVertexCount = pSrc->VertexCount();
    for (int i = 0; i < nVertexCount; ++i)
    {
        auto oPos = pSrc->GetVertex(i)->GetPosition();
        oDest.addVertexes(exportVector3d(pWriter, &oPos));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportBody( gfc::engine::CWriter* pWriter, ggp::CBody* pSrc )
{
    switch (pSrc->Type())
    {
    case ggp::BrepBodyType:
        return exportBrepBody(pWriter, dynamic_cast<ggp::CBrepBody*>(pSrc));
    case ggp::CuboidBodyType:
        return exportCuboidBody(pWriter, dynamic_cast<ggp::CCuboidBody*>(pSrc));
    case ggp::ExtrudedBodyType:
        return exportExtrudedBody(pWriter, dynamic_cast<ggp::CExtrudedBody*>(pSrc));
    case ggp::PolyhedronType:
        return exportPolyhedronBody(pWriter, dynamic_cast<ggp::CPolyhedronBody*>(pSrc));
//     case TinyPolyhedronType:
//         return exportBrepBody(pWriter, dynamic_cast<ggp::CBrepBody*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

void GfcGeometryExporter::initGfcBody(gfc::engine::CWriter* pWriter, gfc::engine::CEntity* pEntity, ggp::CBody* pSrc)
{
    switch (pSrc->Type())
    {
    case ggp::BrepBodyType:
    {
        ggp::CBrepBody* pBrep = static_cast<ggp::CBrepBody*>(pSrc);
        int nFaceCount = pBrep->FaceCount();
        for (int i = 0; i < nFaceCount; ++i)
        {
            pEntity->addEntityRef(L"Faces", exportFace(pWriter, pBrep->GetFace(i)));
        }
        int nEdgeCount = pBrep->EdgeCount();
        for (int i = 0; i < nEdgeCount; ++i)
        {
            pEntity->addEntityRef(L"Edges", exportEdge(pWriter, pBrep->GetEdge(i)));
        }
    }
    //case ggp::CuboidBodyType:
    //    return exportCuboidBody(pWriter, dynamic_cast<ggp::CCuboidBody*>(pSrc));
    //case ggp::ExtrudedBodyType:
    //    return exportExtrudedBody(pWriter, dynamic_cast<ggp::CExtrudedBody*>(pSrc));
    //case ggp::PolyhedronType:
    //    return exportPolyhedronBody(pWriter, dynamic_cast<ggp::CPolyhedronBody*>(pSrc));
        //     case TinyPolyhedronType:
        //         return exportBrepBody(pWriter, dynamic_cast<ggp::CBrepBody*>(pSrc));
    default:
        assert(false);
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportFace( gfc::engine::CWriter* pWriter, ggp::CFace* pSrc )
{
    assert(pSrc);
    GfcFace oDest;
    oDest.setSurface(exportSurface(pWriter, pSrc->Surface()));
    auto oBox = pSrc->Box3d();
    oDest.setBox(exportBox3d(pWriter, &oBox));
    oDest.setIndex(pSrc->Index());
    oDest.setSameDir(pSrc->SameDir());
    innerExportPolygonEx(pWriter, pSrc, &oDest);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportEdge( gfc::engine::CWriter* pWriter, ggp::CEdge* pSrc )
{
    assert(pSrc);
    GfcEdge oDest;
    oDest.setCurve(exportCurve3d(pWriter, pSrc->Curve()));
    oDest.setFaceIndex1(pSrc->FaceIndex(0));
    oDest.setFaceIndex2(pSrc->FaceIndex(1));
    oDest.setLoopIndex1(pSrc->LoopIndex(0));
    oDest.setLoopIndex2(pSrc->LoopIndex(1));
    oDest.setCoedgeIndex1(pSrc->CoedgeIndex(0));
    oDest.setCoedgeIndex2(pSrc->CoedgeIndex(1));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPolygon( gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc )
{
    assert(pSrc);
    if (isSimplePolygon(pSrc))
        return exportSimplePolygon(pWriter, pSrc);
    GfcCommonPolygon oDest;
    innerExportPolygon(pWriter, pSrc, &oDest);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCoedgeList( gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc )
{
    assert(pSrc);
    GfcCoedgeList oDest;
    int nCount = pSrc->CoedgeCount();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addCoedges(exportCurve2d(pWriter, pSrc->GetCurve(i)));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCoedgeListEx( gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc )
{
	assert(pSrc);
	GfcCoedgeListEx oDest;
	int nCount = pSrc->CoedgeCount();
	for (int i = 0; i < nCount; ++i)
	{
		GfcCoedge oCoedge;
		oCoedge.setCurve(exportCurve2d(pWriter, pSrc->GetCurve(i)));
		ggp::CCoedgeEx* pCoedgeEx = (ggp::CCoedgeEx*)pSrc->GetCoedge(i);
		if(pCoedgeEx)
		{
			oCoedge.setEdgeIndex(pCoedgeEx->EdgeIndex());
			oCoedge.setEdgeSameDir(pCoedgeEx->EdgeSameDir());
		}
		oDest.addCoedgeExs(pWriter->writeEntity(&oCoedge));
	}
	return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPolyhedralFace( gfc::engine::CWriter* pWriter, ggp::CPolyhedralFace* pSrc )
{
    assert(pSrc);
    GfcPolyhedralFace oDest;
    int nCount = pSrc->LoopCount();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addLoops(exportPolyhedralLoop(pWriter, pSrc->GetLoop(i)));
    }
    auto oPlaneCoef = pSrc->GetPlaneCoef();
    oDest.setPlane(exportPlaneCoef(pWriter, &oPlaneCoef));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPlaneCoef( gfc::engine::CWriter* pWriter, ggp::CPlaneCoef* pSrc )
{
    assert(pSrc);
    GfcPlaneCoef oDest;
    oDest.setA(pSrc->A);
    oDest.setB(pSrc->B);
    oDest.setC(pSrc->C);
    oDest.setD(pSrc->D);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPolyhedralLoop( gfc::engine::CWriter* pWriter, ggp::CPolyhedralLoop* pSrc )
{
    assert(pSrc);
    GfcPolyhedralLoop oDest;
    int nCount = pSrc->EdgeCount();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addEdges(exportPolyhedralEdge(pWriter, pSrc->GetEdge(i)));
    }
    return pWriter->writeEntity(&oDest);}

gfc::engine::EntityRef GfcGeometryExporter::exportPolyhedralEdge( gfc::engine::CWriter* pWriter, ggp::CPolyhedralEdge* pSrc )
{
    assert(pSrc);
    GfcPolyhedralEdge oDest;
    oDest.setStartVertexIndex(pSrc->StartVertex()->GetIndex());
    oDest.setEndVertexIndex(pSrc->EndVertex()->GetIndex());
    return pWriter->writeEntity(&oDest);
}

void GfcGeometryExporter::innerExportPolygon( gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc, GfcCommonPolygon* pDest )
{
    int nCount = pSrc->LoopCount();
    for (int i = 0; i < nCount; ++i)
    {
        pDest->addLoops(exportCoedgeList(pWriter, pSrc->GetLoop(i)));
    }
}

void GfcGeometryExporter::innerExportPolygonEx(gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc, GfcCommonPolygonEx* pDest)
{
	int nCount = pSrc->LoopCount();
	for (int i = 0; i < nCount; ++i)
	{
		pDest->addLoopExs(exportCoedgeListEx(pWriter, pSrc->GetLoop(i)));
	}
}

gfc::engine::EntityRef GfcGeometryExporter::exportRuledSurface( gfc::engine::CWriter* pWriter, ggp::CRuledSurface* pSrc )
{
    assert(pSrc);
    GfcRuledSurface oDest;
    oDest.setApexIndex(pSrc->ApexIndex());
    auto oRangeV = pSrc->GetRangeV();
    auto oRangeU = pSrc->GetRangeU();
    oDest.setRangeV(exportIntervald(pWriter, &oRangeV));
    oDest.setRangeU(exportIntervald(pWriter, &oRangeU));
    oDest.setDirectrix1(exportCurve3d(pWriter, pSrc->Directrix1()));
    oDest.setDirectrix2(exportCurve3d(pWriter, pSrc->Directrix2()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportImageCurve3d( gfc::engine::CWriter* pWriter, ggp::CImageCurve3d* pSrc )
{
    assert(pSrc);
    GfcImageCurve3d oDest;
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve()));
    oDest.setSurface(exportSurface(pWriter, pSrc->Surface()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportOffsetCurve2d( gfc::engine::CWriter* pWriter, ggp::COffsetCurve2d* pSrc )
{
    assert(pSrc);
    GfcOffsetCurve2d oDest;
    oDest.setOffDist(pSrc->OffsetDistance());
    oDest.setInitCurve(exportCurve2d(pWriter, pSrc->InitialCurve()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportVector3dCompact( gfc::engine::CWriter* pWriter, ggp::CVector3d* pSrc )
{
    assert(pSrc);
//    GfcVector3d oVector;
    if (pSrc->IsEqual(ggp::CVector3d(1.0, 0.0, 0.0)))
        return export100Vector3d(pWriter);
    if (pSrc->IsEqual(ggp::CVector3d(0.0, 1.0, 0.0)))
        return export010Vector3d(pWriter);
    if (pSrc->IsEqual(ggp::CVector3d(0.0, 0.0, 1.0)))
        return export001Vector3d(pWriter);
    if (pSrc->IsEqual(ggp::CVector3d(0.0, 0.0, 0.0)))
        return export000Vector3d(pWriter);
    return exportVector3d(pWriter, pSrc);
//     oVector.setX(pSrc->X);
//     oVector.setY(pSrc->Y);
//     oVector.setZ(pSrc->Z);
//     return pWriter->writeEntity(&oVector);
}

void GfcGeometryExporter::clean()
{
    m_nVec3d100 = -1;
    m_nVec3d010 = -1;
    m_nVec3d001 = -1;
    m_nVec3d000 = -1;
}

gfc::engine::EntityRef GfcGeometryExporter::export100Vector3d( gfc::engine::CWriter* pWriter )
{
    if (m_nVec3d100 == -1)
    {
        GfcVector3d oVec;
        oVec.setX(1.0);
        oVec.setY(0.0);
        oVec.setZ(0.0);
        m_nVec3d100 = pWriter->writeEntity(&oVec);
    }
    return m_nVec3d100;
}

gfc::engine::EntityRef GfcGeometryExporter::export010Vector3d( gfc::engine::CWriter* pWriter )
{
    if (m_nVec3d010 == -1)
    {
        GfcVector3d oVec;
        oVec.setX(0.0);
        oVec.setY(1.0);
        oVec.setZ(0.0);
        m_nVec3d010 = pWriter->writeEntity(&oVec);
    }
    return m_nVec3d010;
}

gfc::engine::EntityRef GfcGeometryExporter::export001Vector3d( gfc::engine::CWriter* pWriter )
{
    if (m_nVec3d001 == -1)
    {
        GfcVector3d oVec;
        oVec.setX(0.0);
        oVec.setY(0.0);
        oVec.setZ(1.0);
        m_nVec3d001 = pWriter->writeEntity(&oVec);
    }
    return m_nVec3d001;

}

gfc::engine::EntityRef GfcGeometryExporter::export000Vector3d( gfc::engine::CWriter* pWriter )
{
    if (m_nVec3d000 == -1)
    {
        GfcVector3d oVec;
        oVec.setX(0.0);
        oVec.setY(0.0);
        oVec.setZ(0.0);
        m_nVec3d000 = pWriter->writeEntity(&oVec);
    }
    return m_nVec3d000;
}



gfc::engine::EntityRef GfcGeometryExporter::exportSimplePolygon( gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc )
{
    GfcSimplePolygon oPolygon;
    int nLoopCount = pSrc->LoopCount();
    for (int i = 0; i < nLoopCount; ++i)
    {
        oPolygon.addLoops(exportSimpleLoop(pWriter, pSrc->GetLoop(i)));
    }
    return pWriter->writeEntity(&oPolygon);
}

bool GfcGeometryExporter::isSimplePolygon( ggp::CPolygon* pSrc )
{
    int nLoopCount = pSrc->LoopCount();
    for (int i = 0; i < nLoopCount; ++i)
    {
        ggp::CLoop* pLoop = pSrc->GetLoop(i); 
        int nCoedgeCount = pLoop->CoedgeCount();
        for (int j = 0; j < nCoedgeCount; ++j)
        {
            int nType = pLoop->GetCoedge(j)->Curve()->Type();
            if (!(nType == ggp::Line2dType || nType == ggp::Arc2dType) || (nCoedgeCount == 1 && nType == ggp::Arc2dType))
            {
                return false;
            }
        }
    }
    return true;
}

gfc::engine::EntityRef GfcGeometryExporter::exportSimpleLoop( gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc )
{
    GfcSimpleLoop oDest;
    int nCount = pSrc->CoedgeCount();
    for (int i = 0; i < nCount; ++i)
    {
        GfcSimpleVertex oVertex;
        ggp::CCurve2d* pCurve = pSrc->GetCurve(i);
        auto oStartPt = pCurve->StartPoint();
        oVertex.setPoint(exportVector2d(pWriter, &oStartPt));
        if (pCurve->Type() == ggp::Arc2dType)
        {
            ggp::CArc2d* pArc = dynamic_cast<ggp::CArc2d*>(pCurve);
            oVertex.setRadius(pArc->Radius());
            oVertex.setArcType((GfcArcType)_getArcType(pArc->GetBulge()));
        }
        oDest.addVertexes(pWriter->writeEntity(&oVertex));//.addCoedges(exportCurve2d(pWriter, pSrc->GetCurve(i)));
    }
    return pWriter->writeEntity(&oDest);
}
