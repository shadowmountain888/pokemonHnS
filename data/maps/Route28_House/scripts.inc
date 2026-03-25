Route28_House_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	goto_if_set FLAG_GOT_TM_STEEL_WING Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "{JPN}あら まあ.みつかって\n"
	.string "{JPN}しまいましたわ.\p"
	.string "{JPN}わたしのことは だれにも\n"
	.string "{JPN}いわないでくださいな.\pひみつにしてくれるなら\nこれをさしあげますわ.\nおねがいします.$"

Route28House_Text_Celebrity2:
	.string "{JPN}トップスターって\n"
	.string "{JPN}たいへんなのよ.\p"
	.string "{JPN}どこへいっても\nひとがおいかけてくるの.\pひとりに\nしておいてほしいわ...$"
Route28House_Text_Fearow:
	.string "{JPN}オニドリル: フィーロ!$"

