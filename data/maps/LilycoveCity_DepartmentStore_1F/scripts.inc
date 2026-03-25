.set LOCALID_LOTTERY_CLERK, 2

LilycoveCity_DepartmentStore_1F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
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
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_TraderWoman::
	msgbox LilycoveCity_DepartmentStore_1F_TraderWoman_Text, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_Machine::
	playse SE_PC_ON
	delay 40
	checkmoney 10000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq SCRIPT_SelfTrade_V1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_DepartmentStore_1F_Machine_NoMoney
	end

LilycoveCity_DepartmentStore_1F_Machine_NoMoney::
	msgbox LilycoveCity_DepartmentStore_1F_Machine_NoMoney_Text, MSGBOX_NPC
	end

SCRIPT_SelfTrade_V1::
	lock
	faceplayer
	msgbox SCRIPT_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	removemoney 10000, 0
	msgbox SCRIPT_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_V2::
	lock
	faceplayer
	msgbox SCRIPT_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 7
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setvar VAR_0x8004, 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox SCRIPT_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_DeclineTrade::
	msgbox SCRIPT_SelfTrade_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_Text_IllTradeIfYouWant:
	.string "{JPN}デボンコーポレーション\n"
	.string "{JPN}セルフトレーダー アプリへ\l"
	.string "{JPN}ようこそ.\p"
	.string "{JPN}あなたの ポケモンを\n"
	.string "{JPN}じぶんで こうかんします.\l"
	.string "{JPN}いちかいの りようりょうは\l10000えん です.\pポケモンの せんたくがめんに\nすすみますか?$"

SCRIPT_SelfTrade_Text_ComeBack:
	.string "{JPN}デボンコーポレーションの\n"
	.string "{JPN}しょうひんを ごりようください\lまして ありがとうございます.$"

SCRIPT_SelfTrade_Text_YouDontWantToThatsOkay:
	.string "{JPN}デボンコーポレーションの\n"
	.string "{JPN}しょうひんを ごりようくださり\lありがとうございます.$"

LilycoveCity_DepartmentStore_1F_Machine_NoMoney_Text:
	.string "{JPN}もうしわけございません.\n"
	.string "{JPN}おかねが たりません.\l"
	.string "{JPN}いちかい りようするのに\l"
	.string "{JPN}10000えんが ひつようです.\pデボンコーポレーションの\nしょうひんを ごりようくださり\lありがとうございます.$"

LilycoveCity_DepartmentStore_1F_TraderWoman_Text:
	.string "{JPN}ミナモデパートへ\n"
	.string "{JPN}ようこそ!\p"
	.string "{JPN}デボンコーポレーションが\n"
	.string "{JPN}かいはつした あたらしい\l"
	.string "{JPN}ぎじゅつについて\l"
	.string "{JPN}おしりに なりますか?\p"
	.string "{JPN}セルフトレーダー アプリ\n"
	.string "{JPN}です!\p"
	.string "{JPN}かんたんな コンピューター\n"
	.string "{JPN}プログラムの おかげで\l"
	.string "{JPN}ポケモンを いっぴき\l"
	.string "{JPN}デボンコーポレーションの\l"
	.string "{JPN}サーバーに おくって\l"
	.string "{JPN}すうびょうで もどして\l"
	.string "{JPN}もらえるのです!\p"
	.string "{JPN}これにより とくていの\n"
	.string "{JPN}ポケモンの しんかじょうけんを\l"
	.string "{JPN}はっせいさせることが\l"
	.string "{JPN}できます.\p"
	.string "{JPN}ただし このような\nふくざつな システムの\lいじには おかねが\lかかります.\pしょうがいライセンスを\n1000000えんで こうにゅう\lするか まいかい 10000えんで\lりようするか えらべます.\pためしに つかってみたい\nばあいは みぎにある\lコンピューターを\lつかってください!\pデボンコーポレーションの\nしょうひんを ごりようくださり\lありがとうございます!$"

LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
	.string "{JPN}ミナモデパートへ ようこそ.$"

LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
	.string "{JPN}デパートに くると\n"
	.string "{JPN}たのしくて いつも いろんな\l"
	.string "{JPN}ものを かってしまうのよね.$"

LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
	.string "{JPN}きょうは おかあさんが\n"
	.string "{JPN}すてきな かぐを\lかってくれるの.$"

LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
	.string "{JPN}コンテストで かったときの\n"
	.string "{JPN}ごほうびに マリルリに\lなにか かってあげるの.$"

LilycoveCity_DepartmentStore_1F_Text_Azumarill:
	.string "{JPN}マリルリ: マリリルー!$"

LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
	.string "{JPN}1F: サービスカウンター\n"
	.string "{JPN}     ふくびきコーナー\p"
	.string "{JPN}2F: トレーナーズコーナー\p"
	.string "{JPN}3F: バトルコレクション\p"
	.string "{JPN}4F: わざマシンコーナー\p"
	.string "{JPN}5F: ポケモンにんぎょうフロア\p"
	.string "{JPN}おくじょう: スカイガーデン$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
	.string "{JPN}ワイヤレスつうしんって\n"
	.string "{JPN}とても たのしいですよね?\p"
	.string "{JPN}いままで できなかった\n"
	.string "{JPN}ことが できるように\l"
	.string "{JPN}なったと おもいます.\p"
	.string "{JPN}たとえば いままで\n"
	.string "{JPN}こうかんできなかった\lひとと こうかんできたり.\pこれから わくわく\nしますね!$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
	.string "{JPN}ワイヤレスつうしんの\n"
	.string "{JPN}たのしさを ひろめて\lいきたいです.$"

