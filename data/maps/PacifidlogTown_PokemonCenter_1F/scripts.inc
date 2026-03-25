.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "{JPN}きみの トレーナーカードって\n"
	.string "{JPN}なにいろ?\lぼくのは どういろだよ!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "{JPN}パシフィックタウンは\n"
	.string "{JPN}サニーゴの ぐんたいの\l"
	.string "{JPN}うえに うかんでるんだ.\p"
	.string "{JPN}そんなこと いったら\nしんじてくれる?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "{JPN}パシフィックの ひとたちの\n"
	.string "{JPN}せんぞは ふねのうえで\l"
	.string "{JPN}うまれて ふねのうえで\l"
	.string "{JPN}いきて しんだって いわれてる.\p"
	.string "{JPN}なにかを さがしていたから\n"
	.string "{JPN}そんな せいかつを\l"
	.string "{JPN}していたんだって きいたよ.$"

