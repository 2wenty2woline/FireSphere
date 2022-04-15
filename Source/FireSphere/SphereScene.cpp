// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereScene.h"

// Sets default values
ASphereScene::ASphereScene()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	RootComponent = SphereComponent;

	SphereComponent->OnComponentHit.AddDynamic(this, &ASphereScene::OnCompHit);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphererAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphererAsset.Succeeded())
	{
		SphereComponent->SetStaticMesh(SphererAsset.Object);
		SphereComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		SphereComponent->SetWorldScale3D(FVector(1.f));
	}
}

// Called when the game starts or when spawned
void ASphereScene::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASphereScene::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASphereScene::DrawCollision()
{
	
}

void ASphereScene::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if (GEngine)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("NameActor: %s"), *OtherActor->GetName()));
		}

		this->Destroy();

	}
}

