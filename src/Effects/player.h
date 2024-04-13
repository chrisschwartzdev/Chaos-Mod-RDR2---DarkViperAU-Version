#pragma once

#include "effect.h"
#include <set>

void TeleportPlayerTo(float X, float Y, float Z);

void DisableAllMovements();

class EffectLaunchPlayerUp : public Effect
{
public:
	EffectLaunchPlayerUp()
	{
		ID = "launch_player_up";
		name = "Launch Player Up";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectToTheStars : public Effect
{
public:
	EffectToTheStars()
	{
		ID = "to_the_stars";
		name = "To The Stars";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectGivePlayerMoney : public Effect
{
public:
	EffectGivePlayerMoney()
	{
		ID = "give_player_money";
		name = "Give $300 to Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectBankruptcy : public Effect
{
public:
	EffectBankruptcy()
	{
		ID = "bankruptcy";
		name = "Bankruptcy";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectGiveRifle : public Effect
{
public:
	EffectGiveRifle()
	{
		ID = "give_rifle";
		name = "Give a Rifle to Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectGiveRevolver : public Effect
{
public:
	EffectGiveRevolver()
	{
		ID = "give_revolver";
		name = "Give a Revolver To Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectNoAmmo : public Effect
{
public:
	EffectNoAmmo()
	{
		ID = "no_ammo";
		name = "No ammo";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectRemoveAllWeapons : public Effect
{
public:
	EffectRemoveAllWeapons()
	{
		ID = "remove_all_weapons";
		name = "Remove All Player Weapons";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectHonorGood : public Effect
{
public:
	EffectHonorGood()
	{
		ID = "honor_good";
		name = "Set Good Honor";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectHonorBad : public Effect
{
public:
	EffectHonorBad()
	{
		ID = "honor_bad";
		name = "Set Bad Honor";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectHonorReset : public Effect
{
public:
	EffectHonorReset()
	{
		ID = "honor_reset";
		name = "Reset Player's Honor";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectDropWeapon : public Effect
{
public:
	EffectDropWeapon()
	{
		ID = "drop_weapon";
		name = "Drop current weapon";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectHealPlayer : public Effect
{
public:
	EffectHealPlayer()
	{
		ID = "heal_player";
		name = "Heal Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectAlmostDead : public Effect
{
public:
	EffectAlmostDead()
	{
		ID = "almost_dead";
		name = "Almost Dead";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectRestoreStamina : public Effect
{
public:
	EffectRestoreStamina()
	{
		ID = "restore_stamina";
		name = "Restore Player Stamina";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectRagdoll : public Effect
{
public:
	EffectRagdoll()
	{
		ID = "ragdoll";
		name = "Ragdoll";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectGiveRandomWeapon : public Effect
{
public:
	EffectGiveRandomWeapon()
	{
		ID = "give_random_weapon";
		name = "Give Random Weapon";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSetDrunk : public Effect
{
public:
	EffectSetDrunk()
	{
		ID = "set_drunk";
		name = "Player is Drunk";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
	
	virtual void OnTick() override;
};

class EffectClearPursuit : public Effect
{
public:
	EffectClearPursuit()
	{
		ID = "clear_pursuit";
		name = "Stop Pursuit";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectIncreaseBounty : public Effect
{
public:
	EffectIncreaseBounty()
	{
		ID = "increase_bounty";
		name = "Increase Bounty for Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectRemoveCurrentVehicle : public Effect
{
public:
	EffectRemoveCurrentVehicle()
	{
		ID = "remove_current_vehicle";
		name = "Remove Current Vehicle";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectGiveLasso : public Effect
{
public:
	EffectGiveLasso()
	{
		ID = "give_lasso";
		name = "Give Lasso to Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectIgnitePlayer : public Effect
{
public:
	EffectIgnitePlayer()
	{
		ID = "ignite_player";
		name = "Ignite Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectKickflip : public Effect
{
public:
	EffectKickflip()
	{
		ID = "kickflip";
		name = "Kickflip";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectLightningWeapons : public Effect
{
public:
	EffectLightningWeapons()
	{
		ID = "lightning_weapons";
		name = "Lightning Weapons";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
	
	virtual void OnTick() override;

private:
	Vector3 lastVec;
};

class IEffectSkinChange : public Effect
{
public:
	IEffectSkinChange()
	{
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
	
	std::vector<const char*> skinToSet = { "A_C_COW" };
private:
	uint64_t oldSkin1{};
	uint64_t oldSkin2{};
};


class EffectCowSkin : public IEffectSkinChange
{
public:
	EffectCowSkin()
	{
		ID = "cow_skin";
		name = "Player Is a Cow";
		skinToSet = { "A_C_COW", "A_C_Bull_01" };
	}
};

class EffectDwarfSkin : public IEffectSkinChange
{
public:
	EffectDwarfSkin()
	{
		ID = "dwarf_skin";
		name = "Player Is a Dwarf";
		skinToSet = { "CS_Magnifico" };
	}
};

class EffectPigSkin : public IEffectSkinChange
{
public:
	EffectPigSkin()
	{
		ID = "pig_skin";
		name = "Player Is a Pig";
		skinToSet = { "A_C_Pig_01", "A_C_Boar_01", "A_C_BoarLegendary_01" };
	}
	
	virtual void OnActivate() override;
};

class EffectRatSkin : public IEffectSkinChange
{
public:
	EffectRatSkin()
	{
		ID = "rat_skin";
		name = "Player Is a Rat";
		skinToSet = { "A_C_Rat_01" };
	}
};

class EffectTurtleSkin : public IEffectSkinChange
{
public:
	EffectTurtleSkin()
	{
		ID = "turtle_skin";
		name = "Player Is a Turtle";
		skinToSet = { "A_C_TurtleSnapping_01", "A_C_TurtleSea_01" };
		EffectDuration = 40;
	}
};

class EffectPlayerSleep : public IEffectSkinChange
{
public:
	EffectPlayerSleep()
	{
		ID = "player_sleep";
		name = "I Need Some Sleep";
		bTimed = true;
		EffectDuration = 15;
	}
	
	virtual void OnActivate() override;
};

class EffectPlayerIsMinion : public IEffectSkinChange
{
public:
	EffectPlayerIsMinion()
	{
		ID = "player_minion";
		name = "Player Is Minion";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
	
	virtual void OnDeactivate() override;
};


class EffectTeleportToWaypoint : public IEffectSkinChange
{
public:
	EffectTeleportToWaypoint()
	{
		ID = "tp_to_waypoint";
		name = "Teleport To Waypoint";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

void SetPlayerModel(const char* model, uint64_t* ptr1_val, uint64_t* ptr2_val);

void ResetPlayerModel(uint64_t ptr1_val, uint64_t ptr2_val);

class EffectExplosiveWeapons : public Effect
{
public:
	EffectExplosiveWeapons()
	{
		ID = "explosive_weapons";
		name = "Explosive Weapons";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
	
	virtual void OnTick() override;

private:
	Vector3 lastVec;
};

class EffectTeleportWeapons : public Effect
{
public:
	EffectTeleportWeapons()
	{
		ID = "teleport_weapons";
		name = "Teleportation Weapons";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
	
	virtual void OnTick() override;

private:
	Vector3 lastVec;
};


class EffectBloodTrails : public Effect
{
public:
	EffectBloodTrails()
	{
		ID = "blood_trails";
		name = "Blood Trails";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnTick() override;
};


class EffectSetRandomWalkStyle : public Effect
{
public:
	EffectSetRandomWalkStyle()
	{
		ID = "random_walk_style";
		name = "Set Random Walk Style";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
};

class EffectGiveSniperRifle : public Effect
{
public:
	EffectGiveSniperRifle()
	{
		ID = "give_sniper_rifle";
		name = "Give a Sniper Rifle To Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectGiveDynamite : public Effect
{
public:
	EffectGiveDynamite()
	{
		ID = "give_dynamite";
		name = "Give a Dynamite To Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectThrowingKnives : public Effect
{
public:
	EffectThrowingKnives()
	{
		ID = "give_knives";
		name = "Give Throwing Knives To Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectTeleportFewMeters : public Effect
{
public:
	EffectTeleportFewMeters()
	{
		ID = "tp_few_meters";
		name = "Teleport Player a Few Meters";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectBlackingOut : public Effect
{
public:
	EffectBlackingOut()
	{
		ID = "blacking_out";
		name = "Blacking Out";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectRandomClothes : public Effect
{
public:
	EffectRandomClothes()
	{
		ID = "random_clothes";
		name = "Set Random Clothes";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectMostWanted : public Effect
{
public:
	EffectMostWanted()
	{
		ID = "most_wanted";
		name = "Most Wanted";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSetWinterOutfit : public Effect
{
public:
	EffectSetWinterOutfit()
	{
		ID = "winter_outfit";
		name = "Set Winter Outfit";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSuperJump : public Effect
{
public:
	EffectSuperJump()
	{
		ID = "super_jump";
		name = "Super Jump";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnTick() override;
};

class EffectDisableLeftRight : public Effect
{
public:
	EffectDisableLeftRight()
	{
		ID = "disable_left_right";
		name = "Disable Left & Right Movements";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnTick() override;
};

class EffectDisableForwardBackward : public Effect
{
public:
	EffectDisableForwardBackward()
	{
		ID = "disable_forward_backward";
		name = "Disable Forward & Backward Movements";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnTick() override;
};

class EffectDisableSprintJump : public Effect
{
public:
	EffectDisableSprintJump()
	{
		ID = "disable_sprint_jump";
		name = "Disable Sprint & Jump";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnTick() override;
};

class EffectDisableAllMovements : public Effect
{
public:
	EffectDisableAllMovements()
	{
		ID = "disable_movements";
		name = "Disable All Movements";
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnTick() override;
};


class EffectDisableAttackButton : public Effect
{
public:
	EffectDisableAttackButton()
	{
		ID = "disable_attack";
		name = "Disable Attack Button";
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnTick() override;
};

class EffectDisableAiming : public Effect
{
public:
	EffectDisableAiming()
	{
		ID = "disable_aiming";
		name = "Disable Aiming";
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
	
	virtual void OnTick() override;
};

class EffectRandomHonor : public Effect
{
public:
	EffectRandomHonor()
	{
		ID = "random_honor";
		name = "Random Honor Change";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectInvertVelocity : public Effect
{
public:
	EffectInvertVelocity()
	{
		ID = "invert_velocity";
		name = "Invert And Increase Current Velocity";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectIncreaseVelocity : public Effect
{
public:
	EffectIncreaseVelocity()
	{
		ID = "increase_velocity";
		name = "Increase Current Velocity";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectBunnyhop : public Effect
{
public:
	EffectBunnyhop()
	{
		ID = "bunnyhop";
		name = "Bunny Hop";
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnTick() override;
};


class EffectEyeDisorder : public Effect
{
public:
	EffectEyeDisorder()
	{
		ID = "eye_disorder";
		name = "Eye Disorder";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
};

class EffectBirdSkin : public IEffectSkinChange
{
public:
	EffectBirdSkin()
	{
		ID = "bird_skin";
		name = "Player Is a Bird";
		skinToSet = {
			"A_C_BlueJay_01",
			"A_C_CaliforniaCondor_01",
			"A_C_Cardinal_01",
			"A_C_CarolinaParakeet_01",
			"A_C_CedarWaxwing_01",
			"A_C_Chicken_01",
			"A_C_Cormorant_01",
			"A_C_CraneWhooping_01",
			"A_C_Crow_01",
			"A_C_Duck_01",
			"A_C_EAGLE_01",
			"A_C_Eagle_01",
			"A_C_Egret_01",
			"A_C_GooseCanada_01",
			"A_C_Hawk_01",
			"A_C_Heron_01",
			"A_C_Loon_01",
			"A_C_Oriole_01",
			"A_C_Owl_01",
			"A_C_Parrot_01",
			"A_C_Pelican_01",
			"A_C_Pheasant_01",
			"A_C_Pigeon",
			"A_C_PrairieChicken_01",
			"A_C_Quail_01",
			"A_C_Raven_01",
			"A_C_RedFootedBooby_01",
			"A_C_Robin_01",
			"A_C_Rooster_01",
			"A_C_RoseateSpoonbill_01",
			"A_C_Seagull_01",
			"A_C_Turkey_01",
			"A_C_Turkey_02",
			"A_C_TurkeyWild_01",
			"A_C_Vulture_01",
			"A_C_Woodpecker_01",
			"A_C_Woodpecker_02"
		};
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
};

class EffectBodySwap : public Effect
{
public:
	EffectBodySwap()
	{
		ID = "body_swap";
		name = "Body Swap";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;

private:
	Ped clone = 0;
	Hash pedSkin = 0;
};

class EffectPlayerSpin : public Effect
{
public:
	EffectPlayerSpin()
	{
		ID = "player_spin";
		name = "Spin";
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;

private:
	float heading = 0.0f;
};

class EffectPlayerLosesWeight : public Effect
{
public:
	EffectPlayerLosesWeight()
	{
		ID = "lose_weight";
		name = "Player Loses Weight";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectPlayerGainsWeight : public Effect
{
public:
	EffectPlayerGainsWeight()
	{
		ID = "gain_weight";
		name = "Player Gains Weight";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectSetRandomHat : public Effect
{
public:
	EffectSetRandomHat()
	{
		ID = "random_hat";
		name = "Set Random Hat";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectGravityGun : public Effect
{
public:
	EffectGravityGun()
	{
		ID = "gravity_gun";
		name = "Gravity Gun";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
	
	virtual void OnTick() override;

private:
	Vector3 lastVec;
};

class EffectDisableDeadEye : public Effect
{
public:
	EffectDisableDeadEye()
	{
		ID = "disable_dead_eye";
		name = "Disable Dead Eye";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;
};

class EffectSetRandomVelocity : public Effect
{
public:
	EffectSetRandomVelocity()
	{
		ID = "random_velocity";
		name = "Set Random Velocity";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectFirstPerson : public Effect
{
public:
	EffectFirstPerson()
	{
		ID = "first_person";
		name = "First Person";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnTick() override;
};


class EffectTopDownCamera : public Effect
{
public:
	EffectTopDownCamera()
	{
		ID = "top_down_camera";
		name = "Top Down Camera";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
	
	virtual void OnDeactivate() override;

private:
	Camera cam;
};

class EffectAgitateHorse : public Effect
{
public:
	EffectAgitateHorse()
	{
		ID = "agitate_horse";
		name = "Agitate Player's Horse";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectTpRandomLocation : public Effect
{
public:
	EffectTpRandomLocation()
	{
		ID = "tp_to_random";
		name = "Teleport To Random Location";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectFakeTeleport : public EffectTpRandomLocation
{
public:
	EffectFakeTeleport()
	{
		ID = "fake_teleport";
		name = "Fake Teleport";
		bTimed = true;
		EffectDuration = 20;
		bIsFake = true;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
	
	virtual void OnDeactivate() override;

private:
	Vector3 oldCoord;
	std::string oldName;
	
	bool bTeleportedBack = false;
	
	void TeleportToOldCoord();
};

class EffectPinkertonProtection : public Effect
{
public:
	EffectPinkertonProtection()
	{
		ID = "pinkerton_protection";
		name = "Pinkerton Protection";
		bTimed = true;
		EffectDuration = 60;
	}

	virtual void OnActivate() override;

	virtual void OnTick() override;

	virtual void OnDeactivate() override;

private:
	// the total number of Pinkerton agents that can be spawned
	const int maxPinkertonPeds = 20;

	// the radius around the player in which Pinkerton agents will orbit around
	const float orbitRadius = 3.5f;

	// the time it takes for the Pinkerton agents to complete a full orbit around the player
	const float fullOrbitTime = 3.0f;

	// whether we should start the orbiting process - true normally after all Pinkerton agents have been spawned
	bool bStartOrbit = false;

	float lastOrbitTick = 0.0f;

	std::set<Ped> pinkertonPeds = {};

	static float DegreesToRadians(float degrees);
};

class EffectCantTieShoes : public Effect
{
public:
	EffectCantTieShoes()
	{
		ID = "cant_tie_shoes";
		name = "Can't Tie Shoes";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnTick() override;

	virtual void OnDeactivate() override;

private:
	// the player must be running for at-least 2 seconds before we can ragdoll them
	const float runTimeUntilRagdoll = 2.0f;

	bool isRunning = false;
	float lastRunTick = 0.0f;
};

class EffectInfiniteAmmo : public Effect
{
public:
	EffectInfiniteAmmo()
	{
		ID = "infinite_ammo";
		name = "Infinite Ammo";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};

class EffectTeleportToSky : public Effect
{
public:
	EffectTeleportToSky()
	{
		ID = "teleport_to_sky";
		name = "Teleport To Sky";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectArthurHataway : public Effect
{
public:
	EffectArthurHataway()
	{
		ID = "arthur_hataway";
		name = "Arthur Hataway";
		bTimed = true;
		EffectDuration = 35;
	}

	virtual void OnTick() override;
};

class EffectSpawnRandomLegendaryAnimalBearExcluded : public Effect
{
public:
	EffectSpawnRandomLegendaryAnimalBearExcluded()
	{
		ID = "spawn_random_lengendary_animal";
		name = "Spawn Random Legendary Animal";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSuperRunAndJump : public Effect
{
public:
	EffectSuperRunAndJump()
	{
		ID = "super_run_and_jump";
		name = "Super Run & Jump";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};

class EffectBlackHole : public Effect
{
public:
	EffectBlackHole()
	{
		ID = "black_hole";
		name = "Black Hole";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnTick() override;
};

class EffectAnonymousBenefactor : public Effect
{
public :
	EffectAnonymousBenefactor()
	{
		ID = "anonymous_benefactor";
		name = "Anonymous Benefactor";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectHuntingTime : public Effect
{
public:
	EffectHuntingTime()
	{
		ID = "hunting_time";
		name = "Hunting Time!";
		bTimed = false;
	}

	virtual void OnTick() override;
};

class EffectRedneckRage : public Effect
{
public:
	EffectRedneckRage()
	{
		ID = "redneck_rage";
		name = "Redneck Rage";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};

class EffectWhatIsThat : public Effect
{
public:
	EffectWhatIsThat()
	{
		ID = "what_is_that";
		name = "What Is That?";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectRainbowEverything : public Effect
{
public:
	EffectRainbowEverything()
	{
		ID = "rainbow_everything";
		name = "Rainbow Everything";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};

class EffectFullyClean : public Effect
{
public:
	EffectFullyClean()
	{
		ID = "fully_clean_player";
		name = "Fully Clean";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectForcefield : public Effect
{
public:
	EffectForcefield()
	{
		ID = "forcefield";
		name = "Forcefield";
		bTimed = true;
		EffectDuration = 25;
	}


	virtual void OnTick() override;
};

class EffectNothing : public Effect
{
public:
	EffectNothing()
	{
		ID = "nothing";
		name = "Nothing";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectPortalGuns : public Effect
{
public:
	EffectPortalGuns()
	{
		ID = "portal_gun";
		name = "Portal Guns";
		bTimed = true;
		EffectDuration = 45;
	}


	virtual void OnTick() override;
};

class EffectCantStopJumping : public Effect
{
public:
	EffectCantStopJumping()
	{
		ID = "cant_stop_jumping";
		name = "Cant Stop Jumping";
		bTimed = true;
		EffectDuration = 45;
	}

	virtual void OnTick() override;
};

class EffectTeleportAFewMeters : public Effect
{
public:
	EffectTeleportAFewMeters()
	{
		ID = "teleport_a_few_meters";
		name = "Teleport A Few Meters";
		bTimed = false;
	}

	virtual void OnActivate() override;
};


class EffectSetPlayerMaxStats : public Effect
{
public:
	EffectSetPlayerMaxStats()
	{
		ID = "set_player_max_stats";
		name = "Max Player Stats ";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSetPlayerMidStats : public Effect
{
public:
	EffectSetPlayerMidStats()
	{
		ID = "set_player_mid_stats";
		name = "Mid Player Stats ";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSetPlayerMinStats : public Effect
{
public:
	EffectSetPlayerMinStats()
	{
		ID = "set_player_min_stats";
		name = "Min Player Stats ";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectBoop : public Effect
{
public:
	EffectBoop()
	{
		ID = "boop";
		name = "Boop";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectFakeCrash : public Effect
{
public:
	EffectFakeCrash()
	{
		ID = "fake_crash";
		name = "Fake Crash";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectOneBulletReload : public Effect
{
public:
	EffectOneBulletReload()
	{
		ID = "one_bullet_reload";
		name = "One Bullet Reload";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};

class EffectExtremeSnow : public Effect
{
public:
	EffectExtremeSnow()
	{
		ID = "extreme_snow";
		name = "Extreme Snow";
		bTimed = false;
	}

	virtual void OnActivate() override;
};


class EffectSpawnEvilClone : public Effect
{
public:
	EffectSpawnEvilClone()
	{
		ID = "spawn_evil_clone";
		name = "Spawn Evil Clone";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectLumbago : public Effect
{
public:
	EffectLumbago()
	{
		ID = "lumbago";
		name = "Lumbago";
		bTimed = true;
		EffectDuration = 35;
	}

	virtual void OnActivate() override;
	virtual void OnDeactivate() override;
};

class EffectEveryoneLosesTheirGun : public Effect
{
public:
	EffectEveryoneLosesTheirGun()
	{
		ID = "everyone_loses_their_gun";
		name = "Everyone Loses Their Gun";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectMinimumDamage : public Effect
{
public:
	EffectMinimumDamage()
	{
		ID = "minimal_damage";
		name = "Minimal Damage";
		bTimed = true;
		EffectDuration = 20;
	}

	virtual void OnTick() override;
	virtual void OnDeactivate() override;

};

class EffectNeverWanted : public Effect
{
public:
	EffectNeverWanted()
	{
		ID = "never_wanted";
		name = "Never Wanted";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnTick() override;
};

class EffectHotHorses : public Effect
{
public:
	EffectHotHorses()
	{
		ID = "hot_horses";
		name = "Hot Horses";
		bTimed = true;
		EffectDuration = 25;
	}

	virtual void OnTick() override;
};


class EffectTriggerFinger : public Effect
{
public:
	EffectTriggerFinger()
	{
		ID = "trigger_finger";
		name = "Trigger Finger";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};


class EffectKnifeOnly : public Effect
{
public:
	EffectKnifeOnly()
	{
		ID = "knife_only";
		name = "Knife Only";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};



class EffectExplosiveMelee : public Effect
{
public:
	EffectExplosiveMelee()
	{
		ID = "explosive_melee";
		name = "Explosive Melee";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};


class EffectWeatherChangeOnKill : public Effect
{
public:
	EffectWeatherChangeOnKill()
	{
		ID = "weather_change_on_kill";
		name = "Weather Change On Kill";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};

class EffectTurnIntoAGiant : public Effect
{
public:
	EffectTurnIntoAGiant()
	{
		ID = "turn_into_giant";
		name = "Turn Into Giant";
		bTimed = true;
		EffectDuration = 25;
	}

	virtual void OnActivate() override;
	virtual void OnDeactivate() override;
};

class EffectWinnieThePooh : public Effect
{
public:
	EffectWinnieThePooh()
	{
		ID = "winnie_the_pooh";
		name = "Winnie The Pooh";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectLetsTakeALook : public Effect
{
public:
	EffectLetsTakeALook()
	{
		ID = "lets_take_a_look";
		name = "Let's Take A Look";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectDecideOnOutfit : public Effect
{
public:
	EffectDecideOnOutfit()
	{
		ID = "cant_decide_on_outfit";
		name = "Cant Decide On Outfit";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnTick() override;
};

class EffectMaritime : public Effect
{
public:
	EffectMaritime()
	{
		ID = "maritime";
		name = "Maritime";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectTeleportToTumbleweed : public Effect
{
	public :
		EffectTeleportToTumbleweed()
	{
		ID = "tp_to_tumbleweed";
		name = "Teleport To Tumbleweed";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSnakeRain : public Effect
{
public:
	EffectSnakeRain()
	{
		ID = "snake_rain";
		name = "Snake Rain";
		bTimed = true;
		EffectDuration = 25;
	}

	virtual void OnTick() override;

};

class EffectTurnHorsesIntoDogs : public Effect
{
public:
	EffectTurnHorsesIntoDogs()
	{
		ID = "turn_horses_into_dogs";
		name = "Turn Horses Into Doggos";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectTeleportToClosestTrainStation : public Effect
{
public:
	EffectTeleportToClosestTrainStation()
	{
		ID = "tp_to_train_station";
		name = "Teleport To Closest Train Station";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectHorseDiesAndResurrects : public Effect
{
public:
	EffectHorseDiesAndResurrects()
	{
		ID = "horse_dies_and_resurrects";
		name = "Horse Dies And Resurrects";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectTeleportToTallestMountain : public Effect
{
public:
	EffectTeleportToTallestMountain()
	{
		ID = "tp_to_tallest_mountain";
		name = "Country Roads Take Me Home";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectDoggoGun : public Effect
{
public:
	EffectDoggoGun()
	{
		ID = "doggo_gun";
		name = "Doggo Gun";
		bTimed = true;
		EffectDuration = 40;

	}

	virtual void OnTick() override;
};

class EffectSnakeCage : public Effect
{
public:
	EffectSnakeCage()
	{
		ID = "snake_cage";
		name = "SNAKE!";
		bTimed = false;

	}

	virtual void OnActivate() override;
};

class EffectShootHorses : public Effect
{
public:
	EffectShootHorses()
	{
		ID = "shoot_horses";
		name = "Horse Gun";
		bTimed = true;
		EffectDuration = 30;

	}

	virtual void OnTick() override;
};

class EffectRevengeIsAFoolsGame : public Effect
{
public:
	EffectRevengeIsAFoolsGame()
	{
		ID = "revenge_is_a_fools_game";
		name = "Revenge Is A Fools Game";
		bTimed = true;
		EffectDuration = 30;

	}

	virtual void OnActivate() override;
};

class EffectFullyDirty : public Effect
{
public:
	EffectFullyDirty()
	{
		ID = "fully_dirty";
		name = "Very very dirty";
		bTimed = false;

	}

	virtual void OnActivate() override;
};

class EffectScrawnyNag : public Effect
{
public:
	EffectScrawnyNag()
	{
		ID = "scrawny_nag";
		name = "Scrawny Nag";
		bTimed = false;

	}

	virtual void OnActivate() override;
};

class EffectWilliamsRedemption : public Effect
{
public:
	EffectWilliamsRedemption()
	{
		ID = "williams_redemption";
		name = "Williams Redemption";
		bTimed = true;
		EffectDuration = 25;

	}

	virtual void OnActivate() override;
};

class EffectTrot : public Effect
{
public:
	EffectTrot()
	{
		ID = "trot";
		name = "Trot";
		bTimed = true;
		EffectDuration = 40;

	}

	virtual void OnTick() override;
	virtual void OnDeactivate() override;
};

class EffectJohnTime : public Effect
{
public:
	EffectJohnTime()
	{
		ID = "john_time";
		name = "John Time";
		bTimed = false;
	}

	uint64_t oldSkin1{};
	uint64_t oldSkin2{};

	virtual void OnActivate() override;
	virtual void OnDeactivate() override;
};


class EffectGiveOneRandomWeaponForEachSlot : public Effect
{
public:
	EffectGiveOneRandomWeaponForEachSlot()
	{
		ID = "give_one_random_weapon_for_each_slot";
		name = "Random Weapon In Each Slot";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class IEffectSetAllWeaponDirtLevel : public Effect
{
public:
	IEffectSetAllWeaponDirtLevel()
	{
		bTimed = false;
	}

	virtual void OnActivate() override;

protected:
	float dirtLevel = 0;
};

class EffectHillBillyTurf : public Effect
{
public:
	EffectHillBillyTurf()
	{
		ID = "hill_billy_turf";
		name = "Hilly Billy Turf";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectCleanAllWeapons : public IEffectSetAllWeaponDirtLevel
{
public:
	EffectCleanAllWeapons()
	{
		ID = "clean_all_weapons";
		name = "All Players Weapons Are Clean";
		bTimed = false;
		dirtLevel = 0;
	}
};

class EffectDirtyAllWeapons : public IEffectSetAllWeaponDirtLevel
{
public:
	EffectDirtyAllWeapons()
	{
		ID = "dirty_all_weapons";
		name = "All Players Weapons Are Dirty";
		bTimed = false;
		dirtLevel = 1.0f;
	}
};

class EffectPonziScheme : public Effect
{
public:
	EffectPonziScheme()
	{
		ID = "ponzi_scheme";
		name = "Ponzi Scheme";
		bTimed = true;
		EffectDuration = 40;

	}

	virtual void OnTick() override;
};

class EffectRandomClothing : public Effect
{
public:
	EffectRandomClothing()
	{
		ID = "random_clothing";
		name = "Apply Random Clothing";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectExplosiveAmmo : public Effect
{
public:
	EffectExplosiveAmmo()
	{
		ID = "explosive_ammo";
		name = "Explosive Ammo";
		bTimed = true;
		EffectDuration = 25;
	}

	virtual void OnTick() override;
};

class EffectFakeMoney : public Effect
{
public:
	EffectFakeMoney()
	{
		ID = "fake_money";
		name = "Fake Money ";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};

class EffectIHaveAPlan : public Effect
{
public:
	EffectIHaveAPlan()
	{
		ID = "i_have_a_plan";
		name = "I Have A Plan";
		bTimed = true;
	}


	uint64_t oldSkin1{};
	uint64_t oldSkin2{};

	virtual void OnDeactivate() override;
	virtual void OnActivate() override;
};

class EffectThisIsntTahiti : public Effect
{
public:
	EffectThisIsntTahiti()
	{
		ID = "this_isnt_tahiti";
		name = "This Isnt Tahiti";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectFastestInTheWest : public Effect
{
public:
	EffectFastestInTheWest()
	{
		ID = "fastest_in_the_west";
		name = "Fastest In The West";
		bTimed = true;
		EffectDuration = 25;
	}

	virtual void OnTick() override;
};

class EffectTenXMovementSpeedOnFoot : public Effect
{
public:
	EffectTenXMovementSpeedOnFoot()
	{
		ID = "ten_times_movement_speed";
		name = "10x Movement Speed";
		bTimed = true;
		EffectDuration = 35;
	}

	virtual void OnTick() override;
};

class EffectGrandTheftHorses : public Effect
{
public:
	EffectGrandTheftHorses()
	{
		ID = "grand_theft_horses";
		name = "Grand Theft Horses";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectAllExplosives : public Effect
{
public:
	EffectAllExplosives()
	{
		ID = "all_explosives";
		name = "All Explosives";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSwapPlaces : public Effect
{
public:
	EffectSwapPlaces()
	{
		ID = "swap_places";
		name = "Swap Places";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectPaino : public Effect
{
public:
	EffectPaino()
	{
		ID = "paino";
		name = "Paino!";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectWalkOnWater : public Effect
{
public:
	EffectWalkOnWater()
	{
		ID = "walk_on_water";
		name = "Walk On Water";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
};


class EffectTrain : public Effect
{
public:
	EffectTrain()
	{
		ID = "train";
		name = "TRAIN!";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectBackgroundWar : public Effect
{
public:
	EffectBackgroundWar()
	{
		ID = "background_war";
		name = "Background War";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSpawnNightFolk : public Effect
{
public:
	EffectSpawnNightFolk()
	{
		ID = "spawn_night_folk";
		name = "Spawn Night Folk";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectGoldRush : public Effect
{
public:
	EffectGoldRush()
	{
		ID = "gold_rush";
		name = "Gold Rush";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectCampingTime : public Effect
{
public:
	EffectCampingTime()
	{
		ID = "camping_time";
		name = "Camping Time";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSpawnCannon : public Effect
{
public:
	EffectSpawnCannon()
	{
		ID = "spawn_cannon";
		name = "Spawn Cannon";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectRockyRain : public Effect
{
public:
	EffectRockyRain()
	{
		ID = "rocky_rain";
		name = "Rocky Rain";
		bTimed = true;
		EffectDuration = 20;
	}

	virtual void OnTick() override;
};

class EffectCantDismountHorse : public Effect
{
public:
	EffectCantDismountHorse()
	{
		ID = "cant_dismount_horse";
		name = "Cant Dismount Horse";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnTick() override;
	virtual void OnDeactivate() override;
};

class EffectAnimalsRunAwayFromPlayer : public Effect
{
public:
	EffectAnimalsRunAwayFromPlayer()
	{
		ID = "animals_run_away_from_player";
		name = "Animal Runs Away From Player";
		bTimed = true;
		EffectDuration = 20;
	}

	virtual void OnTick() override;
};

class EffectSpawnJohnCompanion : public Effect
{
public:
	EffectSpawnJohnCompanion()
	{
		ID = "spawn_john_companion";
		name = "Spawn John Companion";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectRainingFish : public Effect
{
public:
	EffectRainingFish()
	{
		ID = "raining_fish";
		name = "Raining Fish";
		bTimed = true;
		EffectDuration = 20;
	}

	virtual void OnTick() override;
};

class EffectFireRain : public Effect
{
public:
	EffectFireRain()
	{
		ID = "fire_rain";
		name = "Fire Rain";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnTick() override;
};

class EffectLightningStorm : public Effect
{
public:
	EffectLightningStorm()
	{
		ID = "lightning_storm";
		name = "Lightning Storm";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectBurningMicahOnHorse : public Effect
{
public:
	EffectBurningMicahOnHorse()
	{
		ID = "burning_micah_on_horse";
		name = "Burning Micah On Horse";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectDeathRidesUponAWhiteHorse : public Effect
{
public:
	EffectDeathRidesUponAWhiteHorse()
	{
		ID = "death_rides_upon_a_white_horse";
		name = "Death Rides Upon A White Horse";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectAimbot : public Effect
{
public:
	EffectAimbot()
	{
		ID = "aimbot";
		name = "Aimbot";
		bTimed = true;
		EffectDuration = 35;
	}

	virtual void OnTick() override;
};

class EffectDisableDeadeye : public Effect
{
public:
	EffectDisableDeadeye()
	{
		ID = "disable_deadeye";
		name = "Disable Deadeye";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnTick() override;
};

class EffectShootRandomProp : public Effect
{
public:
	EffectShootRandomProp()
	{
		ID = "shoot_random_prop";
		name = "Shoot Random Prop";
		bTimed = true;
		EffectDuration = 25;
	}

	virtual void OnTick() override;
};

class EffectSpawnSwatTeam : public Effect
{
public:
	EffectSpawnSwatTeam()
	{
		ID = "spawn_swat_team";
		name = "Spawn Swat Team";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectHotAirBalloonMountainDavey : public Effect
{
public:
	EffectHotAirBalloonMountainDavey()
	{
		ID = "mountain_davey";
		name = "Davey?";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectVampire : public Effect
{
public:
	EffectVampire()
	{
		ID = "vampire";
		name = "Vampire";
		bTimed = true;
		EffectDuration = 40;
	}

	virtual void OnActivate() override;
};

class EffectFakeDeath : public Effect
{
public:
	EffectFakeDeath()
	{
		ID = "fake_death";
		name = "Fake Death";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectFakeFakeDeath : public Effect
{
public:
	EffectFakeFakeDeath()
	{
		ID = "fake_fake_death";
		name = "Fake Fake Death";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSmokeGun : public Effect
{
public:
	EffectSmokeGun()
	{
		ID = "smoke_gun";
		name = "Smoke Guns";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnTick() override;
};

class EffectRandomStrangerEncounter : public Effect
{
public:
	EffectRandomStrangerEncounter()
	{
		ID = "random_stranger_encounter";
		name = "Random Stranger Encounter";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectNoBeardAndHair : public Effect
{
public:
	EffectNoBeardAndHair()
	{
		ID = "no_beard_and_hair";
		name = "No Beard And Hair";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectFullBeardAndHair : public Effect
{
public:
	EffectFullBeardAndHair()
	{
		ID = "full_beard_and_hair";
		name = "Full Beard And Hair";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectYeeYeeHaircut : public Effect
{
public:
	EffectYeeYeeHaircut()
	{
		ID = "yee_yee_haircut";
		name = "Yeeyee Haircut";
		bTimed = false;
	}

	virtual void OnActivate() override;
};