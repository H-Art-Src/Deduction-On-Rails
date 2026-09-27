// Fill out your copyright notice in the Description page of Project Settings.


#include "cRail_Path.h"

AcRail_Path::AcRail_Path()
{
    cSpline = CreateDefaultSubobject<USplineComponent>(TEXT("C Spline"));
    cSpline->SetupAttachment(RootComponent);
    TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Render"));
    TextRender->SetupAttachment(RootComponent);
}
