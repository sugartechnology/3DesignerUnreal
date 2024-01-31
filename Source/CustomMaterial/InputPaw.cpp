// Fill out your copyright notice in the Description page of Project Settings.


#include "InputPaw.h"
#include "MeshDescription.h"
#include "MeshAttributes.h"
#include <StaticMeshAttributes.h>

// Sets default values
AInputPaw::AInputPaw()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
}

APlayerController* playerControle;
// Called when the game starts or when spawned
void AInputPaw::BeginPlay()
{
	Super::BeginPlay();
	
	playerControle = GetWorld()->GetFirstPlayerController();
	EnableInput(playerControle);
}

bool onetime = false;
// Called every frame
void AInputPaw::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerControle == NULL)
		return;

	if (playerControle->WasInputKeyJustPressed(EKeys::J))
	{
		FMeshDescription mesh_desc;

		FStaticMeshAttributes attributes(mesh_desc);
		attributes.Register();

		TVertexAttributesRef<FVector3f> positions = mesh_desc.GetVertexPositions();

		mesh_desc.ReserveNewVertices(4);
		FVertexID v0 = mesh_desc.CreateVertex();
		FVertexID v1 = mesh_desc.CreateVertex();
		FVertexID v2 = mesh_desc.CreateVertex();
		FVertexID v3 = mesh_desc.CreateVertex();

		mesh_desc.ReserveNewVertexInstances(4);
		FVertexInstanceID vi0 = mesh_desc.CreateVertexInstance(v0);
		FVertexInstanceID vi1 = mesh_desc.CreateVertexInstance(v1);
		FVertexInstanceID vi2 = mesh_desc.CreateVertexInstance(v2);
		FVertexInstanceID vi3 = mesh_desc.CreateVertexInstance(v3);

		/*mesh_desc.ReserveNewUVs(4);
		FUVID uv0 = mesh_desc.CreateUV();
		FUVID uv1 = mesh_desc.CreateUV();
		FUVID uv2 = mesh_desc.CreateUV();
		FUVID uv3 = mesh_desc.CreateUV();*/

		FPolygonGroupID polygon_group = mesh_desc.CreatePolygonGroup();

		mesh_desc.ReserveNewPolygons(1);
		mesh_desc.CreatePolygon(polygon_group, { vi0, vi1, vi2, vi3 });

		positions = attributes.GetVertexPositions();

		positions[0] = FVector3f(-100, -100, 0);
		positions[1] = FVector3f(-100, 100, 0);
		positions[2] = FVector3f(100, 100, 0);
		positions[3] = FVector3f(100, -100, 0);

		TVertexInstanceAttributesRef<FVector3f> normals = attributes.GetVertexInstanceNormals();

		normals[0] = FVector3f(0, 0, 1);
		normals[1] = FVector3f(0, 0, 1);
		normals[2] = FVector3f(0, 0, 1);
		normals[3] = FVector3f(0, 0, 1);

		/*TVertexInstanceAttributesRef<FVector2f> uvs = attributes.GetVertexInstanceUVs();

		uvs[0] = FVector2f(0, 0);
		uvs[1] = FVector2f(0, 1);
		uvs[2] = FVector2f(1, 1);
		uvs[3] = FVector2f(1, 0);*/

		// At least one material must be added
		UStaticMesh* mesh = NewObject<UStaticMesh>(this, FName(TEXT("ProceduralStaticMesh")));
		mesh->GetStaticMaterials().Add(FStaticMaterial());

		UStaticMesh::FBuildMeshDescriptionsParams mdParams;
		mdParams.bFastBuild = true;
		//mdParams.bBuildSimpleCollision = true;

		//mesh->NaniteSettings.bEnabled = true;

		UE_LOG(LogTemp, Error, TEXT("Vertices... %d"), mesh_desc.Vertices().Num());
		UE_LOG(LogTemp, Error, TEXT("VertexInstances... %d"), mesh_desc.VertexInstances().Num());
		UE_LOG(LogTemp, Error, TEXT("UVs... %d"), mesh_desc.UVs(0).Num());
		UE_LOG(LogTemp, Error, TEXT("Edges... %d"), mesh_desc.Edges().Num());
		UE_LOG(LogTemp, Error, TEXT("Triangles... %d"), mesh_desc.Triangles().Num());
		UE_LOG(LogTemp, Error, TEXT("Polygons... %d"), mesh_desc.Polygons().Num());
		UE_LOG(LogTemp, Error, TEXT("PolygonGroups... %d"), mesh_desc.PolygonGroups().Num());

		// Build static mesh
		mesh->BuildFromMeshDescriptions({ &mesh_desc }, mdParams);

		VisualMesh->SetStaticMesh(mesh);
		VisualMesh->SetMaterial(0, materialPrefab);
	}

}

// Called to bind functionality to input
void AInputPaw::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

