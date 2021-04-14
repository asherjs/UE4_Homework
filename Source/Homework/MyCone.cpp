// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCone.h"

// Sets default values
AMyCone::AMyCone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

}

// Called when the game starts or when spawned
void AMyCone::BeginPlay()
{
	Super::BeginPlay();

	AddActorLocalRotation(FRotator(0.f, 0.f, 100.f), false, 0, ETeleportType::None);

	FVector Color(0.f, 5.f, 0.f);

	StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), Color);
}

// Called every frame
void AMyCone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	StaticMeshComponent->AddRelativeRotation(FRotator(0.f, 1.f, 0.f));
}

void AMyCone::Interact_Implementation(FHitResult Hit, APawn* MyInstigator)
{
	FVector NewColor(FMath::FRandRange(0.0, 1.0), FMath::FRandRange(0.0, 1.0), FMath::FRandRange(0.0, 1.0));
	StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), NewColor);
	
	UE_LOG(LogTemp, Error, TEXT("Interacting"));
}




