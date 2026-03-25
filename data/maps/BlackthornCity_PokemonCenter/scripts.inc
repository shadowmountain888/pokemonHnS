.set LOCALID_NURSE, 1

BlackthornCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "{JPN}はるか とおくの セキエイ\n"
	.string "{JPN}こうげんの おくふかくに\l"
	.string "{JPN}ポケモンリーグが あるのじゃ.\p"
	.string "{JPN}ぜんこくから つよい\nトレーナーたちが あつまると\lきいておるよ.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "{JPN}どうしても おしえたい\n"
	.string "{JPN}わざが あったの.\p"
	.string "{JPN}わすれオヤジに たのんで\n"
	.string "{JPN}ひでんマシンの わざを\lわすれさせて もらったわ.$"
