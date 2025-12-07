// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpriteEditorOnlyTypes.h"

#ifdef PAPER2D_SpriteEditorOnlyTypes_generated_h
#error "SpriteEditorOnlyTypes.generated.h already included, missing '#pragma once' in SpriteEditorOnlyTypes.h"
#endif
#define PAPER2D_SpriteEditorOnlyTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FSpriteGeometryShape **********************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_SpriteEditorOnlyTypes_h_46_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSpriteGeometryShape_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FSpriteGeometryShape;
// ********** End ScriptStruct FSpriteGeometryShape ************************************************

// ********** Begin ScriptStruct FSpriteGeometryCollection *****************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_SpriteEditorOnlyTypes_h_170_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSpriteGeometryCollection_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FSpriteGeometryCollection;
// ********** End ScriptStruct FSpriteGeometryCollection *******************************************

// ********** Begin ScriptStruct FSpriteAssetInitParameters ****************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_SpriteEditorOnlyTypes_h_259_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSpriteAssetInitParameters_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FSpriteAssetInitParameters;
// ********** End ScriptStruct FSpriteAssetInitParameters ******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_SpriteEditorOnlyTypes_h

// ********** Begin Enum ESpriteCollisionMode ******************************************************
#define FOREACH_ENUM_ESPRITECOLLISIONMODE(op) \
	op(ESpriteCollisionMode::None) \
	op(ESpriteCollisionMode::Use2DPhysics) \
	op(ESpriteCollisionMode::Use3DPhysics) 

namespace ESpriteCollisionMode { enum Type : int; }
template<> PAPER2D_API UEnum* StaticEnum<ESpriteCollisionMode::Type>();
// ********** End Enum ESpriteCollisionMode ********************************************************

// ********** Begin Enum ESpriteShapeType **********************************************************
#define FOREACH_ENUM_ESPRITESHAPETYPE(op) \
	op(ESpriteShapeType::Box) \
	op(ESpriteShapeType::Circle) \
	op(ESpriteShapeType::Polygon) 

enum class ESpriteShapeType : uint8;
template<> struct TIsUEnumClass<ESpriteShapeType> { enum { Value = true }; };
template<> PAPER2D_API UEnum* StaticEnum<ESpriteShapeType>();
// ********** End Enum ESpriteShapeType ************************************************************

// ********** Begin Enum ESpritePolygonMode ********************************************************
#define FOREACH_ENUM_ESPRITEPOLYGONMODE(op) \
	op(ESpritePolygonMode::SourceBoundingBox) \
	op(ESpritePolygonMode::TightBoundingBox) \
	op(ESpritePolygonMode::ShrinkWrapped) \
	op(ESpritePolygonMode::FullyCustom) \
	op(ESpritePolygonMode::Diced) 

namespace ESpritePolygonMode { enum Type : int; }
template<> PAPER2D_API UEnum* StaticEnum<ESpritePolygonMode::Type>();
// ********** End Enum ESpritePolygonMode **********************************************************

// ********** Begin Enum ESpritePivotMode **********************************************************
#define FOREACH_ENUM_ESPRITEPIVOTMODE(op) \
	op(ESpritePivotMode::Top_Left) \
	op(ESpritePivotMode::Top_Center) \
	op(ESpritePivotMode::Top_Right) \
	op(ESpritePivotMode::Center_Left) \
	op(ESpritePivotMode::Center_Center) \
	op(ESpritePivotMode::Center_Right) \
	op(ESpritePivotMode::Bottom_Left) \
	op(ESpritePivotMode::Bottom_Center) \
	op(ESpritePivotMode::Bottom_Right) \
	op(ESpritePivotMode::Custom) 

namespace ESpritePivotMode { enum Type : int; }
template<> PAPER2D_API UEnum* StaticEnum<ESpritePivotMode::Type>();
// ********** End Enum ESpritePivotMode ************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
