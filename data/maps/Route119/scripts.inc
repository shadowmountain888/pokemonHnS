.set LOCALID_RIVAL, 16
.set LOCALID_RIVAL_ON_BIKE, 25
.set LOCALID_SCOTT, 43

Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	callnative SetTimeBasedEncounters
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	callnative SetTimeBasedEncounters
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_SapphireKecleon::
	lock
	faceplayer
	setvar VAR_0x8009, 7
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_SapphireKecleon2
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_SapphireKecleon2::
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route119_EventScript_SapphireKecleon3
	release
	end

Route119_EventScript_SapphireKecleon3::
	msgbox Kecleon_Text_UseDevonScopeMonAttacked, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 29
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route119_EventScript_SapphireKecleon4
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route119_EventScript_SapphireKecleon4
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route119_EventScript_SapphireKecleon5
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route119_EventScript_SapphireKecleon5
	release
	end

Route119_EventScript_SapphireKecleon4::
	msgbox Route119_EventScript_SapphireKecleon_Text1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAPPHIRE
	closemessage
	setflag FLAG_SAPPHIRE_KECLEON
	goto Common_EventScript_RemoveStaticPokemon
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	releaseall
	end

Route119_EventScript_SapphireKecleon5::
	msgbox Route119_EventScript_SapphireKecleon_Text2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route119_EventScript_SapphireKecleon_Text1:
	.string "{JPN}カクレオンが\n"
	.string "{JPN}ひかる ものを おとした!$"

Route119_EventScript_SapphireKecleon_Text2:
	.string "{JPN}みえない カクレオンが\n"
	.string "{JPN}まだ ここに いる...$"
Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_RIVAL_ON_BIKE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
	delay 65
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL_ON_BIKE
	addobject LOCALID_RIVAL
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
	releaseall
	end

Route119_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route119_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_BattleMay::
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleMayTreecko
	case 1, Route119_EventScript_BattleMayTorchic
	case 2, Route119_EventScript_BattleMayMudkip
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_BattleBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTorchic
	case 2, Route119_EventScript_BattleBrendanMudkip
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_GARBAGEVAR, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0
	return

Route119_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_RIVAL, 25, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_RIVAL, 26, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_RIVAL_CHIKORITA_4, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RIVAL_CHIKORITA_4
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_RIVAL_CHIKORITA_4, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_GRUNT_3, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GRUNT_3
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_GRUNT_3, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_JASMINE_1_2, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_GRUNT_17, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_NOB, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_JOHN, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "{JPN}ハルカ: {PLAYER}くん!\n"
	.string "{JPN}どこに いたの? さがしてたのよ!\p"
	.string "{JPN}どのくらい つよくなったかしら?\n"
	.string "{JPN}わたしが たしかめてあげる!\p"
	.string "{JPN}ポケモンの じゅんびは できてる?\n"
	.string "{JPN}もちろんよね! いくよ!$"

Route119_Text_MayDefeat:
	.string "{JPN}あちゃー!\n"
	.string "{JPN}{PLAYER}くん つよいのね!\p"
	.string "{JPN}しゅぎょうで くろうしてるんじゃ\n"
	.string "{JPN}ないかって しんぱいしてたの.$"

Route119_Text_MayPresentForYou:
	.string "{JPN}ハルカ: でも ぜんぜん しんぱい\n"
	.string "{JPN}することなかったわね! がんばって!\p"
	.string "{JPN}あっ そうそう! あなたに\nプレゼントが あるの.$"

Route119_Text_MayExplainFly:
	.string "{JPN}ハルカ: そらをとぶを つかえば \n"
	.string "{JPN}ポケモンが いちどに いったことの\l"
	.string "{JPN}ある まちに うんでくれるのよ.\p"
	.string "{JPN}でも そらをとぶを つかうには\n"
	.string "{JPN}キノミのもりシティの ジムバッジが\l"
	.string "{JPN}ひつようなの.たいせつよ.\p"
	.string "{JPN}そらをとぶで かえって\n"
	.string "{JPN}ミシロタウンに かおを だしなさい.\p"
	.string "{JPN}おかあさんも しんぱいしてると\n"
	.string "{JPN}おもうわよ {PLAYER}くん.\p"
	.string "{JPN}じゃあ また どこかで あいましょう!$"

Route119_Text_BrendanIntro:
	.string "{JPN}ユウキ: {PLAYER}! こんなところで\n"
	.string "{JPN}ポケモンを さがしてたのか?\p"
	.string "{JPN}どのくらい うまくなったか\n"
	.string "{JPN}みせてもらおう!\p"
	.string "{JPN}さあ!\n"
	.string "{JPN}しょうぶだ しょうぶ!$"

Route119_Text_BrendanDefeat:
	.string "{JPN}うーん...\n"
	.string "{JPN}きみ かなり つよく なったね$"

Route119_Text_BrendanIllGiveYouThis:
	.string "{JPN}ユウキ: どこでも ポケモンを\n"
	.string "{JPN}さがせるくらい うまくなったな.\p"
	.string "{JPN}ほら これを やろう.\n"
	.string "{JPN}つかって みろよ.$"

Route119_Text_BrendanExplainFly:
	.string "{JPN}ユウキ: そらをとぶを つかえば \n"
	.string "{JPN}ポケモンが いちど いったことの\l"
	.string "{JPN}ある まちに うんでくれるんだ.\p"
	.string "{JPN}でも キノミのもりジムの バッジが\n"
	.string "{JPN}ひつようだけどな.\p"
	.string "{JPN}とにかく おれは いそがしいんだ.$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "{JPN}ガンテツ: はーっはっは!\n"
	.string "{JPN}やるじゃない {PLAYER}くん!\p"
	.string "{JPN}じてんしゃに のった トレーナーと\n"
	.string "{JPN}すれちがったよ.\p"
	.string "{JPN}きみが その トレーナーを たおした\n"
	.string "{JPN}んだろう? あきらかだったからね.\p"
	.string "{JPN}その こは すごく おこって\n"
	.string "{JPN}かおを まっかにしてたよ.\p"
	.string "{JPN}きみとは よく であうなあ.\n"
	.string "{JPN}つぎは キノミのもりジム かい?\p"
	.string "{JPN}ジムでも がんばると おもうよ.\n"
	.string "{JPN}じゃあ また あおう!$"


Route119_Text_ScottYouWonAtFortreeGym:
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ピッ!\p"
	.string "{JPN}エニシダ: やあ {PLAYER}くん ぼくだよ!\p"
	.string "{JPN}やっぱり きみは ヒワマキジムで\n"
	.string "{JPN}かったんだね\p"
	.string "{JPN}きみの つよさ...\n"
	.string "{JPN}もしかして きみこそ ぼくが\l"
	.string "{JPN}さがしていた トレーナーかも\p"
	.string "{JPN}おぼえておいて きみには ファンが\n"
	.string "{JPN}いるんだ えんじょうから\l"
	.string "{JPN}おうえんしてるからね!\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ガチャ!$"
Route119_Text_StayAwayFromWeatherInstitute:
	.string "{JPN}ここで みはりを してるんだ.\p"
	.string "{JPN}おい きみ! てんきけんきゅうじょに\n"
	.string "{JPN}ちかづくな.あぶないぞ.$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "{JPN}みはりの しごとって たいくつだな.\p"
	.string "{JPN}おい きみ! てんきけんきゅうじょに\n"
	.string "{JPN}ちかづかないでくれ.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "{JPN}そらをとぶのは とりポケモンの\n"
	.string "{JPN}むれを つかまえて それに\l"
	.string "{JPN}しがみついて とぶのかと おもった\p"
	.string "{JPN}でも そらをとぶっていう\n"
	.string "{JPN}ひでんマシンの わざが あるのね!\p"
	.string "{JPN}もっと はやく しっていれば\n"
	.string "{JPN}よかったのに...$"
Route119_Text_TallGrassSnaresBikeTires:
	.string "{JPN}ちっ...\n"
	.string "{JPN}だめだ...\p"
	.string "{JPN}たかいくさが じてんしゃの タイヤに\n"
	.string "{JPN}からまる ここは はしれないや$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "{JPN}きみの ポケモンは ひみつのちからで\n"
	.string "{JPN}おおきな くさに ひみつきちを\l"
	.string "{JPN}つくれるかな?$"

Route119_Text_RouteSignFortree:
	.string "{JPN}119ばんどうろ\n"
	.string "{JPN}{RIGHT_ARROW} キノミのもりシティ$"

Route119_Text_WeatherInstitute:
	.string "{JPN}てんきけんきゅうじょ$"

Route119_Text_TrainerTipsDecoration:
	.string "{JPN}トレーナーの ヒント\p"
	.string "{JPN}16こまでの かざりと かぐが\n"
	.string "{JPN}ひみつきちに おけるよ.\p"
	.string "{JPN}すきな ものを えらんで きみだけの\n"
	.string "{JPN}とくべつな ひみつきちを つくろう.$"
	.string ""
	.string ""
