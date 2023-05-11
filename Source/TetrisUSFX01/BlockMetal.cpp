// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockMetal.h"

// Constructor
ABlockMetal::ABlockMetal()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creamos el componente UStaticMeshComponent
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));

	// Lo asignamos como RootComponent
	RootComponent = BlockMesh;

	// Cargamos la malla del bloque
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));

	if (BlockMeshAsset.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockMeshAsset.Object);
		BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

		// Cargamos el material para el bloque de metal
		UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/Metal.Metal'"));

		// Asignamos el material al componente UStaticMeshComponent
		BlockMesh->SetMaterial(0, MyMaterial);
		BlockMesh->SetMaterial(1, MyMaterial);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No se encontró la malla del bloque"));
	}
}

// Called when the game starts or when spawned
void ABlockMetal::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABlockMetal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

