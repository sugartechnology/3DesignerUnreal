// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fabric.h"
#include "ProductPart.generated.h"

USTRUCT()
struct FProductPart
{
	GENERATED_BODY()

public:
	UPROPERTY()
		FString name;
	UPROPERTY()
		FString meshName;
	UPROPERTY()
		FFabric fabric;
};