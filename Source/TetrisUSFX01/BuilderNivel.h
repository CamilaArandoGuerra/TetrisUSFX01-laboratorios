// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuilderNivel.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuilderNivel : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRISUSFX01_API IBuilderNivel
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual class ANivel* GetNivel() = 0;
	virtual void cargarNivel(FString nombreNivel) = 0;

};
