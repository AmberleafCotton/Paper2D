// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperSpriteFactory.h"

#ifdef PAPER2DEDITOR_PaperSpriteFactory_generated_h
#error "PaperSpriteFactory.generated.h already included, missing '#pragma once' in PaperSpriteFactory.h"
#endif
#define PAPER2DEDITOR_PaperSpriteFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperSpriteFactory ******************************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperSpriteFactory_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperSpriteFactory_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUPaperSpriteFactory(); \
	friend struct Z_Construct_UClass_UPaperSpriteFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperSpriteFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperSpriteFactory, UFactory, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UPaperSpriteFactory_NoRegister) \
	DECLARE_SERIALIZER(UPaperSpriteFactory)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperSpriteFactory_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaperSpriteFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperSpriteFactory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperSpriteFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperSpriteFactory); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperSpriteFactory(UPaperSpriteFactory&&) = delete; \
	UPaperSpriteFactory(const UPaperSpriteFactory&) = delete; \
	NO_API virtual ~UPaperSpriteFactory();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperSpriteFactory_h_12_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperSpriteFactory_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperSpriteFactory_h_15_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperSpriteFactory_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperSpriteFactory;

// ********** End Class UPaperSpriteFactory ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperSpriteFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
