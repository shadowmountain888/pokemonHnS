Route12_House_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "{JPN}わたしは つりめいじんの\n"
	.string "{JPN}おとうとです.\p"
	.string "{JPN}あなたは つりが すきですね.\p"
	.string "{JPN}まちがいありません!\p"
	.string "{JPN}どうです? わたしの みたては\n"
	.string "{JPN}ただしいでしょう?$"

Route12_House_Text_GiveSuperRod:
	.string "{JPN}やはり そのとおりでした!\p"
	.string "{JPN}つりずきの あなたに これを\n"
	.string "{JPN}さしあげましょう!\lスーパーロッドです!$"

Route12_House_Text_GaveSuperRod:
	.string "{JPN}みずの あるところなら\n"
	.string "{JPN}どこでも つりを してください.\p"
	.string "{JPN}つかう つりざおに よって\n"
	.string "{JPN}つれる ポケモンが ちがいますよ.$"

Route12_House_Text_DontWantSuperRod:
	.string "{JPN}え? わたしの めが\nくるっていたのですか?$"

