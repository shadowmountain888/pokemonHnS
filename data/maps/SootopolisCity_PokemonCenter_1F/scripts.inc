.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "{JPN}ミクリは ホウエンちほう\n"
	.string "{JPN}いちばんの つよい トレーナー\l"
	.string "{JPN}って ウワサだよ.\p"
	.string "{JPN}この まちの ジムリーダーは\n"
	.string "{JPN}ミクリの しししょうなんだ.\p"
	.string "{JPN}でも してんのうは... ミクリの\n"
	.string "{JPN}しししょうより つよいって\lいわれてるよ.\pいったい どのくらい\nつよいんだろうね?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "{JPN}まちの みんなは ひなんして\n"
	.string "{JPN}いえから でてこないんだ.\p"
	.string "{JPN}わたしだって ほんとうは\n"
	.string "{JPN}そとに でたくないよ.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "{JPN}いつでも どこでも なにがあっても\n"
	.string "{JPN}わたしは ポケモンと\l"
	.string "{JPN}ともだちで いるよ.\p"
	.string "{JPN}ポケモンと いっしょだと\nたのしいからね!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "{JPN}ポケモンは わたしたちの\n"
	.string "{JPN}ともだちでしょ?\pなんで こんなふうに\nあばれるのかしら?$"

