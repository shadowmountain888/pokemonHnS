AbandonedShip_Rooms2_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Rooms2_B1F_EventScript_Camper::
	msgbox AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring, MSGBOX_NPC
	end

AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring:
	.string "{JPN}ここは たんけんするのに\n"
	.string "{JPN}さいこうの ばしょだね!\n"
	.string "{JPN}とっても わくわくするよ!\p"
	.string "{JPN}ふねの なかには すごい\nたからものが ねむってるに\nちがいないよ!$"

