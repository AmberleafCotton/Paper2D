// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TileSetEditor/TileSetEditorSettings.h"

#ifdef PAPER2DEDITOR_TileSetEditorSettings_generated_h
#error "TileSetEditorSettings.generated.h already included, missing '#pragma once' in TileSetEditorSettings.h"
#endif
#define PAPER2DEDITOR_TileSetEditorSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UTileSetEditorSettings ***************************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UTileSetEditorSettings_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_TileSetEditor_TileSetEditorSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTileSetEditorSettings(); \
	friend struct Z_Construct_UClass_UTileSetEditorSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UTileSetEditorSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UTileSetEditorSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UTileSetEditorSettings_NoRegister) \
	DECLARE_SERIALIZER(UTileSetEditorSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_TileSetEditor_TileSetEditorSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTileSetEditorSettings(UTileSetEditorSettings&&) = delete; \
	UTileSetEditorSettings(const UTileSetEditorSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTileSetEditorSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTileSetEditorSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTileSetEditorSettings) \
	NO_API virtual ~UTileSetEditorSettings();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_TileSetEditor_TileSetEditorSettings_h_8_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_TileSetEditor_TileSetEditorSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_TileSetEditor_TileSetEditorSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_TileSetEditor_TileSetEditorSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTileSetEditorSettings;

// ********** End Class UTileSetEditorSettings *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Private_TileSetEditor_TileSetEditorSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
