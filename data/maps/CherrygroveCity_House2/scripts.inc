CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "{JPN}わしがわかいころは\nやりてのトレーナーじゃった！\pちょっとしたアドバイスじゃ\nたくさんポケモンをつかまえろ！\pみんなやさしくそだてるんじゃぞ！$"