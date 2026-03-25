.set LOCALID_ATTENDANT, 1

FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	@opendoor 2, 1
	@waitdooranim
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	@closedoor 2, 1
	@waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "{JPN}よせんかいは まあまあ やれるん\n"
	.string "{JPN}だけど アピールで かてないのよ...\p"
	.string "{JPN}ほかの しゅつじょうしゃが なにを\n"
	.string "{JPN}やってるか みないと だめかな...$"
@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "{JPN}みて!\n"
	.string "{JPN}わたしの ポケモンが\n"
	.string "{JPN}こんなに リボンを かったの!\p"
	.string "{JPN}あなたの ポケモンは\nリボンを もらった?\nポケナビで かくにんできるよ$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "{JPN}ジムリーダーには かてないし...\p"
	.string "{JPN}コンテストも ぜんぜん だめ...\p"
	.string "{JPN}あっちこっち いろんなところに\n"
	.string "{JPN}いったけど ぜんぶ むだだった...$"
@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "{JPN}ポケモン コンテスト\n"
	.string "{JPN}スーパーランク ステージ!$"

