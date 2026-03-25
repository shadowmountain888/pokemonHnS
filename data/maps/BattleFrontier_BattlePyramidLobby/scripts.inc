.set LOCALID_ATTENDANT, 1
.set LOCALID_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "{JPN}トレーナーの ゆうきが\n"
	.string "{JPN}ためされる ばしょ!\p"
	.string "{JPN}バトルピラミッドへ\n"
	.string "{JPN}ようこそ!\p"
	.string "{JPN}わたくしは バトルクエストの\nあんないやくです$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "{JPN}あなたには バトルクエストの\n"
	.string "{JPN}ちょうせんに たちむかう\lゆうきが おありですか?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "{JPN}またの ちょうせんを\nおまちしております!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "{JPN}バトルクエストとは ピラミッドを\n"
	.string "{JPN}たんけんして ちょうじょうを\l"
	.string "{JPN}めざす バトルイベントです\p"
	.string "{JPN}ピラミッドには 7かいの\n"
	.string "{JPN}めいろがあり そこには じゅくれんした\l"
	.string "{JPN}トレーナーや やせいポケモンがいます\p"
	.string "{JPN}3ひきの ポケモンで ちょうせんし\n"
	.string "{JPN}どうぐを もたせてはいけません\p"
	.string "{JPN}とちゅうで バトルバッグが\n"
	.string "{JPN}もらえて どうぐをいれられます\p"
	.string "{JPN}ちょうせんに しっぱいすると\n"
	.string "{JPN}バトルバッグの どうぐは きえます\p"
	.string "{JPN}ちょうせんを ちゅうだんするときは\n"
	.string "{JPN}やすむを えらんで\l"
	.string "{JPN}セーブしてください\p"
	.string "{JPN}セーブせずに ちゅうだんすると\n"
	.string "{JPN}しっかくになります$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "{JPN}ピラミッドには ノーマルと\n"
	.string "{JPN}ハードの 2つのコースがあります\l"
	.string "{JPN}どちらに ちょうせんしますか?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "{JPN}よろしい では いっしょに つれていく\n"
	.string "{JPN}3ひきの ポケモンを えらんでください$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "{JPN}ちょっと もんだいが ありますね!\p"
	.string "{JPN}ちょうせんに ひつような 3ひきの\n"
	.string "{JPN}ポケモンが そろっていないようです\p"
	.string "{JPN}ポケモンの どうぐも\n"
	.string "{JPN}すべて はずしてください\p"
	.string "{JPN}タマゴ{STR_VAR_1}は しゅつじょう\n"
	.string "{JPN}できません\p"
	.string "{JPN}じゅんびが できたら\nおこえがけください$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "{JPN}ちょっと もんだいが ありますね!\p"
	.string "{JPN}ちょうせんに ひつような 3ひきの\n"
	.string "{JPN}ポケモンが そろっていないようです\p"
	.string "{JPN}3ひきの ポケモンは\n"
	.string "{JPN}ちがう しゅるいでなければいけません\p"
	.string "{JPN}ポケモンの どうぐも\n"
	.string "{JPN}すべて はずしてください\p"
	.string "{JPN}タマゴ{STR_VAR_1}は しゅつじょう\n"
	.string "{JPN}できません\pじゅんびが できたら\nおこえがけください$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "{JPN}バトルピラミッドに はいるまえに\n"
	.string "{JPN}セーブが ひつようです よろしいですか?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "{JPN}よろしい では バトルピラミッドに\n"
	.string "{JPN}ごあんないいたします$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "{JPN}たんけんちゅう {PLAYER}さんの\n"
	.string "{JPN}バッグは こちらで\lおあずかりいたします$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "{JPN}そのかわり ぜんかいつかった\n"
	.string "{JPN}バトルバッグを おうけとりください$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "{JPN}そのかわり この バトルバッグを\n"
	.string "{JPN}おうけとりください$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{JPN}{PLAYER}は バッグを バトルバッグと\n"
	.string "{JPN}こうかんした!$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "{JPN}この ゆかパネルに のると\n"
	.string "{JPN}ピラミッドの うえの かいに\l"
	.string "{JPN}てんそうされます\p"
	.string "{JPN}あなたの クエストが ぶじに\n"
	.string "{JPN}すすむことを いのっています!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "{JPN}おおきな もんだいが ありました!\p"
	.string "{JPN}ぜんかい ちょうせんを おわる\n"
	.string "{JPN}まえに セーブしていませんでしたね\p"
	.string "{JPN}そのため ざんねんながら\n"
	.string "{JPN}ちょうせんは しっかくになりました\p"
	.string "{JPN}おあずかりしていた バッグを\n"
	.string "{JPN}おかえしします\p"
	.string "{JPN}{PLAYER}は バッグを とりかえした!$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "{JPN}おかえりなさい!\p"
	.string "{JPN}ピラミッドを せいはしましたね!\n"
	.string "{JPN}すばらしいです!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "{JPN}ちょっと もんだいがあります\p"
	.string "{JPN}ポケモンが どうぐを\n"
	.string "{JPN}mっているようですね\p"
	.string "{JPN}ざんねんですが ピラミッドで\n"
	.string "{JPN}てにいれた どうぐは\lもちかえれません$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "{JPN}ポケモンが もっている どうぐは\n"
	.string "{JPN}すべて {PLAYER}さんの\lバトルバッグに いどうします$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "{JPN}バトルバッグに すべての どうぐが\n"
	.string "{JPN}はいりません ざんねんです\p"
	.string "{JPN}バトルバッグと ポケモンに のこす\n"
	.string "{JPN}どうぐを えらんでください$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "{JPN}まだ ポケモンが どうぐを\n"
	.string "{JPN}もっているようですね$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "{JPN}バトルバッグと ポケモンに のこす\n"
	.string "{JPN}どうぐを えらんでください$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{JPN}{PLAYER}は ポケモンが もっていた\n"
	.string "{JPN}どうぐを すべて かえした!$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "{JPN}つかった バトルバッグは つぎの\n"
	.string "{JPN}ちょうせんのため おあずかりします\p"
	.string "{JPN}{PLAYER}は バトルバッグを わたし\n"
	.string "{JPN}バッグを うけとった!$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "{JPN}けっかを きろくしますので\n"
	.string "{JPN}しばらく おまちください$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "{JPN}バトルピラミッドを せいはした\n"
	.string "{JPN}きねんに これを どうぞ!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{JPN}{PLAYER}は しょうひんの\n"
	.string "{JPN}{STR_VAR_1}を もらった!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "{JPN}...ああ...\n"
	.string "{JPN}あなたの バッグは\l"
	.string "{JPN}いっぱいのようですね.\p"
	.string "{JPN}バッグの なかみを\nせいりしてから\lもどってきてください.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "{JPN}ざんねんでしたね...\p"
	.string "{JPN}おあずかりしていた\n"
	.string "{JPN}バッグを おかえしします.\p"
	.string "{JPN}{PLAYER}は バッグを\nうけとった!$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "{JPN}つぎの ちょうせんを\n"
	.string "{JPN}たのしみに しています!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "{JPN}あなたが くるのを\n"
	.string "{JPN}まっていました!\p"
	.string "{JPN}ピラミッドを せいはした\n"
	.string "{JPN}しょうひんです どうぞ!$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "{JPN}いらっしゃいませ...\p"
	.string "{JPN}ピラミッドで あなたを\n"
	.string "{JPN}まちうけている わざわいを\lおしえして さしあげましょう...$"
BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}あああ!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "{JPN}ひばなの あらしが みえます...\p"
	.string "{JPN}そのなかで あなたの ポケモンが\n"
	.string "{JPN}まひに くるしんでいる\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "{JPN}どくが みえます...\p"
	.string "{JPN}あなたの ポケモンが\n"
	.string "{JPN}どくの こうかに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "{JPN}あかく もえる ほのおが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nやけどに くるしんでいる\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "{JPN}むくわれない いかりの\n"
	.string "{JPN}きょうだいな あっぱくを\l"
	.string "{JPN}かんじます...\p"
	.string "{JPN}それは のろいです...\p"
	.string "{JPN}あなたの ポケモンが\n"
	.string "{JPN}パワーポイントを うしない\lあがくしか てだてが ない\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "{JPN}たかく そらに うかんだ\n"
	.string "{JPN}ポケモンが みえます...\p"
	.string "{JPN}あなたの ポケモンが\nじめんタイプの わざが\lきかずに こまっている\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "{JPN}あしもとから たちのぼる\n"
	.string "{JPN}きょうだいな エネルギーを\l"
	.string "{JPN}かんじます...\p"
	.string "{JPN}あなたの ポケモンが\nその ちからの とりこに\lなって にげられない\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "{JPN}こおりタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nこおりの こうかと\lたたかっている すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "{JPN}つかいてを きけんに さらす\n"
	.string "{JPN}わざの あらしが みえます...\p"
	.string "{JPN}あなたの ポケモンが\n"
	.string "{JPN}それらに たおれる\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "{JPN}エスパータイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nエスパーの わざに\lくるしめられている\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "{JPN}いわタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nいわの わざに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "{JPN}かくとうタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nかくとうの わざで\lなぐられている すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "{JPN}あまごい... にほんばれ...\n"
	.string "{JPN}すなあらし... あられ...\p"
	.string "{JPN}てんきで つよくなる\n"
	.string "{JPN}ポケモンが みえます...\p"
	.string "{JPN}あなたの ポケモンが\n"
	.string "{JPN}さまざまなタイプの わざに\lこんらんしている すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "{JPN}むしタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nさまざまな しゅるいの\lこうげきに くるしんでいる\lすがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "{JPN}あくタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nあくタイプの わざに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "{JPN}みずタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nみずタイプの わざに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "{JPN}ゴーストタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nゴーストタイプの わざに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "{JPN}はがねタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nきょうだいな いりょくの わざに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "{JPN}そらを とぶ ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nきょうだいな いりょくの わざに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "{JPN}いしの ちからで しんかした\n"
	.string "{JPN}ものたちが みえます...\p"
	.string "{JPN}ほのお みず でんきの\n"
	.string "{JPN}ちからも かんじます...\p"
	.string "{JPN}あなたの ポケモンが\n"
	.string "{JPN}その みっつの ちからに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "{JPN}ノーマルタイプの ポケモンが\n"
	.string "{JPN}みえます...\p"
	.string "{JPN}あなたの ポケモンが\nきょうだいな いりょくの わざに\lくるしんでいる すがたが みえます...$"
BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "{JPN}わたしの うらないを\n"
	.string "{JPN}しんじるか しんじないかは\l"
	.string "{JPN}あなたしだいです...\p"
	.string "{JPN}みらいは いつでも\nかえることが できます...\nごあんぜんを いのります...$"
BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "{JPN}しってましたか?\p"
	.string "{JPN}はやく はしると トレーナーに\n"
	.string "{JPN}きづかれて バトルを しかけられる\l"
	.string "{JPN}かもしれません.\p"
	.string "{JPN}トレーナーを さけたいなら\n"
	.string "{JPN}めを あわせずに そっと\lしずかに とおりすぎましょう.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "{JPN}うわあああああああ!\p"
	.string "{JPN}たくさん どうぐを もっていたのに\n"
	.string "{JPN}まけて ぜんぶ うしなっちゃった!\p"
	.string "{JPN}うわあああああああ!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "{JPN}おかえりなさい!\n"
	.string "{JPN}しんじられないことを やりましたね!\p"
	.string "{JPN}ピラミッドキングを たおして\n"
	.string "{JPN}バトルピラミッドを せいはした!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "{JPN}わかき たんけんか よ!\n"
	.string "{JPN}あなたの ゆうきを たたえ\l"
	.string "{JPN}バトルポイントを さしあげます!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "{JPN}バトルクエストの ルールが\nかかれています.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "{JPN}どの こうもくを よみますか?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "{JPN}ピラミッドを せいはすると\n"
	.string "{JPN}そこに でる やせいポケモンが\l"
	.string "{JPN}べつの しゅるいに かわります.\p"
	.string "{JPN}たんけんして かんさつして\n"
	.string "{JPN}どんな やせいポケモンに\lであえるか まなびましょう.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "{JPN}ピラミッドの なかには\n"
	.string "{JPN}トレーナーが まちぶせしています.\p"
	.string "{JPN}かくフロアに さいだい\n"
	.string "{JPN}8にんの トレーナーが います.\p"
	.string "{JPN}トレーナーを たおすと\n"
	.string "{JPN}たんけんに やくだつ ヒントが\lもらえます.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "{JPN}ピラミッドの めいろは\n"
	.string "{JPN}はいる たびに かわります.\p"
	.string "{JPN}めいろは くらく\n"
	.string "{JPN}ちゅういして すすまねばなりません.\p"
	.string "{JPN}やせいポケモンや トレーナーを\n"
	.string "{JPN}たおすと あかりが あかるくなります.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "{JPN}バトルバッグは ピラミッドないで\n"
	.string "{JPN}つかう バッグです.\p"
	.string "{JPN}バトルバッグは 2つ あります.\n"
	.string "{JPN}ノーマルレベルと ハードレベル\l"
	.string "{JPN}それぞれに ひとつずつです.\p"
	.string "{JPN}それぞれ 10しゅるいの どうぐを\n"
	.string "{JPN}99こまで いれられます.\p"
	.string "{JPN}たんけんに しっぱいすると\n"
	.string "{JPN}バトルバッグの なかみは\lうしなわれます.$"

