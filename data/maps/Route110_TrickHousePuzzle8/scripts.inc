Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{JPN}{PLAYER}は とびらに\n"
	.string "{JPN}ひみつのあんごうを\n"
	.string "{JPN}かきこんだ!\p"
	.string "{JPN}カラクリだいおう\n"
	.string "{JPN}だいすき\n... ... ... ... ... ... ... ...\pかちっと かぎが ひらいた!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "{JPN}ここまで たどりついた\n"
	.string "{JPN}トレーナーは すくないんだ$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "{JPN}きみも つよいってことだね...$"
Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "{JPN}きみが ポケモンリーグの\n"
	.string "{JPN}チャンピオンを たおした?\nそりゃ すごすぎるよ!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "{JPN}わたしと たたかえるなんて\n"
	.string "{JPN}うんが いいのね!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "{JPN}そんなばかな!\n"
	.string "{JPN}わたしが まけるなんて!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "{JPN}わたしに かつなんて\n"
	.string "{JPN}きせきね\nじまんしても いいわよ$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "{JPN}きみも トリックハウスの\n"
	.string "{JPN}チャレンジを がんばって\nきたんだな$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "{JPN}そうか...\n"
	.string "{JPN}きみは とくべつな\nスタイルを もってるね$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "{JPN}きみの ような ひとを みれば\n"
	.string "{JPN}カラクリだいおうも\nよろこぶだろう$"

