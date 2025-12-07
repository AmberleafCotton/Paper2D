// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTerrainMaterial.h"

#ifdef PAPER2D_PaperTerrainMaterial_generated_h
#error "PaperTerrainMaterial.generated.h already included, missing '#pragma once' in PaperTerrainMaterial.h"
#endif
#define PAPER2D_PaperTerrainMaterial_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPaperTerrainMaterialRule *****************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPaperTerrainMaterialRule_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FPaperTerrainMaterialRule;
// ********** End ScriptStruct FPaperTerrainMaterialRule *******************************************

// ********** Begin Class UPaperTerrainMaterial ****************************************************
PAPER2D_API UClass* Z_Construct_UClass_UPaperTerrainMaterial_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h_77_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTerrainMaterial(); \
	friend struct Z_Construct_UClass_UPaperTerrainMaterial_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperTerrainMaterial_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTerrainMaterial, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperTerrainMaterial_NoRegister) \
	DECLARE_SERIALIZER(UPaperTerrainMaterial)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h_77_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperTerrainMaterial(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTerrainMaterial) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperTerrainMaterial); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTerrainMaterial); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTerrainMaterial(UPaperTerrainMaterial&&) = delete; \
	UPaperTerrainMaterial(const UPaperTerrainMaterial&) = delete; \
	PAPER2D_API virtual ~UPaperTerrainMaterial();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h_74_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h_77_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h_77_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h_77_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTerrainMaterial;

// ********** End Class UPaperTerrainMaterial ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainMaterial_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
