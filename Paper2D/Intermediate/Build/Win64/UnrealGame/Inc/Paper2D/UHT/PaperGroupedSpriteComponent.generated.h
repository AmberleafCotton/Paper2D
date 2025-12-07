// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperGroupedSpriteComponent.h"

#ifdef PAPER2D_PaperGroupedSpriteComponent_generated_h
#error "PaperGroupedSpriteComponent.generated.h already included, missing '#pragma once' in PaperGroupedSpriteComponent.h"
#endif
#define PAPER2D_PaperGroupedSpriteComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UPaperSprite;
struct FLinearColor;

// ********** Begin ScriptStruct FSpriteInstanceData ***********************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSpriteInstanceData_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FSpriteInstanceData;
// ********** End ScriptStruct FSpriteInstanceData *************************************************

// ********** Begin Class UPaperGroupedSpriteComponent *********************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_60_RPC_WRAPPERS \
	DECLARE_FUNCTION(execSortInstancesAlongAxis); \
	DECLARE_FUNCTION(execGetInstanceCount); \
	DECLARE_FUNCTION(execClearInstances); \
	DECLARE_FUNCTION(execRemoveInstance); \
	DECLARE_FUNCTION(execUpdateInstanceColor); \
	DECLARE_FUNCTION(execUpdateInstanceTransform); \
	DECLARE_FUNCTION(execGetInstanceTransform); \
	DECLARE_FUNCTION(execAddInstance);


PAPER2D_API UClass* Z_Construct_UClass_UPaperGroupedSpriteComponent_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_60_INCLASS \
private: \
	static void StaticRegisterNativesUPaperGroupedSpriteComponent(); \
	friend struct Z_Construct_UClass_UPaperGroupedSpriteComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperGroupedSpriteComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperGroupedSpriteComponent, UMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperGroupedSpriteComponent_NoRegister) \
	DECLARE_SERIALIZER(UPaperGroupedSpriteComponent)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_60_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperGroupedSpriteComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperGroupedSpriteComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperGroupedSpriteComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperGroupedSpriteComponent); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperGroupedSpriteComponent(UPaperGroupedSpriteComponent&&) = delete; \
	UPaperGroupedSpriteComponent(const UPaperGroupedSpriteComponent&) = delete; \
	PAPER2D_API virtual ~UPaperGroupedSpriteComponent();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_57_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_60_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_60_RPC_WRAPPERS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_60_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h_60_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperGroupedSpriteComponent;

// ********** End Class UPaperGroupedSpriteComponent ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperGroupedSpriteComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
