// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TileMapActorFactory.h"

#ifdef PAPER2DEDITOR_TileMapActorFactory_generated_h
#error "TileMapActorFactory.generated.h already included, missing '#pragma once' in TileMapActorFactory.h"
#endif
#define PAPER2DEDITOR_TileMapActorFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UTileMapActorFactory *****************************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UTileMapActorFactory_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TileMapActorFactory_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUTileMapActorFactory(); \
	friend struct Z_Construct_UClass_UTileMapActorFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UTileMapActorFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UTileMapActorFactory, UActorFactory, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UTileMapActorFactory_NoRegister) \
	DECLARE_SERIALIZER(UTileMapActorFactory)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TileMapActorFactory_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTileMapActorFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTileMapActorFactory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTileMapActorFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTileMapActorFactory); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTileMapActorFactory(UTileMapActorFactory&&) = delete; \
	UTileMapActorFactory(const UTileMapActorFactory&) = delete; \
	NO_API virtual ~UTileMapActorFactory();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TileMapActorFactory_h_11_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TileMapActorFactory_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TileMapActorFactory_h_14_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TileMapActorFactory_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTileMapActorFactory;

// ********** End Class UTileMapActorFactory *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TileMapActorFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
