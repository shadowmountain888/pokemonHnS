BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "{JPN}きょうは つよい トレーナーの\n"
	.string "{JPN}インタビューを ほうそう\lするのかしら?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "{JPN}ここで レストランを ひらいたら\n"
	.string "{JPN}ぜったい もうかるのに.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "{JPN}ふう...\p"
	.string "{JPN}はげしい たたかいの あとは\n"
	.string "{JPN}きゅうけいが ひつようだね...\p"
	.string "{JPN}でも いまでも せんりゃくや\n"
	.string "{JPN}コンボを かんがえるのは\nやめられないよ$"

