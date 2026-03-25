BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 5
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSafariBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK, 7, 2
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK, 35, 7
	releaseall
	end

BugContest_Text_Judging0::
	.string "{JPN}たいかいでつかう\n"
	.string "{JPN}せんようのボールをどうぞ!\p"
	.string "{JPN}しんさする ポケモンを\n"
	.string "{JPN}えらんで ください$"

BugContest_Text_Judging1::
	.string "{JPN}みなさんが つかまえた ポケモンの\n"
	.string "{JPN}しんさを いたします!\p"
	.string "...............\n"
	.string "...............\p"
	.string "{JPN}けっかはっぴょう-!!\n"
	.string "{JPN}じゃじゃじゃーん!!$"

BugContest_Text_WrongChoiceMon:
	.string "{JPN}しんさする ポケモンを\n"
	.string "{JPN}えらんで ください$"

BugContest_Text_DidntCatch:
	.string "{JPN}ざんねん!\p"
	.string "{JPN}それいじょう ポケモンを\n"
	.string "{JPN}つかまえられないようですよ!\p"
	.string "{JPN}あずかった ポケモンは\n"
	.string "{JPN}おかえし しますね$"

BugContest_Text_TimesUp:
	.string "{JPN}ピンポーン! じかんを すぎたので\n"
	.string "{JPN}むしとりたいかいは しゅうりょうです$"

BugContest_Text_WhiteOut:
	.string "{JPN}{PLAYER}の てもちの ポケモンは\n"
	.string "{JPN}すべて たおれた!\p"
	.string "{JPN}{PLAYER}は たいかいを きけん した$"

BugContest_Text_First1:
	.string "{JPN}3ばんは エリコが つかまえた\n"
	.string "{JPN}バタフリー!$"
BugContest_Text_First2:
	.string "{JPN}2ばんは ヨウジが つかまえた\n"
	.string "{JPN}カイロス!$"
BugContest_Text_First3:
	.string "{JPN}そして! こんかいの たいかい\n"
	.string "{JPN}1ばんの ゆうしょうしゃは...\p"
	.string "{JPN}{STR_VAR_1}を つかまえた\n"
	.string "{JPN}{PLAYER}さん!$"

BugContest_Text_Second1:
	.string "{JPN}3ばんは エリコが つかまえた\n"
	.string "{JPN}バタフリー!$"
BugContest_Text_Second2:
	.string "{JPN}2ばんは {STR_VAR_1}を つかまえた\n"
	.string "{JPN}{PLAYER}さん!$"
BugContest_Text_Second3:
	.string "{JPN}そして! こんかいの たいかい\n"
	.string "{JPN}1ばんの ゆうしょうしゃは...\p"
	.string "{JPN}カイロスを つかまえた\n"
	.string "{JPN}ヨウジさん!$"


BugContest_Text_Third1:
	.string "{JPN}3ばんは {STR_VAR_1}を つかまえた\n"
	.string "{JPN}{PLAYER}さん!$"
BugContest_Text_Third2:
	.string "{JPN}2ばんは エリコが つかまえた\n"
	.string "{JPN}バタフリー!$"
BugContest_Text_Third3:
	.string "{JPN}そして! こんかいの たいかい\n"
	.string "{JPN}1ばんの ゆうしょうしゃは...\p"
	.string "{JPN}カイロスを つかまえた\n"
	.string "{JPN}ヨウジさん!$"

BugContest_Text_TakePartInFuture:
	.string "{JPN}つぎの むしとりたいかいにも\n"
	.string "{JPN}みなさん さんか してくださいね!$"

BugContest_Text_TransferAndReturn:
	.string "{JPN}つかまえた ポケモンは\n"
	.string "{JPN}ボックスに てんそうされた!\p"
	.string "{JPN}あずかった ポケモンは\n"
	.string "{JPN}おかえし しますね$"
