Gate_SaffronCity_Route7_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "{JPN}はつでんしょの じこの\n"
	.string "{JPN}はなし きいた?\p"
	.string "{JPN}ひがしの ほうで\n"
	.string "{JPN}シオンタウンの ちかくに あるよ$"

Route7_Text_SaffronGuard_Serious:
	.string "{JPN}けいびいんの しごとを\n"
	.string "{JPN}まじめに やってるんだ\p"
	.string "{JPN}おっ! ポケモンずかんを\nもってるじゃないか\pよし とおって いいぞ$"
