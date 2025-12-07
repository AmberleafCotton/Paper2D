// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PaperFlipbookComponent.h"

#ifdef PAPER2D_PaperFlipbookComponent_generated_h
#error "PaperFlipbookComponent.generated.h already included, missing '#pragma once' in PaperFlipbookComponent.h"
#endif
#define PAPER2D_PaperFlipbookComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UPaperFlipbook;
struct FLinearColor;

// ********** Begin Delegate FFlipbookFinishedPlaySignature ****************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_21_DELEGATE \
PAPER2D_API void FFlipbookFinishedPlaySignature_DelegateWrapper(const FMulticastScriptDelegate& FlipbookFinishedPlaySignature);


// ********** End Delegate FFlipbookFinishedPlaySignature ******************************************

// ********** Begin Class UPaperFlipbookComponent **************************************************
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_RPC_WRAPPERS \
	DECLARE_FUNCTION(execOnRep_SourceFlipbook); \
	DECLARE_FUNCTION(execGetFlipbookFramerate); \
	DECLARE_FUNCTION(execGetFlipbookLengthInFrames); \
	DECLARE_FUNCTION(execGetFlipbookLength); \
	DECLARE_FUNCTION(execSetNewTime); \
	DECLARE_FUNCTION(execGetPlayRate); \
	DECLARE_FUNCTION(execSetPlayRate); \
	DECLARE_FUNCTION(execIsLooping); \
	DECLARE_FUNCTION(execSetLooping); \
	DECLARE_FUNCTION(execGetPlaybackPosition); \
	DECLARE_FUNCTION(execSetPlaybackPosition); \
	DECLARE_FUNCTION(execGetPlaybackPositionInFrames); \
	DECLARE_FUNCTION(execSetPlaybackPositionInFrames); \
	DECLARE_FUNCTION(execIsReversing); \
	DECLARE_FUNCTION(execIsPlaying); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execReverseFromEnd); \
	DECLARE_FUNCTION(execReverse); \
	DECLARE_FUNCTION(execPlayFromStart); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execSetSpriteColor); \
	DECLARE_FUNCTION(execGetSpriteColor); \
	DECLARE_FUNCTION(execGetFlipbook); \
	DECLARE_FUNCTION(execSetFlipbook);


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperFlipbookComponent, PAPER2D_API)


PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();

#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUPaperFlipbookComponent(); \
	friend struct Z_Construct_UClass_UPaperFlipbookComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaperFlipbookComponent, UMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2D"), Z_Construct_UClass_UPaperFlipbookComponent_NoRegister) \
	DECLARE_SERIALIZER(UPaperFlipbookComponent) \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_ARCHIVESERIALIZER \
	PAPER2D_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		SourceFlipbook=NETFIELD_REP_START, \
		NETFIELD_REP_END=SourceFlipbook	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(PAPER2D_API)


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PAPER2D_API UPaperFlipbookComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaperFlipbookComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PAPER2D_API, UPaperFlipbookComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaperFlipbookComponent); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaperFlipbookComponent(UPaperFlipbookComponent&&) = delete; \
	UPaperFlipbookComponent(const UPaperFlipbookComponent&) = delete; \
	PAPER2D_API virtual ~UPaperFlipbookComponent();


#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_23_PROLOG
#define FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_RPC_WRAPPERS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_INCLASS \
	FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaperFlipbookComponent;

// ********** End Class UPaperFlipbookComponent ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_2D_Paper2D_Source_Paper2D_Classes_PaperFlipbookComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
