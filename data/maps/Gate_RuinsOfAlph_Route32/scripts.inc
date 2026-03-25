Gate_RuinsOfAlph_Route32_MapScripts::
	.byte 0


Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_Text_PokefanM:
	.string "{JPN}きみは いせきを しらべて\n"
	.string "{JPN}いるのかい?\nしょうらい かがくしゃに\nなりそうだね!$"

Gate_RuinsOfAlph_Route32_Text_Youngster:
	.string "{JPN}いしの パネルに えが\n"
	.string "{JPN}かいてあるんだ.\p"
	.string "{JPN}うごかしてみたけど\n"
	.string "{JPN}なんだろうね これ.$"
