EcruteakCity_House1_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "{JPN}わしがちいさいころのはなし\p"
	.string "{JPN}そらがとつぜん\n"
	.string "{JPN}まっくらになったとおもったら\l"
	.string "{JPN}おっきなポケモンがとんでいった\p"
	.string "{JPN}あのりゅうのような\n"
	.string "{JPN}とりのようなポケモンは\l"
	.string "{JPN}なんじゃったのかのう？$"
EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "{JPN}そんなでっかいポケモン\n"
	.string "{JPN}ほんとうにいるのかな？\l"
	.string "{JPN}いたらすっげーつよそうだけど$"
