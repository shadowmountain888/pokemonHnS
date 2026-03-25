SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "{JPN}やあやあ!わたしは\n"
	.string "{JPN}なまえはんていし!\n"
	.string "{JPN}なまえのうらないしじゃ!\p"
	.string "{JPN}きみの ポケモンの\nニックネームを はんてい\nしてあげよう!$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "{JPN}どの ポケモンの ニックネームを\n"
	.string "{JPN}はんていすれば よいのかな?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "{JPN}うーん... {STR_VAR_1}ですか?\n"
	.string "{JPN}なかなか いい なまえを\n"
	.string "{JPN}つけましたね.\p"
	.string "{JPN}でも! わたしが もうすこし\nよい なまえを つけて\nあげましょうか?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "{JPN}よし よし.では あたらしい\n"
	.string "{JPN}ニックネームは なんじゃ?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "{JPN}できた!これからは この\n"
	.string "{JPN}ポケモンは {STR_VAR_1}と\n"
	.string "{JPN}よばれるのじゃ!\p"
	.string "{JPN}まえより ずっと いい なまえ\nじゃな!きみは うんが いい!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "{JPN}そうか.\n"
	.string "{JPN}また きておくれ.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "{JPN}できた!これからは この\n"
	.string "{JPN}ポケモンは {STR_VAR_1}と\n"
	.string "{JPN}よばれるのじゃ!\p"
	.string "{JPN}まえと おなじに みえるが\n"
	.string "{JPN}これは はるかに すばらしい!\pきみは うんが いいのう!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "{JPN}うーん... {STR_VAR_1}ですね!\p"
	.string "{JPN}これは すばらしい\n"
	.string "{JPN}ニックネームです!\n"
	.string "{JPN}もんくの つけようが\n"
	.string "{JPN}ありません!\pあなたの {STR_VAR_1}を\nいつまでも たいせつに\nしてください.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "{JPN}おおっと.\n"
	.string "{JPN}それは ただの タマゴじゃ!$"

