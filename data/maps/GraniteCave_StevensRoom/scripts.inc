.set LOCALID_STEVEN, 1

GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "{JPN}わたしの なまえは ダイゴ.\p"
	.string "{JPN}めずらしい いしに きょうみが\n"
	.string "{JPN}あるので あちこち たびを\n"
	.string "{JPN}しているんだ.\p"
	.string "{JPN}お?\nわたしに てがみ?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "{JPN}ダイゴ: そうか ありがとう.\p"
	.string "{JPN}きみは わざわざ これを\n"
	.string "{JPN}とどけに きてくれたんだね.\l"
	.string "{JPN}おれいを しなければ.\p"
	.string "{JPN}そうだな...\n"
	.string "{JPN}この わざマシンを きみに\l"
	.string "{JPN}あげよう.\pおれの だいすきな わざ\nはがねのつばさが はいってるよ.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "{JPN}ダイゴ: きみの ポケモンは\n"
	.string "{JPN}なかなか つよそうだね.\p"
	.string "{JPN}もっと しゅぎょうを つめば\n"
	.string "{JPN}いつか ポケモンリーグの\l"
	.string "{JPN}チャンピオンにも なれそうだ.\l"
	.string "{JPN}そう おもうよ.\p"
	.string "{JPN}せっかく しりあいに なったし\n"
	.string "{JPN}おたがいの ポケナビに\l"
	.string "{JPN}とうろく しあわないか.\p... ... ... ... ... ...$"
GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "{JPN}ダイゴを ポケナビに\n"
	.string "{JPN}とうろく しました.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "{JPN}それじゃあ いそがなくちゃ.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "{JPN}あれ バッグが いっぱいだね...\n"
	.string "{JPN}それは ざんねんだ.$"

