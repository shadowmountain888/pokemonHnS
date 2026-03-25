.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VictoryRoad_1F_OnTransition:
	callnative SetTimeBasedEncounters
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_GARBAGEFLAG
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "{JPN}ミツル: やあ! {PLAYER}!\p"
	.string "{JPN}ここで ぼくに あうなんて\n"
	.string "{JPN}びっくり したでしょ!\p"
	.string "{JPN}ここまで こられたのも\n"
	.string "{JPN}{PLAYER}の おかげだよ!\p"
	.string "{JPN}{PLAYER} あのとき きみに\n"
	.string "{JPN}まけて ぼくは つよくなった!\p"
	.string "{JPN}でも もう まけないよ!\p"
	.string "{JPN}ぼくに ゆうきと ちからを\n"
	.string "{JPN}くれた ポケモンの ために!\pよし... いくよ!$"
VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "{JPN}わあ!\n"
	.string "{JPN}{PLAYER} きみは やっぱり\nつよいね!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "{JPN}ミツル: きょうは {PLAYER}に\n"
	.string "{JPN}かてなかったけど いつかきっと\l"
	.string "{JPN}おいつくからね!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "{JPN}ミツル: やあ! {PLAYER}!\p"
	.string "{JPN}あのときから つよくなったんだ!\n"
	.string "{JPN}きみに みせたかったよ {PLAYER}!\p"
	.string "{JPN}よし... いくよ!$"
VictoryRoad_1F_Text_WallyDefeat:
	.string "{JPN}わあ!\n"
	.string "{JPN}{PLAYER} きみは やっぱり\nつよいね!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "{JPN}ミツル: こんかいも きみには\n"
	.string "{JPN}かなわなかった...\l"
	.string "{JPN}でも いつか {PLAYER} \n"
	.string "{JPN}きっと おいつくからね...\pそして ポケモンリーグに\nちょうせんするんだ!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "{JPN}なんかいか ここまで きたけど\n"
	.string "{JPN}さいごの みちのりが ながくて...$"
VictoryRoad_1F_Text_EdgarDefeat:
	.string "{JPN}また ここで ゆめが\nおわってしまった...$"
VictoryRoad_1F_Text_EdgarPostBattle:
	.string "{JPN}ここまで こられたんだ.\n"
	.string "{JPN}この いきおいで チャンピオンに\l"
	.string "{JPN}なってくれよ! きみなら できる!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "{JPN}ここまで きて まけるなんて\n"
	.string "{JPN}ありえない!\nそんなかのうせいは ないんだ!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "{JPN}そんな ばかな...\n"
	.string "{JPN}まけた だって?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "{JPN}ここで まけるとは...\p"
	.string "{JPN}チャンピオンになる しかくが\n"
	.string "{JPN}ぼくには ないのか...$"
VictoryRoad_1F_Text_HopeIntro:
	.string "{JPN}この むげんに つづく きびしいみちは\n"
	.string "{JPN}ビクトリーロードという なまえに\lふさわしいね.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "{JPN}きみの たたかいかたって\nすばらしいね...$"
VictoryRoad_1F_Text_HopePostBattle:
	.string "{JPN}きみには チャンピオンに なる\n"
	.string "{JPN}かのうせいが あるようだね.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "{JPN}ビクトリーロードって なんだか\n"
	.string "{JPN}しってる? かったら おしえてやるよ!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "{JPN}よし!\n"
	.string "{JPN}よく やったな!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "{JPN}ここを ぶじに とおりぬけること--\n"
	.string "{JPN}それが ポケモンチャンピオンを\l"
	.string "{JPN}めざす トレーナーの さいごのしれん.\p"
	.string "{JPN}だから ビクトリーロードと\n"
	.string "{JPN}よばれているんだ.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "{JPN}ここまで きた ひとに いうことは\n"
	.string "{JPN}なにも ない. かかってこい!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "{JPN}これは はずかしい...$"
VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "{JPN}ふん さっさと いけばいいじゃない.\n"
	.string "{JPN}しったことか.$"
