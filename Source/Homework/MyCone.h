// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "Components/StaticMeshComponent.h"
#include "InteractionInterface.h"
#include "MyCone.generated.h"



UCLASS(BlueprintType, Category=Interact)
class AMyCone : public ABaseActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCone();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;


protected:
	// Called when the game starts or when spawned

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(FHitResult Hit, APawn* MyInstigator) override;

};
