MahoganyTown_House1_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "{JPN}なんだなんだ\n"
	.string "{JPN}ロケットだんふっかつしたのか？\p"
	.string "{JPN}いかりのみずうみで\n"
	.string "{JPN}くろずくめのやつをみかけたんだが$"
MahoganyRedGyaradosHouse_Text_Teacher:
	.string "{JPN}すきなラジオばんぐみ？\nポケモンおんがくですね$"
MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "{JPN}ポケモンはしんかするとね\n"
	.string "{JPN}ちからづよくなるけど\l"
	.string "{JPN}わざをおぼえるのはおそくなるの$"
