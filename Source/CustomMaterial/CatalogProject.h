// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CatalogScene.h"
#include "CatalogProject.generated.h"

/**
 * 
 */
USTRUCT()
struct FCatalogProject
{
	GENERATED_BODY()

public:
	UPROPERTY()
		FString name;
	UPROPERTY()
		FCatalogScene catalogScene;
};
