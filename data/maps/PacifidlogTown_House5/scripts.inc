PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "{JPN}きょうは まぼろしじまが\nみえないなあ...$"
PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "{JPN}あら! あらまあ!\n"
	.string "{JPN}きょうは まぼろしじまが\nみえるわ!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "{JPN}まぼろしじま...\p"
	.string "{JPN}きっと しんきろうが でる\n"
	.string "{JPN}てんきの じょうけんに よって\l"
	.string "{JPN}みえたり みえなくなったり\n"
	.string "{JPN}するんだろうなあ\p"
	.string "{JPN}それとも ほんとうに\n"
	.string "{JPN}あらわれたり きえたり\n"
	.string "{JPN}しているのかな?\p"
	.string "{JPN}. . .\p"
	.string "{JPN}もしかして ポケモンが\n"
	.string "{JPN}しまを あらわれさせたり\lきえさせたりしているのかも?\pぜったい でんせつの\nポケモンだと おもうんだ$"
