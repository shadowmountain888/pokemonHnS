.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "{JPN}トキワのジムリーダー\n"
	.string "{JPN}どこにいっちゃったんだろう？\l"
	.string "{JPN}ちょうせんしてみたかったのに..$"
ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "{JPN}トキワジムには ジムトレーナーが\n"
	.string "{JPN}いないんだ.\p"
	.string "{JPN}リーダーは ぶかを つかわずに\n"
	.string "{JPN}かつのが しんじょうだって いってるよ.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "{JPN}グレンタウンのジムが\n"
	.string "{JPN}なくなっちゃったみたいよ\p"
	.string "{JPN}リーダーのカツラさん\n"
	.string "{JPN}どこでなにしてるのかしら？$"
ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "{JPN}ジムリーダーになることが\n"
	.string "{JPN}ぼくのゆめなんだ！$"