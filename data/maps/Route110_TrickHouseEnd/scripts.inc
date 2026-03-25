.set LOCALID_TRICK_MASTER, 1

Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "{JPN}うわあ!\n"
	.string "{JPN}わたしまで たどりついただと?\l"
	.string "{JPN}うーむ... おまえ するどいな!$"
Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "{JPN}あの きを ぜんぶ うえるのに\n"
	.string "{JPN}ひとばん かかったのだ...\p"
	.string "{JPN}おまえは わたしの いだいさに\n"
	.string "{JPN}たったの 1,2,3,4,5,6ばんだけ\lおよばないぐらいだ!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "{JPN}あの めいろを つくるのに\n"
	.string "{JPN}ひとばん かかったのだ...\p"
	.string "{JPN}おまえは わたしの いだいさに\nたったの 1,2,3,4,5ばんだけ\lおよばないぐらいだ!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "{JPN}あの かべの パネルを じゅんびするのに\n"
	.string "{JPN}ひとばん かかったのだ...\p"
	.string "{JPN}おまえは わたしの いだいさに\n"
	.string "{JPN}たったの 1,2,3,4ばんだけ\lおよばないぐらいだ!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "{JPN}あの いわを おしこむのに\n"
	.string "{JPN}ひとばん かかったのだ...\p"
	.string "{JPN}おまえは わたしの いだいさに\n"
	.string "{JPN}たったの 1,2,3ばんだけ\lおよばないぐらいだ!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "{JPN}メカにんぎょうを つくるのに ひとばん\n"
	.string "{JPN}クイズを かんがえるのに さらに\l"
	.string "{JPN}ひとばん かかったのだ...\p"
	.string "{JPN}おまえは わたしの いだいさに\nたったの 1,2ばんだけ\lおよばないぐらいだ!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "{JPN}あの ドアを せっちするのに\n"
	.string "{JPN}ひとばん かかったのだ...\p"
	.string "{JPN}おまえは わたしの いだいさに\nほぼ ひってきするぐらいだ!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "{JPN}あの やじるしを せっちするのに\n"
	.string "{JPN}ひとばん かかったのだ...\pおまえは わたしと おなじぐらい\nいだいだ!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "{JPN}あの ゆかを みがくのに\n"
	.string "{JPN}ひとばん かかったのだ...\p"
	.string "{JPN}おまえは わたしより いだいだ!\nたぶん...だが$"
Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "{JPN}ど どうすれば いいのだ?\n"
	.string "{JPN}しかけの アイデアが\l"
	.string "{JPN}つきてしまった...\p"
	.string "{JPN}あたらしい しかけを かんがえるため\n"
	.string "{JPN}ぜんこく りょこうでも する\lときが きたのかもしれん...$"
Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "{JPN}まけを みとめたくないが\n"
	.string "{JPN}きみに やられてしまった!\p"
	.string "{JPN}それでも きみは わたしの\n"
	.string "{JPN}みりょくに ひかれて なんども\l"
	.string "{JPN}ここに きているのだろう!\p"
	.string "{JPN}そうに ちがいない!\p"
	.string "{JPN}しかし それと わたしが まけた\n"
	.string "{JPN}ことは かんけいないぞ!\p"
	.string "{JPN}やるきに みちた きみと\n"
	.string "{JPN}てんさいである わたしとの\l"
	.string "{JPN}ゆうじょうの あかしとして\l"
	.string "{JPN}この きねんひんを もらって\l"
	.string "{JPN}もらおう!\p"
	.string "{JPN}じつは ふたつ あるのだ--\nあかい テントと あおい テントが\lどちらが このみかね?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "{JPN}なんと? パソコンに スペースが\n"
	.string "{JPN}ないだと? どういうことだ?\p"
	.string "{JPN}そんなことを いいたいのだが\n"
	.string "{JPN}わたしは とても やさしくて\lしんせつなので あとで きたまえ!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}わたしは はっけんの たびに でる.\n"
	.string "{JPN}あたらしい しかけを もとめる たびに.\p"
	.string "{JPN}いつか また きて わたしを\n"
	.string "{JPN}たのしませてくれることを のぞんでいる.\p"
	.string "{JPN}それでは さらばだ!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "{JPN}よろしい!\n"
	.string "{JPN}きみは この ほうしゅうを\nかくとくしたのだ!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "{JPN}なんと? これを もつ スペースが\n"
	.string "{JPN}ないのか? いったい なにを\l"
	.string "{JPN}もっているのだ?\p"
	.string "{JPN}だが まあいい きみが ここまで\nきたのだから ほうしゅうは\lあとまで わたしが もっていよう$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "{JPN}その にやけづらを ひっこめろ!\n"
	.string "{JPN}かったと おもうのは まだ はやい!\p"
	.string "{JPN}きみを こまらせる あたらしい\n"
	.string "{JPN}トリックを つくってやる\p"
	.string "{JPN}つぎの わくわくする ぼうけんに\n"
	.string "{JPN}もどって きたまえ!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "{JPN}おいおい! いま わたしを\n"
	.string "{JPN}むししているのか?\nそれは かなしすぎるぞ!$"

