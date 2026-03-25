DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "{JPN}この みごとさを みて!\p"
	.string "{JPN}これは シルクのスカーフよ.\n"
	.string "{JPN}さいしんの ファッションなの!\p"
	.string "{JPN}あら あなたの めが きらきら\n"
	.string "{JPN}してるじゃない! わたしの\l"
	.string "{JPN}センスが わかるのね!\p"
	.string "{JPN}あなたって すてきね!\nはい どうぞ.もらって ちょうだい!$"

DewfordTown_House2_Text_NoRoom:
	.string "{JPN}あら もちものが いっぱい?\p"
	.string "{JPN}よく きいて この スカーフは\n"
	.string "{JPN}ぜったいに ひつような ものよ!\l"
	.string "{JPN}ぜんぶ うって でも ほしい\lくらいなのよ!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "{JPN}シルクのスカーフは ノーマル\n"
	.string "{JPN}タイプの わざの いりょくを\l"
	.string "{JPN}あげるの.\p"
	.string "{JPN}どんな ポケモンにも にあう\nすばらしい スカーフよ!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "{JPN}わあ うみを わたって\n"
	.string "{JPN}ムロタウンまで きたの?\p"
	.string "{JPN}もしかして トウキの\n"
	.string "{JPN}うわさを きいて きたの?\p"
	.string "{JPN}かれって とっても すてき...\n"
	.string "{JPN}みんな あこがれてるのよ$"

