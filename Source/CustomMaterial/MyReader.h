// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Serialization/JsonSerializer.h"
#include "CatalogProject.h"
#include "Fabric.h"
#include "ImporterActor.h"
#include "Http.h"
#include "MyReader.generated.h"


UCLASS()
class CUSTOMMATERIAL_API UMyReader : public UObject
{
	GENERATED_BODY()

private:
	FString cachFile;

public:

	bool loading;

	FString outFile;

	static FString cacheFilePath;

	FString downloadedFile;
	AImporterActor* currentParentActor;
	FCatalogProduct* currentProductEntity = nullptr;
	FProductPart* currentProductPartEntity = nullptr;

	FString ReadFile(FString filePath, bool& wasSuccessfull, FString& message);

	TSharedPtr<FJsonObject> ReadJsonFile(FString filePath, bool& wasSuccessfull, FString& message);

	FCatalogProject ReadJsonFileAsRR(FString filePath, bool& wasSuccessfull, FString& message);

	void DownloadEnd(FHttpRequestPtr Request, FHttpResponsePtr Response, bool succesfull);
	void DownloadFile(FString url, AImporterActor* parentActor);

	void DownloadFromProduct(FCatalogProduct* productEntity, AImporterActor* parentActor);
	void DownloadFromFabric(FProductPart* productPartEntity, AImporterActor* parentActor);

	void ImportFilesInFolder(FString zipOutFolder);

};
