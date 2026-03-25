CherrygroveCity_House3_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "{JPN}ポケモンって\n"
	.string "{JPN}たたかっているとけいけんつんで\l"
	.string "{JPN}すがたかたちがかわっちゃうんだよ$"
CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "{JPN}ポケモンがかわる？\pほんとうにそんなことあったら\nびっくりしちゃう！$"