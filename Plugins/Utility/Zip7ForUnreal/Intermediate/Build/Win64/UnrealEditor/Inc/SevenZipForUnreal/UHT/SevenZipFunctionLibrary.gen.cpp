// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SevenZipForUnreal/Public/SevenZipFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSevenZipFunctionLibrary() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	SEVENZIPFORUNREAL_API UClass* Z_Construct_UClass_USevenZipFunctionLibrary();
	SEVENZIPFORUNREAL_API UClass* Z_Construct_UClass_USevenZipFunctionLibrary_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SevenZipForUnreal();
// End Cross Module References
	DEFINE_FUNCTION(USevenZipFunctionLibrary::execExtractAsBufferWihtPwd)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ArchivePath);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBuffer);
		P_GET_PROPERTY(FStrProperty,Z_Param_Password);
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USevenZipFunctionLibrary::ExtractAsBufferWihtPwd(Z_Param_ArchivePath,Z_Param_Out_OutBuffer,Z_Param_Password,Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USevenZipFunctionLibrary::execExtractAsBuffer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ArchivePath);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBuffer);
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USevenZipFunctionLibrary::ExtractAsBuffer(Z_Param_ArchivePath,Z_Param_Out_OutBuffer,Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USevenZipFunctionLibrary::execExtractWithPwd)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ArchivePath);
		P_GET_PROPERTY(FStrProperty,Z_Param_DistPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_Password);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USevenZipFunctionLibrary::ExtractWithPwd(Z_Param_ArchivePath,Z_Param_DistPath,Z_Param_Password);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USevenZipFunctionLibrary::execExtract)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ArchivePath);
		P_GET_PROPERTY(FStrProperty,Z_Param_DistPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USevenZipFunctionLibrary::Extract(Z_Param_ArchivePath,Z_Param_DistPath);
		P_NATIVE_END;
	}
	void USevenZipFunctionLibrary::StaticRegisterNativesUSevenZipFunctionLibrary()
	{
		UClass* Class = USevenZipFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Extract", &USevenZipFunctionLibrary::execExtract },
			{ "ExtractAsBuffer", &USevenZipFunctionLibrary::execExtractAsBuffer },
			{ "ExtractAsBufferWihtPwd", &USevenZipFunctionLibrary::execExtractAsBufferWihtPwd },
			{ "ExtractWithPwd", &USevenZipFunctionLibrary::execExtractWithPwd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics
	{
		struct SevenZipFunctionLibrary_eventExtract_Parms
		{
			FString ArchivePath;
			FString DistPath;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ArchivePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ArchivePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DistPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DistPath;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ArchivePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ArchivePath = { "ArchivePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtract_Parms, ArchivePath), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ArchivePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ArchivePath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_DistPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_DistPath = { "DistPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtract_Parms, DistPath), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_DistPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_DistPath_MetaData)) };
	void Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SevenZipFunctionLibrary_eventExtract_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SevenZipFunctionLibrary_eventExtract_Parms), &Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ArchivePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_DistPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::Function_MetaDataParams[] = {
		{ "Category", "SevenZip" },
		{ "ModuleRelativePath", "Public/SevenZipFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USevenZipFunctionLibrary, nullptr, "Extract", nullptr, nullptr, sizeof(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::SevenZipFunctionLibrary_eventExtract_Parms), Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USevenZipFunctionLibrary_Extract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USevenZipFunctionLibrary_Extract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics
	{
		struct SevenZipFunctionLibrary_eventExtractAsBuffer_Parms
		{
			FString ArchivePath;
			TArray<uint8> OutBuffer;
			int32 Index;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ArchivePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ArchivePath;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutBuffer_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBuffer;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ArchivePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ArchivePath = { "ArchivePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractAsBuffer_Parms, ArchivePath), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ArchivePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ArchivePath_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_OutBuffer_Inner = { "OutBuffer", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_OutBuffer = { "OutBuffer", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractAsBuffer_Parms, OutBuffer), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractAsBuffer_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SevenZipFunctionLibrary_eventExtractAsBuffer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SevenZipFunctionLibrary_eventExtractAsBuffer_Parms), &Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ArchivePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_OutBuffer_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_OutBuffer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SevenZip" },
		{ "CPP_Default_Index", "0" },
		{ "ModuleRelativePath", "Public/SevenZipFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USevenZipFunctionLibrary, nullptr, "ExtractAsBuffer", nullptr, nullptr, sizeof(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::SevenZipFunctionLibrary_eventExtractAsBuffer_Parms), Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics
	{
		struct SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms
		{
			FString ArchivePath;
			TArray<uint8> OutBuffer;
			FString Password;
			int32 Index;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ArchivePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ArchivePath;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutBuffer_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBuffer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ArchivePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ArchivePath = { "ArchivePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms, ArchivePath), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ArchivePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ArchivePath_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_OutBuffer_Inner = { "OutBuffer", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_OutBuffer = { "OutBuffer", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms, OutBuffer), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_Password_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms, Password), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_Password_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_Password_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms), &Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ArchivePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_OutBuffer_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_OutBuffer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_Password,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::Function_MetaDataParams[] = {
		{ "Category", "SevenZip" },
		{ "CPP_Default_Index", "0" },
		{ "ModuleRelativePath", "Public/SevenZipFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USevenZipFunctionLibrary, nullptr, "ExtractAsBufferWihtPwd", nullptr, nullptr, sizeof(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::SevenZipFunctionLibrary_eventExtractAsBufferWihtPwd_Parms), Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics
	{
		struct SevenZipFunctionLibrary_eventExtractWithPwd_Parms
		{
			FString ArchivePath;
			FString DistPath;
			FString Password;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ArchivePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ArchivePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DistPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DistPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ArchivePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ArchivePath = { "ArchivePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractWithPwd_Parms, ArchivePath), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ArchivePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ArchivePath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_DistPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_DistPath = { "DistPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractWithPwd_Parms, DistPath), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_DistPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_DistPath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_Password_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SevenZipFunctionLibrary_eventExtractWithPwd_Parms, Password), METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_Password_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_Password_MetaData)) };
	void Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SevenZipFunctionLibrary_eventExtractWithPwd_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SevenZipFunctionLibrary_eventExtractWithPwd_Parms), &Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ArchivePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_DistPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_Password,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::Function_MetaDataParams[] = {
		{ "Category", "SevenZip" },
		{ "ModuleRelativePath", "Public/SevenZipFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USevenZipFunctionLibrary, nullptr, "ExtractWithPwd", nullptr, nullptr, sizeof(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::SevenZipFunctionLibrary_eventExtractWithPwd_Parms), Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USevenZipFunctionLibrary);
	UClass* Z_Construct_UClass_USevenZipFunctionLibrary_NoRegister()
	{
		return USevenZipFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USevenZipFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USevenZipFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_SevenZipForUnreal,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USevenZipFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USevenZipFunctionLibrary_Extract, "Extract" }, // 3475488125
		{ &Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBuffer, "ExtractAsBuffer" }, // 1963365166
		{ &Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractAsBufferWihtPwd, "ExtractAsBufferWihtPwd" }, // 2351098936
		{ &Z_Construct_UFunction_USevenZipFunctionLibrary_ExtractWithPwd, "ExtractWithPwd" }, // 3438036123
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USevenZipFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SevenZipFunctionLibrary.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SevenZipFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USevenZipFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USevenZipFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USevenZipFunctionLibrary_Statics::ClassParams = {
		&USevenZipFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USevenZipFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USevenZipFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USevenZipFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_USevenZipFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USevenZipFunctionLibrary.OuterSingleton, Z_Construct_UClass_USevenZipFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USevenZipFunctionLibrary.OuterSingleton;
	}
	template<> SEVENZIPFORUNREAL_API UClass* StaticClass<USevenZipFunctionLibrary>()
	{
		return USevenZipFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USevenZipFunctionLibrary);
	struct Z_CompiledInDeferFile_FID_Users_PC_Documents_3DesignerUnreal_Plugins_Utility_Zip7ForUnreal_Source_SevenZipForUnreal_Public_SevenZipFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PC_Documents_3DesignerUnreal_Plugins_Utility_Zip7ForUnreal_Source_SevenZipForUnreal_Public_SevenZipFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USevenZipFunctionLibrary, USevenZipFunctionLibrary::StaticClass, TEXT("USevenZipFunctionLibrary"), &Z_Registration_Info_UClass_USevenZipFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USevenZipFunctionLibrary), 3805740520U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PC_Documents_3DesignerUnreal_Plugins_Utility_Zip7ForUnreal_Source_SevenZipForUnreal_Public_SevenZipFunctionLibrary_h_1803350808(TEXT("/Script/SevenZipForUnreal"),
		Z_CompiledInDeferFile_FID_Users_PC_Documents_3DesignerUnreal_Plugins_Utility_Zip7ForUnreal_Source_SevenZipForUnreal_Public_SevenZipFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PC_Documents_3DesignerUnreal_Plugins_Utility_Zip7ForUnreal_Source_SevenZipForUnreal_Public_SevenZipFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
