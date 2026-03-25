.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "{JPN}トレーナーの ちえを ためす\n"
	.string "{JPN}ばしょ!\p"
	.string "{JPN}バトルファクトリーに\n"
	.string "{JPN}ようこそ!\p"
	.string "{JPN}わたしは バトルスワップ\nシングルトーナメントの\nガイドです$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "{JPN}バトルスワップ シングル\n"
	.string "{JPN}チャレンジに ちょうせん\nしますか?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "{JPN}バトルスワップ シングル\n"
	.string "{JPN}トーナメントは レンタルポケモン\l"
	.string "{JPN}のみを つかった シングルバトル\l"
	.string "{JPN}きょうぎです\p"
	.string "{JPN}まず このイベント せんよう\n"
	.string "{JPN}に みっぴきの ポケモンを\n"
	.string "{JPN}おかしします\p"
	.string "{JPN}ていきょうされた レンタル\n"
	.string "{JPN}ポケモンを つかって シングル\n"
	.string "{JPN}バトルを おこないます\p"
	.string "{JPN}かったら レンタルポケモンの\n"
	.string "{JPN}うち いっぴきを こうかん\n"
	.string "{JPN}することが できます\p"
	.string "{JPN}この バトルと こうかんを\n"
	.string "{JPN}くりかえし 7かい れんしょう\l"
	.string "{JPN}すると バトルポイントが\lもらえます\pチャレンジを ちゅうだん\nしたいときは ゲームを\nセーブして ください\pセーブしないと しっかく\nしてしまいます$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "{JPN}つぎの おこしを\nおまちしております$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "{JPN}どちらの レベルに ちょうせん\n"
	.string "{JPN}しますか?\nノーマル それとも ハード?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "{JPN}チャレンジを はじめる まえに\n"
	.string "{JPN}ゲームを セーブします\nよろしいですか?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "{JPN}では あなたの ポケモンは\n"
	.string "{JPN}きょうぎちゅう あずからせて\niただきます$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "{JPN}こちらへ どうぞ$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "{JPN}おつかれさまでした!\p"
	.string "{JPN}あなたの ポケモンを\n"
	.string "{JPN}レンタルポケモンと こうかん\n"
	.string "{JPN}して おかえしします\p"
	.string "{JPN}イベントけっかを セーブ\nしますので おまちください$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "{JPN}あなたの ポケモンを\n"
	.string "{JPN}レンタルポケモンと こうかん\nして おかえしします$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "{JPN}おめでとうございます!\n"
	.string "{JPN}バトルスワップで 7かい\nれんしょうです!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "{JPN}7かい れんしょうの しょうとして\n"
	.string "{JPN}バトルポイントを さしあげます$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "{JPN}おおっと!\p"
	.string "{JPN}バトルポイントが\n"
	.string "{JPN}マックスですね\p"
	.string "{JPN}バトルポイントを つかってから\nまた きてください$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "{JPN}おまちしてました!\p"
	.string "{JPN}チャレンジを さいかいする\n"
	.string "{JPN}まえに ゲームを セーブ\nします$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "{JPN}もうしわけありませんが\n"
	.string "{JPN}ぜんかい やめるときに\n"
	.string "{JPN}セーブしていませんでした\p"
	.string "{JPN}そのため チャレンジから\nしっかく となりました$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "{JPN}あなたの ポケモンを\nおかえしします$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{JPN}{PLAYER}は しょうひんの\n"
	.string "{JPN}{STR_VAR_1}を もらった!$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "{JPN}トレーナーの ちえを ためす\n"
	.string "{JPN}ばしょ!\p"
	.string "{JPN}バトルファクトリーに\n"
	.string "{JPN}ようこそ!\p"
	.string "{JPN}わたしは バトルスワップ\nダブルトーナメントの\nガイドです$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "{JPN}バトルスワップ ダブル\n"
	.string "{JPN}チャレンジに ちょうせん\nしますか?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "{JPN}バトルスワップ ダブル\n"
	.string "{JPN}トーナメントは レンタルポケモン\l"
	.string "{JPN}のみを つかった ダブルバトル\l"
	.string "{JPN}きょうぎです\p"
	.string "{JPN}まず このイベント せんよう\n"
	.string "{JPN}に みっぴきの ポケモンを\n"
	.string "{JPN}おかしします\p"
	.string "{JPN}ていきょうされた レンタル\n"
	.string "{JPN}ポケモンを つかって ダブル\n"
	.string "{JPN}バトルを おこないます\p"
	.string "{JPN}かったら レンタルポケモンの\n"
	.string "{JPN}うち いっぴきを こうかん\n"
	.string "{JPN}することが できます\p"
	.string "{JPN}この バトルと こうかんを\n"
	.string "{JPN}くりかえし 7かい れんしょう\l"
	.string "{JPN}すると バトルポイントが\lもらえます\pチャレンジを ちゅうだん\nしたいときは ゲームを\nセーブして ください\pちゅうだんまえに セーブ\nしないと しっかく\nしてしまいます$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "{JPN}ファクトリーヘッドに かって\n"
	.string "{JPN}7かい れんしょう\n"
	.string "{JPN}おめでとうございます!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "{JPN}ゆたかな ちしきと するどい\n"
	.string "{JPN}ちせいの しょうとして\l"
	.string "{JPN}バトルポイントを さしあげます$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "{JPN}あなたの ポケモンと\n"
	.string "{JPN}レンタルポケモンを\n"
	.string "{JPN}こうかんします\p"
	.string "{JPN}バトルデータを セーブ\nしますので おまちください$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "{JPN}さいごの バトルファクトリーの\n"
	.string "{JPN}たたかいを フロンティアパスに\l"
	.string "{JPN}きろくしますか?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "{JPN}やあ!\n"
	.string "{JPN}きみ!\p"
	.string "{JPN}そだてた ポケモンチームが\n"
	.string "{JPN}いらないから ここの イベント\l"
	.string "{JPN}は かんたんだと おもってる?\p"
	.string "{JPN}そんなに かんたんに\n"
	.string "{JPN}かてると おもわない ほうが\n"
	.string "{JPN}iいよ\p"
	.string "{JPN}ポケモンや わざの ちしきが\n"
	.string "{JPN}しっかりしてないと れんしょう\lしつづけるのは むずかしいよ$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "{JPN}I swapped for a weak POKéMON...\n"
	.string "{JPN}I thought it was a good kind to have...\p"
	.string "{JPN}They wiped the floor with us...$"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "{JPN}さいきん ぜんぜん\n"
	.string "{JPN}うまくいかないなあ.\p"
	.string "{JPN}あいての ポケモンが つよいか\n"
	.string "{JPN}どうか バトルちゅうに\l"
	.string "{JPN}ちゃんと みきわめないとね.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "{JPN}スタッフが つぎの あいてに\n"
	.string "{JPN}ついて ヒントを くれるでしょ?\p"
	.string "{JPN}おとなの おとこなのに\n"
	.string "{JPN}そのヒントが よくわからないんだ.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "{JPN}おれは つよいけど すぐに\n"
	.string "{JPN}あきちゃうから こうたいして\l"
	.string "{JPN}バトルを くりかえしてたんだ.\p"
	.string "{JPN}バトルこうたいに なんども\n"
	.string "{JPN}さんかしてたら レンタルポケモン\l"
	.string "{JPN}のしゅるいが かわってるのに きづいた.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "{JPN}バトルこうたいの ルールが\nかいてあるよ.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "{JPN}どの こうもくを よみますか?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "{JPN}バトルこうたいでは 3ひきの\n"
	.string "{JPN}ポケモンしか つかえません.\p"
	.string "{JPN}レンタルでも こうたいでも\n"
	.string "{JPN}おなじ ポケモンを 2ひき いじょう\l"
	.string "{JPN}チームに いれることは できません.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "{JPN}ポケモンを こうたいできるのは\n"
	.string "{JPN}たおした トレーナーとだけです.\p"
	.string "{JPN}こうたいできるのは たおした\n"
	.string "{JPN}トレーナーが つかっていた\lポケモンのみです.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "{JPN}バトルに かつたびに あいての\n"
	.string "{JPN}ポケモンを 1ひき こうたい\l"
	.string "{JPN}できます.\p"
	.string "{JPN}7にんめの トレーナーとは\n"
	.string "{JPN}ポケモンを こうたい\lできません.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "{JPN}ポケモンを こうたいするときの\n"
	.string "{JPN}ちゅういてんが 2つ あります.\p"
	.string "{JPN}まず こうたいするとき\n"
	.string "{JPN}もらう ポケモンの のうりょくを\l"
	.string "{JPN}かくにん できません.\p"
	.string "{JPN}つぎに チームの ポケモンは\n"
	.string "{JPN}レンタルした じゅんばんで\l"
	.string "{JPN}ならんでいます.\p"
	.string "{JPN}この じゅんばんは こうたいしても\n"
	.string "{JPN}かわりません.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "{JPN}ハードレベルでは レンタルポケモンも\n"
	.string "{JPN}あいての トレーナーの ポケモンも\l"
	.string "{JPN}すべて レベル50です.$"
