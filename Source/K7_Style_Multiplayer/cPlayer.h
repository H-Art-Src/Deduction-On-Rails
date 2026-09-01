// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "cRail_Path.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/PointLightComponent.h"
#include "cPlayer.generated.h"

UCLASS()
class K7_STYLE_MULTIPLAYER_API AcPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UCameraComponent> ground_ref;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<USpringArmComponent> camera_boom;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UCapsuleComponent> boom_capsule;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UPointLightComponent> flash_photography_light;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<USceneCaptureComponent2D> avatar_capture;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UStaticMeshComponent> sweet_spot_particle;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UStaticMeshComponent> first_person_mesh;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UArrowComponent> Arrow1;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UBillboardComponent> billboard;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<USkeletalMeshComponent> first_person_skeletal_mesh;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UCameraComponent> first_person_camera;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UCameraComponent> follow_camera;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings")
	double BaseTurnRate;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings")
	double BaseLookUpRate;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, current_rail_path) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	TObjectPtr<AcRail_Path> current_rail_path;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(MultiLine="true"))
	double current_path_distance;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, forwards) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool forwards;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double speed;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, first_person_mode_pressed) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated)
	bool first_person_mode_pressed;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, first_person_mode) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool first_person_mode;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, attack_and_confirm) to GetLifetimeReplicatedProps");
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fattack_and_confirm);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default", Replicated, meta=(MultiLine="true"))
	Fattack_and_confirm attack_and_confirm;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, aim_rotation) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	FRotator aim_rotation;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, hit_points) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes (replicated)", Replicated, meta=(MultiLine="true", ClampMin="0", ClampMax="51", UIMin="0", UIMax="51"))
	int32 hit_points;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, sweet_spot) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	FName sweet_spot;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, dead) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool dead;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes")
	int32 max_ammo;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	int32 start_hitpoints;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, firing) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool firing;

	/** Stops movement, NOT to be used in child classes. For rail path changes */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, movement_lock) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool movement_lock;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, current_move_axis) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true", ClampMin="-1", ClampMax="1"))
	double current_move_axis;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings", meta=(MultiLine="true"))
	bool use_first_person_mesh_instead;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, server_look_axis) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	FVector2D server_look_axis;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Components", meta=(MultiLine="true"))
	TObjectPtr<UParticleSystemComponent> sweet_particle;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Server only", meta=(MultiLine="true"))
	TArray<FName> valid_sweet_spots;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	int32 blood_count;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, timestamp) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	double timestamp;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double gun_delay;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double cooldown_aim;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double special_delay;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	TObjectPtr<UClass> projectile;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	TObjectPtr<UClass> special;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fdied);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default", meta=(MultiLine="true"))
	Fdied died;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Components", meta=(MultiLine="true"))
	TObjectPtr<UParticleSystem> sweet_spot_effect;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	TObjectPtr<UClass> rail_spawn_class;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Frespawned);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default", meta=(MultiLine="true"))
	Frespawned respawned;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Sounds", meta=(MultiLine="true"))
	TObjectPtr<USoundBase> critical_one_liner;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Sounds", meta=(MultiLine="true"))
	TObjectPtr<USoundBase> damage_sound;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Sounds", meta=(MultiLine="true"))
	TObjectPtr<USoundBase> death_sound;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Sounds", meta=(MultiLine="true"))
	TObjectPtr<USoundBase> ready_weapon_sound;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Sounds", meta=(MultiLine="true"))
	TObjectPtr<USoundBase> respawn_sound;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes", meta=(MultiLine="true"))
	double sweet_spot_radius;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, loaded_ammo) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes (replicated)", Replicated)
	int32 loaded_ammo;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, team_int) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes (replicated)", Replicated)
	int32 team_int;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double respawn_time;

	/** Please add a variable description */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, stunned) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool stunned;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	bool third_person_camera_forwards;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	TObjectPtr<UMaterialInstanceDynamic> Photo;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fwent_first_person);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	Fwent_first_person went_first_person;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fdamaged);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	Fdamaged damaged;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fserver_interact_dispatch);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	Fserver_interact_dispatch server_interact_dispatch;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes")
	float ammo_recharge_rate;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FRotator boom_capsule_rotation;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FTransform start_3p_transform;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FTransform start_3p_transform_ground;

	// Sets default values for this character's properties
	AcPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
