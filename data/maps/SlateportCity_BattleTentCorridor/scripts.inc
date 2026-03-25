.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_ATTENDANT, 2, 2
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	@opendoor 2, 1
	@waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	@closedoor 2, 1
	@waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "{JPN}コンテストに かんする\n"
	.string "{JPN}おいしい アドバイスが ほしい?\p"
	.string "{JPN}とくてい の わざの あとに\n"
	.string "{JPN}べつの しゅるい の わざを つかうと\l"
	.string "{JPN}とくべつな ちゅうもく を ひく\l"
	.string "{JPN}ことが あるんだ.\p"
	.string "{JPN}なに を してるか わかってれば\n"
	.string "{JPN}アピールで おおきく とくてんを\l"
	.string "{JPN}とれるよ.\pもちろん あいても きみの\nポケモンの パフォーマンスを\lじゃま してくるかも しれないけどね.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "{JPN}わたしの パパは コンテストの\n"
	.string "{JPN}しんぱんいんなの.\p"
	.string "{JPN}おとなに なったら しんぱんいんに\nなるか ジムリーダーに なるか\lまよっちゃう.$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "{JPN}よお おれ すっげー むかついてるんだ\n"
	.string "{JPN}よお. なんで おれの ポケモンが\l"
	.string "{JPN}かてないのか しりたかっただけ\l"
	.string "{JPN}なんだけどよお.\p"
	.string "{JPN}それでよお しんぱんに ぶんくを\n"
	.string "{JPN}いってやったのよ ただで な.\p"
	.string "{JPN}そしたら はなしも きいて くれ\n"
	.string "{JPN}ないんだぜ! ちょー むかつくー!\p"
	.string "{JPN}よお あんた! だまってろよな!\n"
	.string "{JPN}これ もってけよ!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "{JPN}それは わざマシン41だぜ.\n"
	.string "{JPN}いじめる だよ きいてるか?\p"
	.string "{JPN}あいてが おなじ わざを 2かい\n"
	.string "{JPN}つづけて つかえなく するんだ.\p"
	.string "{JPN}おい きけよ おれは あんたを\n"
	.string "{JPN}いじめてるん じゃないからな!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "{JPN}エムシー: おや おや!\n"
	.string "{JPN}なんて すばらしい ポケモンでしょう!\p"
	.string "{JPN}どうぞ! こちらに きて\n"
	.string "{JPN}わたしたちの すてきな コンテストに\l"
	.string "{JPN}さんか してください!\p"
	.string "{JPN}きっと うまくいきますよ!\nわたしの めに まちがいは ありません!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "{JPN}しんぱんいん: こんにちは!\n"
	.string "{JPN}トレーナーさん ですね!\p"
	.string "{JPN}それでは ポケモン コンテストを\n"
	.string "{JPN}みのがす わけには いきませんね!\p"
	.string "{JPN}トウカシティで コンテストパスを\n"
	.string "{JPN}もらって いつでも さんか\lしてくださいね!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "{JPN}アピールタイム だ!\n"
	.string "{JPN}なにから はじめよう かな?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "{JPN}みんな わたしの ポケモンの\n"
	.string "{JPN}アピールに ちゅうもく して\l"
	.string "{JPN}くれなかった...\p"
	.string "{JPN}ふん あの しんさいんは いい\nものを みても わからないのよ$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "{JPN}あ こんにちは! こんなに\n"
	.string "{JPN}ちかくまで きて みるなんて\l"
	.string "{JPN}ねっしんな ファンね.\p"
	.string "{JPN}あなたの ねつい に こたえて\n"
	.string "{JPN}けんじゃの アドバイスを\l"
	.string "{JPN}おしえて あげましょう.\p"
	.string "{JPN}わざが とても うけると\n"
	.string "{JPN}かんきゃくが こうふん するの.\n"
	.string "{JPN}そのとき アピールする\n"
	.string "{JPN}ポケモンは...\pきっと いいことが\nおこるはずよ!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "{JPN}だめだ! わたし ポケモンより\n"
	.string "{JPN}きんちょう してる.\p"
	.string "{JPN}ふるえて どきどき してる!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "{JPN}バトルと コンテストは おなじでは\n"
	.string "{JPN}ないけど にている ところも あるね.\n"
	.string "{JPN}がんばって そだてた ポケモンを\n"
	.string "{JPN}しんじる ことが ひつようだ.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "{JPN}そのポケモン ちょうしが よさそう\n"
	.string "{JPN}だね?\n"
	.string "{JPN}ふくしんさで よい せいせき の\n"
	.string "{JPN}ポケモンは アピールの ときも\l"
	.string "{JPN}リラックス してる みたいだ.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "{JPN}あの ざまを みて くれよ?\n"
	.string "{JPN}へっ おれの ポケモンの ほうが\n"
	.string "{JPN}ぜったいに あの れんちゅうより\lうえだぜ!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "{JPN}ポケモンが げんきいっぱいに\n"
	.string "{JPN}アピール してたら いっしょに\l"
	.string "{JPN}うごきたく ならない?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "{JPN}ポケモン コンテスト\n"
	.string "{JPN}ハイパーランク ステージ!$"

