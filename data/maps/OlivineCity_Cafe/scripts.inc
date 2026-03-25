.set LOCALID_CAFE_JASMINE, 4

OlivineCity_Cafe_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "{JPN}あ.こんにちは{PLAYER}さん.\pこのおさらはあたしが\nぜんぶたべたわけでは.\pえーっと.\pあたしのまえにすわってた\nひとがたくさんたべて.\pまたしょうぶしたいときは\nヤマブキシティのかくとう\lどうじょうにきてください.$"
OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "{JPN}はっ！きみのポケモンは\nよわそうだな！\pいわをうごかすちからが\nないようだ！\pこれをつかってかいりきを\nおしえてやれ！$"
OlivineCity_Text_CafeSailorGotStrength:
	.string "{JPN}うみでたよれるのは\nじぶんだけだからな！\pおれのきんにくがじまんだ！\nきみもおれみたいにきたえろ！$"
OlivineCity_Text_CafeFishingGuru:
	.string "{JPN}このアサギしょくどうには\n"
	.string "{JPN}ちからじまんのうみのおとこが\l"
	.string "{JPN}まんぞくするメニューがいっぱい！$"
OlivineCity_Text_CafeSailor:
	.string "{JPN}アサギにきたときはかならず\n"
	.string "{JPN}このしょくどうによっていくんだ\p"
	.string "{JPN}ここのメシはどれをくっても\n"
	.string "{JPN}ちからがつくんだからやめられん！$"
