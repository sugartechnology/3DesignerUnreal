// Fill out your copyright notice in the Description page of Project Settings.

#include "ImporterActor.h"

#include "HAL/FileManagerGeneric.h"
#include "MyReader.h"
#include "GltfImporter.h"


APlayerController* playerControl;
FCatalogProject currentProject;

int curProduct = 0;
float myTimer = 0;
// Sets default values
AImporterActor::AImporterActor()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void AImporterActor::BeginPlay()
{
	Super::BeginPlay();

	playerControl = GetWorld()->GetFirstPlayerController();
	EnableInput(playerControl);
	myTimer = 0;
	currentProject = FCatalogProject();
	UE_LOG(LogTemp, Display, TEXT("null ptr here"));
}

class FFileVisitor : public IPlatformFile::FDirectoryVisitor
{
public:
	virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override
	{
		if (!bIsDirectory)
		{
			Files.Add(FilenameOrDirectory);
		}
		return true;
	}

	TArray<FString> Files;
};

// Called every frame
void AImporterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerControl->IsInputKeyDown(EKeys::R))
	{
		DirectionalLightParent->AddActorWorldRotation(FRotator(0, 0, 20 * DeltaTime));
	}

	if (playerControl == NULL)
		return;

	if (currentProject.name != "")
	{
		if (myTimer < 3)
		{
			myTimer += FApp::GetDeltaTime();
			return;
		}

		myTimer = 0;
		int t_products = currentProject.catalogScene.products.Num();
		for (; curProduct < t_products; curProduct++)
		{
			auto p_name = currentProject.catalogScene.products[curProduct].name;
			UE_LOG(LogTemp, Display, TEXT("product name %s"), *p_name);
			UMyReader* downloadReader = NewObject<UMyReader>();
			downloadReader->DownloadFromProduct(&currentProject.catalogScene.products[curProduct], this);
			/*for (int j = 0; j < currentProject->catalogScene.products[curProduct].productParts.Num(); j++)
			{
				//UE_LOG(LogTemp, Display, TEXT("product part name %s"), *currentProject->catalogScene.products[curProduct].productParts[j].name);
				//UE_LOG(LogTemp, Display, TEXT("product part fabric name %s"), *currentProject->catalogScene.products[curProduct].productParts[j].fabric.name);
				UMyReader* fabricDownloadReader = NewObject<UMyReader>();
				fabricDownloadReader->DownloadFromFabric(&currentProject->catalogScene.products[curProduct].productParts[j], this);
			}*/
		}
	}

	if (playerControl->WasInputKeyJustPressed(EKeys::E))
	{
		bool wasSuccessFull;
		FString tmpStr;

		UMyReader* newReader = NewObject<UMyReader>();

		newReader->cacheFilePath = rrImportCacheDir;

		currentProject = newReader->ReadJsonFileAsRR(rrDir, wasSuccessFull, tmpStr);
		if (wasSuccessFull)
		{
			myTimer = 0;
			curProduct = 0;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("fail me %s"), *tmpStr);
			UE_LOG(LogTemp, Error, TEXT("fail me "));
		}
	}

	if (playerControl->WasInputKeyJustPressed(EKeys::K))
	{
		UE_LOG(LogTemp, Error, TEXT("pressed KEY :K"));
		const TCHAR* erdemChar = TEXT("");

		FFileManagerGeneric erdemFileMan = FFileManagerGeneric();
		FFileVisitor* myFileVisitor = new FFileVisitor();

		const TCHAR* glbDirChar = *glbDir;

		erdemFileMan.IterateDirectory(glbDirChar, *myFileVisitor);

		for (FString localGLBFile : myFileVisitor->Files)
		{
			UE_LOG(LogTemp, Error, TEXT("Loading file : %s"), *localGLBFile);

			ImportGLB(localGLBFile, nullptr, nullptr);
		}
	}
}


void AImporterActor::ImportGLB(FString gltfPath, FCatalogProduct* productEntity, FProductPart* currentProductPartEntity)
{
	GltfImporter myImporter = GltfImporter();
	myImporter.ImportGltf(gltfPath, this, productEntity, currentProductPartEntity);
}

