// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerCapsule.h"
#include "Components/TextRenderComponent.h"
#include "Components/SplineComponent.h"
#include "cRail_Path.generated.h"

UENUM(BlueprintType)
enum class enum_camera_follow_mode : uint8
{
	custom_camera        UMETA(DisplayName = "Custom Camera"),
	shoulder     UMETA(DisplayName = "Shoulder"),
	ground     UMETA(DisplayName = "Ground"),
	shoulder_noturn     UMETA(DisplayName = "Shoulder Noturn"),
	ground_noturn     UMETA(DisplayName = "Ground Noturn"),
	custom_camera_focus_on_player	UMETA(DisplayName = "Custom Camera Focus On Player")
};

/**
 * 
 */
UCLASS()
class K7_STYLE_MULTIPLAYER_API AcRail_Path : public ATriggerCapsule
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UTextRenderComponent> TextRender;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Components")
	TObjectPtr<USplineComponent> cSpline;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	FName path_name;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	double radius = 50.0;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	bool Bind_to_exit_first_person;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default", meta=(MultiLine="true"))
	bool already_exists;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	bool one_way;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Camera Settings")
	enum_camera_follow_mode camera_follow_mode;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Camera Settings")
	TObjectPtr<ACameraActor> custom_camera;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Camera Settings")
	bool custom_camera_focus_on_player;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Connections", meta=(MultiLine="true"))
	TArray<AcRail_Path*> connected_paths;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Connections", meta=(MultiLine="true"))
	TObjectPtr<AcRail_Path> child_path;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Connections", meta=(MultiLine="true"))
	bool rebuild_paths = false;

	AcRail_Path();
};
