EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_KOGA, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_KOGA, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_PHOEBE_REMATCH, EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LUCY_BF_BRAIN, EverGrandeCity_PhoebesRoom_Text_Defeat2
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_KOGA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_IntroSpeech:
	.string "{JPN}あはははっ!\p"
	.string "{JPN}わたし してんのう の フヨウ よ.\n"
	.string "{JPN}おくりびやま で しゅぎょう したの.\p"
	.string "{JPN}しゅぎょう ちゅう に ゴースト\n"
	.string "{JPN}タイプ の ポケモン と はなせる\l"
	.string "{JPN}ようになったのよ.\p"
	.string "{JPN}そう ポケモン と の きずな は\n"
	.string "{JPN}とても ふかく なったわ.\p"
	.string "{JPN}さあ わたし の ポケモン に\nダメージ を あたえられるか\lためして みなさい!$"

EverGrandeCity_PhoebesRoom_Text_IntroSpeech2:
	.string "{JPN}あはははっ! また あなた ね!\p"
	.string "{JPN}わたし してんのう の フヨウ よ.\n"
	.string "{JPN}ポケモン と の きずな は\l"
	.string "{JPN}もっと つよく なったの!\p"
	.string "{JPN}だから わたし の ポケモン に\n"
	.string "{JPN}ダメージ を あたえられるか\l"
	.string "{JPN}ためして みなさい.\pまえ みたいに は いかないから!$"

EverGrandeCity_PhoebesRoom_Text_Defeat:
	.string "{JPN}あら まいったわ.\n"
	.string "{JPN}まけちゃった.$"

EverGrandeCity_PhoebesRoom_Text_Defeat2:
	.string "{JPN}あら だめ...\n"
	.string "{JPN}また やられちゃった.$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech:
	.string "{JPN}あなた と ポケモン の あいだ にも\n"
	.string "{JPN}たしかな きずな が あるのね.\p"
	.string "{JPN}わたし それ に きづかなかった\n"
	.string "{JPN}から まける の が しぜん よ.\p"
	.string "{JPN}うん あなた の きずな が\n"
	.string "{JPN}どこまで はこんで くれるか\l"
	.string "{JPN}みて みたいわ.\nさあ つぎ の へや へ すすんで.$"

