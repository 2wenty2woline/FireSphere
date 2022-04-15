// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereScene.h"
#include "SpawnSphere.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnySphereDestroyed, AActor*, Sphere);

UCLASS()
class FIRESPHERE_API ASpawnSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnSphere(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TArray<ASphereScene*> ArraySpawnSphere;
	
	UPROPERTY(BlueprintAssignable)
	FAnySphereDestroyed AnySphereDestroyed;
	
	UFUNCTION(BlueprintCallable)
	void SpawnObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 countSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 cSphereOnScrene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 countTide;

	UFUNCTION()
	void SphereDestroyed(AActor* DestroyedActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinSizeSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StepReSizeSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SizeSphere;

};
