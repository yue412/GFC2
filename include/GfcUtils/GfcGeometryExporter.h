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
        class Writer;
    }
}

class Gfc2Polygon;
class Gfc2CommonPolygon;
class Gfc2Vector2d;

class GfcGeometryExporter
{
public:
    static void clean();
    static gfc::engine::EntityRef exportVector2d(gfc::engine::Writer* pWriter, ggp::CVector2d* pSrc);
    //static void exportVector2d(ggp::CVector2d* pSrc, Gfc2Vector2d* pDest);
    static gfc::engine::EntityRef exportVector3d(gfc::engine::Writer* pWriter, ggp::CVector3d* pSrc);
    static gfc::engine::EntityRef exportVector3dCompact(gfc::engine::Writer* pWriter, ggp::CVector3d* pSrc);
    static gfc::engine::EntityRef exportIntervald(gfc::engine::Writer* pWriter, ggp::CIntervald* pSrc);
    static gfc::engine::EntityRef exportCoordinates3d(gfc::engine::Writer* pWriter, ggp::CCoordinates3d* pSrc);
    static gfc::engine::EntityRef exportCoordinates2d(gfc::engine::Writer* pWriter, ggp::CCoordinates2d* pSrc);
    static gfc::engine::EntityRef exportBox3d(gfc::engine::Writer* pWriter, ggp::CBox3d* pSrc);

    static gfc::engine::EntityRef exportLine2d(gfc::engine::Writer* pWriter, ggp::CLine2d* pSrc);
    static gfc::engine::EntityRef exportArc2d(gfc::engine::Writer* pWriter, ggp::CArc2d* pSrc);
    static gfc::engine::EntityRef exportEllipse2d(gfc::engine::Writer* pWriter, ggp::CEllipse2d* pSrc);
    static gfc::engine::EntityRef exportNurbsCurve2d(gfc::engine::Writer* pWriter, ggp::CNurbsCurve2d* pSrc);
    static gfc::engine::EntityRef exportPreimageCurve2d(gfc::engine::Writer* pWriter, ggp::CPreimageCurve2d* pSrc);
    static gfc::engine::EntityRef exportSinCurve2d(gfc::engine::Writer* pWriter, ggp::CSinCurve2d* pSrc);
    static gfc::engine::EntityRef exportSpiralLine2d(gfc::engine::Writer* pWriter, ggp::CSpiralLine2d* pSrc);
    static gfc::engine::EntityRef exportOffsetCurve2d(gfc::engine::Writer* pWriter, ggp::COffsetCurve2d* pSrc);
    static gfc::engine::EntityRef exportCurve2d(gfc::engine::Writer* pWriter, ggp::CCurve2d* pSrc);

    static gfc::engine::EntityRef exportLine3d(gfc::engine::Writer* pWriter, ggp::CLine3d* pSrc);
	//static gfc::engine::EntityRef exportArc3d(gfc::engine::Writer* pWriter, ggp::CArc3d* pSrc);
	//static gfc::engine::EntityRef exportEllipse3d(gfc::engine::Writer* pWriter, ggp::CEllipse3d* pSrc);
	static gfc::engine::EntityRef exportPlaneCurve3d( gfc::engine::Writer* pWriter, ggp::CPlaneCurve3d* pSrc );
	static gfc::engine::EntityRef exportNurbsCurve3d(gfc::engine::Writer* pWriter, ggp::CNurbsCurve3d* pSrc);
    static gfc::engine::EntityRef exportIntersectionCurve3d(gfc::engine::Writer* pWriter, ggp::CIntersectionCurve3d* pSrc);
    static gfc::engine::EntityRef exportSpiralLine3d(gfc::engine::Writer* pWriter, ggp::CSpiralLine* pSrc);
    static gfc::engine::EntityRef exportSweepCurve3d(gfc::engine::Writer* pWriter, ggp::CSweepCurve3d* pSrc);
    static gfc::engine::EntityRef exportImageCurve3d(gfc::engine::Writer* pWriter, ggp::CImageCurve3d* pSrc);
    static gfc::engine::EntityRef exportCurve3d(gfc::engine::Writer* pWriter, ggp::CCurve3d* pSrc);

    static gfc::engine::EntityRef exportBevel(gfc::engine::Writer* pWriter, ggp::CBevel* pSrc);
    static gfc::engine::EntityRef exportCylinder(gfc::engine::Writer* pWriter, ggp::CCylinder* pSrc);
    static gfc::engine::EntityRef exportHelicoid(gfc::engine::Writer* pWriter, ggp::CHelicoid* pSrc);
    static gfc::engine::EntityRef exportNurbsSurface(gfc::engine::Writer* pWriter, ggp::CNurbsSurface* pSrc);
    static gfc::engine::EntityRef exportPlane(gfc::engine::Writer* pWriter, ggp::CPlane* pSrc);
    static gfc::engine::EntityRef exportSphere(gfc::engine::Writer* pWriter, ggp::CSphere* pSrc);
    static gfc::engine::EntityRef exportSweep(gfc::engine::Writer* pWriter, ggp::CSweep* pSrc);
    static gfc::engine::EntityRef exportTorus(gfc::engine::Writer* pWriter, ggp::CTorus* pSrc);
    static gfc::engine::EntityRef exportRuledSurface(gfc::engine::Writer* pWriter, ggp::CRuledSurface* pSrc);
    static gfc::engine::EntityRef exportSurface(gfc::engine::Writer* pWriter, ggp::CSurface* pSrc);

    static gfc::engine::EntityRef exportBrepBody(gfc::engine::Writer* pWriter, ggp::CBrepBody* pSrc);
    static gfc::engine::EntityRef exportCuboidBody(gfc::engine::Writer* pWriter, ggp::CCuboidBody* pSrc);
    static gfc::engine::EntityRef exportExtrudedBody(gfc::engine::Writer* pWriter, ggp::CExtrudedBody* pSrc);
    static gfc::engine::EntityRef exportPolyhedronBody(gfc::engine::Writer* pWriter, ggp::CPolyhedronBody* pSrc);
    static gfc::engine::EntityRef exportBody(gfc::engine::Writer* pWriter, ggp::CBody* pSrc);
    static gfc::engine::EntityRef exportPolygon(gfc::engine::Writer* pWriter, ggp::CPolygon* pSrc);
    static gfc::engine::EntityRef exportSimplePolygon(gfc::engine::Writer* pWriter, ggp::CPolygon* pSrc);
private:
    static bool isSimplePolygon(ggp::CPolygon* pSrc);

    static gfc::engine::EntityRef exportNurbsCtrlPt2d(gfc::engine::Writer* pWriter, ggp::NurbsCtrlPt2d* pSrc);
    static gfc::engine::EntityRef exportNurbsCtrlPt3d(gfc::engine::Writer* pWriter, ggp::NurbsCtrlPt3d* pSrc);
    static gfc::engine::EntityRef exportInternalChart(gfc::engine::Writer* pWriter, ggp::CInternalChart* pSrc);
    static gfc::engine::EntityRef exportInternalPt(gfc::engine::Writer* pWriter, ggp::CInternalPt* pSrc);
    static gfc::engine::EntityRef exportPlaneInfo(gfc::engine::Writer* pWriter, ggp::CVector3d* pDirX, ggp::CVector3d* pDirY, ggp::CVector3d* pPos);

    static gfc::engine::EntityRef exportFace(gfc::engine::Writer* pWriter, ggp::CFace* pSrc);
    static gfc::engine::EntityRef exportEdge(gfc::engine::Writer* pWriter, ggp::CEdge* pSrc);
    static gfc::engine::EntityRef exportCoedgeList(gfc::engine::Writer* pWriter, ggp::CCoedgeList* pSrc);
	static gfc::engine::EntityRef exportCoedgeListEx( gfc::engine::Writer* pWriter, ggp::CCoedgeList* pSrc );
	static gfc::engine::EntityRef exportSimpleLoop(gfc::engine::Writer* pWriter, ggp::CCoedgeList* pSrc);
    static gfc::engine::EntityRef exportPolyhedralFace(gfc::engine::Writer* pWriter, ggp::CPolyhedralFace* pSrc);
    static gfc::engine::EntityRef exportPlaneCoef(gfc::engine::Writer* pWriter, ggp::CPlaneCoef* pSrc);
    static gfc::engine::EntityRef exportPolyhedralLoop(gfc::engine::Writer* pWriter, ggp::CPolyhedralLoop* pSrc);
    static gfc::engine::EntityRef exportPolyhedralEdge(gfc::engine::Writer* pWriter, ggp::CPolyhedralEdge* pSrc);
    static void innerExportPolygon(gfc::engine::Writer* pWriter, ggp::CPolygon* pSrc, Gfc2CommonPolygon* pDest);
	static void innerExportPolygonEx(gfc::engine::Writer* pWriter, ggp::CPolygon* pSrc, Gfc2CommonPolygonEx* oDest);
    static gfc::engine::EntityRef export100Vector3d(gfc::engine::Writer* pWriter);
    static gfc::engine::EntityRef export010Vector3d(gfc::engine::Writer* pWriter);
    static gfc::engine::EntityRef export001Vector3d(gfc::engine::Writer* pWriter);
    static gfc::engine::EntityRef export000Vector3d(gfc::engine::Writer* pWriter);
    static gfc::engine::EntityRef m_nVec3d100;
    static gfc::engine::EntityRef m_nVec3d010;
    static gfc::engine::EntityRef m_nVec3d001;
    static gfc::engine::EntityRef m_nVec3d000;
};

#endif
