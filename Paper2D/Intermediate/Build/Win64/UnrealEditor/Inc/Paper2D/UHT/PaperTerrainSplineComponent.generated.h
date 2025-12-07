// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTerrainSplineComponent.h"

#ifdef PAPER2D_PaperTerrainSplineComponent_generated_h
#error "PaperTerrainSplineComponent.generated.h already included, missing '#pragma once' in PaperTerrainSplineComponent.h"
#endif
#define PAPER2D_PaperTerrainSplineComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperTerrainSplineComponent *********************************************
PAPER2D_API UClass* Z_Construct_UClass_UPaperTerrainSplineComponent_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainSplineComponent_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTerrainSplineComponent(); \
	friend struct Z_Construct_UClass_UPaperTerrainSplineComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperTerrainSplineComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTerrainSplineComponent, USplineComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperTerrainSplineComponent_NoRegister) \
	DECLARE_SERIALIZER(UPaperTerrainSplineComponent)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainSplineComponent_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperTerrainSplineComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTerrainSplineComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperTerrainSplineComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTerrainSplineComponent); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTerrainSplineComponent(UPaperTerrainSplineComponent&&) = delete; \
	UPaperTerrainSplineComponent(const UPaperTerrainSplineComponent&) = delete; \
	PAPER2D_API virtual ~UPaperTerrainSplineComponent();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainSplineComponent_h_11_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainSplineComponent_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainSplineComponent_h_14_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainSplineComponent_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTerrainSplineComponent;

// ********** End Class UPaperTerrainSplineComponent ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainSplineComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
