CaveOfOrigin_UnusedRubySapphireMap1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CaveOfOrigin_UnusedRubySapphireMap1_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CaveOfOrigin_UnusedRubySapphireMap1_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, CaveOfOrigin_UnusedRubySapphireMap1_CloseRegiEntrance
	end

CaveOfOrigin_UnusedRubySapphireMap1_CloseRegiEntrance::
	setmetatile 14, 14, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 14, 15, METATILE_General_RockWall_SandBase, TRUE
	return

CaveOfOrigin_UnusedRubySapphireMap1_Scientist1::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist1_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist2::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist2_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist3::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist3_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Kirlia_Text, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist1_Text:
	.string "{JPN}このしゅるいの いわの こうぞうを\n"
	.string "{JPN}132ばんどうろなど ほかのばしょでも\l"
	.string "{JPN}みたことが あるんです.\p"
	.string "{JPN}これらの いわの けいせいぶつには\n"
	.string "{JPN}どのような いみが あるのでしょうか?\p"
	.string "{JPN}じんこうてきに つくられたものだと\nかくしんしています.\lなにか てがかりは ありませんか?$"

CaveOfOrigin_UnusedRubySapphireMap1_Scientist2_Text:
	.string "{JPN}らいうのたびに いくつかの かみなりが\n"
	.string "{JPN}この ちいさな しまに おちているん\l"
	.string "{JPN}です.あやしいと おもいませんか?\p"
	.string "{JPN}かみなりだけを えいようにしている\n"
	.string "{JPN}ポケモンが ここに すんでいると\l"
	.string "{JPN}かんがえています.$"

CaveOfOrigin_UnusedRubySapphireMap1_Scientist3_Text:
	.string "{JPN}すうかげつかん つづいている\n"
	.string "{JPN}ふしぎな げんしょうを けんきゅう\l"
	.string "{JPN}しています.この しまには にんげんが\l"
	.string "{JPN}すんでいないので ここでおこって\l"
	.string "{JPN}いることは きょくたんに なぞめいて\l"
	.string "{JPN}います.\p"
	.string "{JPN}キリも てがかりを さがしています.\n"
	.string "{JPN}この なぞを かいめい しなければ\lなりません.$"

CaveOfOrigin_UnusedRubySapphireMap1_Kirlia_Text:
	.string "{JPN}キリ:キリ!$"
