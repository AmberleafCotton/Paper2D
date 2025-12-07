// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTileMap.h"

#ifdef PAPER2D_PaperTileMap_generated_h
#error "PaperTileMap.generated.h already included, missing '#pragma once' in PaperTileMap.h"
#endif
#define PAPER2D_PaperTileMap_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperTileMap ************************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_41_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperTileMap, PAPER2D_API)


PAPER2D_API UClass* Z_Construct_UClass_UPaperTileMap_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_41_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTileMap(); \
	friend struct Z_Construct_UClass_UPaperTileMap_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperTileMap_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTileMap, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperTileMap_NoRegister) \
	DECLARE_SERIALIZER(UPaperTileMap) \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_41_ARCHIVESERIALIZER


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_41_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperTileMap(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTileMap) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperTileMap); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTileMap); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTileMap(UPaperTileMap&&) = delete; \
	UPaperTileMap(const UPaperTileMap&) = delete; \
	PAPER2D_API virtual ~UPaperTileMap();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_38_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_41_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_41_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h_41_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTileMap;

// ********** End Class UPaperTileMap **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMap_h

// ********** Begin Enum ETileMapProjectionMode ****************************************************
#define FOREACH_ENUM_ETILEMAPPROJECTIONMODE(op) \
	op(ETileMapProjectionMode::Orthogonal) \
	op(ETileMapProjectionMode::IsometricDiamond) \
	op(ETileMapProjectionMode::IsometricStaggered) \
	op(ETileMapProjectionMode::HexagonalStaggered) 

namespace ETileMapProjectionMode { enum Type : int; }
template<> PAPER2D_API UEnum* StaticEnum<ETileMapProjectionMode::Type>();
// ********** End Enum ETileMapProjectionMode ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
