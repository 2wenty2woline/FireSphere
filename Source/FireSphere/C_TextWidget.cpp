// Fill out your copyright notice in the Description page of Project Settings.


#include "C_TextWidget.h"
UC_TextWidget::UC_TextWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    ScreneSphereText = NewObject<UTextBlock>(this, "ScreneSphereText");

    countSphereText = NewObject<UTextBlock>(this, "countSphereText");

    ScreneSphereText->SetText(FText::FromString("Tide count"));
    countSphereText->SetText(FText::AsNumber(0));
}

void UC_TextWidget::SetScreneSphere(int32 & count)
{
    countSphereText->SetText(FText::AsNumber(count));
}