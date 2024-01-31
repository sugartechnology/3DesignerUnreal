// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CatalogProduct.h"
#include "ImporterActor.generated.h"

UCLASS()
class CUSTOMMATERIAL_API AImporterActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AImporterActor();

	UPROPERTY(EditAnywhere)
		FString glbDir;
	
	UPROPERTY(EditAnywhere)
		FString rrDir;

	UPROPERTY(EditAnywhere)
		FString rrImportCacheDir;

	UPROPERTY(EditAnywhere)
		UMaterial* materialPrefab;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere)
		AActor* DirectionalLightParent;

	//DECLARE_DELEGATE_ThreeParams(FHttpRequestCompleteDelegate, FHttpRequestPtr /*Request*/, FHttpResponsePtr /*Response*/, bool /*bConnectedSuccessfully*/);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ImportGLB(FString gltfPath, FCatalogProduct* productEntity, FProductPart* currentProductPartEntity);

};
