.set LOCALID_NURSE, 1

MtSilver_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MT_SILVER
	end

MtSilver_PokemonCenter_EventScript_Meara::
	msgbox MtSilver_PokemonCenter_Text_Meara, MSGBOX_NPC
	end

MtSilver_PokemonCenter_Text_Meara:
	.string "{JPN}わたしは ニビシティの\n"
	.string "{JPN}はくぶつかんの けんきゅういんです.\p"
	.string "{JPN}この ちいきで めずらしい\n"
	.string "{JPN}いせきが たくさん はっけん\l"
	.string "{JPN}されているので しらべに\l"
	.string "{JPN}きました.\p"
	.string "{JPN}やまの まわりに ぶんめいが\n"
	.string "{JPN}あったという きろくは\l"
	.string "{JPN}ありませんが いせきは たしかに\l"
	.string "{JPN}ひとが つくったものです.\pほんとうに ふしぎですね.$"
