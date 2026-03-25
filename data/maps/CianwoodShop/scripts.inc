CianwoodShop_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::	
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
	.string "{JPN}ななんてことだ..\p"
	.string "{JPN}きみとおなじくらいのとしごろで\n"
	.string "{JPN}めつきがするどくて\l"
	.string "{JPN}かみのけながくて\l"
	.string "{JPN}なんだかこわそうなしょうねんに\l"
	.string "{JPN}だいじなポケモンをとられたよ！\p"
	.string "{JPN}てもとに1ひきのこっているけど\n"
	.string "{JPN}またおそわれたらどうしよう..\p"
	.string "{JPN}きみつよそうだな\n"
	.string "{JPN}しばらくポケモンあずかってよ！$"
CianwoodCity_Text_ReceivedSecretpotion:
	.string "{JPN}{PLAYER}は\nひでんのくすりをもらった！$"
CianwoodCity_Text_PharmacistDescribePotion:
	.string "{JPN}{PLAYER}はマニアから\n"
	.string "{JPN}ポケモンをあずかった！$"