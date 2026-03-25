CliffEdgeCave_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "{JPN}どうくつの なかで みちが\n"
	.string "{JPN}ふたつに わかれていたら\l"
	.string "{JPN}たいてい ひとつは ただしくて\l"
	.string "{JPN}もう ひとつは いきどまりじゃ\p"
	.string "{JPN}でも ひとは りょうほう\nためしたく なってしまうのう$"
