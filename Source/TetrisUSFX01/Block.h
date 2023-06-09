// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS(Abstract)
class TETRISUSFX01_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();
	virtual void reducirVida() PURE_VIRTUAL(ABlock::reducirVida, );

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int vida;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtual void MostrarInformacion() = 0;
	void MostrarInformacion() PURE_VIRTUAL(ABlock::MostrarInformacion, );
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BlockMesh;

	UPROPERTY(EditAnywhere)
	TArray<class UMaterial*> Materials;


};
