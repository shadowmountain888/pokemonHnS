.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "{JPN}じぶんの ポケモンを\n"
	.string "{JPN}しんじられなければ\l"
	.string "{JPN}ほんとうの トレーナーとは\l"
	.string "{JPN}いえないよ.\p"
	.string "{JPN}さいごまで たたかう\n"
	.string "{JPN}ポケモンを しんじられる\lひとだけが さいごまで\lかちぬくことが できるんだ.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "{JPN}だれかが シダケタウンに\n"
	.string "{JPN}くる りゆうは...\p"
	.string "{JPN}もちろん バトルテントが\n"
	.string "{JPN}あるからさ.\p"
	.string "{JPN}それとも だれかに\n"
	.string "{JPN}あいに きたのかい?$"

