.set LOCALID_NURSE, 1

PewterCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "{JPN}でねでね..\n"
	.string "{JPN}グレンのジムがなくなってるの！\l"
	.string "{JPN}あたしちょーおどろいたー！\p"
	.string "{JPN}..なーに？でんわちゅうなの\n"
	.string "{JPN}ジャマしないでよ！$"
PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "{JPN}ぷうーぷぷうー$"
PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "{JPN}プリンのうたごえをきくと..\n"
	.string "{JPN}たいていのポケモンはねむくなる\p"
	.string "{JPN}ねむっているときにつかうわざが\n"
	.string "{JPN}いくつかあるんだよね！$"