Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_Incense::
	msgbox Route117_PokemonDayCare_Incense_Text, MSGBOX_NPC
	end

Route117_PokemonDayCare_Incense_Text:
	.string "{JPN}とくていの ポケモンは おこうと\n"
	.string "{JPN}よばれる どうぐを もたせて\l"
	.string "{JPN}そだてやに あずけないと てにはいりません.\p"
	.string "{JPN}おこうには 2しゅるいあります.\n"
	.string "{JPN}なんびきの ポケモンが てにはいる\l"
	.string "{JPN}でしょうか?\pげんざい 9しゅるいの ちがう\nポケモンが おこうを つかって\lてにはいります.$"
