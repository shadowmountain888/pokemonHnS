CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "{JPN}ポケモントレーナーとして\n"
	.string "{JPN}じつりょくをたしかめるのか？\p"
	.string "{JPN}だったらジョウトちほうの\n"
	.string "{JPN}かくちにあるポケモンジムで\l"
	.string "{JPN}バッジをあつめることだな！$"
CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "{JPN}ぼくおおきくなったら\n"
	.string "{JPN}がんばってジムリーダーになる！\p"
	.string "{JPN}そのためともだちのポケモンと\n"
	.string "{JPN}たたかわせてきたえるんだ！$"