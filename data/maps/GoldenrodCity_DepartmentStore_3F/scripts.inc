GoldenrodCity_DepartmentStore_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore3_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Rocker::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FRocker, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_3FSuperNerd:
    .string "{JPN}おおれせっかちだから\n"
	.string "{JPN}ポポケモンしょうぶのときも\l"
	.string "{JPN}スピーダーつかって\l"
	.string "{JPN}ポケモンのすばやさあげてる！$"
GoldenrodDeptStore_Text_3FRocker:
    .string "{JPN}おうたたかうときポケモンに\n"
	.string "{JPN}スペシャルアップはつかってるか？\p"
	.string "{JPN}とくしゅのうりょくがあがって\n"
	.string "{JPN}ばっちりいいかんじだぜ！$"
GoldenrodDeptStore_Text_3FDirectory:
    .string "{JPN}しょうぶにかつために\n"
	.string "{JPN}3かい..バトルコレクション$"