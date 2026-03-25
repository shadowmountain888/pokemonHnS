Route6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_Text_PokefanM:
	.string "{JPN}はつでんしょのじこが\n"
	.string "{JPN}かいけつするまで\l"
	.string "{JPN}つうこうきんしなんだって！$"
Route6_Text_UndergroundPathSign:
	.string "{JPN}ちかつうろ\p"
	.string "{JPN}ハナダシティ - クチバシティ$"

PokefanM_Text_RexSeen:
	.string "{JPN}ぼくのオドシシは せかいで\n"
	.string "{JPN}いちばん かわいいんだ!$"

PokefanM_Text_RexBeaten:
	.string "{JPN}ぼくのオドシシが!$"

PokefanM_Text_RexAfter:
	.string "{JPN}みてよ! ぼくのオドシシの\n"
	.string "{JPN}かわいいしぐさを!\p"
	.string "{JPN}かわいくて こころが とけちゃう\n"
	.string "{JPN}でしょう?$"

PokefanM_Text_AllanSeen:
	.string "{JPN}ぼくのグランブルは せかいで\n"
	.string "{JPN}いちばん かわいいんだ!$"

PokefanM_Text_AllanBeaten:
	.string "{JPN}ぼくのグランブルが!$"

PokefanM_Text_AllanAfter:
	.string "{JPN}みてよ! ぼくのグランブルの\n"
	.string "{JPN}かわいいしぐさを!\p"
	.string "{JPN}かわいくて こころが とけちゃう\n"
	.string "{JPN}でしょう?$"

