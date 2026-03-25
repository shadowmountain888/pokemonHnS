PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "{JPN}わたしも\n"
	.string "{JPN}ポケモンをそだててるの！\l"
	.string "{JPN}いまじゃガードマンのかわりよ！$"
PalletTown_Text_Fisher:
	.string "{JPN}かがくのちからってすげー！\p"
	.string "{JPN}ジョウトにはうみのむこうの\n"
	.string "{JPN}くにのひとたちと\l"
	.string "{JPN}ポケモンをこうかんできる\l"
	.string "{JPN}しせつがあるんだってな！$"
PalletTown_Text_Sign:
	.string "{JPN}マサラタウン\p"
	.string "{JPN}しんじつと りそうの いろ\n"
	.string "{JPN}あおと みどりに かこまれた まち$"

PalletTown_Text_RedsHouseSign:
	.string "{JPN}ここはレッドのいえ$"
PalletTown_Text_OaksLabSign:
	.string "{JPN}ここはオーキドはかせの\n"
	.string "{JPN}ポケモンけんきゅうじょ$"
PalletTown_Text_BluesHouseSign:
	.string "{JPN}ここはグリーンのいえ$"