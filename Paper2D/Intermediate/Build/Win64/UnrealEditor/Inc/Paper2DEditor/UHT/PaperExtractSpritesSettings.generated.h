// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ExtractSprites/PaperExtractSpritesSettings.h"

#ifdef PAPER2DEDITOR_PaperExtractSpritesSettings_generated_h
#error "PaperExtractSpritesSettings.generated.h already included, missing '#pragma once' in PaperExtractSpritesSettings.h"
#endif
#define PAPER2DEDITOR_PaperExtractSpritesSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperExtractSpritesSettings *********************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperExtractSpritesSettings_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPaperExtractSpritesSettings(); \
	friend struct Z_Construct_UClass_UPaperExtractSpritesSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperExtractSpritesSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperExtractSpritesSettings, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UPaperExtractSpritesSettings_NoRegister) \
	DECLARE_SERIALIZER(UPaperExtractSpritesSettings)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperExtractSpritesSettings(UPaperExtractSpritesSettings&&) = delete; \
	UPaperExtractSpritesSettings(const UPaperExtractSpritesSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperExtractSpritesSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperExtractSpritesSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperExtractSpritesSettings) \
	NO_API virtual ~UPaperExtractSpritesSettings();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_22_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_25_INCLASS_NO_PURE_DECLS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperExtractSpritesSettings;

// ********** End Class UPaperExtractSpritesSettings ***********************************************

// ********** Begin Class UPaperExtractSpriteGridSettings ******************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperExtractSpriteGridSettings_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_58_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPaperExtractSpriteGridSettings(); \
	friend struct Z_Construct_UClass_UPaperExtractSpriteGridSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperExtractSpriteGridSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperExtractSpriteGridSettings, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UPaperExtractSpriteGridSettings_NoRegister) \
	DECLARE_SERIALIZER(UPaperExtractSpriteGridSettings)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_58_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperExtractSpriteGridSettings(UPaperExtractSpriteGridSettings&&) = delete; \
	UPaperExtractSpriteGridSettings(const UPaperExtractSpriteGridSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperExtractSpriteGridSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperExtractSpriteGridSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperExtractSpriteGridSettings) \
	NO_API virtual ~UPaperExtractSpriteGridSettings();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_55_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_58_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_58_INCLASS_NO_PURE_DECLS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h_58_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperExtractSpriteGridSettings;

// ********** End Class UPaperExtractSpriteGridSettings ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_ExtractSprites_PaperExtractSpritesSettings_h

// ********** Begin Enum ESpriteExtractMode ********************************************************
#define FOREACH_ENUM_ESPRITEEXTRACTMODE(op) \
	op(ESpriteExtractMode::Auto) \
	op(ESpriteExtractMode::Grid) 

enum class ESpriteExtractMode : uint8;
template<> struct TIsUEnumClass<ESpriteExtractMode> { enum { Value = true }; };
template<> PAPER2DEDITOR_API UEnum* StaticEnum<ESpriteExtractMode>();
// ********** End Enum ESpriteExtractMode **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
