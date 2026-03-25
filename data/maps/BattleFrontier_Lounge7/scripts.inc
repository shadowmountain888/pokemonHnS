BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor::
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "{JPN}ぶはははは!\p"
	.string "{JPN}いまのすがたからは\n"
	.string "{JPN}そうぞうできないでしょうけど\l"
	.string "{JPN}わたし むかしは つよい\l"
	.string "{JPN}トレーナーだったのよ!\p"
	.string "{JPN}サイキョウの ビューティーとして\n"
	.string "{JPN}ゆうめいだったのよ!\p"
	.string "{JPN}                       \p"
	.string "{JPN}どうしたの?\n"
	.string "{JPN}しんじられないって かんじ?\p"
	.string "{JPN}むこうの ほらふきおんなとは\n"
	.string "{JPN}ちがうのよ! わたし ほんとうに\l"
	.string "{JPN}うでまえが あるのよ!\p"
	.string "{JPN}しょうこを みせて あげる!\n"
	.string "{JPN}あなたの ポケモンに とくべつで\l"
	.string "{JPN}かわいい わざを\lおしえて あげるわ!\pでも ただでは おしえないわよ!\nわざを おしえるだいかに\lバトルポイントを\lすこし いただくわよ!$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "{JPN}ぶはははは!\p"
	.string "{JPN}とくべつで かわいい ポケモンの\n"
	.string "{JPN}わざを おしえに もどってきたのか?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "{JPN}よし よし みてみろ!\n"
	.string "{JPN}どの わざを おしえようかな?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "{JPN}わざ {STR_VAR_1} だな?\n"
	.string "{JPN}それは {STR_VAR_2} バトルポイントだ!$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "{JPN}よし よし つぎは わざを おしえる\n"
	.string "{JPN}ポケモンを えらんでくれ!$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "{JPN}なによ   \n"
	.string "{JPN}バトルポイントが たりないじゃない!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "{JPN}どうだ わしの うでまえは!\n"
	.string "{JPN}バトルポイントを いただくぞ!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "{JPN}なんですって?\n"
	.string "{JPN}やりたくないの   \p"
	.string "{JPN}わたしの うでまえを みたくなったら\n"
	.string "{JPN}いつでも きなさいよ!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "{JPN}いひひひ!\p"
	.string "{JPN}いまは そうみえないけど\n"
	.string "{JPN}わたし むかしは さいこうの\l"
	.string "{JPN}トレーナーだったのよ!\p"
	.string "{JPN}むてきの スイマーとして\n"
	.string "{JPN}ゆうめいだったのよ!\p"
	.string "{JPN}                       \p"
	.string "{JPN}どうしたの?\n"
	.string "{JPN}しんじられないのね?\p"
	.string "{JPN}むこうの ばかな おんなとは\n"
	.string "{JPN}ちがうのよ! わたし ほんとうに\l"
	.string "{JPN}けいけんが あるのよ!\n"
	.string "{JPN}しょうこを みせて あげるわ!\n"
	.string "{JPN}あなたの ポケモンに かたくて\l"
	.string "{JPN}きれいな わざを\l"
	.string "{JPN}おしえて あげる!\pでも ただでは おしえないわよ!\nわざを おしえるだいかに\lバトルポイントを\lすこし もらうわよ!$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "{JPN}いひひひ!\p"
	.string "{JPN}きびしくて きれいな ポケモンの\n"
	.string "{JPN}わざを ならいに きたのかい?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "{JPN}あの おんなのこたち おたがいの\n"
	.string "{JPN}わるぐちを いいあってるから\l"
	.string "{JPN}なかが わるいと おもうだろ?\p"
	.string "{JPN}でも ほんとうに なかが わるかったら\n"
	.string "{JPN}いっしょに ここに いないよね?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "{JPN}ぼくが ちいさな キッズだったころ\n"
	.string "{JPN}あの おねえさんたちは つよくて\l"
	.string "{JPN}うつくしかったんだ!\p"
	.string "{JPN}トレーナーの あいだでは\n"
	.string "{JPN}あこがれの そんざいだったよ!\p"
	.string "{JPN}いまでも としを とっても\n"
	.string "{JPN}のうりょくは おとろえてない!\p"
	.string "{JPN}じつは ポケモンの わざは\n"
	.string "{JPN}もっと みがきが かかってるんだ!\p"
	.string "{JPN}でも    なぜか ぼくには\n{JPN}こんな きもちが   \p{JPN}じかんって ざんこくだな   $"
BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "{JPN}じぶんの さいだい\n"
	.string "{JPN}HPの はんぶんまで\n"
	.string "{JPN}かいふく する$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "{JPN}じぶんの レベルと\n"
	.string "{JPN}おなじ ダメージを\n"
	.string "{JPN}あたえる$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "{JPN}ねむり じょうたいの\n"
	.string "{JPN}あいてに ダメージの\n"
	.string "{JPN}はんぶん かいふくする$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "{JPN}ものすごい ちからで\n"
	.string "{JPN}くりだす つよい\n"
	.string "{JPN}パンチ こうげき$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "{JPN}ものすごい ちからで\n"
	.string "{JPN}くりだす とても\n"
	.string "{JPN}つよい キック$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "{JPN}ぜんしんで あいてに\n"
	.string "{JPN}ぶつかって まひ\n"
	.string "{JPN}じょうたいにする$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "{JPN}おおきな いわを\n"
	.string "{JPN}なげつけて ひるませる\n"
	.string "{JPN}ことが ある$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "{JPN}ぶつり こうげきを\n"
	.string "{JPN}うけたとき ばいの\n"
	.string "{JPN}ちからで はんげき$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "{JPN}よわい でんきで\n"
	.string "{JPN}あいてを まひ\n"
	.string "{JPN}じょうたいに する$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "{JPN}たたかいの まいで\n"
	.string "{JPN}じぶんの こうげきを\n"
	.string "{JPN}おおきく あげる$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "{JPN}からだを まるめて\n"
	.string "{JPN}じゃくてんを かくし\n"
	.string "{JPN}ぼうぎょを あげる$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "{JPN}ねむっている ときに\n"
	.string "{JPN}だけ つかえる\n"
	.string "{JPN}おおごえの こうげき$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "{JPN}あいての かおに\n"
	.string "{JPN}どろを なげつけて\n"
	.string "{JPN}めいちゅうりつを さげる$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "{JPN}ほしがたの ひかりを\n"
	.string "{JPN}はっしゃして ぜったいに\n"
	.string "{JPN}めいちゅう させる$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "{JPN}つめたい かぜで\n"
	.string "{JPN}こうげきして あいての\n"
	.string "{JPN}すばやさを さげる$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "{JPN}どんな こうげきも\n"
	.string "{JPN}1ターンだけ HPを\n"
	.string "{JPN}1のこして たえる$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "{JPN}あいての のうりょく\n"
	.string "{JPN}へんかを じぶんに\n"
	.string "{JPN}コピーする$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "{JPN}つめたい パンチで\n"
	.string "{JPN}あいてを こおらせる\n"
	.string "{JPN}ことが ある$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "{JPN}でんきを まとった\n"
	.string "{JPN}パンチで あいてを\n"
	.string "{JPN}まひさせることがある$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "{JPN}ほのおの パンチで\n"
	.string "{JPN}あいてを やけど\n"
	.string "{JPN}させることがある$"

BattleFrontier_Lounge7_Text_ElementalTutorIntro::
	.string "{JPN}zzz   \p"
	.string "{JPN}なに? どう? なんだ?\p"
	.string "{JPN}ああ すまない すこし\n"
	.string "{JPN}いねむりを していたよ\p"
	.string "{JPN}わたしは エレメンタルチューター\n"
	.string "{JPN}なのだ!\p"
	.string "{JPN}くさ ほのお みずタイプの\n"
	.string "{JPN}ポケモンに さいきょうの わざを\l"
	.string "{JPN}おしえる ちからを もっている!\pそんな つよい ちからを\nまなびに きたのかね?$"

BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack:
	.string "{JPN}zzz   \p"
	.string "{JPN}なに? どう? なんだ? だれだ?\p"
	.string "{JPN}ああ わたしの さいきょうの わざの\n"
	.string "{JPN}ちからを まなびに きたのかね?$"

BattleFrontier_Lounge7_Text_TeachWhichMoveElemental::
	.string "{JPN}どの わざが きみの ポケモンに\n"
	.string "{JPN}ふさわしいと おもうかね?$"

BattleFrontier_Lounge7_Text_StrongElementalMoveDesc::
	.string "{JPN}きょうりょくだが\n"
	.string "{JPN}つかった あとは\n"
	.string "{JPN}1ターン うごけない$"
