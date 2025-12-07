// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTerrainComponent.h"

#ifdef PAPER2D_PaperTerrainComponent_generated_h
#error "PaperTerrainComponent.generated.h already included, missing '#pragma once' in PaperTerrainComponent.h"
#endif
#define PAPER2D_PaperTerrainComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FLinearColor;

// ********** Begin Class UPaperTerrainComponent ***************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_RPC_WRAPPERS \
	DECLARE_FUNCTION(execSetTerrainColor);


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperTerrainComponent, PAPER2D_API)


PAPER2D_API UClass* Z_Construct_UClass_UPaperTerrainComponent_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTerrainComponent(); \
	friend struct Z_Construct_UClass_UPaperTerrainComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperTerrainComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTerrainComponent, UPrimitiveComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperTerrainComponent_NoRegister) \
	DECLARE_SERIALIZER(UPaperTerrainComponent) \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_ARCHIVESERIALIZER


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperTerrainComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTerrainComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperTerrainComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTerrainComponent); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTerrainComponent(UPaperTerrainComponent&&) = delete; \
	UPaperTerrainComponent(const UPaperTerrainComponent&) = delete; \
	PAPER2D_API virtual ~UPaperTerrainComponent();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_53_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_RPC_WRAPPERS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h_56_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTerrainComponent;

// ********** End Class UPaperTerrainComponent *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
