PalletTown_RedsHouse_2F_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{JPN}{PLAYER}は ファミコンで\n"
	.string "{JPN}あそんだ.\pもう いかなくちゃ--\nじかんが ないよ!$"

RedsHouse_Text_PC:
	.string "{JPN}..ながいあいだ\n"
	.string "{JPN}つかわれていないみたい$"