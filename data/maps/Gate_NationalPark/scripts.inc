Gate_NationalPark_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantExit::
	special LoadPlayerParty
	setvar VAR_BUG_CONTEST_STATE, 0
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "{JPN}こんにちは トレーナー!\n"
	.string "{JPN}きょうは むしとりたいかい\l"
	.string "{JPN}ですよ.\p"
	.string "{JPN}ルールは かんたんです.\p"
	.string "{JPN}じぶんの ポケモンを つかって\n"
	.string "{JPN}むしポケモンを つかまえて\lしんさを うけるのです.\pさんか してみませんか?$"

Route35NationalParkGate_Text_OfficerGiveParkBalls:
	.string "{JPN}たいかいちゅうに あなたの\n"
	.string "{JPN}ポケモンが かくとくした\l"
	.string "{JPN}けいけんちは でるときに\l"
	.string "{JPN}もどります.\p"
	.string "{JPN}こちらが たいかいよう\nサファリボールです.$"

Route35NationalParkGate_Text_ReceivedParkBalls:
	.string "{JPN}{PLAYER}は サファリボールを\nうけとった!$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "{JPN}いちばん つよい むしポケモンを\n"
	.string "{JPN}つかまえた ひとが ゆうしょうです.\p"
	.string "{JPN}サファリボールが なくなったら\n"
	.string "{JPN}しゅうりょうです.\p"
	.string "{JPN}5ひきまで つかまえられます.\n"
	.string "{JPN}さいごに つかまえた ポケモン\l"
	.string "{JPN}だけが のこって たいかいに\l"
	.string "{JPN}でます.\p"
	.string "{JPN}がんばって つよい むしポケモンを\nつかまえてください!$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "{JPN}ポケモンを 2ひき いじょう\n"
	.string "{JPN}もっている ばあい\p"
	.string "{JPN}さきとうの ポケモンを\n"
	.string "{JPN}つかうことになります.\pそれで だいじょうぶですか?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "{JPN}では ほかの ポケモンは\n"
	.string "{JPN}たいかいちゅう おあずかり\lします.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "{JPN}{PLAYER}の ポケモンは\n"
	.string "{JPN}たいかい スタッフに\lあずけられた.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "{JPN}たいかいに さんかする ポケモンを\n"
	.string "{JPN}えらんでから きてください.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "{JPN}わかりました. また こんど\n"
	.string "{JPN}さんか してくださいね.$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "{JPN}あれれ... てもちの いちばん\n"
	.string "{JPN}まえの ポケモンが たたかえません.\p"
	.string "{JPN}つかいたい ポケモンと いれかえて\n"
	.string "{JPN}から また きてくださいね.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "{JPN}あれれ... てもちも パソコンの\n"
	.string "{JPN}ボックスも いっぱいですね.\p"
	.string "{JPN}つかまえた むしポケモンを\n"
	.string "{JPN}いれる ばしょが ありません.\p"
	.string "{JPN}てもちか パソコンのボックスに\n"
	.string "{JPN}すきまを つくって きてください.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "{JPN}あれれ... てもちの いちばんまえが\n"
	.string "{JPN}タマゴに なっていますね.\p"
	.string "{JPN}つかいたい ポケモンと いれかえて\n"
	.string "{JPN}から また きてくださいね.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "{JPN}きょうの たいかいは おわりました.\n"
	.string "{JPN}また こんど さんか してください.$"

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "{JPN}おれは とりポケモンが だいすき!\n"
	.string "{JPN}ゆうべ こうえんで あくタイプの\l"
	.string "{JPN}とりを みつけたんだ!$"

Route35NationalParkGate_Text_BC2:
	.string "{JPN}すげー ストライクを\nつかまえたぜ!$"

Route35NationalParkGate_Text_Beauty:
	.string "{JPN}あのひとは いつも\nたいかいで かつのよ!$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "{JPN}こうえんでは ていきてきに\n"
	.string "{JPN}たいかいを かいさい しています.\nぜひ ちょうせん してください.$"

Route35NationalParkGate_Text_YoungsterWonders:
	.string "{JPN}つぎの むしとりたいかいは\n"
	.string "{JPN}いつ ひらかれるの?$"

Route35NationalParkGate_Text_ContestExplanation:
	.string "{JPN}むしとりたいかいは かようび \n"
	.string "{JPN}もくようび どようびに\l"
	.string "{JPN}かいさい されます.\p"
	.string "{JPN}さんかするだけで しょうひんが\n"
	.string "{JPN}もらえるだけでなく \p"
	.string "{JPN}たいかい しゅうりょうじに\nもっている むしポケモンも\lもらえます.$"
