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
	/** Displays path_name for devs. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UTextRenderComponent> TextRender;

	/** Spline to walk across. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<USplineComponent> cSpline;

	/** In-game name. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	FName path_name;

	/** Radius from center for junctions to connect. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	double radius = 50.0;

	/** Shows junction selectors when exiting first person. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	bool Bind_to_exit_first_person;

	/** Can't return to where you came from. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	bool one_way;

	/** Marks itself as already exists to prevent duplicate path selectors. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default", meta=(MultiLine="true"))
	bool already_exists;

	/** Sets camera mode. Will be overidden if custom_camera is set. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Camera Settings")
	enum_camera_follow_mode camera_follow_mode = enum_camera_follow_mode.shoulder;

	/** Reference to camera that the player will see when on this junction. */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Camera Settings")
	TObjectPtr<ACameraActor> custom_camera;

	/** Sets camera_follow_mode if custom_camera is set. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Camera Settings")
	bool custom_camera_focus_on_player;

	/** Auto-detected conected conjunctions. */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Connections", meta=(MultiLine="true"))
	TArray<AcRail_Path*> connected_paths;

	/** Child path actor that overlaps its capsule with this. */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Connections", meta=(MultiLine="true"))
	TObjectPtr<AcRail_Path> child_path;

	/** Set to force launch the construction script. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Connections", meta=(MultiLine="true"))
	bool rebuild_paths = false;

	AcRail_Path();
};
