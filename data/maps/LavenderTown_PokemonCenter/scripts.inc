.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "{JPN}シオンタウンの きたには\n"
	.string "{JPN}イワヤマトンネルが あるよ.\l"
	.string "{JPN}そこを とおると はつでんしょに\lいけるんだ.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "{JPN}ポケモンのふえの おんがくを\n"
	.string "{JPN}ながす ラジオばんぐみが\l"
	.string "{JPN}あるのよ.\p"
	.string "{JPN}あら? あなたの ラジオには\n"
	.string "{JPN}ラジオカードが ひつようね.\p"
	.string "{JPN}このまちの ラジオきょくで\nもらえるかも しれないわよ?$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "{JPN}はつでんしょが うごいて\n"
	.string "{JPN}いないと リニアも うごかない\n"
	.string "{JPN}よね...\p"
	.string "{JPN}ラジオきょくも ほうそう\nできないし...$"
LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "{JPN}ラジオきょくの きょくちょうさんが\n"
	.string "{JPN}とても よろこんでいたよ.\p"
	.string "{JPN}はつでんしょが また うごいて\n"
	.string "{JPN}ほうそうが さいかいできるって\l"
	.string "{JPN}いってたんだ.$"
