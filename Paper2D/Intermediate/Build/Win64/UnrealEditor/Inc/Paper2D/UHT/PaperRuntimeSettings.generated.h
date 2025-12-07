// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperRuntimeSettings.h"

#ifdef PAPER2D_PaperRuntimeSettings_generated_h
#error "PaperRuntimeSettings.generated.h already included, missing '#pragma once' in PaperRuntimeSettings.h"
#endif
#define PAPER2D_PaperRuntimeSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperRuntimeSettings ****************************************************
PAPER2D_API UClass* Z_Construct_UClass_UPaperRuntimeSettings_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperRuntimeSettings_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUPaperRuntimeSettings(); \
	friend struct Z_Construct_UClass_UPaperRuntimeSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperRuntimeSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperRuntimeSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperRuntimeSettings_NoRegister) \
	DECLARE_SERIALIZER(UPaperRuntimeSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperRuntimeSettings_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperRuntimeSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperRuntimeSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperRuntimeSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperRuntimeSettings); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperRuntimeSettings(UPaperRuntimeSettings&&) = delete; \
	UPaperRuntimeSettings(const UPaperRuntimeSettings&) = delete; \
	PAPER2D_API virtual ~UPaperRuntimeSettings();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperRuntimeSettings_h_10_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperRuntimeSettings_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperRuntimeSettings_h_13_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperRuntimeSettings_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperRuntimeSettings;

// ********** End Class UPaperRuntimeSettings ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperRuntimeSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
