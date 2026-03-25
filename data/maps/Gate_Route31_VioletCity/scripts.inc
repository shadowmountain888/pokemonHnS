Gate_Route31_VioletCity_MapScripts::
	.byte 0

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "{JPN}やあ! きみは\n"
	.string "{JPN}マツバのとうに いったかい?$"

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "{JPN}かわいい ポケモンを\n"
	.string "{JPN}みつけたの.\p"
	.string "{JPN}ピカチュウに そっくり\nだったわ!$"
