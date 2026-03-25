PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_Youngster, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Nerd::
	msgbox PewterCity_Mart_Text_SuperNerd, MSGBOX_NPC
	end

PewterCity_Mart_Text_Youngster:
	.string "{JPN}やあ! ぼくの ギャラドスを\n"
	.string "{JPN}みてよ!\p"
	.string "{JPN}コイキングから そだてたんだ.\nこんなに つよくなるなんて\nしんじられないよ!$"

PewterCity_Mart_Text_SuperNerd:
	.string "{JPN}むかし へんな おじいさんが\n"
	.string "{JPN}コイキングを うってたんです.\p"
	.string "{JPN}いかりのみずうみの コイキングは\n"
	.string "{JPN}すばらしいって いってましたね.$"

