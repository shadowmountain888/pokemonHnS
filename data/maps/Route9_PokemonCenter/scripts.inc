.set LOCALID_NURSE, 1

Route9_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route9_PokemonCenter_EventScript_Engineer1::
	msgbox Route9_PokemonCenter_Text_Engineer1, MSGBOX_NPC
	end

Route9_PokemonCenter_EventScript_Engineer2::
	msgbox Route9_PokemonCenter_Text_Engineer2, MSGBOX_NPC
	end

Route9_PokemonCenter_Text_Engineer1:
	.string "{JPN}わたしたち エンジニアは\n"
	.string "{JPN}きゅうけいの ために ここに\l"
	.string "{JPN}くることが あるよ.\p"
	.string "{JPN}それか マネージャーから\nにげるために ね.\pあの ひとは クレイジーだよ.$"

Route9_PokemonCenter_Text_Engineer2:
	.string "{JPN}はつでんしょは とても\n"
	.string "{JPN}とおい ばしょに あるから\lしごとの ために とおくまで\lいどうしてるんだ.$"
