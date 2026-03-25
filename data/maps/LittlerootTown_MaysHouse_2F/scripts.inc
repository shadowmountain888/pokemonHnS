.set LOCALID_RIVAL, 1

LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
	call_if_lt VAR_GARBAGEVAR, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
	call_if_ge VAR_GARBAGEVAR, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
	call_if_eq VAR_GARBAGEVAR, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto_if_ge VAR_GARBAGEVAR, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos

LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_RIVAL, 8, 2
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return

LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	return

LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
	setvar VAR_GARBAGEVAR, 2
	return

LittlerootTown_MaysHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_GARBAGEVAR, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
	delay 10
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
	setvar VAR_GARBAGEVAR, 3
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setvar VAR_GARBAGEVAR, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_Movement_MayEnters:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
	walk_up
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RivalsHouse_2F_EventScript_Rival::
	lockall
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_Brendan
	end

RivalsHouse_2F_EventScript_May::
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_Brendan::
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_RivalPostLilycove::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_MayPostLilycove
	call_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_BrendanPostLilycove
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	releaseall
	end

RivalsHouse_2F_EventScript_MayPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_MaysHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

RivalsHouse_2F_Text_MayWhoAreYou:
	.string "{JPN}え?\n"
	.string "{JPN}だれ... だれなの?\p"
	.string "{JPN}... ... ... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ... ... ...\p"
	.string "{JPN}あ {PLAYER}くんなのね.\n"
	.string "{JPN}きょう おひっこしだったのね.\p"
	.string "{JPN}えっと... わたし マユミ.\n"
	.string "{JPN}よろしくね!\p"
	.string "{JPN}わたし...\n"
	.string "{JPN}せかいじゅうの ポケモンと\l"
	.string "{JPN}ともだちに なりたいの.\p"
	.string "{JPN}わたし... {PLAYER}くんのこと\n"
	.string "{JPN}パパの オダマキはかせから きいてたの.\p"
	.string "{JPN}{PLAYER}くんが やさしいひとで\n"
	.string "{JPN}ともだちに なってくれたら いいなって.\p"
	.string "{JPN}あ これって おかしいよね?\n"
	.string "{JPN}わたし... {PLAYER}くんと あったばかりなのに.\p"
	.string "{JPN}えへへ...\p"
	.string "{JPN}あ そうだ! わすれてた!\p"
	.string "{JPN}パパの てつだいで やせいの\n"
	.string "{JPN}ポケモンを つかまえに いくんだった!\p"
	.string "{JPN}{PLAYER}くん また あとでね!$"

RivalsHouse_2F_Text_MayGettingReady:
	.string "{JPN}ポケモンの たいりょくも かいふく!\n"
	.string "{JPN}どうぐも ばっちりで...$"
RivalsHouse_2F_Text_BrendanWhoAreYou:
	.string "{JPN}おい!\n"
	.string "{JPN}きみは...\p"
	.string "{JPN}だれだ?\p"
	.string "{JPN}あ {PLAYER}だろ?\n"
	.string "{JPN}となりに ひっこしてきたんだよな?\p"
	.string "{JPN}おんなのこだとは しらなかった.\n"
	.string "{JPN}とうちゃんの オダマキはかせが\l"
	.string "{JPN}あたらしい となりのひとは ジムリーダーの\l"
	.string "{JPN}こどもだって いってたから おとこのこだと おもってた.\p"
	.string "{JPN}おれの なまえは ユウキ.\n"
	.string "{JPN}よろしく となりさん!\p"
	.string "{JPN}ん? おい {PLAYER} ポケモン\n"
	.string "{JPN}もってないのか?\n"
	.string "{JPN}つかまえてきて やろうか?\p"
	.string "{JPN}あー しまった わすれてた...\p"
	.string "{JPN}とうちゃんの てつだいで やせいの\n"
	.string "{JPN}ポケモンを つかまえに いくんだった.\n"
	.string "{JPN}また こんどにしよう.$"

RivalsHouse_2F_Text_BrendanGettingReady:
	.string "{JPN}ポケモンの たいりょくも かいふく...\n"
	.string "{JPN}どうぐも ぜんぶ つめこんで...$"
RivalsHouse_2F_Text_ItsRivalsPokeBall:
	.string "{JPN}シルバーの モンスターボール!\p"
	.string "{JPN}そのままに しておこう.$"

RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
	.string "{JPN}ハルカ: {PLAYER}{KUN}!\p"
	.string "{JPN}ポケモンずかんを チェック\n"
	.string "{JPN}してたの.\p"
	.string "{JPN}みたことは あるけど\n"
	.string "{JPN}つかまえてない ポケモンが\l"
	.string "{JPN}まだ いっぱい いるの.\p"
	.string "{JPN}それに しんかしそうな\n"
	.string "{JPN}ポケモンも たくさん いるし.\nつぎは どこで ポケモンを\nつかまえようかな?$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext:
	.string "{JPN}ハルカ: つぎは どこで ポケモンを\n"
	.string "{JPN}つかまえようかな?\p"
	.string "{JPN}{PLAYER}{KUN}と ばったり\n"
	.string "{JPN}あったりしたら おもしろいね!$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
	.string "{JPN}ユウキ: よう {PLAYER}.\p"
	.string "{JPN}ポケモンずかんを みてたんだ.\p"
	.string "{JPN}まだ つかまえなきゃいけない\n"
	.string "{JPN}ポケモンは たくさん いるけど \l"
	.string "{JPN}なかなか いいかんじだよ.\p"
	.string "{JPN}ポケモンずかんを みてると\n"
	.string "{JPN}また たびに でたくなるな.$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
	.string "{JPN}ユウキ: つぎは どこで ポケモンを\n"
	.string "{JPN}つかまえるか まよってるんだ.\p"
	.string "{JPN}おい {PLAYER} おれが ポケモンを\n"
	.string "{JPN}つかまえてるとき きみに あったら\l"
	.string "{JPN}バトルでも どうだい?$"
