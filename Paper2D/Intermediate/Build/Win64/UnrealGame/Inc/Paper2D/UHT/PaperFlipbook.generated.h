// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperFlipbook.h"

#ifdef PAPER2D_PaperFlipbook_generated_h
#error "PaperFlipbook.generated.h already included, missing '#pragma once' in PaperFlipbook.h"
#endif
#define PAPER2D_PaperFlipbook_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UPaperSprite;

// ********** Begin ScriptStruct FPaperFlipbookKeyFrame ********************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPaperFlipbookKeyFrame_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FPaperFlipbookKeyFrame;
// ********** End ScriptStruct FPaperFlipbookKeyFrame **********************************************

// ********** Begin Class UPaperFlipbook ***********************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_RPC_WRAPPERS \
	DECLARE_FUNCTION(execIsValidKeyFrameIndex); \
	DECLARE_FUNCTION(execGetNumKeyFrames); \
	DECLARE_FUNCTION(execGetSpriteAtFrame); \
	DECLARE_FUNCTION(execGetSpriteAtTime); \
	DECLARE_FUNCTION(execGetKeyFrameIndexAtTime); \
	DECLARE_FUNCTION(execGetTotalDuration); \
	DECLARE_FUNCTION(execGetNumFrames);


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperFlipbook, PAPER2D_API)


PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_INCLASS \
private: \
	static void StaticRegisterNativesUPaperFlipbook(); \
	friend struct Z_Construct_UClass_UPaperFlipbook_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperFlipbook, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperFlipbook_NoRegister) \
	DECLARE_SERIALIZER(UPaperFlipbook) \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_ARCHIVESERIALIZER


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperFlipbook(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperFlipbook) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperFlipbook); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperFlipbook); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperFlipbook(UPaperFlipbook&&) = delete; \
	UPaperFlipbook(const UPaperFlipbook&) = delete; \
	PAPER2D_API virtual ~UPaperFlipbook();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_53_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_RPC_WRAPPERS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h_56_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperFlipbook;

// ********** End Class UPaperFlipbook *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbook_h

// ********** Begin Enum EFlipbookCollisionMode ****************************************************
#define FOREACH_ENUM_EFLIPBOOKCOLLISIONMODE(op) \
	op(EFlipbookCollisionMode::NoCollision) \
	op(EFlipbookCollisionMode::FirstFrameCollision) \
	op(EFlipbookCollisionMode::EachFrameCollision) 

namespace EFlipbookCollisionMode { enum Type : int; }
template<> PAPER2D_API UEnum* StaticEnum<EFlipbookCollisionMode::Type>();
// ********** End Enum EFlipbookCollisionMode ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
