// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorNivel.h"

ADirectorNivel::ADirectorNivel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorNivel::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADirectorNivel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADirectorNivel::AsignarConstructorDeNivel(AActor* Builder)
{
	//Cast the passed Actor and set the Builder
	BuilderNivel = Cast<IBuilderNivel>(Builder);
	if (!BuilderNivel) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("CAST Inválido!!!!!!!!!"));
	}
}

ANivel* ADirectorNivel::GetNiveles()
{
	if (BuilderNivel)
	{
		//Returns the Lodging of the Builder
		return BuilderNivel->GetNiveles();
	}
	//Log if the Builder is NULL
	UE_LOG(LogTemp, Error, TEXT("Erro en GetNiveles, retornando nullptr!!!!!!!"));
	return nullptr;
}
void ADirectorNivel::ConstruirNivel()
{
	/*UWorld* World = GetWorld();*/


	//Log if the Builder is NULL
	if (!BuilderNivel) {
		UE_LOG(LogTemp, Error, TEXT("El builder es NULL, asegurate de inicializarlo!!!!!!!!!")); return;
	}
	//Creates the buildings
	BuilderNivel->spawnNivel();
}