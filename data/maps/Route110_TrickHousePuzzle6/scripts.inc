Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{JPN}{PLAYER}は ひみつの あいことばを\n"
	.string "{JPN}ドアに かきこんだ.\p"
	.string "{JPN}カラクリだいおうが わがじんせい\n"
	.string "{JPN}                \p"
	.string "{JPN}かぎが かちっと ひらいた!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "{JPN}ふしぎな いえが あるって\n"
	.string "{JPN}きいたから みに きたのよ$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "{JPN}つよい トレーナーを\nはっけん したわ!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "{JPN}ここを たんけん するのって\n"
	.string "{JPN}とても たのしいの\p"
	.string "{JPN}なんども ちょうせん したく\n"
	.string "{JPN}なる ばしょ だわね!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "{JPN}とりポケモンで かべを\n"
	.string "{JPN}とびこえさせようかな   $"
Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "{JPN}ぐわあああ! しっぱい した!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "{JPN}えへへへ    ずるを しようと\n"
	.string "{JPN}したから まけちゃった$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "{JPN}このかいてんドアで\n"
	.string "{JPN}めが まわっちゃうよ   $"
Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "{JPN}ぐるぐる まわって\n"
	.string "{JPN}もう だめだ   $"
Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "{JPN}きみは まったく えいきょうを\n"
	.string "{JPN}uけて いない みたいだね\pそれとも ポーカーフェイスを\nきめこんで いるのかな?$"

