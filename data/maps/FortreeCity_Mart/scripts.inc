FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "{JPN}スーパーむしよけは ながく\n"
	.string "{JPN}もつし こうかてきだよ.\p"
	.string "{JPN}ふつうの むしよけより\n"
	.string "{JPN}ずっと いいね!$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "{JPN}わたしは いつも ひつような\n"
	.string "{JPN}ぶんより おおく かっておくの.\p"
	.string "{JPN}なにが おこるか わからないから\n"
	.string "{JPN}そなえあれば うれいなし よ!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "{JPN}ふしぎな アメは ポケモンを\n"
	.string "{JPN}すぐに 1レベル せいちょう させる.$"

