// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Project.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMMATERIAL_API UProject : public UUserDefinedStruct
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		FString name;
//	UPROPERTY()
//		FCatalogScene catalogScene;
};
