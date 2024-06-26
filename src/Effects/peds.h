#pragma once

#include "effect.h"
#include <vector>
#include <set>
#include <map>

Ped SpawnPedAroundPlayer(Hash skinModel, bool bSetInVehicle = true, bool bSpawnHorseForPed = false);

class EffectSpawnSoldier : public Effect
{
public:
	EffectSpawnSoldier()
	{
		ID = "spawn_soldier";
		name = "Spawn Soldier Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnDrunkardJon : public Effect
{
public:
	EffectSpawnDrunkardJon()
	{
		ID = "spawn_jon";
		name = "Spawn Drunkard Jon";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnLenny : public Effect
{
public:
	EffectSpawnLenny()
	{
		ID = "spawn_lenny";
		name = "Spawn Companion Lenny";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnChicken : public Effect
{
public:
	EffectSpawnChicken()
	{
		ID = "spawn_chicken";
		name = "Spawn Chicken Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnWolfPack : public Effect
{
public:
	EffectSpawnWolfPack()
	{
		ID = "spawn_wolf_pack";
		name = "Spawn Companion Wolf Pack";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectKidnapping : public Effect
{
public:
	EffectKidnapping()
	{
		ID = "kidnapping";
		name = "Pig Farmers Kidnap Player";
		bTimed = true;
		EffectDuration = 15;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
};

class EffectSpawnHorse : public Effect
{
public:
	EffectSpawnHorse()
	{
		ID = "spawn_horse";
		name = "Spawn Horse";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnMule : public Effect
{
public:
	EffectSpawnMule()
	{
		ID = "spawn_mule";
		name = "Spawn Mule";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnDonkey : public Effect
{
public:
	EffectSpawnDonkey()
	{
		ID = "spawn_donkey";
		name = "Spawn Donkey";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnMiniDonkey : public Effect
{
public:
	EffectSpawnMiniDonkey()
	{
		ID = "spawn_mini_donkey";
		name = "Spawn Mini Donkey";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnGiantDonkey : public Effect
{
public:
	EffectSpawnGiantDonkey()
	{
		ID = "spawn_giant_donkey";
		name = "Spawn Giant Donkey";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnSerialKiller : public Effect
{
public:
	EffectSpawnSerialKiller()
	{
		ID = "spawn_serial_killer";
		name = "Spawn Serial Killer";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnVampire : public Effect
{
public:
	EffectSpawnVampire()
	{
		ID = "spawn_vampire";
		name = "Spawn Vampire";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnGiantCop : public Effect
{
public:
	EffectSpawnGiantCop()
	{
		ID = "spawn_giant_cop";
		name = "Spawn Giant Cop";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnAngrySkeleton : public Effect
{
public:
	EffectSpawnAngrySkeleton()
	{
		ID = "spawn_skeleton";
		name = "Spawn Angry Skeleton";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectTownTooSmall : public Effect
{
public:
	EffectTownTooSmall()
	{
		ID = "town_too_small";
		name = "This Town Ain't Big Enough";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnActivate() override;

	virtual void OnTick() override;

	virtual void OnDeactivate() override;
};

class EffectSpawnAngryDwarf : public Effect
{
public:
	EffectSpawnAngryDwarf()
	{
		ID = "spawn_dwarf";
		name = "Spawn Angry Dwarf";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnCompanionBertram : public Effect
{
public:
	EffectSpawnCompanionBertram()
	{
		ID = "spawn_bertram";
		name = "Spawn Companion Bertram";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnFrozenCouple : public Effect
{
public:
	EffectSpawnFrozenCouple()
	{
		ID = "spawn_frozen_couple";
		name = "Spawn Frozen Couple";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectSpawnRobot : public Effect
{
public:
	EffectSpawnRobot()
	{
		ID = "spawn_robot";
		name = "Spawn Robot Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnLassoGuy : public Effect
{
public:
	EffectSpawnLassoGuy()
	{
		ID = "lasso_guy";
		name = "Spawn Lasso Guy";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSkyrimIntro : public Effect
{
public:
	EffectSkyrimIntro()
	{
		ID = "skyrim_intro";
		name = "You're Finally Awake";
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
};

class EffectSpawnParrotCompanion : public Effect
{
public:
	EffectSpawnParrotCompanion()
	{
		ID = "parrot_companion";
		name = "Spawn Parrot Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnShireHorse : public Effect
{
public:
	EffectSpawnShireHorse()
	{
		ID = "spawn_shire_horse";
		name = "Spawn Shire Horse";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectUndeadNightmare : public Effect
{
public:
	EffectUndeadNightmare()
	{
		ID = "undead_nightmare";
		name = "Undead Nightmare";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnDogCompanion : public Effect
{
public:
	EffectSpawnDogCompanion()
	{
		ID = "spawn_dog_companion";
		name = "Spawn Dog Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnCatCompanion : public Effect
{
public:
	EffectSpawnCatCompanion()
	{
		ID = "spawn_cat_companion";
		name = "Spawn Cat Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnBearCompanion : public Effect
{
public:
	EffectSpawnBearCompanion()
	{
		ID = "spawn_bear_companion";
		name = "Spawn Bear Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnAngryCorpse : public Effect
{
public:
	EffectSpawnAngryCorpse()
	{
		ID = "spawn_angry_corpse";
		name = "Spawn Angry Corpse";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectSpawnAngryCaveman : public Effect
{
public:
	EffectSpawnAngryCaveman()
	{
		ID = "spawn_angry_caveman";
		name = "Spawn Angry Caveman";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnAngryTwin : public Effect
{
public:
	EffectSpawnAngryTwin()
	{
		ID = "spawn_angry_twin";
		name = "Spawn Angry Twin";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnAngryCowboy : public Effect
{
public:
	EffectSpawnAngryCowboy()
	{
		ID = "spawn_angry_cowboy";
		name = "Spawn Angry Cowboy";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnUndeadBoss : public Effect
{
public:
	EffectSpawnUndeadBoss()
	{
		ID = "spawn_undead_boss";
		name = "Spawn Undead Boss";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnGrieferMicah : public Effect
{
public:
	EffectSpawnGrieferMicah()
	{
		ID = "spawn_greifer_micah";
		name = "Spawn Griefer Micah";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectDutchStealsPlayersVeh : public Effect
{
public:
	EffectDutchStealsPlayersVeh()
	{
		ID = "dutch_steals_veh";
		name = "Dutch Steals Player's Veh";
		bTimed = true;
		EffectDuration = 20;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnDeactivate() override;

private:
	Ped dutch;
};

class EffectSpawnPredator : public Effect
{
public:
	EffectSpawnPredator()
	{
		ID = "spawn_predator";
		name = "Spawn Predator";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};


class EffectPedsBhop : public Effect
{
public:
	EffectPedsBhop()
	{
		ID = "peds_bhop";
		name = "Peds Can't Stop Bunny Hopping";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnTick() override;
};

class EffectPedsSpin : public Effect
{
public:
	EffectPedsSpin()
	{
		ID = "peds_spin";
		name = "Spinning Peds";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;

private:
	std::set <Ped> peds;
	
	float heading = 0.0f;
};

class EffectCloneEnemy : public Effect
{
public:
	EffectCloneEnemy()
	{
		ID = "clone_enemy";
		name = "Clone Random Enemy";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectPedsFollowPlayer : public Effect
{
public:
	EffectPedsFollowPlayer()
	{
		ID = "peds_follow_player";
		name = "Peds Follow Player";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
	
	virtual void OnDeactivate() override;

private:
	std::set <Ped> peds;
};

class EffectPedsFleeing : public Effect
{
public:
	EffectPedsFleeing()
	{
		ID = "peds_fleeing";
		name = "Nearby Peds Are Fleeing";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectHealNearbyPeds : public Effect
{
public:
	EffectHealNearbyPeds()
	{
		ID = "heal_nearby_peds";
		name = "Heal Nearby Peds";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectReviveDeadPeds : public Effect
{
public:
	EffectReviveDeadPeds()
	{
		ID = "revive_dead_peds";
		name = "Revive Dead Peds";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnAngryTommy : public Effect
{
public:
	EffectSpawnAngryTommy()
	{
		ID = "spawn_tommy";
		name = "Spawn Angry Tommy";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectPartyTime : public Effect
{
public:
	EffectPartyTime()
	{
		ID = "party_time";
		name = "Party Time";
		bTimed = true;
		EffectDuration = 25;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;
	
	virtual void OnDeactivate() override;

private:
	std::set <Ped> peds;
	std::map<Ped, char*> pedAnimNames;
};

class EffectExplodeNearbyPeds : public Effect
{
public:
	EffectExplodeNearbyPeds()
	{
		ID = "explode_nearby_peds";
		name = "Explode Nearby Peds";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectNearbyPedIsCompanion : public Effect
{
public:
	EffectNearbyPedIsCompanion()
	{
		ID = "nearby_ped_is_companion";
		name = "Nearby Ped Is Player's Companion";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectEveryoneRagdollsWhenShot : public Effect
{
public:
	EffectEveryoneRagdollsWhenShot()
	{
		ID = "everyone_ragdolls_when_shot";
		name = "Everyone Ragdolls When Shot";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;

private:
	std::set <Ped> peds;
};

class EffectNearbyPedIsEnemy : public Effect
{
public:
	EffectNearbyPedIsEnemy()
	{
		ID = "nearby_ped_is_enemy";
		name = "Nearby Ped Is Player's Enemy";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectExplosiveCombat : public Effect
{
public:
	EffectExplosiveCombat()
	{
		ID = "explosive_combat";
		name = "Explosive Combat";
		bTimed = true;
		EffectDuration = 30;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;

private:
	std::set <Ped> peds;
};

class EffectODriscolls : public Effect
{
public:
	EffectODriscolls()
	{
		ID = "spawn_odriscolls";
		name = "Spawn O'Driscoll Boys";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectBanditoKidnapsPlayer : public Effect
{
public:
	EffectBanditoKidnapsPlayer()
	{
		ID = "bandito_kidnaps";
		name = "Bandito Kidnaps Player";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnTwitchViewer : public Effect
{
public:
	EffectSpawnTwitchViewer()
	{
		ID = "spawn_twitch_viewer";
		name = "Spawn Random Twitch Viewer";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
	
	void Spawn(std::string name);

private:
	Ped ped = 0;
};


class EffectEveryoneIsLenny : public Effect
{
public:
	EffectEveryoneIsLenny()
	{
		ID = "everyone_is_lenny";
		name = "Nearby Peds Are Lenny";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnExtremeEvilMicah : public Effect
{
public:
	EffectSpawnExtremeEvilMicah()
	{
		ID = "spawn_evil_micah";
		name = "Spawn Extreme Griefer Micah";
		bTimed = true;
		EffectDuration = 45;
	}
	
	virtual void OnActivate() override;
	
	virtual void OnTick() override;

private:
	Vector3 lastVec;
	Ped micahPed;
};

class EffectBabyHorses : public Effect
{
public:
	EffectBabyHorses()
	{
		ID = "baby_horses";
		name = "Horses Tiny";
		bTimed = true;
		EffectDuration = 45;
	}

	virtual void OnTick() override;
	
	virtual void OnDeactivate() override;
	
private:
	// the horses that are effected by this effect
	std::set <Ped> effectedHorses;
};

class ISetAllPlayerHorseStatsEffect : public Effect
{
public :
	ISetAllPlayerHorseStatsEffect()
	{
		bTimed = false;
	}

	virtual void OnActivate() override;

protected:
	// the amount to set all the horses stats to (0.0f - 1.0f)
	float statAmountMultiplier = 0.0f;
};

class EffectSetAllPlayerHorseStatsToMax : public ISetAllPlayerHorseStatsEffect
{
public:
	EffectSetAllPlayerHorseStatsToMax()
	{
		ID = "set_all_player_horse_stats_to_max";
		name = "Set Player Horse Stats To Max";
		statAmountMultiplier = 1.0f;
	}
};

class EffectSetAllPlayerHorseStatsToMin : public ISetAllPlayerHorseStatsEffect
{
public:
	EffectSetAllPlayerHorseStatsToMin()
	{
		ID = "set_all_player_horse_stats_to_min";
		name = "Set Player Horse Stats To Min";
		statAmountMultiplier = 0.0f;
	}
};

class EffectSetAllPlayerHorseStatsToHalf : public ISetAllPlayerHorseStatsEffect
{
public:
	EffectSetAllPlayerHorseStatsToHalf()
	{
		ID = "set_all_player_horse_stats_to_half";
		name = "Set Player Horse Stats To Half";
		statAmountMultiplier = 0.5f;
	}
};

class EffectHorseMagnet : public Effect
{
public:
	EffectHorseMagnet()
	{
		ID = "horse_magnet";
		name = "Horse Magnet";
		bTimed = true;
		EffectDuration = 60;
	}

	virtual void OnActivate() override;

	virtual void OnTick() override;

	virtual void OnDeactivate() override;

private:
	std::set <Ped> excludedPeds;
	std::set <Ped> pedsEffectedByMagnet;
};

class EffectHorseLosesAllStamina : public Effect
{
public:
	EffectHorseLosesAllStamina()
	{
		ID = "horse_loses_all_stamina";
		name = "Can't Teach A Horse To Drink";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSpawnGrieferCougar: public Effect
{
public:
	EffectSpawnGrieferCougar()
	{
		// For now it's only spawn the cougar and won't despawn it
		// like "Spawn Extreme Evil Micah"
		// may be change to timed effect later?
		ID = "spawn_griefer_cougar";
		name = "Spawn Griefer Cougar";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnCompanionDutch : public Effect
{
public:
	EffectSpawnCompanionDutch()
	{
		ID = "spawn_companion_dutch";
		name = "Have Faith In Dutch";
		bTimed = false;
	}
	
	virtual void OnActivate() override;
};

class EffectSpawnKillerBunnyHorde : public Effect
{
public:
	EffectSpawnKillerBunnyHorde()
	{
		ID = "spawn_killer_bunny_horde";
		name = "Wabbit Season";
		bTimed = true;
		EffectDuration = 60;
	}
	
	virtual void OnActivate() override;
	virtual void OnTick() override;
	virtual void OnDeactivate() override;
	
private:
	std::set <Ped> rabbits;
	Ped player;
	int lastDamageTick;
	Hash rabbitSkinModel;
};

class EffectSpawnUncleArmy : public Effect
{
public:
	EffectSpawnUncleArmy()
	{
		ID = "spawn_uncle_army";
		name = "Spawn Uncle Army";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSpawnCompanionUncle : public Effect
{
public:
	EffectSpawnCompanionUncle()
	{
		ID = "spawn_companion_uncle";
		name = "Spawn Companion Uncle";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSpawnCompanionPredator : public Effect
{
public:
	EffectSpawnCompanionPredator()
	{
		ID = "spawn_companion_predator";
		name = "Spawn Companion Predator";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSpawnNativeAmbush : public Effect
{
public:
	EffectSpawnNativeAmbush()
	{
		ID = "spawn_native_ambush";
		name = "Native Ambush";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectSpawnPinkertons : public Effect
{
public:
	EffectSpawnPinkertons()
	{
		ID = "spawn_pinkertons";
		name = "Damn Pinkertons!";
		bTimed = false;
	}

	virtual void OnActivate() override;
};

class EffectFightingGhosts : public Effect
{
public:
	EffectFightingGhosts()
	{
		ID = "fighting_ghosts";
		name = "Fighting Ghosts";
		bTimed = true;
		EffectDuration = 30;
	}

	virtual void OnActivate() override;

	virtual void OnTick() override;

	virtual void OnDeactivate() override;

private:
	// the maximum number of ghosts that can be spawned at once
	const int maxGhosts = 5;

	// the maximum distance from the player the ghosts can be, if they are further away they will be deleted
	const float maxDistanceFromPlayer = 500.0f;

	// the ghosts that are currently spawned
	std::set<Ped> ghostPeds;

	// the model hash of the ghost ped
	Hash ghostModelHash;

	// internal function to spawn a ghost
	void SpawnGhost();
};

class EffectGunslingerDuel : public Effect
{
public:
	EffectGunslingerDuel()
	{
		ID = "gunslinger_duel";
		name = "Gunslinger Duel";
		bTimed = false;
	}

	virtual void OnActivate() override;

private:
	inline static std::vector<const char*> gunSlingerModels = {"CS_famousgunslinger_01", "CS_famousgunslinger_02"
											"CS_famousgunslinger_03", "CS_famousgunslinger_04",
											"CS_famousgunslinger_05", "CS_famousgunslinger_06"};
};

std::vector <Ped> GetNearbyPeds(int32_t Max);

void RemovePedFromVeh(Ped ped);

void RemoveAllPedWeapons(Ped ped);

void MarkPedAsCompanion(Ped ped);

void MarkPedAsEnemy(Ped ped, bool hideBlip = false);

void SetPedScale(Ped ped, float scale);

void FixEntityInCutscene(Entity entity);