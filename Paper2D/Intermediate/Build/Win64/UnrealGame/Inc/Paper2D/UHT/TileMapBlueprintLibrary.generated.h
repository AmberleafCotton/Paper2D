// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TileMapBlueprintLibrary.h"

#ifdef PAPER2D_TileMapBlueprintLibrary_generated_h
#error "TileMapBlueprintLibrary.generated.h already included, missing '#pragma once' in TileMapBlueprintLibrary.h"
#endif
#define PAPER2D_TileMapBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UPaperTileSet;
struct FPaperTileInfo;

// ********** Begin Class UTileMapBlueprintLibrary *************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execMakeTile); \
	DECLARE_FUNCTION(execBreakTile); \
	DECLARE_FUNCTION(execGetTileTransform); \
	DECLARE_FUNCTION(execGetTileUserData);


PAPER2D_API UClass* Z_Construct_UClass_UTileMapBlueprintLibrary_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTileMapBlueprintLibrary(); \
	friend struct Z_Construct_UClass_UTileMapBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UTileMapBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UTileMapBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UTileMapBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(UTileMapBlueprintLibrary)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTileMapBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTileMapBlueprintLibrary(UTileMapBlueprintLibrary&&) = delete; \
	UTileMapBlueprintLibrary(const UTileMapBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTileMapBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTileMapBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTileMapBlueprintLibrary) \
	NO_API virtual ~UTileMapBlueprintLibrary();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_17_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_20_INCLASS_NO_PURE_DECLS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTileMapBlueprintLibrary;

// ********** End Class UTileMapBlueprintLibrary ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_TileMapBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
