Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "{JPN}ここは レート{STR_VAR_1}の ルーレットだい です\n"
	.string "{JPN}ルーレットで あそびますか?$"

Roulette_Text_NotEnoughCoins::
	.string "{JPN}コインが たりません$"

Roulette_Text_SpecialRateTable::
	.string "{JPN}ほんじつ このだいでは\n"
	.string "{JPN}レート アップ じっしちゅう!$"

Roulette_Text_ControlsInstruction::
	.string "{JPN}ベットする わくを じゅうじボタンで えらんで\n"
	.string "{JPN}Aボタンで けってい します$"

Roulette_Text_ItsAHit::
	.string "{JPN}あたりー!$"

Roulette_Text_Jackpot::
	.string "{JPN}おおあたり!!$"

Roulette_Text_NothingDoing::
	.string "{JPN}はずれー$"

Roulette_Text_YouveWonXCoins::
	.string "{JPN}おめでとう ございます!\n"
	.string "{JPN}コイン {STR_VAR_1}まい はいります!$"

Roulette_Text_NoCoinsLeft::
	.string "{JPN}コインが なくなりました$"

Roulette_Text_KeepPlaying::
	.string "{JPN}つづけて あそびますか?$"

Roulette_Text_BoardWillBeCleared::
	.string "{JPN}だいの うえの たまを\n"
	.string "{JPN}クリア します$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "{JPN}コインケースを もっていません!$"

Roulette_Text_CoinCaseIsFull::
	.string "{JPN}コインが いっぱいです!\n"
	.string "{JPN}けいひんと こうかん して ください$"
