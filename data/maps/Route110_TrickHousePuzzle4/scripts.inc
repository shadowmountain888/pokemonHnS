Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_GRUNT_28, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{JPN}{PLAYER}は とびらに ひみつの\n"
	.string "{JPN}あんごうを かきこんだ.\p"
	.string "{JPN}カラクリだいおうは かっこいい.\n"
	.string "{JPN}                \p"
	.string "{JPN}かぎが かちりと あいた!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "{JPN}かんがえるのが めんどうだよ.\n"
	.string "{JPN}たたかいたかっただけなのに!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "{JPN}まけちゃったけど やっぱり\n"
	.string "{JPN}たたかいが いちばん すきだよ!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "{JPN}そう おもわない? トレーナーが\n"
	.string "{JPN}いるなら どこでも いくでしょ.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "{JPN}へっ! こんな いわなんて\n"
	.string "{JPN}ゆびいっぽんで どかせるぜ!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "{JPN}いわは おせるけど\n"
	.string "{JPN}なぞとき できない   $"
Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "{JPN}ちからだけじゃ だめなんだ   \n"
	.string "{JPN}あたまも つかわないと!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "{JPN}トリックハウスって だんだん\n"
	.string "{JPN}むずかしく なってるよね?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "{JPN}きゃーっ!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "{JPN}だれか さいごまで たどりついた\nひとは いるのかしら?$"

