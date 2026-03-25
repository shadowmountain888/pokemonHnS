RuinsOfAlph_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_B1F_OnFrame
	.byte 0

RuinsOfAlph_B1F_OnFrame::
	map_script_2 VAR_RUINSOFALPH_STATE, 1, RuinsOfAlph_B1F_EventScript_Presence
	.2byte 0

RuinsOfAlph_B1F_EventScript_Presence::
	lock
	msgbox RuinsOfAlph_B1F_Text_Presence, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUINSOFALPH_STATE, 0
	release
	end


RuinsOfAlph_B1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Teacher, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Hiker::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Gramps::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Gramps, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HelixFossil::
	finditem ITEM_HELIX_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OldAmber::
	finditem ITEM_OLD_AMBER
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_GSBALL::
	finditem ITEM_GS_BALL
	end

RuinsOfAlph_B1F_Text_Presence:
	.string "{JPN}ここには ふしぎな けはいが ある.$"

RuinsOfAlph_B1F_Text_Hiker:
	.string "{JPN}ここは ひろい へやだが\n"
	.string "{JPN}なにも ないな.$"

RuinsOfAlph_B1F_Text_Teacher:
	.string "{JPN}ここは しんぴてきな\n"
	.string "{JPN}ふんいきが しますね.\p"
	.string "{JPN}なんだか げんそうてきな\n"
	.string "{JPN}かんじが します.$"

RuinsOfAlph_B1F_Text_Gramps:
	.string "{JPN}こだいの たてものは\n"
	.string "{JPN}おうの はかばなのじゃ.\p"
	.string "{JPN}ピラミッドなんかが\n"
	.string "{JPN}そうじゃな.$"
