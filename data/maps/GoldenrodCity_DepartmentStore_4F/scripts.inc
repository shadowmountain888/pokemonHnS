GoldenrodCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "{JPN}つよいポケモンがすきでよ\n"
	.string "{JPN}タウリンあげまくって\l"
	.string "{JPN}こうげきりょくあげまくりだぜ！$"
GoldenrodDeptStore_Text_4FBugCatcher:
    .string "{JPN}ブロムヘキシンでねポケモンの\n"
	.string "{JPN}ぼうぎょりょくがアップするの！$"
GoldenrodDeptStore_Text_4FGameboyKid:
    .string "{JPN}こうかんしないと\n"
	.string "{JPN}しんかしない ポケモンが\l"
    .string "{JPN}いるって うわさが\l"
	.string "{JPN}あったんだって.\p"
    .string "{JPN}フン...\p"
	.string "{JPN}そんなの でたらめだよ.\p"
    .string "{JPN}うわさの ポケモンは\n"
	.string "{JPN}ゴーリキー カラカラ\l"
    .string "{JPN}ゴースト イシツブテ\l"
	.string "{JPN}らしいけど\l"
    .string "{JPN}ぜんぶ レベルアップで\l"
	.string "{JPN}しんかするんだ.$"

GoldenrodDeptStore_Text_4FDirectory:
    .string "{JPN}ポケモンののうりょくアップ！\n"
	.string "{JPN}4かい..メディシンボックス$"