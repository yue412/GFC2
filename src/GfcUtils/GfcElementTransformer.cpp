#include "GfcUtils\GfcElementTransformer.h"
#include "GfcUtils\GfcShapeTransformer.h"

GFCENGINE_IMP_FACTORY(GfcElementTransformer, 0)

GfcElementTransformer::GfcElementTransformer()
{
}


GfcElementTransformer::~GfcElementTransformer()
{
}

GFCENGINE_IMP_OBJECT(GfcColumnTransformer, L"Column", 0)

std::shared_ptr<gfc::engine::CEntity> GfcColumnTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return pTransformer->toPointShape(pShape);
}

void GfcColumnTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcForceWallTransformer, L"ForceWall", 0)

std::shared_ptr<gfc::engine::CEntity> GfcForceWallTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcForceWallTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcInsulatingWallTransformer, L"InsulatingWall", 0)

std::shared_ptr<gfc::engine::CEntity> GfcInsulatingWallTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcInsulatingWallTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcMasonryReinfTransformer, L"MasonryReinf", 0)

std::shared_ptr<gfc::engine::CEntity> GfcMasonryReinfTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcMasonryReinfTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPierTransformer, L"Pier", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPierTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPierTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcDoorTransformer, L"Door", 0)

std::shared_ptr<gfc::engine::CEntity> GfcDoorTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcDoorTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcWindowTransformer, L"Window", 0)

std::shared_ptr<gfc::engine::CEntity> GfcWindowTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcWindowTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcDoorWinTransformer, L"DoorWin", 0)

std::shared_ptr<gfc::engine::CEntity> GfcDoorWinTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcDoorWinTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcWallHoleTransformer, L"WallHole", 0)

std::shared_ptr<gfc::engine::CEntity> GfcWallHoleTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcWallHoleTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRibbonWindowTransformer, L"RibbonWindow", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRibbonWindowTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRibbonWindowTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRibbonOpeningTransformer, L"RibbonOpening", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRibbonOpeningTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRibbonOpeningTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSwingWinTransformer, L"SwingWin", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSwingWinTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSwingWinTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcDormerTransformer, L"Dormer", 0)

std::shared_ptr<gfc::engine::CEntity> GfcDormerTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcDormerTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcLintelTransformer, L"Lintel", 0)

std::shared_ptr<gfc::engine::CEntity> GfcLintelTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcLintelTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcAlcoveTransformer, L"Alcove", 0)

std::shared_ptr<gfc::engine::CEntity> GfcAlcoveTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcAlcoveTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcBeamTransformer, L"Beam", 0)

std::shared_ptr<gfc::engine::CEntity> GfcBeamTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcBeamTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcEmbedBeamTransformer, L"EmbedBeam", 0)

std::shared_ptr<gfc::engine::CEntity> GfcEmbedBeamTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcEmbedBeamTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcLinkBeamTransformer, L"LinkBeam", 0)

std::shared_ptr<gfc::engine::CEntity> GfcLinkBeamTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcLinkBeamTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRingBeamTransformer, L"RingBeam", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRingBeamTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRingBeamTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSlabTransformer, L"Slab", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSlabTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSlabTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSpiralSlabTransformer, L"SpiralSlab", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSpiralSlabTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSpiralSlabTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcReinforcementTransformer, L"Reinforcement", 0)

std::shared_ptr<gfc::engine::CEntity> GfcReinforcementTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcReinforcementTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcNegReinforcementTransformer, L"NegReinforcement", 0)

std::shared_ptr<gfc::engine::CEntity> GfcNegReinforcementTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcNegReinforcementTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSlabHoleTransformer, L"SlabHole", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSlabHoleTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSlabHoleTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcTieColumnTransformer, L"TieColumn", 0)

std::shared_ptr<gfc::engine::CEntity> GfcTieColumnTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcTieColumnTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcColumnCapTransformer, L"ColumnCap", 0)

std::shared_ptr<gfc::engine::CEntity> GfcColumnCapTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcColumnCapTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcColumnBaseTransformer, L"ColumnBase", 0)

std::shared_ptr<gfc::engine::CEntity> GfcColumnBaseTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcColumnBaseTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcStairTransformer, L"Stair", 0)

std::shared_ptr<gfc::engine::CEntity> GfcStairTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcStairTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcFlightTransformer, L"Flight", 0)

std::shared_ptr<gfc::engine::CEntity> GfcFlightTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcFlightTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSpiralFlightTransformer, L"SpiralFlight", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSpiralFlightTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSpiralFlightTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRoomTransformer, L"Room", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRoomTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRoomTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcFloorFinishTransformer, L"FloorFinish", 0)

std::shared_ptr<gfc::engine::CEntity> GfcFloorFinishTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcFloorFinishTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcCeilingTransformer, L"Ceiling", 0)

std::shared_ptr<gfc::engine::CEntity> GfcCeilingTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcCeilingTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcHungCeilingTransformer, L"HungCeiling", 0)

std::shared_ptr<gfc::engine::CEntity> GfcHungCeilingTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcHungCeilingTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcWallFaceFinishTransformer, L"WallFaceFinish", 0)

std::shared_ptr<gfc::engine::CEntity> GfcWallFaceFinishTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcWallFaceFinishTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcDadoTransformer, L"Dado", 0)

std::shared_ptr<gfc::engine::CEntity> GfcDadoTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcDadoTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSkirtTransformer, L"Skirt", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSkirtTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSkirtTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcIsolatedColumnFinishTransformer, L"IsolatedColumnFinish", 0)

std::shared_ptr<gfc::engine::CEntity> GfcIsolatedColumnFinishTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcIsolatedColumnFinishTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcExcavatedEarthTransformer, L"ExcavatedEarth", 0)

std::shared_ptr<gfc::engine::CEntity> GfcExcavatedEarthTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcExcavatedEarthTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcDitchEarthTransformer, L"DitchEarth", 0)

std::shared_ptr<gfc::engine::CEntity> GfcDitchEarthTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcDitchEarthTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPitEarthTransformer, L"PitEarth", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPitEarthTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPitEarthTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcExcavatedEarthBackfillTransformer, L"ExcavatedEarthBackfill", 0)

std::shared_ptr<gfc::engine::CEntity> GfcExcavatedEarthBackfillTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcExcavatedEarthBackfillTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcDitchEarthBackfillTransformer, L"DitchEarthBackfill", 0)

std::shared_ptr<gfc::engine::CEntity> GfcDitchEarthBackfillTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcDitchEarthBackfillTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPitEarthBackfillTransformer, L"PitEarthBackfill", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPitEarthBackfillTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPitEarthBackfillTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRoomBackFillTransformer, L"RoomBackfill", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRoomBackFillTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRoomBackFillTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcFDBeamTransformer, L"FDBeam", 0)

std::shared_ptr<gfc::engine::CEntity> GfcFDBeamTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcFDBeamTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRaftFDTransformer, L"RaftFD", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRaftFDTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRaftFDTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRaftFDReinfTransformer, L"RaftFDReinf", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRaftFDReinfTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRaftFDReinfTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRaftFDNegReinfTransformer, L"RaftFDNegReinf", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRaftFDNegReinfTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRaftFDNegReinfTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcStripFDTransformer, L"StripFD", 0)

std::shared_ptr<gfc::engine::CEntity> GfcStripFDTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcStripFDTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcIsolatedFDTransformer, L"IsolatedFD", 0)

std::shared_ptr<gfc::engine::CEntity> GfcIsolatedFDTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcIsolatedFDTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPileCapTransformer, L"PileCap", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPileCapTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPileCapTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPileTransformer, L"Pile", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPileTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPileTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcBeddingTransformer, L"Bedding", 0)

std::shared_ptr<gfc::engine::CEntity> GfcBeddingTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcBeddingTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSumpTransformer, L"Sump", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSumpTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSumpTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcFDSlabStripTransformer, L"FDSlabStrip", 0)

std::shared_ptr<gfc::engine::CEntity> GfcFDSlabStripTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcFDSlabStripTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcFloorAreaTransformer, L"FloorArea", 0)

std::shared_ptr<gfc::engine::CEntity> GfcFloorAreaTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcFloorAreaTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSiteLevelingTransformer, L"SiteLeveling", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSiteLevelingTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSiteLevelingTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcApronTransformer, L"Apron", 0)

std::shared_ptr<gfc::engine::CEntity> GfcApronTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcApronTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcFootStepTransformer, L"FootStep", 0)

std::shared_ptr<gfc::engine::CEntity> GfcFootStepTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcFootStepTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPostCastStripTransformer, L"PostCastStrip", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPostCastStripTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPostCastStripTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcEaveTransformer, L"Eave", 0)

std::shared_ptr<gfc::engine::CEntity> GfcEaveTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcEaveTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcCanopyTransformer, L"Canopy", 0)

std::shared_ptr<gfc::engine::CEntity> GfcCanopyTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcCanopyTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcBalconyTransformer, L"Balcony", 0)

std::shared_ptr<gfc::engine::CEntity> GfcBalconyTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcBalconyTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRoofTransformer, L"Roof", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRoofTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRoofTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcInsulatingLayerTransformer, L"InsulatingLayer", 0)

std::shared_ptr<gfc::engine::CEntity> GfcInsulatingLayerTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcInsulatingLayerTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcParapetTransformer, L"Parapet", 0)

std::shared_ptr<gfc::engine::CEntity> GfcParapetTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcParapetTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcCopingTransformer, L"Coping", 0)

std::shared_ptr<gfc::engine::CEntity> GfcCopingTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcCopingTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcCustomPointTransformer, L"CustomPoint", 0)

std::shared_ptr<gfc::engine::CEntity> GfcCustomPointTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcCustomPointTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcCustomLineTransformer, L"CustomLine", 0)

std::shared_ptr<gfc::engine::CEntity> GfcCustomLineTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcCustomLineTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcCustomFaceTransformer, L"CustomFace", 0)

std::shared_ptr<gfc::engine::CEntity> GfcCustomFaceTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcCustomFaceTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSlabStripTransformer, L"SlabStrip", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSlabStripTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSlabStripTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcTrenchTransformer, L"Trench", 0)

std::shared_ptr<gfc::engine::CEntity> GfcTrenchTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcTrenchTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcStripFDUnitTransformer, L"StripFDUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcStripFDUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcStripFDUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcIsolatedFDUnitTransformer, L"IsolatedFDUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcIsolatedFDUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcIsolatedFDUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPileCapUnitTransformer, L"PileCapUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPileCapUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPileCapUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcTrenchUnitTransformer, L"TrenchUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcTrenchUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcTrenchUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcStairWellTransformer, L"StairWell", 0)

std::shared_ptr<gfc::engine::CEntity> GfcStairWellTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcStairWellTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcInsulatingWallUnitTransformer, L"InsulatingWallUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcInsulatingWallUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcInsulatingWallUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcExcavatedEarthBackfillUnitTransformer, L"ExcavatedEarthBackfillUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcExcavatedEarthBackfillUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcExcavatedEarthBackfillUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcDitchEarthBackfillUnitTransformer, L"DitchEarthBackfillUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcDitchEarthBackfillUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcDitchEarthBackfillUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcPitEarthBackfillUnitTransformer, L"PitEarthBackfillUnit", 0)

std::shared_ptr<gfc::engine::CEntity> GfcPitEarthBackfillUnitTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcPitEarthBackfillUnitTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcAirDefenseWallTransformer, L"AirDefenseWall", 0)

std::shared_ptr<gfc::engine::CEntity> GfcAirDefenseWallTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcAirDefenseWallTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcAloneBeamFinishTransformer, L"AloneBeamFinish", 0)

std::shared_ptr<gfc::engine::CEntity> GfcAloneBeamFinishTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcAloneBeamFinishTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcHollowFloorSlabTransformer, L"HollowFloorSlab", 0)

std::shared_ptr<gfc::engine::CEntity> GfcHollowFloorSlabTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcHollowFloorSlabTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcHollowFloorColumnCapTransformer, L"HollowFloorColumnCap", 0)

std::shared_ptr<gfc::engine::CEntity> GfcHollowFloorColumnCapTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcHollowFloorColumnCapTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcHandrailTransformer, L"Handrail", 0)

std::shared_ptr<gfc::engine::CEntity> GfcHandrailTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcHandrailTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcRampTransformer, L"Ramp", 0)

std::shared_ptr<gfc::engine::CEntity> GfcRampTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcRampTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcMainRibsBeamTransformer, L"MainRibsBeam", 0)

std::shared_ptr<gfc::engine::CEntity> GfcMainRibsBeamTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcMainRibsBeamTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSubRibsBeamTransformer, L"SubRibsBeam", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSubRibsBeamTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSubRibsBeamTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSubRibsBeamBottomBarTransformer, L"SubRibsBeamBottomBar", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSubRibsBeamBottomBarTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSubRibsBeamBottomBarTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcSubRibsBeamSptBarTransformer, L"SubRibsBeamSptBar", 0)

std::shared_ptr<gfc::engine::CEntity> GfcSubRibsBeamSptBarTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcSubRibsBeamSptBarTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcNeutralPositionTransformer, L"NeutralPosition", 0)

std::shared_ptr<gfc::engine::CEntity> GfcNeutralPositionTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcNeutralPositionTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcHollowFloorReinforcementTransformer, L"HollowFloorReinforcement", 0)

std::shared_ptr<gfc::engine::CEntity> GfcHollowFloorReinforcementTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcHollowFloorReinforcementTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcCurtainWallTransformer, L"CurtainWall", 0)

std::shared_ptr<gfc::engine::CEntity> GfcCurtainWallTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcCurtainWallTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcMasonryColumnTransformer, L"MasonryColumn", 0)

std::shared_ptr<gfc::engine::CEntity> GfcMasonryColumnTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcMasonryColumnTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcBrickWallTransformer, L"BrickWall", 0)

std::shared_ptr<gfc::engine::CEntity> GfcBrickWallTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcBrickWallTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcConstrainedAreaTransformer, L"ConstrainedArea", 0)

std::shared_ptr<gfc::engine::CEntity> GfcConstrainedAreaTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcConstrainedAreaTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}

GFCENGINE_IMP_OBJECT(GfcBrickMembraneTransformer, L"BrickMembrane", 0)

std::shared_ptr<gfc::engine::CEntity> GfcBrickMembraneTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcBrickMembraneTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}
