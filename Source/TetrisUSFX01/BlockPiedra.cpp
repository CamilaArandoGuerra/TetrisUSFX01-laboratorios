// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockPiedra.h"

ABlockPiedra::ABlockPiedra() {
    PrimaryActorTick.bCanEverTick = true;
    vida = 2;
    BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
    RootComponent = BlockMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));
    if (BlockMeshAsset.Succeeded())
    {
        BlockMesh->SetStaticMesh(BlockMeshAsset.Object);
        BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/M_Stone01.M_Stone01'"));
        BlockMesh->SetMaterial(0, MyMaterial);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
    }
}

void ABlockPiedra::BeginPlay()
{
    Super::BeginPlay();
}

void ABlockPiedra::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

