.set LOCALID_CAPT_STERN, 4
.set LOCALID_SS_TIDAL, 5
.set LOCALID_GRUNT, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_SUBMARINE, 8

SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_GARBAGEFLAG
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_GARBAGEFLAG
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_GRUNT
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_GARBAGEFLAG
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	copyobjectxytoperm LOCALID_CAPT_STERN
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "{JPN}もうしわけございません.\n"
	.string "{JPN}ふねをおさがしですか?\p"
	.string "{JPN}もうしわけありませんが \n"
	.string "{JPN}フェリーサービスは\lげんざいりようできません...$"
SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "{JPN}こんにちは フェリーで\n"
	.string "{JPN}りょこうされますか?\nチケットを みせて\nください.$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{JPN}{PLAYER}は チケットを\n"
	.string "{JPN}もっていない...\p"
	.string "{JPN}ほんとうにもうしわけ\n"
	.string "{JPN}ございません.\pフェリーにのるには\nチケットがひつようです.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{JPN}{PLAYER}は チケットを\n"
	.string "{JPN}みせた.\p"
	.string "{JPN}かんぺき! じゅんびは\nばんたんです!\pどちらに いかれますか?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "{JPN}また こんどの きかいに\nごりよう ください!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "{JPN}ミナモシティ ですね!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "{JPN}バトルフロンティア ですね!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "{JPN}フェリーに のって\n"
	.string "{JPN}しゅっぱつまで おまちください.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "{JPN}では どちらに いかれますか?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "{JPN}うみのそこへのたび...\n"
	.string "{JPN}どんなかんじなんでしょう?\p"
	.string "{JPN}いつかふかいうみのそこに\n"
	.string "{JPN}いってみたいです.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "{JPN}ふねが あんぜんに こうかい\n"
	.string "{JPN}するには てんきが だいじだ!\p"
	.string "{JPN}そういえば きしょうけんきゅうじょの\n"
	.string "{JPN}ひとから きいたはなしが ある.\p"
	.string "{JPN}せかいじゅうで いじょうきしょうが\n"
	.string "{JPN}ほうこく されてるらしい!\p"
	.string "{JPN}きしょうけんきゅうじょに いって\n"
	.string "{JPN}はなしを きいてみるといい!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "{JPN}クスノキ せんちょう といっしょに\n"
	.string "{JPN}かいていたんさに いきたかったんだ.\p"
	.string "{JPN}でも せんすいかんが ちいさすぎて\n"
	.string "{JPN}ぼくには むりだよ.\p"
	.string "{JPN}もし ぼくが のりこんだら\nせんちょうの ばしょが なくなっちゃう...$"
SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "{JPN}クスノキせんちょう: あの あくとうども...\p"
	.string "{JPN}はくぶつかんで デボンのしなを\n"
	.string "{JPN}ぬすもうとした れんちゅうと おなじだ.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "{JPN}アクア: おや?\n"
	.string "{JPN}またおまえか...\p"
	.string "{JPN}ここまでおいかけてくるとは\n"
	.string "{JPN}しつこいやつだ.\p"
	.string "{JPN}だがいまでは...\n"
	.string "{JPN}だれにもとめられん! だれにも!\p"
	.string "{JPN}それともわれらがアジトの\n"
	.string "{JPN}ミナモシティまで\l"
	.string "{JPN}おいかけてくるか?\pふぁっはっはっは...$"
SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "{JPN}クスノキかんちょう: なぜ...\p"
	.string "{JPN}なぜアクアだんが ぼくの\n"
	.string "{JPN}せんすいかん エクスプローラー1を\l"
	.string "{JPN}ぬすんだんだ?\p"
	.string "{JPN}うみのそこでねむっている\n"
	.string "{JPN}ポケモンがめあてとは\l"
	.string "{JPN}おもえないが...\pぼくがおいかけても\nかれらにはかなわない...$"
SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "{JPN}クスノキかんちょう: おお \n"
	.string "{JPN}{PLAYER}くん...\p"
	.string "{JPN}そうか... アクアだんは\n"
	.string "{JPN}きみがとめるまえに\l"
	.string "{JPN}いってしまったのか...\p"
	.string "{JPN}いや じぶんをせめては\n"
	.string "{JPN}いけないよ.\p"
	.string "{JPN}きみのせいじゃない.\p"
	.string "{JPN}せんすいかんをつかまえるなんて\n"
	.string "{JPN}ふつうのひとには\l"
	.string "{JPN}むりなことだ.\p"
	.string "{JPN}ダイビングをおぼえた\n"
	.string "{JPN}ポケモンがひつようだ...\pミナモシティにいって\nみるといい...\pダイバーがおおくすんでいるから\nだれかがおしえてくれる\lかもしれない...$"
SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "{JPN}クスノキかんちょう: せんすいかんを\n"
	.string "{JPN}つかまえるなんて...\l"
	.string "{JPN}むりなことだ.\p"
	.string "{JPN}ダイビングをおぼえた\n"
	.string "{JPN}ポケモンがひつようだ...\p"
	.string "{JPN}ミナモシティにいって\n"
	.string "{JPN}みるといい...\p"
	.string "{JPN}ダイバーがおおくすんでいるから\nだれかがおしえてくれる\lかもしれない...$"
SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "{JPN}センチョウ:ああ そうそう.\n"
	.string "{JPN}ハギろうじんが ぞうせんじょに.\p"
	.string "{JPN}もうすぐ フェリーが\n"
	.string "{JPN}かんせいするよ!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "{JPN}センチョウ:{PLAYER}くん!\p"
	.string "{JPN}ついに フェリー\n"
	.string "{JPN}タイドリッパーごうが かんせいした!\p"
	.string "{JPN}ハギろうじんの おかげだよ.\p"
	.string "{JPN}ぜひ たんきかんこうに\n"
	.string "{JPN}でかけてくれ!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "{JPN}クスノキかんちょう: おや?\n"
	.string "{JPN}{PLAYER}くん そのアイテムは...\p"
	.string "{JPN}それはスキャナーだね!\n"
	.string "{JPN}ぼくらのたんさくにやくだつよ.\p"
	.string "{JPN}{PLAYER}くん そのスキャナーを\n"
	.string "{JPN}なにかとこうかんしてくれないか?\p"
	.string "{JPN}たとえば ぼくがもっている\n"
	.string "{JPN}しんかいのキバや\lしんかいのウロコと?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "{JPN}クスノキかんちょう: ほんとうに?\n"
	.string "{JPN}きみにはいらないものなのに\n"
	.string "{JPN}{PLAYER}くん...\p"
	.string "{JPN}まあ いいよ.スキャナーを\nこうかんしたくなったら\lこえをかけてくれ.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "{JPN}センチョウ:それと わたしの\n"
	.string "{JPN}しんかいのキバを こうかんかい?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "{JPN}センチョウ:それと わたしの\n"
	.string "{JPN}しんかいのウロコを こうかんかい?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "{JPN}センチョウ:どちらが ほしいかな?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{JPN}{PLAYER}は スキャナーを\n"
	.string "{JPN}センチョウに わたした.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "{JPN}センチョウ:ありがとう {PLAYER}くん!\n"
	.string "{JPN}これで けんきゅうが すすむよ!$"
