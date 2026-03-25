OlivineCity_House3_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "{JPN}アサギといえばうみ！\n"
	.string "{JPN}うみといえばつり！\p"
	.string "{JPN}わしはここで30ねん\n"
	.string "{JPN}つりをしとるんだ\p"
	.string "{JPN}きみもうみにむかって\n"
	.string "{JPN}つりでちょうせんしてみるかね？$"
OlivineCity_Text_GiveGoodRod:
	.string "{JPN}おっほっほう！\n"
	.string "{JPN}つりびとたんじょうだ！$"
OlivineCity_Text_GaveGoodRod:
	.string "{JPN}さかなはうみだけじゃなく\nみずのあるところならどこにでも\lいるんだよ\pところでポケモンずかんには\nつりでつかまえたなかまがでるぞ\pばしょによってにたような\nさかなポケモンがつれるんだ$"
OlivineCity_Text_DontWantGoodRod:
	.string "{JPN}なんじゃと！\n"
	.string "{JPN}つりがきらい！しんじられんのお$"
OlivineCity_Text_HaveGoodRod:
	.string "{JPN}どう？\n"
	.string "{JPN}おおものつれたかね？$"