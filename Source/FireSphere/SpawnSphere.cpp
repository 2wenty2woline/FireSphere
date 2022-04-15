// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnSphere.h"
#include "DrawDebugHelpers.h"

																				// Sets default values
ASpawnSphere::ASpawnSphere(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 																				// Set this actor to call Tick() every frame.  
																				// You can turn this off to improve performance if you don't need it.
	countSphere			= 15;
	countTide			= 0;
	MinSizeSphere		= 0.5f;
	StepReSizeSphere	= 0.05f;
	SizeSphere			= 1.f;
	ArraySpawnSphere.Reserve(countSphere);
}

																				// Called when the game starts or when spawned
void ASpawnSphere::BeginPlay()
{
	Super::BeginPlay();

	SpawnObject();
}

																				// Called every frame
void ASpawnSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawnSphere::SpawnObject()
{
	UWorld* const World = GetWorld();
	if (World)
	{
																				// increment +10%, when Tide is > 1
		if (countTide > 0)
		{
			for (int32 i = 0; i < countTide; i++)
			{
				countSphere += countSphere / 10;
			}
		}

		for (int32 i = 0; i < countSphere; i++)
		{
																				// Choose random number for spawn selection
			float RandX				= FMath::FRandRange(-2000, 2000);
			float RandY				= FMath::FRandRange(-2000, 2000);
			FVector LocationPlayer	= World->GetFirstPlayerController()->GetPawn()->GetActorLocation();

			ASphereScene* MyActor	= World->SpawnActor<ASphereScene>(ASphereScene::StaticClass(),
																	  FVector(RandX + LocationPlayer.X, RandY + LocationPlayer.Y, 500.0f),
																	  FRotator(0.0f, 0.0f, 0.0f));

																				// resize sphere
			MyActor->SphereComponent->SetWorldScale3D(FVector(SizeSphere));

																				// create collision sphere
			TArray<FHitResult> OutHits;
			FCollisionShape MyColSphere = FCollisionShape::MakeSphere(130.f);
			FVector Sweep = FVector(MyActor->GetActorLocation().X,
									MyActor->GetActorLocation().Y,
									MyActor->GetActorLocation().Z + 50 * SizeSphere);

																				// draw collision sphere
			//DrawDebugSphere(GetWorld(), FVector(Sweep), MyColSphere.GetSphereRadius(), 50, FColor::Purple, true, 999);

																				// check if something got hit in the sweep
			bool isHit = GetWorld()->SweepMultiByChannel(OutHits, Sweep, Sweep, FQuat::Identity, ECC_WorldStatic, MyColSphere);

			if (isHit)
			{
				for (auto& Hit : OutHits)
				{
					if (GEngine)
					{
						if (Hit.Actor != MyActor)
						{
							i--;
							MyActor->Destroy();
							continue;
						}
					}
				}
			}

			MyActor->OnDestroyed.AddDynamic(this, &ASpawnSphere::SphereDestroyed);

			ArraySpawnSphere.Emplace(MyActor);

																				// ReSize sphere
			if (SizeSphere >= MinSizeSphere)
			{
				SizeSphere -= StepReSizeSphere;
			}
		}
	}
}

void ASpawnSphere::SphereDestroyed(AActor* DestroyedActor)
{

	AnySphereDestroyed.Broadcast(DestroyedActor);

																				// Destroy sphere engine
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("DESTROY %s"), *DestroyedActor->GetName()));

	ASphereScene* MyDestroyedSphere = Cast<ASphereScene>(DestroyedActor);

																				// Destroy on TArray sphere
	int32 index = -1;
	ArraySpawnSphere.Find(MyDestroyedSphere, index);
	ArraySpawnSphere.RemoveAt(index);

																				// Decrement
	cSphereOnScrene += 1;
	countSphere		-= 1;

	if (countSphere <= 5)
	{
		countTide	+= 1;
		countSphere = 15;

		SpawnObject();
	}

}