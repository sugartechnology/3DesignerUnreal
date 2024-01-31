// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CatalogProduct.h"

#include "CatalogScene.generated.h"

USTRUCT()
struct FCatalogScene
{
	GENERATED_BODY()

public:
	UPROPERTY()
		TArray<FCatalogProduct> products;
};

