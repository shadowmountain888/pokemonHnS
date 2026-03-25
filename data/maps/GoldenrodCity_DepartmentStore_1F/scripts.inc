GoldenrodCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "{JPN}いらっしゃいませ！\n"
	.string "{JPN}コガネひゃっかてんです$"
GoldenrodDeptStore1_Text_Gentleman:
    .string "{JPN}コガネのひゃっかてんには\n"
	.string "{JPN}いろんなものがそろっとる\p"
	.string "{JPN}でもねこのまちの\n"
	.string "{JPN}ゲームコーナーのけいひんでないと\l"
	.string "{JPN}てにはいらないものもあるんだよ$"
GoldenrodDeptStore1_Text_PokefanF:
    .string "{JPN}さあきょうも\n"
	.string "{JPN}たくさんおかいものするわよ！$"
GoldenrodDeptStore1_Text_BugCatcher:
    .string "{JPN}おかあさんはかいものじょうず\p"
	.string "{JPN}ちょっとやすいねだんで\n"
	.string "{JPN}どうぐをかってくるよ$"
GoldenrodDeptStore1_Text_Directory:
    .string "{JPN}1かい..サービスカウンター\n"
	.string "{JPN}2かい..トレーナーズマーケット\l"
	.string "{JPN}3かい..バトルコレクション\l"
	.string "{JPN}4かい..メディシンボックス\l"
	.string "{JPN}5かい..わざマシンコーナー\l"
	.string "{JPN}6かい..いこいのひろば$"