Route26_House2_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "{JPN}なにか かいて あるね.\p"
	.string "{JPN}よんでみる?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "{JPN}きょうだいたちへ\p"
	.string "{JPN}わたしたちは ポケモン\n"
    .string "{JPN}トレーナーの おてつだいを\n"
	.string "{JPN}することに ほこりを\n"
    .string "{JPN}もっています.\p"
	.string "{JPN}トレーナーが はなしかけて\n"
    .string "{JPN}きたら なにか やくにたつ\n"
	.string "{JPN}ものを あげてください.\pあい\nモニカ\pつづきを よみますか?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "{JPN}げつようび モニカ\n"
	.string "{JPN}40ばんどうろ\p"
    .string "{JPN}かようび タスカニー\n"
	.string "{JPN}29ばんどうろ\p"
    .string "{JPN}すいようび ウェスリー\n"
	.string "{JPN}いかりのみずうみ\p"
    .string "{JPN}mokuyoubi アーサー\n"
	.string "{JPN}36ばんどうろ\p"
    .string "{JPN}きんようび フリーダ\n"
	.string "{JPN}32ばんどうろ\p"
    .string "{JPN}どようび サントス\n"
	.string "{JPN}フスベシティ\p"
    .string "{JPN}にちようび サニー\n"
	.string "{JPN}37ばんどうろ$"
