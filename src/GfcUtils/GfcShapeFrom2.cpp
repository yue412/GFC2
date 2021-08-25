#include "GfcUtils\GfcShapeFrom2.h"
#include "GfcUtils\GfcFrom2.h"
#include "GfcEngine\EntityUpgrader.h"
#include "GfcEngine\ModelCompatibility.h"
#include "GfcEngine\ClassCompatibility.h"
#include "GfcEngine\Writer.h"
#include "GfcUtils\GfcGeometryImporter.h"
#include "GfcUtils\GfcGeometryExporter.h"
#include "GMath\GMathDef.h"

ggp::CPolygon * TransPolygon(ggp::CPolygon * pPolygon, const ggp::CVector2d & rBaseInsertPt, const ggp::CVector2d & rInsertPt, double dAngle, bool bMirror)
{
    if (pPolygon)
    {
        pPolygon = (ggp::CPolygon *)pPolygon->Clone();
        //先镜像
        if (bMirror)
        {
            ggp::CMatrix4d oMatrix4d;
            oMatrix4d.SetMirror(ggp::CVector3d(rBaseInsertPt, 0), ggp::CVector3d::UnitX);
            pPolygon->Transform(oMatrix4d);
        }
        //再旋转
        if (!ggp::isZero(dAngle, ggp::g_DoubleResolution) && !ggp::is_nan(dAngle))
        {
            pPolygon->Rotate(rBaseInsertPt, dAngle);
        }
        //最后再移动
        pPolygon->Move(rInsertPt - rBaseInsertPt);
    }
    return pPolygon;
}

// 计算墙起始端面
ggp::CPolygon * calcWallPolygon(double dWidth, double dLeftWidth, double dAngle, double dHeight)
{
    auto oPt1 = ggp::CVector2d(- dWidth + dLeftWidth, 0);
    auto oPt2 = ggp::CVector2d(dLeftWidth, 0); 
    auto oDir = ggp::CVector2d(dHeight * tan(dAngle), dHeight);
    auto oPt3 = oPt2 + oDir;
    auto oPt4 = oPt1 + oDir;
    std::vector<ggp::CVector2d> oVertexes = { oPt1, oPt2, oPt3, oPt4 };
    auto pPolygon = new ggp::CPolygon(oVertexes);
    return pPolygon;
}

GFCENGINE_IMP_FACTORY(GfcShapeFrom2, 0)

GfcShapeFrom2::GfcShapeFrom2(): m_pOwner(nullptr)
{

}

GfcShapeFrom2::~GfcShapeFrom2()
{
}

gfc::engine::EntityPtr GfcShapeFrom2::transform(gfc::engine::EntityPtr pSrcShape)
{
    auto pShape = createShape(pSrcShape);
    doTransform(pSrcShape, pShape);
    return pShape;
}

void GfcShapeFrom2::doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    if (owner() == nullptr)
        return;
    auto pUpgrader = owner()->upgrader();
    auto pClass = pUpgrader->model()->find(L"Gfc2Shape");
    assert(pClass);
    pUpgrader->transform(pClass, pSrcShape.get(), pDestShape.get());
}

GFCENGINE_IMP_OBJECT(Gfc2SolidShapeFrom2, L"Gfc2SolidShape", 0)

gfc::engine::EntityPtr Gfc2SolidShapeFrom2::createShape(gfc::engine::EntityPtr pSrcShape)
{
    if (owner() == nullptr)
        return nullptr;
    auto pEntity = owner()->createEntity(L"Gfc2ManifoldSolidShape");
    return pEntity;
}

void Gfc2SolidShapeFrom2::doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    GfcShapeFrom2::doTransform(pSrcShape, pDestShape);
    if (owner() == nullptr)
        return;
    auto pUpgrader = owner()->upgrader();
    auto pBody = pSrcShape->asEntity(L"Body");
    if (pBody)
    {
        auto pDestBody = gfc::engine::EntityPtr(pUpgrader->update(pBody.get()));
        auto nRef = owner()->write(pSrcShape->ref(), pDestBody);
        pDestShape->setAsEntityRef(L"Body", nRef);
    }
}

GFCENGINE_IMP_OBJECT(Gfc2PointShapeFrom2, L"Gfc2PointShape", 0)

gfc::engine::EntityPtr Gfc2PointShapeFrom2::createShape(gfc::engine::EntityPtr pSrcShape)
{
    if (owner() == nullptr)
        return nullptr;
    if(pSrcShape->isNull(L"TopPoly"))
        return owner()->createEntity(L"Gfc2ExtrudedAreaSolidShape");
    else
        return owner()->createEntity(L"Gfc2ExtrudedAreaSolidTaperedShape");
}

void Gfc2PointShapeFrom2::doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    Gfc2SolidShapeFrom2::doTransform(pSrcShape, pDestShape);
    if (pSrcShape->isNull(L"TopPoly"))
    {
        auto oDir = GfcGeometryImporter::importVector3d(pSrcShape->asEntity(L"ObliqueDir").get());
        oDir.Normalize();
        if (ggp::sameValue(oDir.Z, 1, ggp::g_DoubleResolution))
        {
            auto dHeight = pSrcShape->asDouble(L"Height");
            auto pPolygon = GfcGeometryImporter::importPolygon(pSrcShape->asEntity(L"Poly").get());
            auto oInsertPt = GfcGeometryImporter::importVector2d(pSrcShape->asEntity(L"InsertPt").get());
            auto oBaseInsertPt = GfcGeometryImporter::importVector2d(pSrcShape->asEntity(L"BaseInsertPt").get());
            auto dAngle = pSrcShape->asDouble(L"Angle");
            auto bMirrorFlag = pSrcShape->asBoolean(L"MirrorFlag");
            auto pTransPolygon = TransPolygon(pPolygon, oBaseInsertPt, oInsertPt, dAngle, bMirrorFlag);
            auto pSection = owner()->createEntity(L"Gfc2ArbitrarySection");
            pSection->setAsEntityRef(L"Poly", GfcGeometryExporter::exportPolygon(owner()->writer(), pTransPolygon));
            pDestShape->setAsEntityRef(L"SweptArea", owner()->writer()->writeEntity(pSection.get()));
            pDestShape->setAsEntityRef(L"ExtrudedDirection", GfcGeometryExporter::exportVector3d(owner()->writer(), &oDir));
            pDestShape->setAsDouble(L"Len", dHeight);
            pTransPolygon->Free();
            pPolygon->Free();
        }
        else 
        {
            //todo
        }
    }
    else
    {
        //todo
    }
}

void Gfc2BaseLineShapeFrom2::doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    Gfc2SolidShapeFrom2::doTransform(pSrcShape, pDestShape);
    auto pLine = GfcGeometryImporter::importCurve2d(pSrcShape->asEntity(L"Line").get());
    if(pDestShape->entityName() == L"Gfc2ExtrudedAreaSolidShape" || pDestShape->entityName() == L"Gfc2ExtrudedAreaSolidTaperedShape")
        doTransformExtruded(dynamic_cast<ggp::CLine2d*>(pLine), pSrcShape, pDestShape);
    else if (pDestShape->entityName() == L"Gfc2RevolvedAreaSolidShape" || pDestShape->entityName() == L"Gfc2RevolvedAreaSolidTaperedShape")
        doTransformRevolved(dynamic_cast<ggp::CArc2d*>(pLine), pSrcShape, pDestShape);
    pLine->Free();
}

void Gfc2BaseLineShapeFrom2::doTransformExtruded(ggp::CLine2d* pLine, gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    auto pPoly = createStartPolygon(pSrcShape);
    auto oLocalCoordinate = GfcGeometryImporter::importCoordinates3d(pSrcShape->asEntity(L"LocalCoordinate").get());
    auto oZ = ggp::CVector3d(pLine->StartVt(), 0.0);
    auto oY = ggp::CVector3d::UnitY;
    auto oX = oY.CrossProduct(oZ);
    auto oOrigin = ggp::CVector3d(pLine->StartPoint(), 0.0);
    auto oCoord = ggp::CCoordinates3d(oOrigin, oX, oY, oZ);
    oCoord.ToWorldCoord(oLocalCoordinate);

    auto dElev = pSrcShape->asDouble(L"E_S_Elevation");
    auto oExtrudedDir = ggp::CVector3d(0, dElev, pLine->Length());
    auto dLen = oExtrudedDir.Length();
    oExtrudedDir = oExtrudedDir / dLen;

    pDestShape->setAsEntityRef(L"LocalCoordinate", GfcGeometryExporter::exportCoordinates3d(owner()->writer(), &oCoord));
    auto pSection = owner()->createEntity(L"Gfc2ArbitrarySection");
    pSection->setAsEntityRef(L"Poly", GfcGeometryExporter::exportPolygon(owner()->writer(), pPoly));
    pDestShape->setAsEntityRef(L"SweptArea", owner()->writer()->writeEntity(pSection.get()));
    pDestShape->setAsEntityRef(L"ExtrudedDirection", GfcGeometryExporter::exportVector3d(owner()->writer(), &oExtrudedDir));
    pDestShape->setAsDouble(L"Len", dLen);

    pPoly->Free();
}

void Gfc2BaseLineShapeFrom2::doTransformRevolved(ggp::CArc2d* pArc, gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    auto pPoly = createStartPolygon(pSrcShape);
    auto oLocalCoordinate = GfcGeometryImporter::importCoordinates3d(pSrcShape->asEntity(L"LocalCoordinate").get());
    auto oZ = ggp::CVector3d(pArc->StartVt(), 0.0);
    auto oY = ggp::CVector3d::UnitY;
    auto oX = oY.CrossProduct(oZ);
    auto oOrigin = ggp::CVector3d(pArc->StartPoint(), 0.0);
    auto oCoord = ggp::CCoordinates3d(oOrigin, oX, oY, oZ);
    oCoord.ToWorldCoord(oLocalCoordinate);

    auto oLocal = ggp::CVector2d(pArc->ClockSign() * pArc->Radius(), 0);
    auto oAxisDir = ggp::CVector2d(0, pArc->ClockSign());
    auto dAngle = pArc->RotateAngle();

    pDestShape->setAsEntityRef(L"LocalCoordinate", GfcGeometryExporter::exportCoordinates3d(owner()->writer(), &oCoord));
    auto pSection = owner()->createEntity(L"Gfc2ArbitrarySection");
    pSection->setAsEntityRef(L"Poly", GfcGeometryExporter::exportPolygon(owner()->writer(), pPoly));
    pDestShape->setAsEntityRef(L"SweptArea", owner()->writer()->writeEntity(pSection.get()));
    pDestShape->setAsEntityRef(L"Location", GfcGeometryExporter::exportVector2d(owner()->writer(), &oLocal));
    pDestShape->setAsEntityRef(L"Axis", GfcGeometryExporter::exportVector2d(owner()->writer(), &oAxisDir));
    pDestShape->setAsDouble(L"Angle", dAngle);
}

GFCENGINE_IMP_OBJECT(Gfc2LineShapeFrom2, L"Gfc2LineShape", 0)

gfc::engine::EntityPtr Gfc2LineShapeFrom2::createShape(gfc::engine::EntityPtr pSrcShape)
{
    gfc::engine::EntityPtr pResult = nullptr;
    if (pSrcShape->isNull(L"ArcInfo"))
    {
        auto pLine = GfcGeometryImporter::importCurve2d(pSrcShape->asEntity(L"Line").get());
        switch (pLine->Type())
        {
        case ggp::Line2dType:
            if (!ggp::sameValue(pSrcShape->asDouble(L"StartPtHeight"), pSrcShape->asDouble(L"EndPtHeight"), ggp::g_DoubleResolution))
                pResult = owner()->createEntity(L"Gfc2ExtrudedAreaSolidTaperedShape");
            else
                pResult = owner()->createEntity(L"Gfc2ExtrudedAreaSolidShape");
            break;
        case ggp::Arc2dType:
            if (ggp::isZero(pSrcShape->asDouble(L"E_S_Elevation"), ggp::g_DoubleResolution) &&
                ggp::sameValue(pSrcShape->asDouble(L"StartPtHeight"), pSrcShape->asDouble(L"EndPtHeight"), ggp::g_DoubleResolution))
            {
                pResult = owner()->createEntity(L"Gfc2RevolvedAreaSolidShape");
            }
            else
            {
                pResult = owner()->createEntity(L"Gfc2ManifoldSolidShape");
            }
            break;
        default:
            pResult = owner()->createEntity(L"Gfc2ManifoldSolidShape");
        }
        pLine->Free();
    }
    else
        pResult = owner()->createEntity(L"Gfc2ManifoldSolidShape");
    return pResult;
}

ggp::CPolygon * Gfc2LineShapeFrom2::createStartPolygon(gfc::engine::EntityPtr pSrcShape)
{
    return calcWallPolygon(pSrcShape->asDouble(L"Width"), pSrcShape->asDouble(L"LeftWidth"), pSrcShape->asDouble(L"Tilt"), pSrcShape->asDouble(L"StartPtHeight"));
}

void Gfc2LineShapeFrom2::doTransformExtruded(ggp::CLine2d * pLine, gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    Gfc2BaseLineShapeFrom2::doTransformExtruded(pLine, pSrcShape, pDestShape);

    if (!ggp::sameValue(pSrcShape->asDouble(L"StartPtHeight"), pSrcShape->asDouble(L"EndPtHeight"), ggp::g_DoubleResolution))
    {
        // 变截面拉伸
        auto pEndPoly = calcWallPolygon(pSrcShape->asDouble(L"Width"), pSrcShape->asDouble(L"LeftWidth"), pSrcShape->asDouble(L"Tilt"), pSrcShape->asDouble(L"EndPtHeight"));
        auto pSection = owner()->createEntity(L"Gfc2ArbitrarySection");
        pSection->setAsEntityRef(L"Poly", GfcGeometryExporter::exportPolygon(owner()->writer(), pEndPoly));
        pDestShape->setAsEntityRef(L"EndSweptArea", owner()->writer()->writeEntity(pSection.get()));
        pEndPoly->Free();
    }
}

GFCENGINE_IMP_OBJECT(Gfc2SectionLineShapeFrom2, L"Gfc2SectionLineShape", 0)

gfc::engine::EntityPtr Gfc2SectionLineShapeFrom2::createShape(gfc::engine::EntityPtr pSrcShape)
{
    auto sName = L"Gfc2ManifoldSolidShape";
    if (pSrcShape->isNull(L"ArcInfo"))
    {
        auto pLine = GfcGeometryImporter::importCurve2d(pSrcShape->asEntity(L"Line").get());
        switch (pLine->Type())
        {
        case ggp::Line2dType:
            sName = L"Gfc2ExtrudedAreaSolidShape";
            break;
        case ggp::Arc2dType:
            if (ggp::isZero(pSrcShape->asDouble(L"E_S_Elevation"), ggp::g_DoubleResolution))
            {
                sName = L"Gfc2RevolvedAreaSolidShape";
            }
            break;
        }
        pLine->Free();
    }
    return owner()->createEntity(sName);
}

ggp::CPolygon * Gfc2SectionLineShapeFrom2::createStartPolygon(gfc::engine::EntityPtr pSrcShape)
{
    auto pPolygon = GfcGeometryImporter::importPolygon(pSrcShape->asEntity(L"Poly").get());
    auto oInsertPt = ggp::CVector2d(0, 0);
    auto oBaseInsertPt = GfcGeometryImporter::importVector2d(pSrcShape->asEntity(L"BaseInsertPt").get());
    auto dAngle = pSrcShape->asDouble(L"Angle");
    auto bMirrorFlag = pSrcShape->asBoolean(L"MirrorFlag");
    return TransPolygon(pPolygon, oBaseInsertPt, oInsertPt, dAngle, bMirrorFlag);
}

GFCENGINE_IMP_OBJECT(Gfc2FaceShapeFrom2, L"Gfc2FaceShape", 0)

gfc::engine::EntityPtr Gfc2FaceShapeFrom2::createShape(gfc::engine::EntityPtr pSrcShape)
{
    auto sName = pSrcShape->isNull(L"FaceInfo") ? L"Gfc2ExtrudedAreaSolidShape" : L"Gfc2ManifoldSolidShape";
    return owner()->createEntity(sName);
}

void Gfc2FaceShapeFrom2::doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape)
{
    Gfc2SolidShapeFrom2::doTransform(pSrcShape, pDestShape);
    if (pDestShape->entityName() == L"Gfc2ExtrudedAreaSolidShape")
    {
        auto oLocalCoordinate = GfcGeometryImporter::importCoordinates3d(pSrcShape->asEntity(L"LocalCoordinate").get());
        auto oExtrudedDir = ggp::CVector3d::NegaUnitY;
        oExtrudedDir = oExtrudedDir.ToLocalVt(oLocalCoordinate);

        auto pPoly = GfcGeometryImporter::importPolygon(pSrcShape->asEntity(L"Poly").get());
        auto dLen = abs(pSrcShape->asDouble(L"Thickness"));

        auto pSection = owner()->createEntity(L"Gfc2ArbitrarySection");
        pSection->setAsEntityRef(L"Poly", GfcGeometryExporter::exportPolygon(owner()->writer(), pPoly));
        pDestShape->setAsEntityRef(L"SweptArea", owner()->writer()->writeEntity(pSection.get()));
        pDestShape->setAsEntityRef(L"ExtrudedDirection", GfcGeometryExporter::exportVector3d(owner()->writer(), &oExtrudedDir));
        pDestShape->setAsDouble(L"Len", dLen);

        pPoly->Free();
    }
}
