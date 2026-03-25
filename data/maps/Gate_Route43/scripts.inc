Gate_Route43_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Gate_Route43_Rocket_OnFrame
	.byte 0

Gate_Route43_Rocket_OnFrame::
	map_script_2 VAR_TEMP_0, 0, Gate_Route43_RocketChecker
	.2byte 0

Gate_Route43_RocketChecker::
	setvar VAR_TEMP_0, 1
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 1, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 2, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 4, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 5, Gate_Route43_Rocket_EventScript_Shakedown
	end

Gate_Route43_Rocket_EventScript_Shakedown::
	lock
	showmoneybox 0, 0
	msgbox Gate_Route43_Rocket_Text_TollFee, MSGBOX_DEFAULT
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_ShakedownBroke
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_ShakedownBroke::
	checkmoney 1
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_KickOut
	msgbox Gate_Route43_Rocket_Text_AllYouGot, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_KickOut::
	msgbox Gate_Route43_Rocket_Text_KickOut, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_Policeman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_FROM_MAHOGANY_COP, Gate_Route43_Rocket_EventScript_PolicemanAfter
	msgbox Route43Gate_Text_OfficerFoundTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	setflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_PolicemanAfter::
	msgbox Gate_Route43_Text_OfficerAvoidGrass, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_Rockets::
	msgbox Gate_Route43_Rocket_Text_MakingABundle, MSGBOX_NPC
	end

Gate_Route43_Rocket_Text_TollFee:
    .string "{JPN}ちょっと まて こども!\p"
	.string "{JPN}つうこうりょうは 500えん\n"
    .string "{JPN}はらってもらうぞ.$"

Gate_Route43_Rocket_Text_ThankYou:
    .string "{JPN}どうも ありがとう!$"

Gate_Route43_Rocket_Text_AllYouGot:
    .string "{JPN}じゃあ もってる ぶんだけ\nはらってくれよ.$"

Gate_Route43_Rocket_Text_KickOut:
	.string "{JPN}うわあ!\p"
	.string "{JPN}まったく もってない のか!\p"
	.string "{JPN}ちょっと かわいそうになったぞ.\p"
	.string "{JPN}よし とおって いいぞ...\p"
	.string "{JPN}ほかの けいびに いうなよ\n"
	.string "{JPN}わかったな?$"

Gate_Route43_Rocket_Text_MakingABundle:
    .string "{JPN}へへへ. たんまり かせがせて\n"
	.string "{JPN}もらってるぜ.\p"
    .string "{JPN}みんな いかりのみずうみで\nなにが おこってるか\nしりたがってるからな.$"

Route43Gate_Text_OfficerFoundTM:
    .string "{JPN}くろい ふくの やつらに\n"
	.string "{JPN}おいだされちまった.\p"
    .string "{JPN}やつらが これを\n"
	.string "{JPN}わすれて いったんだ.\p"
    .string "{JPN}きもちわるいから\nきみが もっていって\nくれないか?$"

Gate_Route43_Text_ReceivedTM30:
    .string "{JPN}{PLAYER}は わざマシン36を\nてにいれた.$"

Gate_Route43_Text_OfficerAvoidGrass:
    .string "{JPN}このゲートを つかえば\n"
	.string "{JPN}くさむらを とおらずに\nすむぞ.$"
