LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "{JPN}つまが おんせんで タマゴを\n"
	.string "{JPN}あたためてるんだ. つまが\l"
	.string "{JPN}いってたよ.\p"
	.string "{JPN}そだてやに ふたひきの ポケモンを\nあずけてたら\lそのタマゴが みつかったんだって!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "{JPN}ジグザグマ: プシュー!$"

