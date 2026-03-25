PalletTown_RedsHouse_1F_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "{JPN}あらこんにちは！\p"
	.string "{JPN}うちのレッドはたびにでてるの\n"
	.string "{JPN}ぜんぜんれんらくしてこないから\l"
	.string "{JPN}どこでなにをしてるのやら..\p"
	.string "{JPN}たよりがないのは\n"
	.string "{JPN}げんきなしらせっていうけど\l"
	.string "{JPN}それでも..しんぱいよね$"
RedsHouse_Text_Mom2:
	.string "{JPN}ケガやびょうきがしんぱいだけど\n"
	.string "{JPN}おとこのこはゲンキがいちばん！$"
RedsHouse_Text_TV:
	.string "{JPN}ジョウトではみたことない\n"
	.string "{JPN}ばんぐみをほうそうしてる..！$"