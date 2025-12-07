// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTileLayer.h"

#ifdef PAPER2D_PaperTileLayer_generated_h
#error "PaperTileLayer.generated.h already included, missing '#pragma once' in PaperTileLayer.h"
#endif
#define PAPER2D_PaperTileLayer_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPaperTileInfo ****************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h_28_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPaperTileInfo_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FPaperTileInfo;
// ********** End ScriptStruct FPaperTileInfo ******************************************************

// ********** Begin Class UPaperTileLayer **********************************************************
PAPER2D_API UClass* Z_Construct_UClass_UPaperTileLayer_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h_114_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTileLayer(); \
	friend struct Z_Construct_UClass_UPaperTileLayer_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperTileLayer_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTileLayer, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperTileLayer_NoRegister) \
	DECLARE_SERIALIZER(UPaperTileLayer)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h_114_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperTileLayer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTileLayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperTileLayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTileLayer); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTileLayer(UPaperTileLayer&&) = delete; \
	UPaperTileLayer(const UPaperTileLayer&) = delete; \
	PAPER2D_API virtual ~UPaperTileLayer();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h_111_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h_114_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h_114_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h_114_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTileLayer;

// ********** End Class UPaperTileLayer ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileLayer_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
