Gate_Route29_Route46_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "{JPN}だんさを のぼることは\n"
	.string "{JPN}できないよ.\p"
	.string "{JPN}でも とびおりることは\nできるから\lちかみちに なるんだ.$"

Gate_Route29_Route46_Text_Youngster:
	.string "{JPN}このさきには いろんな\n"
	.string "{JPN}しゅるいの ポケモンが でるよ.\p"
	.string "{JPN}ぜんぶ つかまえたいなら\n"
	.string "{JPN}どこでも さがさないと\lだめだよ.$"
