// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderNivel.h"
#include "DirectorNivel.generated.h"

UCLASS()
class TETRISUSFX01_API ADirectorNivel : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADirectorNivel();

	IBuilderNivel* BuilderNivel;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Crea los Niveles			--constructNivel
	void ConstruirNivel();
	//Asignar el Actor Builder	--setNivelConstructor
	void AsignarConstructorDeNivel(AActor* Builder);
	//Obtener el Nivel del Builder --getniveles
	class ANiveles* GetNiveles();


};
