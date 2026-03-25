.set LOCALID_NURSE, 1

LilycoveCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
	end

@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx::
	special SetLilycoveLadyGfx
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
	end

LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon::
	setflag FLAG_GARBAGEFLAG
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon::
	clearflag FLAG_GARBAGEFLAG
	end

LilycoveCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Boy::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_Maniac::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon:
	.string "{JPN}せかいには どのくらいの\n"
	.string "{JPN}しゅるいの ポケモンが\l"
	.string "{JPN}いるのかしら.\p"
	.string "{JPN}うみを こえて とおくの\nひとたちと ポケモンこうかんが\lできたら すてきね.$"

LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels:
	.string "{JPN}ポケモンを ぬすんだり\n"
	.string "{JPN}いんせきを だましとったり\l"
	.string "{JPN}する わるいやつらの\lうわさを きいたわ.$"

LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels:
	.string "{JPN}ポケモンを ぬすんで\n"
	.string "{JPN}いんせきを うばう\l"
	.string "{JPN}にっくき やつらを...\pさいきん みかけないね$"

