.set LOCALID_OLIVINEPORT_SAILOR, 1
.set LOCALID_OLIVINEPORT_BOAT, 6
.set LOCALID_OLIVINEPORT_OAK, 7

OlivineCity_PortInside_MapScripts::
	.byte 0


OlivineCity_PortInside_EventScript_Oak::
	lock
	playbgm MUS_HG_OAK, TRUE
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_OLIVINEPORT_OAK, DIR_NORTH
	msgbox OlivineCity_PortInside_Text_Nationaldex1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakFixDex
	waitmovement 0
	delay 30
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_ITEM
	message OlivineCity_PortInside_Text_Nationaldex2
	waitfanfare
	delay 50
	msgbox OlivineCity_PortInside_Text_Nationaldex3, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 60
	msgbox OlivineCity_PortInside_Text_Nationaldex4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OlivineCity_PortInside_Movement_PlayerMoveOver
	waitmovement 0
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakLeave
	waitmovement 0
	setflag FLAG_HIDE_OLIVINE_PORT_OAK
	playse SE_EXIT
	removeobject LOCALID_OLIVINEPORT_OAK
	fadedefaultbgm
	waitse
	release
	end

OlivineCity_PortInside_Movement_OakFixDex:
	walk_in_place_up
	walk_in_place_up
	step_end

OlivineCity_PortInside_Movement_PlayerMoveOver:
	walk_up
	walk_left
	face_right
	step_end

OlivineCity_PortInside_Movement_OakLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_PortInside_Text_Nationaldex1:
	.string "{JPN}オーキドはかせやあ！\nきみも チャンピオンらしく\lなってきたね {PLAYER}くん！\pポケモンずかんも\nレベルアップの じきだな\pちょっと ポケモンずかんを\nみせて もらえるかな\pぜんこくバージョンに\nバージョンアップしてあげよう$"
OlivineCity_PortInside_Text_Nationaldex2:
	.string "{JPN}{PLAYER}の ポケモンずかんが\nぜんこくバージョンに なった！$"
OlivineCity_PortInside_Text_Nationaldex3:
	.string "{JPN}オーキドはかせぜんこく\nポケモンずかんの かんせいは\pなかなか たいへんだと おもうが\nがんばって ちょうせんしてくれ！$"
OlivineCity_PortInside_Text_Nationaldex4:
	.string "{JPN}おっと じかんが ない！\pコガネの ラジオとうで\nばんぐみの しゅうろくがあるんだ\pきみは カントーに いくんだね\pマサラタウンに きたときは\nけんきゅうじょに よってくれよ！$"
OlivinePort_EventScript_CooltrainerF::
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher1::
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher2::
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
	end

OlivinePort_EventScript_Youngster::
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
	end

OlivinePort_EventScript_Sailor::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivinePort_EventScript_Sailor_AfterKanto
	msgbox OlivinePort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivinePort_EventScript_Sailor_MaidenVoyage
	msgbox OlivinePort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_AfterKanto::
	message OlivinePort_Text_WhereSail
	multichoice 20, 0, MULTI_OLIVINE_HARBOR, FALSE
	switch VAR_RESULT
	case 0, OlivinePort_EventScript_ChoseVermilion
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
	case 2, OlivinePort_EventScript_ChoseBirthIsland
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
	case 4, OlivinePort_EventScript_ChoseBattleFrontier
	case 5, OlivinePort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
	release
	end

OlivinePort_EventScript_ChoseVermilion::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
	release
	end

OlivinePort_EventScript_ChoseSouthernIsland::
	closemessage
	delay 20
	checkitem ITEM_EON_TICKET
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	release
	end

OlivinePort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR, 13, 23
	release
	end

OlivinePort_EventScript_ChoseFarawayIsland::
	closemessage
	delay 20
	checkitem ITEM_OLD_SEA_MAP
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	release
	end	

OlivinePort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 20, 67
	release
	end	

OlivinePort_EventScript_Sailor_MaidenVoyage::
	msgbox OlivinePort_Text_FlashTicket, MSGBOX_DEFAULT
	call OlivinePort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	clearflag FLAG_HIDE_SSAQUA_SAILOR
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	warpsilent MAP_SSAQUA_1F, 29, 3
	release
	end

OlivinePort_EventScript_EnterShip::
	msgbox OlivinePort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, OlivinePort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_BoatLeave
	applymovement LOCALID_OLIVINEPORT_BOAT, OlivinePort_Movement_BoatLeave
	waitmovement LOCALID_OLIVINEPORT_BOAT
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	return

OlivinePort_EventScript_Sailor_Refused::
	msgbox OlivinePort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_NoCredentials::
	msgbox OlivinePort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

OlivinePort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

OlivinePort_Movement_BoatLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OlivinePort_Text_NoPass:
	.string "{JPN}{PLAYER}は\n{STR_VAR_1}を みせようとした.\p.でも {STR_VAR_1}が ない！\pすみません！\n{STR_VAR_1}が ないと\lのせられません$"
OlivinePort_Text_SailorGetOnBoard:
	.string "{JPN}もうすぐ しゅっぱつです\nのって ください$"
OlivinePort_Text_CantBoard:
	.string "{JPN}すみません いまは のれません$"
OlivinePort_Text_WhereSail:
	.string "{JPN}どちらまで いかれますか？$"
OlivinePort_Text_AskBoard:
	.string "{JPN}こうそくせんアクアごうへ\nようこそ！\pきょうはおのりになりますか？$"
OlivinePort_Text_AskTicket:
	.string "{JPN}ふねのチケットを\nおもちでしょうか？$"
OlivinePort_Text_ComeAgain:
	.string "{JPN}またのごりようを\nおまちしております！$"
OlivinePort_Text_FlashTicket:
	.string "{JPN}{PLAYER}は\nふねのチケットをみせた！\pはい！かくにんできました！$"
OlivinePort_Text_NoTicket:
	.string "{JPN}{PLAYER}は\nふねのチケットをみせようとした.\p.しかしチケットがない！\pもうしわけありません！\nふねのチケットをおもちの\lかたのみごりようできます！$"
OlivinePort_Text_FishingGuru1:
	.string "{JPN}ここではシェルダーが\nよくつれるんだ\pほかのばしょではめずらしいぞ$"
OlivinePort_Text_FishingGuru2:
	.string "{JPN}つりざおをなんぼんもってるかね？\pつりざおがちがうと\nつれるポケモンもちがうぞ$"
OlivinePort_Text_Youngster:
	.string "{JPN}アクアごうはジェットで\nなみのうえをすべるんだ！$"
OlivinePort_Text_CooltrainerF:
	.string "{JPN}カントーにはたくさんの\nポケモンがいるのよ\pわたしもいってみたいなあ.$"
OlivinePort_Text_SailorBeforeHOF:
	.string "{JPN}うみにおちるとあぶないので\nかんけいしゃいがいははいれません$"