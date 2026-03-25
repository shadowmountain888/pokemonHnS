.set LOCALID_CERULEAN_GYM_ROCKET, 5

CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "{JPN}ハナダポケモンジム\n"
	.string "{JPN}リーダー:カスミ\p"
	.string "{JPN}しょうりしゃ:\n"
	.string "{JPN}グリーン レッド$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "{JPN}ハナダポケモンジム\n"
	.string "{JPN}リーダー:カスミ\p"
    .string "{JPN}しょうりしゃ:\n"
	.string "{JPN}グリーン レッド {PLAYER}$"

CeruleanGym_Text_Note:
	.string "{JPN}ごめんなさい しばらく\n"
	.string "{JPN}るすにします.\l"
	.string "{JPN}ジムリーダー カスミ\p"
	.string "{JPN}カスミがるすなので \n"
	.string "{JPN}わたしたちもるすに\lします.ジムトレーナー$"


CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	msgbox CeruleanGym_Text_MistyTm, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	clearflag FLAG_HIDE_CAPE_MISTY
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanGym_Text_GruntIntro:
	.string "{JPN}オー！ソーリー！\n"
	.string "{JPN}ユーけがナッシングですかー？\l"
	.string "{JPN}わたしベリービジーね！\l"
	.string "{JPN}ユーとゆっくりトーキング\l"
	.string "{JPN}してられませーん！\l"
	.string "{JPN}だれかにみられたら\l"
	.string "{JPN}わたしこまりまーす！$"
CeruleanGym_Text_GruntBigMistake:
	.string "{JPN}..オーノー！\n"
	.string "{JPN}すでにユーにみられました！\l"
	.string "{JPN}ビックマイミステイク！$"
CeruleanGym_Text_GruntBye:
	.string "{JPN}ヘイユー！\n"
	.string "{JPN}このことフォーゲットするね！\l"
	.string "{JPN}ユーはなにもみてなーい\l"
	.string "{JPN}なにもきいてなーい\l"
	.string "{JPN}なにもしらなーいね！\p"
	.string "{JPN}バイバイ！\n"
	.string "{JPN}ロンググッドバイ！！$"
CeruleanGym_Text_Note1:
	.string "{JPN}ごめんなさい しばらく\n"
	.string "{JPN}るすにします.\l"
	.string "{JPN}ジムリーダー カスミ\p"
	.string "{JPN}カスミがるすなので \nわたしたちもるすに\lします.ジムトレーナー$"

CeruleanGym_Text_MistyIntro:
	.string "{JPN}きたわねオジャマムシ！\p"
	.string "{JPN}ジョウトのジムバッジを\n"
	.string "{JPN}たくさんもってるみたいだけど\l"
	.string "{JPN}なめてもらっちゃこまるわ！\p"
	.string "{JPN}あたしのみずタイプのポケモンは\n"
	.string "{JPN}つよいわよっ！$"
CeruleanGym_Text_MistyWinLoss:
	.string "{JPN}やるじゃない..\p"
	.string "{JPN}あんたのじつりょく\n"
	.string "{JPN}すなおにみとめるわ..\p"
	.string "{JPN}はいこれ\n"
	.string "{JPN}ブルーバッジよ！$"
CeruleanGym_Text_ReceivedBadge:
	.string "{JPN}{PLAYER}はカスミから\n"
	.string "{JPN}ブルーバッジをもらった！$"
CeruleanGym_Text_MistyFightDone:
	.string "{JPN}カスミ:ジョウトには\n"
	.string "{JPN}つよいトレーナーが\l"
	.string "{JPN}たくさんいるの?\p"
	.string "{JPN}あなたみたいな.\p"
	.string "{JPN}いつかりょこうして\n"
	.string "{JPN}うでききのトレーナーと\lたたかってみたいわ.$"

CeruleanGym_Text_MistyRematch:
	.string "{JPN}カスミ:わあ あなたが\n"
	.string "{JPN}カントーチャンピオンに\l"
	.string "{JPN}なったのね!\p"
	.string "{JPN}すごいじゃない!\n"
	.string "{JPN}すっかりつよくなって \l"
	.string "{JPN}{PLAYER}.\pでもわたしもまけないわ.\pもういちどしょうぶ\nしない?$"

CeruleanGym_Text_MistyRematchDefeat:
	.string "{JPN}カスミ: あなた ほんとうに\nつよいのね...$"
CeruleanGym_Text_SwimmerfDianaSeen:
	.string "{JPN}るすにしててごめんね.\n"
	.string "{JPN}さあ はじめましょう!$"

CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "{JPN}まいった!あなたのかち\nよ!$"

CeruleanGym_Text_SwimmerfDianaAfter:
	.string "{JPN}しずかにおよいでいるわ.$"

CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "{JPN}わたしのゆうがな\n"
	.string "{JPN}およぎにみとれちゃ\lダメよ.$"

CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "{JPN}きゃあ れいせいに\nたおされちゃった...$"
CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "{JPN}わたしにかったからって\n"
	.string "{JPN}ちょうしにのっちゃ\l"
	.string "{JPN}ダメよ.\p"
	.string "{JPN}ゆだんしてたら\nカスミにやられちゃうわ.$"

CeruleanGym_Text_SwimmermParkerSeen:
	.string "{JPN}ぐるぐる...\p"
	.string "{JPN}ぼくが いちばん!\nかかって こいよ!$"

CeruleanGym_Text_SwimmermParkerBeaten:
	.string "{JPN}そんな ばかな...$"
CeruleanGym_Text_SwimmermParkerAfter:
	.string "{JPN}カスミはここすうねんで\n"
	.string "{JPN}ずいぶんつよくなったよ.\p"
	.string "{JPN}ゆだんしてたら\n"
	.string "{JPN}やられちゃうぞ!$"

CeruleanGym_Text_GuideIntro:
	.string "{JPN}おーす！\n"
	.string "{JPN}みらいのレジェンド！\p"
	.string "{JPN}カスミたちがいないもんだから\n"
	.string "{JPN}オレもあそびにいってたんだ！\l"
	.string "{JPN}なははははっ！$"
CeruleanGym_Text_GuideWin:
	.string "{JPN}さすがにつよいな！\n"
	.string "{JPN}いいたたかいだったぜ！$"
CeruleanGym_Text_MistyTm:
	.string "{JPN}これももっていって.$"
