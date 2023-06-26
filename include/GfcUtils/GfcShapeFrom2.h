#ifndef GFCSHAPEFROM2_H
#define GFCSHAPEFROM2_H

#include "GfcEngine/SysMarco.h"
#include "GfcEngine/Entity.h"
#include <memory>

namespace gfc {
    namespace engine {
        class CEntity;
        class CClassCompatibility;
        class CWriter;
    }
}

namespace ggp {
    class CLine2d;
    class CArc2d;
    class CPolygon;
}

class GfcFrom2;

class GfcShapeFrom2 : public gfc::engine::CObject
{
    GFCENGINE_DEC_FACTORY(GfcShapeFrom2, 0, std::wstring)
public:
    GfcShapeFrom2();
    virtual ~GfcShapeFrom2();
    gfc::engine::EntityPtr transform(gfc::engine::EntityPtr pSrcShape);
    // 输出
    void setOwner(GfcFrom2* pOwner) { m_pOwner = pOwner; }
    GfcFrom2* owner() { return m_pOwner; }
protected:
    virtual gfc::engine::EntityPtr createShape(gfc::engine::EntityPtr pSrcShape) = 0;
    virtual void doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);
private:
    GfcFrom2* m_pOwner;
};

class Gfc2SolidShapeFrom2 : public GfcShapeFrom2
{
    GFCENGINE_DEC_OBJECT(Gfc2SolidShapeFrom2, GfcShapeFrom2)
public:
protected:
    virtual gfc::engine::EntityPtr createShape(gfc::engine::EntityPtr pSrcShape);
    virtual void doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);
};

class Gfc2PointShapeFrom2 : public Gfc2SolidShapeFrom2
{
    GFCENGINE_DEC_OBJECT(Gfc2PointShapeFrom2, GfcShapeFrom2)
protected:
    virtual gfc::engine::EntityPtr createShape(gfc::engine::EntityPtr pSrcShape);
    virtual void doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);

};

class Gfc2BaseLineShapeFrom2 : public Gfc2SolidShapeFrom2
{
    //GFCENGINE_DEC_OBJECT(Gfc2BaseLineShapeFrom2, GfcShapeFrom2)
protected:
    virtual void doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);
    virtual ggp::CPolygon* createStartPolygon(gfc::engine::EntityPtr pSrcShape) = 0;
    virtual void doTransformExtruded(ggp::CLine2d* pLine, gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);
    virtual void doTransformRevolved(ggp::CArc2d* pArc, gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);
};

class Gfc2LineShapeFrom2 : public Gfc2BaseLineShapeFrom2
{
    GFCENGINE_DEC_OBJECT(Gfc2LineShapeFrom2, GfcShapeFrom2)
protected:
    virtual gfc::engine::EntityPtr createShape(gfc::engine::EntityPtr pSrcShape);
    virtual ggp::CPolygon* createStartPolygon(gfc::engine::EntityPtr pSrcShape);
    virtual void doTransformExtruded(ggp::CLine2d* pLine, gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);
};

class Gfc2SectionLineShapeFrom2 : public Gfc2BaseLineShapeFrom2
{
    GFCENGINE_DEC_OBJECT(Gfc2SectionLineShapeFrom2, GfcShapeFrom2)
protected:
    virtual gfc::engine::EntityPtr createShape(gfc::engine::EntityPtr pSrcShape);
    virtual ggp::CPolygon* createStartPolygon(gfc::engine::EntityPtr pSrcShape);
};

class Gfc2FaceShapeFrom2 : public Gfc2SolidShapeFrom2
{
    GFCENGINE_DEC_OBJECT(Gfc2FaceShapeFrom2, GfcShapeFrom2)
protected:
    virtual gfc::engine::EntityPtr createShape(gfc::engine::EntityPtr pSrcShape);
    virtual void doTransform(gfc::engine::EntityPtr pSrcShape, gfc::engine::EntityPtr pDestShape);
};

#endif // !GFCSHAPEFROM2_H
