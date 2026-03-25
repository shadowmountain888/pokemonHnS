LavenderTown_Mart_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Pokefan::
	msgbox LavenderMart_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderMart_Text_Rocker, MSGBOX_NPC
	end

LavenderMart_Text_PokefanM:
	.string "{JPN}どうくつを たんけんするなら\n"
	.string "{JPN}むしよけスプレーが ひつようだよ.\p"
	.string "{JPN}たんけんは すきだけど\n"
	.string "{JPN}まだ ぜんぶの どうくつには\l"
	.string "{JPN}いってないんだ.$"

LavenderMart_Text_Rocker:
	.string "{JPN}ジョウト ちほうの ヒワダタウンに\n"
	.string "{JPN}オリジナルの ボールを つくってくれる\l"
	.string "{JPN}しょくにんが いるって きいたぜ.\p"
	.string "{JPN}オレも ほしいなあ.$"
