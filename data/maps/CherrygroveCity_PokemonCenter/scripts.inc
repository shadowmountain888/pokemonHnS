.set LOCALID_NURSE, 1

CherrygroveCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGrove_Pokecenter_OnTransition
	.byte 0

CherryGrove_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	end

CherryGrove_Pokecenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_Chansey::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox CherryGrove_Pokecenter_Text_Chansey, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	closemessage
	end

CherryGrove_Pokecenter_Text_Fisher:
	.string "{JPN}ポケモンなんひきあずけても\n"
	.string "{JPN}ただなのはうれしいなあ$"
CherryGrove_Pokecenter_Text_Gentleman:
	.string "{JPN}あそこにおかれたパソコンは\n"
	.string "{JPN}ポケモントレーナーならだれでも\l"
	.string "{JPN}じゆうにつかっていいのだよ！$"
CherryGrove_Pokecenter_Text_Lass:
	.string "{JPN}まつみはながいっていうけど\nポケモンセンターのとけいを\lみてるとあっというまね！$"
CherryGrove_Pokecenter_Text_Chansey:
	.string "{JPN}ラッキー:ラッキー！$"