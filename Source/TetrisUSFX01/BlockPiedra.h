// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "BlockPiedra.generated.h"

/**
 * 
 */
UCLASS()
class TETRISUSFX01_API ABlockPiedra : public ABlock
{
	GENERATED_BODY()

public:
	ABlockPiedra();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	UStaticMeshComponent* BlockMesh;
	
};
