.set LOCALID_ELM, 2
.set LOCALID_AIDE1, 1
.set LOCALID_AIDE2, 3
.set LOCALID_COP, 7
.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{JPN}{PLAYER}くん！\pここでなにをしてるんだい？\pきみをキキョウシティで\nじょしゅがまってるよ！$"
NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 60
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	givemon PLAYER_STARTER_SPECIES, 5
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_EXP_SHARE
	removeitem ITEM_MYSTERY_EGG
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 60
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	specialvar VAR_RESULT, CheckTogepi
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "{JPN}さわらないほうがよさそうだ$"
NewBarkTown_Lab_Text_ElmIntro:
	.string "{JPN}ウツギ{PLAYER}くん！きてくれたね！\pおねがいがあるんだ\pいまあたらしいポケモンの\nけんきゅうをしているんだが\lてつだってもらえないかな\l{PLAYER}くん\pじつは..\pがっかいではっぴょうする\nろんぶんをかいているんだ\pでもまだよくわからない\nことがあるんだよ\pそこで！\nさいきんつかまえたポケモンを\nそだててもらいたいんだ$"
NewBarkTown_Lab_Text_ElmAccepted:
	.string "{JPN}ありがとう{PLAYER}くん！\nたすかるよ！$"
NewBarkTown_Lab_Text_ElmRefused:
	.string "{JPN}でも..おねがいだ\nてつだってくれ！$"
NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "{JPN}けんきゅうけっかをはっぴょうすれば\nポケモンのなぞがもっと\pふかくかいめいされるはずだ\pきたいしていてくれ！$"
NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "{JPN}おっ！メールがきてる！\p...\nふむ..なるほど..\pそうか..$"
NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "{JPN}きいてくれ\pポケモンじいさんという\nちじんがいるんだ\pいつもへんなものをみつけては\nだいはっけんだといってくる\pさっきメールがきて\nこんどはほんもので\lまちがいないというんだが..\pきょうみはあるが\nポケモンけんきゅうがいそがしくて\pそうだ！\nいいことをおもいついた！\p{PLAYER}くん\nかわりにいってもらえるかい？$"
NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "{JPN}このボールにはいっている\nポケモンをそだててほしい\p{PLAYER}くんが\nはじめてのパートナーになるんだ！\pさあ！えらんでごらん！$"
NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "{JPN}{STR_VAR_2}！どこいくの？$"
NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "{JPN}ウツギ{STR_VAR_1}\n{STR_VAR_2}ポケモンをえらぶんだね？$"
NewBarkTown_Lab_Text_ChooseTotodile:
	.string "{JPN}ウツギ{STR_VAR_1}\n{STR_VAR_2}ポケモンがほしいのかい？$"
NewBarkTown_Lab_Text_ChooseChikorita:
	.string "{JPN}ウツギそうか {STR_VAR_1}\n{STR_VAR_2}ポケモンがすきなんだね？$"
NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "{JPN}ウツギよくかんがえてみて\pパートナーはたいせつだからね$"
NewBarkTown_Lab_Text_ChoseStarter:
	.string "{JPN}ウツギそれもすばらしい\nポケモンだよ！$"
NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{JPN}{PLAYER}は{STR_VAR_1}をもらった！$"
NewBarkTown_Lab_Text_Nickname:
	.string "{JPN}あなたの {STR_VAR_1} に\n"
	.string "{JPN}ニックネームを つけますか?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "{JPN}ポケモンじいさんはヨシノタウンを\nこえたところにすんでいる\lんだ\pほぼまっすぐだから\nまよわないはずだよ\pねんのためぼくのでんわばんごうを\nおしえておこう なにかあったら\lでんわしてくれ！$"
NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "{JPN}ポケモンをもっていれば\n"
	.string "{JPN}やせいのポケモンがでてきても\l"
	.string "{JPN}たたかわせればいいんだよ！$"
NewBarkTown_Lab_Text_ElmDirections2:
	.string "{JPN}やせいのポケモンがでてきたら\nきみのポケモンとたたかわせよう！\pポケモンがきずついたら\nみぎのマシンかポケモンセンターで\lかいふくさせるんだ\pきみをしんじているよ！$"
NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{JPN}{PLAYER}はウツギはかせの\nでんわばんごうをとうろくした！$"
NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "{JPN}ポケモンじいさんはいろんなところで\nめずらしいものをみつけるんだ\pただめずらしいだけで\nあまりやくにはたたないがね.$"
NewBarkTown_Lab_Text_ElmPokeBall:
	.string "{JPN}ウツギはかせがつかまえた\nポケモンがはいっている$"@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "{JPN}{PLAYER}くん..\n"
	.string "{JPN}たいへんなめにあったよ\p"
	.string "{JPN}あっそうそう\n"
	.string "{JPN}ポケモンじいさんの\l"
	.string "{JPN}だいはっけんってなんだったの？$"
NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{JPN}{PLAYER}はウツギはかせに\n"
	.string "{JPN}ふしぎなタマゴをわたした！$"
NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "{JPN}ウツギこれが？$"
NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "{JPN}しかし.ポケモンのタマゴかい？\pもしそうならすごい\nだいはっけんだよ！\pウツギなんだって！？\pオーキドはかせがきみに\nポケモンずかんを？\p{PLAYER}くん それはほんとうかい？\nすっすごいじゃないか！\pはかせはトレーナーのそしつを\nみるめがすぐれているからね\pうーん {PLAYER}くん きみは\nチャンピオンになれるかもしれないよ\pポケモンとのあいしょうも\nばつぐんみたいだしね\pポケモンジムに\nちょうせんしてみるといい\pいちばんちかいのは\nキキョウシティのジムだ\p.{PLAYER}くん チャンピオンへの\nみちのりはながいよ\nでかけるまえに\nおかあさんとはなしておきなさい$"
NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "{JPN}がんばるんだよ！\n"
	.string "{JPN}ぼくもタマゴについてわかりしだい\l"
	.string "{JPN}れんらくするからね！$"
NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "{JPN}あれ{PLAYER}くん\n"
	.string "{JPN}ぼくのじょしゅとあわなかった？\p"
	.string "{JPN}きみにタマゴをとどけるため\n"
	.string "{JPN}キキョウのフレンドリィショップに\l"
	.string "{JPN}いってるはずなんだけど..$"
NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "{JPN}へんこう$"
NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{JPN}あれ{PLAYER}くん\n"
	.string "{JPN}タマゴかえったんでしょ\l"
	.string "{JPN}ポケモンどうしてるの？$"
NewBarkTown_Lab_Text_ShowTogepi1:
	.string "{JPN}ウツギ{PLAYER}くん！\nげんきそうだね！$"
NewBarkTown_Lab_Text_ShowTogepi2:
	.string "{JPN}えっ？そのポケモンは！？！$"
NewBarkTown_Lab_Text_ShowTogepi3:
	.string "{JPN}タマゴがかえったんだね！\nやっぱりポケモンは..\pいや..すべてのポケモンが\nそうとはかぎらないが..\pまだまだけんきゅうすることが\nたくさんあるなあ$"
NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "{JPN}ありがとう{PLAYER}くん！\nポケモンのなぞかいめいに\pきみはとてもやくにたってる！\nこれはおれいのきもちだよ$"
NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "{JPN}それはかわらずのいしだ\pポケモンのなかにはある\nレベルでしんかするしゅるいが\pかわらずのいしをもたせると\nしんかしなくなるんだ\pしんかさせたくないポケモンに\nもたせてみるといいよ$"
NewBarkTown_Lab_Text_ElmCallYou:
	.string "{JPN}じゃあなにかあったら\n"
	.string "{JPN}れんらくするからねよろしく！$"
NewBarkTown_Lab_Text_AideAfterTheft:
	.string "{JPN}..それにしても\p"
	.string "{JPN}ぬすまれたポケモン\n"
	.string "{JPN}いまごろどうしてるかな..\p"
	.string "{JPN}わるいひとにそだてられると\n"
	.string "{JPN}わるいポケモンになるっていうし..$"
NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "{JPN}やあ{PLAYER}くん！\n"
	.string "{JPN}ホントきみには\l"
	.string "{JPN}びっくりさせられちゃうよね\p"
	.string "{JPN}おかげでぼくのけんきゅうも\n"
	.string "{JPN}はかどってるよ！\p"
	.string "{JPN}これはぼくからのきもち\n"
	.string "{JPN}ぜひつかってよ！$"
NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "{JPN}そのマスターボールは！！\p"
	.string "{JPN}どんなポケモンでも\n"
	.string "{JPN}ぜったいにつかまえられる\l"
	.string "{JPN}きゅうきょくのモンスターボール\p"
	.string "{JPN}ポケモンのけんきゅうを\n"
	.string "{JPN}みとめられたひとに\l"
	.string "{JPN}おくられるものらしいけど..\p"
	.string "{JPN}ぼくよりきみのほうが\n"
	.string "{JPN}うまくつかえるとおもうからね\l"
	.string "{JPN}{PLAYER}くんにあげるよ！$"
NewBarkTown_Lab_Text_KimonoGirls:
	.string "{JPN}まいこさんたち\n"
	.string "{JPN}エンジュのかぶれんじょうで\l"
	.string "{JPN}まってるっていってたよ！\p"
	.string "{JPN}きみもあのタマゴからずいぶん\n"
	.string "{JPN}おおきなことにまきこまれて\l"
	.string "{JPN}たいへんだろうけど\p"
	.string "{JPN}ここまできたからには\n"
	.string "{JPN}さいごまでやりとげてほしいね$"
NewBarkTown_Lab_Text_KimonoWaiting:
	.string "{JPN}まいこさんたち\n"
	.string "{JPN}エンジュのかぶれんじょうで\l"
	.string "{JPN}まってるっていってたよ！$"
NewBarkTown_Lab_Text_League:
	.string "{JPN}ウツギはかせはははは..\nおつかれさま！\pあのふしぎなタマゴで\nたいへんなおもいをしたね？\pまいこはんたちが\nぼくのことをいってた？\pぼくはなんもかんけいないよ\pきみがじぶんできめて\nやりとげたんだ\pここまでやったからには\nポケモンリーグにいけるよ！\pセキエイこうげんへ\nむかうといい！\pいきかたはわかるかい？\n27ばんどうろから26ばん\pそこからまっすぐきただ！$"
NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "{JPN}やあ{PLAYER}くん\n"
	.string "{JPN}まっていたよ！\p"
	.string "{JPN}きょうきみをよんだのは\n"
	.string "{JPN}あげたいものがあるからなんだ！\p"
	.string "{JPN}ほら！\n"
	.string "{JPN}ふねのチケット\p"
	.string "{JPN}これでカントーのポケモンも\n"
	.string "{JPN}つかまえられるようになるね！$"
NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "{JPN}ふねはアサギシティから\nしゅっぱつするよ\pでも{PLAYER}くんは\nもうしってるよね\pポケモンといっしょに\nあちこちたびしたんだから\pカントーのオーキドはかせに\nよろしくつたえてよ！$"
NewBarkTown_Lab_Text_LabMonEgg:
	.string "{JPN}ウツギはかせがけんきゅうちゅう\nのポケモンのタマゴだ$"
NewBarkTown_Lab_Text_AideGivePotion:
	.string "{JPN}{PLAYER}くん！おつかいの\nきみにこれをあげよう$"
NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "{JPN}3にんしかいないから\nいつもいそがしいんだ$"
NewBarkTown_Lab_Text_AideSave:
	.string "{JPN}ときどきセーブするのを\nわすれないでね！\pスタートボタンをおして\nセーブをえらぶんだ！$"
NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "{JPN}そとでおおきなおとがして..\n"
	.string "{JPN}はかせとみにいったすきに\l"
	.string "{JPN}ポケモンをぬすまれたようです..\p"
	.string "{JPN}..はあ\n"
	.string "{JPN}ぬすまれたポケモン\l"
	.string "{JPN}いまごろどうしてるだろう..\p"
	.string "{JPN}わるいひとにそだてられると\n"
	.string "{JPN}わるいポケモンになるっていうし..$"
NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{JPN}{PLAYER}くん！\pポケモンずかんかんせいに\nこれをつかってね！$"
NewBarkTown_Lab_Text_AideExplainBalls:
	.string "{JPN}ポケモンずかんをかんせい\nさせるにはつかまえること\pやせいポケモンに\nモンスターボールをなげるんだ$"
NewBarkTown_Lab_Text_Officer1:
	.string "{JPN}ここでポケモンがぬすまれた\nときいてきました..\pウツギはかせからはなしを\nうかがっていたところです\pはんにんはあかいかみの\nわかいおとこだそうで..\pなに？\pそんなトレーナーと\nたたかったって？\pなまえをきいてませんか？$"
NewBarkTown_Lab_Text_Officer2_1:
	.string "{JPN}なるほど！\n"
	.string "{JPN}{RIVAL}というのだね！$"
NewBarkTown_Lab_Text_Officer2:
	.string "{JPN}ごきょうりょくありがとう！\p"
	.string "{JPN}ほんかんのつぎなるこうどうは\n"
	.string "{JPN}あかいかみのじんぶつをおえ！\l"
	.string "{JPN}というわけだな！$"
NewBarkTown_Lab_Text_OfficerNo:
	.string "{JPN}たしかにあいつのなまえを\nきいたんだろう？！$"
NewBarkTown_Lab_Text_Elm_CallMe:
	.string "{JPN}ああ {PLAYER}くん！\pポケモンずかんのちょうしは\nどうだい？\nいまはいそがしいけど\lこんどでんわしてくれれば\lしんぽをみてあげるよ！$"