Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "{JPN}なんのちらしだろう?\p"
	.string "{JPN}ぶれいなトレーナーたちが\n"
	.string "{JPN}ちかつうろで\l"
	.string "{JPN}バトルをしているもよう.\p"
	.string "{JPN}ちいきじゅうみんからの\n"
	.string "{JPN}くじょうがふえたため \l"
	.string "{JPN}ちかつうろはむきげんふうさ.\p"
	.string "{JPN}タマムシけいさつ$"

Route7_Text_LockedDoor:
	.string "{JPN}かぎがかかっている...$"
