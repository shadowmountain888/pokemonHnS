GoldenrodCity_House2_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "{JPN}このまえたたかってるとき\n"
	.string "{JPN}ポケモンわざをだせなくなった\p"
	.string "{JPN}パワーポイントが\n"
	.string "{JPN}ゼロになってたんだ$"
GoldenrodPPSpeechHouse_Text_Lass:
    .string "{JPN}ポケモンがげんきいっぱいでも\n"
	.string "{JPN}わざをつかえないこともあるわ！\p"
	.string "{JPN}そんなときはポケモンセンターか\n"
	.string "{JPN}どうぐでなおしてあげなきゃ！$"