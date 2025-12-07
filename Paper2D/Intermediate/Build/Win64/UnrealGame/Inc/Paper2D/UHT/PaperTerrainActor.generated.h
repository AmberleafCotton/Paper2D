// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTerrainActor.h"

#ifdef PAPER2D_PaperTerrainActor_generated_h
#error "PaperTerrainActor.generated.h already included, missing '#pragma once' in PaperTerrainActor.h"
#endif
#define PAPER2D_PaperTerrainActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APaperTerrainActor *******************************************************
PAPER2D_API UClass* Z_Construct_UClass_APaperTerrainActor_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainActor_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAPaperTerrainActor(); \
	friend struct Z_Construct_UClass_APaperTerrainActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_APaperTerrainActor_NoRegister(); \
public: \
	DECLARE_CLASS2(APaperTerrainActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_APaperTerrainActor_NoRegister) \
	DECLARE_SERIALIZER(APaperTerrainActor)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainActor_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API APaperTerrainActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APaperTerrainActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, APaperTerrainActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APaperTerrainActor); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APaperTerrainActor(APaperTerrainActor&&) = delete; \
	APaperTerrainActor(const APaperTerrainActor&) = delete; \
	PAPER2D_API virtual ~APaperTerrainActor();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainActor_h_18_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainActor_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainActor_h_21_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainActor_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APaperTerrainActor;

// ********** End Class APaperTerrainActor *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTerrainActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
