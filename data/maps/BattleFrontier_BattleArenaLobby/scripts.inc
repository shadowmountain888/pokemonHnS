.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "{JPN}トレーナーたちの たたかう\n"
	.string "{JPN}きもちが ためされる ばしょ!\p"
	.string "{JPN}バトルアリーナへ ようこそ!\p"
	.string "{JPN}わたしは セットKOトーナメントの\nあんないやくです!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "{JPN}それでは バトルアリーナの\n"
	.string "{JPN}チャレンジを おうけしますか?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "{JPN}またの ちょうせんを\n"
	.string "{JPN}おまちしております!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "{JPN}バトルアリーナでは セットKO\n"
	.string "{JPN}トーナメントを おこないます\p"
	.string "{JPN}3ひきの ポケモンで チームを\n"
	.string "{JPN}くんで さんかしていただきます\p"
	.string "{JPN}3ひきの ポケモンは でてくる\n"
	.string "{JPN}じゅんばんに ならべてください\p"
	.string "{JPN}バトルちゅうは よてい された\n"
	.string "{JPN}じゅんばんで 1ぴきずつ でてきます\p"
	.string "{JPN}バトルに でた ポケモンは\n"
	.string "{JPN}しょうぶが きまるまで たたかいます\p"
	.string "{JPN}3ターンで しょうぶが つかなければ\n"
	.string "{JPN}はんてい しょうぶと なります\p"
	.string "{JPN}チャレンジを ちゅうだん したいときは\n"
	.string "{JPN}セーブを おねがいします\p"
	.string "{JPN}セーブしないと チャレンジを\n"
	.string "{JPN}つづけることが できません\p"
	.string "{JPN}7にんの トレーナーに れんしょう\n"
	.string "{JPN}できれば バトルポイントを\l"
	.string "{JPN}プレゼントいたします$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "{JPN}バトルアリーナへ ごあんないする\n"
	.string "{JPN}まえに セーブします よろしいですか?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "{JPN}バトルアリーナには ノーマルと\n"
	.string "{JPN}ハード 2つの なんいどがあります\l"
	.string "{JPN}どちらを えらびますか?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "{JPN}では 3ひきの ポケモンを\n"
	.string "{JPN}えらんでください$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "{JPN}チャレンジャーさま!\p"
	.string "{JPN}さんかに ひつような 3ひきの\n"
	.string "{JPN}ポケモンが いませんね\p"
	.string "{JPN}さんかするには ちがう しゅるいの\n"
	.string "{JPN}ポケモン 3ひきが ひつようです\p"
	.string "{JPN}また おなじ しゅるいの アイテムを\n"
	.string "{JPN}もたせることは できません\p"
	.string "{JPN}タマゴ{STR_VAR_1} さんか できません\p"
	.string "{JPN}じゅんびが できましたら\n"
	.string "{JPN}ぜひ もどってきてくださいね$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "{JPN}チャレンジャーさま!\p"
	.string "{JPN}さんかに ひつような 3ひきの\n"
	.string "{JPN}ポケモンが いませんね\p"
	.string "{JPN}さんかするには ちがう しゅるいの\n"
	.string "{JPN}ポケモン 3ひきが ひつようです\p"
	.string "{JPN}また おなじ しゅるいの アイテムを\n"
	.string "{JPN}もたせることは できません\p"
	.string "{JPN}タマゴ{STR_VAR_1} さんか できません\p"
	.string "{JPN}じゅんびが できましたら\n"
	.string "{JPN}ぜひ もどってきてくださいね$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "{JPN}それでは バトルアリーナへ\n"
	.string "{JPN}ごあんないいたします$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "{JPN}チャレンジャーさま!\p"
	.string "{JPN}でんげんを きるまえに セーブを\n"
	.string "{JPN}しませんでしたね?\p"
	.string "{JPN}ざんねんですが しっかくと\n"
	.string "{JPN}なってしまいました\p"
	.string "{JPN}もちろん あらたな チャレンジは\n"
	.string "{JPN}かのうですよ$"
	.string ""

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "{JPN}7にんの トレーナーに れんしょう\n"
	.string "{JPN}おめでとうございます!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "{JPN}きろくを のこします\n"
	.string "{JPN}セーブちゅうですので おまちください$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "{JPN}7れんしょうの きねんに\n"
	.string "{JPN}こちらを さしあげます$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{JPN}{PLAYER}は しょうひん\n"
	.string "{JPN}{STR_VAR_1}を もらった!$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "{JPN}あら?\n"
	.string "{JPN}バッグが いっぱいのようですね\p"
	.string "{JPN}ばしょを あけて また\n"
	.string "{JPN}とりに きてくださいね$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "{JPN}さんか ありがとうございました!\p"
	.string "{JPN}セーブちゅうですので おまちください$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "{JPN}またの ちょうせんを\n"
	.string "{JPN}おまちしております!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "{JPN}おまちしておりました\p"
	.string "{JPN}バトルアリーナへ ごあんないする\n"
	.string "{JPN}まえに セーブいたします\l"
	.string "{JPN}おまちください$"
	.string ""

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "{JPN}さきほどの バトルアリーナでの\n"
	.string "{JPN}たたかいを フロンティアパスに\lきろくしますか?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "{JPN}しんぱんの はんていで まけた...\p"
	.string "{JPN}ぼうぎょわざ ばかりで\n"
	.string "{JPN}こうげき しないのは よくなかったな...$"
BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "{JPN}はんていで かった!\p"
	.string "{JPN}あいての ポケモンに こうげきを\n"
	.string "{JPN}あてつづけるのが こうかてきだった!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "{JPN}ひきわけ はんていでした\p"
	.string "{JPN}じかんぎれの とき わたしの\n"
	.string "{JPN}ポケモンも あいても どうじぐらいの\l"
	.string "{JPN}HPが のこってたからね$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "{JPN}バトルアリーナでは ポケモンの\n"
	.string "{JPN}じゅんばんが とても だいじだよ\p"
	.string "{JPN}たとえば さいしょの ポケモンが\n"
	.string "{JPN}タイプで ふりなら\l"
	.string "{JPN}2ひきめは 1ひきめに こうかばつぐんの\n"
	.string "{JPN}わざを おぼえさせるといいよ\l"
	.string "{JPN}それで こうりつてきな チームが\n"
	.string "{JPN}つくれると おもうよ$"
	.string ""

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "{JPN}セットKOトーナメントの\nルールが かいてあります$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "{JPN}どの こうもくを よみますか?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "{JPN}セット KO トーナメントは\n"
	.string "{JPN}つうじょうの たたかいとは\l"
	.string "{JPN}ちがう とくべつな ルールが\l"
	.string "{JPN}あります.\p"
	.string "{JPN}まず ひとつの たたかいは\n"
	.string "{JPN}3ターンで おわります.\p"
	.string "{JPN}3ターン たっても しょうぶが\n"
	.string "{JPN}つかない ばあいは\l"
	.string "{JPN}しんぱんに なります.\n"
	.string "{JPN}しんぱんは ポケモンの\nたたかいぶりを みて\lしょうしゃを きめます.\pまた ポケモンは たたかいの\nけっかが きまるまで\lこうたい できません.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "{JPN}ひとつめの しんぱん ようそは\n"
	.string "{JPN}マインドです.\l"
	.string "{JPN}この ようそは たたかいで\l"
	.string "{JPN}どれだけ せっきょくてきだったかを\l"
	.string "{JPN}ひょうかします.\p"
	.string "{JPN}トレーナーが こうげきわざを\nどれだけ つかったかで\lはんだん されます.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "{JPN}ふたつめの しんぱん ようそは\n"
	.string "{JPN}スキルです.\l"
	.string "{JPN}この ようそは ポケモンの わざを\l"
	.string "{JPN}どれだけ こうかてきに つかったかを\l"
	.string "{JPN}ひょうか します.\p"
	.string "{JPN}わざが せいこう すれば\n"
	.string "{JPN}スキル レーティングが あがります.\p"
	.string "{JPN}わざが しっぱい すれば\n"
	.string "{JPN}スキル レーティングが\l"
	.string "{JPN}さがります.\p"
	.string "{JPN}こうげきわざの ばあい\n"
	.string "{JPN}こうかは ばつぐんだなら\l"
	.string "{JPN}スキル レーティングが あがり\n"
	.string "{JPN}こうかは いまひとつだなら\l"
	.string "{JPN}さがります.\n"
	.string "{JPN}まもる や みきり などの\n"
	.string "{JPN}わざでは スキル レーティングは\lあがりません.\pあいてが まもる や みきりを\nつかって じぶんの ポケモンの\lわざが あたらなかった ばあい\nスキル レーティングは\lさがりません.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "{JPN}みっつめの しんぱん ようそは\n"
	.string "{JPN}ボディです.\l"
	.string "{JPN}この ようそは たたかい しゅうりょうじに\l"
	.string "{JPN}どれだけ HP が のこっていたかに\l"
	.string "{JPN}もとづいて きまります.\p"
	.string "{JPN}レーティングは ポケモンが\nたたかい かいしじに もっていた\lHP と しゅうりょうじに のこった\lHP を こうりょ します.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "{JPN}バトルアリーナの アリーナタイクーンから\n"
	.string "{JPN}しょうりを うばいとり\l"
	.string "{JPN}7にん ぬきの だいせいか!\p"
	.string "{JPN}あなたの すばらしい ちょうせんを\nおめでとう ございます!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "{JPN}すばらしい ちょうせんしゃよ\n"
	.string "{JPN}あなたの ふくつの せいしんに\l"
	.string "{JPN}けいいを ひょうして\lこの バトルポイントを\lうけとって ください.$"
