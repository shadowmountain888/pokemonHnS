.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_BUGSY_1, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_ZUKI, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_FALKNER_1, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_DEVIN, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_GARBAGEFLAG
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end
	
Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "{JPN}けんきゅうじょが てんきに かんけい\n"
	.string "{JPN}する ポケモンを つくったんだ.\l"
	.string "{JPN}それを うばいに きたぞ!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "{JPN}おれたちの けいかくが\nガキに じゃまされるのか?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "{JPN}ここで つくられた ポケモンが\n"
	.string "{JPN}てんきを じゆうに あやつれるなら\l"
	.string "{JPN}アクアだんの おれたちに ひつようだ!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "{JPN}おれたちは アクアだんだ!\n"
	.string "{JPN}ちんしな ものが あるところには\l"
	.string "{JPN}どこにでも あらわれるぞ!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "{JPN}やられた!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "{JPN}アクアだんの おれたちが なにを\n"
	.string "{JPN}めざしているか わからないだろう!\l"
	.string "{JPN}じゃまするな!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "{JPN}まさか おまえも てんきポケモンを\n"
	.string "{JPN}さがしに きたのか?\p"
	.string "{JPN}ダメダメ!\n"
	.string "{JPN}おれたちが さきに とりに きたんだ!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "{JPN}ああ おれの ポケモンを\nみてくれよ$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "{JPN}フン だから なんだ?\n"
	.string "{JPN}おれたちが ほしいのは...\p"
	.string "{JPN}おれたちが ほんとうに\n"
	.string "{JPN}ほしいのは ここには ない...\nイヒヒヒヒ...$"
Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "{JPN}あははははは!\p"
	.string "{JPN}アクアだんの じゃまを\n"
	.string "{JPN}するつもり?\p"
	.string "{JPN}きょうふしらずか むちか\n"
	.string "{JPN}それとも りょうほうか!\p"
	.string "{JPN}かわいくて むかつくわね!\n"
	.string "{JPN}このガキ やっつけてやる!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "{JPN}あははははは!\n"
	.string "{JPN}むかつくほど つよいわね!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "{JPN}マグマだんが うろちょろするのも\n"
	.string "{JPN}めいわくなのに あんたまで!\p"
	.string "{JPN}いったい なんで あたしたちの\n"
	.string "{JPN}しごとを かぎまわるのよ?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "{JPN}たいへんな じたいです!\p"
	.string "{JPN}マグマだんの しゅうだんが\n"
	.string "{JPN}てんきけんきゅうじょを とおって\l"
	.string "{JPN}いきました!\p"
	.string "{JPN}シオンやまに むかっているようです!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "{JPN}なに?!\p"
	.string "{JPN}もう ここで じかんを\n"
	.string "{JPN}むだにできないわ!\l"
	.string "{JPN}あたしたちも シオンやまに\l"
	.string "{JPN}いそがなくちゃ!\pあははははは!\nマグマだん まっていなさい!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "{JPN}ありがとう!\n"
	.string "{JPN}きみの おかげで たすかったよ!\p"
	.string "{JPN}へんな おれいだけど\n"
	.string "{JPN}この ポケモンを もらってくれ$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "{JPN}あれ? この ポケモンを\n"
	.string "{JPN}もつ ばしょが ないみたいだね$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{JPN}{PLAYER}は ポワルンを もらった!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "{JPN}その ポケモンは てんきの じょうたい\n"
	.string "{JPN}によって すがたが かわるんだ.\p"
	.string "{JPN}けんきゅうじょには たくさんいるから\n"
	.string "{JPN}もらっていってくれ$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "{JPN}ながい あいだ あめの けんきゅうを\n"
	.string "{JPN}しているが にんげんが じゆうに\l"
	.string "{JPN}てんきを かえるなんて ばかげている$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "{JPN}ホウエンちほうの てんきの\n"
	.string "{JPN}パターンを ついせき してるんだ.\p"
	.string "{JPN}げんざい {STR_VAR_1}で\n"
	.string "{JPN}かんばつが きろく されてる.\n"
	.string "{JPN}もしかして {STR_VAR_1}の\n"
	.string "{JPN}ちかくの どこかで...$"
Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "{JPN}ホウエンちほうの てんきの\n"
	.string "{JPN}パターンを ついせき してるんだ.\p"
	.string "{JPN}げんざい {STR_VAR_1}で\n"
	.string "{JPN}おおあめが きろく されてる.\n"
	.string "{JPN}もしかして {STR_VAR_1}の\n"
	.string "{JPN}ちかくの どこかで...$"
Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "{JPN}いじょうてんきの ほうこくは\n"
	.string "{JPN}もう なくなりました.\p"
	.string "{JPN}ときどきの あめは ほんとうに\n"
	.string "{JPN}めぐみですね$"

