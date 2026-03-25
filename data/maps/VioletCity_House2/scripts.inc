VioletCity_House2_MapScripts::
	.byte 0

VioletCity_House2_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VioletCity_NicknameHouse_Text_Bird, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_NicknameHouse_Text_Teacher:
	.string "{JPN}すきなたべもののなまえを\n"
	.string "{JPN}つけているのよ\p"
	.string "{JPN}ウチのむすめがつけてる\n"
	.string "{JPN}ポケモンのニックネームのことよ$"
VioletCity_NicknameHouse_Text_Lass:
	.string "{JPN}あたしのポッポ\n"
	.string "{JPN}イチゴちゃんってなまえなの！$"
VioletCity_NicknameHouse_Text_Bird:
	.string "{JPN}ぽっぽー！$"