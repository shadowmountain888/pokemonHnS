LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "{JPN}しんじられる?\p"
	.string "{JPN}ポケモンのせわに\n"
	.string "{JPN}あきちゃうひとがいるのよ.\p"
	.string "{JPN}おじいちゃんはそんな\n"
	.string "{JPN}かわいそうなポケモンを\lひきとってせわしてるの.$"
LavenderTown_House1_Text_Guy:
	.string "{JPN}フジろうじんはここにすんで\n"
	.string "{JPN}いるけど いまはるすだよ.\l"
	.string "{JPN}レイのとうにいるはずさ.$"
LavenderTown_House1_Text_Marowak:
	.string "...$"

LavenderTown_House1_Text_Marowak2:
	.string "{JPN}ガラガラはしずかだが \n"
	.string "{JPN}とてもしあわせそうに\lみえる.$"

