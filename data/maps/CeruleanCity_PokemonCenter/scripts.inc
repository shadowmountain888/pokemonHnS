.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "{JPN}やっぱりたいせんのときは\n"
	.string "{JPN}たとえよわくたって\l"
	.string "{JPN}つかまえたばかりのポケモンより\l"
	.string "{JPN}ずっとそだててきたポケモンを\l"
	.string "{JPN}つかいたいよね！$"
CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "{JPN}リニアはじそく550キロ！\n"
	.string "{JPN}カントーとジョウトを\l"
	.string "{JPN}あっというまにおうふくさ！\p"
	.string "{JPN}これでジョウトにも\n"
	.string "{JPN}いきやすくなったね！$"
