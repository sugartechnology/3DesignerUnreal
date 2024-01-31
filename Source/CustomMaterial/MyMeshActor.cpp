// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMeshActor.h"
#include "GLTFAsset.h"
#include "GLTFLogger.h"
#include "GLTFMeshFactory.h"
#include "GLTFMaterialFactory.h"
#include "GLTFReader.h"
#include "GLTFMaterialExpressions.h"
//#include "CUSTOMMATERIAL_API/Erdem.h"

// Sets default values
AMyMeshActor::AMyMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	/*
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	*/
}

// Called when the game starts or when spawned
void AMyMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
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


	//GLTF::FMaterialFactory* myFact = new GLTF::FMaterialFactory(EElementFactory, ETextureFactory);
	//myFact->CleanUp();
	//TArray<GLTF::FMaterialElement*> gltfMaterials = myFact->CreateMaterials(*inAsset, parentActor, EObjectFlags::RF_WillBeLoaded);
}
*/