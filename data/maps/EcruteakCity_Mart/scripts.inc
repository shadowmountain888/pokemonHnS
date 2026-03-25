EcruteakCity_Mart_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "{JPN}ぼくのイーブイ\n"
	.string "{JPN}エーフィにしんかしたよ\p"
	.string "{JPN}でもともだちのイーブイは\n"
	.string "{JPN}ブラッキーにしんかしたよ\p"
	.string "{JPN}なにがちがったんだろな\n"
	.string "{JPN}ふたりともずっとイーブイのまま\l"
	.string "{JPN}そだてていたのに..$"
EcruteakMart_Text_Granny:
	.string "{JPN}げんきのかけらをつかってあげると\n"
	.string "{JPN}ひんしのポケモンもとびおきますよ$"