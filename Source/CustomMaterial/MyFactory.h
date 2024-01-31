// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Map.h"

#include "GLTFAsset.h"

struct FVertexID;
struct FMeshDescription;

namespace GLTFErdem
{
	struct FMesh;
	class MyFactoryImpl;


	class CUSTOMMATERIAL_API MyFactory
	{
	public:
		MyFactory();
		~MyFactory();

		using FIndexVertexIdMap = TMap<FPlatformTypes::int32, FVertexID>;

		void FillMeshDescription(const GLTF::FMesh& Mesh, FMeshDescription* MeshDescription);

		float GetUniformScale() const;
		void  SetUniformScale(float Scale);

		//const TArray<GLTF::FLogMessage>& GetLogMessages() const;

		void SetReserveSize(uint32 Size);

		TArray<MyFactory::FIndexVertexIdMap>& GetPositionIndexToVertexIdPerPrim() const;

		void CleanUp();

	private:
		TUniquePtr<MyFactoryImpl> Impl;
	};
}

#if UE_ENABLE_INCLUDE_ORDER_DEPRECATED_IN_5_2
#include "CoreMinimal.h"
#include "MeshTypes.h"
#endif
