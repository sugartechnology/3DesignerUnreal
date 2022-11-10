// Fill out your copyright notice in the Description page of Project Settings.

#include "Erdem.h"
#include "GLTFCoreModule.h"

#include "GLTFAsset.h"
#include "GLTFLogger.h"
#include "GLTFMeshFactory.h"
#include "GLTFMaterialFactory.h"
#include "GLTFReader.h"
#include "GLTFMaterialExpressions.h"

#include "MyActor.h"
#include "MyMeshActor.h"

#include "MeshDescription.h"

#include "DatasmithTranslator/Public/Utility/DatasmithMeshHelper.h"
#include "DatasmithSceneFactory.h"

#include "Engine/StaticMeshActor.h"

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"


void ReadGltfFile(GLTF::FFileReader* inFileReader, GLTF::FAsset* outAsset, FString glbPath);
void PrintGltfAssetNodes(GLTF::FAsset* inAsset, AErdem* parentActor);
void CalculateNodeTransforms(GLTF::FAsset* inAsset);
//void CreateGltfMeshes(GLTF::FStaticMeshFactory* inMeshFactory, GLTF::FAsset* inAsset, AErdem* parentPackage);
FString GetNodeType(GLTF::FNode::EType nodeType);
void CalculateChildNodeTransforms(GLTF::FAsset* inAsset, GLTF::FNode parentNode);
void CreateActorsFromMesh(UStaticMesh* inMesh, AErdem* parentActor, FTransform meshTransform);
void CreateRuntimeGltfMeshes(GLTF::FAsset* inAsset, AErdem* parentActor);
void CreateRuntimeGltfMaterials(GLTF::FAsset* inAsset, AErdem* parentActor);
void AddMaterialsToMesh(UStaticMesh* inMesh, AErdem* parentActor, UMaterialInstance* inMaterial);


// Sets default values
AErdem::AErdem()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

TArray<UStaticMesh*> outMeshes = TArray<UStaticMesh*>();
TArray<UMaterialInstance*> outMaterials = TArray<UMaterialInstance*>();
TArray<UTexture2D*> outTextures = TArray<UTexture2D*>();

// Called when the game starts or when spawned
void AErdem::BeginPlay()
{
	Super::BeginPlay();

	// If this is not added here unreal engine goes mad when you start the game a second time :)
	outMeshes = TArray<UStaticMesh*>(); 
	outMaterials = TArray<UMaterialInstance*>();
	outTextures = TArray<UTexture2D*>();

	GLTF::FAsset erdemAsset = GLTF::FAsset();
	GLTF::FFileReader erdemReader = GLTF::FFileReader();

	ReadGltfFile(&erdemReader, &erdemAsset, glbPath);

	CalculateNodeTransforms(&erdemAsset);

	CreateRuntimeGltfMeshes(&erdemAsset, this);
	CreateRuntimeGltfMaterials(&erdemAsset, this);

	PrintGltfAssetNodes(&erdemAsset, this);
}

// Called every frame
void AErdem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AErdem::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ReadGltfFile(GLTF::FFileReader* inFileReader, GLTF::FAsset* outAsset, FString glbPath)
{
	inFileReader->ReadFile(glbPath, true, true, *outAsset);

	outAsset->GenerateNames(TEXT("blank")); // Fixing empty name error!

	auto& erdemMessages = inFileReader->GetLogMessages();
	UE_LOG(LogTemp, Error, TEXT("Printing reader messages: "));
	for (auto& erdemMsg : erdemMessages)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *erdemMsg.Value);
	}
	UE_LOG(LogTemp, Error, TEXT("Ending reader messages..."));
}

void PrintGltfAssetNodes(GLTF::FAsset* inAsset, AErdem* parentActor)
{
	UE_LOG(LogTemp, Error, TEXT("Printing nodes..."));
	UE_LOG(LogTemp, Error, TEXT("Total nodes : %d"), inAsset->Nodes.Num());

	for (auto& erdemAS : inAsset->Nodes)
	{
		UE_LOG(LogTemp, Warning, TEXT("Printing index: %d"), erdemAS.MeshIndex);
		UE_LOG(LogTemp, Warning, TEXT("Printing node name: %s"), *erdemAS.Name);

		UE_LOG(LogTemp, Warning, TEXT("Printing node name: %s"), *GetNodeType(erdemAS.Type));

		UE_LOG(LogTemp, Warning, TEXT("Printing location: X:%f Y:%f Z:%f"), erdemAS.Transform.GetLocation().X, erdemAS.Transform.GetLocation().Y, erdemAS.Transform.GetLocation().Z);
		UE_LOG(LogTemp, Warning, TEXT("Printing rotation: X:%f Y:%f Z:%f"), erdemAS.Transform.GetRotation().X, erdemAS.Transform.GetRotation().Y, erdemAS.Transform.GetRotation().Z);
		UE_LOG(LogTemp, Warning, TEXT("Printing scale3D: X:%f Y:%f Z:%f"), erdemAS.Transform.GetScale3D().X, erdemAS.Transform.GetScale3D().Y, erdemAS.Transform.GetScale3D().Z);
		
		if (erdemAS.Type == GLTF::FNode::EType::Mesh)
		{
			auto& currentMesh = outMeshes[erdemAS.MeshIndex];

			for (auto& primitive : inAsset->Meshes[erdemAS.MeshIndex].Primitives)
			{
				UE_LOG(LogTemp, Warning, TEXT("MAterial erdem iindex: %d"), primitive.MaterialIndex);
				//auto& currentMaterial = outMaterials[primitive.MaterialIndex];

				AddMaterialsToMesh(currentMesh, parentActor, nullptr);
			}
			
			CreateActorsFromMesh(currentMesh, parentActor, erdemAS.Transform);
		}
	}
}

void CalculateNodeTransforms(GLTF::FAsset* inAsset)
{
	TArray<int32> rootNodeIndices = TArray<int32>();

	inAsset->GetRootNodes(rootNodeIndices);

	UE_LOG(LogTemp, Error, TEXT("Printing root indices: "));
	for (auto& rIndice : rootNodeIndices)
	{
		UE_LOG(LogTemp, Warning, TEXT("Printing root indices: %d"), rIndice);
		FTransform curTransform = inAsset->Nodes[rIndice].Transform;
		CalculateChildNodeTransforms(inAsset, inAsset->Nodes[rIndice]);
	}
}

void CalculateChildNodeTransforms(GLTF::FAsset* inAsset, GLTF::FNode parentNode)
{
	//UE_LOG(LogTemp, Warning, TEXT("Printing Root Indices..."));
	UE_LOG(LogTemp, Error, TEXT("Printing child indices: "));
	for (auto& childIndice : parentNode.Children)
	{		
		UE_LOG(LogTemp, Warning, TEXT("Printing root indices: %d"), childIndice);
		UE_LOG(LogTemp, Warning, TEXT("Printing location: X:%f Y:%f Z:%f"), inAsset->Nodes[childIndice].Transform.GetLocation().X);
		inAsset->Nodes[childIndice].Transform.Accumulate(parentNode.Transform);
		UE_LOG(LogTemp, Warning, TEXT("Printing location: X:%f Y:%f Z:%f"), inAsset->Nodes[childIndice].Transform.GetLocation().X);

		CalculateChildNodeTransforms(inAsset, inAsset->Nodes[childIndice]);
	}
}

FString GetNodeType(GLTF::FNode::EType nodeType)
{
	switch (nodeType)
	{
		case GLTF::FNode::EType::Camera:
			return "Camera";
		case GLTF::FNode::EType::Joint:
			return "Joint";
		case GLTF::FNode::EType::Light:
			return "Light";
		case GLTF::FNode::EType::Mesh:
			return "Mesh";
		case GLTF::FNode::EType::MeshSkinned:
			return "MeshSkinned";
		case GLTF::FNode::EType::None:
			return "None";
		case GLTF::FNode::EType::Transform:
			return "Transform";
		default:
			return "";
	}
}



void CreateRuntimeGltfMeshes(GLTF::FAsset* inAsset, AErdem* parentActor)
{
	GLTF::FMeshFactory myFact = GLTF::FMeshFactory();
	myFact.SetUniformScale(100);

	for (auto& myMesh : inAsset->Meshes)
	{
		AMyMeshActor* myAct = parentActor->GetWorld()->SpawnActor<AMyMeshActor>();
		//UStaticMeshComponent* myMeshStat = myAct->VisualMesh;

		UStaticMesh* mystaticMesh = NewObject<UStaticMesh>();

		//FMeshDescription* MeshDescription = myMeshStat->GetStaticMesh()->CreateMeshDescription(0);
		FMeshDescription MeshDescription;
		DatasmithMeshHelper::PrepareAttributeForStaticMesh(MeshDescription);

		myFact.FillMeshDescription(myMesh, &MeshDescription);
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

		UStaticMesh::FBuildMeshDescriptionsParams mdParams;
		mdParams.bBuildSimpleCollision = true;
		mdParams.bFastBuild = true;

		// Build static mesh
		TArray<const FMeshDescription*> meshDescPtrs;
		meshDescPtrs.Emplace(&MeshDescription);
		mystaticMesh->BuildFromMeshDescriptions(meshDescPtrs, mdParams);

		outMeshes.Add(mystaticMesh);

		//myMeshStat->SetStaticMesh(mystaticMesh);

		UE_LOG(LogTemp, Error, TEXT("Mesh build suucess..."));
	}
}

class FErdemGLTFMaterialElement : public GLTF::FMaterialElement
{
public:
	FErdemGLTFMaterialElement(const FString& Name) : GLTF::FMaterialElement(Name)
	{

	}

	virtual int  GetBlendMode() const override
	{
		return 0;
	}
	virtual void SetBlendMode(int InBlendMode) override
	{

	}
	virtual bool GetTwoSided() const override
	{
		return false;
	}
	virtual void SetTwoSided(bool bTwoSided) override
	{

	}
	virtual void SetShadingModel(GLTF::EGLTFMaterialShadingModel InShadingModel) override
	{

	}
	virtual void SetTranslucencyLightingMode(int InLightingMode) override
	{

	}
	virtual void Finalize() override
	{

	}
};

class ERDEMMaterialElementFactory : public GLTF::IMaterialElementFactory
{
public:
	virtual GLTF::FMaterialElement* CreateMaterial(const TCHAR* Name, UObject* ParentPackage, EObjectFlags Flags) override
	{
		//const FString PackageName = ParentPackage->GetName() + TEXT("Materials") + Name;
		//UPackage* AssetPackage = CreatePackage(*PackageName);
		//UMaterial* Material = NewObject<UMaterial>(AssetPackage, UMaterial::StaticClass(), *FPaths::GetBaseFilename(PackageName), Flags);
		return new FErdemGLTFMaterialElement(Name);
	}
};

class FGLTFERDEMTextureElement : public GLTF::ITextureElement
{
public:
	FTexture* Texture;

	FGLTFERDEMTextureElement(FTexture& Texture)
		: Texture(&Texture)
	{
	}
};

class ERDEMTextureElementFactory : public GLTF::ITextureFactory
{
public:
	virtual GLTF::ITextureElement* CreateTexture(const GLTF::FTexture& Texture, UObject* ParentPackage, EObjectFlags Flags, GLTF::ETextureMode TextureMode)
	{
		//TSharedPtr<GLTF::ITextureElement> TextureElement(new FGLTFERDEMTextureElement(*Texture));
		//CreatedTextures.Add(TextureElement);
		//FGLTFERDEMTextureElement TextureElement;// = FGLTFERDEMTextureElement(*Texture);
		//return &TextureElement;
		return nullptr;
	}
	virtual void CleanUp()
	{

	}
};


void CreateRuntimeGltfMaterials(GLTF::FAsset* inAsset, AErdem* parentActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Material create starting ..."));

	//TSharedPtr<IDatasmithUEPbrMaterialElement> MaterialElement = FDatasmithSceneFactory::CreateUEPbrMaterial(TEXT("ErdemMat"));
	//CurrentScene->AddMaterial(MaterialElement);
	ERDEMMaterialElementFactory* EElementFactory = new ERDEMMaterialElementFactory();
	ERDEMTextureElementFactory* ETextureFactory = new ERDEMTextureElementFactory();
	

	GLTF::FMaterialFactory* myFact = new GLTF::FMaterialFactory(EElementFactory, ETextureFactory);
	myFact->CleanUp();
	TArray<GLTF::FMaterialElement*> gltfMaterials = myFact->CreateMaterials(*inAsset, parentActor, EObjectFlags::RF_WillBeLoaded);


	for (auto& txt : inAsset->Textures)
	{
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

		EImageFormat myFormaty = ImageWrapperModule.DetectImageFormat(txt.Source.Data, txt.Source.DataByteLength);

		if (myFormaty == EImageFormat::Invalid) UE_LOG(LogTemp, Warning, TEXT("Invalide"));
		if (myFormaty == EImageFormat::PNG) UE_LOG(LogTemp, Warning, TEXT("PNGG"));
		if (myFormaty == EImageFormat::JPEG) UE_LOG(LogTemp, Warning, TEXT("JPEGG"));
		if (myFormaty == EImageFormat::GrayscaleJPEG) UE_LOG(LogTemp, Warning, TEXT("GrayscaleJPEGG"));

		//UE_LOG(LogTemp, Warning, TEXT("Texture format %s"), *(UEnum::GetDisplayValueAsText(myFormaty).ToString()));

		// Note: PNG format.  Other formats are supported
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(myFormaty);

		GLTF::FImage::EFormat myERdem = txt.Source.Format;
		//UE_LOG(LogTemp, Warning, TEXT("Texture formats %s"), *(UEnum::GetDisplayValueAsText(myERdem).ToString()));

		UE_LOG(LogTemp, Warning, TEXT("TRYING Texture"));
		if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(txt.Source.Data, txt.Source.DataByteLength))
		{
			UE_LOG(LogTemp, Warning, TEXT("Creating Texture"));
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

				UE_LOG(LogTemp, Warning, TEXT("AFTER Texture %d "), MyTexture->GetSizeX());
				UE_LOG(LogTemp, Warning, TEXT("AFTER Texture %d "), MyTexture->GetSizeY());

				outTextures.Add(MyTexture);
			}
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Material create ending ... %d"), gltfMaterials.Num());

	for (auto& gltfMat : inAsset->Materials)
	{
		UMaterialInstanceDynamic* sceneMat = UMaterialInstanceDynamic::Create(parentActor->materialPrefab, parentActor);
		/*
		UE_LOG(LogTemp, Warning, TEXT("Material create ending ... %d"), gltfMat.BaseColor.TextureIndex);
		UE_LOG(LogTemp, Warning, TEXT("Material create ending ... %d"), gltfMat.Normal.TextureIndex);
		UE_LOG(LogTemp, Warning, TEXT("Material create ending ... %d"), gltfMat.MetallicRoughness.Map.TextureIndex);
		UE_LOG(LogTemp, Warning, TEXT("Material create ending ... %d"), gltfMat.Occlusion.TextureIndex);

		UE_LOG(LogTemp, Warning, TEXT("Total texrues ... %d"), outTextures.Num());

		
		sceneMat->SetVectorParameterValue("BaseColor", gltfMat.BaseColorFactor);
		if (gltfMat.BaseColor.TextureIndex > -1)
		{
			sceneMat->SetTextureParameterValue("BaseColor Map", outTextures[gltfMat.BaseColor.TextureIndex]);
		}
		sceneMat->SetScalarParameterValue("Normal Scale", gltfMat.NormalScale);
		if (gltfMat.Normal.TextureIndex > -1)
		{
			FMaterialParameterInfo erdemInfo = FMaterialParameterInfo();
			erdemInfo.Association = EMaterialParameterAssociation::BlendParameter;
			erdemInfo.Name = "Normal Map";
			sceneMat->SetTextureParameterValueByInfo(erdemInfo, outTextures[gltfMat.Normal.TextureIndex]);
		}
		sceneMat->SetScalarParameterValue("Metallic Factor", gltfMat.MetallicRoughness.MetallicFactor);
		sceneMat->SetScalarParameterValue("Roughness Factor", gltfMat.MetallicRoughness.RoughnessFactor);
		if (gltfMat.MetallicRoughness.Map.TextureIndex > -1)
		{
			sceneMat->SetTextureParameterValue("MetallicRoughness Map", outTextures[gltfMat.MetallicRoughness.Map.TextureIndex]);
		}
		sceneMat->SetScalarParameterValue("Occlusion Strength", gltfMat.OcclusionStrength);
		if (gltfMat.Occlusion.TextureIndex > -1)
		{
			sceneMat->SetTextureParameterValue("Occlusion Map", outTextures[gltfMat.Occlusion.TextureIndex]);
		}

		// Modify sceneMat with gltfMat
		*/
		//const FVector4 newBCpp = FVector4(0, 0, 0, 0);
		//sceneMat->SetVectorParameterValue(FName("BaseColor"), FLinearColor(0,0,0,0));
		outMaterials.Add(sceneMat);
	}
}

void AddMaterialsToMesh(UStaticMesh* inMesh, AErdem* parentActor, UMaterialInstance* inMaterial)
{
	//inMesh->AddMaterial(inMaterial);
	
	//UMaterialInstanceConstant* MI_SkySphere = LoadObject<UMaterialInstanceConstant>(nullptr, TEXT("/Game/Hero/WeatherSystem/Materials/Sky/MI_SkySphere.MI_SkySphere"));
	
	//inMesh->AddMaterial(parentActor->materialPrefab);

	UMaterial* mt = LoadObject<UMaterial>(nullptr, TEXT("/Game/erdem/ERdemMat.ERdemMat"));
	inMesh->AddMaterial(mt);
	//inMesh->SetMaterial();
}

void CreateActorsFromMesh(UStaticMesh* inMesh, AErdem* parentActor, FTransform meshTransform)
{
	AMyMeshActor* myAct = parentActor->GetWorld()->SpawnActor<AMyMeshActor>(AMyMeshActor::StaticClass());

	UStaticMeshComponent* myMeshStat = myAct->VisualMesh;

	//ee->Build();
	//ee->GetStaticMaterialsName();
	//UStaticMeshComponent* myMeshStat = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("erdem"));
	//myMeshStat->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	myMeshStat->SetStaticMesh(inMesh);
	myMeshStat->SetWorldLocation(meshTransform.GetLocation()*100);
	myMeshStat->SetWorldScale3D(meshTransform.GetScale3D());
	myMeshStat->SetWorldRotation(meshTransform.GetRotation());

	//inMesh->Build();

	UE_LOG(LogTemp, Warning, TEXT("Printing bounds..."));
	UE_LOG(LogTemp, Warning, TEXT("%f"), inMesh->GetBounds().BoxExtent.X);
	UE_LOG(LogTemp, Warning, TEXT("%f"), inMesh->GetBounds().BoxExtent.Y);
	UE_LOG(LogTemp, Warning, TEXT("%f"), inMesh->GetBounds().BoxExtent.Z);
}

