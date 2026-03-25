.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_MAHOGANY_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_GARBAGEFLAG
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	goto_if_set FLAG_FINITE_TMS, SlateportCity_EventScript_PowerTMClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
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

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
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

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "{JPN}おれは エナジーグル だ!\n"
	.string "{JPN}やるき まんまんで なんでも\lうってやるぞ!$"

SlateportCity_Text_OhYourPokemon:
	.string "{JPN}あら?\n"
	.string "{JPN}きみの {STR_VAR_1}...$"
SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "{JPN}すっげぇ がんばったな!\p"
	.string "{JPN} ごほうびに この\n"
	.string "{JPN}がんばリボンを あげてくれ!$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{JPN}{PLAYER}は がんばリボンを\nもらった!$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{JPN}{PLAYER}は {STR_VAR_1}に\n"
	.string "{JPN}がんばリボンを つけた!$"

SlateportCity_Text_GoForItLittleHarder:
	.string "{JPN}もうちょっと がんばって\n"
	.string "{JPN}みろよ!\p"
	.string "{JPN} そうすれば きみの ポケモンに\nいいものを あげるからな!$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "{JPN}おお! きみの {STR_VAR_1}!\n"
	.string "{JPN}その がんばリボン にあってるな!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "{JPN}とうだいの ひかりは\n"
	.string "{JPN}すうじゅうマイルさき まで とどくよ\p"
	.string "{JPN} うみの ポケモンたちを\n"
	.string "{JPN}おどろかせたり しないかな?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "{JPN}おおっ これを みてくれ!\p"
	.string "{JPN} このへんで とれる わかめは\n"
	.string "{JPN}しんせんで いきいき してるんだ\p"
	.string "{JPN} まるで たちあがって\n"
	.string "{JPN}こうげき してきそうだよ!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "{JPN}みずが きれいな ところには\n"
	.string "{JPN}ゆたかな みのりが あつまる\p"
	.string "{JPN} ひとが あつまる ところには\n"
	.string "{JPN}やがて いちばが できる\p"
	.string "{JPN} そうやって まちは うまれ\nそだって いくんだ$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "{JPN}うみの かおりを かんじながら\n"
	.string "{JPN}おかいものが できるなんて...\p"
	.string "{JPN}カイナシティって\nすてきな ばしょね!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "{JPN}ニンギョウや クッションを\n"
	.string "{JPN}ゆかに おくと よごれちゃうの\p"
	.string "{JPN} ブロックを かって ニンギョウや\n"
	.string "{JPN}クッションを おいても\l"
	.string "{JPN}よごれない ように するのよ$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "{JPN}うおおおお! おれも\n"
	.string "{JPN}バトルテントで たたかうぞ!\p"
	.string "{JPN} でも そのまえに ポケモンを\n"
	.string "{JPN}つかまえなくちゃ!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "{JPN}ふう... つかれたあ...\p"
	.string "{JPN}キンセツシティから あるいて きたん\n"
	.string "{JPN}だけど このまちって でかいのね\p"
	.string "{JPN}こんなことなら じてんしゃで\n"
	.string "{JPN}くればよかったよ$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "{JPN}はくぶつかんを つくった クスノキ\n"
	.string "{JPN}という ひとは かいていたんさ\l"
	.string "{JPN}チームの リーダーでもあるんだ\p"
	.string "{JPN} だから みんな キャプテン クスノキ\nって よんでるよ$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "{JPN}あそこの ながい ぎょうれつ\n"
	.string "{JPN}なんだろう?$"
SlateportCity_Text_VisitedMuseumOften:
	.string "{JPN}こどものころは よく\n"
	.string "{JPN}はくぶつかんに きてたなあ\p"
	.string "{JPN} てんじひんを みて うみの しんぴ\n"
	.string "{JPN}について ゆめを みたものさ$"

SlateportCity_Text_QuitPushing:
	.string "{JPN}おい そこの きみ!\n"
	.string "{JPN}おすなよ! れつに ならんでるんだ!$"

SlateportCity_Text_AquaHasPolicy:
	.string "{JPN}アクアだんは さくせんちで\n"
	.string "{JPN}しゅうごう かいさんするのが\l"
	.string "{JPN}きほんだ$"

SlateportCity_Text_BossIsBrilliant:
	.string "{JPN}わが ボスは てんさいだ\p"
	.string "{JPN} いったい はくぶつかんで\n"
	.string "{JPN}なにを しようと してるんだろう?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "{JPN}あたらしい さくせんって\n"
	.string "{JPN}なんだろうね?\p"
	.string "{JPN}ボスは おこると こわいから\nしっぱいは できないよ...$"
SlateportCity_Text_ShouldTakeItAll:
	.string "{JPN}はくぶつかんに ひつような\n"
	.string "{JPN}ものが あるなら ぜんぶ\lもらって しまえ!$"

SlateportCity_Text_DontButtIn:
	.string "{JPN}おい そこの やつ!\n"
	.string "{JPN}じゃまするな!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "{JPN}ながい ぎょうれつかあ\p"
	.string "{JPN}にんきゲームを かうために\n"
	.string "{JPN}ならんだこと おもいだすなあ...$"
SlateportCity_Text_WhyAreWeLiningUp:
	.string "{JPN}なんで れつに ならんで\n"
	.string "{JPN}おかねを はらってるんだ?\p そのまま つっこめばいいのに!$"

SlateportCity_Text_WhatDoYouWant:
	.string "{JPN}なんだ?\n"
	.string "{JPN}なにか ようか?$"

SlateportCity_Text_IllReadSignForYou:
	.string "{JPN}この かんばんを よみたいのか?\n"
	.string "{JPN}おれが よんでやろう!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "{JPN}えーっと...\p"
	.string "{JPN}たしか うみの いのちは\n"
	.string "{JPN}かぎりないって かんじかな?\p"
	.string "{JPN}そう かいてある おもうよ$"
	.string ""

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "{JPN}ぶつぶつ...\p"
	.string "{JPN}ゲームボーイアドバンスを\n"
	.string "{JPN}もってくれば よかったよ...\p"
	.string "{JPN}ぶつぶつ...$"
SlateportCity_Text_HotSpringsAfterOperation:
	.string "{JPN}この さくせんが おわったら\n"
	.string "{JPN}おんせんに つれていってやる!\p"
	.string "{JPN} それが リーダーとの やくそくだ\n"
	.string "{JPN}たのしみだなあ!$"

SlateportCity_Text_SeaIsSoWet:
	.string "{JPN}うみって ひろいなあ...\p"
	.string "{JPN}うみって ポケモンの なみだで\n"
	.string "{JPN}できたのかな?$"

SlateportCity_Text_SinkOldBoats:
	.string "{JPN}ふるくなって うみに でられなく\n"
	.string "{JPN}なった ふねが どうなるか しってる?\p"
	.string "{JPN} うみに しずめて ポケモンたちの\n"
	.string "{JPN}すみかに してあげるんだよ$"

SlateportCity_Text_BuyTooMuch:
	.string "{JPN}ここに くると いつも\n"
	.string "{JPN}ちょうしに のって かいすぎちゃう$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "{JPN}ポケモンの ニックネームを\n"
	.string "{JPN}かえたいなら なまえはんていしに\l"
	.string "{JPN}たのまなくちゃ だめよ$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "{JPN}こうかんで もらった ポケモンの\n"
	.string "{JPN}ニックネームは かえられないよ.\p"
	.string "{JPN}そのポケモンに たいする\n"
	.string "{JPN}もとのトレーナーの あいじょうが\lニックネームに こめられているんだ.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "{JPN}さいきん カナシダシティに\n"
	.string "{JPN}バトルテントが たてられたんだ.\p"
	.string "{JPN}ジムも たのしいけど\n"
	.string "{JPN}バトルテントも それなりに\l"
	.string "{JPN}すごいんだよ.\p"
	.string "{JPN}バトルテントのために\nつよいポケモンを さがしてみなよ!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "{JPN}ゆうめいな スターだったら\n"
	.string "{JPN}サインを もらえると\l"
	.string "{JPN}おもってたんだけどな.\p"
	.string "{JPN}でも インタビューを うけてるのは\nだれなんだろう?\lあれって クスノキかんちょうじゃない?$"

SlateportCity_Text_InterviewerSoCool:
	.string "{JPN}あの おんなの ひとの\n"
	.string "{JPN}インタビューアー とても\l"
	.string "{JPN}かっこよくて きれいね.\p"
	.string "{JPN}おおきくなったら\nこくさいてきな ジャーナリストに\lなるの!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "{JPN}クスノキかんちょうが うみの\n"
	.string "{JPN}そこで なにかを はっけん\l"
	.string "{JPN}したって いってるよ.\p"
	.string "{JPN}なんだろう?\nなにかな?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "{JPN}ここで なにが おこってるんだ?\p"
	.string "{JPN}かんちょうさんが うみの そこから\n"
	.string "{JPN}おおきな さかなを もってかえって\lきたのかな?$"

SlateportCity_Text_AmIOnTV:
	.string "{JPN}おい! みてるかい?\n"
	.string "{JPN}ぼく テレビに うつってる?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "{JPN}テレビインタビュー! ここで!\n"
	.string "{JPN}かんちょうは ゆうめいじんだ!$"

SlateportCity_Text_BigSmileForCamera:
	.string "{JPN}テレビー: はい クスノキかんちょう\n"
	.string "{JPN}カメラに むかって\lおおきく わらってください!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "{JPN}ガビー:なるほど なるほど\n"
	.string "{JPN}とても きちょうな たいけんを...$"
SlateportCity_Text_SternMoveAheadWithExploration:
	.string "{JPN}クスノキかんちょう: はい そのとおりです.\n"
	.string "{JPN}わたしたちは たんさを\lつづけていく つもりです.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "{JPN}ガビー: それは すばらしいですね\n"
	.string "{JPN}クスノキかんちょう!\l"
	.string "{JPN}いそがしい なかで\p"
	.string "{JPN}インタビューの じかんを\n"
	.string "{JPN}つくって いただき\lありがとうございました.\pまた あらたな はっけんの\nニュースで インタビュー\lできることを のぞんでいます!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "{JPN}クスノキ せんちょう:ふう...\p"
	.string "{JPN}テレビのインタビューなんて\n"
	.string "{JPN}はじめてで きんちょうしたよ$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "{JPN}おお! {PLAYER}くん!\n"
	.string "{JPN}げんきそうだね!\p"
	.string "{JPN}ぜんかいの かいていたんさで\n"
	.string "{JPN}おおきな はっけんを したんだ.\p"
	.string "{JPN}ルート128で すいちゅうの\n"
	.string "{JPN}どうくつを みつけたんだ.\p"
	.string "{JPN}ずっと ぜつめつしたと\n"
	.string "{JPN}いわれていた ポケモンの\lすみかだと おもうんだ.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "{JPN}ふふふ...\n"
	.string "{JPN}クスノキ せんちょうですね\p"
	.string "{JPN}われわれ アクアだんが\n"
	.string "{JPN}あなたの せんすいかんを\l"
	.string "{JPN}いただきます!\p"
	.string "{JPN}もんくは きかない!\n"
	.string "{JPN}おとなしく したがいなさい!\p"
	.string "{JPN}ふふふ...\n"
	.string "{JPN}アクアだんの けいかくを\lとくと みているがいい!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "{JPN}クスノキ せんちょう:いまのは\n"
	.string "{JPN}なんだったんだ?\p"
	.string "{JPN}だれか メガホンを つかって\n"
	.string "{JPN}はなしていたような...\pどこから きこえたんだろう?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "{JPN}みなとから きた!\p"
	.string "{JPN}せんすいかんを!\n"
	.string "{JPN}うばおうと してる!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{JPN}{PLAYER}くん!\n"
	.string "{JPN}おねがいします いっしょに きて!$"

SlateportCity_Text_BattleTentSign:
	.string "{JPN}バトルテント カナシダしてん\n"
	.string "{JPN}みつけろ! さいきょうの ポケモン!$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "{JPN}クスノキぞうせんじょ\p"
	.string "{JPN}ぼしゅう: すべての かいりゅうを\n"
	.string "{JPN}こうかい できる せんいん$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "{JPN}クスノキぞうせんじょ\p"
	.string "{JPN}カナシダこうと ミナモこうを\n"
	.string "{JPN}むすぶ れんらくせん タイドリップごうの\l"
	.string "{JPN}かんせいが ちかづいています$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "{JPN}クスノキぞうせんじょ\p"
	.string "{JPN}カナシダーミナモかん\n"
	.string "{JPN}れんらくせん タイドリップごうの\l"
	.string "{JPN}じょうせんは みなとで おこないます$"

SlateportCity_Text_PokemonFanClubSign:
	.string "{JPN}ポケモンだいすきクラブ\n"
	.string "{JPN}ポケモンファン だいしゅうごう!$"

SlateportCity_Text_OceanicMuseumSign:
	.string "{JPN}おわりなき うみが\n"
	.string "{JPN}すべての いのちを はぐくむ\p"
	.string "{JPN}かいようはくぶつかん$"

SlateportCity_Text_CitySign:
	.string "{JPN}カナシダシティ\p"
	.string "{JPN}ひとと ポケモンが\n"
	.string "{JPN}であう みなとまち$"

SlateportCity_Text_MarketSign:
	.string "{JPN}カナシダマーケット\n"
	.string "{JPN}ここでしか てにはいらない レアなアイテム!$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "{JPN}カナシダこう\p"
	.string "{JPN}れんらくせん タイドリップごうは\n"
	.string "{JPN}ぞうせんじょで けんせつちゅうです.\p"
	.string "{JPN}サービスは まもなく\n"
	.string "{JPN}かいしよてい です$"

SlateportCity_Text_HarborSign:
	.string "{JPN}カナシダこう\p"
	.string "{JPN}れんらくせん タイドリップごうで\n"
	.string "{JPN}たのしい クルーズを どうぞ$"

SlateportCity_Text_NameRatersHouseSign:
	.string "{JPN}なまえおやじの いえ\n"
	.string "{JPN}ポケモンの ニックネーム ひょうか$"

SlateportCity_Text_ExplainBerries:
	.string "{JPN}やせいの ポケモンが きずついたとき\n"
	.string "{JPN}きのみを かじって じぶんを\l"
	.string "{JPN}なおすんだよ.\p"
	.string "{JPN}しってた?\p"
	.string "{JPN}それを みた だれかが きのみから\n"
	.string "{JPN}くすりを つくることを おもいついた\l"
	.string "{JPN}んだって.\p"
	.string "{JPN}しってた?\n"
	.string "{JPN}きのみを くすりに するには\n"
	.string "{JPN}こなに くだかないと だめなんだ.\p"
	.string "{JPN}しってた?\n"
	.string "{JPN}きみは きのみに きょうみが\n"
	.string "{JPN}ありそうだね!\pきみの ような ひとには\nいいものが あるよ.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "{JPN}さいきん ポケモンセンターに きのみを\n"
	.string "{JPN}くだく マシンを せっちしたんだ.\p"
	.string "{JPN}バリバリマシンは にかいの\n"
	.string "{JPN}ダイレクトコーナーに あるよ.\p"
	.string "{JPN}しってた?\p"
	.string "{JPN}そのマシンを つかって ぼくのために\n"
	.string "{JPN}きのみのこなを つくってくれる?\p"
	.string "{JPN}きのみのこなを たくさん もってきて\n"
	.string "{JPN}くれれば いろんな くすりを\lつくってあげるよ.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "{JPN}きのみのこなを もってきて\n"
	.string "{JPN}くれたかな?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "{JPN}なにと こうかん したいかな?$"
	.string ""

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "{JPN}よし きのみのこなと\n"
	.string "{JPN}{STR_VAR_1} ひとつを\lこうかんするんだね?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "{JPN}あれれ.きのみのこなが\n"
	.string "{JPN}たりないよ.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "{JPN}これは いいきのみのこなだね.\n"
	.string "{JPN}すばらしい くすりが できるよ.\p"
	.string "{JPN}ほかにも きのみのこなと\n"
	.string "{JPN}なにかを こうかん したいかい?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "{JPN}わかった!きのみのこなが\n"
	.string "{JPN}もっと てにはいったら\lもってきて おくれ!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "{JPN}きのみのこなと くすりを\n"
	.string "{JPN}こうかん したくなったら\l"
	.string "{JPN}また きてよ.\p"
	.string "{JPN}いつでも ここで ばざーを\nやってるからね.\pしってた?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "{JPN}エニシダあれ?\n"
	.string "{JPN}きみと どこかで あったような\l"
	.string "{JPN}きが するなあ.\p"
	.string "{JPN}じこしょうかい したかな?\n"
	.string "{JPN}もし してなかったら ぼくは\l"
	.string "{JPN}エニシダだ.\p"
	.string "{JPN}さっき アクアだんが はちに\nさされたような かおで\lにげていくのを みたよ.\pもしかして きみが おいはらった?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "{JPN}エニシダ:うーん...\n"
	.string "{JPN}もしかして このトレーナーは...$"
SlateportCity_Text_LetsRegisterEachOther:
	.string "{JPN}エニシダ:よし! きみとは\n"
	.string "{JPN}よい ともだちに なれそうだ\p"
	.string "{JPN}おたがいの ポケナビに\n"
	.string "{JPN}とうろく しあおう\p"
	.string "{JPN}... ... ... ... ... ...$"
SlateportCity_Text_RegisteredScott:
	.string "{JPN}エニシダさんを ポケナビに\n"
	.string "{JPN}とうろく しました.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "{JPN}エニシダきみと いっしょに\n"
	.string "{JPN}たびを したいけど ほかの ひとの\l"
	.string "{JPN}さいのうも みて おきたいんだ.\p"
	.string "{JPN}だから ほかの まちを まわって\n"
	.string "{JPN}くるよ.\p"
	.string "{JPN}それじゃあ {PLAYER}くん!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "{JPN}エニシダおお!\n"
	.string "{JPN}{PLAYER}くん じゃないか!\p"
	.string "{JPN}{PLAYER}くん もしかして バトルテントの\n"
	.string "{JPN}チャレンジを するつもりかな?\p"
	.string "{JPN}そうか!それは いいかんがえだ!\n"
	.string "{JPN}ほんとうに すばらしい かんがえだよ!\p"
	.string "{JPN}つよい トレーナーこそ\n"
	.string "{JPN}バトルテントに ぴったりだからね!\p"
	.string "{JPN}がんばって!$"
