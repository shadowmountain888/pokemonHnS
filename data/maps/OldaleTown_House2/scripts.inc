OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "{JPN}ポケモンが たたかうと\n"
	.string "{JPN}だんだん レベルが あがって\lつよくなるんだよ$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "{JPN}いっしょにいる ポケモンが\n"
	.string "{JPN}つよくなれば もっと とおくまで\l"
	.string "{JPN}いけるように なるよ$"

