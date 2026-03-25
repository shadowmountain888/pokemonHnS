Gate_AzaleaTown_IlexForest_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "{JPN}ウバメのもりは\n"
	.string "{JPN}ひろいからな.\l"
	.string "{JPN}きをつけて!\lまいごになるなよ.$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "{JPN}ウバメのもりは\n"
	.string "{JPN}もりのばんにんが\l"
	.string "{JPN}まもっておるのじゃ.\pいたずらしちゃ\nだめじゃよ!$"
