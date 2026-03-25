FuchsiaCity_Mart_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_Fisher::
	msgbox FuchsiaMart_Text_Fisher, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Woman::
	msgbox FuchsiaMart_Text_CooltrainerF, MSGBOX_NPC
	end

FuchsiaMart_Text_Fisher:
	.string "{JPN}むかしの サファリゾーンの\n"
	.string "{JPN}おみやげの ほうが よかったなあ...$"

FuchsiaMart_Text_CooltrainerF:
	.string "{JPN}むかしの サファリゾーンの\n"
	.string "{JPN}かんりにんの まごむすめが\nまちに すんでるよ$"
