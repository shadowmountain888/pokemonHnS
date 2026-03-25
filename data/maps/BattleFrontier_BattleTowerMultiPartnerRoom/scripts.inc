.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "{JPN}ここにあつまった\n"
	.string "{JPN}トレーナーのなかから\lパートナーをみつけてね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{JPN}{PLAYER}さん タッグチームの\n"
	.string "{JPN}パートナーがみつかりませんね\p"
	.string "{JPN}さがすのをやめて\n"
	.string "{JPN}うけつけカウンターに\lもどりますか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "{JPN}それでは ここにあつまった\n"
	.string "{JPN}トレーナーのなかから\lパートナーをみつけてね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "{JPN}パートナーをえらんで\n"
	.string "{JPN}いただき ありがとうございます\p"
	.string "{JPN}それでは マルチバトルルームに\nごあんないします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "{JPN}ぼくは {STR_VAR_1}の {STR_VAR_2}ばんめの\n"
	.string "{JPN}でし {STR_VAR_3}だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "{JPN}{STR_VAR_1}のアドバイスで\n"
	.string "{JPN}{STR_VAR_2}をおぼえた {STR_VAR_3}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "{JPN}{STR_VAR_1}をおぼえた {STR_VAR_2}を\n"
	.string "{JPN}つれてきたんだ\pタッグチームをくまないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "{JPN}ありがとう!\n"
	.string "{JPN}いますぐとうろくしてくるよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "{JPN}ほんとうは きみと\n"
	.string "{JPN}タッグを くみたかったんだ\n{PLAYER}...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "{JPN}わたくしは {STR_VAR_1}の {STR_VAR_2}ばんめの\n"
	.string "{JPN}でし {STR_VAR_3}です$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "{JPN}{STR_VAR_1}からのアドバイスで\n"
	.string "{JPN}{STR_VAR_2}をおぼえた {STR_VAR_3}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "{JPN}{STR_VAR_1}をおぼえた {STR_VAR_2}を\n"
	.string "{JPN}えらびました\pタッグチームをくみましょう!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "{JPN}ありがとうございます!\n"
	.string "{JPN}すぐにとうろくしてまいります!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{JPN}{PLAYER} ぼくは きみと\n"
	.string "{JPN}パートナーを くめたらって\nおもってたんだ...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "{JPN}あの ぼくの なまえは {STR_VAR_3}で\n"
	.string "{JPN}{STR_VAR_1}の だい {STR_VAR_2}ごう\n"
	.string "{JPN}でしです.\p"
	.string "{JPN}ぐすっ...\p"
	.string "{JPN}ごめんなさい!\nきんちょうして なみだが...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{JPN}{STR_VAR_3}のアドバイスで\n"
	.string "{JPN}{STR_VAR_1}をおぼえた {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう\n"
	.string "{JPN}{STR_VAR_2}を 1ぴき.\p"
	.string "{JPN}ぐすっ...\nおねがいです チームを\nくんでください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "{JPN}え ほんとうですか? \n"
	.string "{JPN}やったー! すごい! うおおお!\p"
	.string "{JPN}ああ... ごめんなさい...\n"
	.string "{JPN}うれしくて なみだが...\p"
	.string "{JPN}すぐに とうろく してきます.\n"
	.string "{JPN}いかないで くださいね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "{JPN}あ で でも...\n"
	.string "{JPN}うう... うわああああん!$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "{JPN}やあ! ぼく {STR_VAR_3}だよ!\n"
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2}ばんめのでしさ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{JPN}{STR_VAR_3}のすすめで\n"
	.string "{JPN}{STR_VAR_1}をおぼえた {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "{JPN}{STR_VAR_1}をおぼえた {STR_VAR_2}\n"
	.string "{JPN}をもってきたんだ! どう?\p"
	.string "{JPN}さあさあ!\n"
	.string "{JPN}タッグチームをくもうぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "{JPN}やったあ! すごいや!\n"
	.string "{JPN}よし とうろくしてくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "{JPN}ええー なんで?\n"
	.string "{JPN}チームくみたかったのに {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "{JPN}ぼくは ゆうめいな {STR_VAR_1}の\n"
	.string "{JPN}{STR_VAR_2}ばんめのでし {STR_VAR_3}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "{JPN}{STR_VAR_3}にアドバイスをもらって\n"
	.string "{JPN}{STR_VAR_1}をつかう {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "{JPN}{STR_VAR_1}をおぼえた {STR_VAR_2}が\n"
	.string "{JPN}ぼくのペアなんだ\p"
	.string "{JPN}タッグチームをくんでもらえるか?$"
	.string ""

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "{JPN}ありがとう!\n"
	.string "{JPN}すぐにとうろくしてくる!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{JPN}{PLAYER} きみと\n"
	.string "{JPN}タッグチームを くめたらって\nおもってたんだ...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "{JPN}あの... はなしかけて\n"
	.string "{JPN}もらえて しんから\n"
	.string "{JPN}うれしいです.\p"
	.string "{JPN}わたしは {STR_VAR_3}です.\n{STR_VAR_1}の だい {STR_VAR_2}ごう\nでしなんです...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{JPN}{STR_VAR_3}にアドバイスをもらいました\n"
	.string "{JPN}とてもかんしゃしています\p"
	.string "{JPN}{STR_VAR_1}をおぼえた {STR_VAR_2}と$"
	.string ""

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう\n"
	.string "{JPN}{STR_VAR_2}を 1ぴき.\n"
	.string "{JPN}むりな おねがいだと\n"
	.string "{JPN}おもうんですが...\pパートナーとして\nいっしょに やって\nもらえませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "{JPN}ほんとうですか!\n"
	.string "{JPN}しんじられません!\n"
	.string "{JPN}いっしょに やって\n"
	.string "{JPN}もらえるなんて!\l"
	.string "{JPN}がんばります!\pあの... ほんとうに\nいいなら すぐに とうろく\nしてきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "{JPN}ああ...\n"
	.string "{JPN}やっぱり だめでしたね...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "{JPN}こんにちは {STR_VAR_3}です\n"
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2}ばんめのでしです!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{JPN}{STR_VAR_3}から このチームがいいと\n"
	.string "{JPN}いわれました\n"
	.string "{JPN}{STR_VAR_1}をつかう {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "{JPN}それと {STR_VAR_1} をつかえる\n"
	.string "{JPN}{STR_VAR_2} が ひとひき\p"
	.string "{JPN}わるくないでしょ?\n"
	.string "{JPN}いっしょに チームをくまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "{JPN}よし! よろしくね!\n"
	.string "{JPN}あしをひっぱらないでよね!\l"
	.string "{JPN}とうろくしてくるから!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "{JPN}え? なんで だめなの?\n"
	.string "{JPN}ひとをみるめがないなあ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "{JPN}ぼくは {STR_VAR_3}\n"
	.string "{JPN}トライアスリートだよ\l"
	.string "{JPN}まいにち ジョギングに とれーにんぐ\p"
	.string "{JPN}らっぷも やってて いそがしいんだ\p"
	.string "{JPN}{STR_VAR_1} の だい{STR_VAR_2}ごうの\nでしでもあるんだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "{JPN}{STR_VAR_3} が すすめてくれたのは\n"
	.string "{JPN}{STR_VAR_1} をつかう {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "{JPN}それと {STR_VAR_1} をつかう\n"
	.string "{JPN}{STR_VAR_2}\p"
	.string "{JPN}iそがしいなかでも\n"
	.string "{JPN}がんばって そだてたんだ\p"
	.string "{JPN}タッグチームを くんで\n"
	.string "{JPN}ちょうせんしよう!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "{JPN}ありがとう! そのいきだ!\n"
	.string "{JPN}とうろくしてくるから まってて!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "{JPN}いそがしいなか じかんをさいて\n"
	.string "{JPN}きたのに! かんべんしてよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "{JPN}やあ!\n"
	.string "{JPN}ちょうしはどう?\p"
	.string "{JPN}{STR_VAR_3} だよ {STR_VAR_1} の\n"
	.string "{JPN}だい{STR_VAR_2}ごうの でしだ よろしく!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "{JPN}きいて きいて! {STR_VAR_3} が\n"
	.string "{JPN}すすめてくれた ポケモンのはなし!\l"
	.string "{JPN}{STR_VAR_1} をもつ {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "{JPN}{STR_VAR_1} をもつ {STR_VAR_2}\n"
	.string "{JPN}もちろん ばっちり そだてたよ!\p"
	.string "{JPN}どう? チームをくまない?\n"
	.string "{JPN}ぜったい いいコンビになるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "{JPN}やった! たのしくなりそう!\n"
	.string "{JPN}とうろくしてくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "{JPN}ああ ひどいよ!\n"
	.string "{JPN}すいせんされてきたのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "{JPN}じこしょうかいを させてください\n"
	.string "{JPN}わたくし {STR_VAR_3} ともうします\p"
	.string "{JPN}{STR_VAR_1} の だい{STR_VAR_2}ごうの\n"
	.string "{JPN}でしを つとめております$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "{JPN}{STR_VAR_3} の けんめいな\n"
	.string "{JPN}アドバイスを いただき\l"
	.string "{JPN}{STR_VAR_1} をもつ {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "{JPN}それと {STR_VAR_1} をもつ\n"
	.string "{JPN}{STR_VAR_2} を そだてました\pどうか タッグチームを\nくんでいただけませんか!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "{JPN}ああ... うれしいです!\n"
	.string "{JPN}ぜったい がんばります!\p"
	.string "{JPN}もちろん とうろく\n"
	.string "{JPN}してきます!\nまっていて ください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "{JPN}きみと いっしょに やりたかった\n"
	.string "{JPN}{PLAYER}...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "{JPN}きゃあ! はなしかけて\n"
	.string "{JPN}くれたんですね!\n"
	.string "{JPN}うれしすぎます!\p"
	.string "{JPN}わたし {STR_VAR_3}です!\n{STR_VAR_1}の だい {STR_VAR_2}ごう\nでしです!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "{JPN}{STR_VAR_3} の アドバイスで\n"
	.string "{JPN}{STR_VAR_1} をつかう {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "{JPN}それと {STR_VAR_1} をつかう\n"
	.string "{JPN}{STR_VAR_2} を きたえました\p"
	.string "{JPN}おねがいです ねがいを\n"
	.string "{JPN}かなえてください!\pタッグチームの パートナーに\nなってください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "{JPN}きゃあ! きもちが\n"
	.string "{JPN}ふわふわします!\n"
	.string "{JPN}ありがとう ございます!\lすぐに とうろく\nしてきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "{JPN}うわあん! あわれみは\n"
	.string "{JPN}ないんですか?\nでも それが かっこいい...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "{JPN}やっほー! {STR_VAR_1} の\n"
	.string "{JPN}だい{STR_VAR_2}ごうの でしだよ!\p"
	.string "{JPN}{STR_VAR_3} だよ よろしく!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "{JPN}しょうの {STR_VAR_3} が すすめてくれた\n"
	.string "{JPN}{STR_VAR_1} のたつじんの {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "{JPN}それと {STR_VAR_1} のたつじんの\n"
	.string "{JPN}{STR_VAR_2}\p"
	.string "{JPN}いいでしょ?\n"
	.string "{JPN}パートナーになってくれるよね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "{JPN}よし さいこう!\n"
	.string "{JPN}とうろくを さっさと すませてくる!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "{JPN}ぐわあああ!\n"
	.string "{JPN}けいさんだかいやつだな {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "{JPN}おい! たいへんだ!\n"
	.string "{JPN}バトルタワーが きょうで\n"
	.string "{JPN}さいごだって!\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}うそだよ!\n"
	.string "{JPN}ひとは おれを {STR_VAR_3}って\n"
	.string "{JPN}よぶし おれも そう おもう!\n{STR_VAR_1}の だい 1000ごう\nでしだ!\lほんとは だい {STR_VAR_2}ごう\nだけどな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{JPN}{STR_VAR_3} に アドバイスを\n"
	.string "{JPN}もらったんだ\l{STR_VAR_1} をもつ {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{JPN}{STR_VAR_1} をもつ {STR_VAR_2}\n"
	.string "{JPN}それぞれ 10ひきずつ もってる!\l"
	.string "{JPN}ほんとうは 1ひきずつだけど!\p"
	.string "{JPN}どうかな?\n"
	.string "{JPN}タッグバトルを やってみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "{JPN}やったー!\n"
	.string "{JPN}おれいに ポケモンを あげるよ!\p"
	.string "{JPN}なーんて うそだけどね! でも\n"
	.string "{JPN}ほんとうに とうろく してくるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "{JPN}ああ つめたいなあ! それなら\n"
	.string "{JPN}バトルタワーを はかいしちゃうぞ!\p"
	.string "{JPN}もちろん うそだけどね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "{JPN}よお! おれは のりのり だぜ!\n"
	.string "{JPN}ポケモンを あやつってるぜ!\p"
	.string "{JPN}おれは {STR_VAR_3} ラップする かいじん!\n"
	.string "{JPN}なきむしと まちがえるなよ!\p"
	.string "{JPN}おれは {STR_VAR_1}の だい{STR_VAR_2}の でし!\n"
	.string "{JPN}おれを あなどっちゃ いけねえぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "{JPN}{STR_VAR_3}の アドバイスを きいて\n"
	.string "{JPN}じまんの チームを つくったぜ!\l"
	.string "{JPN}{STR_VAR_1}つかいの {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "{JPN}それと {STR_VAR_1}つかいの\n"
	.string "{JPN}{STR_VAR_2}だ!\p"
	.string "{JPN}この であいを きねんして\n"
	.string "{JPN}タッグで しょうりを いわおうぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "{JPN}よっしゃ! きみの スタイルが\n"
	.string "{JPN}きにいったぜ! とうろく してくる!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "{JPN}おいおい {PLAYER}! それは つめたいぜ!\n"
	.string "{JPN}もし いって いいなら な!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "{JPN}やっほー!\n"
	.string "{JPN}あ にげないで! たのしんでただけ!\p"
	.string "{JPN}ハーイ! わたし {STR_VAR_3}よ!\n"
	.string "{JPN}わたし {STR_VAR_1}の だい{STR_VAR_2}の でしなの!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{JPN}{STR_VAR_3}が おしえてくれたの\n"
	.string "{JPN}{STR_VAR_1}つかいの {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "{JPN}それと {STR_VAR_1}つかいの\n"
	.string "{JPN}{STR_VAR_2}を えらんだわ!\p"
	.string "{JPN}ねえ どうかしら?\n"
	.string "{JPN}わたしを よろこばせて!\p"
	.string "{JPN}おねがい! おがんでるの!\n"
	.string "{JPN}いっしょに いかせて ブルーにしないで!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "{JPN}やったー! うんが みかたよ!\n"
	.string "{JPN}ほんとうに うれしいわ!\p"
	.string "{JPN}たたかう まえに\n"
	.string "{JPN}とうろく してくるわね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "{JPN}ことわるの?\n"
	.string "{JPN}{PLAYER} かなしく させるのね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "{JPN}ゲホッ!\p"
	.string "{JPN}ああ ごめん かぜを ひいてるんだ\n"
	.string "{JPN}ポケモンは げんきだけどね\p"
	.string "{JPN}ぼくの なまえは {STR_VAR_3} {STR_VAR_1}の\n"
	.string "{JPN}だい{STR_VAR_2}の でし ゲホッ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "{JPN}{STR_VAR_3}の アドバイスを こころに きざんで\n"
	.string "{JPN}チームを くみました\l"
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2} それと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2}です\p"
	.string "{JPN}まいにち きたえました\n"
	.string "{JPN}かぜや あめの ひも\p"
	.string "{JPN}だから かぜを ひいちゃったんだと\n"
	.string "{JPN}おもいます\p"
	.string "{JPN}それが ぼくの やりかたです\n"
	.string "{JPN}タッグパートナーに なりませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "{JPN}ありがとう かんしゃします!\n"
	.string "{JPN}ゲホ ゲホ!\l"
	.string "{JPN}とうろく してきますね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "{JPN}だめですか?\n"
	.string "{JPN}{PLAYER} いいコンビに なれると おもうんですが$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "{JPN}あ こんにちは!\n"
	.string "{JPN}きんちょうします\p"
	.string "{JPN}わたし {STR_VAR_3}です\n"
	.string "{JPN}わたしは {STR_VAR_1}の だい{STR_VAR_2}の でしです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{JPN}{STR_VAR_3}さんが このチームが いいって\n"
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2} それと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2}です\n"
	.string "{JPN}じしんが ありませんが\n"
	.string "{JPN}いっしょに いかせて もらえませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "{JPN}あ ありがとう ございます!\n"
	.string "{JPN}はずかしいですが がんばります!\n"
	.string "{JPN}とうろく してきますね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "{JPN}ああ だめって いわないで!\n"
	.string "{JPN}もう じゅうぶん\nはずかしいんだから...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "{JPN}わたしは {STR_VAR_3}です うそでは ありません\n"
	.string "{JPN}わたしは {STR_VAR_1}の だい{STR_VAR_2}の でしです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{JPN}{STR_VAR_3}が わたしの チームを すすめました\n"
	.string "{JPN}アドバイスが まことに きこえたので\n"
	.string "{JPN}{STR_VAR_1}つかいの {STR_VAR_2} それと$"
	.string ""

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{JPN}{STR_VAR_1}つかいの {STR_VAR_2}を\n"
	.string "{JPN}つれてくる ことに しました\p"
	.string "{JPN}もし よろしければ タッグチームの\nパートナーとして うけいれて いただきたく$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "{JPN}ほんとうに うけいれて くださるのですか?\n"
	.string "{JPN}そうでなければ ひどすぎます\n"
	.string "{JPN}しかし さんせい していただいたので けっこうです\n"
	.string "{JPN}ふたりぶん とうろく してまいります$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "{JPN}ん? なんで ことわるんだ?\n"
	.string "{JPN}ふざけてるのか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "{JPN}わたし {STR_VAR_1}!\nミニスカートよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "{JPN}もってるのは {STR_VAR_1}を\n"
	.string "{JPN}つかう {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう\n"
	.string "{JPN}{STR_VAR_2}よ!\p"
	.string "{JPN}パートナーになってくれる?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "{JPN}ありがとう!\n"
	.string "{JPN}とうろく してくるわね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "{JPN}パートナーは いやなの?\n"
	.string "{JPN}あとで こうかい するわよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "{JPN}こんにちは!\p"
	.string "{JPN}ぼく たんぱんこぞうの\n{STR_VAR_1}だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "{JPN}なにを もってるか しりたい?\n"
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2}だよ!\p"
	.string "{JPN}タッグパートナーになって\n"
	.string "{JPN}くれるよね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "{JPN}やったー!\n"
	.string "{JPN}とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "{JPN}えー! ぼくのポケモンと\n"
	.string "{JPN}タッグくんだら むてきだよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "{JPN}やっほー!\n"
	.string "{JPN}やまおとこの {STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "{JPN}なにを もってるか しってるか?\n"
	.string "{JPN}{STR_VAR_1}つかいの {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "{JPN}{STR_VAR_1}つかいの {STR_VAR_2}だ!\p"
	.string "{JPN}どうだ?\n"
	.string "{JPN}タッグチーム くまないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "{JPN}やっほー!\n"
	.string "{JPN}とうろく してくるぞ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "{JPN}きみと いっしょに たたかいたかった\n"
	.string "{JPN}んだがなあ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "{JPN}こんにちは!\n"
	.string "{JPN}おとなのおねえさんの {STR_VAR_1}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "{JPN}わたしが そだててるのを\n"
	.string "{JPN}しってる? {STR_VAR_1}の {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "{JPN}{STR_VAR_1}の {STR_VAR_2}よ!\p"
	.string "{JPN}どうかしら?\n"
	.string "{JPN}タッグチーム くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "{JPN}すてき!\n"
	.string "{JPN}とうろく してくるわね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "{JPN}ざんねん!\p"
	.string "{JPN}わたしたち ふたりなら\n"
	.string "{JPN}さいこうだったのに!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "{JPN}よお!\p"
	.string "{JPN}おれが だれか しってるか?\n"
	.string "{JPN}つりびとの {STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "{JPN}もってるのは {STR_VAR_1}つかいの\n"
	.string "{JPN}{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "{JPN}{STR_VAR_1}つかいの {STR_VAR_2}だ.\p"
	.string "{JPN}どうだ?\n"
	.string "{JPN}おれと たたかってくれるか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "{JPN}よし よし!\n"
	.string "{JPN}まかせとけ!\p"
	.string "{JPN}とうろく してくるからな.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "{JPN}ぴったりの コンビだった\nのになあ...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "{JPN}はじめまして.\n"
	.string "{JPN}わたくし {STR_VAR_1} と\nもうします おじょうさまです.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "{JPN}わたくしは {STR_VAR_1} を\n"
	.string "{JPN}おぼえた {STR_VAR_2} ひとひきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "{JPN}{STR_VAR_1} を おぼえた\n"
	.string "{JPN}{STR_VAR_2} ひとひきを\n"
	.string "{JPN}つれております.\pいかがでしょうか.\nあなたの パートナーと\nさせていただきたいのです.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "{JPN}ありがとうございます.\n"
	.string "{JPN}とうろくは わたくしが\nいたします.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "{JPN}わたくしを パートナーに\n"
	.string "{JPN}しなかったこと きっと\nこうかいなさいますわ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "{JPN}わたし トライアスリート\n{STR_VAR_1} よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "{JPN}わたしが もってるのは...\n"
	.string "{JPN}{STR_VAR_1}を つかう\n{STR_VAR_2}を 1ぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "{JPN}{STR_VAR_1} を おぼえた\n"
	.string "{JPN}{STR_VAR_2} ひとひき!\n"
	.string "{JPN}これが わたしの チーム!\p"
	.string "{JPN}おねがい!\nわたしと タッグチームを\nくんでくれる?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "{JPN}やったあ! ありがとう!\n"
	.string "{JPN}カウンターで とうろくしてくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "{JPN}わたしたちふたりなら\n"
	.string "{JPN}ぜったい つよかったのに!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "{JPN}やあ!\n"
	.string "{JPN}ぼく むしとり {STR_VAR_1} だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "{JPN}ぼくの ポケモンを みてよ!\n"
	.string "{JPN}{STR_VAR_1} を おぼえた\n{STR_VAR_2} ひとひきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "{JPN}{STR_VAR_1} を おぼえた\n"
	.string "{JPN}{STR_VAR_2} ひとひき!\p"
	.string "{JPN}ねえ きいてよ!\nタッグチーム くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "{JPN}やったね!\p"
	.string "{JPN}カウンターで とうろくの\n"
	.string "{JPN}てつづき してくるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "{JPN}ええー ぼくの ポケモン\n"
	.string "{JPN}すごいのに.\nこうかいするよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "{JPN}こんにちは!\n"
	.string "{JPN}ぼく じゅくせい {STR_VAR_1} です!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "{JPN}ぼくが そだてているのは\n"
	.string "{JPN}{STR_VAR_1} を つかう\n{STR_VAR_2} ひとひきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "{JPN}{STR_VAR_1} を つかう\n"
	.string "{JPN}{STR_VAR_2} ひとひき です.\p"
	.string "{JPN}なかなか いいでしょう?\n"
	.string "{JPN}タッグチームを くみませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "{JPN}ありがとうございます!\n"
	.string "{JPN}とうろく してきますね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "{JPN}ざんねんだなあ...\p"
	.string "{JPN}きみの パートナーと して\n"
	.string "{JPN}べんきょう させて もらいたかった\nんだ...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "{JPN}よう! おしえてやるよ!\n"
	.string "{JPN}おれは おぼっちゃま {STR_VAR_1} だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "{JPN}なにを もってるか あててみろ!\n"
	.string "{JPN}{STR_VAR_1} を おぼえた\n{STR_VAR_2} ひとひきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "{JPN}{STR_VAR_1} を おぼえた\n"
	.string "{JPN}{STR_VAR_2} ひとひき だ!\p"
	.string "{JPN}おれと タッグチームを くむ\nチャンスを やってやるよ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "{JPN}かしこいな!\p"
	.string "{JPN}とうろくの てつづき\n"
	.string "{JPN}すぐに おわらせてやる!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "{JPN}このおれさまを ことわるのか?\n"
	.string "{JPN}ぜったい こうかいするぞ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "{JPN}はあーっ!\n"
	.string "{JPN}わたしは からてだい {STR_VAR_1} だ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "{JPN}わたしの なかまとして\n"
	.string "{JPN}{STR_VAR_1} を つかう\n{STR_VAR_2} ひとひき$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "{JPN}それと {STR_VAR_1}を つかう\n"
	.string "{JPN}{STR_VAR_2} ですよ.\p"
	.string "{JPN}どうか おねがいします!\n"
	.string "{JPN}ぼくを タッグパートナーに\nしてください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "{JPN}ひやー!\n"
	.string "{JPN}さっそく とうろく してきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "{JPN}そうか... つぎに あった ときに\n"
	.string "{JPN}きかいが あると いいな...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "{JPN}こんにちは!\n"
	.string "{JPN}わたし {STR_VAR_1}.\nうきわガールよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "{JPN}わたしが もってるのはね.\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}よ!\nタッグチームに いれてくれる?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "{JPN}ありがとう!\n"
	.string "{JPN}いま とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "{JPN}パートナーに なってたら\n"
	.string "{JPN}とっても つよく なれたのにな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "{JPN}ごきげんよう...\n"
	.string "{JPN}わたしは おかると マニア\nの {STR_VAR_1}...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "{JPN}わたしが つれてるのは\n"
	.string "{JPN}{STR_VAR_1}を つかう\n{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう\n"
	.string "{JPN}{STR_VAR_2}...\p"
	.string "{JPN}おねがい します...\nタッグチームを くみませんか...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "{JPN}かんしゃ します...\n"
	.string "{JPN}とうろく してきます...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "{JPN}あなたと いっしょに\nたたかいたかった...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "{JPN}はじめまして! わたくし {STR_VAR_1}.\n"
	.string "{JPN}ポケモンブリーダーです!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "{JPN}いいこたちを そだててますよ!\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}です!\p"
	.string "{JPN}いかがでしょう?\nわたしと タッグチームを\nくみませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "{JPN}ありがとうございます!\p"
	.string "{JPN}とうろくは わたしが やりますので\n"
	.string "{JPN}ここで おまちください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "{JPN}きみの パートナーに\n"
	.string "{JPN}なるのを たのしみに\nしていたのに...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "{JPN}こんにちは!\n"
	.string "{JPN}わたし トライアスリート\n{STR_VAR_1}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "{JPN}わたしの そうそうメンバーはね.\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}よ!\p"
	.string "{JPN}どう?\nわたしと タッグチーム くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "{JPN}やったね!\p"
	.string "{JPN}すぐに とうろく おわらせて\n"
	.string "{JPN}くるから!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "{JPN}あなたと わたしなら\n"
	.string "{JPN}さいこうだったのに...\nざんねんね...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "{JPN}よう! おれは {STR_VAR_1}!\n"
	.string "{JPN}トライアスリートだ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "{JPN}おれの たくましいチームは\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}だ!\p"
	.string "{JPN}なかなか だろ?\nおれたち タッグチーム くもうぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "{JPN}よし!\n"
	.string "{JPN}いっそくで とうろく してくる!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "{JPN}きみと タッグを くんで\n"
	.string "{JPN}たたかいたかったな...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "{JPN}わたし バトルガール {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "{JPN}わたしが きたえてるのは\n"
	.string "{JPN}{STR_VAR_1}を つかう {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう {STR_VAR_2}よ!\p"
	.string "{JPN}この コンビ どう?\n"
	.string "{JPN}わたしたち くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "{JPN}ありがとう!\p"
	.string "{JPN}いますぐ とうろく してくるね!$"
	.string ""

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "{JPN}あなたとなら さいきょうの\n"
	.string "{JPN}タッグチームが つくれると\nおもったのに...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "{JPN}おれは トライアスリート {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "{JPN}ぼくは {STR_VAR_1} を\n"
	.string "{JPN}つかえる {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "{JPN}{STR_VAR_1} を もつ\n"
	.string "{JPN}{STR_VAR_2} で はしってるんだ!\p"
	.string "{JPN}タッグチームを くめるかも\nしれないよね. どうかな?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "{JPN}ありがとう!\p"
	.string "{JPN}ぼくたちを とうろく してくるよ.\n"
	.string "{JPN}いま すぐにね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "{JPN}あー  ざんねんだなあ.\n"
	.string "{JPN}さいきょうの タッグチーム だったのに!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "{JPN}ぼく?\n"
	.string "{JPN}うきわボーイの {STR_VAR_1} だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "{JPN}なにを もってるかって?\n"
	.string "{JPN}{STR_VAR_1} を もつ {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "{JPN}{STR_VAR_1} を もつ\n"
	.string "{JPN}{STR_VAR_2} だよ!\p"
	.string "{JPN}ねえ?\nぼくと チームを くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "{JPN}やったあ!\p"
	.string "{JPN}とうろく してくるよ!\n"
	.string "{JPN}いっしょに がんばろうね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "{JPN}ぼくの ポケモンは\n"
	.string "{JPN}つよいんだよ...\nチームを くまないなんて\nざんねんだな$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "{JPN}イエーイ!\n"
	.string "{JPN}ギタリストの {STR_VAR_1} だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "{JPN}ぼくの なかまを みてよ!\n"
	.string "{JPN}{STR_VAR_1} を もつ {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "{JPN}{STR_VAR_1} を もつ\n"
	.string "{JPN}{STR_VAR_2} だよ!\p"
	.string "{JPN}イエーイ! かっこいいでしょ?\nタッグチームで デュエット しようよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "{JPN}イエーイ! サイコーだぜ!\n"
	.string "{JPN}とうろく してくるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "{JPN}ぼくの ポケモンは ロック だぜ!\n"
	.string "{JPN}こうかい するよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "{JPN}はじめまして.\n"
	.string "{JPN}しんし の {STR_VAR_1} です.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "{JPN}わたしには しんらいできる\n"
	.string "{JPN}{STR_VAR_1} を つかう {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "{JPN}{STR_VAR_1} を つかう\n"
	.string "{JPN}{STR_VAR_2} が います.\p"
	.string "{JPN}タッグチームの パートナーに\nなって いただけませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "{JPN}ああ  しんらい していただき\n"
	.string "{JPN}ありがとうございます.\lとうろく を すませて まいります.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "{JPN}それは じつに\n"
	.string "{JPN}ざんねんですな...\p"
	.string "{JPN} つぎの きかいを\nたのしみに しておりますよ...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "{JPN}こんにちは. {STR_VAR_1} です.\n"
	.string "{JPN}ポケモンだいすきクラブの メンバーです.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "{JPN}いま いっしょに いるのは\n"
	.string "{JPN}{STR_VAR_1} を おぼえた {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "{JPN}{STR_VAR_1} を もつ\n"
	.string "{JPN}{STR_VAR_2} です.\p"
	.string "{JPN}どうですか?\nぼくの タッグパートナーに なりませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "{JPN}ありがとうございます!\n"
	.string "{JPN}とうろく を しておきますね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "{JPN}わたしの ポケモンは\n"
	.string "{JPN}いちりゅうなのに...\nそれが わからないとは\nざんねんですな$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "{JPN}フム!\n"
	.string "{JPN}エキスパートの {STR_VAR_1} だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "{JPN}ワシが きたえあげた ポケモンは\n"
	.string "{JPN}{STR_VAR_1} を もつ {STR_VAR_2} と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "{JPN}{STR_VAR_1} を もつ\n"
	.string "{JPN}{STR_VAR_2} だ!\pワシと タッグチームを くまんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "{JPN}フム!\n"
	.string "{JPN}すぐに とうろく してこよう!\l"
	.string "{JPN}ふたりとも がんばるのだ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "{JPN}きみの せんたくが\n"
	.string "{JPN}ただしいことを\nいのろう...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "{JPN}こんにちは こんにちは.\n"
	.string "{JPN}わたし{STR_VAR_1} エキスパートです.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "{JPN}わたしのポケモンは\n"
	.string "{JPN}てっていてきにそだてました.\n{STR_VAR_1}をもつ{STR_VAR_2}が1ぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "{JPN}{STR_VAR_1}をもつ{STR_VAR_2}が\n"
	.string "{JPN}1ぴき\n"
	.string "{JPN}これがわたしのてもちです.\pわたしとチームをくみませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "{JPN}よろしい よろしい.\n"
	.string "{JPN}すぐにとうろくしてまいります.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "{JPN}つぎにおあいするときには\n"
	.string "{JPN}チームをくめるかもしれませんね.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "{JPN}おれはりゅうつかい{STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "{JPN}おれがきたえあげたチームは\n"
	.string "{JPN}{STR_VAR_1}をもつ{STR_VAR_2}が1ぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "{JPN}{STR_VAR_1}をもつ{STR_VAR_2}が\n"
	.string "{JPN}1ぴきだ!\p"
	.string "{JPN}どうだ?\nおれのパートナーにならないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "{JPN}よし ぜんりょくでがんばるぞ!\n"
	.string "{JPN}いまからとうろくしてくる!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "{JPN}おれよりつよいパートナーなんて\n"
	.string "{JPN}そうそういないぞ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "{JPN}ぼくはとりつかい{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "{JPN}どんなポケモンをもっているかって?\n"
	.string "{JPN}{STR_VAR_1}をもつ{STR_VAR_2}が1ぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "{JPN}{STR_VAR_1}をもつ{STR_VAR_2}が\n"
	.string "{JPN}1ぴきです.\p"
	.string "{JPN}ぼくたち いいタッグチームに\nなれるとおもいませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "{JPN}やった ありがとう!\n"
	.string "{JPN}とうろくはぼくがやっておくよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "{JPN}ぼくとポケモンはつよいのに.\n"
	.string "{JPN}ざんねんです.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "{JPN}おれはにんじゃごう{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "{JPN}おれのポケモンチームは\n"
	.string "{JPN}{STR_VAR_1}をもつ{STR_VAR_2}が1ぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "{JPN}{STR_VAR_1}をもつ{STR_VAR_2}が\n"
	.string "{JPN}1ぴきだ!\pいっしょにタッグチームをくもう!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "{JPN}やったー!\n"
	.string "{JPN}とうろくしてくる!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "{JPN}おれのつよいポケモンを\n"
	.string "{JPN}みかたにしなくてこうかいするぞ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "{JPN}こんにちは!\n"
	.string "{JPN}わたしパラソルレディの{STR_VAR_1}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "{JPN}いまわたしをごあんないしているのは\n"
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}が\n"
	.string "{JPN}1ぴきよ.\p"
	.string "{JPN}すてきでしょう?\n"
	.string "{JPN}わたしたちとタッグチームをくまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "{JPN}ありがとう!\p"
	.string "{JPN}カウンターでとうろくしてくるわね.\n"
	.string "{JPN}おたがいがっかりしないようにしましょ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "{JPN}わたしの ポケモンは\n"
	.string "{JPN}とても つよいのに...\nがっかりだわ...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "{JPN}こんにちは.\n"
	.string "{JPN}ぼく{STR_VAR_1} むしマニアです!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "{JPN}ぼくのポケモンを\n"
	.string "{JPN}みつけたんだ そう.\n{STR_VAR_1}をつかう{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}を\n"
	.string "{JPN}みつけたんだ.\p"
	.string "{JPN}\n"
	.string "{JPN}タッグチームをくんで\nくれないかい?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "{JPN}オーケー!\n"
	.string "{JPN}わかった!\p"
	.string "{JPN}\nとうろくはすぐに\nすませてくるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "{JPN}わたしが みつけた\n"
	.string "{JPN}ポケモンと いっしょなら\nまけなかったのに...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "{JPN}おーい そこの!\n"
	.string "{JPN}オレはせんいん{STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "{JPN}オレのじまんのポケモンを\n"
	.string "{JPN}みせてやる!\n{STR_VAR_1}をつかう{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}だ!\p"
	.string "{JPN}\n"
	.string "{JPN}もちろんことわったりしないよな.\nいっしょにチームをくもうぜ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "{JPN}それでこそだ!\n"
	.string "{JPN}いまからとうろくしてくるぜ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "{JPN}あいてをあっとうできたのに!\n"
	.string "{JPN}ざんねんだな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "{JPN}こんにちは ぼくは{STR_VAR_1}.\n"
	.string "{JPN}コレクターなんだ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "{JPN}ぼくのコレクションの\n"
	.string "{JPN}たからものは\n{STR_VAR_1}をつかう{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}だ!\p"
	.string "{JPN}\n"
	.string "{JPN}すごいだろ?\nいっしょにチームをくもう.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "{JPN}やったー!\p"
	.string "{JPN}\n"
	.string "{JPN}じかんをむだにしないで\nふたりでとうろくしてくるよ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "{JPN}がっかりだよ.\n"
	.string "{JPN}ぼくのポケモンが\nわからないんだね.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "{JPN}やあ ぼくは{STR_VAR_1}.\n"
	.string "{JPN}ポケモンレンジャーだ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "{JPN}ぼくといっしょにいるのは\n"
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}だ!\p"
	.string "{JPN}\n"
	.string "{JPN}すごいタッグチームに\nなるとおもわないかい?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "{JPN}それはすばらしい!\n"
	.string "{JPN}いまからとうろくをすませてくる.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "{JPN}つぎはぼくのポケモンを\n"
	.string "{JPN}えらんでくれるかい?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "{JPN}わたしのなまえは{STR_VAR_1}.\n"
	.string "{JPN}ポケモンレンジャーよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "{JPN}わたしのチームについて\n"
	.string "{JPN}はなしましょう.\n{STR_VAR_1}をつかう{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "{JPN}{STR_VAR_1}をつかう{STR_VAR_2}が\n"
	.string "{JPN}いるのよ!\p"
	.string "{JPN}\nわたしのなかまたちと\nタッグチームをくまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "{JPN}さいこうのチームになるわ!\n"
	.string "{JPN}いそいでとうろくしてくるわね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "{JPN}つぎはわたしのポケモンを\n"
	.string "{JPN}えらんでもらいたいわ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "{JPN}はじめまして.わたしは{STR_VAR_1}.\n"
	.string "{JPN}アロマなおねえさんよ.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "{JPN}わたしは{STR_VAR_1}をつかう\n"
	.string "{JPN}{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう\n"
	.string "{JPN}{STR_VAR_2}を いっぴき.\p"
	.string "{JPN}きに いって もらえると\n"
	.string "{JPN}いいのですが.\nパートナーに なりませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "{JPN}うけて いただき\n"
	.string "{JPN}とても こうえいです.\nすぐに とうろく してきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "{JPN}つぎに あう ときには\n"
	.string "{JPN}タッグチームが くめると\nいいですね.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "{JPN}ぼくが だれか しりたい?\n"
	.string "{JPN}いせきマニアの {STR_VAR_1}だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "{JPN}ぼくが つれている ポケモンは\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}が いっぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}が いっぴき!\p"
	.string "{JPN}おもしろいでしょ?\nきみと パートナーを くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "{JPN}いい はんだんだね!\n"
	.string "{JPN}とうろくの てつづき してくるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "{JPN}うーん...\n"
	.string "{JPN}ぼくの ポケモンは\nつよいと おもうんだけど...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "{JPN}おれは エリートトレーナーの\n{STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "{JPN}いま おれが もっている ポケモンは\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}が いっぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}が いっぴき.\n"
	.string "{JPN}かっこいいだろ?\p"
	.string "{JPN}おれたちで タッグチームを\nくんだら かっこいいと おもわない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "{JPN}かっこいい!\n"
	.string "{JPN}すぐに とうろく してくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "{JPN}おれたちが さいこうの\n"
	.string "{JPN}チームに なると おもったんだが.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "{JPN}わたし エリートトレーナーの\n{STR_VAR_1}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "{JPN}わたしが そだてている チームは\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}が いっぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}が いっぴき.\p"
	.string "{JPN}どうかしら?\nタッグパートナーに ならない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "{JPN}いいじゃない!\n"
	.string "{JPN}とうろく してくるわ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "{JPN}わたしたちなら\n"
	.string "{JPN}つよいチームに\nなれたとおもうのに...$"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "{JPN}よー!\n"
	.string "{JPN}ポケモンマニアの {STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "{JPN}おれみたいな やつが なにを\n"
	.string "{JPN}もってるって?\n{STR_VAR_1}を おぼえた\n{STR_VAR_2}が いっぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}が いっぴき \n"
	.string "{JPN}ってところだな!\p"
	.string "{JPN}やろうぜ!\nタッグチームで あばれまくろう!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "{JPN}いいね!\n"
	.string "{JPN}ふたりぶん とうろく してくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "{JPN}おれの ポケモンは きょうぼうだぜ!\n"
	.string "{JPN}こうかい しても しらないからな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "{JPN}よう!\n"
	.string "{JPN}たんぱんこぞうの {STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "{JPN}おれの しゅぎょうで できあがったのは\n"
	.string "{JPN}{STR_VAR_1}を おぼえた\n{STR_VAR_2}が いっぴきと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}が いっぴき!\p"
	.string "{JPN}どうだ?\nタッグチームを くまないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "{JPN}よし!\n"
	.string "{JPN}とうろく してくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "{JPN}こんど あったときは\n"
	.string "{JPN}ぜったい いっしょに チームを\nくんでくれよな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "{JPN}おれは {STR_VAR_1}!\nキャンプボーイだ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "{JPN}{STR_VAR_2}を おぼえた\n"
	.string "{JPN}{STR_VAR_1}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{JPN}{STR_VAR_2}を おぼえた\n"
	.string "{JPN}{STR_VAR_1}を そだててるんだ\p"
	.string "{JPN}\nいっしょに チームを くまないか?\nきっと たのしいぞ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "{JPN}やったー!\n"
	.string "{JPN}とうろく してくるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "{JPN}こんどでいいからさ!\n"
	.string "{JPN}きみと チーム くみたいんだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "{JPN}こんにちは!\n"
	.string "{JPN}わたし {STR_VAR_1}!\nピクニックガールよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "{JPN}わたしが つれてきた ポケモンは\n"
	.string "{JPN}{STR_VAR_1}を おぼえた {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}よ\p"
	.string "{JPN}\nタッグチームで いっしょに\nたたかってみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "{JPN}ありがとう!\n"
	.string "{JPN}いますぐ とうろく してくるわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "{JPN}べつの きかいに あなたと\n"
	.string "{JPN}チームを くめたら いいなあ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "{JPN}おれは サイキッカーの\n{STR_VAR_1}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "{JPN}おれが そだてた ふたりは\n"
	.string "{JPN}{STR_VAR_1}を おぼえた {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}だ\p"
	.string "{JPN}\nおれと いっしょに タッグチームを\nくまないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "{JPN}よし!\n"
	.string "{JPN}とうろくは おれが やっておく!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "{JPN}また あったら そのときは\n"
	.string "{JPN}きみと チームを くみたいな$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "{JPN}わたしは {STR_VAR_1}\n"
	.string "{JPN}サイキッカーよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "{JPN}{STR_VAR_1}を おぼえた {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "{JPN}{STR_VAR_1}を おぼえた {STR_VAR_2}--\n"
	.string "{JPN}このこたちは わたしの でしよ\p"
	.string "{JPN}\n"
	.string "{JPN}タッグチーム パートナーシップに\nきょうみは ない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "{JPN}ありがとう\n"
	.string "{JPN}とうろくの てつづきを\nしてくるわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "{JPN}べつの きかいに どうめいを\n"
	.string "{JPN}むすべることを のぞんでいるわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "{JPN}わたし じゅくせいの\n{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "{JPN}{STR_VAR_1}を おぼえた {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "{JPN}と {STR_VAR_1}を おぼえた\n"
	.string "{JPN}{STR_VAR_2}が わたしの\n"
	.string "{JPN}ポケモンペア よ\p"
	.string "{JPN}\nタッグチームの パートナーに\nなってもらえる?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "{JPN}わあ ありがとう!\n"
	.string "{JPN}すぐに カウンターで とうろく\nしてくるわ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "{JPN}おねがい!\n"
	.string "{JPN}こんどは いっしょに やらせて?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "{JPN}やあ! わたし {STR_VAR_1}!\n"
	.string "{JPN}ポケモンブリーダーよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "{JPN}そだてた ポケモンは\n"
	.string "{JPN}{STR_VAR_1}を つかう {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう {STR_VAR_2}よ!\p"
	.string "{JPN}どう? おもしろそうでしょ?\n"
	.string "{JPN}タッグチーム くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "{JPN}やったね!\n"
	.string "{JPN}とうろくは わたしに まかせて!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "{JPN}こんどは ぜったい\n"
	.string "{JPN}いっしょに やるのよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "{JPN}わたし {STR_VAR_1}!\n"
	.string "{JPN}ポケモンファンを\nじまんに おもってるの!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "{JPN}そだてた かわいい ポケモンは\n"
	.string "{JPN}{STR_VAR_1}もちの {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "{JPN}{STR_VAR_1}もちの {STR_VAR_2}よ!\p"
	.string "{JPN}とっても かわいいでしょ?\n"
	.string "{JPN}チームを つくりましょ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "{JPN}ありがとう!\n"
	.string "{JPN}とうろくしに いくわね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "{JPN}わたしの だいじな ポケモンは\n"
	.string "{JPN}さいこうなのよ! しつれいね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "{JPN}こんにちは! スイマーの\n{STR_VAR_1}です!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "{JPN}{STR_VAR_1}を つかう {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "{JPN}{STR_VAR_1}を つかう {STR_VAR_2}を\n"
	.string "{JPN}そだてました!\p"
	.string "{JPN}あなたと わたしで\nタッグチーム つくりましょ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "{JPN}いいですね!\n"
	.string "{JPN}ふたりぶん とうろくします!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "{JPN}こんど あったら ぜったい\n"
	.string "{JPN}タッグチーム よろしく!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "{JPN}よう! おれは {STR_VAR_1}!\n"
	.string "{JPN}トライアスリートだ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "{JPN}なかなかの ポケモンを もってる!\n"
	.string "{JPN}{STR_VAR_1}もちの {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "{JPN}{STR_VAR_1}もちの {STR_VAR_2}だ!\p"
	.string "{JPN}いっしょに タッグチーム つくったら\n"
	.string "{JPN}おもしろそうだな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "{JPN}よし!\n"
	.string "{JPN}とうろく まってろよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "{JPN}こんどは ぜったい\n"
	.string "{JPN}iっしょに やろうぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "{JPN}トライアスリートの\n{STR_VAR_1}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "{JPN}{STR_VAR_1}もちの {STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "{JPN}{STR_VAR_1}を つかえる\n"
	.string "{JPN}{STR_VAR_2}! この2ひきよ!\p"
	.string "{JPN}どうかしら?\n"
	.string "{JPN}いいチームに なりそうでしょ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "{JPN}その こたえ いいね!\n"
	.string "{JPN}とうろく ささっと すませるわ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "{JPN}また パートナーに なって\n"
	.string "{JPN}くれる チャンス くれるよね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "{JPN}やあ! こんにちは!\n"
	.string "{JPN}ぼく {STR_VAR_1}! スイマーだよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "{JPN}ぼくが そだててる ポケモン\n"
	.string "{JPN}みて! {STR_VAR_1}を もった$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "{JPN}{STR_VAR_2}と {STR_VAR_1}を もった\n"
	.string "{JPN}{STR_VAR_2}だよ!\p"
	.string "{JPN}すごいでしょ?\nチーム くんでみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "{JPN}ありがとう!\n"
	.string "{JPN}とうろく すませて くるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "{JPN}また あったら ぜったい\n"
	.string "{JPN}チーム くんでよね?$"

