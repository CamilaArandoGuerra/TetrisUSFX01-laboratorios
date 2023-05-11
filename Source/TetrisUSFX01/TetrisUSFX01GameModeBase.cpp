// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"
#include "Board.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"


ATetrisUSFX01GameModeBase::ATetrisUSFX01GameModeBase() {
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    DefaultPawnClass = ABoard::StaticClass();
    siguientePosicionZ = 0;

    DefaultPawnClass = ABoard::StaticClass();

}

void ATetrisUSFX01GameModeBase::BeginPlay()
{
    // Call the parent class version of this function
    Super::BeginPlay();
    // Displays a red message on the screen for 10 seconds
    //GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Block"));
    // Spawn an instance of the AMyFirstActor class at the
    //default location.
    /*FTransform SpawnLocation;
    SpawnedActor = GetWorld()->SpawnActor<ABlock>(ABlock::StaticClass(), SpawnLocation);
    SpawnedActor->SetActorRelativeLocation(FVector(0.0, 0.0, 0.0));

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
    SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
    SpawnedPiece->SetActorRelativeLocation(FVector(0.0, 100.0, 0.0));
    SpawnedPiece->SpawnBlocks();*/

    for (TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
    {
        UE_LOG(LogTemp, Warning, TEXT("Find camera: %s"), *(it->GetFName().ToString()));
        if (it->GetFName() == TEXT("BoardCamera"))
        //if (it->GetFName() == TEXT("LeftCamera"))
        {
            APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
            PC->SetViewTargetWithBlend(*it, 0.5);
            break;
        }
    }

    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Presione 1.PrimerNivel, 2.SegundoNivel 3.TercerNivel")));
    GetWorldTimerManager().SetTimer(crearBoard, this, &ATetrisUSFX01GameModeBase::crearNuevoBoard, 5.f, true);
    // Call the parent class version of this function
    Super::BeginPlay();

    for (TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
    {
        UE_LOG(LogTemp, Warning, TEXT("Find camera: %s"), *(it->GetFName().ToString()));
        if (it->GetFName() == TEXT("BoardCamera"))
        {
            APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
            PC->SetViewTargetWithBlend(*it, 0.5);
            break;
        }
    }

}

void ATetrisUSFX01GameModeBase::crearNuevoBoard() {
    FString prueba = TEXT("prueba");
    TArray<AActor*> Instances;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoard::StaticClass(), Instances);//Obtenemos todos los catores de tipo board
    if (Instances.Num() >= 1) { // si ya hay almenos 1 (o mas boards) entonces no deja crear otro, pero caso contrario, SI crea un nuevo board.
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Board Ya existe, no se puede crear otro.")));
    }
    else {
        ABoard* boardNuevo = GetWorld()->SpawnActor<ABoard>(ABoard::StaticClass());
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Creando nuevo board.")));
    }
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%d Cantidad de boards: "), Instances.Num()));
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Presione 1.PrimerNivel, 2.SegundoNivel 3.TercerNivel")));
}




// Called every frame
void ATetrisUSFX01GameModeBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   /* FTransform SpawnLocation;

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
    SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
    SpawnedPiece->SetActorRelativeLocation(FVector(0.0, 100.0, 0.0));
    SpawnedPiece->SpawnBlocks();*/ 

}


void ATetrisUSFX01GameModeBase::DestroyActorFunction()
{
	//if (SpawnedActor != nullptr)
 //  {
 //     // Displays a red message on the screen for 10 seconds
 //     GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Block destruido"));
 //     SpawnedActor->Destroy();
 //  }
}


