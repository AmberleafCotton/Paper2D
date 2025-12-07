// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TerrainSplineActorFactory.h"

#ifdef PAPER2DEDITOR_TerrainSplineActorFactory_generated_h
#error "TerrainSplineActorFactory.generated.h already included, missing '#pragma once' in TerrainSplineActorFactory.h"
#endif
#define PAPER2DEDITOR_TerrainSplineActorFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UTerrainSplineActorFactory ***********************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UTerrainSplineActorFactory_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TerrainSplineActorFactory_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUTerrainSplineActorFactory(); \
	friend struct Z_Construct_UClass_UTerrainSplineActorFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UTerrainSplineActorFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UTerrainSplineActorFactory, UActorFactory, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UTerrainSplineActorFactory_NoRegister) \
	DECLARE_SERIALIZER(UTerrainSplineActorFactory)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TerrainSplineActorFactory_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTerrainSplineActorFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTerrainSplineActorFactory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTerrainSplineActorFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTerrainSplineActorFactory); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTerrainSplineActorFactory(UTerrainSplineActorFactory&&) = delete; \
	UTerrainSplineActorFactory(const UTerrainSplineActorFactory&) = delete; \
	NO_API virtual ~UTerrainSplineActorFactory();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TerrainSplineActorFactory_h_11_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TerrainSplineActorFactory_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TerrainSplineActorFactory_h_14_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TerrainSplineActorFactory_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTerrainSplineActorFactory;

// ********** End Class UTerrainSplineActorFactory *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_TerrainSplineActorFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
