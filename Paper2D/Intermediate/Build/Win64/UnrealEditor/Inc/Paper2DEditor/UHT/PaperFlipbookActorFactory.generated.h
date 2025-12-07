// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperFlipbookActorFactory.h"

#ifdef PAPER2DEDITOR_PaperFlipbookActorFactory_generated_h
#error "PaperFlipbookActorFactory.generated.h already included, missing '#pragma once' in PaperFlipbookActorFactory.h"
#endif
#define PAPER2DEDITOR_PaperFlipbookActorFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaperFlipbookActorFactory ***********************************************
PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperFlipbookActorFactory_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperFlipbookActorFactory_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUPaperFlipbookActorFactory(); \
	friend struct Z_Construct_UClass_UPaperFlipbookActorFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DEDITOR_API UClass* Z_Construct_UClass_UPaperFlipbookActorFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperFlipbookActorFactory, UActorFactory, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2DEditor"), Z_Construct_UClass_UPaperFlipbookActorFactory_NoRegister) \
	DECLARE_SERIALIZER(UPaperFlipbookActorFactory)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperFlipbookActorFactory_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaperFlipbookActorFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperFlipbookActorFactory) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaperFlipbookActorFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperFlipbookActorFactory); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperFlipbookActorFactory(UPaperFlipbookActorFactory&&) = delete; \
	UPaperFlipbookActorFactory(const UPaperFlipbookActorFactory&) = delete; \
	NO_API virtual ~UPaperFlipbookActorFactory();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperFlipbookActorFactory_h_11_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperFlipbookActorFactory_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperFlipbookActorFactory_h_14_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperFlipbookActorFactory_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperFlipbookActorFactory;

// ********** End Class UPaperFlipbookActorFactory *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2DEditor_Classes_PaperFlipbookActorFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
