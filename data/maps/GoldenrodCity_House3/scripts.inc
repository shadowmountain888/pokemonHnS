GoldenrodCity_House3_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "{JPN}いつもポケモンしょうぶでまけて\n"
	.string "{JPN}ひんしにさせてばかり..\p"
	.string "{JPN}それがりゆうなのか\n"
	.string "{JPN}ポケモンなついてくれないんだよ$"
GoldenrodHappinessRater_Text_Twin:
    .string "{JPN}ポケモンにどうぐつかってあげると\n"
	.string "{JPN}すごくうれしそうにするの！$"