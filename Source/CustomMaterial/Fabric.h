// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fabric.generated.h"

USTRUCT()
struct FFabric
{
	GENERATED_BODY()

public:
	UPROPERTY()
		double id;
	UPROPERTY()
		FString name;
	UPROPERTY()
		FString pbrFileUrl;
};