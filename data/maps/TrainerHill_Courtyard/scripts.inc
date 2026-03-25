TrainerHill_Courtyard_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "{JPN}わあ トレーナーヒルって\n"
	.string "{JPN}でっかいね!\p"
	.string "{JPN}あの なかには いろんな\nしゅるいの ポケモンが\nいるんだろうなあ!$"

BattleTowerOutsideBeautyText:
	.string "{JPN}バトルテントでは\n"
	.string "{JPN}ポケモンを3ひきしか\l"
	.string "{JPN}つかえないの.\p"
	.string "{JPN}どの3ひきを\nせんとうにださせるか\lきめるのがたいへんで...$"
BattleTowerOutsideSailorText:
	.string "{JPN}へへへ しごとを\n"
	.string "{JPN}さぼっちゃった.\p"
	.string "{JPN}かつまでは ぜったい\nかえれないよ!\pぜんぶ かたなきゃ\nだめなんだ!$"

BattleTowerOutsideSignText:
	.string "{JPN}{UP_ARROW} トレーナーヒル いりぐち\p"
	.string "{JPN}のぼれ! あつきこころの\n"
	.string "{JPN}トレーナーたちよ!\p"
	.string "{JPN}{RIGHT_ARROW} バトルテント.$"

BattleTower_Battle_Tent_Text_Factory:
	.string "{JPN}バトルテント:ファクトリー\n"
	.string "{JPN}みつけろ! きゅうきょくの ポケモン!$"

BattleTower_Battle_Tent_Text_Palace:
	.string "{JPN}バトルテント:パレス\n"
	.string "{JPN}みよ! たたかいの うつくしさを!$"

BattleTower_Battle_Tent_Text_Arena:
	.string "{JPN}バトルテント:アリーナ\n"
	.string "{JPN}さいきょうの チーム あつまれ!$"

BattleTowerOutsideText_Closed:
	.string "{JPN}トレーナーヒルは げんざい\n"
	.string "{JPN}しゅうりのため へいかん\nしています.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor
	msgbox TrainerHill_Courtyard_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor::
	msgbox TrainerHill_Courtyard_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor
	msgbox TrainerHill_Courtyard_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor::
	msgbox TrainerHill_Courtyard_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor
	msgbox TrainerHill_Courtyard_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor::
	msgbox TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_EventScript_CancelChooseMon::
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
TrainerHill_Courtyard_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_EventScript_TeachTutorMove
	msgbox TrainerHill_Courtyard_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseNewMove
	end

TrainerHill_Courtyard_EventScript_TeachTutorMove::
	msgbox TrainerHill_Courtyard_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_EventScript_CancelChooseMon
	msgbox TrainerHill_Courtyard_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

TrainerHill_Courtyard_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove
	goto TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove
	end

TrainerHill_Courtyard_Text_LeftTutorIntro:
	.string "{JPN}ぶはははは!\p"
	.string "{JPN}いまのすがたからは\n"
	.string "{JPN}そうぞうできないでしょうが\l"
	.string "{JPN}わたしはむかし\l"
	.string "{JPN}つよいトレーナーだったのよ!\p"
	.string "{JPN}いちばんつよいビューティー\n"
	.string "{JPN}としてゆうめいだったの!\p"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}なによ?\n"
	.string "{JPN}しんじられないっていうの?\p"
	.string "{JPN}あっちにいるほらふきおんなとは\n"
	.string "{JPN}ちがうのよ.\l"
	.string "{JPN}わたしはほんとうにうでがたつの!\p"
	.string "{JPN}それをしょうめいしてあげる.\n"
	.string "{JPN}あなたのポケモンに\l"
	.string "{JPN}とくべつでかわいいわざを\lおしえてあげられるのよ.\pでもただじゃないわ.\nおしえるわざのだいきんを\lバトルポイントで\lはらってくれる?$"

TrainerHill_Courtyard_Text_LeftTutorWelcomeBack:
	.string "{JPN}ぶはははは!\p"
	.string "{JPN}とくべつで かわいい\n"
	.string "{JPN}ポケモンの わざを\nおそわりに もどってきたのか?$"

TrainerHill_Courtyard_Text_TeachWhichMove:
	.string "{JPN}よし よし みてみろ!\n"
	.string "{JPN}どの わざを おしえようか?$"

TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints:
	.string "{JPN}{STR_VAR_1}だな?\n"
	.string "{JPN}それは {STR_VAR_2}バトルポイント\nだが いいか?$"

TrainerHill_Courtyard_Text_TeachMoveToWhichMon:
	.string "{JPN}よし よし つぎは\n"
	.string "{JPN}どの ポケモンに わざを\nおしえるか えらんでくれ.$"

TrainerHill_Courtyard_Text_HaventGotEnoughPoints:
	.string "{JPN}なんですって...\n"
	.string "{JPN}バトルポイントが\nたりないじゃない!$"

TrainerHill_Courtyard_Text_IllTakeBattlePoints:
	.string "{JPN}わたしの うでまえを\n"
	.string "{JPN}みたろう?\nバトルポイント いただくぞ!$"

TrainerHill_Courtyard_Text_YouDontWantTo:
	.string "{JPN}なんですって?\n"
	.string "{JPN}やりたくないって...\p"
	.string "{JPN}わたしのうでまえを\n"
	.string "{JPN}みたくなったら\lいつでもきなさい!$"

TrainerHill_Courtyard_Text_RightTutorIntro:
	.string "{JPN}いひひひ!\p"
	.string "{JPN}いまはこんなふうけいだけど\n"
	.string "{JPN}むかしはすばらしい\l"
	.string "{JPN}トレーナーだったのよ!\p"
	.string "{JPN}さいきょうのスイマーとして\n"
	.string "{JPN}ゆうめいだったんだから!\p"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}どうしたの?\n"
	.string "{JPN}しんじてくれないのね.\p"
	.string "{JPN}あっちにいるばかげたおんなとは\n"
	.string "{JPN}ちがうのよ.\l"
	.string "{JPN}わたしはほんとうにけいけんが\l"
	.string "{JPN}あるんだから!\p"
	.string "{JPN}それをしょうめいしてあげる.\n"
	.string "{JPN}あなたのポケモンに\l"
	.string "{JPN}つよくてきれいなわざを\lおしえることができるの.\pでもただじゃないわ.\nおしえるわざのだいきんを\lバトルポイントで\lはらってくれる?$"

TrainerHill_Courtyard_Text_RightTutorWelcomeBack:
	.string "{JPN}いひひひ!\n"
	.string "{JPN}かたくて きれいな\n"
	.string "{JPN}ポケモンの わざを\nならいに きたのかい?$"

TrainerHill_Courtyard_Text_ThinkLadiesDontGetAlong:
	.string "{JPN}あの ふたり おたがいの\n"
	.string "{JPN}わるぐちばかり いってるから\l"
	.string "{JPN}なかが わるいと おもうだろう?\p"
	.string "{JPN}でも ほんとうに なかが\n"
	.string "{JPN}わるかったら いっしょに\nここに いないと おもうよ.$"

TrainerHill_Courtyard_Text_LadiesWereStrongAndBeautiful:
	.string "{JPN}わたしがまだちいさな\n"
	.string "{JPN}たんぱんこぞうだったとき\l"
	.string "{JPN}あのふたりはつよくて\l"
	.string "{JPN}うつくしかったんだ.\p"
	.string "{JPN}トレーナーたちのあこがれ\n"
	.string "{JPN}だったんだよ.\p"
	.string "{JPN}いまでも としはとったけど\n"
	.string "{JPN}うでまえはおとろえていない.\p"
	.string "{JPN}じっさい ポケモンのわざは\n"
	.string "{JPN}もっとみがかれているよ.\pでも... どうしてだろう...\nこんなきもちになるのは...\pときのながれって\nざんこくだなあ...$"
TrainerHill_Courtyard_Text_SoftboiledDesc::
	.string "{JPN}じぶんの さいだい\n"
	.string "{JPN}HPの はんぶんまで\n"
	.string "{JPN}かいふく する.$"

TrainerHill_Courtyard_Text_SeismicTossDesc::
	.string "{JPN}つかうがわの\n"
	.string "{JPN}レベルと おなじ\n"
	.string "{JPN}ダメージを あたえる.$"

TrainerHill_Courtyard_Text_DreamEaterDesc::
	.string "{JPN}ねむっている あいてに\n"
	.string "{JPN}あたえた ダメージの\n"
	.string "{JPN}はんぶんを かいふく.$"

TrainerHill_Courtyard_Text_MegaPunchDesc::
	.string "{JPN}すさまじい ちからで\n"
	.string "{JPN}くりだす\n"
	.string "{JPN}つよい パンチ.$"

TrainerHill_Courtyard_Text_MegaKickDesc::
	.string "{JPN}ものすごい ちからで\n"
	.string "{JPN}あいてを ける\n"
	.string "{JPN}きょうりょくな キック.$"

TrainerHill_Courtyard_Text_BodySlamDesc::
	.string "{JPN}ぜんしんで あいてに\n"
	.string "{JPN}たいあたりして\n"
	.string "{JPN}まひさせることがある.$"

TrainerHill_Courtyard_Text_RockSlideDesc::
	.string "{JPN}おおきな いわを\n"
	.string "{JPN}らっかさせて こうげき.\n"
	.string "{JPN}ひるませることがある.$"

TrainerHill_Courtyard_Text_CounterDesc::
	.string "{JPN}ぶつり こうげきを\n"
	.string "{JPN}うけたとき その\n"
	.string "{JPN}2ばいの いりょくで はんげき.$"

TrainerHill_Courtyard_Text_ThunderWaveDesc::
	.string "{JPN}よわい でんきを\n"
	.string "{JPN}あびせかけて\n"
	.string "{JPN}あいてを まひさせる.$"

TrainerHill_Courtyard_Text_SwordsDanceDesc::
	.string "{JPN}たたかいの まいを\n"
	.string "{JPN}おどって じぶんの\n"
	.string "{JPN}こうげきりょくを あげる.$"

TrainerHill_Courtyard_Text_DefenseCurlDesc::
	.string "{JPN}からだを まるめて\n"
	.string "{JPN}じゃくてんを かくし\n"
	.string "{JPN}ぼうぎょりょくを あげる.$"

TrainerHill_Courtyard_Text_SnoreDesc::
	.string "{JPN}ねむっている\n"
	.string "{JPN}あいだだけ つかえる\n"
	.string "{JPN}おおきな こえの こうげき$"

TrainerHill_Courtyard_Text_MudSlapDesc::
	.string "{JPN}あいての かおに\n"
	.string "{JPN}どろを なげつけて\n"
	.string "{JPN}めいちゅうを さげる$"

TrainerHill_Courtyard_Text_SwiftDesc::
	.string "{JPN}ほしのかたちの\n"
	.string "{JPN}ひかりを はっしゃして\n"
	.string "{JPN}かならず あたる$"

TrainerHill_Courtyard_Text_IcyWindDesc::
	.string "{JPN}つめたい かぜで\n"
	.string "{JPN}こうげきして\n"
	.string "{JPN}あいての すばやさを さげる$"

TrainerHill_Courtyard_Text_EndureDesc::
	.string "{JPN}どんな こうげきでも\n"
	.string "{JPN}1ターン たえて\n"
	.string "{JPN}HP 1で のこる$"

TrainerHill_Courtyard_Text_PsychUpDesc::
	.string "{JPN}あいての のうりょく\n"
	.string "{JPN}へんかを コピーして\n"
	.string "{JPN}じぶんに かける$"

TrainerHill_Courtyard_Text_IcePunchDesc::
	.string "{JPN}つめたい パンチで\n"
	.string "{JPN}こうげき あいてを\n"
	.string "{JPN}こおらせることがある$"

TrainerHill_Courtyard_Text_ThunderPunchDesc::
	.string "{JPN}でんきを こめた\n"
	.string "{JPN}パンチで こうげき\n"
	.string "{JPN}まひさせることがある$"

TrainerHill_Courtyard_Text_FirePunchDesc::
	.string "{JPN}ほのおの パンチで\n"
	.string "{JPN}こうげき あいてを\n"
	.string "{JPN}やけどさせることがある$"

TrainerHill_Courtyard_Text_ElementalTutorIntro::
	.string "{JPN}zzzzz...\p"
	.string "{JPN}なに なに なに?\p"
	.string "{JPN}あ ごめん\n"
	.string "{JPN}ちょっとうとうとしてた.\p"
	.string "{JPN}わたしはエレメンタルせんせい.\p"
	.string "{JPN}くさ ほのお みずタイプの\n"
	.string "{JPN}ポケモンにさいきょうのわざを\l"
	.string "{JPN}おしえるちからをもっている.\p"
	.string "{JPN}そんなつよいちからを\nまなびにきたのかい?$"

TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack:
	.string "{JPN}zzzzz...\p"
	.string "{JPN}なに なに なに だれ?\p"
	.string "{JPN}あ さいきょうのわざの\n"
	.string "{JPN}ちからをまなびにきたのかい?$"

TrainerHill_Courtyard_Text_TeachWhichMoveElemental::
	.string "{JPN}どの わざが あなたの\n"
	.string "{JPN}ポケモンに ふさわしいと おもいますか?$"

TrainerHill_Courtyard_Text_StrongElementalMoveDesc::
	.string "{JPN}きょうりょくだが\n"
	.string "{JPN}つぎのターン\n"
	.string "{JPN}うごけなくなる$"

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
	.string "{JPN}そのアイテムは すでに もっています$"

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "{JPN}こんにちは! ふしぎなこうかんを\n"
	.string "{JPN}おさがしでしたら いまは すべての\l"
	.string "{JPN}\nポケモンセンターに ありますよ!\pたのしんでくださいね!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "{JPN}いらっしゃいませ こちらは\n"
	.string "{JPN}こうかんサービスコーナーです\p"
	.string "{JPN}あつめた バトルポイントを\n"
	.string "{JPN}すてきな しょうひんと\l"
	.string "{JPN}こうかんしています\pこのリストから しょうひんを\nえらんでください$"

@ Unused
TrainerHill_Courtyard_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "{JPN}このリストから しょうひんを\nえらんでください$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "{JPN}キスポスターを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "{JPN}キスクッションを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "{JPN}ムチュールにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "{JPN}トゲピーにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "{JPN}ニャースにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "{JPN}ピッピにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "{JPN}メタモンにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "{JPN}ヒノアラシにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "{JPN}チコリータにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "{JPN}ワニノコにんぎょうを\n"
	.string "{JPN}えらばれましたね\nよろしいですか?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "{JPN}ラプラスのにんぎょうを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "{JPN}カビゴンのにんぎょうを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "{JPN}フシギバナのにんぎょうを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "{JPN}リザードンのにんぎょうを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "{JPN}カメックスのにんぎょうを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "{JPN}タウリンを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "{JPN}リゾチウムを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron:
	.string "{JPN}ブロムヘキシンを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "{JPN}キトサンを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "{JPN}インドメタシンを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp:
	.string "{JPN}マックスアップを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "{JPN}ひかりのこなを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "{JPN}しろいハーブを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "{JPN}せんせいのツメを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "{JPN}メンタルハーブを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "{JPN}こだわりハチマキを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "{JPN}おうじゃのしるしを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "{JPN}きあいのハチマキを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "{JPN}ピントレンズを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "{JPN}たべのこしを\n"
	.string "{JPN}えらびましたね?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "{JPN}ありがとうございます!\n"
	.string "{JPN}パソコンにおくりますね$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "{JPN}しょうひんをどうぞ!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "{JPN}もうしわけございません...\n"
	.string "{JPN}バトルポイントが\nたりません...$"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull:
	.string "{JPN}もうしわけございません...\n"
	.string "{JPN}パソコンがいっぱいのようです...$"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "{JPN}もうしわけございません...\n"
	.string "{JPN}もつばしょがありません...$"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "{JPN}ありがとうございました\p"
	.string "{JPN}バトルポイントがたまったら\n"
	.string "{JPN}またきてくださいね$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "{JPN}ああ!とってもすてき!\n"
	.string "{JPN}わたしもほしいな!\l"
	.string "{JPN}かわいいクッション!\l"
	.string "{JPN}おおきなぬいぐるみ!\l"
	.string "{JPN}ちいさなぬいぐるみ!\l"
	.string "{JPN}ぜんぶほしいわあ!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "{JPN}おかあさんにまかせて!\p"
	.string "{JPN}あなたのほしいものなら\n"
	.string "{JPN}なんでもてにいれてあげる!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "{JPN}ここのアイテムを てにいれたら\n"
	.string "{JPN}おれの ポケモンは つよくなる.\p"
	.string "{JPN}もちろん つよくなるぞ!\n"
	.string "{JPN}まちがいなしだ!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "{JPN}はあ?\n"
	.string "{JPN}なに みてるんだ?\p"
	.string "{JPN}あたしの ぬいぐるみを\n"
	.string "{JPN}そんなに みつめないでよ.\p"
	.string "{JPN}ほしいなら じぶんで とりなさい!\n"
	.string "{JPN}そうよね ムチュール?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "{JPN}しってる?\p"
	.string "{JPN}バトルしせつで きろくを のばすと\n"
	.string "{JPN}どんどん たくさんの\l"
	.string "{JPN}バトルポイントが もらえるのよ.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "{JPN}ムチュールが かかれた\nおおきな ポスター.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "{JPN}ムチュールの クッション.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "{JPN}ムチュールの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "{JPN}トゲピーの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "{JPN}ニャースの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "{JPN}ピッピの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "{JPN}メタモンの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "{JPN}ヒノアラシの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "{JPN}チコリータの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "{JPN}ワニノコの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "{JPN}おおきな ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに おける.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ProteinDesc::
	.string "{JPN}はなれじまに いくことが\n"
	.string "{JPN}できる ふしぎな チケット$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CalciumDesc::
	.string "{JPN}はいきょされた しまへ\n"
	.string "{JPN}つれていってくれる ふしぎなチケット.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_IronDesc::
	.string "{JPN}はいきょされた しまへ\n"
	.string "{JPN}つれていってくれる ふしぎなチケット.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ZincDesc::
	.string "{JPN}ふるい... ちず?\n"
	.string "{JPN}どこかへいけるかも.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CarbosDesc::
	.string "{JPN}EV 10ばい しゅとく.\nただし すばやさが はんぶん.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HPUpDesc::
	.string "{JPN}シルフカンパニーが つくった\n"
	.string "{JPN}きみょうな はこ.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "{JPN}せんとうちゅう HPを すこしずつ\n"
	.string "{JPN}かいふくする もちもの.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "{JPN}さがった のうりょくを\n"
	.string "{JPN}もとにもどす もちもの.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "{JPN}たまに せんせい こうげきが\n"
	.string "{JPN}できる もちもの.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "{JPN}ポケモンの メロメロを\n"
	.string "{JPN}なおす もちもの.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "{JPN}ひかりで てきの めいちゅうりつを\n"
	.string "{JPN}さげる もちもの.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "{JPN}わざの いりょくは あがるが\n"
	.string "{JPN}そのわざしか つかえない.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "{JPN}あいてを ひるませることが\n"
	.string "{JPN}ある もちもの$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "{JPN}ひんしを まれに\n"
	.string "{JPN}ふせぐ もちもの$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "{JPN}きゅうしょりつを\n"
	.string "{JPN}あげる もちもの$"
