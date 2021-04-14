// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "InteractionActor.generated.h"

UENUM()
enum class EColor : uint8
{
	Red,
	Green,
	Blue
};


//ENUM_CLASS_FLAGS(EColor)

UCLASS()
class HOMEWORK_API AInteractionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractionActor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	uint8 CurrentColor;

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
