.set LOCALID_NURSE, 1

MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "{JPN}このまちの ジムリーダーは\n"
	.string "{JPN}きょうりょくな コンビなんだ.\p"
	.string "{JPN}ふたりの れんけいこうげきは\n"
	.string "{JPN}すごくて かんぺきだよ!$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
	.string "{JPN}ポケモンの とくせいに よっては\n"
	.string "{JPN}わざが へんかしたり\l"
	.string "{JPN}こうかが なくなったり するんだ.$"

