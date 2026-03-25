FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "{JPN}ひとも... ポケモンも...\p"
	.string "{JPN}しぜんかんきょうのなかで\n"
	.string "{JPN}くらすことで かくされた\lちからが めざめるのじゃ...$"
FortreeCity_House2_Text_CoinInWhichHand:
	.string "{JPN}このばあさんが おぬしの\n"
	.string "{JPN}かくされたちからが めざめて\l"
	.string "{JPN}いるか みてやろう...\p"
	.string "{JPN}てのひらに コインを\n"
	.string "{JPN}もっておる\pさあ こたえよ みぎてに\nあるかな? ひだりてかな?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "{JPN}おお!そうです せいかい!\p"
	.string "{JPN}もういちど やってみましょう.\p"
	.string "{JPN}どちらの てに コインを\n"
	.string "{JPN}かくしているでしょうか?\nみぎか ひだりか?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "{JPN}おお!そうです せいかい!\p"
	.string "{JPN}もういちど やってみましょう.\p"
	.string "{JPN}どちらの てに コインを\n"
	.string "{JPN}かくしているでしょうか?\nみぎか ひだりか?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "{JPN}おお!すばらしい!\n"
	.string "{JPN}あなたの かくされた ちからが\n"
	.string "{JPN}めざめましたね!\p"
	.string "{JPN}さあ これを うけとって\nあなたの ポケモンの かくされた\nちからを めざめさせて ください.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "{JPN}めざめるパワーは ポケモンに\n"
	.string "{JPN}よって かわる わざなのです.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "{JPN}いいえ ざんねん.\n"
	.string "{JPN}はずれです.$"

