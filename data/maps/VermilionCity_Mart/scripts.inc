VermilionCity_Mart_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_BirdMan::
	msgbox VermilionMart_Text_SuperNerd, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_Woman::
	msgbox VermilionMart_Text_Beauty, MSGBOX_NPC
	end

VermilionMart_Text_SuperNerd:
	.string "{JPN}ロケットだんは もう カントーには\n"
	.string "{JPN}iないんだ.\p"
	.string "{JPN}それだけで うれしいよ.$"

VermilionMart_Text_Beauty:
	.string "{JPN}ヤマブキシティに かいものに\n"
	.string "{JPN}いこうかと おもってるの.$"
