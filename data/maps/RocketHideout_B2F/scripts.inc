.set LOCALID_ROCKETHIDEOUT2_LANCE, 7
.set LOCALID_ROCKETHIDEOUT2_DRAGONITE, 8
.set LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, 15
.set LOCALID_ROCKETHIDEOUT2_MURKROWGATE, 16
.set LOCALID_ROCKETHIDEOUT2_ARIANA, 14
.set LOCALID_ROCKETHIDEOUT2_GRUNT, 12
.set LOCALID_LANCEELECTRODE1, 3
.set LOCALID_LANCEELECTRODE2, 2
.set LOCALID_LANCEELECTRODE3, 1


RocketHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B2F_OnLoad
	.byte 0

RocketHideout_B2F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT2_GATE, RocketHideout_B2F_HideGate
	call_if_eq VAR_MAHOGANY_TOWN_STATE, 13, RocketHideout_B2F_MoveLanceDragonite
	call_if_ge VAR_ELECTRODES_FAINTED, 4, RockerHideout2_DeactivateGenerator
	end

RockerHideout2_DeactivateGenerator::
	setmetatile 13, 8, 0x303, TRUE
	setmetatile 13, 9, 0x303, TRUE
	setmetatile 13, 10, 0x303, TRUE
	setmetatile 13, 11, 0x303, TRUE
	setmetatile 13, 12, 0x303, TRUE
	setmetatile 13, 13, 0x303, TRUE
	setmetatile 13, 14, 0x303, TRUE
	setmetatile 13, 15, 0x303, TRUE

	setmetatile 14, 8, 0x303, TRUE
	setmetatile 14, 9, 0x303, TRUE
	setmetatile 14, 10, 0x303, TRUE
	setmetatile 14, 11, 0x303, TRUE
	setmetatile 14, 12, 0x303, TRUE
	setmetatile 14, 13, 0x303, TRUE
	setmetatile 14, 14, 0x303, TRUE
	setmetatile 14, 15, 0x303, TRUE

	setmetatile 15, 8, 0x303, TRUE
	setmetatile 15, 9, 0x303, TRUE
	setmetatile 15, 10, 0x303, TRUE
	setmetatile 15, 11, 0x303, TRUE
	setmetatile 15, 12, 0x303, TRUE
	setmetatile 15, 13, 0x303, TRUE
	setmetatile 15, 14, 0x303, TRUE
	setmetatile 15, 15, 0x303, TRUE

	setmetatile 16, 8, 0x303, TRUE
	setmetatile 16, 9, 0x303, TRUE
	setmetatile 16, 10, 0x303, TRUE
	setmetatile 16, 11, 0x303, TRUE
	setmetatile 16, 12, 0x303, TRUE
	setmetatile 16, 13, 0x303, TRUE
	setmetatile 16, 14, 0x303, TRUE
	setmetatile 16, 15, 0x303, TRUE

	setmetatile 17, 8, 0x303, TRUE
	setmetatile 17, 9, 0x303, TRUE
	setmetatile 17, 10, 0x303, TRUE
	setmetatile 17, 11, 0x303, TRUE
	setmetatile 17, 12, 0x303, TRUE
	setmetatile 17, 13, 0x303, TRUE
	setmetatile 17, 14, 0x303, TRUE
	setmetatile 17, 15, 0x303, TRUE

	setmetatile 18, 8, 0x303, TRUE
	setmetatile 18, 9, 0x303, TRUE
	setmetatile 18, 10, 0x303, TRUE
	setmetatile 18, 11, 0x303, TRUE
	setmetatile 18, 12, 0x303, TRUE
	setmetatile 18, 13, 0x303, TRUE
	setmetatile 18, 14, 0x303, TRUE
	setmetatile 18, 15, 0x303, TRUE
	return

RocketHideout_B2F_HideGate::
	setmetatile 14, 19, 0x378, FALSE
	setmetatile 14, 20, 0x380, FALSE
	setmetatile 15, 19, 0x379, FALSE
	setmetatile 15, 20, 0x379, FALSE
	setmetatile 16, 19, 0x379, FALSE
	setmetatile 16, 20, 0x379, FALSE
	return

RocketHideout_B2F_MoveLanceDragonite::
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	return

RocketHideout_B2F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setvar VAR_MAHOGANY_TOWN_STATE, 10
	release
	end

RocketHideout_B2F_Movement_MurkrowStairs1:
	jump_in_place_left
	jump_in_place_left
	step_end

RocketHideout_B2F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Trigger_MurkrowGate::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_Murkrow, MSGBOX_DEFAULT
	msgbox RocketHideout_B2F_Text_MurkrowUnlock, MSGBOX_DEFAULT
	playse SE_CLICK
	setmetatile 14, 19, 0x378, FALSE
	setmetatile 14, 20, 0x380, FALSE
	setmetatile 15, 19, 0x379, FALSE
	setmetatile 15, 20, 0x379, FALSE
	setmetatile 16, 19, 0x379, FALSE
	setmetatile 16, 20, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT2_GATE
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 12
	release
	end
RocketHideout_B2F_Movement_MurkrowGate1:
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B2F_Movement_MurkrowGate2:
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RocketHideout_B2F_Text_MurkrowUnlock:
    .string "{JPN}ヤミカラスが ペトレルの こえを\n"
	.string "{JPN}まねして あいことばを いった.\p"
    .string "{JPN}...\n"
	.string "{JPN}おんせいにんしき システムが\l"
    .string "{JPN}とびらの ロックを かいじょした!$"

@============================================================================================================================================

RocketHideout_B2F_Trigger_PlayerMoveLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return
RocketHideout_B2F_Trigger_PlayerMoveRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

RocketHideout_B2F_Trigger_Ariana::
	lock 
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 6, 26
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 5, 26
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	addobject LOCALID_ROCKETHIDEOUT2_ARIANA
	addobject LOCALID_ROCKETHIDEOUT2_GRUNT
	delay 20
	msgbox RocketHideout_B2F_Text_ArianaHoldIt, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 14, RocketHideout_B2F_Trigger_PlayerMoveLeft
	call_if_eq VAR_TEMP_0, 16, 	RocketHideout_B2F_Trigger_PlayerMoveRight
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerMeetAriana
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, RocketHideout_B2F_Movement_Ariana
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, RocketHideout_B2F_Movement_Ariana
	waitmovement LOCALID_ROCKETHIDEOUT2_GRUNT
	msgbox RocketHideout_B2F_Text_ArianaChallenge, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	addobject LOCALID_ROCKETHIDEOUT2_LANCE
	addobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_Lance
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_Lance
	waitmovement 0
	msgbox RocketHideout_B2F_Text_LanceInterrupt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkInPlaceFasterUp
	msgbox RocketHideout_B2F_Text_ArianaOutraged
	closemessage
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt
	end
	
RocketHideout_B2F_Movement_PlayerMeetAriana:
	walk_down
	walk_down
	walk_down
	step_end

RocketHideout_B2F_Movement_Ariana:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B2F_Movement_Lance:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Text_ArianaHoldIt:
    .string "{JPN}アリアナ: そこで とまりなさい!$"

RocketHideout_B2F_Text_ArianaChallenge:
    .string "{JPN}アリアナ: あんたみたいな がきに\n"
	.string "{JPN}いつまでも すきかってに させる\l"
    .string "{JPN}わけには いかないの.\p"
	.string "{JPN}ロケットだんの プライドが\n"
    .string "{JPN}きずつくのよ.\l"
	.string "{JPN}どんどん おちていく のよ.\p"
    .string "{JPN}...だから あんたを\n"
	.string "{JPN}おわりに してあげる.\p"
    .string "{JPN}いくら つよくても\n"
	.string "{JPN}ふたりで かかれば\l"
    .string "{JPN}かてっこ ないでしょ?\p"
	.string "{JPN}うふふふ! ざんねんね.\nぼこぼこに されなさい!$"

RocketHideout_B2F_Text_LanceInterrupt:
    .string "{JPN}ワタル: まて!\n"
	.string "{JPN}2たい1の バトル?\p"
    .string "{JPN}それは ひきょうだ!\n"
	.string "{JPN}ロケットだんらしい\l"
    .string "{JPN}きたない てだな.\p"
	.string "{JPN}ぼくも せんとうに さんかしよう!$"

RocketHideout_B2F_Text_ArianaOutraged:
    .string "{JPN}アリアナ: なに? なかまが いたの?\n"
	.string "{JPN}プライドって ものが ないの?\p"
    .string "{JPN}サカキさまの かわりの\n"
	.string "{JPN}りんじボスとして ロケットだんに\l"
    .string "{JPN}さからう まちがいを おしえてあげる!$"

RocketHideout_B2F_Text_LanceChooseMons:
    .string "{JPN}ワタル: はやく {PLAYER}\n"
	.string "{JPN}ポケモンを えらぶんだ!$"

RocketHideout_B2F_EventScript_ReadyForBattlePrompt::
	msgbox RocketHideout_B2F_Text_LanceChooseMons, MSGBOX_DEFAULT
	goto RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle
	end

RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle::
	setflag FLAG_ROCKETHIDEOUT2_BATTLE
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, RocketHideout_B2F_EventScript_DoLanceMultiBattle
	special LoadPlayerParty
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt

RocketHideout_B2F_EventScript_DoLanceMultiBattle::
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_LANCE
	setvar VAR_0x8005, 0
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, Common_Movement_WalkUp1
	waitmovement 0
	turnobject LOCALID_ROCKETHIDEOUT2_GRUNT, DIR_WEST
	special DoSpecialTrainerBattle
	waitstate
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, RocketHideout_B2F_EventScript_DefeatedAriana
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	special SetCB2WhiteOut
	waitstate

RocketHideout_B2F_EventScript_ArianaTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_ARIANA_1, 0, RocketHideout_B2F_Text_ArianaLoss, RocketHideout_B2F_Text_ArianaLoss
	end

RocketHideout_B2F_EventScript_GruntTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_GRUNT_23, 0, RocketHideout_B2F_Text_GruntLoss, RocketHideout_B2F_Text_GruntLoss
	end

RocketHideout_B2F_EventScript_DefeatedAriana::
	clearflag FLAG_ROCKETHIDEOUT2_BATTLE
	msgbox RocketHideout_Text_ArianaRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkRight1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkRight1
	waitmovement 0
	setflag FLAG_HIDE_MAHOGANY_ROCKETS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	removeobject LOCALID_ROCKETHIDEOUT2_ARIANA
	removeobject LOCALID_ROCKETHIDEOUT2_GRUNT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox RocketHideout_Text_LanceStepBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteWalkToGenerator
	delay 55
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_LanceWalkToGenerator
	waitmovement 0

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteInvestigateGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceInvestigateGenerator
	delay 165
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	msgbox RocketHideout_B2F_Text_LanceElectrodeFaint, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerWalkToElectrode
	waitmovement 0
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	setvar VAR_MAHOGANY_TOWN_STATE, 13
	release
	end

RocketHideout_B2F_Movement_LanceWalkToGenerator:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
RocketHideout_B2F_Movement_DragoniteWalkToGenerator:
	delay_8
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	step_end


RocketHideout_B2F_Movement_LanceInvestigateGenerator:
	walk_up
	walk_left
	face_up
	delay_8
	delay_8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	delay_8
	delay_8
	face_right
	delay_8
	delay_8
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	face_down
	step_end

RocketHideout_B2F_Movement_DragoniteInvestigateGenerator:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	delay_16
	delay_16
	delay_8
	delay_8	
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceWalkToElectrode:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RocketHideout_B2F_Movement_PlayerWalkToElectrode:
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Trigger_Electrode::
	lock
	goto_if_eq VAR_ELECTRODES_FAINTED, 3, RocketHideout_B2F_EventScript_ElectrodeDone
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_WEST
	msgbox RocketHideout_B2F_Text_LanceSide, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	release
	end

RocketHideout_B2F_EventScript_Electrode::
	lock
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ELECTRODE, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RocketHideout_B2F_EventScript_Ran_Electrode
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RocketHideout_B2F_EventScript_Ran_Electrode
	removeobject VAR_LAST_TALKED
	addvar VAR_ELECTRODES_FAINTED, 1
	release
	end

RocketHideout_B2F_EventScript_Ran_Electrode::
	release
	end

RocketHideout_B2F_EventScript_ElectrodeDone::
	playse SE_M_HYPER_BEAM
	removeobject LOCALID_LANCEELECTRODE1
	removeobject LOCALID_LANCEELECTRODE2
	removeobject LOCALID_LANCEELECTRODE3
	waitse
	getplayerxy VAR_TEMP_0, VAR_TEMP_1 
	call_if_eq VAR_TEMP_1, 16, RocketHideout_B2F_Movement_PlayerMeetLanceTop
	call_if_eq VAR_TEMP_1, 18, RocketHideout_B2F_Movement_PlayerMeetLanceBot
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE

	playse SE_CLICK
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	call RockerHideout2_DeactivateGenerator
	special DrawWholeMapView
	delay 55
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox RocketHideout_B2F_Text_LanceElectrodeDone, MSGBOX_DEFAULT
	giveitem ITEM_HM_WHIRLPOOL
	msgbox RocketHideout_B2F_Text_LanceWhirlpool, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_SOUTH
	delay 20
	msgbox RocketHideout_B2F_Text_LanceMonMaster, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceFinalExit
	delay 20

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteFinalExit
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE

	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_ELECTRODES_FAINTED, 4
	setvar VAR_MAHOGANY_TOWN_STATE, 14
	clearflag FLAG_HIDE_MAHOGANY_COP
	setflag FLAG_HIDE_MAHOGANY_TOWN_FATMAN
	setvar VAR_ROCKET_HIDEOUT_STATUE_1, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_2, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_3, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_4, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_5, 2
	release
	end

RocketHideout_B2F_Movement_PlayerMeetLanceTop:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	return

RocketHideout_B2F_Movement_PlayerMeetLanceBot:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	return

RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceFinalExit:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Movement_DragoniteFinalExit:
	walk_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Text_GruntLoss:
    .string "...$"

RocketHideout_B2F_Text_ArianaLoss:
    .string "{JPN}ちっ ほんとうに つよいのね.\n"
	.string "{JPN}ざんねんだわ.\p"
    .string "{JPN}ロケットだんに はいれば\n"
	.string "{JPN}かんぶに なれたのに.$"

RocketHideout_Text_ArianaRetreat:
    .string "{JPN}アリアナ: でも いいの.\n"
	.string "{JPN}でんぱの じっけんは\l"
    .string "{JPN}だいせいこうだった.\p"
	.string "{JPN}ここの アジトが どうなっても\n"
    .string "{JPN}かまわないの.\p"
	.string "{JPN}もっと おおきな けいかくが\n"
    .string "{JPN}あるのよ. ロケットだんの\l"
	.string "{JPN}ほんとうの ちからを しるがいい.\n"
    .string "{JPN}いまのうちに たのしみなさい...\n"
	.string "{JPN}うふふふ...$"

RocketHideout_Text_LanceStepBack:
    .string "{JPN}すまない {PLAYER}. きみが\n"
	.string "{JPN}がんばってるのを みてたから\l"
    .string "{JPN}うしろで みていたよ.\p"
	.string "{JPN}あとは あの へんな でんぱを\nとめるだけだな.$"


RocketHideout_B2F_Text_LanceElectrodeFaint:
    .string "{JPN}このきかいが すべての\n"
	.string "{JPN}もんだいの げんいんだ.\p"
    .string "{JPN}スイッチが みあたらない...\p"
	.string "{JPN}しかたない.すべての\n"
    .string "{JPN}マルマインを きぜつ\l"
	.string "{JPN}させるしかない.\p"
    .string "{JPN}そうすれば このきかいの\n"
	.string "{JPN}へんなでんぱを とめる\l"
    .string "{JPN}ことが できるはずだ.\p"
	.string "{JPN}ポケモンに つみはないのに\n"
    .string "{JPN}もうしわけない きもちだ.\p{PLAYER} やくわりを\nわけて やろう.$"

RocketHideout_B2F_Text_LanceSide:
    .string "{JPN}ワタル: こちらがわは\nぼくに まかせろ.$"

RocketHideout_B2F_Text_LanceElectrodeDone:
    .string "{JPN}ワタル: あの へんな しんごうが\n"
	.string "{JPN}やっと とまったな.\p"
    .string "{JPN}みずうみも もとに\n"
	.string "{JPN}もどっただろう.\p"
    .string "{JPN}きみが ヒーローだ! すべての\n"
	.string "{JPN}ポケモンの かわりに\l"
    .string "{JPN}おれいを いわせてくれ.\p"
	.string "{JPN}そうそう. これを もっていけ.\n"
    .string "{JPN}ここで みつけたが ぼくには\l"
	.string "{JPN}ひつような ないんだ.$"

RocketHideout_B2F_Text_LanceWhirlpool:
    .string "{JPN}それは うずしおだ. ポケモンに\n"
	.string "{JPN}おぼえさせれば あれた みずの\l"
    .string "{JPN}うえを わたれる.\p"
	.string "{JPN}だが おぼえておけ.\p"
    .string "{JPN}せんとういがいで つかうには\n"
	.string "{JPN}チョウジジムの バッジが\lひつようだ.$"

RocketHideout_B2F_Text_LanceMonMaster:
    .string "{JPN}{PLAYER}...\p"
	.string "{JPN}ポケモンマスターになる\n"
    .string "{JPN}たびは ながく つらい\l"
	.string "{JPN}ものだ.\p"
    .string "{JPN}それを しっても\n"
	.string "{JPN}あきらめずに いくか?\p"
    .string "{JPN}...\p"
	.string "{JPN}そうか.いや きみの\n"
    .string "{JPN}いうとおりだ.\p"
	.string "{JPN}かんたんに あきらめるなら\n"
    .string "{JPN}はじめから そのゆめを\l"
	.string "{JPN}おわなかったろうからな.\n"
    .string "{JPN}また あえるひを\nたのしみにしている!$"

RocketHideout_B2F_Text_B2FTransmitter:
    .string "{JPN}あくいに みちた しんごうを\n"
	.string "{JPN}おくっている ラジオの\l"
    .string "{JPN}そうしんきだ.\pフルパワーで うごいている.$"

RocketHideout_B2F_Text_B2FDeactivateTransmitter:
    .string "{JPN}ラジオそうしんきが ついに\n"
	.string "{JPN}あくの ほうそうを とめた.$"


@===========================================================================================================================================

RocketHideout_EventScript_Item_Thief::
	finditem ITEM_TM_THIEF
	end

RocketHideout_B2F_EventScript_LanceTriggerLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_LanceTriggerRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_Lance::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	msgbox RocketHideout_B2F_Text_LanceHeals1, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RocketHideout_B2F_Text_LanceHeals2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceGoDeeper
	applymovement2 LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteGoDeeper
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 6
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	release
	end

RocketHideout_B2F_Movement_LanceGoDeeper:
	walk_right
	walk_right
	delay_2
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Movement_DragoniteGoDeeper:
	delay_8
	delay_8
	delay_8
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Text_LanceHeals1:
    .string "{JPN}ワタル: だいじょうぶか?\p"
	.string "{JPN}きみの ポケモンが\n"
    .string "{JPN}きずついて つかれている.\p"
	.string "{JPN}ほら  ぼくの くすりを\nつかってくれ.$"

RocketHideout_B2F_Text_LanceHeals2:
    .string "{JPN}ワタル: {PLAYER}  ポケモンの\n"
	.string "{JPN}ために がんばろう.$"

RocketHideout_B2F_Text_GruntM17Seen:
    .string "{JPN}ドアが ひらかない?\n"
	.string "{JPN}あたりまえだろ. ロケットだんしか\n"
    .string "{JPN}しらない あいことばが いるんだ.$"
	.string ""

RocketHideout_B2F_Text_GruntM17Beaten:
    .string "{JPN}なんだと? まけた?$"

RocketHideout_B2F_Text_GruntM17After:
    .string "{JPN}へっ  おれは ただの したっぱだ.\p"
	.string "{JPN}あいことばなんて しらないぜ.\n"
    .string "{JPN}ざんねんだったな.$"

RocketHideout_B2F_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_14 RocketHideout_B2F_Text_GruntM17Seen, RocketHideout_B2F_Text_GruntM17Beaten
	msgbox RocketHideout_B2F_Text_GruntM17After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM18Seen:
    .string "{JPN}おお  がきか? あまり\n"
	.string "{JPN}きにいらないが けすしかない.$"

RocketHideout_B2F_Text_GruntM18Beaten:
    .string "{JPN}やっぱり まけちゃった...$"
RocketHideout_B2F_Text_GruntM18After:
    .string "{JPN}ぜんかいの にんむでも\n"
	.string "{JPN}ガキに やられたんだ.\p"
    .string "{JPN}ポケモンを さらっていたら\n"
	.string "{JPN}ながい あかいかみで\l"
    .string "{JPN}いじわるそうな めをした\l"
	.string "{JPN}ガキに ボコボコに\lされちまった...$"
RocketHideout_B2F_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_15 RocketHideout_B2F_Text_GruntM18Seen, RocketHideout_B2F_Text_GruntM18Beaten
	msgbox RocketHideout_B2F_Text_GruntM18After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM19Seen:
    .string "{JPN}うざったい ちいさな がきめ!$"

RocketHideout_B2F_Text_GruntM19Beaten:
    .string "{JPN}ぐぬぬ...$"
RocketHideout_B2F_Text_GruntM19After:
    .string "{JPN}へっ  あの ドアの あいことばは\n"
	.string "{JPN}ボスしか しらないんだ.\p"
    .string "{JPN}ボスが どこに いるかって?\n"
	.string "{JPN}しらないね. じぶんで さがせよ.$"

RocketHideout_B2F_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_16 RocketHideout_B2F_Text_GruntM19Seen, RocketHideout_B2F_Text_GruntM19Beaten
	msgbox RocketHideout_B2F_Text_GruntM19After, MSGBOX_AUTOCLOSE
	end

