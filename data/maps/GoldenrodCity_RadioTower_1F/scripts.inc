.set LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, 6
.set LOCALID_GOLDENROD_RADIOTOWER_GRUNT, 3
.set LOCALID_LOTTERY_CLERK, 2

GoldenrodCity_RadioTower_1F_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "{JPN}アカネ: こんにちは!\p"
	.string "{JPN}わたし アカネよ!\p"
	.string "{JPN}ラジオが もらえる クイズの\n"
	.string "{JPN}ことを きいて ここに きたの...\p"
	.string "{JPN}でも このクイズ とっても\n"
	.string "{JPN}むずかしいの!$"

RadioTower1F_Text_Whitney2::
	.string "{JPN}アカネ: すごいじゃない!\p"
	.string "{JPN}だいさんもんの こたえは\n"
	.string "{JPN}ぜったいに きのみだと おもった!\l"
	.string "{JPN}あらら!\p"
	.string "{JPN}ジムに もどる じかんね!$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_RADIO
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "{JPN}はじめまして！こちらは\n"
	.string "{JPN}グローバルトレードステーション\l"
	.string "{JPN}りゃくしてGTSです！\p"
	.string "{JPN}こちらでは\n"
	.string "{JPN}WiーFiコネクションをつかって\p"
	.string "{JPN}せかいじゅうのひとと\n"
	.string "{JPN}ポケモンのこうかんがたのしめます\p"
	.string "{JPN}ポケモングローバルこうかんを\n"
	.string "{JPN}ごきぼうですか？$"
RadioTower1F_Text_ReceptionistNoTours:
	.string "{JPN}こんにちは もうしわけ\nございませんがきょうは\lけんがくはやっておりません$"
RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "{JPN}いまは とくべつクイズ\n"
	.string "{JPN}キャンペーンちゅうなの.\p"
    .string "{JPN}ごもんを せいかいすると\n"
	.string "{JPN}ラジオが もらえるのよ.\p"
    .string "{JPN}あなたと あなたのポケモンが\n"
	.string "{JPN}いつでも どこでも おんがくを\l"
    .string "{JPN}たのしめるわ.\pクイズに ちょうせん してみる?$"

RadioTower1F_Text_QuizQuestion1:
	.string "{JPN}だい1もん！\pひるまにしかでてこない\nポケモンはいる？$"
RadioTower1F_Text_QuizQuestion2:
	.string "{JPN}せいかい！\nだい2もん！\pつぎのぶんしょうは\nただしいでしょうか？\pフレンドリィショップでは\nきのみはうっていない$"
RadioTower1F_Text_QuizQuestion3:
    .string "{JPN}せいかい!\n"
	.string "{JPN}だいさんもん:\p"
    .string "{JPN}ポケボールを つくるひと\n"
	.string "{JPN}ガンテツは きのみを ざいりょうに\lつかう?$"

RadioTower1F_Text_QuizQuestion4:
    .string "{JPN}いまのところ じゅんちょうね!\n"
	.string "{JPN}だいよんもん:\p"
    .string "{JPN}ハヤトは キキョウジムリーダーで\n"
	.string "{JPN}ひこうタイプの ポケモンを\lつかう?$"

RadioTower1F_Text_QuizQuestion5:
	.string "{JPN}おお！またせいかい！\nさいごのもんだいです！\pコガネゲームコーナーの\nスロットのリールには\nヒトカゲがある？$"
RadioTower1F_Text_QuizWin:
	.string "{JPN}ビンゴ！せいかいです！\nおめでとうございます！\pしょうひんのラジオです！$"
RadioTower1F_Text_PokegearRadio:
	.string "{JPN}{PLAYER}のポケギアに\nラジオきのうがついた！$"
RadioTower1F_Text_TuneIn:
	.string "{JPN}ラジオばんぐみを\nきいてくださいね！$"
RadioTower1F_Text_WrongAnswer:
	.string "{JPN}あらまあ.\nざんねんですがまちがいです\pまたちょうせんしてくださいね！$"
RadioTower1F_Text_DeclineQuiz:
    .string "{JPN}はいはい..いいえなのね\n"
	.string "{JPN}わかりましたよ\l"
	.string "{JPN}きがむいたらまたおいでなさいよ$"
RadioTower1F_Text_Lass:
	.string "{JPN}ベンってすてきなDJなの\pあまいこえにうっとりしちゃう！$"
RadioTower1F_Text_Youngster:
	.string "{JPN}ぼくポケモンだいすきクラブの\nメアリーがだいすきなんだ\pこえしかしらないけどね$"
RadioTower1F_Text_GruntM3Seen:
	.string "{JPN}ついにラジオとうを\nのっとったぞ！\pみんなにロケットだんの\nほんとうのおそろしさを\nあじわわせてやる！\pおれたちのおそろしさを\nおしえてやるぜ！$"
RadioTower1F_Text_GruntM3Beaten:
	.string "{JPN}つよすぎる！ボス.すみません.$"
RadioTower1F_Text_GruntM3After:
	.string "{JPN}きみはつよすぎる\pさくせんがだいなしになる\nなかまにしらせなければ.$"
RadioTower1F_Text_Directory:
	.string "{JPN}1F うけつけ\n2F えいぎょう\p3F じんじ\n4F せいさく\p5F しゃちょうしつ$"
GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	@special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	@special EndLotteryCornerComputerEffect
	delay 10
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "{JPN}ここはポケモンくじコーナーです\pくじのばんごうがきみの\nポケモンのIDばんごうと\lいっちすればすてきなしょうひんを\nプレゼント！\pポケモンくじをひいてみますか？$"
GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "{JPN}またあしたきてくださいね$"
GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "{JPN}それではまたおこしください$"
GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "{JPN}くじをひいてください\n...$"
GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "{JPN}くじのばんごうは{STR_VAR_1}です\pこのばんごうがきみの\nポケモンのIDばんごうと\lいっちするかしらべますので\nしょうしょうおまちください$"
GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "{JPN}おめでとうございます！\nてもちの{STR_VAR_1}の\nIDばんごうがくじの\lばんごうといっちしました！$"
GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "{JPN}おめでとうございます！\nパソコンのボックスにいる\n{STR_VAR_1}のIDばんごうが\lくじのばんごうといっちしました！$"
GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "{JPN}ざんねんです\nばんごうはいっちしませんでした$"
GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "{JPN}にけたあたり！\nさんとうしょうです！\lおめでとうございます！\n{STR_VAR_1}のかちです！$"
GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "{JPN}さんけたあたり！\nにとうしょうです！\lおめでとうございます！\n{STR_VAR_1}のかちです！$"
GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "{JPN}よんけたあたり！\nいっとうしょうです！\lおめでとうございます！\n{STR_VAR_1}のかちです！$"
GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "{JPN}わあ！ごけたぜんぶ\nあたりです！\pだいとうりょう！\n{STR_VAR_1}のかちです！$"
GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "{JPN}あら？\nもちものがいっぱいですね\pバッグにばしょをつくって\nまたきてくださいね$"
GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{JPN}{PLAYER}さん？\nおまちしてましたよ\pこれがおあずかりしていた\nけいひんです$"
GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "{JPN}それではまたおこしください$"

