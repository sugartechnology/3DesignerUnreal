// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImporterActor.h"

/**
 * 
 */
class CUSTOMMATERIAL_API GltfImporter
{
private:
	FCatalogProduct* selfProductEntity;
	FProductPart* selfProductPartEntity;

public:
	GltfImporter();
	~GltfImporter();

	void ImportGltf(FString gltfPath, AImporterActor* parentActor, FCatalogProduct* productEntity, FProductPart* currentFabricEntity);
};
