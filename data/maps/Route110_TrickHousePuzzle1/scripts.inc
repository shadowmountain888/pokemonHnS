Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{JPN}{PLAYER}は ひみつの あんごうを\n"
	.string "{JPN}とびらに かきこんだ.\p"
	.string "{JPN}カラクリだいおうは すばらしい\n"
	.string "{JPN}... ... ... ... ... ... ... ...\p"
	.string "{JPN}かぎが カチッと ひらいた!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "{JPN}いまおぼえたばかりの\n"
	.string "{JPN}いあいぎりで ばっさばっさと\nしょうりするわよ!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "{JPN}どうして そんなに\nまじめなのよ?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "{JPN}ばっさばっさきるのって\n"
	.string "{JPN}ぜんぜん あきないのよね!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "{JPN}へんな いえに まちがって\n"
	.string "{JPN}はいっちゃったんだ...$"
Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "{JPN}それで まけちゃった...$"
Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "{JPN}みちに まよって バトルに まけて \n"
	.string "{JPN}もっと まよっちゃった... でられない...$"
Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "{JPN}からくりおやじって\nいったい だれなんだろう?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "{JPN}かんがえごとを してたら\nまけちゃった!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "{JPN}きみ つよいね!\n"
	.string "{JPN}いったい だれなんだい?$"

