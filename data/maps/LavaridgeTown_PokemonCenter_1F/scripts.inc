.set LOCALID_NURSE, 1

LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "{JPN}ポケモンは トレーナーと\n"
	.string "{JPN}いっしょに いる じかんが\l"
	.string "{JPN}ながいほど なかよく なると\l"
	.string "{JPN}おもうよ.\pそれが わたしの かんがえ\nなんだ.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "{JPN}おんせんに はいってるだけで\n"
	.string "{JPN}げんきに なるなんて\l"
	.string "{JPN}ふしぎだよね.\p"
	.string "{JPN}わたしの ポケモンも\nいっしょに はいらせて\lあげたいなあ.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "{JPN}ほほほ! ぼうや ここから\n"
	.string "{JPN}おんせんに いけるのよ.\p"
	.string "{JPN}ポケモンが やすんでるなら\n"
	.string "{JPN}トレーナーも やすまないと\lいけないわね.$"

