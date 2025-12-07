// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperImporterSettings.h"

#ifdef PAPER2DEDITOR_PaperImporterSettings_generated_h
#error "PaperImporterSettings.generated.h already included, missing '#pragma once' in PaperImporterSettings.h"
#endif
#define PAPER2DEDITOR_PaperImporterSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperImporterSettings ***************************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperImporterSettings_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperImporterSettings_h_53_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPaperImporterSettings(); \
	friend struct Z_Construct_UClass_UPaperImporterSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperImporterSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperImporterSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UPaperImporterSettings_NoRegister) \
	DECLARE_SERIALIZER(UPaperImporterSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Editor");} \



#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperImporterSettings_h_53_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperImporterSettings(UPaperImporterSettings&&) = delete; \
	UPaperImporterSettings(const UPaperImporterSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperImporterSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperImporterSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPaperImporterSettings) \
	NO_API virtual ~UPaperImporterSettings();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperImporterSettings_h_50_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperImporterSettings_h_53_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperImporterSettings_h_53_INCLASS_NO_PURE_DECLS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperImporterSettings_h_53_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperImporterSettings;

// ********** End Class UPaperImporterSettings *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperImporterSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
