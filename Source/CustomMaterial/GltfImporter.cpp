// Fill out your copyright notice in the Description page of Project Settings.


#include "GltfImporter.h" //Self

#include "GLTFAsset.h"
#include "GLTFReader.h"

#include "MyReader.h"
#include "MyFactory.h"

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"

#include "TestMaterial.h"

#include "MeshDescription.h"
#include "Kismet/GameplayStatics.h"

GltfImporter::GltfImporter()
{
}

GltfImporter::~GltfImporter()
{
}

void ReadGltfFile(GLTF::FAsset* outAsset, FString glbPath);
void PrintGltfAssetNodes(GLTF::FAsset* inAsset, ATestMaterial* parentActor, FProductPart* productPart);
void CalculateNodeTransforms(GLTF::FAsset* inAsset);
void CalculateChildNodeTransforms(GLTF::FAsset* inAsset, GLTF::FNode parentNode);
void CreateActorsFromMesh(UStaticMesh* inMesh, ATestMaterial* parentActor, FTransform meshTransform, UMaterialInstance* inMaterial, FString nodeName);
void CreateRuntimeGltfMeshes(GLTF::FAsset* inAsset, AImporterActor* parentActor);
void CreateRuntimeGltfMaterials(GLTF::FAsset* inAsset, AImporterActor* parentActor);

TArray<UStaticMesh*> outMeshes = TArray<UStaticMesh*>();
TArray<UMaterialInstance*> outMaterials = TArray<UMaterialInstance*>();
TArray<UTexture2D*> outTextures = TArray<UTexture2D*>();
bool matSetted = false;

void GltfImporter::ImportGltf(FString gltfPath, AImporterActor* parentActor, FCatalogProduct* productEntity, FProductPart* productPart)
{
	UE_LOG(LogTemp, Error, TEXT("Importing: %s"), *gltfPath);

	selfProductEntity = productEntity;
	selfProductPartEntity = productPart;

	outMeshes = TArray<UStaticMesh*>();
	outMaterials = TArray<UMaterialInstance*>();
	outTextures = TArray<UTexture2D*>();

	GLTF::FAsset erdemAsset = GLTF::FAsset();

	ReadGltfFile(&erdemAsset, gltfPath);

	CalculateNodeTransforms(&erdemAsset);

	CreateRuntimeGltfMaterials(&erdemAsset, parentActor);
	CreateRuntimeGltfMeshes(&erdemAsset, parentActor);

	ATestMaterial* myAct = parentActor->GetWorld()->SpawnActor<ATestMaterial>(ATestMaterial::StaticClass());
	
	if (selfProductEntity != nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Ending reader messages... %f %f %f"), selfProductEntity->position.x, selfProductEntity->position.y, selfProductEntity->position.z);
		myAct->SetActorLocation(selfProductEntity->GetPosition());
		myAct->SetActorRotation(selfProductEntity->GetRotation());
		myAct->SetActorScale3D(selfProductEntity->GetScale());
	}

#if WITH_EDITOR
	if (selfProductEntity != nullptr)
		myAct->SetActorLabel(*selfProductEntity->name);
#endif
	matSetted = false;
	PrintGltfAssetNodes(&erdemAsset, myAct, selfProductPartEntity);
}

void ReadGltfFile(GLTF::FAsset* outAsset, FString glbPath)
{
	GLTF::FFileReader gltfReaderBase = GLTF::FFileReader();
	gltfReaderBase.ReadFile(glbPath, true, true, *outAsset);
	outAsset->GenerateNames(TEXT("blank")); // Fixing empty name error!

	/*auto& erdemMessages = gltfReaderBase.GetLogMessages();
	UE_LOG(LogTemp, Error, TEXT("Printing reader messages: "));
	for (auto& erdemMsg : erdemMessages)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *erdemMsg.Value);
	}
	UE_LOG(LogTemp, Error, TEXT("Ending reader messages..."));*/
}

void PrintGltfAssetNodes(GLTF::FAsset* inAsset, ATestMaterial* parentActor, FProductPart* productPart)
{
	if (productPart != nullptr)
	{
		if (productPart->meshName == "")
			return;
		//if (matSetted)
		//	return;

		UE_LOG(LogTemp, Warning, TEXT("this part name ... %s"), *productPart->meshName);
		
		TArray<AActor*> testMaterialObjects;
		UGameplayStatics::GetAllActorsOfClass(parentActor, ATestMaterial::StaticClass(), testMaterialObjects);

		for (UMaterialInstance* mat : outMaterials)
		{
			for (AActor* testMaterialObject : testMaterialObjects)
			{
				ATestMaterial* testMaterialInstance = Cast<ATestMaterial>(testMaterialObject);
				TArray<UActorComponent*> staticMeshes;
				testMaterialInstance->GetComponents(staticMeshes);
				UE_LOG(LogTemp, Warning, TEXT("test material name ... %s"), *testMaterialObject->GetName());

				for (UActorComponent* staticMeshInstance : staticMeshes)
				{
					UStaticMeshComponent* staticMesh = Cast<UStaticMeshComponent>(staticMeshInstance);
					UE_LOG(LogTemp, Warning, TEXT("static mesh name ... %s"), *staticMesh->GetName());
					if (!staticMesh->GetName().Equals(productPart->meshName))
					{
						continue;
					}
					if (staticMesh->GetStaticMesh() == nullptr)
					{
						UE_LOG(LogTemp, Warning, TEXT("i am null here ... %s"), *testMaterialObject->GetName());
						continue;
					}

					UE_LOG(LogTemp, Warning, TEXT("i have something here ... %s"), *testMaterialObject->GetName());
					staticMesh->SetMaterial(0, mat);
					matSetted = true;
					//goto nextMat;
				}
			}
			//nextMat:
			{

			}
		}
		return;
	}

	for (auto& curNode : inAsset->Nodes)
	{
		if (curNode.Type == GLTF::FNode::EType::Mesh)
		{
			auto& currentMesh = outMeshes[curNode.MeshIndex];

			for (auto& primitive : inAsset->Meshes[curNode.MeshIndex].Primitives)
			{
				auto& currentMaterial = outMaterials[primitive.MaterialIndex];
				
				CreateActorsFromMesh(currentMesh, parentActor, curNode.Transform, currentMaterial, curNode.Name);
			}
		}
	}
}

void CalculateNodeTransforms(GLTF::FAsset* inAsset)
{
	TArray<int32> rootNodeIndices = TArray<int32>();

	inAsset->GetRootNodes(rootNodeIndices);

	for (auto& rIndice : rootNodeIndices)
	{
		FTransform curTransform = inAsset->Nodes[rIndice].Transform;
		CalculateChildNodeTransforms(inAsset, inAsset->Nodes[rIndice]);
	}
}

void CalculateChildNodeTransforms(GLTF::FAsset* inAsset, GLTF::FNode parentNode)
{
	for (auto& childIndice : parentNode.Children)
	{
		inAsset->Nodes[childIndice].Transform.Accumulate(parentNode.Transform);
		CalculateChildNodeTransforms(inAsset, inAsset->Nodes[childIndice]);
	}
}

void CreateRuntimeGltfMeshes(GLTF::FAsset* inAsset, AImporterActor* parentActor)
{
	//GLTF::FMeshFactory myFact = GLTF::FMeshFactory();
	GLTFErdem::MyFactory myFact = GLTFErdem::MyFactory();
	myFact.SetUniformScale(100);

	for (auto& myMesh : inAsset->Meshes)
	{
		UStaticMesh* mystaticMesh = NewObject<UStaticMesh>();
		mystaticMesh->GetStaticMaterials().Add(FStaticMaterial());

		FMeshDescription MeshDescription;
		myFact.FillMeshDescription(myMesh, &MeshDescription);

		UStaticMesh::FBuildMeshDescriptionsParams mdParams;
		mdParams.bFastBuild = true;

		// Build static mesh
		TArray<const FMeshDescription*> meshDescPtrs;
		meshDescPtrs.Emplace(&MeshDescription);
		mystaticMesh->BuildFromMeshDescriptions(meshDescPtrs, mdParams);

		outMeshes.Add(mystaticMesh);
	}
}

void CreateRuntimeGltfMaterials(GLTF::FAsset* inAsset, AImporterActor* parentActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Material create starting ..."));

	for (auto& gltfTexture : inAsset->Textures)
	{
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

		EImageFormat myFormaty = ImageWrapperModule.DetectImageFormat(gltfTexture.Source.Data, gltfTexture.Source.DataByteLength);

		// Note: PNG format.  Other formats are supported
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(myFormaty);

		if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(gltfTexture.Source.Data, gltfTexture.Source.DataByteLength))
		{
			TArray<uint8> UncompressedBGRA;
			if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
			{
				// Create the UTexture for rendering
				UTexture2D* MyTexture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);

				// Fill in the source data from the file
				uint8* TextureData = (uint8*)MyTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedBGRA.GetData(), UncompressedBGRA.Num());
				MyTexture->GetPlatformData()->Mips[0].BulkData.Unlock();

				// Update the rendering resource from data.
				MyTexture->UpdateResource();

				//UE_LOG(LogTemp, Warning, TEXT("AFTER Texture %d "), MyTexture->GetSizeX());
				//UE_LOG(LogTemp, Warning, TEXT("AFTER Texture %d "), MyTexture->GetSizeY());

				outTextures.Add(MyTexture);
			}
		}
	}

	for (auto& gltfMat : inAsset->Materials)
	{
		UMaterialInstanceDynamic* sceneMat = UMaterialInstanceDynamic::Create(parentActor->materialPrefab, parentActor);

		sceneMat->SetVectorParameterValue("BaseColor", gltfMat.BaseColorFactor);

		sceneMat->SetScalarParameterValue("BaseColorScaleX", gltfMat.BaseColor.TextureTransform.Scale[0]);
		sceneMat->SetScalarParameterValue("BaseColorScaleY", gltfMat.BaseColor.TextureTransform.Scale[1]);
		if (gltfMat.BaseColor.TextureIndex > -1)
		{
			sceneMat->SetTextureParameterValue("BaseColor Map", outTextures[gltfMat.BaseColor.TextureIndex]);
		}
		sceneMat->SetScalarParameterValue("Normal Scale", gltfMat.NormalScale);

		sceneMat->SetScalarParameterValue("NormalMapScaleX", gltfMat.Normal.TextureTransform.Scale[0]);
		sceneMat->SetScalarParameterValue("NormalMapScaleY", gltfMat.Normal.TextureTransform.Scale[1]);
		if (gltfMat.Normal.TextureIndex > -1)
		{
			FMaterialParameterInfo erdemInfo = FMaterialParameterInfo();
			erdemInfo.Association = EMaterialParameterAssociation::GlobalParameter;
			erdemInfo.Name = "Normal Map";
			sceneMat->SetTextureParameterValueByInfo(erdemInfo, outTextures[gltfMat.Normal.TextureIndex]);
		}

		sceneMat->SetScalarParameterValue("Metallic Factor", gltfMat.MetallicRoughness.MetallicFactor);
		sceneMat->SetScalarParameterValue("Roughness Factor", gltfMat.MetallicRoughness.RoughnessFactor);

		sceneMat->SetScalarParameterValue("MetallicRoughnessMapScaleX", gltfMat.MetallicRoughness.Map.TextureTransform.Scale[0]);
		sceneMat->SetScalarParameterValue("MetallicRoughnessMapScaleY", gltfMat.MetallicRoughness.Map.TextureTransform.Scale[1]);

		if (gltfMat.MetallicRoughness.Map.TextureIndex > -1)
		{
			sceneMat->SetTextureParameterValue("MetallicRoughness Map", outTextures[gltfMat.MetallicRoughness.Map.TextureIndex]);
		}
		sceneMat->SetScalarParameterValue("Occlusion Strength", gltfMat.OcclusionStrength);

		sceneMat->SetScalarParameterValue("MetallicRoughnessMapScaleX", gltfMat.Occlusion.TextureTransform.Scale[0]);
		sceneMat->SetScalarParameterValue("MetallicRoughnessMapScaleY", gltfMat.Occlusion.TextureTransform.Scale[1]);

		if (gltfMat.Occlusion.TextureIndex > -1)
		{
			sceneMat->SetTextureParameterValue("Occlusion Map", outTextures[gltfMat.Occlusion.TextureIndex]);
		}

		outMaterials.Add(sceneMat);
	}
}

void CreateActorsFromMesh(UStaticMesh* inMesh, ATestMaterial* parentActor, FTransform meshTransform, UMaterialInstance* inMaterial, FString nodeName)
{
	UStaticMeshComponent* newComponent = NewObject<UStaticMeshComponent>(parentActor);

	newComponent->Rename(*nodeName);
	
	newComponent->RegisterComponent();
	newComponent->AttachToComponent(parentActor->VisualMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName(*nodeName));
	parentActor->AddInstanceComponent(newComponent);

	//newComponent->SetRelativeLocation(... position ...);

	newComponent->SetStaticMesh(inMesh);
	newComponent->SetMaterial(0, inMaterial);

	parentActor->SetActorLocation(FVector(FMath::RandRange(-500, 500), FMath::RandRange(-500, 500), 0));
	//myAct->SetActorLocation(FVector(FMath::RandRange(-100, 100), FMath::RandRange(-100, 100), FMath::RandRange(-100, 100)));
	//myMeshStat->SetWorldLocation(FVector(FMath::RandRange(-100, 100), FMath::RandRange(-100, 100), FMath::RandRange(-100, 100)));
	newComponent->SetRelativeLocation(meshTransform.GetLocation() * 100);
	newComponent->SetRelativeScale3D(meshTransform.GetScale3D());
	newComponent->SetRelativeRotation(meshTransform.GetRotation());
}
