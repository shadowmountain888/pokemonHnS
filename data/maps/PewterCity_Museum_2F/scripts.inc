PewterCity_Museum_2F_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "{JPN}ニビのちかくに\n"
	.string "{JPN}いんせきがおちたんだそうだよ\p"
	.string "{JPN}そんなめずらしいもの\n"
	.string "{JPN}ぜひうちのはくぶつかんに\l"
	.string "{JPN}かざってみたいものだけど..\p"
	.string "{JPN}なんかふしぎなエネルギーが\n"
	.string "{JPN}でているみたいでね\l"
	.string "{JPN}はこびだせないらしいんだ..$"
PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "{JPN}ピカチュウが ほしいの!\n"
	.string "{JPN}とっても かわいいの!\p"
    .string "{JPN}パパに つかまえて もらうように\nたのんだの!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "{JPN}そうよ きっと すぐに\nピカチュウを つかまえるわ!$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "{JPN}スペースシャトル$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "{JPN}おつきみやまに おちた いんせき.\n"
	.string "{JPN}つきのいしだと かんがえられて\nいる.$"
