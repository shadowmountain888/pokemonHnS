.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_GARBAGEFLAG
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "{JPN}ポケモンと いっしょに いることで\n"
	.string "{JPN}ひとは どんどん ともだちを つくる\p"
	.string "{JPN}そして それが せかいを もっと\n"
	.string "{JPN}ちかづけるんだ すばらしいと おもう$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "{JPN}それ!\n"
	.string "{JPN}いけ とりポケモン!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "{JPN}へへへ わたしの キャモメに\n"
	.string "{JPN}おつかいを たのんだんだ$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "{JPN}よし!\n"
	.string "{JPN}おかえり キャモメ!\p"
	.string "{JPN}あれ? これは なんだ?\n"
	.string "{JPN}なにを もっているんだ?\p"
	.string "{JPN}メンタルハーブ?\n"
	.string "{JPN}どこかで ひろってきたのかな\p"
	.string "{JPN}でも わたしは トレーナーじゃ\n"
	.string "{JPN}ないから きみが もっていきなよ$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "{JPN}キャモメの おかげで とおくに\n"
	.string "{JPN}すむ ともだちが いるんだ$"

FortreeCity_House4_Text_Wingull:
	.string "{JPN}キャモメ: ピヒョー!$"

