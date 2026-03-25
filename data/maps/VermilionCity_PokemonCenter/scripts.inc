.set LOCALID_NURSE, 1

VermilionCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "{JPN}ねむっているポケモンが\n"
	.string "{JPN}ディグダのあなのまえに\l"
	.string "{JPN}よこになっているよ.\p"
	.string "{JPN}つかまえるには\nさいこうのチャンスだけど\lどうやっておこすんだい?$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "{JPN}まえはねむっている\n"
	.string "{JPN}ポケモンがディグダのあなの\l"
	.string "{JPN}まえによこになっていたんだ.\p"
	.string "{JPN}でもきえちゃったみたいだね.$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "{JPN}こうそくせんはトレーナーと\n"
	.string "{JPN}であってたたかうのには\lさいこうのばしょだぜ!$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "{JPN}おや?きみはぼくがみたことの\n"
	.string "{JPN}ないバッジをもっているね.\p"
	.string "{JPN}ああ わかった.ジョウトちほうで\n"
	.string "{JPN}てにいれたんだね.$"
