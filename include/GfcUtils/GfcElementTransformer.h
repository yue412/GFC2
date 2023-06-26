#ifndef GFCELEMENTTRANSFORMER_H
#define GFCELEMENTTRANSFORMER_H

#include "GfcEngine/SysMarco.h"
#include "GfcEngine/Entity.h"
#include <memory>

namespace gfc {
    namespace engine {
        class CEntity;
    }
}

class GfcShapeTransformer;

class GfcElementTransformer : public gfc::engine::CObject
{
    GFCENGINE_DEC_FACTORY(GfcElementTransformer, 0, std::wstring)
public:
    GfcElementTransformer();
    virtual ~GfcElementTransformer();
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape) = 0;
    virtual std::wstring elementName() = 0;
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity) = 0;
};

class GfcColumnTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcColumnTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Column"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcForceWallTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcForceWallTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2ForceWall"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcInsulatingWallTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcInsulatingWallTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2InsulatingWall"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcMasonryReinfTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcMasonryReinfTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2MasonryReinf"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPierTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPierTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Pier"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcDoorTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcDoorTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Door"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcWindowTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcWindowTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Window"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcDoorWinTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcDoorWinTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2DoorWin"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcWallHoleTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcWallHoleTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2WallHole"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRibbonWindowTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRibbonWindowTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2RibbonWindow"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRibbonOpeningTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRibbonOpeningTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2RibbonOpening"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSwingWinTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSwingWinTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SwingWin"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcDormerTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcDormerTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Dormer"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcLintelTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcLintelTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Lintel"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcAlcoveTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcAlcoveTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Alcove"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcBeamTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcBeamTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Beam"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcEmbedBeamTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcEmbedBeamTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2EmbedBeam"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcLinkBeamTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcLinkBeamTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2LinkBeam"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRingBeamTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRingBeamTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2RingBeam"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSlabTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSlabTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Slab"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSpiralSlabTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSpiralSlabTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SpiralSlab"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcReinforcementTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcReinforcementTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Reinforcement"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcNegReinforcementTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcNegReinforcementTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2NegReinforcement"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSlabHoleTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSlabHoleTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SlabHole"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcTieColumnTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcTieColumnTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2TieColumn"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcColumnCapTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcColumnCapTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2ColumnCap"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcColumnBaseTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcColumnBaseTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2ColumnBase"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcStairTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcStairTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Stair"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcFlightTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcFlightTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Flight"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSpiralFlightTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSpiralFlightTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SpiralFlight"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRoomTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRoomTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Room"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcFloorFinishTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcFloorFinishTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2FloorFinish"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcCeilingTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcCeilingTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Ceiling"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcHungCeilingTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcHungCeilingTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2HungCeiling"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcWallFaceFinishTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcWallFaceFinishTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2WallFaceFinish"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcDadoTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcDadoTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Dado"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSkirtTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSkirtTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Skirt"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcIsolatedColumnFinishTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcIsolatedColumnFinishTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2IsolatedColumnFinish"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcExcavatedEarthTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcExcavatedEarthTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2ExcavatedEarth"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcDitchEarthTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcDitchEarthTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2DitchEarth"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPitEarthTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPitEarthTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2PitEarth"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcExcavatedEarthBackfillTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcExcavatedEarthBackfillTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2ExcavatedEarthBackfill"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcDitchEarthBackfillTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcDitchEarthBackfillTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2DitchEarthBackfill"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPitEarthBackfillTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPitEarthBackfillTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2PitEarthBackfill"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRoomBackFillTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRoomBackFillTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2RoomBackfill"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcFDBeamTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcFDBeamTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2FDBeam"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRaftFDTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRaftFDTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2RaftFD"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRaftFDReinfTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRaftFDReinfTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2RaftFDReinf"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRaftFDNegReinfTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRaftFDNegReinfTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2RaftFDNegReinf"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcStripFDTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcStripFDTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2StripFD"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcIsolatedFDTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcIsolatedFDTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2IsolatedFD"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPileCapTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPileCapTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2PileCap"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPileTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPileTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Pile"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcBeddingTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcBeddingTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Bedding"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSumpTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSumpTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Sump"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcFDSlabStripTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcFDSlabStripTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2FDSlabStrip"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcFloorAreaTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcFloorAreaTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2FloorArea"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSiteLevelingTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSiteLevelingTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SiteLeveling"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcApronTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcApronTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Apron"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcFootStepTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcFootStepTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2FootStep"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPostCastStripTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPostCastStripTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2PostCastStrip"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcEaveTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcEaveTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Eave"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcCanopyTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcCanopyTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Canopy"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcBalconyTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcBalconyTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Balcony"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRoofTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRoofTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Roof"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcInsulatingLayerTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcInsulatingLayerTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2InsulatingLayer"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcParapetTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcParapetTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Parapet"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcCopingTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcCopingTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Coping"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcCustomPointTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcCustomPointTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2CustomPoint"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcCustomLineTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcCustomLineTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2CustomLine"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcCustomFaceTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcCustomFaceTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2CustomFace"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSlabStripTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSlabStripTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SlabStrip"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcTrenchTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcTrenchTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Trench"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcStripFDUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcStripFDUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2StripFDUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcIsolatedFDUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcIsolatedFDUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2IsolatedFDUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPileCapUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPileCapUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2PileCapUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcTrenchUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcTrenchUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2TrenchUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcStairWellTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcStairWellTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2StairWell"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcInsulatingWallUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcInsulatingWallUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2InsulatingWallUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcExcavatedEarthBackfillUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcExcavatedEarthBackfillUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2ExcavatedEarthBackfillUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcDitchEarthBackfillUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcDitchEarthBackfillUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2DitchEarthBackfillUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcPitEarthBackfillUnitTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcPitEarthBackfillUnitTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2PitEarthBackfillUnit"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcAirDefenseWallTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcAirDefenseWallTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2AirDefenseWall"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcAloneBeamFinishTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcAloneBeamFinishTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2AloneBeamFinish"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcHollowFloorSlabTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcHollowFloorSlabTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2HollowFloorSlab"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcHollowFloorColumnCapTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcHollowFloorColumnCapTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2HollowFloorColumnCap"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcHandrailTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcHandrailTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Handrail"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcRampTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcRampTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2Ramp"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcMainRibsBeamTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcMainRibsBeamTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2MainRibsBeam"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSubRibsBeamTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSubRibsBeamTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SubRibsBeam"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSubRibsBeamBottomBarTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSubRibsBeamBottomBarTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SubRibsBeamBottomBar"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcSubRibsBeamSptBarTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcSubRibsBeamSptBarTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2SubRibsBeamSptBar"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcNeutralPositionTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcNeutralPositionTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2NeutralPosition"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcHollowFloorReinforcementTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcHollowFloorReinforcementTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2HollowFloorReinforcement"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcCurtainWallTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcCurtainWallTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2CurtainWall"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcMasonryColumnTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcMasonryColumnTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2MasonryColumn"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcBrickWallTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcBrickWallTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2BrickWall"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcConstrainedAreaTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcConstrainedAreaTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2ConstrainedArea"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

class GfcBrickMembraneTransformer : public GfcElementTransformer
{
    GFCENGINE_DEC_OBJECT(GfcBrickMembraneTransformer, GfcElementTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape);
    virtual std::wstring elementName() { return L"Gfc2BrickMembrane"; }
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity);
};

#endif // !GFCSHAPETRANSFORMER_H
