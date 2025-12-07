// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTileSet.h"

#ifdef PAPER2D_PaperTileSet_generated_h
#error "PaperTileSet.generated.h already included, missing '#pragma once' in PaperTileSet.h"
#endif
#define PAPER2D_PaperTileSet_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPaperTileMetadata ************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPaperTileMetadata_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FPaperTileMetadata;
// ********** End ScriptStruct FPaperTileMetadata **************************************************

// ********** Begin ScriptStruct FPaperTileSetTerrain **********************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_62_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPaperTileSetTerrain_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FPaperTileSetTerrain;
// ********** End ScriptStruct FPaperTileSetTerrain ************************************************

// ********** Begin Class UPaperTileSet ************************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_79_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperTileSet, PAPER2D_API)


PAPER2D_API UClass* Z_Construct_UClass_UPaperTileSet_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_79_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTileSet(); \
	friend struct Z_Construct_UClass_UPaperTileSet_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperTileSet_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTileSet, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperTileSet_NoRegister) \
	DECLARE_SERIALIZER(UPaperTileSet) \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_79_ARCHIVESERIALIZER


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_79_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperTileSet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTileSet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperTileSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTileSet); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTileSet(UPaperTileSet&&) = delete; \
	UPaperTileSet(const UPaperTileSet&) = delete; \
	PAPER2D_API virtual ~UPaperTileSet();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_76_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_79_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_79_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h_79_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTileSet;

// ********** End Class UPaperTileSet **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileSet_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
