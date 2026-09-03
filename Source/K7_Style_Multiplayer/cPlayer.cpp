// Fill out your copyright notice in the Description page of Project Settings.

#include "Net/UnrealNetwork.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "cRail_Path.h"
#include "cPlayer.h"

// Sets default values
AcPlayer::AcPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

//enum_camera_follow_mode "custom camera" enums.
void AcPlayer::UpdateCustomCamera(FVector NewVector, FRotator NewRotation)
{
	Cfollow_camera->SetWorldRotation(NewRotation);
	Cfollow_camera->SetWorldLocation(NewVector);
	Ccamera_boom->SetActive(false, false);
}

//All other camera modes.
void AcPlayer::UpdateDefaultCamera(FTransform NewTransform, float BlendA)
{
	NewTransform.Blend(NewTransform , Cfollow_camera->GetRelativeTransform() , BlendA);
	Cfollow_camera->SetRelativeTransform(NewTransform);
	Ccamera_boom->SetActive(true, true);
}


// Called every frame
void AcPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto splinePTR = current_rail_path->cSpline;

	//Movement
	FVector SplineLocation = splinePTR->GetLocationAtDistanceAlongSpline(current_path_distance, ESplineCoordinateSpace::World);
	FHitResult GroundHit;
	GetWorld()->LineTraceSingleByChannel(GroundHit, SplineLocation, FVector(SplineLocation.X, SplineLocation.Z, MIN_flt), ECC_Visibility);
	SetActorLocation(FVector(SplineLocation.X, SplineLocation.Y, GroundHit.Location.Z - GetMesh()->GetComponentLocation().Z));

	//Not dead
	if(!dead)
	{
		if(first_person_mode)
		{
			if(first_person_mode_pressed && !use_first_person_mesh_instead && IsLocallyControlled())
				SetActorRotation(aim_rotation);
			else
				SetActorRotation(FRotator(0.0,0.0,aim_rotation.Yaw));
		}
		else
		{
			boom_capsule_rotation = Cboom_capsule->GetComponentRotation();
			float SplineLookAtYaw = UKismetMathLibrary::FindLookAtRotation(
				GetActorLocation(),
				splinePTR->GetLocationAtDistanceAlongSpline(current_path_distance + (forwards ? 100.0 : -100.0), ESplineCoordinateSpace::World)
			).Yaw;
			SetActorRotation(FRotator(0.0,0.0, FMath::Lerp(GetActorRotation().Yaw , SplineLookAtYaw, 0.1)));

			FVector NewVector;
			switch(current_rail_path->camera_follow_mode)
			{
				//TODO all of these camera modifiers
				case enum_camera_follow_mode::custom_camera:
					UpdateCustomCamera(current_rail_path->custom_camera->GetActorLocation(), current_rail_path->custom_camera->GetActorRotation());
					break;
				case enum_camera_follow_mode::custom_camera_focus_on_player:
					NewVector = current_rail_path->custom_camera->GetActorLocation();
					UpdateCustomCamera(NewVector, UKismetMathLibrary::FindLookAtRotation(NewVector,GetActorLocation()));
					break;
				case enum_camera_follow_mode::shoulder:
					UpdateDefaultCamera(start_3p_transform, 0.1);
					break;
				case enum_camera_follow_mode::ground:
					UpdateDefaultCamera(start_3p_transform_ground, 0.1);
					break;
				case enum_camera_follow_mode::shoulder_noturn:
					break;
				case enum_camera_follow_mode::ground_noturn:
					break;
			}
		}
	}

	//Timestamp
	current_path_distance = distance_after_velocity(current_move_axis, DeltaTime);
	if(HasAuthority())
		timestamp += DeltaTime;
}

double AcPlayer::distance_after_velocity(double axis, double delta)
{
	if(first_person_mode || first_person_mode_pressed || movement_lock || dead)
		return current_path_distance;
	double ret = speed * axis * delta;
	if(forwards)
		ret = current_path_distance + ret;
	else
		ret = current_path_distance - ret;
	return FMath::Clamp(ret , 15.0 , current_rail_path->cSpline->GetSplineLength());
}

// Called to bind functionality to input
void AcPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AcPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AcPlayer, current_rail_path);
	DOREPLIFETIME(AcPlayer, forwards);
	DOREPLIFETIME(AcPlayer, first_person_mode_pressed);
	DOREPLIFETIME(AcPlayer, first_person_mode);
	DOREPLIFETIME(AcPlayer, attack_and_confirm);
	DOREPLIFETIME(AcPlayer, aim_rotation);
	DOREPLIFETIME(AcPlayer, hit_points);
	DOREPLIFETIME(AcPlayer, sweet_spot);
	DOREPLIFETIME(AcPlayer, dead);
	DOREPLIFETIME(AcPlayer, firing);
	DOREPLIFETIME(AcPlayer, movement_lock);
	DOREPLIFETIME(AcPlayer, current_move_axis);
	DOREPLIFETIME(AcPlayer, server_look_axis);
	DOREPLIFETIME(AcPlayer, timestamp);
	DOREPLIFETIME(AcPlayer, loaded_ammo);
	DOREPLIFETIME(AcPlayer, team);
	DOREPLIFETIME(AcPlayer, stunned);

}
