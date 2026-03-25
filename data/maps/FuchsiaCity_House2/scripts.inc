FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "{JPN}わたしの おじいちゃんは\n"
	.string "{JPN}サファリゾーンの えんちょうなの.\p"
	.string "{JPN}すくなくとも まえは そうだった...\p"
	.string "{JPN}きゅうに きゅうかを とるって\n"
	.string "{JPN}いって ひとりで かいがいに\l"
	.string "{JPN}いっちゃったのよ.\p"
	.string "{JPN}サファリゾーンも そのまま\nやめちゃったの.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "{JPN}サファリゾーンが しまって\n"
	.string "{JPN}がっかりした ひとが おおいけど\l"
	.string "{JPN}おじいちゃんって がんこだから...$"
FuchsiaCity_House2_Text_WardenPhoto:
	.string "{JPN}にこにこしている\n"
	.string "{JPN}おじいさんが ポケモンに\nかこまれている しゃしんだ$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "{JPN}おおきな くさはらで\n"
	.string "{JPN}めずらしい ポケモンが\nたのしそうに あそんでいる\nしゃしんだ$"
