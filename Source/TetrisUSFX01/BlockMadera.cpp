// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockMadera.h"

ABlockMadera::ABlockMadera() {
    PrimaryActorTick.bCanEverTick = true;
    vida = 3; // Cambiar la cantidad de vidas del bloque de madera
    BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
    RootComponent = BlockMesh;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block_madera.block_madera'")); // Cambiar la ruta de acceso a la malla de bloque de madera
    if (BlockMeshAsset.Succeeded())
    {
        BlockMesh->SetStaticMesh(BlockMeshAsset.Object);
        BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/M_Wood_Pine.M_Wood_Pine'")); // Cambiar la ruta de acceso al material de textura de madera
        BlockMesh->SetMaterial(0, MyMaterial);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
    }
}

void ABlockMadera::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABlockMadera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABlockMadera::reducirVida() {

    UE_LOG(LogTemp, Log, TEXT("Bloque de madera, Vidas: %d"), vida);
    --vida;
    if (vida <= 0) {
        DestroyActor();
    }
}

void ABlockMadera::DestroyActor() {
    Destroy();
}
