EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_KAREN, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_KAREN, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_DRAKE_REMATCH, EverGrandeCity_DrakesRoom_EventScript_DrakeRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIP, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIP2, EverGrandeCity_DrakesRoom_Text_Defeat2
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_KAREN
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "{JPN}わしは ポケモンリーグ\n"
	.string "{JPN}してんのう さいごの ひとり\p"
	.string "{JPN}ドラゴン つかいの ゲンジ じゃ!\p"
	.string "{JPN}しぜんの じょうたいでは\n"
	.string "{JPN}ポケモンは やせいの いきもの\p"
	.string "{JPN}じゆうに いきて おるのじゃ\p"
	.string "{JPN}ときには われらを こまらせ\n"
	.string "{JPN}ときには たすけて くれる\p"
	.string "{JPN}ポケモンを パートナーと して\n"
	.string "{JPN}たたかう ために ひつようなこと\p"
	.string "{JPN}それが なんなのか\nわかって おるか?\pもし わからぬなら\nわしには かてぬぞ!$"

EverGrandeCity_DrakesRoom_Text_IntroSpeech2:
	.string "{JPN}わしは ポケモンリーグ\n"
	.string "{JPN}してんのう さいごの ひとり\p"
	.string "{JPN}ドラゴン つかいの ゲンジ じゃ!\p"
	.string "{JPN}おまえの ポケモンの\n"
	.string "{JPN}パートナーたちは どうじゃ?\p"
	.string "{JPN}かれらが おまえを つよく\n"
	.string "{JPN}して くれたか?\p"
	.string "{JPN}きっと そうじゃろう!\p"
	.string "{JPN}もう やるきに なって おるな\nほかの してんのうたちが\pおまえを つかれさせたかの?\nいまさら よわきに なるでない!\pわしを たおして みせい!\nさあ はじめよう!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "{JPN}みごと というべきじゃな$"

EverGrandeCity_DrakesRoom_Text_Defeat2:
	.string "{JPN}はっはっは!\n"
	.string "{JPN}わらわずには おれんわい!\p"
	.string "{JPN}おどろいた みごとじゃ\n"
	.string "{JPN}おまえこそ さいこうじゃ$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "{JPN}ポケモンの トレーナーと して\n"
	.string "{JPN}ここまで きた おまえを\p"
	.string "{JPN}しんそこ みとめよう\p"
	.string "{JPN}おまえは ひつようなことを\n"
	.string "{JPN}しって おるようじゃな\p"
	.string "{JPN}そう トレーナーに ひつようなのは\n"
	.string "{JPN}ただしい こころなのじゃ\p"
	.string "{JPN}ポケモンは トレーナーの\n"
	.string "{JPN}よい こころに ふれ\p"
	.string "{JPN}ぜんあくを おぼえ\n"
	.string "{JPN}つよく そだつのじゃ\pいけ! さきへ すすめ!\nチャンピオンが まって おるぞ!$"

