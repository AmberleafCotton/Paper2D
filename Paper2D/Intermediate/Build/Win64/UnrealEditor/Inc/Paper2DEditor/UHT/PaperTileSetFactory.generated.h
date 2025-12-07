// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperTileSetFactory.h"

#ifdef PAPER2DEDITOR_PaperTileSetFactory_generated_h
#error "PaperTileSetFactory.generated.h already included, missing '#pragma once' in PaperTileSetFactory.h"
#endif
#define PAPER2DEDITOR_PaperTileSetFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperTileSetFactory *****************************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperTileSetFactory_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileSetFactory_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUPaperTileSetFactory(); \
	friend struct Z_Construct_UClass_UPaperTileSetFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperTileSetFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperTileSetFactory, UFactory, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UPaperTileSetFactory_NoRegister) \
	DECLARE_SERIALIZER(UPaperTileSetFactory)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileSetFactory_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaperTileSetFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperTileSetFactory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperTileSetFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperTileSetFactory); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperTileSetFactory(UPaperTileSetFactory&&) = delete; \
	UPaperTileSetFactory(const UPaperTileSetFactory&) = delete; \
	NO_API virtual ~UPaperTileSetFactory();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileSetFactory_h_12_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileSetFactory_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileSetFactory_h_15_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileSetFactory_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperTileSetFactory;

// ********** End Class UPaperTileSetFactory *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperTileSetFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
