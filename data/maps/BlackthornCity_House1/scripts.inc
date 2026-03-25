BlackthornCity_House1_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "{JPN}このフスベシティには\n"
	.string "{JPN}ドラゴンをじゆうにあやつれる\l"
	.string "{JPN}いちぞくがすんでおる\p"
	.string "{JPN}そのためかこのまちには\n"
	.string "{JPN}ドラゴンにまつわるでんせつが\l"
	.string "{JPN}たくさんのこされておるんじゃよ$"
BlackthornCity_House1_Text_Dratini:
	.string "{JPN}リュー$"