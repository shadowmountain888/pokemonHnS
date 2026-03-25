PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_CIANWOOD_CITY
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "{JPN}パシフィックログタウンと\n"
	.string "{JPN}カイナのあいだのうみは\l"
	.string "{JPN}ながれがはやいんだ.\p"
	.string "{JPN}なみのりをつかうときは\nきをつけないと\lながされちゃうよ.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "{JPN}ほら すごいでしょう?\n"
	.string "{JPN}いえがみずのうえにあるんだよ!\p"
	.string "{JPN}わたしはここでうまれたの!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "{JPN}そらのはしら?\p"
	.string "{JPN}...ああ きっと あの たかーい\n"
	.string "{JPN}たかーい とうの ことだね.\p"
	.string "{JPN}わたしなら のぼらないよ.\n"
	.string "{JPN}あんなに たかいところ こわすぎる.\p"
	.string "{JPN}かいめんの パシフィックログで\n"
	.string "{JPN}くらすのが いちばんだよ.$"

PacifidlogTown_Text_TownSign:
	.string "{JPN}パシフィックログタウン\p"
	.string "{JPN}あさのひがみずべにほほえむ\n"
	.string "{JPN}まち$"

