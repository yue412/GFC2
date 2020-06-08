#ifndef GFCGEOMETRYEXPORTER_H
#define GFCGEOMETRYEXPORTER_H

#include "GfcEngine/Entity.h"
#include "GMath/GVec2.h"
#include "GMath/GVec3.h"
#include "GMath/GCoordinates2.h"
#include "GMath/GCoordinates3.h"
#include "GMath/GBox3.h"
#include "Geometry/Line2d.h"
#include "Geometry/Arc2d.h"
#include "Geometry/Ellipse2d.h"
#include "Geometry/NurbsCurve2d.h"
#include "Geometry/PreimageCurve2d.h"
#include "Geometry/SinCurve2d.h"
#include "Geometry/SpiralLine2d.h"
#include "Geometry/Surface.h"
#include "Geometry/Curve3d.h"
#include "Geometry/Arc3d.h"
#include "Geometry/Line3d.h"
#include "Geometry/Ellipse3d.h"
#include "Geometry/NurbsCurve3d.h"
#include "Geometry/IntersectionCurve3d.h"
#include "Geometry/SpiralLine.h"
#include "Geometry/SweepCurve3d.h"
#include "Geometry/Bevel.h"
#include "Geometry/Cylinder.h"
#include "Geometry/Helicoid.h"
#include "Geometry/NurbsSurface.h"
#include "Geometry/Plane.h"
#include "Geometry/Sphere.h"
#include "Geometry/Sweep.h"
#include "Geometry/Torus.h"
#include "Geometry/Body.h"
#include "Geometry/BrepBody.h"
#include "Geometry/CuboidBody.h"
#include "Geometry/ExtrudedBody.h"
#include "Geometry/PolyhedronBody.h"
#include "Geometry/Face.h"
#include "Geometry/Edge.h"
#include "Geometry/Polygon.h"
#include "Geometry/CoedgeList.h"
#include "Geometry/PolyhedralFace.h"
#include "Geometry/PolyhedralLoop.h"
#include "Geometry/PolyhedralEdge.h"
#include "Geometry/OffsetCurve2d.h"
#include "Geometry/ImageCurve3d.h"
#include "Geometry/RuledSurface.h"
#include "Geometry/PlaneCurve3d.h"
#include "Gfc2CommonPolygonEx.h"
#include "Gfc2CommonPolygon.h"

namespace gfc {
    namespace engine {
        class CWriter;
    }
}

class Gfc2Polygon;
class Gfc2CommonPolygon;
class Gfc2Vector2d;

class GfcGeometryExporter
{
public:
    static void clean();
    static gfc::engine::EntityRef exportVector2d(gfc::engine::CWriter* pWriter, ggp::CVector2d* pSrc);
    //static void exportVector2d(ggp::CVector2d* pSrc, Gfc2Vector2d* pDest);
    static gfc::engine::EntityRef exportVector3d(gfc::engine::CWriter* pWriter, ggp::CVector3d* pSrc);
    static gfc::engine::EntityRef exportVector3dCompact(gfc::engine::CWriter* pWriter, ggp::CVector3d* pSrc);
    static gfc::engine::EntityRef exportIntervald(gfc::engine::CWriter* pWriter, ggp::CIntervald* pSrc);
    static gfc::engine::EntityRef exportCoordinates3d(gfc::engine::CWriter* pWriter, ggp::CCoordinates3d* pSrc);
    static gfc::engine::EntityRef exportCoordinates2d(gfc::engine::CWriter* pWriter, ggp::CCoordinates2d* pSrc);
    static gfc::engine::EntityRef exportBox3d(gfc::engine::CWriter* pWriter, ggp::CBox3d* pSrc);

    static gfc::engine::EntityRef exportLine2d(gfc::engine::CWriter* pWriter, ggp::CLine2d* pSrc);
    static gfc::engine::EntityRef exportArc2d(gfc::engine::CWriter* pWriter, ggp::CArc2d* pSrc);
    static gfc::engine::EntityRef exportEllipse2d(gfc::engine::CWriter* pWriter, ggp::CEllipse2d* pSrc);
    static gfc::engine::EntityRef exportNurbsCurve2d(gfc::engine::CWriter* pWriter, ggp::CNurbsCurve2d* pSrc);
    static gfc::engine::EntityRef exportPreimageCurve2d(gfc::engine::CWriter* pWriter, ggp::CPreimageCurve2d* pSrc);
    static gfc::engine::EntityRef exportSinCurve2d(gfc::engine::CWriter* pWriter, ggp::CSinCurve2d* pSrc);
    static gfc::engine::EntityRef exportSpiralLine2d(gfc::engine::CWriter* pWriter, ggp::CSpiralLine2d* pSrc);
    static gfc::engine::EntityRef exportOffsetCurve2d(gfc::engine::CWriter* pWriter, ggp::COffsetCurve2d* pSrc);
    static gfc::engine::EntityRef exportCurve2d(gfc::engine::CWriter* pWriter, ggp::CCurve2d* pSrc);

    static gfc::engine::EntityRef exportLine3d(gfc::engine::CWriter* pWriter, ggp::CLine3d* pSrc);
	//static gfc::engine::EntityRef exportArc3d(gfc::engine::Writer* pWriter, ggp::CArc3d* pSrc);
	//static gfc::engine::EntityRef exportEllipse3d(gfc::engine::Writer* pWriter, ggp::CEllipse3d* pSrc);
	static gfc::engine::EntityRef exportPlaneCurve3d( gfc::engine::CWriter* pWriter, ggp::CPlaneCurve3d* pSrc );
	static gfc::engine::EntityRef exportNurbsCurve3d(gfc::engine::CWriter* pWriter, ggp::CNurbsCurve3d* pSrc);
    static gfc::engine::EntityRef exportIntersectionCurve3d(gfc::engine::CWriter* pWriter, ggp::CIntersectionCurve3d* pSrc);
    static gfc::engine::EntityRef exportSpiralLine3d(gfc::engine::CWriter* pWriter, ggp::CSpiralLine* pSrc);
    static gfc::engine::EntityRef exportSweepCurve3d(gfc::engine::CWriter* pWriter, ggp::CSweepCurve3d* pSrc);
    static gfc::engine::EntityRef exportImageCurve3d(gfc::engine::CWriter* pWriter, ggp::CImageCurve3d* pSrc);
    static gfc::engine::EntityRef exportCurve3d(gfc::engine::CWriter* pWriter, ggp::CCurve3d* pSrc);

    static gfc::engine::EntityRef exportBevel(gfc::engine::CWriter* pWriter, ggp::CBevel* pSrc);
    static gfc::engine::EntityRef exportCylinder(gfc::engine::CWriter* pWriter, ggp::CCylinder* pSrc);
    static gfc::engine::EntityRef exportHelicoid(gfc::engine::CWriter* pWriter, ggp::CHelicoid* pSrc);
    static gfc::engine::EntityRef exportNurbsSurface(gfc::engine::CWriter* pWriter, ggp::CNurbsSurface* pSrc);
    static gfc::engine::EntityRef exportPlane(gfc::engine::CWriter* pWriter, ggp::CPlane* pSrc);
    static gfc::engine::EntityRef exportSphere(gfc::engine::CWriter* pWriter, ggp::CSphere* pSrc);
    static gfc::engine::EntityRef exportSweep(gfc::engine::CWriter* pWriter, ggp::CSweep* pSrc);
    static gfc::engine::EntityRef exportTorus(gfc::engine::CWriter* pWriter, ggp::CTorus* pSrc);
    static gfc::engine::EntityRef exportRuledSurface(gfc::engine::CWriter* pWriter, ggp::CRuledSurface* pSrc);
    static gfc::engine::EntityRef exportSurface(gfc::engine::CWriter* pWriter, ggp::CSurface* pSrc);

    static gfc::engine::EntityRef exportBrepBody(gfc::engine::CWriter* pWriter, ggp::CBrepBody* pSrc);
    static gfc::engine::EntityRef exportCuboidBody(gfc::engine::CWriter* pWriter, ggp::CCuboidBody* pSrc);
    static gfc::engine::EntityRef exportExtrudedBody(gfc::engine::CWriter* pWriter, ggp::CExtrudedBody* pSrc);
    static gfc::engine::EntityRef exportPolyhedronBody(gfc::engine::CWriter* pWriter, ggp::CPolyhedronBody* pSrc);
    static gfc::engine::EntityRef exportBody(gfc::engine::CWriter* pWriter, ggp::CBody* pSrc);
    static gfc::engine::EntityRef exportPolygon(gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc);
    static gfc::engine::EntityRef exportSimplePolygon(gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc);
private:
    static bool isSimplePolygon(ggp::CPolygon* pSrc);

    static gfc::engine::EntityRef exportNurbsCtrlPt2d(gfc::engine::CWriter* pWriter, ggp::NurbsCtrlPt2d* pSrc);
    static gfc::engine::EntityRef exportNurbsCtrlPt3d(gfc::engine::CWriter* pWriter, ggp::NurbsCtrlPt3d* pSrc);
    static gfc::engine::EntityRef exportInternalChart(gfc::engine::CWriter* pWriter, ggp::CInternalChart* pSrc);
    static gfc::engine::EntityRef exportInternalPt(gfc::engine::CWriter* pWriter, ggp::CInternalPt* pSrc);
    static gfc::engine::EntityRef exportPlaneInfo(gfc::engine::CWriter* pWriter, ggp::CVector3d* pDirX, ggp::CVector3d* pDirY, ggp::CVector3d* pPos);

    static gfc::engine::EntityRef exportFace(gfc::engine::CWriter* pWriter, ggp::CFace* pSrc);
    static gfc::engine::EntityRef exportEdge(gfc::engine::CWriter* pWriter, ggp::CEdge* pSrc);
    static gfc::engine::EntityRef exportCoedgeList(gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc);
	static gfc::engine::EntityRef exportCoedgeListEx( gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc );
	static gfc::engine::EntityRef exportSimpleLoop(gfc::engine::CWriter* pWriter, ggp::CCoedgeList* pSrc);
    static gfc::engine::EntityRef exportPolyhedralFace(gfc::engine::CWriter* pWriter, ggp::CPolyhedralFace* pSrc);
    static gfc::engine::EntityRef exportPlaneCoef(gfc::engine::CWriter* pWriter, ggp::CPlaneCoef* pSrc);
    static gfc::engine::EntityRef exportPolyhedralLoop(gfc::engine::CWriter* pWriter, ggp::CPolyhedralLoop* pSrc);
    static gfc::engine::EntityRef exportPolyhedralEdge(gfc::engine::CWriter* pWriter, ggp::CPolyhedralEdge* pSrc);
    static void innerExportPolygon(gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc, Gfc2CommonPolygon* pDest);
	static void innerExportPolygonEx(gfc::engine::CWriter* pWriter, ggp::CPolygon* pSrc, Gfc2CommonPolygonEx* oDest);
    static gfc::engine::EntityRef export100Vector3d(gfc::engine::CWriter* pWriter);
    static gfc::engine::EntityRef export010Vector3d(gfc::engine::CWriter* pWriter);
    static gfc::engine::EntityRef export001Vector3d(gfc::engine::CWriter* pWriter);
    static gfc::engine::EntityRef export000Vector3d(gfc::engine::CWriter* pWriter);
    static gfc::engine::EntityRef m_nVec3d100;
    static gfc::engine::EntityRef m_nVec3d010;
    static gfc::engine::EntityRef m_nVec3d001;
    static gfc::engine::EntityRef m_nVec3d000;
};

#endif
