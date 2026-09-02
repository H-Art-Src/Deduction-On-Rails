// Fill out your copyright notice in the Description page of Project Settings.

#include "Net/UnrealNetwork.h"
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

// Called every frame
void AcPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
