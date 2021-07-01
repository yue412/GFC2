#ifndef GFCGEOMETRYIMPORTER_H
#define GFCGEOMETRYIMPORTER_H

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
#include "Geometry/NurbsCurve2d.h"

namespace gfc {
    namespace engine {
        class CEntity;
    }
}

class GfcGeometryImporter
{
public:
    static ggp::CVector2d importVector2d(gfc::engine::CEntity* pSrc);
    static ggp::CVector3d importVector3d(gfc::engine::CEntity* pSrc);
    static ggp::CIntervald importIntervald(gfc::engine::CEntity* pSrc);
    static ggp::CCoordinates3d importCoordinates3d(gfc::engine::CEntity* pSrc);
    static ggp::CCoordinates2d importCoordinates2d(gfc::engine::CEntity* pSrc);
    static ggp::CBox3d importBox3d(gfc::engine::CEntity* pSrc);

    static ggp::CLine2d* importLine2d(gfc::engine::CEntity* pSrc);
    static ggp::CArc2d* importArc2d(gfc::engine::CEntity* pSrc);
    static ggp::CEllipse2d* importEllipse2d(gfc::engine::CEntity* pSrc);
    static ggp::CNurbsCurve2d* importNurbsCurve2d(gfc::engine::CEntity* pSrc);
	static ggp::CNurbsCurve2d* importHermiteCurve2d(gfc::engine::CEntity* pSrc);
	static ggp::CPreimageCurve2d* importPreimageCurve2d(gfc::engine::CEntity* pSrc);
    static ggp::CSinCurve2d* importSinCurve2d(gfc::engine::CEntity* pSrc);
    static ggp::CSpiralLine2d* importSpiralLine2d(gfc::engine::CEntity* pSrc);
    static ggp::COffsetCurve2d* importOffsetCurve2d(gfc::engine::CEntity* pSrc);
    static ggp::CCurve2d* importCurve2d(gfc::engine::CEntity* pSrc);

    static ggp::CLine3d* importLine3d(gfc::engine::CEntity* pSrc);
    //static ggp::CArc3d* importArc3d(Gfc2Arc3d* pSrc);
    //static ggp::CEllipse3d* importEllipse3d(Gfc2Ellipse3d* pSrc);
	static ggp::CPlaneCurve3d* importPlaneCurve3d(gfc::engine::CEntity* pSrc );
	static ggp::CNurbsCurve3d* importNurbsCurve3d(gfc::engine::CEntity* pSrc);
    static ggp::CIntersectionCurve3d* importIntersectionCurve3d(gfc::engine::CEntity* pSrc);
    static ggp::CSpiralLine* importSpiralLine3d(gfc::engine::CEntity* pSrc);
    static ggp::CSweepCurve3d* importSweepCurve3d(gfc::engine::CEntity* pSrc);
    static ggp::CImageCurve3d* importImageCurve3d(gfc::engine::CEntity* pSrc);
    static ggp::CCurve3d* importCurve3d(gfc::engine::CEntity* pSrc);

    static ggp::CBevel* importBevel(gfc::engine::CEntity* pSrc);
    static ggp::CCylinder* importCylinder(gfc::engine::CEntity* pSrc);
    static ggp::CHelicoid* importHelicoid(gfc::engine::CEntity* pSrc);
    static ggp::CNurbsSurface* importNurbsSurface(gfc::engine::CEntity* pSrc);
    static ggp::CPlane* importPlane(gfc::engine::CEntity* pSrc);
    static ggp::CSphere* importSphere(gfc::engine::CEntity* pSrc);
    static ggp::CSweep* importSweep(gfc::engine::CEntity* pSrc);
    static ggp::CTorus* importTorus(gfc::engine::CEntity* pSrc);
    static ggp::CRuledSurface* importRuledSurface(gfc::engine::CEntity* pSrc);
    static ggp::CSurface* importSurface(gfc::engine::CEntity* pSrc);

    static ggp::CBrepBody* importBrepBody(gfc::engine::CEntity* pSrc);
    static ggp::CCuboidBody* importCuboidBody(gfc::engine::CEntity* pSrc);
    static ggp::CExtrudedBody* importExtrudedBody(gfc::engine::CEntity* pSrc);
    static ggp::CPolyhedronBody* importPolyhedronBody(gfc::engine::CEntity* pSrc);
    static ggp::CBody* importBody(gfc::engine::CEntity* pSrc);
    static ggp::CPolygon* importPolygon(gfc::engine::CEntity* pSrc);
private:
    static ggp::NurbsCtrlPt2d importNurbsCtrlPt2d(gfc::engine::CEntity* pSrc);
    static ggp::NurbsCtrlPt3d importNurbsCtrlPt3d(gfc::engine::CEntity* pSrc);
    static ggp::CInternalChart importInternalChart(gfc::engine::CEntity* pSrc);
    static ggp::CInternalPt importInternalPt(gfc::engine::CEntity* pSrc);
    //static glodon::objectbuf::EntityRef importPlaneInfo(ggp::CVector3d* pDirX, ggp::CVector3d* pDirY, ggp::CVector3d* pPos);

    static ggp::CFace* importFace(gfc::engine::CEntity* pSrc);
    static ggp::CEdge* importEdge(gfc::engine::CEntity* pSrc);
    //static ggp::CCoedgeList* importCoedgeList(Gfc2CoedgeList* pSrc);
    static ggp::CPolyhedralFace* importPolyhedralFace(gfc::engine::CEntity* pSrc, ggp::CPolyhedronBody* pBody);
    static ggp::CPlaneCoef importPlaneCoef(gfc::engine::CEntity* pSrc);
    static ggp::CPolyhedralLoop* importPolyhedralLoop(gfc::engine::CEntity* pSrc, ggp::CPolyhedralFace* pFace);
    static ggp::CPolyhedralEdge* importPolyhedralEdge(gfc::engine::CEntity* pSrc, ggp::CPolyhedralLoop* pLoop);
    static void innerImportPolygon(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest);
    static void innerImportSimplePolygon(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest);
    static void innerImportCommonPolygon(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest);
	static void innerImportCommonPolygonEx(gfc::engine::CEntity* pSrc, ggp::CPolygon* pDest);
};

#endif