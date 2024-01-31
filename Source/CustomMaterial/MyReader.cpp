// Fill out your copyright notice in the Description page of Project Settings.


#include "MyReader.h"
#include "HAL/PlatformFileManager.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"
#include "CatalogProject.h"
#include "Http.h"
#include "ImporterActor.h"
#include "GltfImporter.h"
#include "HAL/FileManagerGeneric.h"


FString UMyReader::cacheFilePath;

FString UMyReader::ReadFile(FString filePath, bool& wasSuccessfull, FString& message)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*filePath))
	{
		UE_LOG(LogTemp, Error, TEXT("F1"));
		wasSuccessfull = false;
		return "";
	}

	FString outString = "";

	if (!FFileHelper::LoadFileToString(outString, *filePath))
	{
		UE_LOG(LogTemp, Error, TEXT("F2"));
		wasSuccessfull = false;
		return "";
	}

	wasSuccessfull = true;
	return outString;
}

TSharedPtr<FJsonObject> UMyReader::ReadJsonFile(FString filePath, bool& wasSuccessfull, FString& message)
{
	FString jsonString = ReadFile(filePath, wasSuccessfull, message);
	if (!wasSuccessfull)
	{
		UE_LOG(LogTemp, Error, TEXT("F3"));
		return nullptr;
	}

	TSharedPtr<FJsonObject> outJson;

	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(jsonString), outJson))
	{
		UE_LOG(LogTemp, Error, TEXT("F4"));
		wasSuccessfull = false;
		return nullptr;
	}

	wasSuccessfull = true;
	return outJson;
}

FCatalogProject UMyReader::ReadJsonFileAsRR(FString filePath, bool& wasSuccessfull, FString& message)
{
	TSharedPtr<FJsonObject> jsonString = ReadJsonFile(filePath, wasSuccessfull, message);

	if (!wasSuccessfull)
	{
		UE_LOG(LogTemp, Error, TEXT("F5"));
		return FCatalogProject();
	}

	FCatalogProject resultProject = FCatalogProject();

	if (!FJsonObjectConverter::JsonObjectToUStruct<FCatalogProject>(jsonString.ToSharedRef(), &resultProject))
	{
		UE_LOG(LogTemp, Error, TEXT("F6"));
		wasSuccessfull = false;
		return FCatalogProject();
	}

	return resultProject;
}

void DownloadProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived)
{
	UE_LOG(LogTemp, Display, TEXT("Downloading... %d"), BytesSent);
}

void UMyReader::DownloadEnd(FHttpRequestPtr Request, FHttpResponsePtr Response, bool succesfull)
{
	UE_LOG(LogTemp, Display, TEXT("Response here %d"), Response->GetContentLength());
	
	auto contentLength = Response->GetContentLength();
	auto contentBytes = Response->GetContent();

	FString zipOutFolder = FPaths::Combine(UMyReader::cacheFilePath, cachFile).Replace(*FString("."), *FString("_"));
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*zipOutFolder);

	FString filePath = FPaths::Combine(zipOutFolder, cachFile);
	UE_LOG(LogTemp, Display, TEXT("create pass %s"), *UMyReader::cacheFilePath);
	UE_LOG(LogTemp, Display, TEXT("create pass %s"), *cachFile);
	UE_LOG(LogTemp, Display, TEXT("create pass %s"), *filePath);
	auto handler = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*filePath, false, true);
	handler->Write(contentBytes.GetData(), contentLength);
	handler->Flush();
	handler->~IFileHandle();

	// Zipped file
	if (cachFile.EndsWith("rrfile"))
	{
		UE_LOG(LogTemp, Display, TEXT("create pass %s"), *zipOutFolder);

		FString zip7location = "C:/Users/Erdem/Downloads/7z2201-extra/7za.exe";
		FString params = "e " + filePath;
		params += " -pj2+66H%ZSLzWWA%+yS$vQnBkJa2T-2"; // No space between -p and the password itself
		params += " -o" + zipOutFolder;

		FString outst;
		FString outsterr;
		FPlatformProcess::ExecProcess(*zip7location, *params, false, &outst, &outsterr);
		//UE_LOG(LogTemp, Error, TEXT("suces me %s"), *outst);
		//UE_LOG(LogTemp, Error, TEXT("suces me11 %2"), *outsterr);
	}

	UE_LOG(LogTemp, Display, TEXT("finis respons"));
	loading = false;
	outFile = filePath.Replace(*FString("rrfile"), *FString("glb"));

	ImportFilesInFolder(zipOutFolder);
}

void UMyReader::ImportFilesInFolder(FString zipOutFolder)
{
	TArray<FString> yuz;
	FFileManagerGeneric FileMgr;
	//FileMgr.SetSandboxEnabled(true);
	//FileMgr.FindFiles(yuz, *zipOutFolder, true, false);
	FString wildcard(""); // May be "" (empty string) to search all files
	FileMgr.FindFiles(yuz, *zipOutFolder, *wildcard);

	for (auto file : yuz)
	{
		FString curGltfPath = FPaths::Combine(zipOutFolder, file);
		currentParentActor->ImportGLB(curGltfPath, UMyReader::currentProductEntity, currentProductPartEntity);
	}
}

void UMyReader::DownloadFile(FString url, AImporterActor* parentActor)
{
	//UMyReader::cacheFilePath = "C:/Users/Erdem/Desktop/";
	loading = true;
	currentParentActor = parentActor;
	downloadedFile = url;

	cachFile = downloadedFile.Replace(*FString("https://"), *FString(""));
	//downloadedFile = downloadedFile.Replace(*FString("."), *FString(""));
	cachFile = cachFile.Replace(*FString("/"), *FString("_"));

	FString zipOutFolder = FPaths::Combine(UMyReader::cacheFilePath, cachFile).Replace(*FString("."), *FString("_"));
	if (FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*zipOutFolder))
	{
		ImportFilesInFolder(zipOutFolder);
		return;
	}

	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	//Request->OnRequestProgress().BindLambda(&DownloadProgress);
	Request->OnProcessRequestComplete().BindUObject(this, &UMyReader::DownloadEnd);
	Request->SetURL(url);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UMyReader::DownloadFromProduct(FCatalogProduct* productEntity, AImporterActor* parentActor)
{
	currentProductEntity = productEntity;
	DownloadFile(productEntity->productModelUrl, parentActor);
}

void UMyReader::DownloadFromFabric(FProductPart* fabricEntity, AImporterActor* parentActor)
{
	currentProductPartEntity = fabricEntity;

	if (currentProductPartEntity->fabric.pbrFileUrl.EndsWith("glb"))
	{
		UE_LOG(LogTemp, Display, TEXT("product part fabric name %s"), *currentProductPartEntity->fabric.pbrFileUrl);
		DownloadFile(currentProductPartEntity->fabric.pbrFileUrl, parentActor);
	}
}