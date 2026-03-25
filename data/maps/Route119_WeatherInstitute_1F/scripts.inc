.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, Route119_WeatherInstitute_1F_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Bed_PokecenterChallenge::
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_ZEKE, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_FALKNER_2, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "{JPN}ボスが ここの けんきゅうに\n"
	.string "{JPN}きょうみを もったから\l"
	.string "{JPN}おれたちが おくられたんだ\p"
	.string "{JPN}じゃまするな!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "{JPN}ちくしょう...\n"
	.string "{JPN}ガキにやられるなんて...$"
Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "{JPN}ボスは なんでも しってる\p"
	.string "{JPN}でも おれは ただの したっぱ\n"
	.string "{JPN}ボスが なにを かんがえてるかなんて\lしるわけないだろ$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "{JPN}あ?\n"
	.string "{JPN}こんなところに ガキがなにしてる?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "{JPN}あ?\n"
	.string "{JPN}まけた?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "{JPN}やばい...\n"
	.string "{JPN}ガキに まけたなんて\l"
	.string "{JPN}おこられちゃうよ...\pベッドで ひるねでも\nしてよっと...$"
Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "{JPN}おれが ねてるあいだに\n"
	.string "{JPN}みんな 2かいに いっちゃった!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "{JPN}わあ! きみって\n"
	.string "{JPN}ほんとうに つよいんだね!\p"
	.string "{JPN}わたしも きみのような\nポケモン トレーナーに なりたいな!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "{JPN}はかせは あめが だいすきなんだ\n"
	.string "{JPN}それは じじつだよ\p"
	.string "{JPN}でも あめが ふりつづけたら\n"
	.string "{JPN}ひとびとが こまってしまう\l"
	.string "{JPN}それも また じじつなんだ\p"
	.string "{JPN}だから はかせは あめを\nうまく りようできないか\lけんきゅうしてるんだ$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "{JPN}けんきゅうじょの 2かいでは\n"
	.string "{JPN}ホウエンちほうの てんきの\l"
	.string "{JPN}パターンを しらべているんだ\p"
	.string "{JPN}さいきん きゅうに かんそうしたり\n"
	.string "{JPN}おおあめが ふったりする\l"
	.string "{JPN}げんしょうが おきているよ...$"
Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "{JPN}こんにちは!\n"
	.string "{JPN}きみの おかげで たすかったよ!\p"
	.string "{JPN}でも アクアだんが\n"
	.string "{JPN}いったい なにを しようとしてたのか\lさっぱり わからないんだ$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "{JPN}ベッドが あるね...\n"
	.string "{JPN}ちょっと やすもうか$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed_PokecenterChallenge:
	.string "{JPN}ごめん! きみは\n"
	.string "{JPN}ポケモンセンター チャレンジを\lやってるから だめなんだ!$"
