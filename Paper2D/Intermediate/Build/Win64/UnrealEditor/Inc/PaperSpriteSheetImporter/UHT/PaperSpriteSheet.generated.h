// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperSpriteSheet.h"

#ifdef PAPERSPRITESHEETIMPORTER_PaperSpriteSheet_generated_h
#error "PaperSpriteSheet.generated.h already included, missing '#pragma once' in PaperSpriteSheet.h"
#endif
#define PAPERSPRITESHEETIMPORTER_PaperSpriteSheet_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperSpriteSheet ********************************************************
#if WITH_EDITORONLY_DATA
#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperSpriteSheet, NO_API)
#else // WITH_EDITORONLY_DATA
#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_ARCHIVESERIALIZER
#endif // WITH_EDITORONLY_DATA


PAPERSPRITESHEETIMPORTER_API UClass* Z_Construct_UClass_UPaperSpriteSheet_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_INCLASS \
private: \
	static void StaticRegisterNativesUPaperSpriteSheet(); \
	friend struct Z_Construct_UClass_UPaperSpriteSheet_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPERSPRITESHEETIMPORTER_API UClass* Z_Construct_UClass_UPaperSpriteSheet_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperSpriteSheet, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PaperSpriteSheetImporter"), Z_Construct_UClass_UPaperSpriteSheet_NoRegister) \
	DECLARE_SERIALIZER(UPaperSpriteSheet) \
	FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_ARCHIVESERIALIZER


#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaperSpriteSheet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperSpriteSheet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperSpriteSheet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperSpriteSheet); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperSpriteSheet(UPaperSpriteSheet&&) = delete; \
	UPaperSpriteSheet(const UPaperSpriteSheet&) = delete; \
	NO_API virtual ~UPaperSpriteSheet();


#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_9_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperSpriteSheet;

// ********** End Class UPaperSpriteSheet **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheet_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
