AbandonedShip_Corridors_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "{JPN}ふねのなかで うきわを もってるのが\n"
	.string "{JPN}そんなに おかしいかよ?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "{JPN}うわあ  まいったよ!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "{JPN}うきわに つかまりながら\n"
	.string "{JPN}モンスターボールを なげるのは\nむずかしいんだ!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "{JPN}ここって たのしくない?\n"
	.string "{JPN}いるだけで わくわくするよ!$"
