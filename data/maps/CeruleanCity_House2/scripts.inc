CeruleanCity_House2_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "{JPN}あやしいヤツが\n"
	.string "{JPN}ウロウロしてるってはなしだ！\p"
	.string "{JPN}ドロボーだったら\n"
	.string "{JPN}ワシがゆるさーん！！$"
CeruleanPolice_Text_PokefanF:
	.string "{JPN}むかしねうちって\n"
	.string "{JPN}ドロボーにはいられたことあるの$"
CeruleanPolice_Text_Diglett:
	.string "{JPN}だぐだぐ$"
