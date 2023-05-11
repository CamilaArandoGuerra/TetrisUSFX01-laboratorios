// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockExplosivo.h"

#include "bloqueExplosivo.h"
/// BLOQUE EXPLOSIVO

ABlockExplosivo::ABlockExplosivo() {
	PrimaryActorTick.bCanEverTick = true;
	//imprimirNombre();
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	RootComponent = BlockMesh;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));

	if (BlockMeshAsset.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockMeshAsset.Object);
		/*FVector NuevaEscala = FVector(0.03f, 0.03f, 0.03f);*/
		BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		//BlockMesh->SetWorldScale3D(NuevaEscala);
		UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/M_Explosive.M_Explosive'"));
		BlockMesh->SetMaterial(0, MyMaterial);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
	}
}

void ABlockExplosivo::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABlockExplosivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


