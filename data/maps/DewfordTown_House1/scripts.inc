DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "{JPN}こんな ちいさな しまで\n"
	.string "{JPN}ポケモンや かぞくと いっしょに\l"
	.string "{JPN}くらすのって すてきよね$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "{JPN}わたし スレートシティの\n"
	.string "{JPN}おおきな みなとまちから\l"
	.string "{JPN}けっこんして ここに きたの\p"
	.string "{JPN}この ちいさな しまでは\n"
	.string "{JPN}じかんが ゆっくり ながれるわ\lでも うみに かこまれて\lこれも しあわせよね$"

DewfordTown_House1_Text_Zigzagoon:
	.string "{JPN}ジグザグマ: ぐぐうー!$"

