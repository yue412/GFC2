#include "GfcUtils/GfcGeometryExporter.h"
#include "GMath/GMathNurbs.h"
#include "Geometry/Loop.h"
#include "Geometry/Coedge.h"
#include "Geometry/CoedgeEx.h"
#include "GfcClasses\x3\Gfc2Vector2d.h"
#include "GfcClasses\x3\Gfc2Vector3d.h"
#include "GfcClasses\x3\Gfc2Intervald.h"
#include "GfcClasses\x3\Gfc2Coordinates3d.h"
#include "GfcClasses\x3\Gfc2Coordinates2d.h"
#include "GfcClasses\x3\Gfc2Box3d.h"
#include "GfcClasses\x3\Gfc2Line2d.h"
#include "GfcClasses\x3\Gfc2Arc2d.h"
#include "GfcClasses\x3\Gfc2NurbsCurve2d.h"
#include "GfcClasses\x3\Gfc2NurbsCtrlPt2d.h"
#include "GfcClasses\x3\Gfc2Ellipse2d.h"
#include "GfcClasses\x3\Gfc2PreimageCurve2d.h"
#include "GfcClasses\x3\Gfc2SinCurve2d.h"
#include "GfcClasses\x3\Gfc2SpiralLine2d.h"
#include "GfcClasses\x3\Gfc2Line3d.h"
#include "GfcClasses\x3\Gfc2Arc3d.h"
#include "GfcClasses\x3\Gfc2Ellipse3d.h"
#include "GfcClasses\x3\Gfc2NurbsCtrlPt3d.h"
#include "GfcClasses\x3\Gfc2NurbsCurve3d.h"
#include "GfcClasses\x3\Gfc2IntersectionCurve3d.h"
#include "GfcClasses\x3\Gfc2SpiralLine3d.h"
#include "GfcClasses\x3\Gfc2SweepCurve3d.h"
#include "GfcClasses\x3\Gfc2Bevel.h"
#include "GfcClasses\x3\Gfc2Cylinder.h"
#include "GfcClasses\x3\Gfc2Helicoid.h"
#include "GfcClasses\x3\Gfc2NurbsSurface.h"
#include "GfcClasses\x3\Gfc2Plane.h"
#include "GfcClasses\x3\Gfc2Sphere.h"
#include "GfcClasses\x3\Gfc2Sweep.h"
#include "GfcClasses\x3\Gfc2Torus.h"
#include "GfcClasses\x3\Gfc2BrepBody.h"
#include "GfcClasses\x3\Gfc2CuboidBody.h"
#include "GfcClasses\x3\Gfc2ExtrudedBody.h"
#include "GfcClasses\x3\Gfc2PolyhedronBody.h"
#include "GfcClasses\x3\Gfc2Face.h"
#include "GfcClasses\x3\Gfc2Edge.h"
#include "GfcClasses\x3\Gfc2Polygon.h"
#include "GfcClasses\x3\Gfc2CoedgeList.h"
#include "GfcClasses\x3\Gfc2PolyhedralFace.h"
#include "GfcClasses\x3\Gfc2PlaneCoef.h"
#include "GfcClasses\x3\Gfc2PolyhedralLoop.h"
#include "GfcClasses\x3\Gfc2PolyhedralEdge.h"
#include "GfcClasses\x3\Gfc2OffsetCurve2d.h"
#include "GfcClasses\x3\Gfc2ImageCurve3d.h"
#include "GfcClasses\x3\Gfc2RuledSurface.h"
#include "GfcClasses\x3\Gfc2SimplePolygon.h"
#include "GfcClasses\x3\Gfc2PlaneCurve3d.h"
#include "GfcClasses\x3\Gfc2CoedgeListEx.h"
#include "GfcClasses\x3\Gfc2Coedge.h"
#include "GfcEngine\Writer.h"
#include "GfcClasses\x3\Gfc2CommonPolygonEx.h"
#include "GfcClasses\x3\Gfc2CommonPolygon.h"

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
    Gfc2Vector2d oVector2d;
    oVector2d.setX(pSrc->X);
    oVector2d.setY(pSrc->Y);
    return pWriter->writeEntity(&oVector2d);
}

// void GfcGeometryExporter::exportVector2d( ggp::CVector2d* pSrc, Gfc2Vector2d* pDest )
// {
//     pDest->setX(pSrc->X);
//     pDest->setY(pSrc->Y);
// }

gfc::engine::EntityRef GfcGeometryExporter::exportVector3d( gfc::engine::CWriter* pWriter, ggp::CVector3d* pSrc )
{
    assert(pSrc);
    Gfc2Vector3d oVector;
    oVector.setX(pSrc->X);
    oVector.setY(pSrc->Y);
    oVector.setZ(pSrc->Z);
    return pWriter->writeEntity(&oVector);
}

gfc::engine::EntityRef GfcGeometryExporter::exportIntervald( gfc::engine::CWriter* pWriter, ggp::CIntervald* pSrc )
{
    assert(pSrc);
    Gfc2Intervald oDest;
    oDest.setMin(pSrc->Min);
    oDest.setMax(pSrc->Max);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCoordinates3d( gfc::engine::CWriter* pWriter, ggp::CCoordinates3d* pSrc )
{
    assert(pSrc);
    Gfc2Coordinates3d oDest;
    oDest.setOrigin(exportVector3dCompact(pWriter, &pSrc->Origin));
    oDest.setX(exportVector3dCompact(pWriter, &pSrc->X));
    oDest.setY(exportVector3dCompact(pWriter, &pSrc->Y));
    oDest.setZ(exportVector3dCompact(pWriter, &pSrc->Z));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCoordinates2d( gfc::engine::CWriter* pWriter, ggp::CCoordinates2d* pSrc )
{
    assert(pSrc);
    Gfc2Coordinates2d oDest;
    oDest.setOrigin(exportVector2d(pWriter, &pSrc->Origin));
    oDest.setX(exportVector2d(pWriter, &pSrc->X));
    oDest.setY(exportVector2d(pWriter, &pSrc->Y));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportBox3d( gfc::engine::CWriter* pWriter, ggp::CBox3d* pSrc )
{
    assert(pSrc);
    Gfc2Box3d oDest;
    oDest.setMin(exportVector3d(pWriter, &pSrc->MinPt()));
    oDest.setMax(exportVector3d(pWriter, &pSrc->MaxPt()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportLine2d( gfc::engine::CWriter* pWriter, ggp::CLine2d* pSrc )
{
    assert(pSrc);
    Gfc2Line2d oDest;
    oDest.setStartPt(exportVector2d(pWriter, &pSrc->StartPoint()));
    oDest.setEndPt(exportVector2d(pWriter, &pSrc->EndPoint()));
//    oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportArc2d( gfc::engine::CWriter* pWriter, ggp::CArc2d* pSrc )
{
    assert(pSrc);
    Gfc2Arc2d oDest;
    oDest.setCenterPt(exportVector2d(pWriter, &pSrc->CenterPt()));
    oDest.setRadius(pSrc->Radius());
    oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    oDest.setClockSign(pSrc->ClockSign());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportEllipse2d( gfc::engine::CWriter* pWriter, ggp::CEllipse2d* pSrc )
{
    assert(pSrc);
    Gfc2Ellipse2d oDest;
    oDest.setCenterPt(exportVector2d(pWriter, &pSrc->CenterPt()));
    oDest.setMajorAxis(exportVector2d(pWriter, &pSrc->MajorAxis()));
    oDest.setdMajorRad(pSrc->MajorRadius());
    oDest.setdMinorRad(pSrc->MinorRadius());
    oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    oDest.setClockSign(pSrc->ClockSign());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsCurve2d( gfc::engine::CWriter* pWriter, ggp::CNurbsCurve2d* pSrc )
{
    assert(pSrc);
    Gfc2NurbsCurve2d oDest;
    oDest.setDegree(pSrc->Degree());
    int nCount = pSrc->CtrlPtCount();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addCtrlPts(exportNurbsCtrlPt2d(pWriter, &pSrc->CtrlPt(i)));
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
    Gfc2NurbsCtrlPt2d oDest;
    oDest.setPoint(exportVector2d(pWriter, &pSrc->Point));
    oDest.setWeight(pSrc->Weight);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPreimageCurve2d( gfc::engine::CWriter* pWriter, ggp::CPreimageCurve2d* pSrc )
{
    assert(pSrc);
    Gfc2PreimageCurve2d oDest;
    oDest.setRange(exportIntervald(pWriter, const_cast<ggp::CIntervald*>(&pSrc->Range())));
    oDest.setReversed(pSrc->Reversed());
    oDest.setBase(exportSurface(pWriter, pSrc->GetBaseSurface().get()));
    oDest.setCurve(exportCurve3d(pWriter, pSrc->GetBaseCurve().get()));
    oDest.setTolerance(pSrc->Tolerance()); // can not get
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSinCurve2d( gfc::engine::CWriter* pWriter, ggp::CSinCurve2d* pSrc )
{
    assert(pSrc);
    Gfc2SinCurve2d oDest;
    oDest.setPos(exportVector2d(pWriter, &pSrc->Pos()));
    oDest.setDirX(exportVector2d(pWriter, &pSrc->DirX()));
    oDest.setA(pSrc->A());
    oDest.setB(pSrc->B());
    oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    oDest.setClockSign(pSrc->ClockSign());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSpiralLine2d( gfc::engine::CWriter* pWriter, ggp::CSpiralLine2d* pSrc )
{
    assert(pSrc);
    Gfc2SpiralLine2d oDest;
    oDest.setCoord(exportCoordinates2d(pWriter, &pSrc->Coord()));
    oDest.setRadius(pSrc->Radius());
    oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
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
    case Line2dType:
        return exportLine2d(pWriter, dynamic_cast<ggp::CLine2d*>(pSrc));
    case Arc2dType:
        return exportArc2d(pWriter, dynamic_cast<ggp::CArc2d*>(pSrc));
    case NurbsCurve2dType:
        return exportNurbsCurve2d(pWriter, dynamic_cast<ggp::CNurbsCurve2d*>(pSrc));
    case Ellipse2dType:
        return exportEllipse2d(pWriter, dynamic_cast<ggp::CEllipse2d*>(pSrc));
    case SinCurve2dType:
        return exportSinCurve2d(pWriter, dynamic_cast<ggp::CSinCurve2d*>(pSrc));
    case SpiralLine2dType:
        return exportSpiralLine2d(pWriter, dynamic_cast<ggp::CSpiralLine2d*>(pSrc));
    case PreimageCurve2dType:
        return exportPreimageCurve2d(pWriter, dynamic_cast<ggp::CPreimageCurve2d*>(pSrc));
    case OffsetCurve2dType:
        return exportOffsetCurve2d(pWriter, dynamic_cast<ggp::COffsetCurve2d*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportLine3d( gfc::engine::CWriter* pWriter, ggp::CLine3d* pSrc )
{
    assert(pSrc);
    Gfc2Line3d oDest;
    oDest.setStartPt(exportVector3d(pWriter, &pSrc->StartPoint()));
    oDest.setEndPt(exportVector3d(pWriter, &pSrc->EndPoint()));
    //oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    return pWriter->writeEntity(&oDest);
}

//gfc::engine::EntityRef GfcGeometryExporter::exportArc3d( gfc::engine::Writer* pWriter, ggp::CArc3d* pSrc )
//{
//	assert(pSrc);
//	Gfc2Arc3d oDest;
//	oDest.setArc(exportCurve2d(pWriter, pSrc->Curve2d()));    
//	oDest.setPlane(exportPlaneInfo(pWriter, &pSrc->DirX(), &pSrc->DirY(), &pSrc->Pos()));
//	return pWriter->writeEntity(&oDest);
//}
//
//gfc::engine::EntityRef GfcGeometryExporter::exportEllipse3d( gfc::engine::Writer* pWriter, ggp::CEllipse3d* pSrc )
//{
//	assert(pSrc);
//	Gfc2Ellipse3d oDest;
//	oDest.setEllipse(exportCurve2d(pWriter, pSrc->Curve2d()));    
//	oDest.setPlane(exportPlaneInfo(pWriter, &pSrc->DirX(), &pSrc->DirY(), &pSrc->Pos()));
//	return pWriter->writeEntity(&oDest);
//}

gfc::engine::EntityRef GfcGeometryExporter::exportPlaneCurve3d( gfc::engine::CWriter* pWriter, ggp::CPlaneCurve3d* pSrc )
{
	assert(pSrc);
	Gfc2PlaneCurve3d oDest;
	oDest.setPlaneCurve(exportCurve2d(pWriter, pSrc->Curve2d()));    
	oDest.setPlane(exportPlaneInfo(pWriter, (ggp::CVector3d*)&pSrc->DirX(), (ggp::CVector3d*)&pSrc->DirY(), (ggp::CVector3d*)&pSrc->Pos()));
	return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsCurve3d( gfc::engine::CWriter* pWriter, ggp::CNurbsCurve3d* pSrc )
{
    assert(pSrc);
    Gfc2NurbsCurve3d oDest;
    oDest.setDegree(pSrc->Degree());
    int nCount = pSrc->CtrlPtCount();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addCtrlPts(exportNurbsCtrlPt3d(pWriter, &pSrc->CtrlPt(i)));
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
    Gfc2IntersectionCurve3d oDest;
    ggp::CSurfacePtr pBases[2];
    pSrc->GetBaseSurfaces(pBases);
    oDest.setBases1(exportSurface(pWriter, pBases[0].get()));
    oDest.setBases2(exportSurface(pWriter, pBases[1].get()));
    oDest.setRange(exportIntervald(pWriter, const_cast<ggp::CIntervald*>(&pSrc->Range())));
    oDest.setChart(exportInternalChart(pWriter, const_cast<ggp::CInternalChart*>(&pSrc->Chart())));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSpiralLine3d( gfc::engine::CWriter* pWriter, ggp::CSpiralLine* pSrc )
{
    assert(pSrc);
    Gfc2SpiralLine3d oDest;
    oDest.setCoord(exportCoordinates3d(pWriter, &pSrc->Coord()));
    oDest.setRadius(pSrc->Radius());
    oDest.setRange(exportIntervald(pWriter, &pSrc->Range()));
    oDest.setClockSign(pSrc->ClockSign());
    oDest.setRadiusCoef(pSrc->RadiusCoef());
    oDest.setHeightCoef(pSrc->HeightCoef());
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSweepCurve3d( gfc::engine::CWriter* pWriter, ggp::CSweepCurve3d* pSrc )
{
    assert(pSrc);
    Gfc2SweepCurve3d oDest;
    oDest.setSpine3d(exportCurve3d(pWriter, pSrc->Spine()));
    oDest.setReferenceVector(exportVector3d(pWriter, const_cast<ggp::CVector3d*>(&pSrc->GetReferenceVector())));
    oDest.setPoint(exportVector2d(pWriter, const_cast<ggp::CVector2d*>(&pSrc->Profile())));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCurve3d( gfc::engine::CWriter* pWriter, ggp::CCurve3d* pSrc )
{
    switch (pSrc->Type())
    {
    case Line3dType:
        return exportLine3d(pWriter, dynamic_cast<ggp::CLine3d*>(pSrc));
    case NurbsCurve3dType:
        return exportNurbsCurve3d(pWriter, dynamic_cast<ggp::CNurbsCurve3d*>(pSrc));
    case PlaneCurve3dType:
		return exportPlaneCurve3d(pWriter, dynamic_cast<ggp::CPlaneCurve3d*>(pSrc));
    case SpiralLineType:
        return exportSpiralLine3d(pWriter, dynamic_cast<ggp::CSpiralLine*>(pSrc));
    case SweepCurve3dType:
        return exportSweepCurve3d(pWriter, dynamic_cast<ggp::CSweepCurve3d*>(pSrc));
    case IntersectionCurve3dType:
        return exportIntersectionCurve3d(pWriter, dynamic_cast<ggp::CIntersectionCurve3d*>(pSrc));
    case ImageCurve3dType:
        return exportImageCurve3d(pWriter, dynamic_cast<ggp::CImageCurve3d*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsCtrlPt3d( gfc::engine::CWriter* pWriter, ggp::NurbsCtrlPt3d* pSrc )
{
    assert(pSrc);
    Gfc2NurbsCtrlPt3d oDest;
    oDest.setPoint(exportVector3d(pWriter, &pSrc->Point));
    oDest.setWeight(pSrc->Weight);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportInternalChart( gfc::engine::CWriter* pWriter, ggp::CInternalChart* pSrc )
{
    assert(pSrc);
    Gfc2InternalChart oDest;
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
    Gfc2InternalPt oDest;
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
    Gfc2PlaneInfo oDest;
    oDest.setDirX(exportVector3d(pWriter, pDirX));
    oDest.setDirY(exportVector3d(pWriter, pDirY));
    oDest.setPos(exportVector3d(pWriter, pPos));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportBevel( gfc::engine::CWriter* pWriter, ggp::CBevel* pSrc )
{
    assert(pSrc);
    Gfc2Bevel oDest;
    ggp::CCoordinates3d pSrc1 = pSrc->Coord();
    oDest.setCoord(exportCoordinates3d(pWriter, &pSrc1));
    oDest.setHeight(pSrc->Height());
    oDest.setRangeV(exportIntervald(pWriter, &pSrc->RangeV()));
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCylinder( gfc::engine::CWriter* pWriter, ggp::CCylinder* pSrc )
{
    assert(pSrc);
    Gfc2Cylinder oDest;
    Gfc2Coordinates3d oCoord;
    oCoord.setX(exportVector3d(pWriter, &pSrc->DirX()));
    oCoord.setY(exportVector3d(pWriter, &pSrc->DirY()));
    oCoord.setZ(exportVector3d(pWriter, &pSrc->DirZ()));
    oCoord.setOrigin(exportVector3d(pWriter, &pSrc->Pos()));
    //oDest.setCoord(pWriter->writeEntity(&oCoord));
    oDest.setRangeV(exportIntervald(pWriter, &pSrc->RangeV()));
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportHelicoid( gfc::engine::CWriter* pWriter, ggp::CHelicoid* pSrc )
{
    assert(pSrc);
    Gfc2Helicoid oDest;
    oDest.setCoord(exportCoordinates3d(pWriter, &pSrc->Coord()));
    oDest.setRadius(pSrc->Radius());
    oDest.setRangeV(exportIntervald(pWriter, &pSrc->RangeV()));
    oDest.setClockSign(pSrc->ClockSign());
    oDest.setHeightCoef(pSrc->HeightCoef());
    oDest.setRadiusCoef(pSrc->RadiusCoef());
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportNurbsSurface( gfc::engine::CWriter* pWriter, ggp::CNurbsSurface* pSrc )
{
    assert(pSrc);
    Gfc2NurbsSurface oDest;
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
    Gfc2Plane oDest;
    oDest.setDirU(exportVector3d(pWriter, &pSrc->DirU()));
    oDest.setDirV(exportVector3d(pWriter, &pSrc->DirV()));
    oDest.setPos(exportVector3d(pWriter, &pSrc->Pos()));
    oDest.setRangeU(exportIntervald(pWriter, &pSrc->RangeU()));
    oDest.setRangeV(exportIntervald(pWriter, &pSrc->RangeV()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSphere( gfc::engine::CWriter* pWriter, ggp::CSphere* pSrc )
{
    assert(pSrc);
    Gfc2Sphere oDest;
    oDest.setCoords(exportCoordinates3d(pWriter, const_cast<ggp::CCoordinates3d*>(&pSrc->Coord())));
    oDest.setRadius(pSrc->Radius());
    oDest.setRangeV(exportIntervald(pWriter, &pSrc->RangeV()));
    oDest.setRangeU(exportIntervald(pWriter, &pSrc->RangeU()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSweep( gfc::engine::CWriter* pWriter, ggp::CSweep* pSrc )
{
    assert(pSrc);
    Gfc2Sweep oDest;
    oDest.setProfile(exportCurve2d(pWriter, pSrc->Profile()));
    oDest.setSpine3d(exportCurve3d(pWriter, pSrc->Spine()));
    oDest.setReferenceVector(exportVector3d(pWriter, const_cast<ggp::CVector3d*>(&pSrc->GetReferenceVector())));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportTorus( gfc::engine::CWriter* pWriter, ggp::CTorus* pSrc )
{
    assert(pSrc);
    Gfc2Torus oDest;
    oDest.setCoord(exportCoordinates3d(pWriter, &pSrc->Coord()));
    oDest.setRadius(pSrc->Radius());
    oDest.setClockSign(pSrc->ClockSign());
    oDest.setRangeV(exportIntervald(pWriter, &pSrc->RangeV()));
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve2d()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportSurface( gfc::engine::CWriter* pWriter, ggp::CSurface* pSrc )
{
    switch (pSrc->Type())
    {
    case PlaneType:
        return exportPlane(pWriter, dynamic_cast<ggp::CPlane*>(pSrc));
    case CylinderType:
        return exportCylinder(pWriter, dynamic_cast<ggp::CCylinder*>(pSrc));
    case NurbsSurfaceType:
        return exportNurbsSurface(pWriter, dynamic_cast<ggp::CNurbsSurface*>(pSrc));
    case BevelType:
        return exportBevel(pWriter, dynamic_cast<ggp::CBevel*>(pSrc));
    case TorusType:
        return exportTorus(pWriter, dynamic_cast<ggp::CTorus*>(pSrc));
    case SphereType:
        return exportSphere(pWriter, dynamic_cast<ggp::CSphere*>(pSrc));
    case HelicoidType:
        return exportHelicoid(pWriter, dynamic_cast<ggp::CHelicoid*>(pSrc));
    case SweepType:
        return exportSweep(pWriter, dynamic_cast<ggp::CSweep*>(pSrc));
    case RuledSurfaceType:
        return exportRuledSurface(pWriter, dynamic_cast<ggp::CRuledSurface*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportBrepBody( gfc::engine::CWriter* pWriter, ggp::CBrepBody* pSrc )
{
    assert(pSrc);
    Gfc2BrepBody oDest;
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
    Gfc2CuboidBody oDest;
    oDest.setCoordinate(exportCoordinates3d(pWriter, const_cast<ggp::CCoordinates3d*>(&pSrc->GetCoordinate())));
    oDest.setDimension(exportVector3d(pWriter, const_cast<ggp::CVector3d*>(&pSrc->GetDimension())));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportExtrudedBody( gfc::engine::CWriter* pWriter, ggp::CExtrudedBody* pSrc )
{
    assert(pSrc);
    Gfc2ExtrudedBody oDest;
    oDest.setCoordinate(exportCoordinates3d(pWriter, const_cast<ggp::CCoordinates3d*>(&pSrc->GetCoordinate())));
    oDest.setLen(pSrc->GetLength());
    oDest.setSection(exportPolygon(pWriter, pSrc->Section()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPolyhedronBody( gfc::engine::CWriter* pWriter, ggp::CPolyhedronBody* pSrc )
{
    assert(pSrc);
    Gfc2PolyhedronBody oDest;
    int nFaceCount = pSrc->FaceCount();
    for (int i = 0; i < nFaceCount; ++i)
    {
        oDest.addFaces(exportPolyhedralFace(pWriter, pSrc->GetFace(i)));
    }
    int nVertexCount = pSrc->VertexCount();
    for (int i = 0; i < nVertexCount; ++i)
    {
        oDest.addVertexes(exportVector3d(pWriter, const_cast<ggp::CVector3d*>(&pSrc->GetVertex(i)->GetPosition())));
    }
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportBody( gfc::engine::CWriter* pWriter, ggp::CBody* pSrc )
{
    switch (pSrc->Type())
    {
    case BrepBodyType:
        return exportBrepBody(pWriter, dynamic_cast<ggp::CBrepBody*>(pSrc));
    case CuboidBodyType:
        return exportCuboidBody(pWriter, dynamic_cast<ggp::CCuboidBody*>(pSrc));
    case ExtrudedBodyType:
        return exportExtrudedBody(pWriter, dynamic_cast<ggp::CExtrudedBody*>(pSrc));
    case PolyhedronType:
        return exportPolyhedronBody(pWriter, dynamic_cast<ggp::CPolyhedronBody*>(pSrc));
//     case TinyPolyhedronType:
//         return exportBrepBody(pWriter, dynamic_cast<ggp::CBrepBody*>(pSrc));
    default:
        assert(false);
        return -1;
    }
}

gfc::engine::EntityRef GfcGeometryExporter::exportFace( gfc::engine::CWriter* pWriter, ggp::CFace* pSrc )
{
    assert(pSrc);
    Gfc2Face oDest;
    oDest.setSurface(exportSurface(pWriter, pSrc->Surface()));
    oDest.setBox(exportBox3d(pWriter, &pSrc->Box3d()));
    oDest.setIndex(pSrc->Index());
    oDest.setSameDir(pSrc->SameDir());
    innerExportPolygonEx(pWriter, pSrc, &oDest);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportEdge( gfc::engine::CWriter* pWriter, ggp::CEdge* pSrc )
{
    assert(pSrc);
    Gfc2Edge oDest;
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
    Gfc2CommonPolygon oDest;
    innerExportPolygon(pWriter, pSrc, &oDest);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportCoedgeList( gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc )
{
    assert(pSrc);
    Gfc2CoedgeList oDest;
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
	Gfc2CoedgeListEx oDest;
	int nCount = pSrc->CoedgeCount();
	for (int i = 0; i < nCount; ++i)
	{
		Gfc2Coedge oCoedge;
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
    Gfc2PolyhedralFace oDest;
    int nCount = pSrc->LoopCount();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addLoops(exportPolyhedralLoop(pWriter, pSrc->GetLoop(i)));
    }
    oDest.setPlane(exportPlaneCoef(pWriter, &pSrc->GetPlaneCoef()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPlaneCoef( gfc::engine::CWriter* pWriter, ggp::CPlaneCoef* pSrc )
{
    assert(pSrc);
    Gfc2PlaneCoef oDest;
    oDest.setA(pSrc->A);
    oDest.setB(pSrc->B);
    oDest.setC(pSrc->C);
    oDest.setD(pSrc->D);
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportPolyhedralLoop( gfc::engine::CWriter* pWriter, ggp::CPolyhedralLoop* pSrc )
{
    assert(pSrc);
    Gfc2PolyhedralLoop oDest;
    int nCount = pSrc->EdgeCount();
    for (int i = 0; i < nCount; ++i)
    {
        oDest.addEdges(exportPolyhedralEdge(pWriter, pSrc->GetEdge(i)));
    }
    return pWriter->writeEntity(&oDest);}

gfc::engine::EntityRef GfcGeometryExporter::exportPolyhedralEdge( gfc::engine::CWriter* pWriter, ggp::CPolyhedralEdge* pSrc )
{
    assert(pSrc);
    Gfc2PolyhedralEdge oDest;
    oDest.setStartVertexIndex(pSrc->StartVertex()->GetIndex());
    oDest.setEndVertexIndex(pSrc->EndVertex()->GetIndex());
    return pWriter->writeEntity(&oDest);
}

void GfcGeometryExporter::innerExportPolygon( gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc, Gfc2CommonPolygon* pDest )
{
    int nCount = pSrc->LoopCount();
    for (int i = 0; i < nCount; ++i)
    {
        pDest->addLoops(exportCoedgeList(pWriter, pSrc->GetLoop(i)));
    }
}

void GfcGeometryExporter::innerExportPolygonEx(gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc, Gfc2CommonPolygonEx* pDest)
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
    Gfc2RuledSurface oDest;
    oDest.setApexIndex(pSrc->ApexIndex());
    oDest.setRangeV(exportIntervald(pWriter, &pSrc->GetRangeV()));
    oDest.setRangeU(exportIntervald(pWriter, &pSrc->GetRangeU()));
    oDest.setDirectrix1(exportCurve3d(pWriter, pSrc->Directrix1()));
    oDest.setDirectrix2(exportCurve3d(pWriter, pSrc->Directrix2()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportImageCurve3d( gfc::engine::CWriter* pWriter, ggp::CImageCurve3d* pSrc )
{
    assert(pSrc);
    Gfc2ImageCurve3d oDest;
    oDest.setCurve(exportCurve2d(pWriter, pSrc->Curve()));
    oDest.setSurface(exportSurface(pWriter, pSrc->Surface()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportOffsetCurve2d( gfc::engine::CWriter* pWriter, ggp::COffsetCurve2d* pSrc )
{
    assert(pSrc);
    Gfc2OffsetCurve2d oDest;
    oDest.setOffDist(pSrc->OffsetDistance());
    oDest.setInitCurve(exportCurve2d(pWriter, pSrc->InitialCurve()));
    return pWriter->writeEntity(&oDest);
}

gfc::engine::EntityRef GfcGeometryExporter::exportVector3dCompact( gfc::engine::CWriter* pWriter, ggp::CVector3d* pSrc )
{
    assert(pSrc);
//    Gfc2Vector3d oVector;
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
        Gfc2Vector3d oVec;
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
        Gfc2Vector3d oVec;
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
        Gfc2Vector3d oVec;
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
        Gfc2Vector3d oVec;
        oVec.setX(0.0);
        oVec.setY(0.0);
        oVec.setZ(0.0);
        m_nVec3d000 = pWriter->writeEntity(&oVec);
    }
    return m_nVec3d000;
}



gfc::engine::EntityRef GfcGeometryExporter::exportSimplePolygon( gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc )
{
    Gfc2SimplePolygon oPolygon;
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
            if (!(nType == Line2dType || nType == Arc2dType) || (nCoedgeCount == 1 && nType == Arc2dType))
            {
                return false;
            }
        }
    }
    return true;
}

gfc::engine::EntityRef GfcGeometryExporter::exportSimpleLoop( gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc )
{
    Gfc2SimpleLoop oDest;
    int nCount = pSrc->CoedgeCount();
    for (int i = 0; i < nCount; ++i)
    {
        Gfc2SimpleVertex oVertex;
        ggp::CCurve2d* pCurve = pSrc->GetCurve(i);
        oVertex.setPoint(exportVector2d(pWriter, &pCurve->StartPoint()));
        if (pCurve->Type() == Arc2dType)
        {
            ggp::CArc2d* pArc = dynamic_cast<ggp::CArc2d*>(pCurve);
            oVertex.setRadius(pArc->Radius());
            oVertex.setArcType((Gfc2ArcType)_getArcType(pArc->GetBulge()));
        }
        oDest.addVertexes(pWriter->writeEntity(&oVertex));//.addCoedges(exportCurve2d(pWriter, pSrc->GetCurve(i)));
    }
    return pWriter->writeEntity(&oDest);
}
