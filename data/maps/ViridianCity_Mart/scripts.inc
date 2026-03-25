ViridianCity_Mart_MapScripts::
	.byte 0

ViridianCity_Mart_EventScript_Lass::
	msgbox ViridianMart_Text_Lass, MSGBOX_NPC
	end

ViridianCity_Mart_EventScript_Cooltrainer::
	msgbox ViridianMart_Text_CooltrainerM, MSGBOX_NPC
	end

ViridianMart_Text_Lass:
	.string "{JPN}このまちのジムリーダー\n"
	.string "{JPN}すごくクールでかっこいいのよ！$"
ViridianMart_Text_CooltrainerM:
	.string "{JPN}グレンタウンにはもういった？\p"
	.string "{JPN}ここからずっとみなみのしまが\n"
	.string "{JPN}グレンタウンなんだよ！$"
