GoldenrodCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore2_EventScript_Youngster::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Gent::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FGentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_2FYoungster:
	.string "{JPN}ポケギアには25けんまで\nでんわばんごうがはいるんだ\pどのばんごうをのこすか\nまよっちゃうよ$"
GoldenrodDeptStore_Text_2FCooltrainerF:
    .string "{JPN}わたしのケーシィ\n"
	.string "{JPN}ゲームコーナーでてにいれたの\l"
	.string "{JPN}いまではたいせつなパートナーよ$"
GoldenrodDeptStore_Text_2FGentleman:
    .string "{JPN}ひゃっかてんにくると\n"
	.string "{JPN}コガネはとかいだなあとおもうね\p"
	.string "{JPN}このしなぞろえのよさ\n"
	.string "{JPN}ほかとはちがうよ$"
GoldenrodDeptStore_Text_2FDirectory:
    .string "{JPN}たびのおともに\n"
	.string "{JPN}2かい..トレーナーズマーケット$"