LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "{JPN}あの たてもの すごいよね!\p"
	.string "{JPN}カントーの ラジオとうだよ$"

LavenderTown_Text_Teacher:
	.string "{JPN}カントーには いい ラジオばんぐみが\nたくさん あるのよ$"

LavenderTown_Text_Gramps:
	.string "{JPN}あちこちから ひとが やってきて\n"
	.string "{JPN}なくなった ポケモンたちの\l"
	.string "{JPN}たましいに いのりを ささげるのじゃ$"

LavenderTown_Text_Youngster:
	.string "{JPN}ねむっている ポケモンを おこすには\n"
	.string "{JPN}ポケモンのふえが いるんだ!\p"
	.string "{JPN}トレーナーなら しってて あたりまえ!$"

LavenderTown_Text_Sign:
	.string "{JPN}シオンタウン\p"
	.string "{JPN}こころ きよらかな むらさきいろの まち$"

LavenderTown_Text_KantoRadioStationSign:
	.string "{JPN}カントー ラジオきょく\p"
	.string "{JPN}おきにいりの ばんぐみを\n"
	.string "{JPN}24じかん ほうそうちゅう!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "{JPN}シオン ボランティア\n"
	.string "{JPN}ポケモンハウス$"

LavenderTown_Text_SoulHouseSign:
	.string "{JPN}たましいの いえ\n"
	.string "{JPN}ポケモンたちの たましいよ\n"
	.string "{JPN}やすらかに ねむれ$"
