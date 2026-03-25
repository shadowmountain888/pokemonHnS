Gate_MahoganyTown_Route43_MapScripts::
	.byte 0

Gate_MahoganyTown_Route43_EventScript_Cop::
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, Gate_MahoganyTown_Route43_EventScript_CopAfter
	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_NPC
	end

Gate_MahoganyTown_Route43_EventScript_CopAfter::
	msgbox Route43MahoganyGate_Text_Officer_RocketsCleared, MSGBOX_NPC
	end

Route43MahoganyGate_Text_Officer:
    .string "{JPN}さいきんは いかりのみずうみに\n"
	.string "{JPN}むかうひとしか とおらないなあ$"

Route43MahoganyGate_Text_Officer_RocketsCleared:
    .string "{JPN}このごろは いかりのみずうみに\n"
	.string "{JPN}いくひとも いないねえ$"

