.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "{JPN}トレーナーの こころが\n"
	.string "{JPN}ためされる ばしょ.\p"
	.string "{JPN}バトルパレスへ\n"
	.string "{JPN}ようこそ.\p"
	.string "{JPN}シングルバトルホールの\nちょうせんを うけつけています.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "{JPN}シングルバトルホールに\n"
	.string "{JPN}ちょうせん しますか?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "{JPN}バトルパレスには\n"
	.string "{JPN}シングルバトルホールと\l"
	.string "{JPN}よばれる かいじょうが あります.\p"
	.string "{JPN}シングルバトルは つうじょうの\n"
	.string "{JPN}ルールで おこないますが\l"
	.string "{JPN}ひとつ だけ じゅうような ルールが.\p"
	.string "{JPN}トレーナーは ポケモンの\n"
	.string "{JPN}こうたいだけが きょかされます.\p"
	.string "{JPN}それいがいの しれいは\n"
	.string "{JPN}きんしされています.\p"
	.string "{JPN}ポケモンは じぶんの せいかくに\n"
	.string "{JPN}したがって ひとりで たたかいます.\p"
	.string "{JPN}ポケモンを しんじて\n"
	.string "{JPN}みまもって ください.\n"
	.string "{JPN}7にん れんしょう すれば\n"
	.string "{JPN}バトルポイントを さしあげます.\p"
	.string "{JPN}ちゅうだん するときは\n"
	.string "{JPN}セーブを してください.\p"
	.string "{JPN}セーブしないで ちゅうだんすると\n"
	.string "{JPN}しっかく となります.$"
	.string ""

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "{JPN}こころと ポケモンを\n"
	.string "{JPN}きたえなおしてから\lもどって きてください.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "{JPN}バトルホールは ノーマルと\n"
	.string "{JPN}ハードの 2つが あります.\l"
	.string "{JPN}どちらに ちょうせん しますか?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "{JPN}はあ...\p"
	.string "{JPN}ちょうせんに ひつような\n"
	.string "{JPN}3ひきの ポケモンが\l"
	.string "{JPN}いませんね.\p"
	.string "{JPN}さんかするには 3ひきの\n"
	.string "{JPN}ちがう しゅるいの ポケモンが\l"
	.string "{JPN}ひつようです.\p"
	.string "{JPN}おなじ しゅるいの どうぐを\n"
	.string "{JPN}もたせることも できません.\p"
	.string "{JPN}タマゴ{STR_VAR_1} しかく\nがありません.\pじゅんびが ととのったら\nもどってきてください.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "{JPN}はあ...\p"
	.string "{JPN}ちょうせんに ひつような\n"
	.string "{JPN}3ひきの ポケモンが\l"
	.string "{JPN}いませんね.\p"
	.string "{JPN}さんかするには 3ひきの\n"
	.string "{JPN}ちがう しゅるいの ポケモンが\l"
	.string "{JPN}ひつようです.\p"
	.string "{JPN}おなじ しゅるいの どうぐを\n"
	.string "{JPN}もたせることも できません.\p"
	.string "{JPN}タマゴ{STR_VAR_1} しかく\nがありません.\pじゅんびが ととのったら\nもどってきてください.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "{JPN}では 3ひきの ポケモンを\n"
	.string "{JPN}えらんで ください.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "{JPN}バトルホールへ あんないする\n"
	.string "{JPN}まえに セーブします.\lよろしいですか?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "{JPN}では\n"
	.string "{JPN}ついて きてください.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "{JPN}あなたの ポケモンの\n"
	.string "{JPN}かつやくを みられて\l"
	.string "{JPN}こうえい でした.\p"
	.string "{JPN}けっかを きろく します.\nしばらく おまち ください.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "{JPN}7れんしょうを たっせい\n"
	.string "{JPN}するためには...\p"
	.string "{JPN}あなたと ポケモンの\nこころの きずなが\lかたく まことのもので\lあるように みえます.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "{JPN}あなたの かつやくを\n"
	.string "{JPN}きろく します.\lしばらく おまち ください.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "{JPN}7れんしょうの かつやくに\n"
	.string "{JPN}バトルポイントを\lさしあげます.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "{JPN}しょうひんを いれる すきまが\n"
	.string "{JPN}ないようですね.\p"
	.string "{JPN}バッグを せいり してから\n"
	.string "{JPN}もどって きてください.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "{JPN}あなたを おまちして\nおりました...$"
BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "{JPN}バトルホールへ あんないする\n"
	.string "{JPN}まえに セーブします.\lよろしいですか?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "{JPN}はあ...\p"
	.string "{JPN}まえかい ちょうせんを おわらせる\n"
	.string "{JPN}まえに セーブを わすれて\l"
	.string "{JPN}しまったようですね.\p"
	.string "{JPN}その けっか ちょうせんは\nしっかく となりました.\lざんねんなことです.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{JPN}{PLAYER}は しょうひん\n"
	.string "{JPN}{STR_VAR_1}を もらった!$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "{JPN}おれみたいな つよい やつには\n"
	.string "{JPN}つよい ポケモンが いちばんだ!\p"
	.string "{JPN}こうげきこそ さいだいの ぼうぎょ!\n"
	.string "{JPN}むてきの こうげきが さいきょうだ!\p"
	.string "{JPN}でも それが いいたかった\n"
	.string "{JPN}わけじゃない.\p"
	.string "{JPN}ときどき すごく かわいい じょせいが\n"
	.string "{JPN}ここに やってくるんだ.\p"
	.string "{JPN}ポケモンの かんがえてることが\n"
	.string "{JPN}わかるって いうんだ.\p"
	.string "{JPN}それは よく わからんが\n"
	.string "{JPN}ほんとに かわいいんだ.\p"
	.string "{JPN}あれ?\n"
	.string "{JPN}なんで そんなふうに みるんだ?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "{JPN}うむ...\p"
	.string "{JPN}ポケモンの せいかくと\n"
	.string "{JPN}おぼえている わざが\l"
	.string "{JPN}ここでの たたかいの\l"
	.string "{JPN}かぎのようですね.\p"
	.string "{JPN}より せいかくに いうと\n"
	.string "{JPN}わざが ポケモンの せいかくに\l"
	.string "{JPN}どれだけ あっているかです.\p"
	.string "{JPN}ポケモンが こまっていて\n"
	.string "{JPN}もてる ちからを はっきできない\l"
	.string "{JPN}ばあいは わざが せいかくに\lあっているか しらべてみると\lよいでしょう.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "{JPN}うちの ポケモンは\n"
	.string "{JPN}ふだんは とても おとなしいの.\p"
	.string "{JPN}でも バトルホールに はいると\n"
	.string "{JPN}ときどき あくまに\l"
	.string "{JPN}へんしんしたみたいに なるのよ!\p"
	.string "{JPN}すっごく いかく してくるの.\nほんとに びっくりしちゃう.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "{JPN}あいてを よわらせて\n"
	.string "{JPN}じわじわと せめる せいかくの\l"
	.string "{JPN}ポケモンって どんなだろう.\p"
	.string "{JPN}なまけものの せいかくだったら\n"
	.string "{JPN}おどろくなあ.\pでも まさか そんなわけ ないか.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "{JPN}トレーナーの こころが\n"
	.string "{JPN}ためされる ばしょ.\p"
	.string "{JPN}バトルパレスへ\n"
	.string "{JPN}ようこそ.\p"
	.string "{JPN}ダブルバトルホールの\nちょうせんを うけつけています.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "{JPN}ダブルバトルホールに\n"
	.string "{JPN}ちょうせん しますか?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "{JPN}バトルパレスには\n"
	.string "{JPN}ダブルバトルホールと\l"
	.string "{JPN}よばれる かいじょうが あります.\p"
	.string "{JPN}ダブルバトルは つうじょうの\n"
	.string "{JPN}ルールで おこないますが\l"
	.string "{JPN}ひとつ だけ じゅうような ルールが.\p"
	.string "{JPN}トレーナーは ポケモンの\n"
	.string "{JPN}こうたいだけが きょかされます.\p"
	.string "{JPN}それいがいの しれいは\n"
	.string "{JPN}きんしされています.\p"
	.string "{JPN}ポケモンは じぶんの せいかくに\n"
	.string "{JPN}したがって ひとりで たたかいます.\p"
	.string "{JPN}ポケモンを しんじて\n"
	.string "{JPN}みまもって ください.\n"
	.string "{JPN}7にん れんしょう すれば\n"
	.string "{JPN}バトルポイントを さしあげます.\p"
	.string "{JPN}ちゅうだん するときは\n"
	.string "{JPN}セーブを してください.\p"
	.string "{JPN}セーブしないで ちゅうだんすると\n"
	.string "{JPN}しっかく となります.$"
	.string ""

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "{JPN}パレスガーディアンと\n"
	.string "{JPN}7にんの トレーナーを\lれんぞくで たおすには...$"
BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "{JPN}あなたと ポケモンの きずなに\n"
	.string "{JPN}けいいを ひょうして\l"
	.string "{JPN}バトルポイントを さしあげます.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "{JPN}さいしんの バトルパレスでの\n"
	.string "{JPN}たたかいを フロンティアパスに\l"
	.string "{JPN}きろく しますか?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "{JPN}バトルホールの ルールです.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "{JPN}どの こうもくを\nよみますか?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "{JPN}ここでは ポケモンが じぶんで\n"
	.string "{JPN}かんがえて たたかいます.\p"
	.string "{JPN}やせいとは ちがい ひととの\n"
	.string "{JPN}せいかつで ポケモンの こうどうは\l"
	.string "{JPN}せいかくによって かわります.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "{JPN}せいかくによって ポケモンは\n"
	.string "{JPN}なにがあっても こうげきを\l"
	.string "{JPN}このむことがあります.\p"
	.string "{JPN}べつのポケモンは じぶんを\n"
	.string "{JPN}あらゆるがいから まもることを\l"
	.string "{JPN}このむかもしれません.\p"
	.string "{JPN}また べつのポケモンは てきを\n"
	.string "{JPN}なやませたり こんらんさせたり\l"
	.string "{JPN}するのをたのしむかもしれません.\p"
	.string "{JPN}せいかくのため ポケモンには\n"
	.string "{JPN}とくいで つかいやすい\lおきにいりのわざがあります.\pまた にがてで つかいにくい\nわざもあるかもしれません.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "{JPN}てきに ちょくせつダメージを\n"
	.string "{JPN}あたえる こうげきてきなわざが\l"
	.string "{JPN}あります.\p"
	.string "{JPN}てきのこうげきにそなえたり\n"
	.string "{JPN}HPをかいふくしたりする\l"
	.string "{JPN}ぼうぎょてきなわざがあります.\p"
	.string "{JPN}そのほか どくや まひなどの\n"
	.string "{JPN}じょうたいいじょうで てきを\l"
	.string "{JPN}よわらせる すこしかわった\l"
	.string "{JPN}わざもあります.\p"
	.string "{JPN}ポケモンは これら3つの\nしゅるいのわざを つかうことを\lかんがえます.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "{JPN}トレーナーのしれいがないとき\n"
	.string "{JPN}ポケモンは とくていのわざを\l"
	.string "{JPN}こうりつてきに つかえない\l"
	.string "{JPN}ことがあります.\p"
	.string "{JPN}ポケモンは きらいなわざを\n"
	.string "{JPN}じょうずに つかうことが\l"
	.string "{JPN}できません.\p"
	.string "{JPN}もし ポケモンが じぶんの\nせいかくにあわないわざしか\lしらないばあい しばしば\lほんらいのちからを はっきできず\lにいることがあります.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "{JPN}せいかくによって ポケモンは\n"
	.string "{JPN}ピンチのとき じぶんのせいかくに\l"
	.string "{JPN}あわないわざを つかいはじめる\l"
	.string "{JPN}ことがあります.\p"
	.string "{JPN}もし ポケモンが ピンチで\nおかしなこうどうを はじめたら\lちゅういぶかく みてください.$"

