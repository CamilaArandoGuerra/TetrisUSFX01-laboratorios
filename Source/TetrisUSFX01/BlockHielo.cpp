// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockHielo.h"

ABlockHielo::ABlockHielo() {
	PrimaryActorTick.bCanEverTick = true;
	vida = 3;
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	RootComponent = BlockMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/ice.ice'"));
	if (BlockMeshAsset.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockMeshAsset.Object);
		BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/M_Ice.M_Ice'"));
		BlockMesh->SetMaterial(0, MyMaterial);
		BlockMesh->SetMaterial(1, MyMaterial);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
	}
}

void ABlockHielo::BeginPlay()
{
	Super::BeginPlay();
}

void ABlockHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
