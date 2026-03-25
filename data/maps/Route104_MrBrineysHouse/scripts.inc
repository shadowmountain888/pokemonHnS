.set LOCALID_BRINEY, 1
.set LOCALID_PEEKO, 2

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_GARBAGEVAR, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_GARBAGEFLAG
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_PEEKO, 9, 6
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 8
	setvar VAR_GARBAGEVAR, 2
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "{JPN}ミスターハギろうじん: まて おじょうちゃん!\n"
	.string "{JPN}まつんじゃピーコ!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "{JPN}ん? きみは {PLAYER}{KUN}だね!\n"
	.string "{JPN}わしの だいじな ピーコを\l"
	.string "{JPN}たすけてくれた!\p"
	.string "{JPN}ほんとうに ありがとう!\p"
	.string "{JPN}なんだって?\n"
	.string "{JPN}わしと いっしょに\l"
	.string "{JPN}ふねに のりたいって?\p"
	.string "{JPN}ほほう...\p"
	.string "{JPN}ムロタウンに とどける てがみと\n"
	.string "{JPN}カイナシティに とどける にもつを\l"
	.string "{JPN}もっているのか?\p"
	.string "{JPN}なかなか いそがしい\n"
	.string "{JPN}せいかつを おくっているんだね!\pもちろん きみの おねがいなら\nぜんぜん もんだいないよ!\pただしい あいてに たのんだな!\nムロタウンに むかって\lしゅっぱつだ!$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "{JPN}ミスターハギろうじん: ムロタウンじゃな!\p"
	.string "{JPN}いかりをあげろ!\n"
	.string "{JPN}ピーコ しゅっぱつじゃよ あいじん!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "{JPN}ミスターハギろうじん: そうかい?\n"
	.string "{JPN}おつかいはまてるのかい?\p"
	.string "{JPN}ふねをだしたくなったら\n"
	.string "{JPN}いつでもいってくれ!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "{JPN}ミスターハギろうじん: おーい!\n"
	.string "{JPN}いいたいことはわかっとる!\p"
	.string "{JPN}ムロタウンにてがみ \n"
	.string "{JPN}カイナシティににもつをとどけるんじゃな.\p"
	.string "{JPN}わしにまかせておけば\n"
	.string "{JPN}まったくもんだいないぞ!\p"
	.string "{JPN}まずはムロタウンへしゅっぱつじゃ.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "{JPN}ミスターハギろうじん: おーい!\n"
	.string "{JPN}いいたいことはわかっとる!\p"
	.string "{JPN}カイナシティのクスノキかんちょうに\n"
	.string "{JPN}にもつをとどけるんじゃな.\p"
	.string "{JPN}わしにまかせておけば\n"
	.string "{JPN}まったくもんだいないぞ!\p"
	.string "{JPN}まずはムロタウンへしゅっぱつじゃ.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "{JPN}ミスターハギろうじん: おーい!\n"
	.string "{JPN}きみのためならいつでもうみにでるぞ!\p"
	.string "{JPN}さあ とものよ どこへいく?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "{JPN}ミスターハギろうじん: そうかい?\n"
	.string "{JPN}ピーコのいのちのおんじんじゃからな.\p"
	.string "{JPN}ふねをだしたくなったら\n"
	.string "{JPN}いつでもいってくれ!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "{JPN}ピーコ: ピー ピーひょろ!$"

