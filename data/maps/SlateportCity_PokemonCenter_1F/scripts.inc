.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "{JPN}バトルのコツを\n"
	.string "{JPN}おしえてあげようか?\p"
	.string "{JPN}いろんなタイプの\n"
	.string "{JPN}ポケモンを\l"
	.string "{JPN}バランスよく\n"
	.string "{JPN}そだてることだね.\p"
	.string "{JPN}1ぴきのポケモンだけを\nつよくするのは\lよくないよ.\pタイプのあいしょうが\nわるかったら\lかてないかもしれないからね.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "{JPN}ともだちと\n"
	.string "{JPN}ポケモンこうかんをするんだ.\p"
	.string "{JPN}こうかんしたポケモンが\nどうぐをもっていたら\l2ばいうれしいよ!$"

