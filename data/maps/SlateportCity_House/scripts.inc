SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "{JPN}わたしの ポケモンは\n"
	.string "{JPN}せっかちな せいかくよ.\p"
	.string "{JPN}ほかの ポケモンと くらべて\n"
	.string "{JPN}すばやさが たかいの.\p"
	.string "{JPN}ポケモンの せいかくって\nのうりょくの のびかたに\nかんけいが あるのかしら.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "{JPN}あなた トレーナーでしょう?\p"
	.string "{JPN}カイナシティまで きたってことは\n"
	.string "{JPN}バトルテントに いくのね.$"

