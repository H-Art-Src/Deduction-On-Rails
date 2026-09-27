// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "cRail_Path.h"
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/PointLightComponent.h"
#include "cPlayer.generated.h"

UENUM(BlueprintType)
enum class cEnum_team : uint8
{
	cop        UMETA(DisplayName = "Cop"),
	robber     UMETA(DisplayName = "Robber"),
	civilian     UMETA(DisplayName = "Civilian"),
	spectator     UMETA(DisplayName = "Spectator")
};

class USpringArmComponent;
class UCapsuleComponent;
class UCameraComponent;

UCLASS()
class K7_STYLE_MULTIPLAYER_API AcPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// ==================== Components ====================
	// ==================== Unused in CPP.
	// /** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<UCameraComponent> Cground_ref;
 //
	// /** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<UPointLightComponent> Cflash_photography_light;
 //
	// /** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<USceneCaptureComponent2D> Cavatar_capture;
 //
	// /** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<UStaticMeshComponent> Csweet_spot_particle;
 //
	// /** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<UStaticMeshComponent> Cfirst_person_mesh;
 //
	// /** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<UArrowComponent> CArrow1;
 //
	// /** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<UBillboardComponent> Cbillboard;

	/** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<USkeletalMeshComponent> Cfirst_person_skeletal_mesh;

	/** Please add a variable description */
	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	// TObjectPtr<UCameraComponent> first_person_camera;

	// ==================== Used in CPP tick.
	/** Camera boom. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<USpringArmComponent> camera_boom;

	/** Boom capsule.*/
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UCapsuleComponent> boom_capsule;

	/** 3P camera. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	TObjectPtr<UCameraComponent> follow_camera;

	// ==================== Used in CPP other.
	/** Critical hit particle effect. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Components", meta=(MultiLine="true"))
	TObjectPtr<UParticleSystemComponent> sweet_particle;

	// ==================== Default ====================
	/** Position on spline. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	double current_path_distance;

	/** 3P camera is set forwards. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	bool third_person_camera_forwards;

	/** Player photograph. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	TObjectPtr<UMaterialInstanceDynamic> Photo;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FTransform start_3p_transform;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FTransform start_3p_transform_ground;

	// ==================== Settings ====================
	/** Turn rate controller */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings")
	double BaseTurnRate;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings")
	double BaseLookUpRate;

	/** Use mesh and hide the 3P model when aiming. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings", meta=(MultiLine="true"))
	bool use_first_person_mesh_instead;

	// ==================== Networked Status ====================
	/** Current junction. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, current_rail_path) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	TObjectPtr<AcRail_Path> current_rail_path;

	/** Is moving forwards on the track. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, forwards) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool forwards;

	/** Player pressed first person/battle mode. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, first_person_mode_pressed) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated)
	bool first_person_mode_pressed;

	/** Is in first person/battle mode. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, first_person_mode) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool first_person_mode;

	/** Aim rotation. Does not rotate the model beyond Z axis. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, aim_rotation) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	FRotator aim_rotation;

	/** Sweet spot bone name. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, sweet_spot) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	FName sweet_spot;

	/** Is dead. No controlling or status effects. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, dead) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool dead;

	/** Is firing a weapon for special. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, firing) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool firing;

	/** Stops movement, NOT to be used in child classes. For rail path changes */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, movement_lock) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool movement_lock;

	/** Player's control input replicated to all players. Walk mode.*/
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, current_move_axis) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true", ClampMin="-1", ClampMax="1"))
	double current_move_axis;

	/** Player's control input replicated to all players. Battle mode.*/
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, server_look_axis) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	FVector2D server_look_axis;

	/** Prevents rubber banding. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, timestamp) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	double timestamp;

	/** Flashbangs. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, stunned) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Networked Status", Replicated, meta=(MultiLine="true"))
	bool stunned;

	// ==================== Attributes ====================
	/** Walk speed for junctions. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double speed = 600.0;

	/** Max ammo. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes")
	int32 max_ammo = 4;

	/** Health. Not using float. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	int32 start_hitpoints = 7;

	/** Delay until fire. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double gun_delay = 0.4;

	/** Cooldown until you can fire again. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double cooldown_aim = 0.4;

	/** Special move cooldown. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double special_delay = 1.0;

	/** This class is spawned when doing a normal attack. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	TObjectPtr<UClass> projectile;

	/** This class is spawned when doing a special move. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	TObjectPtr<UClass> special;

	/** Size of sweet spot */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes", meta=(MultiLine="true"))
	double sweet_spot_radius;

	/** Score/money. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	int32 blood_count = 0;

	/** Respawn time. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	double respawn_time = 3.0;

	/** For recharging weapons. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes")
	float ammo_recharge_rate = 2.0;

	/** Which type of class should this player respawn at. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Attributes", meta=(MultiLine="true"))
	TObjectPtr<UClass> rail_spawn_class;

	// ==================== Attributes (Replicated) ====================
	/** Health point. We're not using float or character stats. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, hit_points) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes (replicated)", Replicated, meta=(MultiLine="true", ClampMin="0", ClampMax="51", UIMin="0", UIMax="51"))
	int32 hit_points = 7;

	/** Weapon's current ammo. Was not made initially for multiple weapons per player.*/
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, loaded_ammo) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes (replicated)", Replicated)
	int32 loaded_ammo = 4;

	/** Player's team. Not apparent to all in deduction. */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, team) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes (replicated)", Replicated)
	cEnum_team team;

	// ==================== Delegates ====================
	/** Player attacks or confirms option. (Default mouse click) */
	static_assert(true, "You will need to add DOREPLIFETIME(AcPlayer, attack_and_confirm) to GetLifetimeReplicatedProps");
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fattack_and_confirm);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, EditDefaultsOnly, Category="Default", Replicated, meta=(MultiLine="true"))
	Fattack_and_confirm attack_and_confirm;

	/** Player died. */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fdied);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, EditDefaultsOnly, Category="Default", meta=(MultiLine="true"))
	Fdied died;

	/** Player respawned. */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Frespawned);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, EditDefaultsOnly, Category="Default", meta=(MultiLine="true"))
	Frespawned respawned;

	/** Switched to first person mode. */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fwent_first_person);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, EditDefaultsOnly, Category="Default")
	Fwent_first_person went_first_person;

	/** Hurt in some way. */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fdamaged);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, EditDefaultsOnly, Category="Default")
	Fdamaged damaged;

	/** Interacts with object.. */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fserver_interact_dispatch);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, EditDefaultsOnly, Category="Default")
	Fserver_interact_dispatch server_interact_dispatch;

	// ==================== Sounds ====================
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

	// ==================== Server Only ====================
	/** Array of good sweetspots that can critical hit the player. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Server only", meta=(MultiLine="true"))
	TArray<FName> valid_sweet_spots;

	// ==================== Effects ====================
	/** Sweet spot particle effect. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Components", meta=(MultiLine="true"))
	TObjectPtr<UParticleSystem> sweet_spot_effect;

	// ==================== Methods ====================
	// Sets default values for this character's properties
	AcPlayer();

	/** Please add a function description */
	UFUNCTION(BlueprintPure)
	double distance_after_velocity(double axis, double delta);

	UFUNCTION(BlueprintCallable)
	void UpdateMovement();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	//enum_camera_follow_mode "custom camera" enums.
	void UpdateCustomCamera(FVector NewVector, FRotator NewRotation);

	//All other camera modes.
	void UpdateDefaultCamera(FTransform NewTransform, float BlendA);

	// Default NoTurns.
	void UpdateDefaultNoTurn(float PrevYaw, float Yaw);
};
