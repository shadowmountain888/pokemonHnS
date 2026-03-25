GoldenrodCity_House1_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "{JPN}スペシャルいろちがいポケモンの\nせっていをかえますか？$"
GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "{JPN}いろちがいせっていをかえました！\pパソコンのチャレンジビューワーで\nせっていをかくにんできます$"
GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "{JPN}ニュースです..\pけいさつがこのあかげのしょうねんを\nたんさくしています！\pきみはかれのなまえをしってますか？$"
GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "{JPN}はいはい！わたしはせいめい\nはんだんし！なまえのうらないし！\pポケモンのニックネームを\nうらなってさしあげましょう$"
GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "{JPN}はいはい..\n"
	.string "{JPN}どのポケモンのニックネームを\l"
	.string "{JPN}うらなおうかね..？$"
GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "{JPN}うむ..{STR_VAR_1}ですか？とても\nよいなまえをつけましたね\pしかし！もしもうすこしよい\nなまえをていあんしたらどうです？$"
GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "{JPN}はいはい..では\n"
	.string "{JPN}どんなニックネームにしますかね$"
GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "{JPN}さあどうです？\n"
	.string "{JPN}これからこのポケモンは\l"
	.string "{JPN}{STR_VAR_2}ですよ！\p"
	.string "{JPN}まえよりいいなまえでしょう？\n"
	.string "{JPN}よかったですねz$"
GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "{JPN}それではまたおこしください$"
GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "{JPN}ようしこれから\n"
	.string "{JPN}このポケモンは{STR_VAR_2}！\p"
	.string "{JPN}まえとおなじようにみえる？\n"
	.string "{JPN}そりゃきのせいですよ\p"
	.string "{JPN}こっちのほうがナイスで\n"
	.string "{JPN}よかったね！$"
GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "{JPN}うむ..{STR_VAR_1}ですね！\pこれはすばらしいニックネーム！\nもんくのつけようがありません！\nあなたの{STR_VAR_1}をいつまでも\nたいせつにしてくださいね$"
GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "{JPN}おいおい..\n"
	.string "{JPN}それはタマゴではないですか$"

