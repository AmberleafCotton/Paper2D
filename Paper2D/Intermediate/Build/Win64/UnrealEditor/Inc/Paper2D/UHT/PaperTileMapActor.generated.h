// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTileMapActor.h"

#ifdef PAPER2D_PaperTileMapActor_generated_h
#error "PaperTileMapActor.generated.h already included, missing '#pragma once' in PaperTileMapActor.h"
#endif
#define PAPER2D_PaperTileMapActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APaperTileMapActor *******************************************************
PAPER2D_API UClass* Z_Construct_UClass_APaperTileMapActor_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapActor_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAPaperTileMapActor(); \
	friend struct Z_Construct_UClass_APaperTileMapActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_APaperTileMapActor_NoRegister(); \
public: \
	DECLARE_CLASS2(APaperTileMapActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_APaperTileMapActor_NoRegister) \
	DECLARE_SERIALIZER(APaperTileMapActor)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapActor_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API APaperTileMapActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APaperTileMapActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, APaperTileMapActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APaperTileMapActor); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APaperTileMapActor(APaperTileMapActor&&) = delete; \
	APaperTileMapActor(const APaperTileMapActor&) = delete; \
	PAPER2D_API virtual ~APaperTileMapActor();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapActor_h_19_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapActor_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapActor_h_22_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapActor_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APaperTileMapActor;

// ********** End Class APaperTileMapActor *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperTileMapActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
