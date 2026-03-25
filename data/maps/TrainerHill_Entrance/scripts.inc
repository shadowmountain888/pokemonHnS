.set LOCALID_ATTENDANT, 1
.set LOCALID_NURSE, 2
.set LOCALID_GIRL, 4
.set LOCALID_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	clearflag FLAG_LIMIT_TO_50
	calculatemonstats
	setflag FLAG_TEMP_HIDE_FOLLOWER
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_NURSE
	addobject LOCALID_ATTENDANT
	addobject LOCALID_MAN
	addobject LOCALID_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end


TrainerHill_Entrance_EventScript_Man2::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed2
	msgbox TrainerHill_Entrance_Text_Money, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed2::
	msgbox TrainerHill_Entrance_Text_HereToGetMoney, MSGBOX_NPC
	end

TrainerHill_Entrance_Text_HereToGetMoney:
    .string "{JPN}おれは おかねを かせぎに\n"
	.string "{JPN}きたんだ!\n"
    .string "{JPN}なんでって? ここは てっぺんに\l"
	.string "{JPN}とうたつするたび しょうきんが\l"
    .string "{JPN}もらえるからな!\pいつ ひらくんだろう.\nまちきれないよ!$"

TrainerHill_Entrance_Text_Money:
    .string "{JPN}てっぺんに とうたつする たびに\n"
	.string "{JPN}おかねが もらえるよ.\p"
    .string "{JPN}10ぷんいないに ゴールすれば\n"
	.string "{JPN}1,000,000えんまで もらえるって\l"
    .string "{JPN}きいたことが あるよ!\p"
	.string "{JPN}でも それよりも おそいと\nほうしゅうは へっちゃうんだ...$"
TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	@goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

TrainerHill_Entrance_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

@TrainerHill_Entrance_EventScript_ExpandedPokemart::
@	pokemart TrainerHill_Entrance_Pokemart_Expanded
@	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
@	release
@	end
@
@	.align 2
@TrainerHill_Entrance_Pokemart_Expanded:
@	.2byte ITEM_X_SPEED
@	.2byte ITEM_X_SPECIAL
@	.2byte ITEM_X_ATTACK
@	.2byte ITEM_X_DEFEND
@	.2byte ITEM_DIRE_HIT
@	.2byte ITEM_GUARD_SPEC
@	.2byte ITEM_X_ACCURACY
@	.2byte ITEM_NONE
@	release
@	end

TrainerHill_Entrance_Text_StillGettingReady:
	.string "{JPN}ここは たくさんの トレーナーと\n"
	.string "{JPN}タッグバトルを たのしめる\l"
	.string "{JPN}トレーナーヒルです.\p"
	.string "{JPN}ざんねんながら まだ じゅんびちゅう\n"
	.string "{JPN}です. またあとで きてください!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "{JPN}いらっしゃいませ!\p"
	.string "{JPN}ここは たくさんの トレーナーと\n"
	.string "{JPN}タッグバトルを たのしめる\l"
	.string "{JPN}トレーナーヒルです!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "{JPN}はじめての おこしでしょうか?\p"
	.string "{JPN}はいる まえに セーブを\n"
	.string "{JPN}してくださいね.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "{JPN}えーっと...\n"
	.string "{JPN}いまここにいる トレーナーは...\p"
	.string "{JPN}{STR_VAR_1}かいまでだね.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "{JPN}えーっと...\n"
	.string "{JPN}いまここにいる トレーナーは...\p"
	.string "{JPN}どの へやにも トレーナーが\n"
	.string "{JPN}あつまって いるようだね.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "{JPN}まっている トレーナーたちに\n"
	.string "{JPN}ちょうせん しますか?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "{JPN}きみの しんこうを けいそく\n"
	.string "{JPN}するよ. がんばって!\p"
	.string "{JPN}よーい...\p"
	.string "{JPN}どん!$"
	.string ""

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "{JPN}また おこし くださいね!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "{JPN}ざんねんでしたね.\p"
	.string "{JPN}でも すばらしい たたかいぶりを\n"
	.string "{JPN}みせて いただきました.\p"
	.string "{JPN}また ちょうせんしに きてください!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "{JPN}がんばって くださいね.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "{JPN}トレーナーたちが いりかわるとき\n"
	.string "{JPN}うごきが はげしくなるんです.\p"
	.string "{JPN}あらしを さけるため うけつけを\n"
	.string "{JPN}ここに いどう させました.\p"
	.string "{JPN}ごめいわくを おかけします.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "{JPN}おつかれさまでした!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "{JPN}トレーナーヒルでは タイムアタックと\n"
	.string "{JPN}いう イベントを おこなっています.\p"
	.string "{JPN}ここから おくじょうの オーナーまで\n"
	.string "{JPN}どのくらい じかんが かかるかを\l"
	.string "{JPN}きそう きょうそうです.\p"
	.string "{JPN}さいこう きろくは タイムボードに\n"
	.string "{JPN}のります. ともだちと きそって\l"
	.string "{JPN}みてくださいね.\p"
	.string "{JPN}とちゅうの トレーナーせんでは\n"
	.string "{JPN}けいけんちも おかねも てにはいり\l"
	.string "{JPN}ません.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "{JPN}すみませんが ポケモンが\n"
	.string "{JPN}いっぴき しか いませんね.\p"
	.string "{JPN}この イベントに さんかするには\n"
	.string "{JPN}さいてい にひきの ポケモンが\lひつようです.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "{JPN}ほっほ! ほっほ!\p"
	.string "{JPN}ついに きたね!\n"
	.string "{JPN}そう  とうちゃく したんだ!\p"
	.string "{JPN}まて! いわなくても いい!\n"
	.string "{JPN}きみが ひとりで ここまで\l"
	.string "{JPN}きた りゆうは わかってる!\p"
	.string "{JPN}きみは わたしに あいたかった\n"
	.string "{JPN}んだ  トレーナーヒルの\l"
	.string "{JPN}オーナーで ある わたしに...\p"
	.string "{JPN}わたしと タッグチームを くみ\n"
	.string "{JPN}たかったんだろう!\n"
	.string "{JPN}ワッホー!\p"
	.string "{JPN}え?\n"
	.string "{JPN}ちがうって?\pまあ いいや  きみが のぼって\nくるのを みてたよ.\nすばらしい たたかいっぷり!\nブラボーだ!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "{JPN}すばらしい きみには すてきな\n"
	.string "{JPN}プレゼントと がんばったぶんの\l"
	.string "{JPN}しょうきんを あげよう!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "{JPN}おや これは いっぱいだね!\n"
	.string "{JPN}また あとで とりに きてくれ!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "{JPN}おや ちょっと まって! もしかして\n"
	.string "{JPN}すごく はやく ついたのかい?\p"
	.string "{JPN}それは すばらしい! そんなに\n"
	.string "{JPN}iそいで あいに こなくても\l"
	.string "{JPN}よかったのに!\p"
	.string "{JPN}とても うれしいよ. うけつけの\nタイムボードを こうしん させよう!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "{JPN}でも  あー...\n"
	.string "{JPN}ここまで くるのに じかんが\nかかり すぎたね.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "{JPN}こんどは もっと はやく きて\n"
	.string "{JPN}くれたら うれしいな.\p"
	.string "{JPN}そのときは きみと タッグチームを\n"
	.string "{JPN}くんで みたいものだ!\p"
	.string "{JPN}また あおう アミーゴ!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "{JPN}わたしが トレーナーヒルを つくった\n"
	.string "{JPN}りゆうは ひとつだけなんだ!\p"
	.string "{JPN}タッグチームを くめる さいてきな\n"
	.string "{JPN}パートナーを みつけるためにね!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{JPN}{STR_VAR_1}ふん {STR_VAR_2}.{STR_VAR_3}びょう$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "{JPN}どんな トレーナーや ポケモンの\n"
	.string "{JPN}くみあわせが まってるか\l"
	.string "{JPN}わからないけど\p"
	.string "{JPN}じゃまする やつは みんな\nけちらして やるぜ!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "{JPN}つよい トレーナーが せかいじゅうから\n"
	.string "{JPN}トレーナーヒルに あつまるって\l"
	.string "{JPN}きいたぜ!\p"
	.string "{JPN}はやく ためして みたいよ!\p"
	.string "{JPN}じゃまする やつは みんな\nなぎたおしてやる!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "{JPN}あそこの タイムボード みえる?\p"
	.string "{JPN}ともだちと だれが いちばん はやく\n"
	.string "{JPN}てっぺんに つけるか きそってるんだ.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "{JPN}いつ ひらくか しってる?\p"
	.string "{JPN}いちばん さいしょの ちょうせんしゃに\n"
	.string "{JPN}なるために まってるんだ!$"
	.string ""

TrainerHill_Elevator_Text_ReturnToReception:
	.string "{JPN}うけつけまで もどりますか?$"
	.string ""
