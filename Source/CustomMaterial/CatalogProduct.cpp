// Fill out your copyright notice in the Description page of Project Settings.

#include "CatalogProduct.h"

FVector FCatalogProduct::GetPosition()
{
	return FVector(FCatalogProduct::position.z * 100, FCatalogProduct::position.x * 100, FCatalogProduct::position.y * 100);
}

FRotator FCatalogProduct::GetRotation()
{
	return FRotator::MakeFromEuler(FVector(-FCatalogProduct::rotation.x, FCatalogProduct::rotation.z, -FCatalogProduct::rotation.y + 90));
}

FVector FCatalogProduct::GetScale()
{
	if (scale.x == 0 && scale.y == 0 && scale.z == 0)
		return FVector(1, 1, 1);
	return FVector(FCatalogProduct::scale.x, FCatalogProduct::scale.z, FCatalogProduct::scale.y);
}
