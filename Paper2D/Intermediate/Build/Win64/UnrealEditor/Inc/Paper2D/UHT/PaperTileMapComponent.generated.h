// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTileMapComponent.h"

#ifdef PAPER2D_PaperTileMapComponent_generated_h
#error "PaperTileMapComponent.generated.h already included, missing '#pragma once' in PaperTileMapComponent.h"
#endif
#define PAPER2D_PaperTileMapComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UPaperTileLayer;
class UPaperTileMap;
struct FLinearColor;
struct FPaperTileInfo;

// ********** Begin Class UPaperTileMapComponent ***************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_RPC_WRAPPERS \
	DECLARE_FUNCTION(execRebuildCollision); \
	DECLARE_FUNCTION(execSetLayerCollision); \
	DECLARE_FUNCTION(execSetDefaultCollisionThickness); \
	DECLARE_FUNCTION(execGetTilePolygon); \
	DECLARE_FUNCTION(execGetTileCenterPosition); \
	DECLARE_FUNCTION(execGetTileCornerPosition); \
	DECLARE_FUNCTION(execMakeTileMapEditable); \
	DECLARE_FUNCTION(execSetLayerColor); \
	DECLARE_FUNCTION(execGetLayerColor); \
	DECLARE_FUNCTION(execSetTileMapColor); \
	DECLARE_FUNCTION(execGetTileMapColor); \
	DECLARE_FUNCTION(execAddNewLayer); \
	DECLARE_FUNCTION(execResizeMap); \
	DECLARE_FUNCTION(execSetTile); \
	DECLARE_FUNCTION(execGetTile); \
	DECLARE_FUNCTION(execGetMapSize); \
	DECLARE_FUNCTION(execSetTileMap); \
	DECLARE_FUNCTION(execOwnsTileMap); \
	DECLARE_FUNCTION(execCreateNewTileMap);


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperTileMapComponent, PAPER2D_API)


PAPER2D_API UClass* Z_Construct_UClass_UPaperTileMapComponent_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTileMapComponent(); \
	friend struct Z_Construct_UClass_UPaperTileMapComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperTileMapComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTileMapComponent, UMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperTileMapComponent_NoRegister) \
	DECLARE_SERIALIZER(UPaperTileMapComponent) \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_ARCHIVESERIALIZER


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperTileMapComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTileMapComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperTileMapComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTileMapComponent); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTileMapComponent(UPaperTileMapComponent&&) = delete; \
	UPaperTileMapComponent(const UPaperTileMapComponent&) = delete; \
	PAPER2D_API virtual ~UPaperTileMapComponent();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_37_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_RPC_WRAPPERS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h_40_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTileMapComponent;

// ********** End Class UPaperTileMapComponent *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
