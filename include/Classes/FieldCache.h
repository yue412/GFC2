#ifndef FIELDCACHE_H
#define FIELDCACHE_H

#include "GfcClasses.h"

class FieldCache
{
public:
    FieldCache():
        _Gfc2Shape_LocalCoordinate(0),
        _Gfc2Shape_BoundingBox(0),
        _Gfc2CustomLineShape_Width(0),
        _Gfc2CustomLineShape_LeftWidth(0),
        _Gfc2CustomLineShape_Line(0),
        _Gfc2CustomLineShape_E_S_Elevation(0),
        _Gfc2Entity_Type(0),
        _Gfc2Entity_Representations(0),
        _Gfc2Entity_Shapes(0),
        _Gfc2CustomPointShape_InsertPt(0),
        _Gfc2CustomPointShape_BaseInsertPt(0),
        _Gfc2CustomPointShape_Angle(0),
        _Gfc2CustomPointShape_MirrorFlag(0),
        _Gfc2SolidShape_Body(0),
        _Gfc2SolidShape_EdgeDatas(0),
        _Gfc2Shape2d_Elev(0),
        _Gfc2LineShape_Tilt(0),
        _Gfc2LineShape_StartPtHeight(0),
        _Gfc2LineShape_EndPtHeight(0),
        _Gfc2LineShape_ArcInfo(0),
        _Gfc2LineShape_IsSpiralTop(0),
        _Gfc2LineShape_IsSpiralBtm(0),
        _Gfc2SectionLineShape_Poly(0),
        _Gfc2SectionLineShape_BaseInsertPt(0),
        _Gfc2SectionLineShape_Angle(0),
        _Gfc2SectionLineShape_MirrorFlag(0),
        _Gfc2SectionLineShape_ArcInfo(0),
        _Gfc2SectionLineShape_IsSpiral(0),
        _Gfc2SectionPointShape_Poly(0),
        _Gfc2PointShape_Height(0),
        _Gfc2PointShape_ObliqueDir(0),
        _Gfc2PointShape_TopPoly(0),
        _Gfc2FaceShape_Thickness(0),
        _Gfc2FaceShape_Poly(0),
        _Gfc2FaceShape_MirrorFlag(0),
        _Gfc2FaceShape_FaceInfo(0),
        _Gfc2FaceShape2d_Poly(0),
        _Gfc2AssitAxis_AxisNo(0),
        _Gfc2AssitAxis_AxisNoPos(0),
        _Gfc2AssitAxis_TrimPoints(0),
        _Gfc2CartesianAxisGrid_InsertPt(0),
        _Gfc2CartesianAxisGrid_AxisAngle(0),
        _Gfc2CartesianAxisGrid_SKJ(0),
        _Gfc2CartesianAxisGrid_ZJS(0),
        _Gfc2CartesianAxisGrid_YJS(0),
        _Gfc2CartesianAxisGrid_XKJ(0),
        _Gfc2PolarAxisGrid_InsertPt(0),
        _Gfc2PolarAxisGrid_StartRadius(0),
        _Gfc2PolarAxisGrid_Clockwise(0),
        _Gfc2PolarAxisGrid_XKJ(0),
        _Gfc2PolarAxisGrid_ZJS(0),
        _Gfc2AxisDataItem_AxisNo(0),
        _Gfc2AxisDataItem_Distance(0),
        _Gfc2AxisDataItem_Level(0),
        _Gfc2AxisDataItem_AxisNoPos(0),
        _Gfc2AxisDataItem_TrimPoints(0),
        _Gfc2ParallelAssitAxis_RefAxisNo(0),
        _Gfc2ParallelAssitAxis_Offset(0),
        _Gfc2ParallelAssitAxis_RefAxisIndex(0),
        _Gfc2ParallelAssitAxis_RefAxisType(0),
        _Gfc2PointAngleAssitAxis_RefPoint(0),
        _Gfc2PointAngleAssitAxis_Angle(0),
        _Gfc2AxisAngleAssitAxis_RefAxisNo(0),
        _Gfc2AxisAngleAssitAxis_RefPoint(0),
        _Gfc2AxisAngleAssitAxis_Angle(0),
        _Gfc2AxisAngleAssitAxis_RefAxisIndex(0),
        _Gfc2AxisAngleAssitAxis_RefAxisType(0),
        _Gfc2PolarAngleAssitAxis_RefAxisNo(0),
        _Gfc2PolarAngleAssitAxis_Angle(0),
        _Gfc2PolarAngleAssitAxis_RefAxisIndex(0),
        _Gfc2ThreePointArcAssitAxis_RefPoint1(0),
        _Gfc2ThreePointArcAssitAxis_RefPoint2(0),
        _Gfc2ThreePointArcAssitAxis_RefPoint3(0),
        _Gfc2CenterStartEndArcAssitAxis_Center(0),
        _Gfc2CenterStartEndArcAssitAxis_StartPoint(0),
        _Gfc2CenterStartEndArcAssitAxis_EndPoint(0),
        _Gfc2CircleAssitAxis_Center(0),
        _Gfc2CircleAssitAxis_Radius(0),
        _Gfc2SizeMark_SizeMarkType(0),
        _Gfc2SizeMark_StartLine(0),
        _Gfc2SizeMark_EndLine(0),
        _Gfc2LineShape2d_Line(0),
        _Gfc2Object_ID(0),
        _Gfc2Object_Name(0),
        _Gfc2PropertySet_Identifier(0),
        _Gfc2PropertySet_HasProperties(0),
        _Gfc2Floor_FirstFloorFlag(0),
        _Gfc2Floor_Height(0),
        _Gfc2Floor_StdFloorCount(0),
        _Gfc2Floor_StructuralElevation(0),
        _Gfc2Floor_StartFloorNo(0),
        _Gfc2Floor_Remark(0),
        _Gfc2Property_Name(0),
        _Gfc2IntegerProperty_Value(0),
        _Gfc2DoubleProperty_Value(0),
        _Gfc2BooleanProperty_Value(0),
        _Gfc2StringProperty_Value(0),
        _Gfc2ObjectProperty_Value(0),
        _Gfc2RelDecomposes_RelatingObject(0),
        _Gfc2RelDecomposes_RelatedObjects(0),
        _Gfc2RelDefines_RelatedObjects(0),
        _Gfc2RelDefinesByProperties_RelatingPropertySet(0),
        _Gfc2Vector2d_X(0),
        _Gfc2Vector2d_Y(0),
        _Gfc2Vector3d_X(0),
        _Gfc2Vector3d_Y(0),
        _Gfc2Vector3d_Z(0),
        _Gfc2Intervald_Min(0),
        _Gfc2Intervald_Max(0),
        _Gfc2Coordinates3d_Origin(0),
        _Gfc2Coordinates3d_X(0),
        _Gfc2Coordinates3d_Y(0),
        _Gfc2Coordinates3d_Z(0),
        _Gfc2Coordinates2d_Origin(0),
        _Gfc2Coordinates2d_X(0),
        _Gfc2Coordinates2d_Y(0),
        _Gfc2Line2d_StartPt(0),
        _Gfc2Line2d_EndPt(0),
        _Gfc2Arc2d_CenterPt(0),
        _Gfc2Arc2d_Radius(0),
        _Gfc2Arc2d_Range(0),
        _Gfc2Arc2d_ClockSign(0),
        _Gfc2Ellipse2d_CenterPt(0),
        _Gfc2Ellipse2d_MajorAxis(0),
        _Gfc2Ellipse2d_dMajorRad(0),
        _Gfc2Ellipse2d_dMinorRad(0),
        _Gfc2Ellipse2d_Range(0),
        _Gfc2Ellipse2d_ClockSign(0),
        _Gfc2NurbsCurve2d_Degree(0),
        _Gfc2NurbsCurve2d_CtrlPts(0),
        _Gfc2NurbsCurve2d_Knots(0),
        _Gfc2PreimageCurve2d_Range(0),
        _Gfc2PreimageCurve2d_Reversed(0),
        _Gfc2PreimageCurve2d_Base(0),
        _Gfc2PreimageCurve2d_Curve(0),
        _Gfc2PreimageCurve2d_Tolerance(0),
        _Gfc2SinCurve2d_Pos(0),
        _Gfc2SinCurve2d_DirX(0),
        _Gfc2SinCurve2d_A(0),
        _Gfc2SinCurve2d_B(0),
        _Gfc2SinCurve2d_Range(0),
        _Gfc2SinCurve2d_ClockSign(0),
        _Gfc2SpiralLine2d_Coord(0),
        _Gfc2SpiralLine2d_Radius(0),
        _Gfc2SpiralLine2d_Range(0),
        _Gfc2SpiralLine2d_ClockSign(0),
        _Gfc2SpiralLine2d_RadiusCoef(0),
        _Gfc2NurbsCtrlPt2d_Point(0),
        _Gfc2NurbsCtrlPt2d_Weight(0),
        _Gfc2Line3d_StartPt(0),
        _Gfc2Line3d_EndPt(0),
        _Gfc2NurbsCurve3d_Degree(0),
        _Gfc2NurbsCurve3d_CtrlPts(0),
        _Gfc2NurbsCurve3d_Knots(0),
        _Gfc2IntersectionCurve3d_Bases1(0),
        _Gfc2IntersectionCurve3d_Bases2(0),
        _Gfc2IntersectionCurve3d_Range(0),
        _Gfc2IntersectionCurve3d_Chart(0),
        _Gfc2SpiralLine3d_Coord(0),
        _Gfc2SpiralLine3d_Radius(0),
        _Gfc2SpiralLine3d_Range(0),
        _Gfc2SpiralLine3d_ClockSign(0),
        _Gfc2SpiralLine3d_HeightCoef(0),
        _Gfc2SpiralLine3d_RadiusCoef(0),
        _Gfc2SweepCurve3d_Spine3d(0),
        _Gfc2SweepCurve3d_ReferenceVector(0),
        _Gfc2SweepCurve3d_Point(0),
        _Gfc2PlaneInfo_DirX(0),
        _Gfc2PlaneInfo_DirY(0),
        _Gfc2PlaneInfo_Pos(0),
        _Gfc2NurbsCtrlPt3d_Point(0),
        _Gfc2NurbsCtrlPt3d_Weight(0),
        _Gfc2InternalPt_P(0),
        _Gfc2InternalPt_TVec(0),
        _Gfc2InternalPt_T(0),
        _Gfc2InternalPt_UV(0),
        _Gfc2InternalPt_ST(0),
        _Gfc2InternalPt_UVDir(0),
        _Gfc2InternalPt_STDir(0),
        _Gfc2InternalChart_Tra1(0),
        _Gfc2InternalChart_Tra2(0),
        _Gfc2InternalChart_Tra3(0),
        _Gfc2InternalChart_IPS(0),
        _Gfc2Bevel_Coord(0),
        _Gfc2Bevel_Height(0),
        _Gfc2Bevel_RangeV(0),
        _Gfc2Bevel_Curve(0),
        _Gfc2Cylinder_Coord(0),
        _Gfc2Cylinder_RangeV(0),
        _Gfc2Cylinder_Curve(0),
        _Gfc2Helicoid_Coord(0),
        _Gfc2Helicoid_Radius(0),
        _Gfc2Helicoid_RangeV(0),
        _Gfc2Helicoid_ClockSign(0),
        _Gfc2Helicoid_HeightCoef(0),
        _Gfc2Helicoid_RadiusCoef(0),
        _Gfc2Helicoid_Curve(0),
        _Gfc2NurbsSurface_DegreeU(0),
        _Gfc2NurbsSurface_DegreeV(0),
        _Gfc2NurbsSurface_CtrlPtCountU(0),
        _Gfc2NurbsSurface_CtrlPtCountV(0),
        _Gfc2NurbsSurface_CtrlPts(0),
        _Gfc2NurbsSurface_KnotsU(0),
        _Gfc2NurbsSurface_KnotsV(0),
        _Gfc2Plane_Pos(0),
        _Gfc2Plane_DirU(0),
        _Gfc2Plane_DirV(0),
        _Gfc2Plane_RangeU(0),
        _Gfc2Plane_RangeV(0),
        _Gfc2Sphere_Radius(0),
        _Gfc2Sphere_Coords(0),
        _Gfc2Sphere_RangeU(0),
        _Gfc2Sphere_RangeV(0),
        _Gfc2Sweep_Profile(0),
        _Gfc2Sweep_Spine3d(0),
        _Gfc2Sweep_ReferenceVector(0),
        _Gfc2Torus_Coord(0),
        _Gfc2Torus_Radius(0),
        _Gfc2Torus_ClockSign(0),
        _Gfc2Torus_RangeV(0),
        _Gfc2Torus_Curve(0),
        _Gfc2BrepBody_Faces(0),
        _Gfc2BrepBody_Edges(0),
        _Gfc2CuboidBody_Coordinate(0),
        _Gfc2CuboidBody_Dimension(0),
        _Gfc2ExtrudedBody_Coordinate(0),
        _Gfc2ExtrudedBody_Length(0),
        _Gfc2ExtrudedBody_Section(0),
        _Gfc2PolyhedronBody_Faces(0),
        _Gfc2PolyhedronBody_Vertexes(0),
        _Gfc2CoedgeList_Coedges(0),
        _Gfc2Face_Surface(0),
        _Gfc2Face_Box(0),
        _Gfc2Face_SameDir(0),
        _Gfc2Face_Index(0),
        _Gfc2Edge_Curve(0),
        _Gfc2Edge_FaceIndex1(0),
        _Gfc2Edge_FaceIndex2(0),
        _Gfc2Edge_LoopIndex1(0),
        _Gfc2Edge_LoopIndex2(0),
        _Gfc2Edge_CoedgeIndex1(0),
        _Gfc2Edge_CoedgeIndex2(0),
        _Gfc2PolyhedralFace_Loops(0),
        _Gfc2PolyhedralFace_Plane(0),
        _Gfc2PlaneCoef_A(0),
        _Gfc2PlaneCoef_B(0),
        _Gfc2PlaneCoef_C(0),
        _Gfc2PlaneCoef_D(0),
        _Gfc2PolyhedralLoop_Edges(0),
        _Gfc2PolyhedralEdge_StartVertexIndex(0),
        _Gfc2PolyhedralEdge_EndVertexIndex(0),
        _Gfc2String_Value(0),
        _Gfc2Box3d_Min(0),
        _Gfc2Box3d_Max(0),
        _Gfc2OffsetCurve2d_OffDist(0),
        _Gfc2OffsetCurve2d_InitCurve(0),
        _Gfc2ImageCurve3d_Curve(0),
        _Gfc2ImageCurve3d_Surface(0),
        _Gfc2RuledSurface_ApexIndex(0),
        _Gfc2RuledSurface_RangeV(0),
        _Gfc2RuledSurface_RangeU(0),
        _Gfc2RuledSurface_Directrix1(0),
        _Gfc2RuledSurface_Directrix2(0),
        _Gfc2EdgeData_EdgeIndex(0),
        _Gfc2EdgeData_LoopIndex(0),
        _Gfc2EdgeData_Type(0),
        _Gfc2EdgeData_EdgeInfo(0),
        _Gfc2EdgeData_Param(0),
        _Gfc2EdgeData_BaseType(0),
        _Gfc2EdgeData_SlopePoly(0),
        _Gfc2VariableSectionLineShape_EndPoly(0),
        _Gfc2RelDefinesByElement_RelatingElement(0),
        _Gfc2SimpleLoop_Vertexes(0),
        _Gfc2SimpleVertex_Point(0),
        _Gfc2SimpleVertex_Radius(0),
        _Gfc2SimpleVertex_ArcType(0),
        _Gfc2SimplePolygon_Loops(0),
        _Gfc2CommonPolygon_Loops(0),
        _Gfc2PointShape2d_InsertPt(0),
        _Gfc2PointShape2d_Angle(0),
        _Gfc2PointShape2d_MirrorFlag(0),
        _Gfc2QuotaTotal_Code(0),
        _Gfc2QuotaTotal_SubCode(0),
        _Gfc2QuotaTotal_Name(0),
        _Gfc2QuotaTotal_Content(0),
        _Gfc2QuotaTotal_Unit(0),
        _Gfc2QuotaTotal_Quantity(0),
        _Gfc2QuotaTotal_Memo(0),
        _Gfc2BillTotal_Code(0),
        _Gfc2BillTotal_Name(0),
        _Gfc2BillTotal_Attr(0),
        _Gfc2BillTotal_QuantityType(0),
        _Gfc2BillTotal_Unit(0),
        _Gfc2BillTotal_Quantity(0),
        _Gfc2BillTotal_Memo(0),
        _Gfc2SteelTotal_CompType(0),
        _Gfc2SteelTotal_Level(0),
        _Gfc2SteelTotal_Dia(0),
        _Gfc2SteelTotal_Weight(0),
        _Gfc2SteelTotal_Unit(0),
        _Gfc2SteelDetail_EntityID(0),
        _Gfc2SteelDetail_Name(0),
        _Gfc2SteelDetail_Desc(0),
        _Gfc2SteelDetail_Level(0),
        _Gfc2SteelDetail_Dia(0),
        _Gfc2SteelDetail_Num(0),
        _Gfc2SteelDetail_Length(0),
        _Gfc2SteelDetail_SingleWeight(0),
        _Gfc2SteelDetail_TotalWeight(0),
        _Gfc2SteelDetail_TieinNum(0),
        _Gfc2SteelDetail_TieinType(0),
        _Gfc2BillDetail_FloorNum(0),
        _Gfc2BillDetail_EntityID(0),
        _Gfc2BillDetail_Unit(0),
        _Gfc2BillDetail_Express(0),
        _Gfc2BillDetail_Quantity(0),
        _Gfc2BillDetail_Memo(0),
        _Gfc2QuotaDetail_FloorNum(0),
        _Gfc2QuotaDetail_EntityID(0),
        _Gfc2QuotaDetail_Unit(0),
        _Gfc2QuotaDetail_Express(0),
        _Gfc2QuotaDetail_Quantity(0),
        _Gfc2QuotaDetail_Memo(0),
        _Gfc2PlaneCurve3d_PlaneCurve(0),
        _Gfc2PlaneCurve3d_Plane(0),
        _Gfc2CommonPolygonEx_LoopExs(0),
        _Gfc2CoedgeListEx_CoedgeExs(0),
        _Gfc2Coedge_Curve(0),
        _Gfc2Coedge_EdgeIndex(0),
        _Gfc2Coedge_EdgeSameDir(0),
        _Gfc2HermiteCurve2d_CtrlPts(0),
        _Gfc2HermiteCtrlPt2d_Point(0),
        _Gfc2HermiteCtrlPt2d_Tangent(0),
        _Gfc2HermiteCtrlPt2d_Parameter(0),
        _Gfc2HermiteCurve3d_CtrlPts(0),
        _Gfc2HermiteCtrlPt3d_Point(0),
        _Gfc2HermiteCtrlPt3d_Tangent(0),
        _Gfc2HermiteCtrlPt3d_Parameter(0),
        _Gfc2Representation_Identifier(0),
        _Gfc2Representation_items(0),
        _Gfc2RepresentationItem_PrimitiveType(0),
        _Gfc2RepresentationItem_GeometryDataType(0),
        _Gfc2RepresentationItem_Vertexes(0),
        _Gfc2RepresentationItem_Normals(0),
        _Gfc2RepresentationItem_Indexes(0),
        _Gfc2RepresentationItem_StateSet(0),
        _Gfc2StateSet_Ambient(0),
        _Gfc2StateSet_Diffuse(0),
        _Gfc2StateSet_SourceBlendFactor(0),
        _Gfc2StateSet_DestBlendFactor(0),
        _Gfc2StateSet_DepthTestEnabled(0),
        _Gfc2StateSet_DepthWriteEnabled(0),
        _Gfc2StateSet_DepthTestFunction(0),
        _Gfc2StateSet_PolygonOffsetFactor(0),
        _Gfc2StateSet_PolygonOffsetUnits(0),
        _Gfc2StateSet_PolygonStipple(0),
        _Gfc2StateSet_LineStipplePattern(0),
        _Gfc2StateSet_LineStippleFactor(0),
        _Gfc2StateSet_FaceMode(0),
        _Gfc2StateSet_LightingEnabled(0),
        _Gfc2StateSet_LightModelTwoSided(0),
        _Gfc2GeometryShape_Geo(0),
        _Gfc2FaceArchInfo_AxialLine(0),
        _Gfc2FaceArchInfo_Height(0),
        _Gfc2FaceArchInfo_Chord(0),
        _Gfc2FaceArchInfo_Radius(0),
        _Gfc2FaceArchInfo_DefineByRadius(0),
        _Gfc2FaceArchInfo_CheckInnerChord(0),
        _Gfc2FaceSphereInfo_CenterPoint(0),
        _Gfc2FaceSphereInfo_Height(0),
        _Gfc2FaceSphereInfo_Chord(0),
        _Gfc2FaceSphereInfo_Radius(0),
        _Gfc2FaceSphereInfo_DefineByRadius(0),
        _Gfc2FaceSphereInfo_CheckInnerChord(0),
        _Gfc2FaceConeInfo_Height(0),
        _Gfc2FaceConeInfo_Chord(0),
        _Gfc2FaceConeInfo_CenterPoint(0),
        _Gfc2FaceConeInfo_CheckInnerChord(0),
        _Gfc2LineArcInfo_BasePoint(0),
        _Gfc2LineArcInfo_ArchHeight(0),
        _Gfc2LineArcInfo_HalfChordLength(0),
        _Gfc2LineArcInfo_Radius(0),
        _Gfc2LineArcInfo_DefineByRadius(0),
        _Gfc2AbnormityLineArchInfo_TopArchStartT(0),
        _Gfc2AbnormityLineArchInfo_TopArchEndT(0),
        _Gfc2AbnormityLineArchInfo_TopDefineByRadius(0),
        _Gfc2AbnormityLineArchInfo_TopArchHeight(0),
        _Gfc2AbnormityLineArchInfo_TopArchRadius(0),
        _Gfc2AbnormityLineArchInfo_DownArchStartT(0),
        _Gfc2AbnormityLineArchInfo_DownArchEndT(0),
        _Gfc2AbnormityLineArchInfo_DownDefineByRadius(0),
        _Gfc2AbnormityLineArchInfo_DownArchHeight(0),
        _Gfc2AbnormityLineArchInfo_DownArchRadius(0),
        _Gfc2EntityShape_Identifier(0),
        _Gfc2EntityShape_Shape(0)
    {
    }

    int _Gfc2Shape_LocalCoordinate;
    int _Gfc2Shape_BoundingBox;
    int _Gfc2CustomLineShape_Width;
    int _Gfc2CustomLineShape_LeftWidth;
    int _Gfc2CustomLineShape_Line;
    int _Gfc2CustomLineShape_E_S_Elevation;
    int _Gfc2Entity_Type;
    int _Gfc2Entity_Representations;
    int _Gfc2Entity_Shapes;
    int _Gfc2CustomPointShape_InsertPt;
    int _Gfc2CustomPointShape_BaseInsertPt;
    int _Gfc2CustomPointShape_Angle;
    int _Gfc2CustomPointShape_MirrorFlag;
    int _Gfc2SolidShape_Body;
    int _Gfc2SolidShape_EdgeDatas;
    int _Gfc2Shape2d_Elev;
    int _Gfc2LineShape_Tilt;
    int _Gfc2LineShape_StartPtHeight;
    int _Gfc2LineShape_EndPtHeight;
    int _Gfc2LineShape_ArcInfo;
    int _Gfc2LineShape_IsSpiralTop;
    int _Gfc2LineShape_IsSpiralBtm;
    int _Gfc2SectionLineShape_Poly;
    int _Gfc2SectionLineShape_BaseInsertPt;
    int _Gfc2SectionLineShape_Angle;
    int _Gfc2SectionLineShape_MirrorFlag;
    int _Gfc2SectionLineShape_ArcInfo;
    int _Gfc2SectionLineShape_IsSpiral;
    int _Gfc2SectionPointShape_Poly;
    int _Gfc2PointShape_Height;
    int _Gfc2PointShape_ObliqueDir;
    int _Gfc2PointShape_TopPoly;
    int _Gfc2FaceShape_Thickness;
    int _Gfc2FaceShape_Poly;
    int _Gfc2FaceShape_MirrorFlag;
    int _Gfc2FaceShape_FaceInfo;
    int _Gfc2FaceShape2d_Poly;
    int _Gfc2AssitAxis_AxisNo;
    int _Gfc2AssitAxis_AxisNoPos;
    int _Gfc2AssitAxis_TrimPoints;
    int _Gfc2CartesianAxisGrid_InsertPt;
    int _Gfc2CartesianAxisGrid_AxisAngle;
    int _Gfc2CartesianAxisGrid_SKJ;
    int _Gfc2CartesianAxisGrid_ZJS;
    int _Gfc2CartesianAxisGrid_YJS;
    int _Gfc2CartesianAxisGrid_XKJ;
    int _Gfc2PolarAxisGrid_InsertPt;
    int _Gfc2PolarAxisGrid_StartRadius;
    int _Gfc2PolarAxisGrid_Clockwise;
    int _Gfc2PolarAxisGrid_XKJ;
    int _Gfc2PolarAxisGrid_ZJS;
    int _Gfc2AxisDataItem_AxisNo;
    int _Gfc2AxisDataItem_Distance;
    int _Gfc2AxisDataItem_Level;
    int _Gfc2AxisDataItem_AxisNoPos;
    int _Gfc2AxisDataItem_TrimPoints;
    int _Gfc2ParallelAssitAxis_RefAxisNo;
    int _Gfc2ParallelAssitAxis_Offset;
    int _Gfc2ParallelAssitAxis_RefAxisIndex;
    int _Gfc2ParallelAssitAxis_RefAxisType;
    int _Gfc2PointAngleAssitAxis_RefPoint;
    int _Gfc2PointAngleAssitAxis_Angle;
    int _Gfc2AxisAngleAssitAxis_RefAxisNo;
    int _Gfc2AxisAngleAssitAxis_RefPoint;
    int _Gfc2AxisAngleAssitAxis_Angle;
    int _Gfc2AxisAngleAssitAxis_RefAxisIndex;
    int _Gfc2AxisAngleAssitAxis_RefAxisType;
    int _Gfc2PolarAngleAssitAxis_RefAxisNo;
    int _Gfc2PolarAngleAssitAxis_Angle;
    int _Gfc2PolarAngleAssitAxis_RefAxisIndex;
    int _Gfc2ThreePointArcAssitAxis_RefPoint1;
    int _Gfc2ThreePointArcAssitAxis_RefPoint2;
    int _Gfc2ThreePointArcAssitAxis_RefPoint3;
    int _Gfc2CenterStartEndArcAssitAxis_Center;
    int _Gfc2CenterStartEndArcAssitAxis_StartPoint;
    int _Gfc2CenterStartEndArcAssitAxis_EndPoint;
    int _Gfc2CircleAssitAxis_Center;
    int _Gfc2CircleAssitAxis_Radius;
    int _Gfc2SizeMark_SizeMarkType;
    int _Gfc2SizeMark_StartLine;
    int _Gfc2SizeMark_EndLine;
    int _Gfc2LineShape2d_Line;
    int _Gfc2Object_ID;
    int _Gfc2Object_Name;
    int _Gfc2PropertySet_Identifier;
    int _Gfc2PropertySet_HasProperties;
    int _Gfc2Floor_FirstFloorFlag;
    int _Gfc2Floor_Height;
    int _Gfc2Floor_StdFloorCount;
    int _Gfc2Floor_StructuralElevation;
    int _Gfc2Floor_StartFloorNo;
    int _Gfc2Floor_Remark;
    int _Gfc2Property_Name;
    int _Gfc2IntegerProperty_Value;
    int _Gfc2DoubleProperty_Value;
    int _Gfc2BooleanProperty_Value;
    int _Gfc2StringProperty_Value;
    int _Gfc2ObjectProperty_Value;
    int _Gfc2RelDecomposes_RelatingObject;
    int _Gfc2RelDecomposes_RelatedObjects;
    int _Gfc2RelDefines_RelatedObjects;
    int _Gfc2RelDefinesByProperties_RelatingPropertySet;
    int _Gfc2Vector2d_X;
    int _Gfc2Vector2d_Y;
    int _Gfc2Vector3d_X;
    int _Gfc2Vector3d_Y;
    int _Gfc2Vector3d_Z;
    int _Gfc2Intervald_Min;
    int _Gfc2Intervald_Max;
    int _Gfc2Coordinates3d_Origin;
    int _Gfc2Coordinates3d_X;
    int _Gfc2Coordinates3d_Y;
    int _Gfc2Coordinates3d_Z;
    int _Gfc2Coordinates2d_Origin;
    int _Gfc2Coordinates2d_X;
    int _Gfc2Coordinates2d_Y;
    int _Gfc2Line2d_StartPt;
    int _Gfc2Line2d_EndPt;
    int _Gfc2Arc2d_CenterPt;
    int _Gfc2Arc2d_Radius;
    int _Gfc2Arc2d_Range;
    int _Gfc2Arc2d_ClockSign;
    int _Gfc2Ellipse2d_CenterPt;
    int _Gfc2Ellipse2d_MajorAxis;
    int _Gfc2Ellipse2d_dMajorRad;
    int _Gfc2Ellipse2d_dMinorRad;
    int _Gfc2Ellipse2d_Range;
    int _Gfc2Ellipse2d_ClockSign;
    int _Gfc2NurbsCurve2d_Degree;
    int _Gfc2NurbsCurve2d_CtrlPts;
    int _Gfc2NurbsCurve2d_Knots;
    int _Gfc2PreimageCurve2d_Range;
    int _Gfc2PreimageCurve2d_Reversed;
    int _Gfc2PreimageCurve2d_Base;
    int _Gfc2PreimageCurve2d_Curve;
    int _Gfc2PreimageCurve2d_Tolerance;
    int _Gfc2SinCurve2d_Pos;
    int _Gfc2SinCurve2d_DirX;
    int _Gfc2SinCurve2d_A;
    int _Gfc2SinCurve2d_B;
    int _Gfc2SinCurve2d_Range;
    int _Gfc2SinCurve2d_ClockSign;
    int _Gfc2SpiralLine2d_Coord;
    int _Gfc2SpiralLine2d_Radius;
    int _Gfc2SpiralLine2d_Range;
    int _Gfc2SpiralLine2d_ClockSign;
    int _Gfc2SpiralLine2d_RadiusCoef;
    int _Gfc2NurbsCtrlPt2d_Point;
    int _Gfc2NurbsCtrlPt2d_Weight;
    int _Gfc2Line3d_StartPt;
    int _Gfc2Line3d_EndPt;
    int _Gfc2NurbsCurve3d_Degree;
    int _Gfc2NurbsCurve3d_CtrlPts;
    int _Gfc2NurbsCurve3d_Knots;
    int _Gfc2IntersectionCurve3d_Bases1;
    int _Gfc2IntersectionCurve3d_Bases2;
    int _Gfc2IntersectionCurve3d_Range;
    int _Gfc2IntersectionCurve3d_Chart;
    int _Gfc2SpiralLine3d_Coord;
    int _Gfc2SpiralLine3d_Radius;
    int _Gfc2SpiralLine3d_Range;
    int _Gfc2SpiralLine3d_ClockSign;
    int _Gfc2SpiralLine3d_HeightCoef;
    int _Gfc2SpiralLine3d_RadiusCoef;
    int _Gfc2SweepCurve3d_Spine3d;
    int _Gfc2SweepCurve3d_ReferenceVector;
    int _Gfc2SweepCurve3d_Point;
    int _Gfc2PlaneInfo_DirX;
    int _Gfc2PlaneInfo_DirY;
    int _Gfc2PlaneInfo_Pos;
    int _Gfc2NurbsCtrlPt3d_Point;
    int _Gfc2NurbsCtrlPt3d_Weight;
    int _Gfc2InternalPt_P;
    int _Gfc2InternalPt_TVec;
    int _Gfc2InternalPt_T;
    int _Gfc2InternalPt_UV;
    int _Gfc2InternalPt_ST;
    int _Gfc2InternalPt_UVDir;
    int _Gfc2InternalPt_STDir;
    int _Gfc2InternalChart_Tra1;
    int _Gfc2InternalChart_Tra2;
    int _Gfc2InternalChart_Tra3;
    int _Gfc2InternalChart_IPS;
    int _Gfc2Bevel_Coord;
    int _Gfc2Bevel_Height;
    int _Gfc2Bevel_RangeV;
    int _Gfc2Bevel_Curve;
    int _Gfc2Cylinder_Coord;
    int _Gfc2Cylinder_RangeV;
    int _Gfc2Cylinder_Curve;
    int _Gfc2Helicoid_Coord;
    int _Gfc2Helicoid_Radius;
    int _Gfc2Helicoid_RangeV;
    int _Gfc2Helicoid_ClockSign;
    int _Gfc2Helicoid_HeightCoef;
    int _Gfc2Helicoid_RadiusCoef;
    int _Gfc2Helicoid_Curve;
    int _Gfc2NurbsSurface_DegreeU;
    int _Gfc2NurbsSurface_DegreeV;
    int _Gfc2NurbsSurface_CtrlPtCountU;
    int _Gfc2NurbsSurface_CtrlPtCountV;
    int _Gfc2NurbsSurface_CtrlPts;
    int _Gfc2NurbsSurface_KnotsU;
    int _Gfc2NurbsSurface_KnotsV;
    int _Gfc2Plane_Pos;
    int _Gfc2Plane_DirU;
    int _Gfc2Plane_DirV;
    int _Gfc2Plane_RangeU;
    int _Gfc2Plane_RangeV;
    int _Gfc2Sphere_Radius;
    int _Gfc2Sphere_Coords;
    int _Gfc2Sphere_RangeU;
    int _Gfc2Sphere_RangeV;
    int _Gfc2Sweep_Profile;
    int _Gfc2Sweep_Spine3d;
    int _Gfc2Sweep_ReferenceVector;
    int _Gfc2Torus_Coord;
    int _Gfc2Torus_Radius;
    int _Gfc2Torus_ClockSign;
    int _Gfc2Torus_RangeV;
    int _Gfc2Torus_Curve;
    int _Gfc2BrepBody_Faces;
    int _Gfc2BrepBody_Edges;
    int _Gfc2CuboidBody_Coordinate;
    int _Gfc2CuboidBody_Dimension;
    int _Gfc2ExtrudedBody_Coordinate;
    int _Gfc2ExtrudedBody_Length;
    int _Gfc2ExtrudedBody_Section;
    int _Gfc2PolyhedronBody_Faces;
    int _Gfc2PolyhedronBody_Vertexes;
    int _Gfc2CoedgeList_Coedges;
    int _Gfc2Face_Surface;
    int _Gfc2Face_Box;
    int _Gfc2Face_SameDir;
    int _Gfc2Face_Index;
    int _Gfc2Edge_Curve;
    int _Gfc2Edge_FaceIndex1;
    int _Gfc2Edge_FaceIndex2;
    int _Gfc2Edge_LoopIndex1;
    int _Gfc2Edge_LoopIndex2;
    int _Gfc2Edge_CoedgeIndex1;
    int _Gfc2Edge_CoedgeIndex2;
    int _Gfc2PolyhedralFace_Loops;
    int _Gfc2PolyhedralFace_Plane;
    int _Gfc2PlaneCoef_A;
    int _Gfc2PlaneCoef_B;
    int _Gfc2PlaneCoef_C;
    int _Gfc2PlaneCoef_D;
    int _Gfc2PolyhedralLoop_Edges;
    int _Gfc2PolyhedralEdge_StartVertexIndex;
    int _Gfc2PolyhedralEdge_EndVertexIndex;
    int _Gfc2String_Value;
    int _Gfc2Box3d_Min;
    int _Gfc2Box3d_Max;
    int _Gfc2OffsetCurve2d_OffDist;
    int _Gfc2OffsetCurve2d_InitCurve;
    int _Gfc2ImageCurve3d_Curve;
    int _Gfc2ImageCurve3d_Surface;
    int _Gfc2RuledSurface_ApexIndex;
    int _Gfc2RuledSurface_RangeV;
    int _Gfc2RuledSurface_RangeU;
    int _Gfc2RuledSurface_Directrix1;
    int _Gfc2RuledSurface_Directrix2;
    int _Gfc2EdgeData_EdgeIndex;
    int _Gfc2EdgeData_LoopIndex;
    int _Gfc2EdgeData_Type;
    int _Gfc2EdgeData_EdgeInfo;
    int _Gfc2EdgeData_Param;
    int _Gfc2EdgeData_BaseType;
    int _Gfc2EdgeData_SlopePoly;
    int _Gfc2VariableSectionLineShape_EndPoly;
    int _Gfc2RelDefinesByElement_RelatingElement;
    int _Gfc2SimpleLoop_Vertexes;
    int _Gfc2SimpleVertex_Point;
    int _Gfc2SimpleVertex_Radius;
    int _Gfc2SimpleVertex_ArcType;
    int _Gfc2SimplePolygon_Loops;
    int _Gfc2CommonPolygon_Loops;
    int _Gfc2PointShape2d_InsertPt;
    int _Gfc2PointShape2d_Angle;
    int _Gfc2PointShape2d_MirrorFlag;
    int _Gfc2QuotaTotal_Code;
    int _Gfc2QuotaTotal_SubCode;
    int _Gfc2QuotaTotal_Name;
    int _Gfc2QuotaTotal_Content;
    int _Gfc2QuotaTotal_Unit;
    int _Gfc2QuotaTotal_Quantity;
    int _Gfc2QuotaTotal_Memo;
    int _Gfc2BillTotal_Code;
    int _Gfc2BillTotal_Name;
    int _Gfc2BillTotal_Attr;
    int _Gfc2BillTotal_QuantityType;
    int _Gfc2BillTotal_Unit;
    int _Gfc2BillTotal_Quantity;
    int _Gfc2BillTotal_Memo;
    int _Gfc2SteelTotal_CompType;
    int _Gfc2SteelTotal_Level;
    int _Gfc2SteelTotal_Dia;
    int _Gfc2SteelTotal_Weight;
    int _Gfc2SteelTotal_Unit;
    int _Gfc2SteelDetail_EntityID;
    int _Gfc2SteelDetail_Name;
    int _Gfc2SteelDetail_Desc;
    int _Gfc2SteelDetail_Level;
    int _Gfc2SteelDetail_Dia;
    int _Gfc2SteelDetail_Num;
    int _Gfc2SteelDetail_Length;
    int _Gfc2SteelDetail_SingleWeight;
    int _Gfc2SteelDetail_TotalWeight;
    int _Gfc2SteelDetail_TieinNum;
    int _Gfc2SteelDetail_TieinType;
    int _Gfc2BillDetail_FloorNum;
    int _Gfc2BillDetail_EntityID;
    int _Gfc2BillDetail_Unit;
    int _Gfc2BillDetail_Express;
    int _Gfc2BillDetail_Quantity;
    int _Gfc2BillDetail_Memo;
    int _Gfc2QuotaDetail_FloorNum;
    int _Gfc2QuotaDetail_EntityID;
    int _Gfc2QuotaDetail_Unit;
    int _Gfc2QuotaDetail_Express;
    int _Gfc2QuotaDetail_Quantity;
    int _Gfc2QuotaDetail_Memo;
    int _Gfc2PlaneCurve3d_PlaneCurve;
    int _Gfc2PlaneCurve3d_Plane;
    int _Gfc2CommonPolygonEx_LoopExs;
    int _Gfc2CoedgeListEx_CoedgeExs;
    int _Gfc2Coedge_Curve;
    int _Gfc2Coedge_EdgeIndex;
    int _Gfc2Coedge_EdgeSameDir;
    int _Gfc2HermiteCurve2d_CtrlPts;
    int _Gfc2HermiteCtrlPt2d_Point;
    int _Gfc2HermiteCtrlPt2d_Tangent;
    int _Gfc2HermiteCtrlPt2d_Parameter;
    int _Gfc2HermiteCurve3d_CtrlPts;
    int _Gfc2HermiteCtrlPt3d_Point;
    int _Gfc2HermiteCtrlPt3d_Tangent;
    int _Gfc2HermiteCtrlPt3d_Parameter;
    int _Gfc2Representation_Identifier;
    int _Gfc2Representation_items;
    int _Gfc2RepresentationItem_PrimitiveType;
    int _Gfc2RepresentationItem_GeometryDataType;
    int _Gfc2RepresentationItem_Vertexes;
    int _Gfc2RepresentationItem_Normals;
    int _Gfc2RepresentationItem_Indexes;
    int _Gfc2RepresentationItem_StateSet;
    int _Gfc2StateSet_Ambient;
    int _Gfc2StateSet_Diffuse;
    int _Gfc2StateSet_SourceBlendFactor;
    int _Gfc2StateSet_DestBlendFactor;
    int _Gfc2StateSet_DepthTestEnabled;
    int _Gfc2StateSet_DepthWriteEnabled;
    int _Gfc2StateSet_DepthTestFunction;
    int _Gfc2StateSet_PolygonOffsetFactor;
    int _Gfc2StateSet_PolygonOffsetUnits;
    int _Gfc2StateSet_PolygonStipple;
    int _Gfc2StateSet_LineStipplePattern;
    int _Gfc2StateSet_LineStippleFactor;
    int _Gfc2StateSet_FaceMode;
    int _Gfc2StateSet_LightingEnabled;
    int _Gfc2StateSet_LightModelTwoSided;
    int _Gfc2GeometryShape_Geo;
    int _Gfc2FaceArchInfo_AxialLine;
    int _Gfc2FaceArchInfo_Height;
    int _Gfc2FaceArchInfo_Chord;
    int _Gfc2FaceArchInfo_Radius;
    int _Gfc2FaceArchInfo_DefineByRadius;
    int _Gfc2FaceArchInfo_CheckInnerChord;
    int _Gfc2FaceSphereInfo_CenterPoint;
    int _Gfc2FaceSphereInfo_Height;
    int _Gfc2FaceSphereInfo_Chord;
    int _Gfc2FaceSphereInfo_Radius;
    int _Gfc2FaceSphereInfo_DefineByRadius;
    int _Gfc2FaceSphereInfo_CheckInnerChord;
    int _Gfc2FaceConeInfo_Height;
    int _Gfc2FaceConeInfo_Chord;
    int _Gfc2FaceConeInfo_CenterPoint;
    int _Gfc2FaceConeInfo_CheckInnerChord;
    int _Gfc2LineArcInfo_BasePoint;
    int _Gfc2LineArcInfo_ArchHeight;
    int _Gfc2LineArcInfo_HalfChordLength;
    int _Gfc2LineArcInfo_Radius;
    int _Gfc2LineArcInfo_DefineByRadius;
    int _Gfc2AbnormityLineArchInfo_TopArchStartT;
    int _Gfc2AbnormityLineArchInfo_TopArchEndT;
    int _Gfc2AbnormityLineArchInfo_TopDefineByRadius;
    int _Gfc2AbnormityLineArchInfo_TopArchHeight;
    int _Gfc2AbnormityLineArchInfo_TopArchRadius;
    int _Gfc2AbnormityLineArchInfo_DownArchStartT;
    int _Gfc2AbnormityLineArchInfo_DownArchEndT;
    int _Gfc2AbnormityLineArchInfo_DownDefineByRadius;
    int _Gfc2AbnormityLineArchInfo_DownArchHeight;
    int _Gfc2AbnormityLineArchInfo_DownArchRadius;
    int _Gfc2EntityShape_Identifier;
    int _Gfc2EntityShape_Shape;
};

extern FieldCache* _FieldCache;

void GFCCLASSES_API initFieldCache();
void GFCCLASSES_API freeFieldCache();

#endif
