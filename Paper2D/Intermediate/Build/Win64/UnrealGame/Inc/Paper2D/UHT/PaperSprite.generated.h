// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperSprite.h"

#ifdef PAPER2D_PaperSprite_generated_h
#error "PaperSprite.generated.h already included, missing '#pragma once' in PaperSprite.h"
#endif
#define PAPER2D_PaperSprite_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPaperSpriteSocket ************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPaperSpriteSocket_Statics; \
	PAPER2D_API static class UScriptStruct* StaticStruct();


struct FPaperSpriteSocket;
// ********** End ScriptStruct FPaperSpriteSocket **************************************************

// ********** Begin Class UPaperSprite *************************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_47_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperSprite, PAPER2D_API)


PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_47_INCLASS \
private: \
	static void StaticRegisterNativesUPaperSprite(); \
	friend struct Z_Construct_UClass_UPaperSprite_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperSprite, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperSprite_NoRegister) \
	DECLARE_SERIALIZER(UPaperSprite) \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_47_ARCHIVESERIALIZER \
	virtual UObject* _getUObject() const override { return const_cast<UPaperSprite*>(this); }


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_47_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperSprite(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperSprite) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperSprite); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperSprite); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperSprite(UPaperSprite&&) = delete; \
	UPaperSprite(const UPaperSprite&) = delete; \
	PAPER2D_API virtual ~UPaperSprite();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_44_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_47_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_47_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h_47_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperSprite;

// ********** End Class UPaperSprite ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperSprite_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
