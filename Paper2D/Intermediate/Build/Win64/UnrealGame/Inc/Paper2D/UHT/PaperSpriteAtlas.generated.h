// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperSpriteAtlas.h"

#ifdef PAPER2D_PaperSpriteAtlas_generated_h
#error "PaperSpriteAtlas.generated.h already included, missing '#pragma once' in PaperSpriteAtlas.h"
#endif
#define PAPER2D_PaperSpriteAtlas_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPaperSpriteAtlasSlot *********************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPaperSpriteAtlasSlot_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FPaperSpriteAtlasSlot;
// ********** End ScriptStruct FPaperSpriteAtlasSlot ***********************************************

// ********** Begin Class UPaperSpriteAtlas ********************************************************
PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteAtlas_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h_54_INCLASS \
private: \
	static void StaticRegisterNativesUPaperSpriteAtlas(); \
	friend struct Z_Construct_UClass_UPaperSpriteAtlas_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteAtlas_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperSpriteAtlas, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperSpriteAtlas_NoRegister) \
	DECLARE_SERIALIZER(UPaperSpriteAtlas)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h_54_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperSpriteAtlas(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperSpriteAtlas) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperSpriteAtlas); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperSpriteAtlas); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperSpriteAtlas(UPaperSpriteAtlas&&) = delete; \
	UPaperSpriteAtlas(const UPaperSpriteAtlas&) = delete; \
	PAPER2D_API virtual ~UPaperSpriteAtlas();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h_51_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h_54_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h_54_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h_54_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperSpriteAtlas;

// ********** End Class UPaperSpriteAtlas **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSpriteAtlas_h

// ********** Begin Enum EPaperSpriteAtlasPadding **************************************************
#define FOREACH_ENUM_EPAPERSPRITEATLASPADDING(op) \
	op(EPaperSpriteAtlasPadding::DilateBorder) \
	op(EPaperSpriteAtlasPadding::PadWithZero) 

enum class EPaperSpriteAtlasPadding : uint8;
template<> struct TIsUEnumClass<EPaperSpriteAtlasPadding> { enum { Value = true }; };
template<> PAPER2D_API UEnum* StaticEnum<EPaperSpriteAtlasPadding>();
// ********** End Enum EPaperSpriteAtlasPadding ****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
