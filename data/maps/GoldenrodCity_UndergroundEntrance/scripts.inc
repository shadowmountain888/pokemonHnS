GoldenrodCity_UndergroundEntrance_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "{JPN}したのかいで\nしょうぶをいどまれたんだ。\pしたはきけんだから\nきをつけたほうがいいよ。$"
GoldenrodUnderground1_Text_Teacher:
	.string "{JPN}したのかいにはおみせが..\nでもトレーナーもいるの。\pこわくていけないわ。$"