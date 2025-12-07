// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperSpriteActor.h"

#ifdef PAPER2D_PaperSpriteActor_generated_h
#error "PaperSpriteActor.generated.h already included, missing '#pragma once' in PaperSpriteActor.h"
#endif
#define PAPER2D_PaperSpriteActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APaperSpriteActor ********************************************************
PAPER2D_API UClass* Z_Construct_UClass_APaperSpriteActor_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteActor_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAPaperSpriteActor(); \
	friend struct Z_Construct_UClass_APaperSpriteActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_APaperSpriteActor_NoRegister(); \
public: \
	DECLARE_CLASS2(APaperSpriteActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_APaperSpriteActor_NoRegister) \
	DECLARE_SERIALIZER(APaperSpriteActor)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteActor_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API APaperSpriteActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APaperSpriteActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, APaperSpriteActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APaperSpriteActor); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APaperSpriteActor(APaperSpriteActor&&) = delete; \
	APaperSpriteActor(const APaperSpriteActor&) = delete; \
	PAPER2D_API virtual ~APaperSpriteActor();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteActor_h_18_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteActor_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteActor_h_21_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteActor_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APaperSpriteActor;

// ********** End Class APaperSpriteActor **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
