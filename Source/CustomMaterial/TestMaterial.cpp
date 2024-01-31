// Fill out your copyright notice in the Description page of Project Settings.


#include "TestMaterial.h"

// Sets default values
ATestMaterial::ATestMaterial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	//UStaticMesh* cubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Koltuk/govde.govde'")).Object;
	//VisualMesh->SetStaticMesh(cubeMesh);
}

APlayerController* playerControlE;

// Called when the game starts or when spawned
void ATestMaterial::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATestMaterial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

