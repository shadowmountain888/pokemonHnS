.set LOCALID_NURSE, 1

OlivineCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "{JPN}となりの しょくどうの\nせんいんさんって やさしいんだ\pわたしの ポケモンに\nかいりきを おしえてくれたの\pいまでは おおきな いわも\nらくらく うごかせるのよ$"
OlivineCity_Text_PokecenterTeacher:
	.string "{JPN}うみのむこうタンバシティには\n"
	.string "{JPN}めずらしいポケモンもってるって\l"
	.string "{JPN}じまんしてるひとがいるよ$"
