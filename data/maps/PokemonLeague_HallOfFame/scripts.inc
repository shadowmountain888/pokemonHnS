.set LOCALID_HALLOFFAME_LANCE, 1

PokemonLeague_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	.byte 0

PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 6, PokemonLeague_HallOfFame_EventScript_Cutscene
	.2byte 0

PokemonLeague_HallOfFame_EventScript_Cutscene::
	lock
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_LanceText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp::
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_Rematch_LanceText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags::
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setvar VAR_LEAGUE_STATE, 1
	setvar VAR_NEWBARK_TOWN_STATE, 6
	setvar VAR_SSAQUA_STATE, 0
	return

PokemonLeague_HallOfFame_EventScript_SetGameClearFlags::
	clearflag FLAG_HIDE_LATIOS
	clearflag FLAG_HIDE_LATIAS
	clearflag FLAG_HIDE_RAYQUAZA
	clearflag FLAG_HIDE_GROUDON
	clearflag FLAG_HIDE_KYOGRE
	clearflag FLAG_HIDE_MEWTWO
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	clearflag FLAG_ITEM_GS_BALL
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setflag FLAG_IS_KANTO_CHAMPION
	setvar VAR_COMPLETED_LUGIA, 4
	clearflag FLAG_HIDE_LUGIA
	setvar VAR_COMPLETED_HO_OH, 4
	clearflag FLAG_HIDE_HO_OH
	call PokemonLeague_HallOfFame_EventScript_SpawnRoamers
	call_if_ge VAR_SUICUNE_ENCOUNTERS, 8, PokemonLeague_HallOfFame_EventScript_SpawnSuicune
	call_if_set FLAG_CAUGHT_CELEBI, PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_CAUGHT_MEW
	clearflag FLAG_BATTLED_DEOXYS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_SUMMONED_MTMOON_JIRACHI
	setvar VAR_LEAGUE_STATE, 1
	return

PokemonLeague_HallOfFame_EventScript_SpawnRoamers::
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	setvar VAR_0x8004, 1
	special InitRoamer
	return

PokemonLeague_HallOfFame_EventScript_SpawnSuicune::
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi::
	clearflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	return

PokemonLeague_HallOfFame_Movement_LanceEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

PokemonLeague_HallOfFame_LanceText:
    .string "{JPN}ワタル: ここに らいたのは\n"
	.string "{JPN}ひさしぶりだ.\p"
    .string "{JPN}ここは リーグチャンピオンを\n"
	.string "{JPN}えいえんに たたえる ばしょ.\p"
    .string "{JPN}ゆうかんな ポケモンたちも\n"
	.string "{JPN}ここに のこされる.\p"
    .string "{JPN}きょう われわれは あたらしい\n"
	.string "{JPN}リーグチャンピオンの たんじょうを\p"
    .string "{JPN}もくげきした\p"
	.string "{JPN}すべての ポケモンに\n"
    .string "{JPN}あいじょうと しんらいを\p"
	.string "{JPN}よせる トレーナーを.\p"
    .string "{JPN}にんたいと けついで\n"
	.string "{JPN}せいこうした トレーナーを.\p"
    .string "{JPN}いだいさを そなえた\n"
	.string "{JPN}あたらしい リーグチャンピオンを!\p{PLAYER}よ きみと\nパートナーたちを\pチャンピオンとして\nとうろくさせてくれ!$"

PokemonLeague_HallOfFame_Rematch_LanceText:
    .string "{JPN}ワタル: おぼえているよ.\n"
	.string "{JPN}それほど まえのことでは\p"
    .string "{JPN}ないが ここで きみを\n"
	.string "{JPN}ジョウトの チャンピオンとして\p"
    .string "{JPN}むかえいれた.\p"
	.string "{JPN}そして いま ふたたび\n"
    .string "{JPN}ここにいる.さいこうの\p"
	.string "{JPN}トレーナーと ポケモンを\n"
    .string "{JPN}たたえる しんせいなる ばしょに.\p"
	.string "{JPN}きょう きみは ジョウトだけ\n"
    .string "{JPN}でなく カントーでも じぶんを\l"
	.string "{JPN}しょうめいし わたしの さいきょう\l"
    .string "{JPN}チームさえ うちやぶった.\p"
	.string "{JPN}きみは ポケモンへの\n"
    .string "{JPN}すばらしい あいじょうと\l"
	.string "{JPN}しんらいを みせつけ \l"
    .string "{JPN}その きずなが なんども\l"
	.string "{JPN}しょうりに みちびいてくれた.\p"
    .string "{JPN}にんたいと ゆるがぬ\n"
	.string "{JPN}けついに いろどられた\l"
    .string "{JPN}きみの たび は \l"
	.string "{JPN}トレーナーとしての\l"
    .string "{JPN}しんの せいしんを かたっている.\pきみには しんの いだいさの\nすべてが そなわっている.\pもしかしたら さいだいの\nそんざいに なるかもしれない.\p{PLAYER}よ きみと\nしんらいする パートナーたちを\pふたたび チャンピオンとして\nとうろくできることを ほこりに\pおもう.$"

