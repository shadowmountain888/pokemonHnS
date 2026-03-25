Route110_SeasideCyclingRoadNorthEntrance_MapScripts::
	.byte 0

Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter:
	walk_left
	step_end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_ClearCyclingRoad::
	lockall
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad:
	.string "{JPN}サイクリングロードでは おもいっきり\n"
	.string "{JPN}こいで すきなだけ はやく\l"
	.string "{JPN}はしれるんだ.\p"
	.string "{JPN}そのスピードは きもちいいけど\nだれかに ぶつからないよう\lきをつけてね!$"

Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk:
	.string "{JPN}すみません サイクリングロードは\n"
	.string "{JPN}あるいちゃ だめなんです.\l"
	.string "{JPN}あぶないですからね.\pじてんしゃを もって\nきてください.$"

