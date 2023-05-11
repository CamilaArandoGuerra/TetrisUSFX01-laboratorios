// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "BlockHielo.generated.h"

/**
 * 
 */
UCLASS()
class TETRISUSFX01_API ABlockHielo : public ABlock
{
	GENERATED_BODY()

public:
	ABlockHielo();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	UStaticMeshComponent* BlockMesh;

	
};
