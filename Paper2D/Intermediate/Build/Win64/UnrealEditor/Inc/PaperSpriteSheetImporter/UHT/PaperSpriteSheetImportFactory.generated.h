// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperSpriteSheetImportFactory.h"

#ifdef PAPERSPRITESHEETIMPORTER_PaperSpriteSheetImportFactory_generated_h
#error "PaperSpriteSheetImportFactory.generated.h already included, missing '#pragma once' in PaperSpriteSheetImportFactory.h"
#endif
#define PAPERSPRITESHEETIMPORTER_PaperSpriteSheetImportFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperSpriteSheetImportFactory *******************************************
PAPERSPRITESHEETIMPORTER_API UClass* Z_Construct_UClass_UPaperSpriteSheetImportFactory_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheetImportFactory_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUPaperSpriteSheetImportFactory(); \
	friend struct Z_Construct_UClass_UPaperSpriteSheetImportFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPERSPRITESHEETIMPORTER_API UClass* Z_Construct_UClass_UPaperSpriteSheetImportFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperSpriteSheetImportFactory, UFactory, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PaperSpriteSheetImporter"), Z_Construct_UClass_UPaperSpriteSheetImportFactory_NoRegister) \
	DECLARE_SERIALIZER(UPaperSpriteSheetImportFactory)


#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheetImportFactory_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaperSpriteSheetImportFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperSpriteSheetImportFactory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperSpriteSheetImportFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperSpriteSheetImportFactory); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperSpriteSheetImportFactory(UPaperSpriteSheetImportFactory&&) = delete; \
	UPaperSpriteSheetImportFactory(const UPaperSpriteSheetImportFactory&) = delete; \
	NO_API virtual ~UPaperSpriteSheetImportFactory();


#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheetImportFactory_h_10_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheetImportFactory_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheetImportFactory_h_13_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheetImportFactory_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperSpriteSheetImportFactory;

// ********** End Class UPaperSpriteSheetImportFactory *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_PaperSpriteSheetImporter_Private_PaperSpriteSheetImportFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
