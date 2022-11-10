// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestClass.h"

MyTestClass::MyTestClass()
{
}

MyTestClass::~MyTestClass()
{
}

void TestMethod()
{
	FString erdem1 = "erdem";
	UE_LOG(LogTemp, Warning, TEXT("%s"), *erdem1); // NICE

	UE_LOG(LogTemp, Warning, TEXT("erdem")); // BEAUTIFUL
}
