.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_BLACKTHORN_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_GARBAGEVAR, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_MagnezoneEvo::
	msgbox MauvilleCity_EventScript_MagnezoneEvo_Text, MSGBOX_NPC
	end

MauvilleCity_EventScript_MagnezoneEvo_Text:
	.string "{JPN}レアコイルが しんかするって\n"
	.string "{JPN}しってる?\n"
	.string "{JPN}どうやってやるか しってる?\p"
	.string "{JPN}だって... わたし しりたいの.\p"
	.string "{JPN}いしに かんけいしてたって\n"
	.string "{JPN}しってるの.かみなりのいしよ!\p"
	.string "{JPN}でも それを つかうんじゃない.\n"
	.string "{JPN}たたかうの?もたせるの?\lまじで わからない...$"
MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "{JPN}おじさん:ポケモンの おかげで\n"
	.string "{JPN}この こが げんきに なったのは\l"
	.string "{JPN}いいんじゃが...\lちと げんきすぎるのう...$"
MauvilleCity_Text_WallyWantToChallengeGym:
	.string "{JPN}ミツル: おじさん おねがいします!\p"
	.string "{JPN}ぼく このジムに ちょうせんして\n"
	.string "{JPN}どれだけ つよくなったか\l"
	.string "{JPN}ためしてみたいんです.\pおねがいします! ダメですか?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "{JPN}おじさん: ちょっと まてよ ミツル.\p"
	.string "{JPN}ポケモンと いっしょに くらすように\n"
	.string "{JPN}なってから きみは かなり\l"
	.string "{JPN}つよくなったな.\p"
	.string "{JPN}でも いきなり ジムに ちょうせん\nするなんて むちゃじゃないか?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "{JPN}ミツル: むちゃじゃありません.\p"
	.string "{JPN}ラルトスと ちからを あわせれば \n"
	.string "{JPN}だれにでも かてますよ!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "{JPN}ミツル: あ! {PLAYER}さん!\p"
	.string "{JPN}ぼく であった ときより\n"
	.string "{JPN}ずっと つよくなったんです.\p"
	.string "{JPN}{PLAYER}さん そのことを\n"
	.string "{JPN}きみと おじさんに\l"
	.string "{JPN}わかってもらいたいんです.\p"
	.string "{JPN}{PLAYER}さん おねがいします!\nぼくと バトルしてください!$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "{JPN}ミツル:あ... {PLAYER}が\n"
	.string "{JPN}たたかって くれないと\l"
	.string "{JPN}おじさんに つよくなったこと\lわかって もらえないよ.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "{JPN}おじさん: {PLAYER}くんだったかな?\n"
	.string "{JPN}ミツルの ために おねがいがあるん\l"
	.string "{JPN}だが いちど だけ バトルして\l"
	.string "{JPN}もらえないだろうか?\p"
	.string "{JPN}こんな じょうたいじゃ なにを\nいっても きかないと おもうんだ.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "{JPN}ミツル: {PLAYER}さん おねがいします!\n"
	.string "{JPN}ぼくと バトルしてください.$"

MauvilleCity_Text_WallyHereICome:
	.string "{JPN}ミツル:{PLAYER} ありがとう.\p"
	.string "{JPN}よし... いくよ!$"
MauvilleCity_Text_WallyDefeat:
	.string "{JPN}ミツル:... ... ... ... ... ... ...\p"
	.string "{JPN}... ... ... ... ... ... ... ...\p"
	.string "{JPN}まけちゃった...$"
MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "{JPN}ミツル:おじさん...\n"
	.string "{JPN}シダケタウンに かえるよ...$"
MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{JPN}{PLAYER}さん ありがとう\n"
	.string "{JPN}ございました.\p"
	.string "{JPN}トレーナーって たいへんですね.\p"
	.string "{JPN}ただ ポケモンを もって\n"
	.string "{JPN}バトルさせるだけじゃ\lほんとうの トレーナーじゃない\lってことが わかりました.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "{JPN}おじさん: ミツル そんなに\n"
	.string "{JPN}おちこむ ひつようは ないよ.\p"
	.string "{JPN}つよく つよくなっていけば\n"
	.string "{JPN}いいじゃないか.\p"
	.string "{JPN}さあ いえに かえろう.\n"
	.string "{JPN}みんなが まってるよ.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "{JPN}おじさん: {PLAYER}くん きみが\n"
	.string "{JPN}ミツルが ポケモンを つかまえる\l"
	.string "{JPN}ときに めんどうを みてくれた\l"
	.string "{JPN}トレーナーだったんだな.\p"
	.string "{JPN}こんど シダケタウンに\n"
	.string "{JPN}あそびに きてくれないか?\l"
	.string "{JPN}ミツルも よろこぶと おもうよ.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ピッ!\p"
	.string "{JPN}ミツル:あ {PLAYER}!\p"
	.string "{JPN}おじさんが ポケナビを\n"
	.string "{JPN}かって くれたんだ!\p"
	.string "{JPN}これで いつでも {PLAYER}と\n"
	.string "{JPN}れんらく とれるよ!\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ガチャ!$"
MauvilleCity_Text_RegisteredWally:
	.string "{JPN}ミツルを ポケナビに\n"
	.string "{JPN}とうろくした.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "{JPN}ダツラ:へへ...\n"
	.string "{JPN}その しあい みてたよ!\p"
	.string "{JPN}きみは あの こ ミツルと\n"
	.string "{JPN}ともだちなんだろ?\p"
	.string "{JPN}でも てかげん しないで\n"
	.string "{JPN}みごとに かったね.\p"
	.string "{JPN}そう!それが ほんとうの\n"
	.string "{JPN}ポケモンバトルだ!\p"
	.string "{JPN}そういう トレーナーに\n"
	.string "{JPN}あこがれるよ!\p"
	.string "{JPN}... ... ... ... ... ...\nおうえん してるからね!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "{JPN}テッセン: おお {PLAYER}くん!\n"
	.string "{JPN}げんきが ありそうじゃな!\l"
	.string "{JPN}それは いいことじゃ わっはっは!\p"
	.string "{JPN}よし! きめた!\n"
	.string "{JPN}{PLAYER}くん たのみが あるんじゃ!\p"
	.string "{JPN}キンセツシティには ニューキンセツ\n"
	.string "{JPN}という ちかがいが あるんじゃ.\p"
	.string "{JPN}{PLAYER}くん そこへ いって\n"
	.string "{JPN}はつでんきを とめてもらいたい.\p"
	.string "{JPN}はつでんきが ちょっと\n"
	.string "{JPN}ちょうしわるくてな.\l"
	.string "{JPN}あぶなくなってきたんじゃ.\p"
	.string "{JPN}ほれ これは ニューキンセツに\nはいるための カギじゃ.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "{JPN}テッセン: しんぱいすることはない.\n"
	.string "{JPN}きみなら たやすいことじゃろう.\p"
	.string "{JPN}ニューキンセツの いりぐちは\n"
	.string "{JPN}110ばんどうろから なみのりで\l"
	.string "{JPN}すぐの ところに あるからな.\p"
	.string "{JPN}それじゃあ たのんだぞ!\nわっはっはっは!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "{JPN}テッセン: わっはっはっは!\p"
	.string "{JPN}{PLAYER}くん やっぱりそうじゃった!\n"
	.string "{JPN}きみに たのんで せいかいじゃった!\p"
	.string "{JPN}これは おれいじゃ--\n"
	.string "{JPN}10まんボルトが はいった\l"
	.string "{JPN}わざマシンじゃ!\pさあ うけとってくれ!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "{JPN}テッセン: わっはっはっは!\p"
	.string "{JPN}わかいしが せきにんを もって\n"
	.string "{JPN}がんばる すがたを みるのは\lほんとうに きもちが いいのう!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "{JPN}ポケモンバトルとかって\n"
	.string "{JPN}かっこいいけど...\p"
	.string "{JPN}ポケモンが きずついたら\n"
	.string "{JPN}ちゃんと なおして あげなさいよ.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "{JPN}このまちの みちは きたみなみ\n"
	.string "{JPN}ひがしにしに のびているからね.\p"
	.string "{JPN}そのおかげで いろんなひとが\n"
	.string "{JPN}とおっていくのよ.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "{JPN}サイクルショップ カゼノの\n"
	.string "{JPN}おみせには いったことある?\p"
	.string "{JPN}カゼノの てんしゅは とても\nきさくな ひとよ.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "{JPN}じてんしゃに のっていても\n"
	.string "{JPN}やせいの ポケモンが\lとびだしてくることが あるよ.$"

MauvilleCity_Text_CitySign:
	.string "{JPN}キンセツシティ\n"
	.string "{JPN}あかるく かがやく たのしいまち!$"

MauvilleCity_Text_GymSign:
	.string "{JPN}キンセツシティ ポケモンジム\n"
	.string "{JPN}ジムリーダー: テッセン\l"
	.string "{JPN}あかるく しげきてきな おとこ!$"

MauvilleCity_Text_BikeShopSign:
	.string "{JPN}じゃりを けって たましいを\n"
	.string "{JPN}ゆさぶれ!\l"
	.string "{JPN}サイクルショップ カゼノ$"

MauvilleCity_Text_GameCornerSign:
	.string "{JPN}みんなの あそびば!\n"
	.string "{JPN}キンセツ ゲームコーナー$"

MauvilleCity_Text_ExplainTV:
	.string "{JPN}こんにちは テレビは みてる?\p"
	.string "{JPN}さいきん あたらしい ばんぐみが\n"
	.string "{JPN}たくさん ふえたのよ.\p"
	.string "{JPN}テレビって すごいのよね.\n"
	.string "{JPN}ともだちが きゅうに テレビに\l"
	.string "{JPN}でてたり するんだもの.\p"
	.string "{JPN}それに ときどき なにも いわずに\n"
	.string "{JPN}テレビに だしてくれたり\l"
	.string "{JPN}するのよね.\p"
	.string "{JPN}わたしも いつか テレビに\nでてみたいなあ.\pだから あなたも テレビを みつけ\nたら チェックしてみてね.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "{JPN}こんにちは テレビは チェック\nしてる?$"
