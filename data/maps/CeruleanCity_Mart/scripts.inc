CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "{JPN}ハナダのみさきにいくとちゅうに\n"
	.string "{JPN}たくさんトレーナーがいるんだ\p"
	.string "{JPN}とおりかかったトレーナーの\n"
	.string "{JPN}じつりょくをためしているのさ$"
CeruleanMart_Text_CooltrainerF:
	.string "{JPN}ハナダのみさきにいる\n"
	.string "{JPN}トレーナーたちにかてるひとって\l"
	.string "{JPN}このまちじゃジムリーダーの\l"
	.string "{JPN}カスミちゃんくらいね！$"