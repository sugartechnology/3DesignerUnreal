// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyVector.generated.h"

USTRUCT()
struct FMyVector
{
	GENERATED_BODY()

public:
	UPROPERTY()
		double x;
	UPROPERTY()
		double y;
	UPROPERTY()
		double z;
};