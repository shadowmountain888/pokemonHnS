PokemonLeague_WillsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_WillsRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

EliteFourRoom_OnLoad::
	call_if_eq VAR_TEMP_0, 1, EliteFourRoom_CreateDoor
	end

EliteFourRoom_CreateDoor::
	setmetatile 5, 11, 0x29D, TRUE
	setmetatile 6, 11, 0x29E, TRUE
	setmetatile 7, 11, 0x29F, TRUE
	setmetatile 5, 12, 0x2A5, TRUE
	setmetatile 6, 12, 0x2A6, TRUE
	setmetatile 7, 12, 0x2A7, TRUE
	return

PokemonLeague_WillsRoom_OnResume::
	setvar VAR_0x8004, 0
	special DoPokemonLeagueLightingEffect
	end

EliteFourRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, EliteFourRoom_CloseDoor
	.2byte 0

EliteFourRoom_CloseDoor::
	lock
	setflag FLAG_TEMP_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setmetatile 5, 11, 0x29D, TRUE
	setmetatile 6, 11, 0x29E, TRUE
	setmetatile 7, 11, 0x29F, TRUE
	setmetatile 5, 12, 0x2A5, TRUE
	setmetatile 6, 12, 0x2A6, TRUE
	setmetatile 7, 12, 0x2A7, TRUE
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_TEMP_0, 1
	release
	end

PokemonLeague_WillsRoom_EventScript_Will::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 2, PokemonLeague_WillsRoom_EventScript_WillDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_WillsRoom_EventScript_WillRematch
	msgbox PokemonLeague_WillsRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_WILL_1, PokemonLeague_WillsRoom_Text_Beaten
	goto PokemonLeague_WillsRoom_EventScript_WillOnDefeat

PokemonLeague_WillsRoom_EventScript_WillRematch::
	msgbox PokemonLeague_WillsRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_WILL_2, PokemonLeague_WillsRoom_Text_Beaten
	goto PokemonLeague_WillsRoom_EventScript_WillOnDefeat

PokemonLeague_WillsRoom_EventScript_WillOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_WillsRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 2
	release
	end

PokemonLeague_WillsRoom_EventScript_WillDefeated::
	msgbox PokemonLeague_WillsRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_WillsRoom_Text_Before:
    .string "{JPN}ポケモンリーグへようこそ \n"
	.string "{JPN}{PLAYER}.\p"
    .string "{JPN}じこしょうかいを\n"
	.string "{JPN}させてもらおう.\n"
    .string "{JPN}わたしは イツキだ.\p"
	.string "{JPN}せかいじゅうで しゅぎょうし \n"
    .string "{JPN}エスパータイプの\l"
	.string "{JPN}ポケモンを きたえあげた.\p"
    .string "{JPN}そして ついに\n"
	.string "{JPN}してんのうの いちいんと\l"
    .string "{JPN}なることが できた.\pこれからも つよくなり\nつづけるのみ!\pまけは ゆるされない!$"

PokemonLeague_WillsRoom_Text_Beaten:
    .string "{JPN}I... I can't... believe it...$"
PokemonLeague_WillsRoom_Text_Defeat:
    .string "{JPN}まけても わたしの\n"
	.string "{JPN}しんねんは かわらない.\p"
    .string "{JPN}すべての トレーナーの\n"
	.string "{JPN}ちょうてんに たつまで\l"
    .string "{JPN}たたかい つづけよう!\p"
	.string "{JPN}さあ {PLAYER} \n"
    .string "{JPN}さきへ すすんで\lしてんのうの しんの\lきょうぼうさを あじわえ!$"

PokemonLeague_WillsRoom_Text_RematchBefore:
    .string "{JPN}イツキ: おお \n"
	.string "{JPN}もどってきたな.\p"
    .string "{JPN}この であいを\n"
	.string "{JPN}よげんしていた.\p"
    .string "{JPN}わたしの エスパーポケモンと\n"
	.string "{JPN}わたしは しんかし \l"
    .string "{JPN}あたらしい せんじゅつを\l"
	.string "{JPN}みにつけた.\p"
    .string "{JPN}こうじょうした せんりゃくと\nちからの たたかいに\lそなえよ.\pきみの よちのうが\nわたしと どうかくらべて\lみようではないか.$"
