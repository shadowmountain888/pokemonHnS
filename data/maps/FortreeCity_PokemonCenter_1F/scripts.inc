.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_RhyperiorEvo::
	msgbox FortreeCity_PokemonCenter_1F_RhyperiorEvo_Text, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_RhyperiorEvo_Text:
	.string "{JPN}サイドンは こうかんすると\n"
	.string "{JPN}しんかするんじゃ.\p"
	.string "{JPN}だが とくべつな どうぐを\n"
	.string "{JPN}もたせないと だめじゃぞ.\p"
	.string "{JPN}どんな どうぐかって?\p"
	.string "{JPN}うーむ... さんじゅうねんまえほど\n"
	.string "{JPN}きおくが よくないのう... たしか...\l{JPN}かたい... かたい... あー.\pおもいだせんのう. すまんな.$"

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "{JPN}おい ぼうず  きみは\n"
	.string "{JPN}ポケモンずかんを つくってるのか?\p"
	.string "{JPN}ふむ... サファリゾーンに\n"
	.string "{JPN}いってみなさい. それが わしの\nすすめじゃ.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "{JPN}きろくコーナーで\n"
	.string "{JPN}なにか やったことある?\p"
	.string "{JPN}けっこう おもしろいよ.\n"
	.string "{JPN}トレーナーの きろくを\l"
	.string "{JPN}ミックスして あわせてくれるんだ.\p"
	.string "{JPN}どういう しくみか\nよく わからないけど\lすごいよ. わくわくするね!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "{JPN}おお  すごい!\n"
	.string "{JPN}ポケナビを もってるんだね!\l"
	.string "{JPN}ぼくのと おなじだよ!\p"
	.string "{JPN}ポケナビの\n"
	.string "{JPN}マッチコール システム\l"
	.string "{JPN}しってる?\p"
	.string "{JPN}アクセスすれば\n"
	.string "{JPN}とうろくした トレーナーと\l"
	.string "{JPN}いつでも チャットできるんだ.\p"
	.string "{JPN}それに どの トレーナーが\nさいせんを のぞんでるかも\lしらせてくれるよ.\pほんとうに べんり!\nデボンの ひとたちは\lすごいことを するね!$"

