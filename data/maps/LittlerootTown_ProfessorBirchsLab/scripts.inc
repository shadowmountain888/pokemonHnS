.set LOCALID_AIDE, 1
.set LOCALID_BIRCH, 2
.set LOCALID_RIVAL, 3
.set LOCALID_BALL_CYNDAQUIL, 4
.set LOCALID_BALL_TOTODILE, 5
.set LOCALID_BALL_CHIKORITA, 6

LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
	@ 1: Beat Elite Four, Dex upgrade ready
	@ 2: Received National Dex
	@ 3: Left lab after receiving National Dex
	@ 4: Entered lab after catching all Hoenn mons
	@ 5: Birch told player to choose Johto starter
	@ 6: Chose Johto starter

	@ State descriptions for VAR_GARBAGEVAR
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition:
	callnative SetTimeBasedEncounters
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout

LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_OnWarp:
	map_script_2 VAR_GARBAGEVAR, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	addobject LOCALID_BIRCH
	addobject LOCALID_RIVAL
	turnobject LOCALID_RIVAL, DIR_NORTH
	setobjectxy LOCALID_RIVAL, 5, 5
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	turnobject LOCALID_AIDE, DIR_EAST
	setobjectxy LOCALID_AIDE, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
	addobject LOCALID_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
	addobject LOCALID_BALL_CYNDAQUIL
	addobject LOCALID_BALL_TOTODILE
	addobject LOCALID_BALL_CHIKORITA
	addobject LOCALID_RIVAL
	turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
	setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
	turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
	setobjectxy LOCALID_BALL_TOTODILE, 9, 4
	turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
	setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	turnobject LOCALID_RIVAL, DIR_EAST
	setobjectxy LOCALID_RIVAL, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_GARBAGEVAR, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
	.2byte 0

@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter_Nuzlocke
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter_Nuzlocke::
	message LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon_Nuzlocke
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
	lockall
	goto_if_ge VAR_TIME_BASED_ENCOUNTER, 3, LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNationalSkip
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
	waitmovement 0
	delay 20
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
	playse SE_PC_ON
	waitse
	delay 20
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNationalSkip::
	delay 30
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_GARBAGEVAR, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CYNDAQUIL
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CYNDAQUIL
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_TOTODILE
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_TOTODILE
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CHIKORITA
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CHIKORITA
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_unset FLAG_GARBAGEFLAG, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_GARBAGEVAR, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_GARBAGEVAR, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 4
	setvar VAR_GARBAGEVAR, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	goto_if_ge VAR_TIME_BASED_ENCOUNTER, 3, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedexAltered
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedexAltered::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS
	clearflag FLAG_GARBAGEFLAG
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Book::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
	.string "{JPN}あれ? オダマキはかせ?\p"
	.string "{JPN}はかせは フィールドワークで\n"
	.string "{JPN}でかけて おるのじゃ.\n"
	.string "{JPN}つまり るすなのじゃ.\p"
	.string "{JPN}あっ フィールドワークとは なにか\n"
	.string "{JPN}せつめいしよう.\p"
	.string "{JPN}けんきゅうしつではなく のはらや\n"
	.string "{JPN}やまなど しぜんの かんきょうで\l"
	.string "{JPN}ものごとを けんきゅうすることじゃ.\p"
	.string "{JPN}はかせは つくえでの しごとが\n"
	.string "{JPN}にがてでな.\lほんを よむより そとに でて\lじっさいに けいけんするほうが\lすきな ひとなのじゃ.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
	.string "{JPN}はかせは つくえでの しごとが\n"
	.string "{JPN}にがてでな.\l"
	.string "{JPN}ほんを よむより そとに でて\l"
	.string "{JPN}じっさいに けいけんするほうが\lすきな ひとなのじゃ.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
	.string "{JPN}オダマキはかせは ポケモンの\n"
	.string "{JPN}せいそくちや ぶんぷを けんきゅう\l"
	.string "{JPN}しておるのじゃ.\p"
	.string "{JPN}はかせは シルバーくんの てつだいを\nたのしんでおる.\nあいじょうが あふれておるのじゃ.$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
	.string "{JPN}オダマキはかせそうじゃ {PLAYER}{KUN}.\p"
	.string "{JPN}きみの おとうさんから きみの\n"
	.string "{JPN}はなしを たくさん きいておるよ.\p"
	.string "{JPN}まだ じぶんの ポケモンを\n"
	.string "{JPN}もっていないと きいたが.\p"
	.string "{JPN}でも さっきの たたかいぶりを\n"
	.string "{JPN}みると みごとじゃった!\p"
	.string "{JPN}やはり おとうさんの ちが\n"
	.string "{JPN}ながれておるのじゃな!\p"
	.string "{JPN}そうじゃ. わしを たすけてくれた\n"
	.string "{JPN}おれいに さっき つかった\l"
	.string "{JPN}ポケモンを きみに あげよう.\p"
	.string "{JPN}{PLAYER}は {STR_VAR_1}を てにいれた!$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
	.string "{JPN}オダマキはかせついでに その\n"
	.string "{JPN}{STR_VAR_1}に ニックネームを\lつけて あげたら どうじゃ?$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon_Nuzlocke:
	.string "{JPN}オダマキはかせついでに その\n"
	.string "{JPN}{STR_VAR_1}に ニックネームを\lつけて あげたら どうじゃ?\p$"
	
LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
	.string "{JPN}オダマキはかせポケモンと ともに\n"
	.string "{JPN}がんばって けいけんを つめば\l"
	.string "{JPN}とても よい トレーナーに なると\l"
	.string "{JPN}おもうぞ.\p"
	.string "{JPN}わしの むすこの シルバーも\n"
	.string "{JPN}わしの てつだいを しながら\l"
	.string "{JPN}ポケモンを けんきゅうしておる.\p{PLAYER}{KUN} シルバーに あいに\nいったら どうじゃろうか?$"

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
	.string "{JPN}オダマキはかせそれは よかった!\n"
	.string "{JPN}シルバーも よろこぶじゃろう.\p"
	.string "{JPN}シルバーに トレーナーとは なにかを\n"
	.string "{JPN}おしえて もらうのじゃ.$"

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
	.string "{JPN}オダマキはかせおお そんなこと\n"
	.string "{JPN}いわずに.\nわしの むすこに あってみなさい.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
	.string "{JPN}オダマキはかせ: シルバー?\n"
	.string "{JPN}うちに かえったと おもうよ.\p"
	.string "{JPN}それか またどこかの\n"
	.string "{JPN}くさむらを あるきまわって\l"
	.string "{JPN}いるのかもしれないな...\p"
	.string "{JPN}きみや きみの ポケモンが\nつかれたら うちで やすむんだ.$"

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
	.string "{JPN}オダマキはかせおお {PLAYER}{KUN}!\p"
	.string "{JPN}シルバーに はじめてで かったと\n"
	.string "{JPN}きいたぞ! すばらしいじゃないか!\p"
	.string "{JPN}シルバーは ながい あいだ\n"
	.string "{JPN}わしの けんきゅうを てつだって\l"
	.string "{JPN}くれておるのじゃ.\p"
	.string "{JPN}シルバーは トレーナーとしても\n"
	.string "{JPN}ふるい れきしが あるのじゃぞ.\p"
	.string "{JPN}さあ {PLAYER}{KUN} これは わしの\n"
	.string "{JPN}けんきゅうのために ちゅうもんしたが\lきみが もつべきじゃろう.\lこの ポケモンずかんを あげよう.$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
	.string "{JPN}{PLAYER}は ポケモンずかんを てにいれた!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
	.string "{JPN}オダマキはかせポケモンずかんは\n"
	.string "{JPN}であったり つかまえたりした\l"
	.string "{JPN}ポケモンの きろくを じどうてきに\l"
	.string "{JPN}つくる こうせいのうな どうぐじゃ.\p"
	.string "{JPN}わしの むすこ シルバーは\n"
	.string "{JPN}いつも これを もちあるいておる.\p"
	.string "{JPN}シルバーが めずらしい ポケモンを\n"
	.string "{JPN}つかまえて ポケモンずかんに\l"
	.string "{JPN}きろくすると フィールドワークちゅうの\lわしを さがしだして みせてくれるのじゃ.$"

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
	.string "{JPN}オダマキはかせかずしれない\n"
	.string "{JPN}ポケモンが きみを まっておる!\p"
	.string "{JPN}うーん また フィールドワークが\n"
	.string "{JPN}したくなって きたぞい!$"

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
	.string "{JPN}ハルカわあ {PLAYER}{KUN}!\n"
	.string "{JPN}きみも ポケモンずかんを もらったのね!\p"
	.string "{JPN}よかった! わたしと おなじね!\n"
	.string "{JPN}わたしからも なにか あげる!$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
	.string "{JPN}ハルカたくさん ポケモンが\n"
	.string "{JPN}いたら たのしいのよね!\p"
	.string "{JPN}ちがう ポケモンが ほしいから\n"
	.string "{JPN}いろんな ところを さがすのよ.\p"
	.string "{JPN}かわいい ポケモンを みつけたら\n"
	.string "{JPN}モンスターボールで つかまえるの!\p"
	.string "{JPN}あ それと バッグから ボールを\n"
	.string "{JPN}えらんで つかうと\p"
	.string "{JPN}ポケモンが つかう モンスターボールを\n"
	.string "{JPN}かえられるのよ しってた?\p"
	.string "{JPN}わたしの ポケモンを プレミアボールに\n"
	.string "{JPN}いれようかな. とっても すてきなの!$"

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
	.string "{JPN}あら? バッグが いっぱいね.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
	.string "{JPN}ハルカこんどは どこで ポケモンを\n"
	.string "{JPN}さがそうかしら?$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
	.string "{JPN}ユウキ: へえ...\n"
	.string "{JPN}きみも ポケモンずかんを\l"
	.string "{JPN}もらったのか.\p"
	.string "{JPN}じゃあ これを\nあげるよ.$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
	.string "{JPN}ユウキポケモンが たくさんいたほうが\n"
	.string "{JPN}ぜったい たのしいよな.\p"
	.string "{JPN}いろんな ポケモンを みつけるために\n"
	.string "{JPN}あちこち たんけんするんだ.\p"
	.string "{JPN}かっこいい ポケモンを みつけたら\n"
	.string "{JPN}モンスターボールで つかまえてやるぞ!$"

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
	.string "{JPN}おい バッグが いっぱいだぞ.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
	.string "{JPN}ユウキ: こんどは どこで\n"
	.string "{JPN}ポケモンを さがそうかな...$"
LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
	.string "{JPN}まじめそうな きかいだ.\n"
	.string "{JPN}はかせが けんきゅうに つかってるんだろう.$"

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
	.string "{JPN}けんきゅうよう パソコンだ.\n"
	.string "{JPN}いたずらしないほうが いいな.$"

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
	.string "{JPN}ポケモンの ほんが ぎっしり つまってる.$"

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
	.string "{JPN}むずかしすぎて よめない ほんだ.$"

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
	.string "{JPN}オダマキはかせ: さて...\p"
	.string "{JPN}{PLAYER}くんと シルバー \n"
	.string "{JPN}ふたりには ポケモンけんきゅうを\l"
	.string "{JPN}てつだってもらったね.\p"
	.string "{JPN}きみたちの おかげで\n"
	.string "{JPN}あたらしい はっけんが\l"
	.string "{JPN}つぎつぎと でてきたよ.\p"
	.string "{JPN}ホウエンちほうには ほかの\n"
	.string "{JPN}ちほうの ポケモンも いることが\l"
	.string "{JPN}わかったんだ.\p"
	.string "{JPN}ホウエンの しぜんかんきょうが\n"
	.string "{JPN}いかに ゆたかで たようかを\l"
	.string "{JPN}しめしているね.\p"
	.string "{JPN}そこで きみたちの ポケモンずかんを\n"
	.string "{JPN}ぜんこくばんに アップグレード\lすることにしたんだ.\pポケモンずかんを みせてくれ.$"

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
	.string "{JPN}ハルカえへへ!\p"
	.string "{JPN}わたしの ポケモンずかんまで\n"
	.string "{JPN}アップグレード されちゃった!\p"
	.string "{JPN}{PLAYER}{KUN}が たくさん ポケモンを\n"
	.string "{JPN}つかまえに いったからよ!$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
	.string "{JPN}ユウキおれが ホウエン ちほう\n"
	.string "{JPN}ぜんたいを まわって ポケモンを\l"
	.string "{JPN}しらべて きたんだ.\p"
	.string "{JPN}ぜんこくモード ポケモンずかんに\n"
	.string "{JPN}なったのは おれの おかげだな.\pそう {PLAYER} きみは うんが いいぞ!$"

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
	.string "{JPN}オダマキはかせ: よし \nできあがりじゃ!$"

LittlerootTown_ProfessorBirchsLab_Text_IHadDoneThat:
	.string "{JPN}オダマキはかせ: まって \n"
	.string "{JPN}ぜんこくずかんって?\p"
	.string "{JPN}もう アップグレード\n"
	.string "{JPN}してたのかな?\nまあ いいか...$"
LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
	.string "{JPN}{PLAYER}の ポケモンずかんは\n"
	.string "{JPN}ぜんこくばんに バージョンアップした!$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
	.string "{JPN}オダマキはかせ: でも きいてくれい.\n"
	.string "{JPN}きみは チャンピオンに なったが \l"
	.string "{JPN}ポケモンの たびは おわってない.\p"
	.string "{JPN}ポケモンという みちに\n"
	.string "{JPN}おわりは ないのじゃ.\p"
	.string "{JPN}どこかに きみを まっている\n"
	.string "{JPN}くさむらが あるのじゃ!$"

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
	.string "{JPN}ハルカ: わたし しばらく\n"
	.string "{JPN}フィールドワークを\l"
	.string "{JPN}やすもうと おもうの.\p"
	.string "{JPN}しばらく はかせの\nおてつだいを しようかな.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
	.string "{JPN}ユウキ: しばらく フィールドワークは\n"
	.string "{JPN}おやすみに するよ.\p"
	.string "{JPN}はかせの おてつだいを\n"
	.string "{JPN}しようと おもうんだ.$"

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
	.string "{JPN}オダマキはかせ: おお {PLAYER}くん!\n"
	.string "{JPN}ポケモンずかんを みせてくれ.\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}うん まちがいない.\p"
	.string "{JPN}きみは ホウエンちほうの\n"
	.string "{JPN}ポケモンずかんを かんせい\l"
	.string "{JPN}させたんだね.\p"
	.string "{JPN}すばらしい いじょうだよ.\p"
	.string "{JPN}きみへの おくりものが あるんだ.\p"
	.string "{JPN}きみの すばらしい けんきゅうに\n"
	.string "{JPN}たいする かんしゃの きもちだよ.\p"
	.string "{JPN}べつの ちほうでしか みつからない\n"
	.string "{JPN}めずらしい ポケモンだ!\p"
	.string "{JPN}この みっぴきの うちから\nすきな いっぴきを\lえらんでくれ!$"

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
	.string "{JPN}オダマキはかせ: これらは べつの\n"
	.string "{JPN}ちほうでしか みつからない\l"
	.string "{JPN}めずらしい ポケモンじゃ!\p"
	.string "{JPN}この 3ひきの うち\nどれでも すきなのを\lえらんで よいぞ!$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
	.string "{JPN}オダマキはかせ: ほのおポケモンの\n"
	.string "{JPN}ヒノアラシに きょうみを\l"
	.string "{JPN}もったようじゃな!\p"
	.string "{JPN}あいかわらず めが たかい!\pヒノアラシに きめるかい?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
	.string "{JPN}オダマキはかせ: みずポケモンの\n"
	.string "{JPN}ワニノコを えらぶのか!\n"
	.string "{JPN}めがね たかいのう.\p"
	.string "{JPN}ワニノコに きめるかい?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
	.string "{JPN}オダマキはかせ: くさポケモンの\n"
	.string "{JPN}チコリータを えらぶのか!\n"
	.string "{JPN}なかなか よいせんじゃ.\p"
	.string "{JPN}チコリータに きめるかい?$"

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
	.string "{JPN}オダマキはかせ: きめるまえに\n"
	.string "{JPN}ゆっくり かんがえるとよい.\p"
	.string "{JPN}どの ポケモンも\nたいせつな そんざいじゃ.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
	.string "{JPN}オダマキはかせ: そうか!\n"
	.string "{JPN}よい ポケモンを えらんだのう!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
	.string "{JPN}{PLAYER}は オダマキはかせから\n"
	.string "{JPN}{STR_VAR_1}を もらった!$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
	.string "{JPN}もらった {STR_VAR_1}に\n"
	.string "{JPN}ニックネームを つけますか?$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
	.string "{JPN}オダマキはかせ: きいてくれい \n"
	.string "{JPN}{PLAYER}くん.\l"
	.string "{JPN}ホウエンの ポケモンずかんを\p"
	.string "{JPN}かんせい させたが \n"
	.string "{JPN}ポケモンの たびは\l"
	.string "{JPN}おわってない.\p"
	.string "{JPN}ポケモンという みちに\nおわりは ないのじゃ.\pどこかに きみを まっている\nくさむらが あるのじゃ!$"

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
	.string "{JPN}やくそくの ポケモンを もらった.\n"
	.string "{JPN}ほかの ポケモンには\lさわらない ほうが よいだろう.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
	.string "{JPN}おや ポケモンを もつ\n"
	.string "{JPN}ばしょが ないようじゃ.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
	.string "{JPN}ハルカ: {PLAYER}くん これから\n"
	.string "{JPN}どうするの?\p"
	.string "{JPN}バトルを つづけて\n"
	.string "{JPN}うでを みがくの?\p"
	.string "{JPN}それとも ぜんこくずかんを\n"
	.string "{JPN}かんせいさせるの?\p"
	.string "{JPN}わたしは ここで はかせの\nおてつだいを するつもりよ.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
	.string "{JPN}ユウキ: ぼくは ポケモンを\n"
	.string "{JPN}あつめるより えらんだ\l"
	.string "{JPN}1ぴきを ゆっくり じっくり\pそだてる ほうが すきなんだ.$"

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
	.string "{JPN}ハルカ: あ {PLAYER}くん!\n"
	.string "{JPN}バトルフロンティアって\l"
	.string "{JPN}ところに いったことある?$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
	.string "{JPN}ユウキ: やあ {PLAYER}!\n"
	.string "{JPN}バトルフロンティアって\l"
	.string "{JPN}ところに いったことある?$"

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ピッ!\p"
	.string "{JPN}ダイゴ: やあやあ {PLAYER}!\n"
	.string "{JPN}わたしだ ダイゴ.\p"
	.string "{JPN}いま だいちょうの うえにいる.\n"
	.string "{JPN}うみの うえは さいこうだね!\p"
	.string "{JPN}ところで...\p"
	.string "{JPN}きみを しょうたい したい\n"
	.string "{JPN}ばしょが あるんだ.\p"
	.string "{JPN}きょうみが あるなら カイナか\n"
	.string "{JPN}ミナモで ふねに のってくれ.\p"
	.string "{JPN}あったときに くわしく はなそう.\n"
	.string "{JPN}まってるからね!\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ガチャ!$"
