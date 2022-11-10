// Fill out your copyright notice in the Description page of Project Settings.


#include "MySimpleImportActor.h"

#include "GLTFAsset.h"
#include "GLTFLogger.h"
#include "GLTFMaterialFactory.h"
#include "GLTFReader.h"

// Sets default values
AMySimpleImportActor::AMySimpleImportActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);*/
}

// Called when the game starts or when spawned
void AMySimpleImportActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMySimpleImportActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*
void CreateActorsWithMeshes(TArray<UStaticMesh*> inMeshes, AErdem* parentActor)
{
	for (auto& ee : inMeshes)
	{
		AMyMeshActor* myAct = parentActor->GetWorld()->SpawnActor<AMyMeshActor>(AMyMeshActor::StaticClass());

		UStaticMeshComponent* myMeshStat = myAct->VisualMesh;

		//ee->Build();
		//ee->GetStaticMaterialsName();
		//UStaticMeshComponent* myMeshStat = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("erdem"));
		//myMeshStat->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

		myMeshStat->SetStaticMesh(ee);
		//myMeshStat->SetMaterial();
		//myMeshStat->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

		ee->Build();

		UE_LOG(LogTemp, Warning, TEXT("Printing bounds..."));
		UE_LOG(LogTemp, Warning, TEXT("%f"), ee->GetBounds().BoxExtent.X);
		UE_LOG(LogTemp, Warning, TEXT("%f"), ee->GetBounds().BoxExtent.Y);
		UE_LOG(LogTemp, Warning, TEXT("%f"), ee->GetBounds().BoxExtent.Z);
	}
}
*/

/*void CreateGltfMeshes(GLTF::FStaticMeshFactory* inMeshFactory, GLTF::FAsset* inAsset, AErdem* parentPackage)
{
	outMeshes = inMeshFactory->CreateMeshes(*inAsset, parentPackage, EObjectFlags::RF_Transient, false);

	UE_LOG(LogTemp, Error, TEXT("Printing mesh factory messages: "));
	for (auto& myMsg : inMeshFactory->GetLogMessages())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *myMsg.Value);
	}
	UE_LOG(LogTemp, Error, TEXT("Ending mesh factory messages..."));
}*/