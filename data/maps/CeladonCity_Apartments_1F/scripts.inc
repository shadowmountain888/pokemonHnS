CeladonCity_Apartments_1F_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "{JPN}かわいい ポケモンたちが\n"
	.string "{JPN}いっしょに いてくれるから\p"
	.string "{JPN}さびしく ないんですよ.\pニャースは おかねまで\nはこんできて くれるんです.$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "{JPN}タマムシ マンション\nかんりにん しつ$"
