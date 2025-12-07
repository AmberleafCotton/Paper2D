// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTileMapFactory.h"

#ifdef PAPER2DEDITOR_PaperTileMapFactory_generated_h
#error "PaperTileMapFactory.generated.h already included, missing '#pragma once' in PaperTileMapFactory.h"
#endif
#define PAPER2DEDITOR_PaperTileMapFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperTileMapFactory *****************************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperTileMapFactory_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileMapFactory_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTileMapFactory(); \
	friend struct Z_Construct_UClass_UPaperTileMapFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperTileMapFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTileMapFactory, UFactory, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UPaperTileMapFactory_NoRegister) \
	DECLARE_SERIALIZER(UPaperTileMapFactory)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileMapFactory_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaperTileMapFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTileMapFactory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperTileMapFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTileMapFactory); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTileMapFactory(UPaperTileMapFactory&&) = delete; \
	UPaperTileMapFactory(const UPaperTileMapFactory&) = delete; \
	NO_API virtual ~UPaperTileMapFactory();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileMapFactory_h_12_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileMapFactory_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileMapFactory_h_15_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileMapFactory_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTileMapFactory;

// ********** End Class UPaperTileMapFactory *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileMapFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
