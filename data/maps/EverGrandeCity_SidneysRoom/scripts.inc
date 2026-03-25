EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_GARBAGEFLAG
	end

EverGrandeCity_SidneysRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_WILL, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_WILL, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_SIDNEY_REMATCH, EverGrandeCity_SidneysRoom_EventScript_SidneyRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_SidneyRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LUCY_BF_BRAIN, EverGrandeCity_SidneysRoom_Text_Defeat2
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_WILL
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech:
	.string "{JPN}ようこそ ちょうせんしゃ!\n"
	.string "{JPN}おれは してんのう の\l"
	.string "{JPN}カゲツだ!\p"
	.string "{JPN}いいかおしてるじゃないか.\n"
	.string "{JPN}おもしろい しょうぶが\l"
	.string "{JPN}できそうだな.\l"
	.string "{JPN}いいぞ! すごく いいぞ!\p"
	.string "{JPN}よし! おまえと おれで\nポケモンリーグでしか\lできない しょうぶを\lたのしもうぜ!$"

EverGrandeCity_SidneysRoom_Text_IntroSpeech2:
	.string "{JPN}また きたな ちょうせんしゃ!\n"
	.string "{JPN}おれは してんのう の\l"
	.string "{JPN}カゲツだ!\p"
	.string "{JPN}もう しってるよな!\n"
	.string "{JPN}また おもしろい しょうぶが\l"
	.string "{JPN}できそうだ. いいぞ!\p"
	.string "{JPN}よし! おまえと おれで\n"
	.string "{JPN}ポケモンリーグでしか\l"
	.string "{JPN}できない しょうぶを\lたのしもうぜ!\pこんどは まけないぞ.$"

EverGrandeCity_SidneysRoom_Text_Defeat:
	.string "{JPN}どうだ まいったか? おれの\n"
	.string "{JPN}まけだ!\nはは たのしかったから\lいいけどな.$"

EverGrandeCity_SidneysRoom_Text_Defeat2:
	.string "{JPN}どうだ まいったか? おれの\n"
	.string "{JPN}まけだ!\nまた やられちまった!\nでも たのしかったから いいや.$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
	.string "{JPN}まけた やつの いうことも\n"
	.string "{JPN}きいてくれよ.\p"
	.string "{JPN}おまえには さきに すすむ\n"
	.string "{JPN}ちからが ある.\l"
	.string "{JPN}つぎの へやで つぎの\lしょうぶを たのしんでこい!$"
