#include "player.h"
#include "peds.h"
#include "../script.h"
#include "misc.h"
#include "vehs.h"
#include <random>
#include <ranges>

void EffectLaunchPlayerUp::OnActivate()
{
	Effect::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Entity entityToUse = playerPed;
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		entityToUse = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
	}
	else if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		entityToUse = PED::GET_MOUNT(playerPed);
	}
	else
	{
		FixEntityInCutscene(entityToUse);
		WAIT(75);
		PED::SET_PED_TO_RAGDOLL(playerPed, 5000, 5000, 0, true, true, false);
	}
	
	
	Vector3 entityVelocity = ENTITY::GET_ENTITY_VELOCITY(entityToUse, 0);
	
	ENTITY::SET_ENTITY_VELOCITY(entityToUse, entityVelocity.x, entityVelocity.y, 35.0f);
}

void EffectToTheStars::OnActivate()
{
	Effect::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Entity entityToUse = playerPed;
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		entityToUse = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
	}
	else if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		entityToUse = PED::GET_MOUNT(playerPed);
	}
	else
	{
		PED::SET_PED_TO_RAGDOLL(playerPed, 10000, 10000, 0, true, true, false);
	}
	
	Vector3 entityLocation = ENTITY::GET_ENTITY_COORDS(entityToUse, true, 0);
	
	ENTITY::SET_ENTITY_COORDS(entityToUse, entityLocation.x, entityLocation.y, 800.0f, 0, 0, 0, 0);
}

void TeleportPlayerTo(float X, float Y, float Z)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Entity entityToUse = playerPed;
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		entityToUse = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
	}
	else if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		entityToUse = PED::GET_MOUNT(playerPed);
	}
	
	ENTITY::SET_ENTITY_COORDS(entityToUse, X, Y, Z, 0, 0, 0, 0);
}

void DisableAllMovements()
{
	static std::vector <Hash> keys = {GET_HASH("INPUT_MOVE_LEFT_ONLY"), GET_HASH("INPUT_MOVE_RIGHT_ONLY"),
									  GET_HASH("INPUT_MOVE_LR"), GET_HASH("INPUT_VEH_MOVE_LR"),
									  GET_HASH("INPUT_MOVE_LEFT"), GET_HASH("INPUT_MOVE_RIGHT"),
									  GET_HASH("INPUT_HORSE_MOVE_LEFT_ONLY"), GET_HASH("INPUT_VEH_CAR_TURN_LEFT_ONLY"),
									  GET_HASH("INPUT_VEH_DRAFT_TURN_LEFT_ONLY"),
									  GET_HASH("INPUT_VEH_BOAT_TURN_LEFT_ONLY"), GET_HASH("INPUT_VEH_MOVE_LEFT_ONLY"),
									  GET_HASH("INPUT_FRONTEND_AXIS_X"), GET_HASH("INPUT_HORSE_MOVE_LR"),
									  GET_HASH("INPUT_HORSE_MOVE_RIGHT_ONLY"), GET_HASH("INPUT_VEH_CAR_TURN_LR"),
									  GET_HASH("INPUT_VEH_DRAFT_TURN_RIGHT_ONLY"),
									  GET_HASH("INPUT_VEH_CAR_TURN_RIGHT_ONLY"), GET_HASH("INPUT_VEH_MOVE_RIGHT_ONLY"),
									  GET_HASH("INPUT_VEH_DRAFT_TURN_LR"), GET_HASH("INPUT_VEH_BOAT_TURN_LR"),
									  GET_HASH("INPUT_VEH_BOAT_TURN_RIGHT_ONLY"), GET_HASH("INPUT_FRONTEND_NAV_RIGHT"),
	
									  GET_HASH("INPUT_MOVE_UP_ONLY"), GET_HASH("INPUT_MOVE_DOWN_ONLY"),
									  GET_HASH("INPUT_VEH_ACCELERATE"), GET_HASH("INPUT_VEH_BRAKE"),
									  GET_HASH("INPUT_MOVE_UP"), GET_HASH("INPUT_MOVE_DOWN"), GET_HASH("INPUT_MOVE_UD"),
									  GET_HASH("INPUT_FRONTEND_AXIS_Y"), GET_HASH("INPUT_HORSE_MOVE_DOWN_ONLY"),
									  GET_HASH("INPUT_HORSE_MOVE_UD"), GET_HASH("INPUT_VEH_MOVE_DOWN_ONLY"),
									  GET_HASH("INPUT_VEH_DRAFT_MOVE_UD"), GET_HASH("INPUT_HORSE_MOVE_UP_ONLY"),
									  GET_HASH("INPUT_VEH_MOVE_UP_ONLY"), GET_HASH("INPUT_VEH_MOVE_UD"),
									  GET_HASH("INPUT_FRONTEND_NAV_UP"), GET_HASH("INPUT_HORSE_SPRINT"),
									  GET_HASH("INPUT_VEH_ACCELERATE"), GET_HASH("INPUT_HORSE_STOP"),
									  GET_HASH("INPUT_VEH_HANDCART_BRAKE"), GET_HASH("INPUT_VEH_BOAT_BRAKE"),
									  GET_HASH("INPUT_VEH_HANDBRAKE"), GET_HASH("INPUT_VEH_BRAKE"),
									  GET_HASH("INPUT_VEH_CAR_BRAKE")};
	
	
	for (Hash key : keys)
	{
		CONTROLS::DISABLE_CONTROL_ACTION(0, key, true);
	}
}

void EffectGivePlayerMoney::OnActivate()
{
	CASH::PLAYER_ADD_CASH(30000, 0x2CD419DC);
}

void EffectBankruptcy::OnActivate()
{
	/** _MONEY_DECREMENT_CASH_BALANCE */
	invoke<Void>(0x466BC8769CF26A7A, 999999999);
}

void EffectGiveRifle::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	static Hash weaponHash = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_RIFLE_SPRINGFIELD");
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 100, 1, 0x2cd419dc);
	WEAPON::SET_PED_AMMO(playerPed, weaponHash, 100);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
}

void EffectGiveRevolver::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	static Hash weaponHash = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_REVOLVER_SCHOFIELD");
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 100, 1, 0x2cd419dc);
	WEAPON::SET_PED_AMMO(playerPed, weaponHash, 100);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
}

void EffectNoAmmo::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	/** REMOVE_ALL_PED_AMMO */
	invoke<Void>(0x1B83C0DEEBCBB214, playerPed);
	
	static Hash unarmed = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_UNARMED");
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, unarmed, 1, 0, 0, 0);
}

void EffectRemoveAllWeapons::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	RemoveAllPedWeapons(playerPed);
}

void EffectDropWeapon::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	static std::set <Hash> importantWeapons = {GET_HASH("WEAPON_KIT_CAMERA"), GET_HASH("WEAPON_LASSO"),
											   GET_HASH("WEAPON_FISHINGROD"), GET_HASH("WEAPON_MELEE_LANTERN_ELECTRIC"),
											   GET_HASH("WEAPON_MELEE_KNIFE")};
	
	static Hash unarmed = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_UNARMED");
	Hash weaponHash = 0;
	
	if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, 0, 0, 0) && WEAPON::IS_WEAPON_VALID(weaponHash) &&
		weaponHash != unarmed)
	{
		if (importantWeapons.contains(weaponHash))
		{
			return;
		}
		
		WEAPON::SET_PED_DROPS_INVENTORY_WEAPON(playerPed, weaponHash, 0.0f, 0.0f, 0.0f, 0);
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, unarmed, 1, 0, 0, 0);
	}
}

void EffectHealPlayer::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	int maxHealth = PED::GET_PED_MAX_HEALTH(playerPed);
	
	ENTITY::SET_ENTITY_HEALTH(playerPed, maxHealth, 0);
}

void EffectAlmostDead::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	ENTITY::SET_ENTITY_HEALTH(playerPed, 1, 0);
}

void EffectRestoreStamina::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	PLAYER::RESTORE_PLAYER_STAMINA(PLAYER::PLAYER_ID(), 1.0f);
}

void EffectRagdoll::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	FixEntityInCutscene(playerPed);
	WAIT(75);
	PED::SET_PED_TO_RAGDOLL(playerPed, 3000, 3000, 0, true, true, false);
}

void EffectGiveRandomWeapon::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	static std::set <Hash> importantWeapons = {GET_HASH("WEAPON_KIT_CAMERA"), GET_HASH("WEAPON_LASSO"),
											   GET_HASH("WEAPON_FISHINGROD"), GET_HASH("WEAPON_MELEE_LANTERN_ELECTRIC"),
											   GET_HASH("WEAPON_MELEE_KNIFE")};
	
	for (auto wHash : importantWeapons)
	{
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, wHash, 100, 1, 0x2cd419dc);
		WEAPON::SET_PED_AMMO(playerPed, wHash, 100);
	}
	
	int32_t weaponID = rand() % Effect::WeaponHashes.size();
	
	Hash weaponHash = Effect::WeaponHashes[weaponID];
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 100, 1, 0x2cd419dc);
	WEAPON::SET_PED_AMMO(playerPed, weaponHash, 100);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
}

void EffectSetDrunk::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	AUDIO::SET_PED_IS_DRUNK(playerPed, true);
	CAM::SHAKE_GAMEPLAY_CAM((char*) "DRUNK_SHAKE", 1.0f);
	PED::SET_PED_CONFIG_FLAG(playerPed, 100, true);
	GRAPHICS::ANIMPOSTFX_PLAY((char*) "PlayerDrunk01");
	
	invoke<Void>(0x406CCF555B04FAD3, playerPed, true, 1.0f);
	
	/** Set walking style */
	invoke<Void>(0x89F5E7ADECCCB49C, playerPed, "very_drunk");
}

void EffectSetDrunk::OnDeactivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	AUDIO::SET_PED_IS_DRUNK(playerPed, false);
	CAM::STOP_GAMEPLAY_CAM_SHAKING(true);
	PED::SET_PED_CONFIG_FLAG(playerPed, 100, false);
	GRAPHICS::ANIMPOSTFX_STOP((char*) "PlayerDrunk01");
	
	invoke<Void>(0x406CCF555B04FAD3, playerPed, false, 0.0f);
	invoke<Void>(0x923583741DC87BCE, playerPed, "arthur_healthy");
	invoke<Void>(0x89F5E7ADECCCB49C, playerPed, "default");
}

void EffectSetDrunk::OnTick()
{
	Effect::OnTick();
	
	if (TimerTick(7000))
	{
		PED::SET_PED_TO_RAGDOLL(PLAYER::PLAYER_PED_ID(), 1000, 1000, 0, true, true, false);
	}
}

void EffectClearPursuit::OnActivate()
{
	Player player = PLAYER::PLAYER_ID();
	PURSUIT::CLEAR_CURRENT_PURSUIT();
	PURSUIT::SET_PLAYER_WANTED_INTENSITY(player, 0);
	PURSUIT::SET_PLAYER_PRICE_ON_A_HEAD(player, 0);
}

void EffectIncreaseBounty::OnActivate()
{
	Player player = PLAYER::PLAYER_ID();
	int priceOnHead = PURSUIT::GET_PLAYER_PRICE_ON_A_HEAD(player);
	PURSUIT::SET_PLAYER_PRICE_ON_A_HEAD(player, priceOnHead + 50 * 100);
}

void EffectRemoveCurrentVehicle::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, false, false);
		
		VEHICLE::DELETE_VEHICLE(&veh);
	}
	else if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		Ped mount = PED::GET_MOUNT(playerPed);
		
		/** _REMOVE_PED_FROM_MOUNT */
		invoke<Void>(0x5337B721C51883A9, playerPed, 0, 0);
		
		if (!ENTITY::IS_ENTITY_A_MISSION_ENTITY(mount))
		{
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(mount, false, false);
			
			PED::DELETE_PED(&mount);
		}
	}
}

void EffectGiveLasso::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	static Hash weaponHash = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_LASSO");
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 100, 1, 0x2cd419dc);
	WEAPON::SET_PED_AMMO(playerPed, weaponHash, 100);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
}

void EffectIgnitePlayer::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	FIRE::START_ENTITY_FIRE(playerPed, 1.0f, 0, 0);
}

void EffectKickflip::OnActivate()
{
	Effect::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		
		Vector3 vec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
		
		ENTITY::SET_ENTITY_COORDS(playerPed, vec.x, vec.y, vec.z + 2.0f, false, false, false, false);
		
		Vector3 vel = ENTITY::GET_ENTITY_VELOCITY(veh, 0);
		
		ENTITY::SET_ENTITY_VELOCITY(playerPed, vel.x, vel.y, vel.z);
	}
	
	FixEntityInCutscene(playerPed);
	WAIT(75);
	
	PED::SET_PED_TO_RAGDOLL(playerPed, 1000, 1000, 0, true, true, false);
	
	ENTITY::APPLY_FORCE_TO_ENTITY(playerPed, 1, 0, 0, 10, 2, 0, 0, 0, true, true, true, false, true);
}

void SetPlayerModel(const char* model, uint64_t* ptr1_val, uint64_t* ptr2_val)
{
	Hash hash = GET_HASH(model);
	
	LoadModel(hash);
	
	ChaosMod::Singleton->SavePlayerAttributes();
	
	ChaosMod::UpdatePlayerSkinHash();
	
	PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), hash, 1);
	*getGlobalPtr(0x23) = PLAYER::PLAYER_PED_ID();
	
	
	uint64_t* ptr1 = getGlobalPtr(0x28) + 0x27;
	uint64_t* ptr2 = getGlobalPtr(0x1D890E) + 2;
	
	*ptr1 = hash;
	*ptr2 = hash;
	Ped playerPed = PLAYER::PLAYER_PED_ID();;
	*getGlobalPtr(0x23) = playerPed;
	
	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
	ENTITY::SET_ENTITY_COLLISION(playerPed, true, true);
	ENTITY::SET_ENTITY_DYNAMIC(playerPed, true);
}

void ResetPlayerModel(uint64_t ptr1_val, uint64_t ptr2_val)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		/** _REMOVE_PED_FROM_MOUNT */
		invoke<Void>(0x5337B721C51883A9, playerPed, 0, 0);
	}
	ChaosMod::ResetPlayerSkin();
}

void EffectLightningWeapons::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &lastVec);
}

void EffectLightningWeapons::OnDeactivate()
{
	lastVec.x = lastVec.y = lastVec.z = 0.0f;
}

void EffectLightningWeapons::OnTick()
{
	Vector3 vec;
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	bool bCoordValid = WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &vec);
	
	if (!bCoordValid || (vec.x == lastVec.x && vec.y == lastVec.y && vec.z == lastVec.z))
	{
		return;
	}
	
	lastVec = vec;
	
	/** _FORCE_LIGHTNING_FLASH_AT_COORDS */
	invoke<Void>(0x67943537D179597C, vec.x, vec.y, vec.z);
}

void IEffectSkinChange::OnActivate()
{
	Effect::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		
		Vector3 vec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
		
		ENTITY::SET_ENTITY_COORDS(playerPed, vec.x, vec.y, vec.z + 2.0f, false, false, false, false);
	}
	else if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		Ped mount = PED::GET_MOUNT(playerPed);
		
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(mount, true, true);
		
		/** _REMOVE_PED_FROM_MOUNT */
		invoke<Void>(0x5337B721C51883A9, playerPed, 1, 0);
	}
	
	auto modelName = skinToSet[rand() % skinToSet.size()];
	SetPlayerModel(modelName, & oldSkin1, & oldSkin2);
}

void IEffectSkinChange::OnDeactivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		Ped mount = PED::GET_MOUNT(playerPed);
		
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(mount, true, true);
		
		/** _REMOVE_PED_FROM_MOUNT */
		invoke<Void>(0x5337B721C51883A9, playerPed, 0, 0);
	}
	
	ResetPlayerModel(oldSkin1, oldSkin2);
}

void EffectHonorGood::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	(*getGlobalPtr(0x2BA2)) = 0;
	
	int honor = *getGlobalPtr(0x2BA2);
	
	*getGlobalPtr(1347477 + 155 + 1) = 240;
}

void EffectHonorBad::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	(*getGlobalPtr(0x2BA2)) = 0;
	
	int honor = *getGlobalPtr(0x2BA2);
	
	*getGlobalPtr(1347477 + 155 + 1) = -240;
}

void EffectHonorReset::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	(*getGlobalPtr(0x2BA2)) = 0;
	
	int honor = *getGlobalPtr(0x2BA2);
	
	*getGlobalPtr(1347477 + 155 + 1) = 40;
}

void EffectPlayerSleep::OnActivate()
{
	Effect::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		
		Vector3 vec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
		
		ENTITY::SET_ENTITY_COORDS(playerPed, vec.x, vec.y, vec.z + 2.0f, false, false, false, false);
	}
	
	FixEntityInCutscene(playerPed);
	
	WAIT(75);
	
	PED::SET_PED_TO_RAGDOLL(playerPed, EffectDuration * 1000 + 3000, EffectDuration * 1000 + 3000, 0, true, true,
							false);
}

void EffectPlayerIsMinion::OnActivate()
{
	Effect::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	/** _SET_PED_SCALE */
	invoke<Void>(0x25ACFC650B65C538, playerPed, 0.4f);
}

void EffectPlayerIsMinion::OnTick()
{
	if (TimerTick(500))
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		
		/** _SET_PED_SCALE */
		invoke<Void>(0x25ACFC650B65C538, playerPed, 0.4f);
	}
}

void EffectPlayerIsMinion::OnDeactivate()
{
	Effect::OnDeactivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	/** _SET_PED_SCALE */
	invoke<Void>(0x25ACFC650B65C538, playerPed, 1.0f);
}

void EffectTeleportToWaypoint::OnActivate()
{
	Effect::OnDeactivate();
	
	Entity entity = PLAYER::PLAYER_PED_ID();
	
	
	if (!RADAR::IS_WAYPOINT_ACTIVE())
	{
		return;
	}
	
	if (PED::IS_PED_IN_ANY_VEHICLE(entity, true))
	{
		entity = PED::GET_VEHICLE_PED_IS_IN(entity, false);
	}
	else if (PED::IS_PED_ON_MOUNT(entity))
	{
		entity = PED::GET_MOUNT(entity);
	}
	
	Vector3 coords = RADAR::GET_WAYPOINT_COORDS_3D();
	
	bool bUpdatedCoords = GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, 100.0, &coords.z, FALSE);
	
	if (!bUpdatedCoords)
	{
		static const float groundCheckHeight[] = {100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0,
												  500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0};
		
		for (float height : groundCheckHeight)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(entity, coords.x, coords.y, height, 0, 0, 1);
			WAIT(100);
			if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, height, &coords.z, FALSE))
			{
				coords.z += 3.0;
				break;
			}
		}
	}
	
	ENTITY::SET_ENTITY_COORDS(entity, coords.x, coords.y, coords.z, false, false, false, false);
}

void EffectExplosiveWeapons::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &lastVec);
}

void EffectExplosiveWeapons::OnDeactivate()
{
	lastVec.x = lastVec.y = lastVec.z = 0.0f;
}

void EffectExplosiveWeapons::OnTick()
{
	Vector3 vec;
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	bool bCoordValid = WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &vec);
	
	if (!bCoordValid || (vec.x == lastVec.x && vec.y == lastVec.y && vec.z == lastVec.z))
	{
		return;
	}
	
	lastVec = vec;
	
	FIRE::ADD_EXPLOSION(vec.x, vec.y, vec.z, 27, 1.0f, true, false, 1.0f);
}

void EffectBloodTrails::OnTick()
{
	if (TimerTick(5000))
	{
		invoke<Void>(0xC349EE1E6EFA494B, PLAYER::PLAYER_PED_ID(), 1.0f, 1.0f, 1.0f);
	}
}

void EffectSetRandomWalkStyle::OnActivate()
{
	static std::vector<const char*> walkStyles = {"cower_known", "injured_left_leg"
																 "injured_general", "injured_right_leg",
												  "injured_left_arm", "injured_right_arm", "injured_torso",
												  "very_drunk", "moderate_drunk"};
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	invoke<Void>(0x923583741DC87BCE, playerPed, "default");
	invoke<Void>(0x89F5E7ADECCCB49C, playerPed, walkStyles[rand() % walkStyles.size()]);
}

void EffectSetRandomWalkStyle::OnDeactivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	invoke<Void>(0x923583741DC87BCE, playerPed, "arthur_healthy");
	invoke<Void>(0x89F5E7ADECCCB49C, playerPed, "default");
}

void EffectTeleportWeapons::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &lastVec);
}

void EffectTeleportWeapons::OnDeactivate()
{
	lastVec.x = lastVec.y = lastVec.z = 0.0f;
}

void EffectTeleportWeapons::OnTick()
{
	Vector3 vec;
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	bool bCoordValid = WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &vec);
	
	if (!bCoordValid || (vec.x == lastVec.x && vec.y == lastVec.y && vec.z == lastVec.z))
	{
		return;
	}
	
	lastVec = vec;
	
	ENTITY::SET_ENTITY_COORDS(playerPed, vec.x, vec.y, vec.z + 0.0f, false, false, false, false);
}

void EffectGiveSniperRifle::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static Hash weaponHash = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_SNIPERRIFLE_ROLLINGBLOCK");
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 35, 1, 0x2cd419dc);
	WEAPON::SET_PED_AMMO(playerPed, weaponHash, 35);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
}

void EffectGiveDynamite::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static Hash weaponHash = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_THROWN_DYNAMITE");
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 3, 1, 0x2cd419dc);
	WEAPON::SET_PED_AMMO(playerPed, weaponHash, 3);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
}


void EffectThrowingKnives::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static Hash weaponHash = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_THROWN_THROWING_KNIVES");
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 10, 1, 0x2cd419dc);
	WEAPON::SET_PED_AMMO(playerPed, weaponHash, 10);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
}

void EffectTeleportFewMeters::OnActivate()
{
	Entity entity = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(entity, true))
	{
		entity = PED::GET_VEHICLE_PED_IS_IN(entity, false);
	}
	else if (PED::IS_PED_ON_MOUNT(entity))
	{
		entity = PED::GET_MOUNT(entity);
	}
	
	Vector3 vec = GetRandomCoordInRange(ENTITY::GET_ENTITY_COORDS(entity, true, 0), 10);
	
	bool bUpdatedCoords = GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(vec.x, vec.y, vec.z, &vec.z, FALSE);
	
	if (!bUpdatedCoords)
	{
		static const float groundCheckHeight[] = {100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0,
												  500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0};
		
		for (float height : groundCheckHeight)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(entity, vec.x, vec.y, height, 0, 0, 1);
			WAIT(100);
			if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(vec.x, vec.y, height, &vec.z, FALSE))
			{
				vec.z += 3.0;
				break;
			}
		}
	}
	
	ENTITY::SET_ENTITY_COORDS(entity, vec.x, vec.y, vec.z, false, false, false, false);
}

void EffectBlackingOut::OnActivate()
{
	Effect::OnDeactivate();
	
	GRAPHICS::ANIMPOSTFX_PLAY((char*) "PlayerWakeUpInterrogation");
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		
		Vector3 vec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
		
		ENTITY::SET_ENTITY_COORDS(playerPed, vec.x, vec.y, vec.z + 2.0f, false, false, false, false);
	}
	
	FixEntityInCutscene(playerPed);
	WAIT(75);
	
	PED::SET_PED_TO_RAGDOLL(playerPed, 5000, 5000, 0, true, true, false);
}

void EffectRandomClothes::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	int32_t outfitID = rand() % 58;
	
	if (outfitID == 25 || outfitID == 17 || outfitID == 14 || outfitID == 28)
	{
		outfitID = 0;
	}
	
	invoke<Void>(0x77FF8D35EEC6BBC4, playerPed, outfitID, false);
}

void EffectMostWanted::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Player player = PLAYER::PLAYER_ID();
	
	invoke<Void>(0xF60386770878A98F, player, GAMEPLAY::GET_HASH_KEY((char*) "CRIME_ASSAULT_LAW"), 0, 0, 1);
	int priceOnHead = PURSUIT::GET_PLAYER_PRICE_ON_A_HEAD(player);
	PURSUIT::SET_PLAYER_PRICE_ON_A_HEAD(player, priceOnHead + 50 * 100);
}

void EffectPigSkin::OnActivate()
{
	IEffectSkinChange::OnActivate();
	
	invoke<Void>(0x77FF8D35EEC6BBC4, PLAYER::PLAYER_PED_ID(), rand() % 4, false);
}

void EffectSetWinterOutfit::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Hash playerSkin = ENTITY::GET_ENTITY_MODEL(playerPed);
	
	static Hash skinArthur = GAMEPLAY::GET_HASH_KEY((char*) "PLAYER_ZERO");
	static Hash skinJohn = GAMEPLAY::GET_HASH_KEY((char*) "PLAYER_THREE");
	
	if (playerSkin == skinArthur)
	{
		invoke<Void>(0x77FF8D35EEC6BBC4, playerPed, 1, false);
	}
	else if (playerSkin == skinJohn)
	{
		invoke<Void>(0x77FF8D35EEC6BBC4, playerPed, 25, false);
	}
}

void EffectSuperJump::OnTick()
{
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
}


void EffectDisableLeftRight::OnTick()
{
	static std::vector <Hash> keys = {GET_HASH("INPUT_MOVE_LEFT_ONLY"), GET_HASH("INPUT_MOVE_RIGHT_ONLY"),
									  GET_HASH("INPUT_MOVE_LR"), GET_HASH("INPUT_VEH_MOVE_LR"),
									  GET_HASH("INPUT_MOVE_LEFT"), GET_HASH("INPUT_MOVE_RIGHT"),
									  GET_HASH("INPUT_HORSE_MOVE_LEFT_ONLY"), GET_HASH("INPUT_VEH_CAR_TURN_LEFT_ONLY"),
									  GET_HASH("INPUT_VEH_DRAFT_TURN_LEFT_ONLY"),
									  GET_HASH("INPUT_VEH_BOAT_TURN_LEFT_ONLY"), GET_HASH("INPUT_VEH_MOVE_LEFT_ONLY"),
									  GET_HASH("INPUT_FRONTEND_AXIS_X"), GET_HASH("INPUT_HORSE_MOVE_LR"),
									  GET_HASH("INPUT_HORSE_MOVE_RIGHT_ONLY"), GET_HASH("INPUT_VEH_CAR_TURN_LR"),
									  GET_HASH("INPUT_VEH_DRAFT_TURN_RIGHT_ONLY"),
									  GET_HASH("INPUT_VEH_CAR_TURN_RIGHT_ONLY"), GET_HASH("INPUT_VEH_MOVE_RIGHT_ONLY"),
									  GET_HASH("INPUT_VEH_DRAFT_TURN_LR"), GET_HASH("INPUT_VEH_BOAT_TURN_LR"),
									  GET_HASH("INPUT_VEH_BOAT_TURN_RIGHT_ONLY"), GET_HASH("INPUT_FRONTEND_NAV_RIGHT")
		
	};
	
	for (Hash key : keys)
	{
		CONTROLS::DISABLE_CONTROL_ACTION(0, key, true);
	}
}

void EffectDisableForwardBackward::OnTick()
{
	static std::vector <Hash> keys = {GET_HASH("INPUT_MOVE_UP_ONLY"), GET_HASH("INPUT_MOVE_DOWN_ONLY"),
									  GET_HASH("INPUT_VEH_ACCELERATE"), GET_HASH("INPUT_VEH_BRAKE"),
									  GET_HASH("INPUT_MOVE_UP"), GET_HASH("INPUT_MOVE_DOWN"), GET_HASH("INPUT_MOVE_UD"),
									  GET_HASH("INPUT_FRONTEND_AXIS_Y"), GET_HASH("INPUT_HORSE_MOVE_DOWN_ONLY"),
									  GET_HASH("INPUT_HORSE_MOVE_UD"), GET_HASH("INPUT_VEH_MOVE_DOWN_ONLY"),
									  GET_HASH("INPUT_VEH_DRAFT_MOVE_UD"), GET_HASH("INPUT_HORSE_MOVE_UP_ONLY"),
									  GET_HASH("INPUT_VEH_MOVE_UP_ONLY"), GET_HASH("INPUT_VEH_MOVE_UD"),
									  GET_HASH("INPUT_FRONTEND_NAV_UP"), GET_HASH("INPUT_HORSE_SPRINT"),
									  GET_HASH("INPUT_VEH_ACCELERATE"), GET_HASH("INPUT_HORSE_STOP"),
									  GET_HASH("INPUT_VEH_HANDCART_BRAKE"), GET_HASH("INPUT_VEH_BOAT_BRAKE"),
									  GET_HASH("INPUT_VEH_HANDBRAKE"), GET_HASH("INPUT_VEH_BRAKE"),
									  GET_HASH("INPUT_VEH_CAR_BRAKE")};
	
	for (Hash key : keys)
	{
		CONTROLS::DISABLE_CONTROL_ACTION(0, key, true);
	}
}

void EffectDisableSprintJump::OnTick()
{
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_SPRINT"), true);
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_JUMP"), true);
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_HORSE_SPRINT"), true);
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_VEH_ACCELERATE"), true);
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_HORSE_JUMP"), true);
}

void EffectDisableAllMovements::OnTick()
{
	DisableAllMovements();
}

void EffectDisableAttackButton::OnTick()
{
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_ATTACK"), true);
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_MELEE_ATTACK"), true);
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_MELEE_GRAPPLE_ATTACK"), true);
	CONTROLS::DISABLE_CONTROL_ACTION(0, GET_HASH("INPUT_HORSE_MELEE"), true);
}

void EffectDisableAiming::OnActivate()
{
	/** Should remove reticle */
	UI::_0x4CC5F2FC1332577F(GET_HASH("HUD_CTX_IN_FAST_TRAVEL_MENU"));
}

void EffectDisableAiming::OnDeactivate()
{
	UI::_0x8BC7C1F929D07BF3(GET_HASH("HUD_CTX_IN_FAST_TRAVEL_MENU"));
}

void EffectDisableAiming::OnTick()
{
	CONTROLS::DISABLE_CONTROL_ACTION(0, GAMEPLAY::GET_HASH_KEY((char*) "INPUT_AIM"), true);
}

void EffectRandomHonor::OnActivate()
{
	*getGlobalPtr(1347477 + 155 + 1) = (rand() % 51) - 25;
}

void EffectInvertVelocity::OnActivate()
{
	Entity entity = PLAYER::PLAYER_PED_ID();
	
	bool bUsingVehicle = PED::IS_PED_IN_ANY_VEHICLE(entity, true);
	
	if (bUsingVehicle)
	{
		entity = PED::GET_VEHICLE_PED_IS_IN(entity, false);
	}
	else if (PED::IS_PED_ON_MOUNT(entity))
	{
		entity = PED::GET_MOUNT(entity);
	}
	
	float multiplier = -3.0f;
	
	Vector3 vel = ENTITY::GET_ENTITY_VELOCITY(entity, 0);
	
	if (!bUsingVehicle)
	{
		FixEntityInCutscene(entity);
		WAIT(75);
		PED::SET_PED_TO_RAGDOLL(entity, 1000, 1000, 0, true, true, false);
	}
	else
	{
		multiplier = -5.0f;
	}
	
	vel.x *= multiplier;
	vel.y *= multiplier;
	vel.z *= multiplier;
	
	
	ENTITY::SET_ENTITY_VELOCITY(entity, vel.x, vel.y, vel.z);
}

void EffectIncreaseVelocity::OnActivate()
{
	Entity entity = PLAYER::PLAYER_PED_ID();
	
	bool bUsingVehicle = PED::IS_PED_IN_ANY_VEHICLE(entity, true);
	
	if (bUsingVehicle)
	{
		entity = PED::GET_VEHICLE_PED_IS_IN(entity, false);
	}
	else if (PED::IS_PED_ON_MOUNT(entity))
	{
		entity = PED::GET_MOUNT(entity);
	}
	
	float multiplier = 3.0f;
	Vector3 vel = ENTITY::GET_ENTITY_VELOCITY(entity, 0);
	
	if (!bUsingVehicle)
	{
		FixEntityInCutscene(entity);
		WAIT(75);
		PED::SET_PED_TO_RAGDOLL(entity, 1000, 1000, 0, true, true, false);
	}
	
	
	vel.x *= multiplier;
	vel.y *= multiplier;
	vel.z *= multiplier;
	
	ENTITY::SET_ENTITY_VELOCITY(entity, vel.x, vel.y, vel.z);
}

void EffectBunnyhop::OnTick()
{
	if (!TimerTick(500))
	{
		return;
	}
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
	{
		Vector3 vec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
		
		ENTITY::SET_ENTITY_COORDS(playerPed, vec.x, vec.y, vec.z + 1.5f, false, false, false, false);
	}
	else if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		/** _REMOVE_PED_FROM_MOUNT */
		invoke<Void>(0x5337B721C51883A9, playerPed, 0, 0);
	}
	else
	{
		AI::TASK_JUMP(playerPed, 0);
	}
}

void EffectEyeDisorder::OnActivate()
{
	GRAPHICS::ANIMPOSTFX_PLAY((char*) "OJDominoBlur");
}

void EffectEyeDisorder::OnDeactivate()
{
	GRAPHICS::ANIMPOSTFX_STOP((char*) "OJDominoBlur");
}


void EffectBirdSkin::OnActivate()
{
	IEffectSkinChange::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	uint32_t maxOutfits = PED::_0x10C70A515BC03707(playerPed);
	
	uint32_t randOutfit = rand() % maxOutfits;
	
	invoke<Void>(0x77FF8D35EEC6BBC4, playerPed, randOutfit, false);
}

void EffectBirdSkin::OnTick()
{
	static Hash controlSet = GET_HASH("OnMount");
	CONTROLS::_0x2804658EB7D8A50B(2, controlSet);
}

void EffectBodySwap::OnActivate()
{
	pedSkin = 0;
	clone = 0;
	auto nearbyPeds = GetNearbyPeds(50);
	
	std::vector <Ped> validPeds;
	std::vector <Ped> missionPeds;
	
	
	bool bUseMissionPed = false;
	bool bUseRandomSkin = false;
	
	for (auto ped : nearbyPeds)
	{
		if (PED::IS_PED_HUMAN(ped))
		{
			if (!ENTITY::IS_ENTITY_A_MISSION_ENTITY(ped) || ChaosMod::pedsSet.contains(ped))
			{
				validPeds.push_back(ped);
			}
			else
			{
				missionPeds.push_back(ped);
			}
		}
	}
	
	if (!validPeds.size())
	{
		if (missionPeds.size())
		{
			bUseMissionPed = true;
		}
		else
		{
			bUseRandomSkin = true;
		}
	}
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Ped ped = 0;
	
	if (!bUseRandomSkin)
	{
		if (bUseMissionPed)
		{
			ped = missionPeds[rand() % missionPeds.size()];
		}
		else
		{
			ped = validPeds[rand() % validPeds.size()];
		}
		
		if (!ENTITY::DOES_ENTITY_EXIST(ped))
		{
			return;
		}
	}
	
	
	Vector3 playerVec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
	Vector3 pedVec;
	pedVec.x = pedVec.y = pedVec.z = 0;
	
	auto pedHeading = 0;
	
	Vehicle playerVehicle = 0;
	Ped playerMount = 0;
	uint32_t playerSeat = -2;
	
	Vehicle pedVehicle = 0;
	Ped pedMount = 0;
	uint32_t pedSeat = -2;
	
	if (!bUseRandomSkin)
	{
		pedSkin = ENTITY::GET_ENTITY_MODEL(ped);
	}
	else
	{
		static std::vector<const char*> skins = {"a_m_m_vallaborer_01", "a_m_m_valtownfolk_01", "a_m_m_valtownfolk_02",
												 "a_m_m_tumtownfolk_01", "a_f_m_valtownfolk_01",
												 "a_m_m_asbtownfolk_01"};
		
		pedSkin = GET_HASH(skins[rand() % skins.size()]);
	}
	
	
	if (!bUseMissionPed && !bUseRandomSkin)
	{
		pedVec = ENTITY::GET_ENTITY_COORDS(ped, true, 0);
		pedHeading = ENTITY::GET_ENTITY_HEADING(ped);
		ENTITY::SET_ENTITY_COORDS(playerPed, pedVec.x, pedVec.y, pedVec.z, false, false, false, false);
		
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, true))
		{
			playerVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
			
			playerSeat = PED::_0x4E76CB57222A00E5(playerPed);
			
			ENTITY::SET_ENTITY_COORDS(playerPed, playerVec.x, playerVec.y, playerVec.z, false, false, false, false);
		}
		else if (PED::IS_PED_ON_MOUNT(playerPed))
		{
			playerMount = PED::GET_MOUNT(playerPed);
			
			playerSeat = PED::_0x4E76CB57222A00E5(playerPed);
			
			/** _REMOVE_PED_FROM_MOUNT */
			invoke<Void>(0x5337B721C51883A9, playerPed, 0, 0);
			
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(playerMount, true, true);
		}
		
		if (PED::IS_PED_IN_ANY_VEHICLE(ped, true))
		{
			pedVehicle = PED::GET_VEHICLE_PED_IS_IN(ped, false);
			
			pedSeat = PED::_0x4E76CB57222A00E5(ped);
		}
		else if (PED::IS_PED_ON_MOUNT(ped))
		{
			pedMount = PED::GET_MOUNT(ped);
			
			pedSeat = PED::_0x4E76CB57222A00E5(ped);
		}
		
		PED::DELETE_PED(&ped);
		
		clone = PED::CLONE_PED(playerPed, ENTITY::GET_ENTITY_HEADING(playerPed), true, false);
		
		if (playerVehicle)
		{
			PED::SET_PED_INTO_VEHICLE(clone, playerVehicle, playerSeat);
			AI::TASK_VEHICLE_DRIVE_WANDER(clone, playerVehicle, 100000.0f, 0x400c0025);
			
		}
		else if (playerMount)
		{
			invoke<Void>(0x028F76B6E78246EB, clone, playerMount, playerSeat, true);
			AI::TASK_WANDER_STANDARD(clone, 100.0f, 10);
			
		}
		else
		{
			ENTITY::SET_ENTITY_COORDS(clone, playerVec.x, playerVec.y, playerVec.z, false, false, false, false);
			AI::TASK_WANDER_STANDARD(clone, 100.0f, 10);
		}
		
		if (ENTITY::DOES_ENTITY_EXIST(clone))
		{
			ChaosMod::pedsSet.insert(clone);
		}
	}
	
	LoadModel(pedSkin);
	
	ChaosMod::Singleton->SavePlayerAttributes();
	
	ChaosMod::UpdatePlayerSkinHash();
	
	PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), pedSkin, 1);
	
	*getGlobalPtr(0x23) = PLAYER::PLAYER_PED_ID();
	
	uint64_t* ptr1 = getGlobalPtr(0x28) + 0x27;
	uint64_t* ptr2 = getGlobalPtr(0x1D890E) + 2;
	
	*ptr1 = *ptr2 = pedSkin;
	
	*getGlobalPtr(0x23) = PLAYER::PLAYER_PED_ID();
	
	playerPed = PLAYER::PLAYER_PED_ID();
	
	ENTITY::SET_ENTITY_COLLISION(playerPed, true, true);
	ENTITY::SET_ENTITY_DYNAMIC(playerPed, true);
	
	if (!bUseMissionPed && !bUseRandomSkin)
	{
		if (pedVehicle)
		{
			PED::SET_PED_INTO_VEHICLE(playerPed, pedVehicle, pedSeat);
		}
		else if (pedMount)
		{
			invoke<Void>(0x028F76B6E78246EB, playerPed, pedMount, pedSeat, true);
		}
		else
		{
			ENTITY::SET_ENTITY_COORDS(playerPed, pedVec.x, pedVec.y, pedVec.z, false, false, false, false);
			ENTITY::SET_ENTITY_HEADING(playerPed, pedHeading);
		}
	}
	
	if (bUseRandomSkin)
	{
		uint32_t maxOutfits = PED::_0x10C70A515BC03707(playerPed);
		uint32_t randOutfit = rand() % maxOutfits;
	}
}

void EffectBodySwap::OnDeactivate()
{
	if (ENTITY::DOES_ENTITY_EXIST(clone))
	{
		Ped ped = SpawnPedAroundPlayer(pedSkin, false, false);
		
		Vector3 vec = ENTITY::GET_ENTITY_COORDS(clone, true, 0);
		
		ENTITY::SET_ENTITY_COORDS(ped, vec.x, vec.y, vec.z, false, false, false, false);
		
		AI::TASK_WANDER_STANDARD(ped, 100.0f, 10);
		
		ChaosMod::pedsSet.erase(clone);
		
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(clone, false, false);
		
		PED::DELETE_PED(&clone);
	}
	
	ResetPlayerModel(0, 0);
	
	pedSkin = 0;
	clone = 0;
}

void EffectPlayerSpin::OnActivate()
{
	heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
}

void EffectPlayerSpin::OnTick()
{
	Entity entity = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_IN_ANY_VEHICLE(entity, true))
	{
		entity = PED::GET_VEHICLE_PED_IS_IN(entity, false);
	}
	else if (PED::IS_PED_ON_MOUNT(entity))
	{
		entity = PED::GET_MOUNT(entity);
	}
	
	heading += 625.0f * ChaosMod::GetDeltaTimeSeconds();
	
	heading = fmod(heading, 360.0f);
	
	ENTITY::SET_ENTITY_HEADING(entity, heading);
}

void EffectPlayerLosesWeight::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	PED::_0x1902C4CFCC5BE57C(playerPed, 0x63F130D5);
	PED::_0x1902C4CFCC5BE57C(playerPed, 0x86155956);
	PED::_0x1902C4CFCC5BE57C(playerPed, 0x652668B6);
	PED::_0xCC8CA3E88256E58F(playerPed, 0, 1, 1, 1, false);
}

void EffectPlayerGainsWeight::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	PED::_0x1902C4CFCC5BE57C(playerPed, 0x63F130D5);
	PED::_0x1902C4CFCC5BE57C(playerPed, 0x74D74B1C);
	PED::_0x1902C4CFCC5BE57C(playerPed, 0xBB7091D9);
	PED::_0xCC8CA3E88256E58F(playerPed, 0, 1, 1, 1, false);
}

void EffectSetRandomHat::OnActivate()
{
	static std::vector <Hash> hats = {0x2514B2B9, 0x05A94693, 0xB2A7CB98, 0x2968E73D, 0xAE8ACE4E, 0xD16013FC,
									  0x3D9CEC78, 0x5F74300A, 0x48760F4A};
	
	Hash hat = hats[rand() % hats.size()];
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	PED::_0x1902C4CFCC5BE57C(playerPed, hat);
	PED::_0xCC8CA3E88256E58F(playerPed, 0, 1, 1, 1, false);
}

void EffectGravityGun::OnActivate()
{
	lastVec.x = lastVec.y = lastVec.z = 0.0f;
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	static Hash unarmed = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_UNARMED");
	Hash weaponHash = 0;
	
	if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, 0, 0, 0) && weaponHash == unarmed)
	{
		static Hash weaponHash = GAMEPLAY::GET_HASH_KEY((char*) "WEAPON_PISTOL_MAUSER_DRUNK");
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weaponHash, 35, 1, 0x2cd419dc);
		WEAPON::SET_PED_AMMO(playerPed, weaponHash, 35);
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, 1, 0, 0, 0);
	}
}

void EffectGravityGun::OnDeactivate()
{
	lastVec.x = lastVec.y = lastVec.z = 0.0f;
}

void EffectGravityGun::OnTick()
{
	Vector3 vec;
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	bool bCoordValid = WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &vec);
	
	if (!bCoordValid || (vec.x == lastVec.x && vec.y == lastVec.y && vec.z == lastVec.z))
	{
		return;
	}
	
	lastVec = vec;
	
	std::vector <Entity> entities = GetNearbyPeds(50);
	
	auto nearbyVehs = GetNearbyVehs(45);
	
	for (auto veh : nearbyVehs)
	{
		entities.push_back(veh);
	}
	
	auto props = GetNearbyProps(45);
	
	for (auto prop : props)
	{
		ENTITY::SET_ENTITY_DYNAMIC(prop, true);
		ENTITY::SET_ENTITY_HAS_GRAVITY(prop, true);
		entities.push_back(prop);
	}
	
	Vector3 pVec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
	
	for (auto entity : entities)
	{
		Vector3 vec2 = ENTITY::GET_ENTITY_COORDS(entity, true, 0);
		float dist = GetDistance3D(vec, vec2);
		
		const float maxDist = 5.0f;
		
		if (dist >= maxDist)
		{
			continue;
		}
		
		if (ENTITY::IS_ENTITY_A_PED(entity))
		{
			PED::SET_PED_TO_RAGDOLL(entity, 5000, 5000, 0, true, true, false);
		}
		
		float scale = 15.0f * (1.0f - (dist / maxDist));
		
		Vector3 diff = vec2;
		diff.x -= pVec.x;
		diff.y -= pVec.y;
		diff.z -= pVec.z;
		
		const float squareSum = (diff.x * diff.x) + (diff.y * diff.y) + (diff.z * diff.z);
		const float length = sqrt(squareSum);
		diff.x /= length;
		diff.y /= length;
		diff.z /= length;
		
		diff.x *= scale;
		diff.y *= scale;
		diff.y *= scale;
		
		ENTITY::SET_ENTITY_VELOCITY(entity, diff.x, diff.y, diff.z);
	}
}

void EffectDisableDeadEye::OnActivate()
{
	PLAYER::_0x95EE1DEE1DCD9070(PLAYER::PLAYER_ID(), false);
}

void EffectDisableDeadEye::OnDeactivate()
{
	PLAYER::_0x95EE1DEE1DCD9070(PLAYER::PLAYER_ID(), true);
}

void EffectSetRandomVelocity::OnActivate()
{
	Entity entity = PLAYER::PLAYER_PED_ID();
	
	bool bInVehicle = false;
	
	if (PED::IS_PED_IN_ANY_VEHICLE(entity, true))
	{
		entity = PED::GET_VEHICLE_PED_IS_IN(entity, false);
		bInVehicle = true;
	}
	else if (PED::IS_PED_ON_MOUNT(entity))
	{
		entity = PED::GET_MOUNT(entity);
	}
	
	
	if (!bInVehicle)
	{
		FixEntityInCutscene(entity);
		
		WAIT(75);
		PED::SET_PED_TO_RAGDOLL(entity, 2000, 2000, 0, true, true, false);
	}
	
	Vector3 vel;
	
	vel.x = float((rand() % 15) + 5);
	vel.y = float((rand() % 15) + 5);
	vel.z = float((rand() % 10) + 0);
	
	vel.x *= rand() % 2 ? -1 : 1;
	vel.y *= rand() % 2 ? -1 : 1;
	
	ENTITY::SET_ENTITY_VELOCITY(entity, vel.x, vel.y, vel.y);
}

void EffectFirstPerson::OnTick()
{
	CAM::_0x90DA5BA5C2635416();
}

void EffectTopDownCamera::OnActivate()
{
	this->cam = CAM::CREATE_CAM((char*) "DEFAULT_SCRIPTED_CAMERA", 1);
	CAM::RENDER_SCRIPT_CAMS(true, true, 500, 1, 1, 1);
	
	/** Should remove reticle */
	UI::_0x4CC5F2FC1332577F(GET_HASH("HUD_CTX_IN_FAST_TRAVEL_MENU"));
}

void EffectTopDownCamera::OnTick()
{
	CAM::SET_CAM_ACTIVE(this->cam, true);
	
	Vector3 camCoord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 camRotation = CAM::GET_GAMEPLAY_CAM_ROT(2);
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Vector3 vec = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
	
	vec.z += 10.0f;
	
	CAM::SET_CAM_ROT(cam, -90.0f, 0.0f, 0.0f, 2);
	CAM::SET_CAM_COORD(cam, vec.x, vec.y, vec.z);
	CAM::SET_CAM_AFFECTS_AIMING(cam, false);
}

void EffectTopDownCamera::OnDeactivate()
{
	CAM::SET_CAM_ACTIVE(this->cam, false);
	CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1, 1);
	CAM::SET_CAM_AFFECTS_AIMING(cam, true);
	CAM::DESTROY_CAM(this->cam, true);
	this->cam = 0;
	UI::_0x8BC7C1F929D07BF3(GET_HASH("HUD_CTX_IN_FAST_TRAVEL_MENU"));
}

void EffectAgitateHorse::OnActivate()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (PED::IS_PED_ON_MOUNT(playerPed))
	{
		Ped mount = PED::GET_MOUNT(playerPed);
		PED::_0xBAE08F00021BFFB2(mount, true);
	}
}

void EffectTpRandomLocation::OnActivate()
{
	static std::vector <std::vector<float>> coords = {{-301.0f,  790.0f,   119.0f}, /** Valentine */
													  {-1303.0f, 395.0f,   96.0f}, /** Wallace station */
													  {-1790.0f, -372.5f,  160.0f}, /** Strawberry */
													  {2432.8f,  -1216.0f, 46.0f}, /** Saint Denis */
													  {1526.5f,  431.0f,   91.0f}, /** Emerald Station */
													  {1264.4f,  -1311.0f, 77.0f}, /** Rhoads */
													  {2958.6f,  518.0f,   45.0f}, /** Van Horn */
													  {2927.0f,  1325.9f,  44.0f} /** Annesburg */
	};
	
	auto randomCoord = coords[rand() % coords.size()];
	
	if (randomCoord.size() != 3)
	{
		return;
	}
	
	TeleportPlayerTo(randomCoord[0], randomCoord[1], randomCoord[2]);
}

void EffectFakeTeleport::OnActivate() 
{
	oldName = this->name;
	
	auto* chaosMod = ChaosMod::Singleton;
	
	if (chaosMod)
	{
		auto* originalEffect = chaosMod->EffectsMap["tp_to_random"];
		
		if (originalEffect)
		{
			this->name = originalEffect->name;
		}
	}
	
	bTeleportedBack = false;
	Effect::OnActivate();
	oldCoord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, 0);
	EffectTpRandomLocation::OnActivate();
}

void EffectFakeTeleport::OnTick() 
{
	if (TimerTick(7000) && !bTeleportedBack)
	{
		TeleportToOldCoord();
		bTeleportedBack = true;
	}
}

void EffectFakeTeleport::OnDeactivate()
{
	if (!bTeleportedBack)
	{
		TeleportToOldCoord();
	}
	
	bTeleportedBack = false;
}

void EffectFakeTeleport::TeleportToOldCoord()
{
	TeleportPlayerTo(oldCoord.x, oldCoord.y, oldCoord.z);
	this->name = oldName;
	bTeleportedBack = true;
}

void EffectPinkertonProtection::OnActivate()
{
	Effect::OnActivate();
	
	Hash pinkertonModel = GET_HASH("CS_PinkertonGoon");

	LoadModel(pinkertonModel);

	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, 0);

	for (int i = 0; i < maxPinkertonPeds; i++)
	{
		// spawn the ped under the player, we'll re-position shortly
		Ped ped = PED::CREATE_PED(pinkertonModel, playerPosition.x, playerPosition.y, playerPosition.z - 10, 0.0f, 1, 0, 0, 0);
		DECORATOR::DECOR_SET_INT(ped, (char*)"honor_override", 0);
		PED::SET_PED_HEARING_RANGE(ped, 10000.0f);
		PED::SET_PED_VISIBLE(ped, true);
		ENTITY::SET_ENTITY_INVINCIBLE(ped, true);
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped, true);
		PED::SET_PED_CAN_BE_TARGETTED(ped, false);
		PED::_0xFD6943B6DF77E449(ped, false); // SET_PED_CAN_BE_LASSOED
		ENTITY::SET_ENTITY_COLLISION(ped, false, false);

		float angle = (i * fullOrbitTime);
		Vector3 relativeOffset = ENTITY::GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS(ped,
			playerPosition.x + (orbitRadius * cos(angle)),
			playerPosition.y + (orbitRadius * sin(angle)),
			playerPosition.z
		);

		ENTITY::ATTACH_ENTITY_TO_ENTITY(ped, PLAYER::PLAYER_PED_ID(), -1, relativeOffset.x, relativeOffset.y, 0, 0.0f, 0.0f, 0.0f, false, false, false, true, 0, false, false, false);

		pinkertonPeds.insert(ped);
	}

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(pinkertonModel);
	bStartOrbit = true;
}

void EffectPinkertonProtection::OnDeactivate()
{
	Effect::OnDeactivate();
	
	for (Ped ped : pinkertonPeds)
	{
		PED::DELETE_PED(&ped);
	}

	pinkertonPeds.clear();
	lastOrbitTick = 0;
	bStartOrbit = false;
}

void EffectPinkertonProtection::OnTick()
{
	if (!bStartOrbit)
	{
		return;
	}

	float deltaTimeSeconds = ChaosMod::GetDeltaTimeSeconds();
	float angleIncrementPerSecond = 360.0f / fullOrbitTime;
	lastOrbitTick += deltaTimeSeconds;

	// cached player ped for attaching the pinkerton's to the player
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	// the index of the pinkerton ped we're currently updating
	int index = 0;

	for (auto ped : pinkertonPeds)
	{
		// calculate the angle for this ped based on the index, the max number of peds, and the time that has passed
		float angle = (index * 360.0f / maxPinkertonPeds) + (angleIncrementPerSecond * lastOrbitTick);
		angle = fmod(angle, 360.0f);

		const float angleRadians = DegreesToRadians(angle);

		if (ENTITY::IS_ENTITY_ATTACHED_TO_ANY_PED(ped))
		{
			// go to detach before re-attaching
			ENTITY::DETACH_ENTITY(ped, true, true);
		}

		const Vector3 relativeOffset = {orbitRadius * cos(angleRadians), orbitRadius * sin(angleRadians), 0.0f};

		// calculate the heading based on our orbit angle, so we can face outwards
		float heading = angle - 90.0f;

		ENTITY::ATTACH_ENTITY_TO_ENTITY(ped, playerPed, -1, relativeOffset.x, relativeOffset.y, relativeOffset.z, 0.0f, 0.0f, heading, false, false, false, true, 0, true, false, false);

		index++;
	}
}

float EffectPinkertonProtection::DegreesToRadians(const float degrees)
{
	return degrees * (M_PI / 180.0f);
}

void EffectCantTieShoes::OnTick()
{
	if (!TimerTick(1000))
	{
		// we only need to do this really every 1 second, no point in doing it every tick
		return;
	}

	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!PED::IS_PED_ON_FOOT(playerPed))
	{
		// if the player is not on foot, we don't want to ragdoll them
		return;
	}
	
	if (PED::IS_PED_ON_MOUNT(playerPed) || ENTITY::IS_ENTITY_IN_WATER(playerPed) || PED::IS_PED_RAGDOLL(playerPed))
	{
		// if the player is on a mount, ragdolled or in water, we don't want to ragdoll them
		return;
	}

	if (!AI::IS_PED_RUNNING(playerPed) && !AI::IS_PED_SPRINTING(playerPed))
	{
		isRunning = false;
		lastRunTick = 0;
		
		// if the player is not running or sprinting, we don't want to ragdoll them
		return;
	}

	if (!isRunning)
	{
		isRunning = true;
		lastRunTick = GAMEPLAY::GET_GAME_TIMER();
	}

	if (GAMEPLAY::GET_GAME_TIMER() <  lastRunTick + runTimeUntilRagdoll)
	{
		// we haven't been running long enough yet
		return;
	}
	
	PED::SET_PED_TO_RAGDOLL(playerPed, 1000, 1000, 0, true, true, false);

	isRunning = false;
	lastRunTick = 0;
}

void EffectCantTieShoes::OnDeactivate()
{
	Effect::OnDeactivate();
	
	isRunning = false;
	lastRunTick = 0;
}

void EffectAnonymousBenefactor::OnActivate()
{
	Effect::OnActivate();
	
	PURSUIT::CLEAR_CURRENT_PURSUIT();
	// CLEAR_BOUNTY
	PURSUIT::_0xC76F252371150D9A(PLAYER::PLAYER_ID());
}

void EffectLetsTakeALook::OnActivate()
{
	Effect::OnActivate();
	
	const Ped playerPed = PLAYER::PLAYER_PED_ID();
	const Hash binoculars = GET_HASH("WEAPON_KIT_BINOCULARS");
	
	if (!WEAPON::HAS_PED_GOT_WEAPON(playerPed, binoculars, false, false))
	{
		WEAPON::_0x5E3BDDBCB83F3D84(playerPed, binoculars, 0, true, false, 0, false, 0.5f, 1.0f, 0, true, 0.0f, false);
	}
	
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, binoculars, true, 0, false, false);
}

void EffectTeleportToTumbleweed::OnActivate()
{
	TeleportPlayerTo(-5517.375f, -2936.821f, -2.219434f);
}

void EffectTeleportToClosestTrainStation::OnActivate()
{
	Effect::OnActivate();
	
	// all train station locations in the game as far as I know - There may be a few that I've missed.
	static std::vector <Vector3> tranStationLocations = {
		{-162.851669f, 637.130676f, 114.032166f}, {1526.370972f, 446.802460f, 90.680817f},
		{1226.998901f, -1303.240967f, 76.905373f}, {2755.241455f, -1418.824585f, 46.207653f},
		{2941.989502f, 1272.032349f, 44.635502f}, {-1305.211548f, 405.365326f, 95.383690f},
		{583.828186f, 1684.504639f, 187.670303f}, {-332.960846f, -351.889771f, 88.037399f},
		{-4345.784668f, -3086.569092f, -10.832883f}, {-1097.591187f, -579.141418f, 82.410767f}
	};
	
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, 0);
	Vector3 closest = {0.0f, 0.0f, 0.0f};

	float closestDistance = FLT_MAX;

	for (Vector3 location : tranStationLocations)
	{
		float distance = GetDistance3D(playerPosition, location);

		if (distance < closestDistance)
		{
			closestDistance = distance;
			closest = location;
		}
	}

	if (closest.x == 0.0f && closest.y == 0.0f && closest.z == 0.0f)
	{
		// we didn't find a closest location, so we can't teleport the player
		// this should never happen, but just in case
		return;
	}

	TeleportPlayerTo(closest.x, closest.y, closest.z);
}

void EffectTeleportToTallestMountain::OnActivate()
{
	Effect::OnActivate();
	
	TeleportPlayerTo(-1638.875854f, 1220.375366f, 351.646667f);
}

void IEffectSetAllWeaponDirtLevel::OnActivate()
{
	Effect::OnActivate();
	
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	Hash equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &equippedWeapon, 0, 0, 0);

	for (Hash weaponHash : WeaponHashes)
	{
		if (!WEAPON::_0xF29A186ED428B552(playerPed, weaponHash))
		{
			// _0xF29A186ED428B552 = IS_PED_CARRYING_WEAPON
			// if we aren't carrying it on our person then don't set the dirt level
			continue;
		}

		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, weaponHash, true, 0, false, false);

		int weaponObjectIndex = ENTITY::GET_OBJECT_INDEX_FROM_ENTITY_INDEX(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(playerPed, 0));
		WEAPON::_0x812CE61DEBCAB948(weaponObjectIndex, dirtLevel, false);
	}
	
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, equippedWeapon, true, 0, false, false);
}

void EffectInfiniteAmmo::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	Hash weaponHash;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, 0, 0, 0);

	auto const maxAmmoInClip = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, weaponHash, 0);

	WEAPON::SET_AMMO_IN_CLIP(playerPed, weaponHash, maxAmmoInClip);
}

void EffectTeleportToSky::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isPedOnMount = PED::IS_PED_ON_MOUNT(playerPed);
	
	if (isPedOnMount) {
		AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed, true, true);
	}

	auto const playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);
	auto const playerAdjustedHeight = 500.f;

	ENTITY::SET_ENTITY_COORDS(playerPed, playerCoords.x, playerCoords.y, playerCoords.z + playerAdjustedHeight, 0, 0, 0, 0);

	ENTITY::SET_ENTITY_INVINCIBLE(playerPed, true);

	WAIT(5000);

	while (ENTITY::IS_ENTITY_IN_AIR(playerPed, 0)) {
		WAIT(1000);
	}

	ENTITY::SET_ENTITY_INVINCIBLE(playerPed, false);
}

void EffectArthurHataway::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
    auto const playerHat = PED::GET_PED_LAST_HAT(playerPed);
    auto const HatEquiped = PED::_0xFB4891BD7578CDC1(playerPed, 0x9925C067);

    if (HatEquiped) {
		return;
    }

	auto const mountCheck = PED::IS_PED_ON_MOUNT(playerPed);

	if (mountCheck) {
		PED::_REMOVE_PED_FROM_MOUNT(playerPed, false, false);
	}

	Hash weaponHash;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, false, false, false);

	WEAPON::SET_AMMO_IN_CLIP(playerPed, weaponHash, 0);
}

void EffectSpawnRandomLegendaryAnimalBearExcluded::OnActivate() {
	static std::array<std::uint32_t, 14> legendaryModels = { 0x9770DD23, 0x2830CF33, 0xAA89BB8D, 0xB20D360D, 0xB91BAB89, 0xBB746741,0xC971C4C6, 0xE1884260, 0xAD02460F, 0xAA89BB8D, 0xE8CBC01C, 0xDECA9205, 0xD1641E60, 0xF8FC8F63 };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> dist(0, legendaryModels.size() - 1);

	auto const randomIndex = dist(gen);

	auto const randomLegendaryModel = legendaryModels[randomIndex];

	SpawnPedAroundPlayer(randomLegendaryModel, false, false);
}

void EffectSuperRunAndJump::OnTick() {
	static auto const constexpr INPUT_FRONTEND_ACCEPT = 0xc7b5340a;

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const shouldRun = GetAsyncKeyState(VK_SHIFT);

	if (shouldRun) {
		ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(playerPed, 1, 0.f, 10, 0.f, 0, 1, 1, 1);
	}

	auto const playerId = PLAYER::PLAYER_ID();
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(playerId);
}

static Vector3 blackHolePosition{};
static void ApplyBlackHole(std::int32_t entity, const float force) {
	const auto entity_pos = ENTITY::GET_ENTITY_COORDS(entity, 1, 0);
	
	const auto distance = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(
		blackHolePosition.x, blackHolePosition.y, blackHolePosition.z, 
		entity_pos.x, entity_pos.y, entity_pos.z, 
		true
	);
	
	const auto within_singularity = distance < 5;

	const auto direction = Vector3(
		blackHolePosition.x - entity_pos.x,
		blackHolePosition.y - entity_pos.y,
		blackHolePosition.z - entity_pos.z
	);

	if (!within_singularity) {
		ENTITY::APPLY_FORCE_TO_ENTITY(entity, 1, direction.x * force, direction.y * force, direction.z, 0.f, 0.f, 0.f, 0, false, true, true, 0, 0);
		return;
	}

	ENTITY::SET_ENTITY_VELOCITY(entity, 0.f, 0.f, 0.f);
	ENTITY::SET_ENTITY_COORDS(entity, 0, 0, 0, 0, 0, 0, 0);
	ENTITY::DELETE_ENTITY(&entity);
}

void EffectBlackHole::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, false, 0);

	auto const static blackHoleIndicator = const_cast<char*>("scr_net_target_races");
	auto const static blackHoleIndicatorSub = const_cast<char*>("scr_net_target_fire_ring_mp");
	auto const static blackHoleIndicatorHash = GAMEPLAY::GET_HASH_KEY(blackHoleIndicator);

	static auto const offsettedX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-20, 20);
	static auto const offsettedY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-20, 20);

	STREAMING::_REQUEST_NAMED_PTFX_ASSET(blackHoleIndicatorHash);
	GRAPHICS::USE_PARTICLE_FX_ASSET(blackHoleIndicator);

	blackHolePosition = {
		playerCoords.x + offsettedX,
		playerCoords.y + offsettedY,
		playerCoords.z + 10,
	};

	auto const ptfxHandle = GRAPHICS::START_PARTICLE_FX_LOOPED_AT_COORD(
		blackHoleIndicatorSub,
		blackHolePosition.x,
		blackHolePosition.y,
		blackHolePosition.z,
		0, 0, 0, 2.f, 0, 0, 0, 0
	);

	GRAPHICS::STOP_PARTICLE_FX_LOOPED(ptfxHandle, 0);
	STREAMING::_REMOVE_NAMED_PTFX_ASSET(blackHoleIndicator);

	auto peds = GetNearbyPeds(50);
	auto vehs = GetNearbyVehs(50);
	auto props = GetNearbyProps(50);

	for (auto const& ped : peds) {
		ApplyBlackHole(ped, 1.f);
	}

	for (auto const& veh : vehs) {
		ApplyBlackHole(veh, 1.f);
	}

	for (auto const& prop : props) {
		ApplyBlackHole(prop, 1.f);
	}
}

void EffectHuntingTime::OnTick() {
	static auto const unarmed = GET_HASH("WEAPON_UNARMED");
	static auto const varmintRifle = GET_HASH("w_repeater_pumpaction01");

	auto const playerPed = PLAYER::PLAYER_PED_ID();

	Hash weaponHash;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, 0, 0, 0);

	auto const isWeaponWhitelisted = weaponHash == unarmed || weaponHash == varmintRifle;

	if (!isWeaponWhitelisted) {
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, varmintRifle, 120, true, 0);
	}
}

void EffectRedneckRage::OnTick() {
	if (TimerTick(5000)) {
		auto const playerPed = PLAYER::PLAYER_PED_ID();
		auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

		std::random_device rd_0;
		std::mt19937 gen_0(rd_0());
		std::uniform_int_distribution<std::size_t> dist_0(0, 20);

		std::random_device rd_1;
		std::mt19937 gen_1(rd_1());
		std::uniform_int_distribution<std::size_t> dist_1(0, 20);

		auto const redneckModel = GAMEPLAY::GET_HASH_KEY(const_cast<char*>("CS_MicahBell"));
		auto const redneck = SpawnPedAroundPlayer(redneckModel, false, false);

		ENTITY::SET_ENTITY_COORDS(redneck, location.x + dist_0(gen_0), location.y + dist_1(gen_1), location.z, false, false, false, false);

		auto const static fireRingIndicator = const_cast<char*>("scr_net_target_races");
		auto const static fireRingIndicatorSub = const_cast<char*>("scr_net_target_fire_ring_mp");
		auto const static fireRingIndicatorHash = GAMEPLAY::GET_HASH_KEY(fireRingIndicator);

		for (int _ : std::ranges::iota_view{ 0, 20000 }) { // we do a little trolling xd

			STREAMING::_REQUEST_NAMED_PTFX_ASSET(fireRingIndicatorHash);
			GRAPHICS::USE_PARTICLE_FX_ASSET(fireRingIndicator);

			auto const redneckCoords = ENTITY::GET_ENTITY_COORDS(redneck, true, false);

			auto const ptfxHandle = GRAPHICS::START_PARTICLE_FX_LOOPED_AT_COORD(
				fireRingIndicatorSub, redneckCoords.x, redneckCoords.y, redneckCoords.z, 0, 0, 0, 2.f, 0, 0, 0, 0);

			GRAPHICS::STOP_PARTICLE_FX_LOOPED(ptfxHandle, 0);
			STREAMING::_REMOVE_NAMED_PTFX_ASSET(fireRingIndicator);
		}

		MarkPedAsEnemy(redneck);
	}
}

void EffectWhatIsThat::OnActivate() {
	static std::array<std::uint32_t, 7> randomItemArray = { 0x60F9EB94, 0x6C6FAB20, 0x4FED60F0, 0xF4ED0DA7, 0xE630AC36, 0x4D6B282C, 0xE79D9E95 };

	auto const playerId = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerId, true, false);
	auto const randomItemValue = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, randomItemArray.size() - 1);
	auto const randomItem = OBJECT::CREATE_OBJECT(randomItemArray[randomItemValue], location.x, location.y, location.z + 10, true, true, true, false, false);

	WAIT(500);

	ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(randomItem, 1, 0.f, 0.f, -20.f, 0, 1, 1, 1);
}

void EffectRainbowEverything::OnTick() {
	if (TimerTick(2000)) {
		auto const playerPed = PLAYER::PLAYER_PED_ID();
		
		auto peds = GetNearbyPeds(50);

		for (auto const& ped : peds) {
			std::random_device rd_0;
			std::mt19937 gen_0(rd_0());
			std::uniform_int_distribution<std::size_t> dist_0(0, 58);

			auto outfitId = dist_0(gen_0);

			if (outfitId == 25 || outfitId == 17 || outfitId == 14 || outfitId == 28)
			{
				outfitId = 0;
			}

			PED::_SET_PED_OUTFIT_INDEX(ped, outfitId, false);
			PED::_SET_PED_OUTFIT_INDEX(playerPed, outfitId, false);
		}
	}
}

void EffectFullyClean::OnActivate()
{
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);

	if (playerVehicle) {
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(playerVehicle, 0.f);
	}

	PED::CLEAR_PED_ENV_DIRT(playerPed);
	PED::CLEAR_PED_BLOOD_DAMAGE(playerPed);
	PED::CLEAR_PED_WETNESS(playerPed);
	PED::CLEAR_PED_DAMAGE_DECAL_BY_ZONE(playerPed, 10, const_cast<char*>("ALL"));
}

void EffectMinimumDamage::OnTick() {
	PED::SET_AI_WEAPON_DAMAGE_MODIFIER(0.f);
}

void EffectMinimumDamage::OnDeactivate() {
	PED::SET_AI_WEAPON_DAMAGE_MODIFIER(100.f);
}

void EffectNeverWanted::OnTick() {
	PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_PED_ID(), 0, false);
}

void EffectForcefield::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	PED::SET_PED_CAN_RAGDOLL(playerPed, false);

	if (TimerTick(2000)) {
		FIRE::ADD_EXPLOSION(location.x + 6, location.y, location.z, 29, 1.f, 0, 1, 0.f);
		FIRE::ADD_EXPLOSION(location.x - 6, location.y, location.z, 29, 1.f, 0, 1, 0.f);
		FIRE::ADD_EXPLOSION(location.x, location.y + 6, location.z, 29, 1.f, 0, 1, 0.f);
		FIRE::ADD_EXPLOSION(location.x, location.y - 6, location.z, 29, 1.f, 0, 1, 0.f);
	}
}

void EffectNothing::OnActivate() {}

void EffectPortalGuns::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isShooting = PED::IS_PED_SHOOTING(playerPed);

	if (!isShooting) {
		return;
	}

	Vector3 impactCoords{};

	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &impactCoords);

	auto nearbyPeds = GetNearbyPeds(45);

	for (auto const ped : nearbyPeds) {
		auto const exists = ENTITY::DOES_ENTITY_EXIST(ped);

		if (!exists) {
			continue;
		}

		ENTITY::SET_ENTITY_COORDS(ped, impactCoords.x, impactCoords.y, impactCoords.z, 0, 0, 0, 0);
	}
}

void EffectCantStopJumping::OnTick() {
	if (TimerTick(1000)) {
		auto const playerPed = PLAYER::PLAYER_PED_ID();

		AI::TASK_JUMP(playerPed, 1);
	}
}


void EffectTeleportAFewMeters::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const EntityCoords = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	auto const RandomX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-5, 5);
	auto const RandomY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-5, 5);

	ENTITY::SET_ENTITY_COORDS(playerPed, EntityCoords.x + RandomX, EntityCoords.y + RandomY, EntityCoords.z, false, false, false, false);
}

void EffectSetPlayerMaxStats::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	auto const healthIndex = 0;
	auto const staminaIndex = 1;
	auto const deadeyeIndex = 2;
	auto const maxStats = 100;

	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, healthIndex, maxStats);
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, staminaIndex, maxStats);
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, deadeyeIndex, maxStats);
}

void EffectSetPlayerMidStats::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	auto const healthIndex = 0;
	auto const staminaIndex = 1;
	auto const deadeyeIndex = 2;
	auto const maxStats = 50;

	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, healthIndex, maxStats);
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, staminaIndex, maxStats);
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, deadeyeIndex, maxStats);
}

void EffectSetPlayerMinStats::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	auto const healthIndex = 0;
	auto const staminaIndex = 1;
	auto const deadeyeIndex = 2;
	auto const maxStats = 25;

	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, healthIndex, maxStats);
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, staminaIndex, maxStats);
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, deadeyeIndex, maxStats);
}

void EffectFakeCrash::OnActivate() {
	WAIT(2500);
	Sleep(1000);
	WAIT(250);
	Sleep(1000);
	WAIT(250);
	Sleep(6000);
}

void EffectOneBulletReload::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isShooting = PED::IS_PED_SHOOTING(playerPed);

	if (!isShooting) {
		return;
	}

	Hash weaponHash;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, 0, 0, 0);

	WEAPON::SET_AMMO_IN_CLIP(playerPed, weaponHash, 0);
}


void EffectExtremeSnow::OnActivate() {
	static auto constexpr const heavey_snow = 0x2b402288;

	GAMEPLAY::SET_WEATHER_TYPE(heavey_snow, 0, 1, 0, 0.0, 0);
	GRAPHICS::_SET_SNOW_COVERAGE_TYPE(0);
}

void EffectBoop::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerMount = PED::GET_MOUNT(playerPed);
	auto const isPlayerInVehicle = PED::IS_PED_ON_MOUNT(playerPed);

	if (!isPlayerInVehicle) {
		return;
	}

	PED::AGITATE_HORSE(playerMount, true);

	auto const mountCoords = ENTITY::GET_ENTITY_COORDS(playerMount, 1, 0);

	FIRE::_START_SCRIPT_FIRE(mountCoords.x, mountCoords.y, mountCoords.z, 2, 0.f, false, "INTERIOR_FIRE_SMALL_SOUNDSET", -1.f, 8);
}

void EffectSpawnEvilClone::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerHeading = ENTITY::GET_ENTITY_HEADING(playerPed);

	auto const evilPed = PED::CLONE_PED(playerPed, playerHeading, false, false);

	MarkPedAsEnemy(evilPed);
}

void EffectEveryoneLosesTheirGun::OnActivate() {
	auto peds = GetNearbyPeds(50);

	for (auto const& ped : peds) {
		WEAPON::REMOVE_ALL_PED_WEAPONS(ped, false, true);
	}
}

void EffectLumbago::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	AUDIO::SET_PED_IS_DRUNK(playerPed, true);

	PED::_SET_PED_DRUNKNESS(playerPed, true, 10.f);

	GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
}

void EffectLumbago::OnDeactivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	PED::_SET_PED_DRUNKNESS(playerPed, true, 0.f);
	AUDIO::SET_PED_IS_DRUNK(playerPed, false);
}

void EffectHotHorses::OnTick() {
	static std::array<std::uint32_t, 108> horseHashes = {
		 0xEA523E18, 0x69A37A7B, 0x8AF8EE20, 0xE52CB9B2, 0x6ADB82FE,
		 0x9BE270D3, 0xB57D0193, 0xED07737A, 0x0348B323, 0xE4AD6760,
		 0xE57FC660, 0x2A100154, 0x2C80A080, 0xC2B8CE6B, 0x7EF6A7DC,
		 0xC2A67972, 0x2405C422, 0xBC030D85, 0xA353367A, 0x88D6A59E,
		 0x05052866, 0x5933FD24, 0xA52D4FC0, 0xE7F3880C, 0x5DFCD1F9,
		 0xC8DA3400, 0xA3C3F4C6, 0x8739A629, 0xDA23037A, 0xDD04A33F,
		 0x37DD4055, 0x20C6D093, 0x28F9976A, 0x33598622, 0x5EF3CBDA,
		 0xAF2695EE, 0x970E1781, 0xDF55F5E6, 0x6B54E5D1, 0xAD14C46D,
		 0xD977CC20, 0xB998E803, 0x9E19AA66, 0xA762AEDD, 0x43F0DC62,
		 0xC132BAD0, 0xC7DE4819, 0xBF5D6994, 0xDDAE9AEA, 0x9997DF40,
		 0x3A5BC787, 0x68F5058D, 0x1165B6EB, 0xCF246898, 0x65A30467,
		 0x8EF089E3, 0xFB55A30A, 0x8504B2AA, 0xF1430568, 0xA5A0532E,
		 0xB49928F8, 0x78B24176, 0x651B47C7, 0xB0004639, 0xE6EE2A0B,
		 0xBB31267C, 0x790B9F4B, 0x4955CBE3, 0xC21AB789, 0xC0A1CE3D,
		 0x05C70C99, 0x30331B80, 0x36AE742C, 0xC97A99C6, 0xDC4D3F6B,
		 0x1C8CC068, 0xB9A41AA7, 0x029CBA4A, 0x7E4DF66E, 0x7FE4BEC5,
		 0x0660E640, 0xB4CA3CB2, 0x3F8A66B8, 0x0225752B, 0x2FD9844A,
		 0x9B099788, 0xA0A6C640, 0x3FE5B95B, 0x400B3937, 0xFAE16B63,
		 0x9C978CB3, 0x3E85EE41, 0x1A9FA880, 0xD4A3E715, 0x7E67718B,
		 0x8D4BE5DE, 0xE0A34BD3, 0x6EF6C345, 0x35A71C98, 0x4394FBA4,
		 0x6572D46D, 0xA06225BC, 0xF31B7859, 0xB6A7CE35, 0x23685521
	};

	auto nearby = GetNearbyPeds(45);

	for (auto const& ped : nearby) {
		auto const pedModel = ENTITY::GET_ENTITY_MODEL(ped);

		if (std::ranges::any_of(horseHashes, [pedModel](std::uint32_t hash) { return hash == pedModel; })) {
			auto const coords = ENTITY::GET_ENTITY_COORDS(ped, 1, 0);
			FIRE::_START_SCRIPT_FIRE(coords.x, coords.y, coords.z, 2, 0.f, false, "INTERIOR_FIRE_SMALL_SOUNDSET", -1.f, 8);
		}
	}
}


void EffectTriggerFinger::OnTick() {
	static auto const constexpr INPUT_ATTACK = 0x07ce1e61;

	auto const playerPed = PLAYER::PLAYER_PED_ID();

	if (CONTROLS::IS_CONTROL_PRESSED(0, INPUT_ATTACK)) {
		PED::_SHOOT_TRIGGER_AT_COORDS(playerPed, 0, 0, 0, 0, 0, 0, -1.f);
	}
}

void EffectKnifeOnly::OnTick() {
	auto peds = GetNearbyPeds(50);

	static auto const constexpr knifeModel = 0xdb21ac8c;

	for (auto const& ped : peds) {
		WEAPON::REMOVE_ALL_PED_WEAPONS(ped, false, true);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(ped, knifeModel, 0, 1, 0);
		WEAPON::SET_CURRENT_PED_WEAPON(ped, knifeModel, 1, 0, 0, 0);
	}

	auto const playerPed = PLAYER::PLAYER_PED_ID();

	WEAPON::REMOVE_ALL_PED_WEAPONS(playerPed, false, true);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, knifeModel, 0, 1, 0);
	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, knifeModel, 1, 0, 0, 0);
}

void EffectExplosiveMelee::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const combatCheck = PED::IS_PED_IN_MELEE_COMBAT(playerPed);

	if (combatCheck) {
		auto const enemy = PED::GET_MELEE_TARGET_FOR_PED(playerPed);
		auto const enemyCoords = ENTITY::GET_ENTITY_COORDS(enemy, true, false);

		PED::SET_PED_CAN_RAGDOLL(playerPed, false);

		WAIT(500);
		FIRE::ADD_OWNED_EXPLOSION(playerPed, enemyCoords.x, enemyCoords.y, enemyCoords.z, 12, 10.0f, true, false, 0.5f);
	}
	else if (!combatCheck) {
		PED::SET_PED_CAN_RAGDOLL(playerPed, true);
	}
}

void EffectWeatherChangeOnKill::OnTick() {
	auto const playerId = PLAYER::PLAYER_ID();
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isShooting = PED::IS_PED_SHOOTING(playerPed);

	if (!isShooting) {
		return;
	}

	Entity entity{};

	PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(playerId, &entity);

	if (!entity) {
		return;
	}

	auto const isPedDying = PED::IS_PED_DEAD_OR_DYING(entity, 1);
	auto const isPedDying2 = PED::IS_PED_BEING_STEALTH_KILLED(entity);

	if (isPedDying || isPedDying2) {
		auto const weatherHash = Effect::weatherHashes[rand() % Effect::weatherHashes.size()];

		GAMEPLAY::CLEAR_OVERRIDE_WEATHER();
		GAMEPLAY::SET_WEATHER_TYPE(weatherHash, 0, 1, 0, 0.0, 0);
		GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST();
	}
}

void EffectTurnIntoAGiant::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_SCALE(playerPed, 2.f);
}

void EffectTurnIntoAGiant::OnDeactivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_SCALE(playerPed, 1.f);
}

void EffectWinnieThePooh::OnActivate() {
	auto const legendaryBearModel = 0xDF251C39;
	SpawnPedAroundPlayer(legendaryBearModel, false, false);
}

void EffectMaritime::OnActivate() {
	static std::array<std::uint32_t, 15> boatModels = { 0xEF91537F, 0x75BDDBD6, 0x9FD6BA58, 0xE84E6B74, 0xF097BC6C, 0xDADC0B67, 0xF539E5A0, 0x578D6513, 0xAE057F07, 0x5E56769C, 0xCFD1449, 0x876E6EB7, 0x427A2D4C, 0x7DD49B09, 0xA385E1C7 };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> dist(0, boatModels.size() - 1);

	auto const randomBoat = boatModels[dist(gen)];
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	STREAMING::REQUEST_MODEL(randomBoat, true);

	while (!STREAMING::HAS_MODEL_LOADED(randomBoat)) {
		WAIT(0);
	}

	VEHICLE::CREATE_VEHICLE(randomBoat, location.x, location.y, location.z, 0.0f, 1, 0, 0, 0);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(randomBoat);
}

void EffectDecideOnOutfit::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	std::random_device rd_0;
	std::mt19937 gen_0(rd_0());
	std::uniform_int_distribution<std::size_t> dist_0(0, 58);

	auto outfitId = dist_0(gen_0);

	if (outfitId == 25 || outfitId == 17 || outfitId == 14 || outfitId == 28)
	{
		outfitId = 0;
	}

	PED::_SET_PED_OUTFIT_INDEX(playerPed, outfitId, false);
}

void EffectSnakeRain::OnTick() {
	if (TimerTick(1500)) {
		auto const snake = 0x207D15FA;
		auto const playerId = PLAYER::PLAYER_PED_ID();
		auto const location = ENTITY::GET_ENTITY_COORDS(playerId, true, false);
		auto const randomX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-5, 5);
		auto const randomY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-5, 5);
		PED::CREATE_PED(snake, location.x + randomY, location.y + randomX, location.z + 5, 0, true, true, true, true);
		SpawnPedAroundPlayer(snake, false, false);
	}
}


void EffectTurnHorsesIntoDogs::OnActivate() {
	static std::array<std::uint32_t, 14> dogHashes = {
		0x40E01848, 0xAE6C236C, 0x2552B009, 0xC25FE171, 0xE8C446CB,
		0x40D2BCBC, 0xC5C5D255, 0x801131EF, 0x62F7C1B3, 0xAD779EB4,
		0xCA89FC80, 0x40CAC0E7, 0x5EDF32B4, 0x3B313FCE
	};

	static std::array<std::uint32_t, 105> horseHashes = {
		0xEA523E18, 0x69A37A7B, 0x8AF8EE20, 0xE52CB9B2, 0x6ADB82FE,
		0x9BE270D3, 0xB57D0193, 0xED07737A, 0x0348B323, 0xE4AD6760,
		0xE57FC660, 0x2A100154, 0x2C80A080, 0xC2B8CE6B, 0x7EF6A7DC,
		0xC2A67972, 0x2405C422, 0xBC030D85, 0xA353367A, 0x88D6A59E,
		0x05052866, 0x5933FD24, 0xA52D4FC0, 0xE7F3880C, 0x5DFCD1F9,
		0xC8DA3400, 0xA3C3F4C6, 0x8739A629, 0xDA23037A, 0xDD04A33F,
		0x37DD4055, 0x20C6D093, 0x28F9976A, 0x33598622, 0x5EF3CBDA,
		0xAF2695EE, 0x970E1781, 0xDF55F5E6, 0x6B54E5D1, 0xAD14C46D,
		0xD977CC20, 0xB998E803, 0x9E19AA66, 0xA762AEDD, 0x43F0DC62,
		0xC132BAD0, 0xC7DE4819, 0xBF5D6994, 0xDDAE9AEA, 0x9997DF40,
		0x3A5BC787, 0x68F5058D, 0x1165B6EB, 0xCF246898, 0x65A30467,
		0x8EF089E3, 0xFB55A30A, 0x8504B2AA, 0xF1430568, 0xA5A0532E,
		0xB49928F8, 0x78B24176, 0x651B47C7, 0xB0004639, 0xE6EE2A0B,
		0xBB31267C, 0x790B9F4B, 0x4955CBE3, 0xC21AB789, 0xC0A1CE3D,
		0x05C70C99, 0x30331B80, 0x36AE742C, 0xC97A99C6, 0xDC4D3F6B,
		0x1C8CC068, 0xB9A41AA7, 0x029CBA4A, 0x7E4DF66E, 0x7FE4BEC5,
		0x0660E640, 0xB4CA3CB2, 0x3F8A66B8, 0x0225752B, 0x2FD9844A,
		0x9B099788, 0xA0A6C640, 0x3FE5B95B, 0x400B3937, 0xFAE16B63,
		0x9C978CB3, 0x3E85EE41, 0x1A9FA880, 0xD4A3E715, 0x7E67718B,
		0x8D4BE5DE, 0xE0A34BD3, 0x6EF6C345, 0x35A71C98, 0x4394FBA4,
		0x6572D46D, 0xA06225BC, 0xF31B7859, 0xB6A7CE35, 0x23685521
	};

	auto nearby = GetNearbyPeds(45);

	for (auto& ped : nearby) {
		auto const pedModel = ENTITY::GET_ENTITY_MODEL(ped);

		if (std::ranges::any_of(horseHashes, [pedModel](std::uint32_t hash) { return hash == pedModel; })) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<std::size_t> dist(0, dogHashes.size() - 1);

			auto const randomDog = dogHashes[dist(gen)];
			auto const coords = ENTITY::GET_ENTITY_COORDS(ped, true, false);
			auto const heading = ENTITY::GET_ENTITY_HEADING(ped);

			STREAMING::REQUEST_MODEL(randomDog, true);

			while (!STREAMING::HAS_MODEL_LOADED(randomDog)) {
				WAIT(0);
			}

			auto const dogPed = PED::CREATE_PED(randomDog, coords.x, coords.y, coords.z, heading, 1, false, false, false);

			DECORATOR::DECOR_SET_INT(dogPed, (char*)"honor_override", 0);

			PED::SET_PED_VISIBLE(dogPed, true);
			PED::SET_PED_HEARING_RANGE(dogPed, 10000.0f);

			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(randomDog);

			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(dogPed, false, false);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ped, true, true);
			ENTITY::DELETE_ENTITY(&ped);
		}
	}
}

void EffectHorseDiesAndResurrects::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerMount = PED::GET_MOUNT(playerPed);
	auto const maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(playerMount, 0);

	PED::APPLY_DAMAGE_TO_PED(playerMount, maxHealth + 1337, 0, 0, 0);

	WAIT(10000);

	PED::RESURRECT_PED(playerMount);
	PED::REVIVE_INJURED_PED(playerMount);

	ENTITY::SET_ENTITY_HEALTH(playerMount, maxHealth, 1);

	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerMount, 1, 0);

}

void EffectDoggoGun::OnTick() {
	static std::array<std::uint32_t, 14> dogModels = {
		  0x40E01848, 0xAE6C236C, 0x2552B009, 0xC25FE171, 0xE8C446CB,
		  0x40D2BCBC, 0xC5C5D255, 0x801131EF, 0x62F7C1B3, 0xAD779EB4,
		  0xCA89FC80, 0x40CAC0E7, 0x5EDF32B4, 0x3B313FCE
	};

	auto const playerPedId = PLAYER::PLAYER_PED_ID();
	auto const horse = 0x69A37A7B;

	auto const isPlayerShooting = PED::IS_PED_SHOOTING(playerPedId);

	if (!isPlayerShooting) {
		return;
	}

	Vector3 bulletCoords;
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPedId, &bulletCoords);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> dist(0, dogModels.size() - 1);

	auto const randomDog = dogModels[dist(gen)];

	STREAMING::REQUEST_MODEL(randomDog, true);

	while (!STREAMING::HAS_MODEL_LOADED(randomDog)) {
		WAIT(0);
	}

	auto const dogPed = PED::CREATE_PED(
		randomDog, bulletCoords.x, bulletCoords.y, bulletCoords.z,
		0, 1, false, false, false
	);

	DECORATOR::DECOR_SET_INT(dogPed, (char*)"honor_override", 0);

	PED::SET_PED_VISIBLE(dogPed, true);
	PED::SET_PED_HEARING_RANGE(dogPed, 10000.0f);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(randomDog);

	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(dogPed, false, false);
}

void EffectSnakeCage::OnActivate() {
	auto const snake = 0x207D15FA;
	auto const cage = 0xD04F216B;
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	PED::CREATE_PED(snake, location.x, location.y, location.z + 1, 0, true, true, true, true);
	OBJECT::CREATE_OBJECT(cage, location.x, location.y, location.z - 4, false, true, false, false, false);
}

void EffectShootHorses::OnTick() {
	static std::array<std::uint32_t, 105> horseModels = {
	0xEA523E18, 0x69A37A7B, 0x8AF8EE20, 0xE52CB9B2, 0x6ADB82FE,
	0x9BE270D3, 0xB57D0193, 0xED07737A, 0x0348B323, 0xE4AD6760,
	0xE57FC660, 0x2A100154, 0x2C80A080, 0xC2B8CE6B, 0x7EF6A7DC,
	0xC2A67972, 0x2405C422, 0xBC030D85, 0xA353367A, 0x88D6A59E,
	0x05052866, 0x5933FD24, 0xA52D4FC0, 0xE7F3880C, 0x5DFCD1F9,
	0xC8DA3400, 0xA3C3F4C6, 0x8739A629, 0xDA23037A, 0xDD04A33F,
	0x37DD4055, 0x20C6D093, 0x28F9976A, 0x33598622, 0x5EF3CBDA,
	0xAF2695EE, 0x970E1781, 0xDF55F5E6, 0x6B54E5D1, 0xAD14C46D,
	0xD977CC20, 0xB998E803, 0x9E19AA66, 0xA762AEDD, 0x43F0DC62,
	0xC132BAD0, 0xC7DE4819, 0xBF5D6994, 0xDDAE9AEA, 0x9997DF40,
	0x3A5BC787, 0x68F5058D, 0x1165B6EB, 0xCF246898, 0x65A30467,
	0x8EF089E3, 0xFB55A30A, 0x8504B2AA, 0xF1430568, 0xA5A0532E,
	0xB49928F8, 0x78B24176, 0x651B47C7, 0xB0004639, 0xE6EE2A0B,
	0xBB31267C, 0x790B9F4B, 0x4955CBE3, 0xC21AB789, 0xC0A1CE3D,
	0x05C70C99, 0x30331B80, 0x36AE742C, 0xC97A99C6, 0xDC4D3F6B,
	0x1C8CC068, 0xB9A41AA7, 0x029CBA4A, 0x7E4DF66E, 0x7FE4BEC5,
	0x0660E640, 0xB4CA3CB2, 0x3F8A66B8, 0x0225752B, 0x2FD9844A,
	0x9B099788, 0xA0A6C640, 0x3FE5B95B, 0x400B3937, 0xFAE16B63,
	0x9C978CB3, 0x3E85EE41, 0x1A9FA880, 0xD4A3E715, 0x7E67718B,
	0x8D4BE5DE, 0xE0A34BD3, 0x6EF6C345, 0x35A71C98, 0x4394FBA4,
	0x6572D46D, 0xA06225BC, 0xF31B7859, 0xB6A7CE35, 0x23685521
	};

	auto const playerPedId = PLAYER::PLAYER_PED_ID();
	auto const isPlayerShooting = PED::IS_PED_SHOOTING(playerPedId);

	if (!isPlayerShooting) {
		return;
	}

	Vector3 bulletCoords;
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPedId, &bulletCoords);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> dist(0, horseModels.size() - 1);

	auto const randomHorse = horseModels[dist(gen)];

	STREAMING::REQUEST_MODEL(randomHorse, true);

	while (!STREAMING::HAS_MODEL_LOADED(randomHorse)) {
		WAIT(0);
	}

	auto const horsePed = PED::CREATE_PED(
		randomHorse, bulletCoords.x, bulletCoords.y, bulletCoords.z,
		0, 1, false, false, false
	);

	DECORATOR::DECOR_SET_INT(horsePed, (char*)"honor_override", 0);

	PED::SET_PED_VISIBLE(horsePed, true);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(randomHorse);

}

void EffectRevengeIsAFoolsGame::OnActivate() {
	static auto const constexpr knifeModel = 0xdb21ac8c;

	auto const micahModel = GAMEPLAY::GET_HASH_KEY(const_cast<char*>("CS_MicahBell"));
	auto const micah = SpawnPedAroundPlayer(micahModel, false, false);

	MarkPedAsEnemy(micah);

	ENTITY::SET_ENTITY_PROOFS(micah, 1, 1);
	ENTITY::SET_ENTITY_HEALTH(micah, 10000, 0);
	ENTITY::SET_ENTITY_INVINCIBLE(micah, true);

	WEAPON::REMOVE_ALL_PED_WEAPONS(micah, false, true);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(micah, knifeModel, 0, 1, 0);
	WEAPON::SET_CURRENT_PED_WEAPON(micah, knifeModel, 1, 0, 0, 0);
}

void EffectFullyDirty::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);

	Hash weaponHash;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, 0, 0, 0);

	ATTRIBUTE::SET_ATTRIBUTE_POINTS(playerPed, 16, 1);
	VEHICLE::SET_VEHICLE_DIRT_LEVEL(playerVehicle, 1);
	WEAPON::_SET_WEAPON_DIRT(weaponHash, 1.f, 0);

}

void EffectScrawnyNag::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isPedOnMount = PED::IS_PED_ON_MOUNT(playerPed);
	auto playerMount = PED::GET_MOUNT(playerPed);

	auto const scrawnyNag = SpawnPedAroundPlayer(0x5052866, false, false); // todo; find the correct ped model for "scrawny nag"

	PLAYER::_SET_PLAYER_OWNS_MOUNT(playerPed, scrawnyNag);

	if (!playerMount) {
		return;
	}

	auto const playerMountCoords = ENTITY::GET_ENTITY_COORDS(playerMount, true, 0);
	auto const playerMountHeading = ENTITY::GET_ENTITY_HEADING(playerMount);

	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerMount, 0, 0);
	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed, 0, 0);

	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(playerMount, 0, 0);
	ENTITY::SET_ENTITY_VISIBLE(playerMount, false);

	if (isPedOnMount) {
		AI::TASK_MOUNT_ANIMAL(playerPed, scrawnyNag, 1, -1, -1, 1, 0, 0);
	}

	WAIT(2000);

	ENTITY::SET_ENTITY_VISIBLE(playerPed, true);
	ENTITY::SET_ENTITY_COORDS(playerMount, 0, 0, 0, 0, 0, 0, 0);
	ENTITY::DELETE_ENTITY(&playerMount);

	ENTITY::SET_ENTITY_COORDS(scrawnyNag, playerMountCoords.x, playerMountCoords.y, playerMountCoords.z, 0, 0, 0, 0);
	ENTITY::SET_ENTITY_HEADING(scrawnyNag, playerMountHeading);
}

void EffectWilliamsRedemption::OnActivate() {
	static auto const constexpr dynamite = 0xa64daa5e;
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	WEAPON::REMOVE_ALL_PED_WEAPONS(playerPed, false, true);

	for (int _ : std::ranges::iota_view{ 0, 5 }) { 
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, dynamite, 9, true, 0);
	}
}

void EffectTrot::OnTick() {
	auto static const constexpr INPUT_HORSE_SPRINT = 0x5aa007d7;

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isPedOnMount = PED::IS_PED_ON_MOUNT(playerPed);

	if (!isPedOnMount) {
		return;
	}

	CONTROLS::DISABLE_CONTROL_ACTION(0, INPUT_HORSE_SPRINT, true);
}

void EffectTrot::OnDeactivate() {
	auto static const constexpr INPUT_HORSE_SPRINT = 0x5aa007d7;
	CONTROLS::ENABLE_CONTROL_ACTION(0, INPUT_HORSE_SPRINT, true);
}

void EffectGiveOneRandomWeaponForEachSlot::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	static std::array<std::uint32_t, 10> oneWeaponForEachGroup = {
		GET_HASH("WEAPON_FISHINGROD"), GET_HASH("WEAPON_REPEATER_HENRY"),
		GET_HASH("WEAPON_LASSO"), GET_HASH("WEAPON_BOW"),
		GET_HASH("WEAPON_RIFLE_BOLTACTION"), GET_HASH("WEAPON_SHOTGUN_DOUBLEBARREL"),
		GET_HASH("WEAPON_MELEE_CLEAVER"), GET_HASH("WEAPON_MELEE_KNIFE_JAWBONE"),
		GET_HASH("WEAPON_PISTOL_SEMIAUTO"), GET_HASH("WEAPON_REVOLVER_LEMAT")
	};

	WEAPON::REMOVE_ALL_PED_WEAPONS(playerPed, false, true);

	for (auto const weapon : oneWeaponForEachGroup) {
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, weapon, 9999, true, 0);
	}
}

void EffectHillBillyTurf::OnActivate() {
	auto const static brayModel = GAMEPLAY::GET_HASH_KEY(const_cast<char*>("A_M_M_BtcHillbilly_01"));
	auto const static tammyModel = GAMEPLAY::GET_HASH_KEY(const_cast<char*>("A_F_M_BtcHillbilly_01"));

	auto const bray = SpawnPedAroundPlayer(brayModel, false, false);
	auto const tammy = SpawnPedAroundPlayer(tammyModel, false, false);

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);
	auto const offsettedX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-20, 20);
	auto const offsettedY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-20, 20);

	ENTITY::SET_ENTITY_COORDS(
		bray,
		playerCoords.x + offsettedX,
		playerCoords.y + offsettedY,
		playerCoords.z,
		0, 0, 0, 0
	);

	ENTITY::SET_ENTITY_COORDS(
		tammy,
		playerCoords.x + offsettedX,
		playerCoords.y + offsettedY,
		playerCoords.z,
		0, 0, 0, 0
	);

	MarkPedAsEnemy(bray);
	MarkPedAsEnemy(tammy);

	auto const static shotgunModel = 0x6dfa071b;

	WEAPON::REMOVE_ALL_PED_WEAPONS(bray, false, true);
	WEAPON::REMOVE_ALL_PED_WEAPONS(tammy, false, true);

	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(bray, shotgunModel, 0, 1, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(tammy, shotgunModel, 0, 1, 0);
	// Spawns the hillbilly couple, both have shotguns and will kill anything and everyone in the area
}

void EffectRandomClothing::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	int32_t outfitID = rand() % 58;

	if (outfitID == 25 || outfitID == 17 || outfitID == 14 || outfitID == 28)
	{
		outfitID = 0;
	}

	invoke<Void>(0x77FF8D35EEC6BBC4, playerPed, outfitID, false);
}

void EffectPonziScheme::OnTick() {
	if (TimerTick(250)) {
		auto const randomAmount = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1000, 10000);
		CASH::_MONEY_INCREMENT_CASH_BALANCE(randomAmount, 0x2CD419DC);
	}
}

void EffectExplosiveAmmo::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isShooting = PED::IS_PED_SHOOTING(playerPed);

	if (!isShooting) {
		return;
	}

	Vector3 impactCoords{};

	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &impactCoords);

	FIRE::ADD_EXPLOSION(impactCoords.x, impactCoords.y, impactCoords.z, 0, 1000, 1, 0, 1);
}

void EffectFakeMoney::OnTick() {

	CASH::_MONEY_INCREMENT_CASH_BALANCE(100, 0x2CD419DC);
	if (TimerTick(500)) {
		CASH::_MONEY_DECREMENT_CASH_BALANCE(100);
	}
}

void EffectIHaveAPlan::OnActivate() {

	SetPlayerModel("CS_dutch", &oldSkin1, &oldSkin2);

}

void EffectIHaveAPlan::OnDeactivate() {
	ResetPlayerModel(oldSkin1, oldSkin2);
}

void EffectThisIsntTahiti::OnActivate() {
	auto const static guarmaCoords = Vector3(1997.57, -4499.807, 41.77455);
	auto const static dutchModel = GAMEPLAY::GET_HASH_KEY(const_cast<char*>("CS_dutch"));

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0, 0);

	ENTITY::SET_ENTITY_COORDS(playerPed, guarmaCoords.x, guarmaCoords.y, guarmaCoords.z, 0, 0, 0, 0);

	auto dutch = SpawnPedAroundPlayer(dutchModel, false, false);

	WAIT(10000);

	ENTITY::SET_ENTITY_COORDS(playerPed, playerCoords.x, playerCoords.y, playerCoords.z, 0, 0, 0, 0);
	
}

void EffectFastestInTheWest::OnTick() {
	auto const static constexpr INPUT_FRONTEND_ACCEPT = 0xc7b5340a;

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerOnMount = PED::IS_PED_ON_MOUNT(playerPed);
	auto const playerMount = PED::GET_MOUNT(playerPed);
	auto const shouldRun = GetAsyncKeyState(VK_SHIFT);

	if (shouldRun) {
		ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(playerOnMount ? playerMount : playerPed, 1, 0.f, 5, 0.f, 0, 1, 1, 1);
	}
}

void EffectTenXMovementSpeedOnFoot::OnTick() {
	auto const static constexpr INPUT_FRONTEND_ACCEPT = 0xc7b5340a;

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const shouldRun = GetAsyncKeyState(VK_SHIFT);

	if (shouldRun) {
		ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(playerPed, 1, 0.f, 10, 0.f, 0, 1, 1, 1);
	}
}

void EffectGrandTheftHorses::OnActivate() 
{
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerMount = PED::GET_MOUNT(playerPed);

	auto const model = GAMEPLAY::GET_HASH_KEY((char*)"s_m_m_army_01");
	auto const HorseStealer = SpawnPedAroundPlayer(model);

	invoke<Void>(0x028F76B6E78246EB, playerPed, playerMount, 0, true);
	invoke<Void>(0x028F76B6E78246EB, HorseStealer, playerMount, -1, true);

	auto const mountCoords = ENTITY::GET_ENTITY_COORDS(playerMount, 1, 0);

	FIRE::_START_SCRIPT_FIRE(mountCoords.x, mountCoords.y, mountCoords.z, 2, 0.f, false, "INTERIOR_FIRE_SMALL_SOUNDSET", -1.f, 8);
}

void EffectAllExplosives::OnActivate() 
{
	static std::array<std::uint32_t, 2> explosives[] = { 0x7067e7a7, 0xa64daa5e };

	auto const playerPed = PLAYER::PLAYER_PED_ID();

	for (auto explosive : explosives) {
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, explosive[0], 9, true, 0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, explosive[1], 9, true, 0);
	}
}

void EffectSwapPlaces::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerOnMount = PED::IS_PED_ON_MOUNT(playerPed);
	auto const playerMount = PED::GET_MOUNT(playerPed);

	if (!playerOnMount) {
		return;
	}

	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed, 0, 0);
	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerMount, 0, 0);

	AI::TASK_MOUNT_ANIMAL(playerMount, playerPed, 1, -1, -1, 1, 0, 0);
}



void EffectPaino::OnActivate() 
{
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
	auto const pianoHash = 0x4D6B282C;
	auto const piano = OBJECT::CREATE_OBJECT(pianoHash, location.x, location.y, location.z + 20, false, true, true, false, false);
	ENTITY::SET_ENTITY_VELOCITY(piano, 0, 0, -20);
}


static std::int32_t GetCage() {
	static std::int32_t cage;
	
	if (!cage) {
		auto const playerPed = PLAYER::PLAYER_PED_ID();
		auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
		cage = OBJECT::CREATE_OBJECT(0xD04F216B, location.x, location.y, location.z - 10, 1, 1, 1, 0, 1);
	}

	return cage;
}
void EffectWalkOnWater::OnTick() 
{
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
	auto const inWater = ENTITY::IS_ENTITY_IN_WATER(playerPed);
	auto const playerRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
	
	if (inWater) {
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(GetCage());
		ENTITY::SET_ENTITY_COORDS(GetCage(), location.x, location.y, location.z - 3.3, false, false, false, false);
		ENTITY::SET_ENTITY_ROTATION(GetCage(), playerRot.x, playerRot.y, playerRot.z, 0, false);
		ENTITY::SET_ENTITY_ALPHA(GetCage(), 0, 0);
	}
}

void EffectTrain::OnActivate() 
{
	std::int32_t selectedTrain{};

	auto vehicles = GetNearbyVehs(100);

	for (auto const& vehicle : vehicles) {
		auto const vehicleModel = ENTITY::GET_ENTITY_MODEL(vehicle);
		auto const isTrain = VEHICLE::IS_THIS_MODEL_A_TRAIN(vehicleModel);

		if (isTrain) {
			selectedTrain = vehicle;
			break;
		}
	}

	if (!selectedTrain) {
		return;
	}

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const trainCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(selectedTrain, 0, 1, 0);

	ENTITY::SET_ENTITY_COORDS(playerPed, trainCoords.x, trainCoords.y, trainCoords.z, 0, 5, 0, 0);
}

void EffectBackgroundWar::OnActivate() {
	

	static std::array<std::uint32_t, 3> nativeAmericanModels = {
		 GET_HASH("MSP_NATIVE1_MALES_01"),
		 GET_HASH("RCSP_NATIVE_AMERICANFATHERS_MALES_01"),
		 GET_HASH("RCSP_NATIVE1S2_MALES_01")
	};

	static std::array<std::uint32_t, 3> militaryModels = {
		GET_HASH("S_M_M_Army_01"),
		GET_HASH("S_M_M_Army_01"),
		GET_HASH("S_M_Y_Army_01")
	};

	static constexpr auto bowModel = 0x88a8505c;
	static constexpr auto rifleModel = 0x63f46de6;

	const auto playerPed = PLAYER::PLAYER_PED_ID();

	auto nativeAmericanCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, -25, 0);
	auto militaryCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 5, 0);

	for (int _ : std::ranges::iota_view{ 0, 4 }) {
		for (auto const& model : nativeAmericanModels) {
			auto nativePed = SpawnPedAroundPlayer(model, false, false);
			ENTITY::SET_ENTITY_COORDS(nativePed, nativeAmericanCoords.x, nativeAmericanCoords.y, nativeAmericanCoords.z, 0, 0, 0, 0);
			MarkPedAsEnemy(nativePed);
			WEAPON::REMOVE_ALL_PED_WEAPONS(nativePed, false, true);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(nativePed, bowModel, 0, 1, 0);
			nativeAmericanCoords.x += 1;
		}
	}

	for (int _ : std::ranges::iota_view{ 0, 3 }) {
		for (auto const& model : militaryModels) {
			auto armyPed = SpawnPedAroundPlayer(model, false, false);
			ENTITY::SET_ENTITY_COORDS(armyPed, militaryCoords.x, militaryCoords.y, militaryCoords.z, 0, 0, 0, 0);
			MarkPedAsCompanion(armyPed);
			WEAPON::REMOVE_ALL_PED_WEAPONS(armyPed, false, true);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(armyPed, rifleModel, 0, 1, 0);
			militaryCoords.x += 1;
		}
	}
}

void EffectSpawnNightFolk::OnActivate() {
	

	static std::array<std::uint32_t, 3> nightFolkModels = { GET_HASH("CS_SwampFreak"), GET_HASH("CS_SWAMPWEIRDOSONNY"), GET_HASH("G_M_M_UNISWAMP_01") };

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 5, 0);

	for (auto const& model : nightFolkModels) {
		auto const nightFolk = SpawnPedAroundPlayer(model, 0, 0);

		ENTITY::SET_ENTITY_COORDS(nightFolk, playerCoords.x, playerCoords.y, playerCoords.z, 0, 0, 0, 0);

		MarkPedAsEnemy(nightFolk);
	}
}

void EffectGoldRush::OnActivate() {
	

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	auto const gold = 0x5F9DA261;

	OBJECT::CREATE_OBJECT(gold, location.x + 2, location.y, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x - 2, location.y, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x, location.y + 2, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x, location.y - 2, location.z - 1, true, false, false, false, false);

	OBJECT::CREATE_OBJECT(gold, location.x + 3, location.y, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x - 3, location.y, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x, location.y + 3, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x, location.y - 3, location.z - 1, true, false, false, false, false);

	OBJECT::CREATE_OBJECT(gold, location.x + 4, location.y, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x - 4, location.y, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x, location.y + 4, location.z - 1, true, false, false, false, false);
	OBJECT::CREATE_OBJECT(gold, location.x, location.y - 4, location.z - 1, true, false, false, false, false);
}

void EffectCampingTime::OnActivate() {
	

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	auto const campfire = 0xAD21120D;
	OBJECT::CREATE_OBJECT(campfire, location.x + 5, location.y + 5, location.z - 1.2, true, false, false, false, false);

	auto const tent = 0x5A8F10BD;
	OBJECT::CREATE_OBJECT(tent, location.x + 8, location.y + 8, location.z - 1, true, false, false, false, false);
}

void EffectSpawnCannon::OnActivate() {
	

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);
	auto const object = 0x00E03ACE;
	auto const cannon = SpawnObject(object);

	ENTITY::SET_ENTITY_COORDS(cannon, location.x, location.y, location.z - 1, false, false, false, false);
}

void EffectRockyRain::OnTick() {
	

	static std::array<std::uint32_t, 2> rockModels = { GET_HASH("old_hen_rock_scree_sim_05"), GET_HASH("old_hen_rock_scree_sim_02") };

	auto const playerPedId = PLAYER::PLAYER_PED_ID();

	if (TimerTick(100)) {
		for (auto const& model : rockModels) {
			auto const randomX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-10, 10);
			auto const randomY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-10, 10);

			auto const location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPedId, randomX, randomY, 20);

			auto const rock = SpawnObject(model);

			ENTITY::SET_ENTITY_COORDS(rock, location.x, location.y, location.z, 0, 0, 0, 0);
			ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(rock, 1, 0.f, 0.f, -5.f, 0, 1, 1, 1);
		}
	}
}

void EffectCantDismountHorse::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const vehicle = PED::GET_MOUNT(playerPed);
	auto const vehicleCheck = PED::IS_PED_ON_MOUNT(playerPed);

	if (vehicleCheck) {
		auto const static constexpr GET_OFF_HORSE = 0xcbdb82a8;
		CONTROLS::DISABLE_CONTROL_ACTION(0, GET_OFF_HORSE, true);

		auto const static constexpr EXIT_VEHICLE = 0xfefab9b4;
		CONTROLS::DISABLE_CONTROL_ACTION(0, EXIT_VEHICLE, true);
	}
}

void EffectCantDismountHorse::OnDeactivate() {
	auto const static constexpr GET_OFF_HORSE = 0xcbdb82a8;
	CONTROLS::ENABLE_CONTROL_ACTION(0, GET_OFF_HORSE, true);

	auto const static constexpr EXIT_VEHICLE = 0xfefab9b4;
	CONTROLS::ENABLE_CONTROL_ACTION(0, EXIT_VEHICLE, true);
}

void EffectAnimalsRunAwayFromPlayer::OnTick() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	FIRE::_START_SCRIPT_FIRE(location.x, location.y, location.z + 1, 2, 0.f, false, "INTERIOR_FIRE_SMALL_SOUNDSET", -1.f, 8);
}

void EffectSpawnJohnCompanion::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 5, 0);
	auto const john = SpawnPedAroundPlayer(GET_HASH("CS_johnmarston"), 0, 0);

	ENTITY::SET_ENTITY_COORDS(john, playerCoords.x, playerCoords.y, playerCoords.z, 0, 0, 0, 0);

	MarkPedAsCompanion(john);
}

void EffectRainingFish::OnTick() {
	static std::array<std::uint32_t, 8> fishModels = {
		GET_HASH("A_C_FishSalmonSockeye_01_ms"), GET_HASH("A_C_FishRockBass_01_sm"),
		GET_HASH("A_C_FishRedfinPickerel_01_sm"), GET_HASH("A_C_FishPerch_01_sm"),
		GET_HASH("A_C_FishNorthernPike_01_lg"), GET_HASH("A_C_FishMuskie_01_lg"),
		GET_HASH("A_C_FishLongNoseGar_01_lg"), GET_HASH("A_C_FishLakeSturgeon_01_lg"),
	};

	auto const playerPedId = PLAYER::PLAYER_PED_ID();

	for (auto const& model : fishModels) {
		auto const randomX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-15, 15);
		auto const randomY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-15, 15);

		auto const location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPedId, randomX, randomY, 20);

		auto const fish = SpawnPedAroundPlayer(model);

		ENTITY::SET_ENTITY_COORDS(fish, location.x, location.y, location.z, 0, 0, 0, 0);
		ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(fish, 1, 0.f, 0.f, -5.f, 0, 1, 1, 1);

		WAIT(500);
	}
}

void EffectFireRain::OnTick() {
	if (TimerTick(500)) {
		static const auto constexpr molotovIndex = 24;

		std::random_device rd_0;
		std::mt19937 gen_0(rd_0());
		std::uniform_int_distribution<std::size_t> dist_0(0, 20);

		std::random_device rd_1;
		std::mt19937 gen_1(rd_1());
		std::uniform_int_distribution<std::size_t> dist_1(0, 20);

		auto const playerPed = PLAYER::PLAYER_PED_ID();
		auto const location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, dist_0(gen_0), dist_1(gen_1), 0);

		FIRE::ADD_EXPLOSION(location.x, location.y, location.z, molotovIndex, 1.f, 1, 0, 0.f);
	}
}

void EffectLightningStorm::OnActivate() {
	for (int _ : std::ranges::iota_view{ 0, 50 }) { // we do a little trolling xd
		std::random_device rd_0;
		std::mt19937 gen_0(rd_0());
		std::uniform_int_distribution<std::size_t> dist_0(0, 20);

		std::random_device rd_1;
		std::mt19937 gen_1(rd_1());
		std::uniform_int_distribution<std::size_t> dist_1(0, 20);

		auto const playerPed = PLAYER::PLAYER_PED_ID();
		auto const location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, dist_0(gen_0), dist_1(gen_1), 0);

		GAMEPLAY::FORCE_LIGHTNING_FLASH();
		GAMEPLAY::_FORCE_LIGHTNING_FLASH_AT_COORDS(location.x, location.y, location.z, 1.f);

		WAIT(1);
	}
}

void EffectBurningMicahOnHorse::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 5, 0);

	auto const micah = SpawnPedAroundPlayer(GET_HASH("CS_MicahBell"), 0, 0);
	auto const horse = SpawnPedAroundPlayer(GET_HASH("A_C_Horse_AmericanPaint_SplashedWhite"), 0, 0);

	ENTITY::SET_ENTITY_COORDS(horse, playerCoords.x, playerCoords.y, playerCoords.z, 0, 0, 0, 0);
	ENTITY::SET_ENTITY_COORDS(micah, playerCoords.x, playerCoords.y, playerCoords.z, 0, 0, 0, 0);

	AI::TASK_MOUNT_ANIMAL(micah, horse, 1, -1, -1, 1, 0, 0);

	auto const micaCoords = ENTITY::GET_ENTITY_COORDS(micah, true, false);

	auto const static particleIndicator = const_cast<char*>("scr_net_target_races");
	auto const static particleSub = const_cast<char*>("scr_net_target_fire_ring_mp");
	auto const static particleIndicatorHash = GAMEPLAY::GET_HASH_KEY(particleIndicator);

	for (int _ : std::ranges::iota_view{ 0, 20000 }) { // we do a little trolling xd

		STREAMING::_REQUEST_NAMED_PTFX_ASSET(particleIndicatorHash);
		GRAPHICS::USE_PARTICLE_FX_ASSET(particleIndicator);

		auto const ptfxHandle = GRAPHICS::START_PARTICLE_FX_LOOPED_AT_COORD(
			particleSub,
			micaCoords.x,
			micaCoords.y,
			micaCoords.z,
			0, 0, 0, 2.f, 0, 0, 0, 0
		);

		GRAPHICS::STOP_PARTICLE_FX_LOOPED(ptfxHandle, 0);
		STREAMING::_REMOVE_NAMED_PTFX_ASSET(particleIndicator);
	}
	WAIT(75);
	auto const mountCoords = ENTITY::GET_ENTITY_COORDS(horse, 1, 0);
	FIRE::_START_SCRIPT_FIRE(mountCoords.x, mountCoords.y, mountCoords.z - 0.25, 2, 0.f, false, "INTERIOR_FIRE_SMALL_SOUNDSET", -1.f, 8);
	WAIT(500);
	ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(horse, 1, 0.f, 10, 0.f, 0, 1, 1, 1);
}

void EffectDeathRidesUponAWhiteHorse::OnActivate() {
	static std::array<std::uint32_t, 105> horseModels = {
		0xEA523E18, 0x69A37A7B, 0x8AF8EE20, 0xE52CB9B2, 0x6ADB82FE,
		0x9BE270D3, 0xB57D0193, 0xED07737A, 0x0348B323, 0xE4AD6760,
		0xE57FC660, 0x2A100154, 0x2C80A080, 0xC2B8CE6B, 0x7EF6A7DC,
		0xC2A67972, 0x2405C422, 0xBC030D85, 0xA353367A, 0x88D6A59E,
		0x05052866, 0x5933FD24, 0xA52D4FC0, 0xE7F3880C, 0x5DFCD1F9,
		0xC8DA3400, 0xA3C3F4C6, 0x8739A629, 0xDA23037A, 0xDD04A33F,
		0x37DD4055, 0x20C6D093, 0x28F9976A, 0x33598622, 0x5EF3CBDA,
		0xAF2695EE, 0x970E1781, 0xDF55F5E6, 0x6B54E5D1, 0xAD14C46D,
		0xD977CC20, 0xB998E803, 0x9E19AA66, 0xA762AEDD, 0x43F0DC62,
		0xC132BAD0, 0xC7DE4819, 0xBF5D6994, 0xDDAE9AEA, 0x9997DF40,
		0x3A5BC787, 0x68F5058D, 0x1165B6EB, 0xCF246898, 0x65A30467,
		0x8EF089E3, 0xFB55A30A, 0x8504B2AA, 0xF1430568, 0xA5A0532E,
		0xB49928F8, 0x78B24176, 0x651B47C7, 0xB0004639, 0xE6EE2A0B,
		0xBB31267C, 0x790B9F4B, 0x4955CBE3, 0xC21AB789, 0xC0A1CE3D,
		0x05C70C99, 0x30331B80, 0x36AE742C, 0xC97A99C6, 0xDC4D3F6B,
		0x1C8CC068, 0xB9A41AA7, 0x029CBA4A, 0x7E4DF66E, 0x7FE4BEC5,
		0x0660E640, 0xB4CA3CB2, 0x3F8A66B8, 0x0225752B, 0x2FD9844A,
		0x9B099788, 0xA0A6C640, 0x3FE5B95B, 0x400B3937, 0xFAE16B63,
		0x9C978CB3, 0x3E85EE41, 0x1A9FA880, 0xD4A3E715, 0x7E67718B,
		0x8D4BE5DE, 0xE0A34BD3, 0x6EF6C345, 0x35A71C98, 0x4394FBA4,
		0x6572D46D, 0xA06225BC, 0xF31B7859, 0xB6A7CE35, 0x23685521
	};

	auto nearby = GetNearbyPeds(45);

	for (auto& ped : nearby) {
		auto const pedModel = ENTITY::GET_ENTITY_MODEL(ped);

		if (std::ranges::any_of(horseModels, [pedModel](std::uint32_t hash) { return hash == pedModel; })) {

			auto const horseModel = GET_HASH("A_C_Horse_AmericanPaint_SplashedWhite");
			auto const coords = ENTITY::GET_ENTITY_COORDS(ped, true, false);
			auto const heading = ENTITY::GET_ENTITY_HEADING(ped);

			STREAMING::REQUEST_MODEL(horseModel, true);

			while (!STREAMING::HAS_MODEL_LOADED(horseModel)) {
				WAIT(0);
			}

			auto const horsePed = PED::CREATE_PED(horseModel, coords.x, coords.y, coords.z, heading, 1, false, false, false);

			DECORATOR::DECOR_SET_INT(horsePed, (char*)"honor_override", 0);

			PED::SET_PED_VISIBLE(horsePed, true);
			PED::SET_PED_HEARING_RANGE(horsePed, 10000.0f);

			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(horseModel);

			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(horsePed, false, false);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ped, true, true);
			ENTITY::DELETE_ENTITY(&ped);
		}
	}
	for (auto& ped : nearby) {
		auto const pedModel = ENTITY::GET_ENTITY_MODEL(ped);
		auto const pedIsHuman = PED::IS_PED_HUMAN(ped);

		if (!pedIsHuman) {
			continue;
		}

		auto const nearbyPedCoords = ENTITY::GET_ENTITY_COORDS(ped, true, false);

		ENTITY::SET_ENTITY_COORDS(ped, 0, 0, 0, false, false, false, false);

		auto const newPed = SpawnPedAroundPlayer(GET_HASH("G_M_M_BountyHunters_01"), false, false);

		ENTITY::SET_ENTITY_COORDS(newPed, nearbyPedCoords.x, nearbyPedCoords.y, nearbyPedCoords.z, false, false, false, false);
	}
}

void EffectAimbot::OnTick() {
	auto static const constexpr HEAD_BONE = 0x5226l;
	auto static const constexpr INPUT_ATTACK = 0x07ce1e61;

	auto peds = GetNearbyPeds(69);

	for (auto const& ped : peds) {
		auto const isPedOnScreen = ENTITY::IS_ENTITY_ON_SCREEN(ped);

		auto const playerPed = PLAYER::PLAYER_PED_ID();

		if (!isPedOnScreen) {
			continue;
		}

		auto const isPlayerShooting = PED::IS_PED_SHOOTING(playerPed);

		if (!isPlayerShooting) {
			continue;
		}

		auto const isPedDead = ENTITY::IS_ENTITY_DEAD(ped);

		if (isPedDead) {
			continue;
		}

		auto const pedHeadCoords = PED::GET_PED_BONE_COORDS(ped, HEAD_BONE, 0.f, 0.f, 0.f);
		auto const playerHeadCoords = PED::GET_PED_BONE_COORDS(playerPed, HEAD_BONE, 0.f, 0.f, 0.f);

		Hash weaponHash;
		WEAPON::GET_CURRENT_PED_WEAPON(ped, &weaponHash, false, true, true);

		auto const shotgunHash = 0x31b7b9fe;
		WEAPON::_REQUEST_WEAPON_ASSET(shotgunHash, 0, 0);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pedHeadCoords.x, pedHeadCoords.y + 1, pedHeadCoords.z,
			pedHeadCoords.x, pedHeadCoords.y, pedHeadCoords.z, 1000, 1, shotgunHash, playerPed, 0, 1, 1000.f, 1);

		WEAPON::_REMOVE_WEAPON_ASSET(shotgunHash);
		WAIT(100);
	}
}

void EffectDisableDeadeye::OnTick() {
	auto const static constexpr SPECIAL_ABILITY = 0xcee12b50;
	CONTROLS::DISABLE_CONTROL_ACTION(0, SPECIAL_ABILITY, true);
}


void EffectShootRandomProp::OnTick() {
	static std::array<std::uint32_t, 8> randomItemArray = { GET_HASH("p_chairwicker03x"), GET_HASH("mp004_p_barreltwin01x"), GET_HASH("p_cratetnt01xa"), GET_HASH("p_ammo_cache_01x"), GET_HASH("p_campfirefresh01x"), GET_HASH("p_carcasshorse02x"), GET_HASH("p_cannonwreck01x"), GET_HASH("p_cougar_01x") };

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);
	auto const isPlayerShooting = PED::IS_PED_SHOOTING(playerPed);
	auto const randomItem = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 8);

	if (!isPlayerShooting) {
		return;
	}

	Vector3 weaponCoords;
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &weaponCoords);

	OBJECT::CREATE_OBJECT(randomItemArray[randomItem], weaponCoords.x, weaponCoords.y, weaponCoords.z, true, false, false, false, false);
}

void EffectSpawnSwatTeam::OnActivate() {
	static std::array<std::uint32_t, 5> policeArray = { GET_HASH("S_M_M_AmbientBlWPolice_01"), GET_HASH("S_M_M_AmbientSDPolice_01"), GET_HASH("S_M_M_DispatchLeaderPolice_01"), GET_HASH("S_M_M_DispatchPolice_01"), GET_HASH("U_M_M_SDPoliceChief_01") };

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const location = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);

	auto const randomPoliceOfficer = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, policeArray.size() - 1);

	STREAMING::REQUEST_MODEL(GET_HASH("GATLING_GUN"), false);

	for (auto const police : policeArray) {
		STREAMING::REQUEST_MODEL(police, false);
	}

	for (int _ : std::ranges::iota_view{ 0, 4 }) {
		auto const policeOfficers = SpawnPedAroundPlayer(policeArray[randomPoliceOfficer], false, false);

		ENTITY::SET_ENTITY_COORDS(policeOfficers, location.x + 15, location.y + 4, location.z, false, false, false, false);
		MarkPedAsEnemy(policeOfficers);
	}

	auto const policeGatlingGun = VEHICLE::CREATE_VEHICLE(GET_HASH("GATLING_GUN"), location.x, location.y, location.z, 0, true, false, false, false);
	ENTITY::SET_ENTITY_COORDS(policeGatlingGun, location.x + 12, location.y + 1, location.z, false, false, false, false);

	auto const policeGatlingGunPed = SpawnPedAroundPlayer(policeArray[randomPoliceOfficer], false, false);
	WAIT(500);
	AI::TASK_MOUNT_ANIMAL(policeGatlingGunPed, policeGatlingGun, 1, -1, -1, 1, 0, 0);
	PED::SET_PED_INTO_VEHICLE(policeGatlingGunPed, policeGatlingGun, -1);

	MarkPedAsEnemy(policeGatlingGunPed);
}

void EffectHotAirBalloonMountainDavey::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto playerLocation = ENTITY::GET_ENTITY_COORDS(playerPed, true, 0);

	auto const horseCheck = PED::IS_PED_ON_MOUNT(playerPed);

	if (horseCheck) {
		PED::_REMOVE_PED_FROM_MOUNT(playerPed, false, false);
	}

	WAIT(200);

	playerLocation.z += 2.0f;

	auto const model = GET_HASH("hotAirBalloon01");

	LoadModel(model);
	
	auto const vehicle = VEHICLE::CREATE_VEHICLE(model, playerLocation.x, playerLocation.y, playerLocation.z, rand() % 360,
		false, false, false, false);

	Vehicle vehCopy = vehicle;
	ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&vehCopy);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

	PED::SET_PED_INTO_VEHICLE(playerPed, vehicle, -1);

	Vector3 windDirection = GAMEPLAY::GET_WIND_DIRECTION();

	windDirection.x *= 50.0f;
	windDirection.y *= -50.0f;
	windDirection.z = 25.f;

	WAIT(500);

	ENTITY::SET_ENTITY_COORDS(vehicle, -2124.87, 156.338, 250.137, false, false, false, false);
	WAIT(200);

	ENTITY::SET_ENTITY_VELOCITY(vehicle, windDirection.x, windDirection.y, 25.0f);
}

void EffectVampire::OnActivate() {
	bool isStillVampire{ true };

	auto const effectName = "PlayerDrunk01_PassOut";
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const playerId = PLAYER::PLAYER_ID();

	PLAYER::CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED(playerId);

	GRAPHICS::_ANIMPOSTFX_PLAY_TIMED(effectName, 40000);

	while (isStillVampire) {
		GRAPHICS::_ANIMPOSTFX_SET_POSTFX_COLOR(const_cast<char*>(effectName), 0, 255, 0, 0, 100);

		auto const isPlayerDead = ENTITY::IS_ENTITY_DEAD(playerPed);
		auto const hasPlayerDamagedPed = PLAYER::HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED(playerId);

		if (hasPlayerDamagedPed || isPlayerDead) {
			isStillVampire = false;
			break;
		}

		auto const playerHealth = ENTITY::GET_ENTITY_HEALTH(playerPed);
		ENTITY::SET_ENTITY_HEALTH(playerPed, playerHealth - 10, 0);

		WAIT(500);
	}

	auto const maxPlayerHealth = ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, false);
	ENTITY::SET_ENTITY_HEALTH(playerPed, maxPlayerHealth, 0);

}

void DrawCenterText(char* str, float x, float y) {
	float fX = x / (float)1920;
	float fY = y / (float)1080;

	std::string fmt = std::format("{}{}{}", "<font face='$title'>", str, "</font>");

	UI::SET_TEXT_SCALE(0.f, 4.3f);
	UI::SET_TEXT_COLOR_RGBA(255, 255, 255, 255);
	UI::SET_TEXT_CENTRE(1);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::DRAW_TEXT(GAMEPLAY::CREATE_STRING(10, const_cast<char*>("LITERAL_STRING"), const_cast<char*>(fmt.c_str())), fX, fY);
}

void EffectFakeDeath::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const pedCurrentHealth = ENTITY::GET_ENTITY_HEALTH(playerPed);
	auto const pedOnMount = PED::IS_PED_ON_MOUNT(playerPed);
	auto const maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, 0);
	auto const location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 2, 0);

	std::int32_t playerHorse{};
	float horseCurrentHealth{};

	if (pedOnMount) {
		playerHorse = PED::GET_MOUNT(playerPed);
		horseCurrentHealth = ENTITY::GET_ENTITY_HEALTH(playerHorse);
		auto const maxHealthHorse = ENTITY::GET_ENTITY_MAX_HEALTH(playerHorse, 0);

		ENTITY::SET_ENTITY_HEALTH(playerHorse, maxHealthHorse, 0);
	}

	ENTITY::SET_ENTITY_HEALTH(playerPed, maxHealth, 0);

	GAMEPLAY::FORCE_LIGHTNING_FLASH();
	GAMEPLAY::_FORCE_LIGHTNING_FLASH_AT_COORDS(location.x + 2, location.y, location.z, 1.f);

	WAIT(200);

	UI::DISPLAY_HUD(false);

	GAMEPLAY::SET_TIME_SCALE(0.2f);

	auto const effectName = const_cast<char*>("death01");
	GRAPHICS::_ANIMPOSTFX_PLAY_TIMED(effectName, 5000);
	AUDIO::PLAY_SOUND_FRONTEND(const_cast<char*>("DEATH_SCREEN_ENTER"), const_cast <char*>("DEATH_FAIL_RESPAWN_SOUNDS"), false, false);

	WAIT(5000);

	for (int _ : std::ranges::iota_view{ 0, 250 }) {
		DrawCenterText(const_cast<char*>("~COLOR_PLAYER_STATUS_NEGATIVE~LMAO YOU THOUGHT"), 960, 269);
		WAIT(1);
	}

	AUDIO::PLAY_SOUND_FRONTEND(const_cast<char*>("DEATH_SCREEN_EXIT"), const_cast <char*>("DEATH_FAIL_RESPAWN_SOUNDS"), false, false);

	WAIT(100);

	UI::DISPLAY_HUD(true);
	GAMEPLAY::SET_TIME_SCALE(1.f);
	GRAPHICS::ANIMPOSTFX_STOP(effectName);

	if (pedOnMount) {
		ENTITY::SET_ENTITY_HEALTH(playerHorse, horseCurrentHealth, 0);
	}

	ENTITY::SET_ENTITY_HEALTH(playerPed, pedCurrentHealth, 0);
}

void EffectFakeFakeDeath::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const pedCurrentHealth = ENTITY::GET_ENTITY_HEALTH(playerPed);
	auto const pedOnMount = PED::IS_PED_ON_MOUNT(playerPed);
	auto const maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, 0);
	auto const location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 2, 0);

	std::int32_t playerHorse{};
	float horseCurrentHealth{};

	if (pedOnMount) {
		playerHorse = PED::GET_MOUNT(playerPed);
		horseCurrentHealth = ENTITY::GET_ENTITY_HEALTH(playerHorse);
		auto const maxHealthHorse = ENTITY::GET_ENTITY_MAX_HEALTH(playerHorse, 0);

		ENTITY::SET_ENTITY_HEALTH(playerHorse, maxHealthHorse, 0);
	}

	ENTITY::SET_ENTITY_HEALTH(playerPed, maxHealth, 0);

	GAMEPLAY::FORCE_LIGHTNING_FLASH();
	GAMEPLAY::_FORCE_LIGHTNING_FLASH_AT_COORDS(location.x + 2, location.y, location.z, 1.f);


	WAIT(200);

	UI::DISPLAY_HUD(false);

	GAMEPLAY::SET_TIME_SCALE(0.2f);

	auto const effectName = const_cast<char*>("death01");
	GRAPHICS::_ANIMPOSTFX_PLAY_TIMED(effectName, 5000);
	AUDIO::PLAY_SOUND_FRONTEND(const_cast<char*>("DEATH_SCREEN_ENTER"), const_cast <char*>("DEATH_FAIL_RESPAWN_SOUNDS"), false, false);

	WAIT(5000);

	for (int _ : std::ranges::iota_view{ 0, 250 }) {
		DrawCenterText(const_cast<char*>("~COLOR_PLAYER_STATUS_NEGATIVE~LMAO YOU THOUGHT"), 960, 269);
		WAIT(1);
	}

	AUDIO::PLAY_SOUND_FRONTEND(const_cast<char*>("DEATH_SCREEN_EXIT"), const_cast <char*>("DEATH_FAIL_RESPAWN_SOUNDS"), false, false);

	WAIT(100);

	UI::DISPLAY_HUD(true);
	GAMEPLAY::SET_TIME_SCALE(1.f);
	GRAPHICS::ANIMPOSTFX_STOP(effectName);

	PED::APPLY_DAMAGE_TO_PED(playerPed, 133769420, 0, 0, 0);
}

void EffectSmokeGun::OnTick() {

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const isPlayerShooting = PED::IS_PED_SHOOTING(playerPed);

	if (isPlayerShooting) {

		auto const playerWeapon = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(playerPed, 0);
		auto const weaponCoords = PED::GET_PED_BONE_COORDS(playerPed, 6286, 0, 0, 0);

		auto const static particleIndicator = const_cast<char*>("scr_distance_smoke");
		auto const static particleSub = const_cast<char*>("scr_campfire_distance_smoke_sma");
		auto const static particleIndicatorHash = GAMEPLAY::GET_HASH_KEY(particleIndicator);

		STREAMING::_REQUEST_NAMED_PTFX_ASSET(particleIndicatorHash);
		GRAPHICS::USE_PARTICLE_FX_ASSET(particleIndicator);

		auto const ptfxHandle = GRAPHICS::START_PARTICLE_FX_LOOPED_AT_COORD(
			particleSub,
			weaponCoords.x,
			weaponCoords.y,
			weaponCoords.z - 15,
			0, 0, 0, 0.5f, 0, 0, 0, 0
		);

		GRAPHICS::STOP_PARTICLE_FX_LOOPED(ptfxHandle, 0);
		STREAMING::_REMOVE_NAMED_PTFX_ASSET(particleIndicator);
	}
}

void EffectRandomStrangerEncounter::OnActivate() {
	static std::array<Vector3, 7> strangerLocations{
		Vector3(2955.47, 2219.95, 160.884), Vector3(2596.44, -1003.03, 44.1154),
		Vector3(340.158, -680.321, 42.8093), Vector3(83.399, -245.566, 107.763), 
		Vector3(1551.98, -290.126, 80.677), Vector3(-1385.19, -762.353, 94.0178), 
		Vector3(-2045.33, -1083.43, 108.543) 
	};

	auto const playerPed = PLAYER::PLAYER_PED_ID();
	auto const pedCurrentHealth = ENTITY::GET_ENTITY_HEALTH(playerPed);
	auto const pedOnMount = PED::IS_PED_ON_MOUNT(playerPed);
	auto const maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, 0);
	auto const location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 2, 0);

	std::random_device rd_0;
	std::mt19937 gen_0(rd_0());
	std::uniform_int_distribution<std::size_t> dist_0(0, strangerLocations.size() - 1);

	auto const index = dist_0(gen_0);

	auto const coords = strangerLocations[index];

	WAIT(1000);

	ENTITY::SET_ENTITY_COORDS(playerPed, coords.x, coords.y, coords.z, false, false, false, false);
}


void EffectJohnTime::OnActivate() {
	SetPlayerModel("CS_johnmarston", &oldSkin1, &oldSkin2);
}

void EffectJohnTime::OnDeactivate() {
	ResetPlayerModel(oldSkin1, oldSkin2);
}

void EffectYeeYeeHaircut::OnActivate() {
	static std::array<std::uint32_t, 5> hairModels = { 0x10DC5877, 0x23E6F04A, 0x39665BB3, 0x3C534B23, 0x4F8F7636 };
	static std::array<std::uint32_t, 5> beardModels = { 0x4F585B0F, 0x621738F5, 0xCA2326C, 0x78CDED83, 0x4F585B0F };

	auto const static constexpr hairComponent = 0x864B03AE;
	auto const static constexpr goateeComponent = 0x15D3C7F2;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> dist(0, hairModels.size() - 1);

	auto const playerPed = PLAYER::PLAYER_PED_ID();

	auto const hairModel = hairModels[dist(gen)];
	auto const beardModel = beardModels[dist(gen)];

	PED::_SET_PED_COMPONENT_ENABLED(playerPed, hairModel, 1, 0, true);
	PED::_SET_PED_COMPONENT_VARIATION(playerPed, hairComponent, hairModel, true, false, 0);
	PED::_EQUIP_PED_BODY_COMPONENT(playerPed, hairModel);
	PED::_UPDATE_PED_VARIATION(playerPed, 0, 1, 1, 1, false);

	PED::_SET_PED_COMPONENT_ENABLED(playerPed, beardModel, 1, 0, true);
	PED::_SET_PED_COMPONENT_VARIATION(playerPed, goateeComponent, beardModel, true, false, 0);
	PED::_EQUIP_PED_BODY_COMPONENT(playerPed, beardModel);
	PED::_UPDATE_PED_VARIATION(playerPed, 0, 1, 1, 1, false);
}

void EffectNoBeardAndHair::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	// arrays r overrated frfr
	auto const static constexpr hairComponent = 0x864B03AE;
	auto const static constexpr sideburnsComponent = 0xB6B63737;
	auto const static constexpr goateeComponent = 0x15D3C7F2;
	auto const static constexpr mustacheComponentMP = 0xF8016BCA;
	auto const static constexpr mustacheComponent = 0xECC8B25A;
	auto const static constexpr hairModel = 0x264A371E;

	PED::_SET_PED_COMPONENT_ENABLED(playerPed, hairModel, 1, 0, true);
	PED::_SET_PED_COMPONENT_VARIATION(playerPed, hairComponent, hairModel, true, false, 0);
	PED::_EQUIP_PED_BODY_COMPONENT(playerPed, hairModel);
	PED::_UPDATE_PED_VARIATION(playerPed, 0, 1, 1, 1, false);

	PED::REMOVE_TAG_FROM_META_PED(playerPed, mustacheComponent, 0);
	PED::SET_PED_COMPONENT_ENABLED(playerPed, 0x0, 1, 1, 1);

	PED::REMOVE_TAG_FROM_META_PED(playerPed, sideburnsComponent, 0);
	PED::SET_PED_COMPONENT_ENABLED(playerPed, 0x0, 1, 1, 1);

	PED::REMOVE_TAG_FROM_META_PED(playerPed, mustacheComponentMP, 0);
	PED::SET_PED_COMPONENT_ENABLED(playerPed, 0x0, 1, 1, 1);

	PED::REMOVE_TAG_FROM_META_PED(playerPed, goateeComponent, 0);
	PED::SET_PED_COMPONENT_ENABLED(playerPed, 0x0, 1, 1, 1);
}

void EffectFullBeardAndHair::OnActivate() {
	auto const playerPed = PLAYER::PLAYER_PED_ID();

	static std::array<std::pair<std::uint32_t, std::uint32_t>, 2> facialHair = {
		std::make_pair(0x23E6F04A, 0x864B03AE), 
		std::make_pair(0xEAD62A92, 0xECC8B25A) 
	};

	for (auto const [model, component] : facialHair) {
		PED::_SET_PED_COMPONENT_ENABLED(playerPed, model, 1, 0, true);
		PED::_SET_PED_COMPONENT_VARIATION(playerPed, component, model, true, false, 0);
		PED::_EQUIP_PED_BODY_COMPONENT(playerPed, model);
	}

	PED::_UPDATE_PED_VARIATION(playerPed, 0, 1, 1, 1, false);
}