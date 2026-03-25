EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_BRUNO, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_BRUNO, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_GLACIA_REMATCH, EverGrandeCity_GlaciasRoom_EventScript_GlaciaRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_GlaciaRematch::
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LUCY_BF_BRAIN, EverGrandeCity_GlaciasRoom_Text_Defeat2
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_BRUNO
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
	.string "{JPN}ようこそ わたしは してんのう\n"
	.string "{JPN}のひとり プリムです.\p"
	.string "{JPN}こおりの わざを みがくため\n"
	.string "{JPN}ホウエンまで やってきました.\p"
	.string "{JPN}しかし よわい トレーナーと\n"
	.string "{JPN}ポケモンの ちょうせんばかり.\p"
	.string "{JPN}あなたは どうでしょう?\p"
	.string "{JPN}わたしが ぜんりょくを だせる\n"
	.string "{JPN}あいてなら うれしいですわ!$"

EverGrandeCity_GlaciasRoom_Text_IntroSpeech2:
	.string "{JPN}また あえたね わたし プリム.\n"
	.string "{JPN}じこしょうかいは もう いらない\l"
	.string "{JPN}わよね.\p"
	.string "{JPN}あなたと たたかって いらい\n"
	.string "{JPN}ちょうせんしゃが だれも\l"
	.string "{JPN}こなかった.\p"
	.string "{JPN}あなたは どうなの?\n"
	.string "{JPN}うでを みがいたかしら?\p"
	.string "{JPN}あなたと ほんきで たたかえたら\nこんな うれしいことは\lないわ!\pでも こんどは... わたしが\nかつわ!$"
EverGrandeCity_GlaciasRoom_Text_Defeat:
	.string "{JPN}あなたと あなたの ポケモン...\n"
	.string "{JPN}なんて あついこころを もって\l"
	.string "{JPN}るのかしら!\p"
	.string "{JPN}その もえたぎる ねつりょうに\n"
	.string "{JPN}あっとう されてしまったわ.\pわたしの こおりの わざが\nつうよう しなかった のも\lとうぜんね.$"

EverGrandeCity_GlaciasRoom_Text_Defeat2:
	.string "{JPN}あなたの たましいは まだ\n"
	.string "{JPN}もえているのね! でも\pわたしは また つめたく\nされてしまった...$"
EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
	.string "{JPN}つぎの へやへ おすすみなさい.\p"
	.string "{JPN}そこで ポケモンリーグの\n"
	.string "{JPN}ほんとうに おそろしい すがたを\nかくにんしなさい.$"
