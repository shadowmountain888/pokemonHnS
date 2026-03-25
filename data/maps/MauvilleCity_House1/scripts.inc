MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_GARBAGEFLAG
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "{JPN}ワーホー!\p"
	.string "{JPN}みんなはぼくをいわくだきガイって\n"
	.string "{JPN}よぶけど ちょっとぶれいだよね.\p"
	.string "{JPN}もうちょっとそんけいしてほしいな.\n"
	.string "{JPN}いわくだきデュードとかさ.\p"
	.string "{JPN}ワーホー!\p"
	.string "{JPN}それはそうと きみのポケモン\n"
	.string "{JPN}けっこうつよそうだね.\p"
	.string "{JPN}いいかんじだよ!\n"
	.string "{JPN}はい このひでんマシンをどうぞ!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "{JPN}そのひでんマシンには いわくだき\n"
	.string "{JPN}がはいっているぞ.\p"
	.string "{JPN}おおきないわが みちをふさいで\n"
	.string "{JPN}いるときは...\p"
	.string "{JPN}そのひでんわざで いわを\n"
	.string "{JPN}くだいてしまえばいいのじゃ!\p"
	.string "{JPN}そうじゃ! いわをくだくのじゃ!\nうほほーい!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "{JPN}そうそう いわをくだくとかくれてた\n"
	.string "{JPN}ポケモンがとびだしてくることがあるよ.\p"
	.string "{JPN}ワーホー!$"

