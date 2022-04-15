// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "C_TextWidget.generated.h"

/**
 * 
 */
UCLASS()
class FIRESPHERE_API UC_TextWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* ScreneSphereText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* countSphereText;

	UC_TextWidget(const FObjectInitializer& ObjectInitializer);

	void SetScreneSphere(int32 & count);
};
