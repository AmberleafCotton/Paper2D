// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperCharacter.h"

#ifdef PAPER2D_PaperCharacter_generated_h
#error "PaperCharacter.generated.h already included, missing '#pragma once' in PaperCharacter.h"
#endif
#define PAPER2D_PaperCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APaperCharacter **********************************************************
PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperCharacter_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAPaperCharacter(); \
	friend struct Z_Construct_UClass_APaperCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(APaperCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_APaperCharacter_NoRegister) \
	DECLARE_SERIALIZER(APaperCharacter)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperCharacter_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API APaperCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APaperCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, APaperCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APaperCharacter); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APaperCharacter(APaperCharacter&&) = delete; \
	APaperCharacter(const APaperCharacter&) = delete; \
	PAPER2D_API virtual ~APaperCharacter();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperCharacter_h_14_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperCharacter_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperCharacter_h_17_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperCharacter_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APaperCharacter;

// ********** End Class APaperCharacter ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
