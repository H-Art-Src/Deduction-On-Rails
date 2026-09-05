// Fill out your copyright notice in the Description page of Project Settings.


#include "cRail_Path.h"

AcRail_Path::AcRail_Path()
{
    TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Render"));
    TextRender->SetupAttachment(RootComponent);
}
