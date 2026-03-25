Gate_RuinsOfAlph_Route36_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "{JPN}アルフのいせき\p"
	.string "{JPN}みて さわって たのしめる\n"
	.string "{JPN}かんこうち\pいしのパネルを うごかして\nみよう!$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "{JPN}きみは いせきを けんきゅう\n"
	.string "{JPN}してるのかい?\p みらいの かがくしゃだね$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "{JPN}いしのパネルに え が\n"
	.string "{JPN}かいてあるんだ\p"
	.string "{JPN} うごかしてみたんだけど\n"
	.string "{JPN}なんだろうね これ$"
