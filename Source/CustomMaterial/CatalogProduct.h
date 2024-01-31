// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyVector.h"
#include "ProductPart.h"

// This should be last imported one
#include "CatalogProduct.generated.h"


USTRUCT()
struct FCatalogProduct
{
	GENERATED_BODY()

public:
	UPROPERTY()
		FString name;
	UPROPERTY()
		FString thumbnailFileUrl;
	UPROPERTY()
		FString productModelUrl;
	UPROPERTY()
		FMyVector position;
	UPROPERTY()
		FMyVector rotation;
	UPROPERTY()
		FMyVector scale;
	UPROPERTY()
		TArray<FProductPart> productParts;

	FVector GetPosition();
	FRotator GetRotation();
	FVector GetScale();
};
