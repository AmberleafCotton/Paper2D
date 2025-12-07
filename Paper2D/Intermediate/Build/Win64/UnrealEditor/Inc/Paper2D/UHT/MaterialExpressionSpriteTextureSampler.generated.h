// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MaterialExpressionSpriteTextureSampler.h"

#ifdef PAPER2D_MaterialExpressionSpriteTextureSampler_generated_h
#error "MaterialExpressionSpriteTextureSampler.generated.h already included, missing '#pragma once' in MaterialExpressionSpriteTextureSampler.h"
#endif
#define PAPER2D_MaterialExpressionSpriteTextureSampler_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UMaterialExpressionSpriteTextureSampler **********************************
PAPER2D_API UClass* Z_Construct_UClass_UMaterialExpressionSpriteTextureSampler_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Public_MaterialExpressionSpriteTextureSampler_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUMaterialExpressionSpriteTextureSampler(); \
	friend struct Z_Construct_UClass_UMaterialExpressionSpriteTextureSampler_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UMaterialExpressionSpriteTextureSampler_NoRegister(); \
public: \
	DECLARE_CLASS2(UMaterialExpressionSpriteTextureSampler, UMaterialExpressionTextureSampleParameter2D, COMPILED_IN_FLAGS(0 | CLASS_Optional | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UMaterialExpressionSpriteTextureSampler_NoRegister) \
	DECLARE_SERIALIZER(UMaterialExpressionSpriteTextureSampler)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Public_MaterialExpressionSpriteTextureSampler_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UMaterialExpressionSpriteTextureSampler(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMaterialExpressionSpriteTextureSampler) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UMaterialExpressionSpriteTextureSampler); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMaterialExpressionSpriteTextureSampler); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMaterialExpressionSpriteTextureSampler(UMaterialExpressionSpriteTextureSampler&&) = delete; \
	UMaterialExpressionSpriteTextureSampler(const UMaterialExpressionSpriteTextureSampler&) = delete; \
	PAPER2D_API virtual ~UMaterialExpressionSpriteTextureSampler();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Public_MaterialExpressionSpriteTextureSampler_h_13_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Public_MaterialExpressionSpriteTextureSampler_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Public_MaterialExpressionSpriteTextureSampler_h_16_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Public_MaterialExpressionSpriteTextureSampler_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMaterialExpressionSpriteTextureSampler;

// ********** End Class UMaterialExpressionSpriteTextureSampler ************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Public_MaterialExpressionSpriteTextureSampler_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
