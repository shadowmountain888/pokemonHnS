.set LOCALID_SAFARIZONEGATE_BAOBA, 1

SafariZoneGate_SafariZoneEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZoneGate_SafariZoneEntrance_OnFrame
	.byte 0

SafariZoneGate_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 3, SafariZoneGate_SafariZoneEntrance_MeetBaoba
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	warp MAP_SAFARI_ZONE_ENTERANCE, 0
	delay 120
	end

SafariZoneGate_SafariZoneEntrance_MeetBaoba::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEGATE_BAOBA
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome, MSGBOX_DEFAULT
	closemessage
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_SAFARI_ZONE_GATE_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Baoba::
	lock
	faceplayer
	goto_if_eq VAR_BAOBA_QUEST_STATE, 1, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach
	goto_if_eq VAR_BAOBA_QUEST_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush
	goto_if_eq VAR_BAOBA_QUEST_STATE, 3, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain
	goto_if_eq VAR_BAOBA_QUEST_STATE, 4, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave
	goto_if_ge VAR_BAOBA_QUEST_STATE, 5, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Baoba, MSGBOX_DEFAULT 
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 1
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 200000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 2
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 2
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 300000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 3
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 3
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 4
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 20
	playse SE_SHOP
	updatemoneybox
	delay 20
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 5
	release
	end

SafarioneEntrance_EventScript_BaobaWrong::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined:
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDone, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Test::
	givemon SPECIES_BELDUM, 5
	givemon SPECIES_CASTFORM, 5
	givemon SPECIES_MEDICHAM, 5
	givemon SPECIES_BAGON, 5
	end

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone:
	.string "{JPN}ありがとう {PLAYER}!\n"
	.string "{JPN}ここで このおかねをとって\l"
	.string "{JPN}サファリレベルをアップして\l"
	.string "{JPN}つぎはブラシエリアの\l"
	.string "{JPN}めずらしいポケモンをみせて\lくれ!$"
	
SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone:
	.string "{JPN}ありがとう {PLAYER}!\n"
	.string "{JPN}ここで このおかねをとって\l"
	.string "{JPN}サファリレベルをアップして\l"
	.string "{JPN}つぎはマウンテンエリアの\l"
	.string "{JPN}めずらしいポケモンをみせて\lくれ!$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone:
	.string "{JPN}ありがとう {PLAYER}!\n"
	.string "{JPN}ここで このおかねをとって\l"
	.string "{JPN}サファリレベルをアップして\l"
	.string "{JPN}つぎはケイブエリアの\l"
	.string "{JPN}めずらしいポケモンをみせて\lくれ!$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone:
	.string "{JPN}ありがとう {PLAYER}!\n"
	.string "{JPN}もうじゅうぶんだ.\p"
	.string "{JPN}デボンがなにをしているか\n"
	.string "{JPN}わかったので わたしの\l"
	.string "{JPN}サファリゾーンも\l"
	.string "{JPN}まけずにできそうだ.\lこれはめいわくをかけた\lおれいだ.$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong:
	.string "{JPN}それはちがうな!$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach:
	.string "{JPN}おお {PLAYER}!\p"
	.string "{JPN}フスベサファリゾーンの\n"
	.string "{JPN}ビーチエリアの\l"
	.string "{JPN}めずらしいポケモンを\lもってきてくれたかね?$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush:
	.string "{JPN}おお {PLAYER}!\p"
	.string "{JPN}フスベサファリゾーンの\n"
	.string "{JPN}ブラシエリアの\l"
	.string "{JPN}めずらしいポケモンを\lもってきてくれたかね?$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain:
	.string "{JPN}おお {PLAYER}!\p"
	.string "{JPN}フスベサファリゾーンの\n"
	.string "{JPN}マウンテンエリアの\l"
	.string "{JPN}めずらしいポケモンを\lもってきてくれたかね?$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaCave:
	.string "{JPN}おお {PLAYER}!\p"
	.string "{JPN}フスベサファリゾーンの\n"
	.string "{JPN}ケイブエリアの\l"
	.string "{JPN}めずらしいポケモンを\lもってきてくれたかね?$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined:
	.string "{JPN}どうしたらいいんだ?\n"
	.string "{JPN}デボンにはとてもかなわん!$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaLastMon:
	.string "{JPN}きみのさいごのポケモンは\nもらえないよ!$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaDone:
	.string "{JPN}おお {PLAYER}!\p"
	.string "{JPN}きみのおかげで\n"
	.string "{JPN}サファリゾーンは\l"
	.string "{JPN}はんじょうしている!\p"
	.string "{JPN}きみをサファリゾーンの\n"
	.string "{JPN}オーナーにしようかな...\p"
	.string "{JPN}いや そんなばかな.\nあはははは.$"

SafariZoneGate_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase
	call SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneGate_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_ENTERANCE, 0
	waitstate
	end

SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome:
	.string "{JPN}やあ{PLAYER}!\n"
	.string "{JPN}きみをまっていたよ.\n"
	.string "{JPN}どうかね?\p"
	.string "{JPN}これはまったくあたらしい\n"
	.string "{JPN}サファリゾーンなんだが...\p"
	.string "{JPN}そしてまだかくちょう\n"
	.string "{JPN}ちゅうなんだ!\p"
	.string "{JPN}いまのところ2つのゾーン\n"
	.string "{JPN}がひらいていて あと4つ\l"
	.string "{JPN}がじゅんびなかだ!\p"
	.string "{JPN}サファリゾーンを\nたのしんでくれ!ほかの\lゾーンができたられんらく\lするよ!$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks:
	.string "{JPN}おお!わすれるところだった.\p"
	.string "{JPN}ポケブロックは\n"
	.string "{JPN}わたしのサファリゾーンの\l"
	.string "{JPN}じゅうような きのうなので \lこれをもっていたほうが\lいいぞ!$"

SafariZoneGate_SafariZoneEntrance_Text_Baoba:
	.string "{JPN}やあ{PLAYER}!\p"
	.string "{JPN}サファリゾーンは\n"
	.string "{JPN}たのしんでいるかね?$"

SafariZoneGate_SafariZoneEntrance_Text_Boy:
	.string "{JPN}いま つくっている\n"
	.string "{JPN}あたらしいゾーンには\lドラゴンがいるって\lきいたよ!$"

SafariZoneGate_SafariZoneEntrance_Text_Engineer:
	.string "{JPN}すまないトレーナー \n"
	.string "{JPN}このエリアは\l"
	.string "{JPN}まだこうじなかだ.\lあとでもどってきてくれ!$"
