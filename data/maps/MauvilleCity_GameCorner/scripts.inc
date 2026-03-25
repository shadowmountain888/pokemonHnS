MauvilleCity_GameCorner_MapScripts::
	.byte 0

    @ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000
	.set DOLL_COINS, 1000
	.set DOLL2_COINS,  9000

	.set COINS_PRICE_50,  500
	.set COINS_PRICE_500, 5000
	.set COINS_PRICE_1000, 10000
	.set COINS_PRICE_2500, 25000
	.set COINS_PRICE_5000, 50000

MauvilleCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomFor50CoinsBeginning
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoneyBeginning
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault1000::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 2, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault2500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 3, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault5000::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 4, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500
	end

MauvilleCity_GameCorner_EventScript_Buy1000Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 1000), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_1000
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 1000
	removemoney COINS_PRICE_1000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault1000
	end

MauvilleCity_GameCorner_EventScript_Buy2500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 2500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_2500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 2500
	removemoney COINS_PRICE_2500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault2500
	end

MauvilleCity_GameCorner_EventScript_Buy5000Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 5000), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_5000
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 5000
	removemoney COINS_PRICE_5000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault5000
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoneyBeginning::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoneyFor50, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoneyFor50, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	goto_if_set FLAG_TEMP_2, MauvilleCity_GameCorner_EventScript_ThanksBuyCoins
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_ThanksBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_ThanksBuyCoins, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomFor50CoinsBeginning::
	msgbox MauvilleCity_GameCorner_Text_NoRoomFor50Coins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins::
	msgbox MauvilleCity_GameCorner_Text_NoRoomFor50Coins, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins
	msgbox MauvilleCity_GameCorner_Text_NoRoomForCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls2::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage2
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage2::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize2

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize2

MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrize2::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS2, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_RegirockDoll
	case 1, MauvilleCity_GameCorner_EventScript_RegiceDoll
	case 2, MauvilleCity_GameCorner_EventScript_RegisteelDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_TreeckoDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TorchicDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MudkipDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_RegirockDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_REGIROCK_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2

MauvilleCity_GameCorner_EventScript_RegiceDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_REGIROCK_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2

MauvilleCity_GameCorner_EventScript_RegisteelDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_REGIROCK_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyRegirockDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyRegiceDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyRegisteelDoll
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyRegirockDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL2_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2
	bufferdecorationname STR_VAR_2, DECOR_REGIROCK_DOLL
	checkdecorspace DECOR_REGIROCK_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll2
	removecoins DOLL2_COINS
	adddecoration DECOR_REGIROCK_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_BuyRegiceDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL2_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2
	bufferdecorationname STR_VAR_2, DECOR_REGICE_DOLL
	checkdecorspace DECOR_REGICE_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll2
	removecoins DOLL2_COINS
	adddecoration DECOR_REGICE_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_BuyRegisteelDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL2_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2
	bufferdecorationname STR_VAR_2, DECOR_REGISTEEL_DOLL
	checkdecorspace DECOR_REGISTEEL_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll2
	removecoins DOLL2_COINS
	adddecoration DECOR_REGISTEEL_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll2::
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_CancelDollSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
	end

MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMPsychic::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto_if_unset FLAG_FINITE_TMS, MauvilleCity_GameCorner_EventScript_ConfirmTMPrizeInfinite
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam
	case 2, MauvilleCity_GameCorner_EventScript_BuyTMPsychic
	case 3, MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower
	case 4, MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt
	case 5, MauvilleCity_GameCorner_EventScript_BuyTMIceBeam
	end

MauvilleCity_GameCorner_EventScript_ConfirmTMPrizeInfinite::
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTM32InfiniteDoubleTeam
	case 2, MauvilleCity_GameCorner_EventScript_BuyTM29InfinitePsychic
	case 3, MauvilleCity_GameCorner_EventScript_BuyTM35InfiniteFlamethrower
	case 4, MauvilleCity_GameCorner_EventScript_BuyTM24InfiniteThunderbolt
	case 5, MauvilleCity_GameCorner_EventScript_BuyTM13InfiniteIceBeam
	end

MauvilleCity_GameCorner_EventScript_BuyTM32InfiniteDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_DOUBLE_TEAM, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM29InfinitePsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_PSYCHIC, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM35InfiniteFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_FLAMETHROWER, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM24InfiniteThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_THUNDERBOLT, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM13InfiniteIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_ICE_BEAM, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins  TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_DOUBLE_TEAM
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMPsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_PSYCHIC
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_ICE_BEAM
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis::
    msgbox gText_YouAlreadyHaveThis, MSGBOX_AUTOCLOSE
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_CancelTMSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "{JPN}ここは ゲームコーナーです$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "{JPN}そうですね ゲームようの\n"
	.string "{JPN}コインが ほしいのですね?\p"
	.string "{JPN}でも コインを いれる\n"
	.string "{JPN}コインケースを もっていませんね$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
	.string "{JPN}コインを おさがしですか?\p"
	.string "{JPN}50まい 500えんです\n"
	.string "{JPN}いかがですか?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "{JPN}ありがとうございます!\n"
	.string "{JPN}コインを どうぞ!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoneyFor50:
	.string "{JPN}あの   コインを\n"
	.string "{JPN}かうおかねが\l"
	.string "{JPN}たりないようですが   \p"
	.string "{JPN}1000えん いじょう\nもってから\lまたきてくださいね!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "{JPN}あの   そのまいすうの\n"
	.string "{JPN}コインを かうには\lおかねが たりないですね   $"
MauvilleCity_GameCorner_Text_NoRoomFor50Coins:
	.string "{JPN}あ! コインケースが いっぱいで\n"
	.string "{JPN}コインが はいりません!\p"
	.string "{JPN}コガネゲームコーナーを たのしむか\n"
	.string "{JPN}コインを しょうひんと こうかんしてから\l"
	.string "{JPN}また きてください!$"

MauvilleCity_GameCorner_Text_NoRoomForCoins:
	.string "{JPN}あら?\n"
	.string "{JPN}コインケースに はいりませんね...$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "{JPN}あ   コインは\n"
	.string "{JPN}いらないんですね?\lぼうけん がんばってね!$"

MauvilleCity_GameCorner_Text_ThanksBuyCoins:
	.string "{JPN}コインを かってくれて\n"
	.string "{JPN}ありがとうございます!\nぼうけん がんばってください!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "{JPN}いらっしゃいませ\p"
	.string "{JPN}コインを しょうひんと\n"
	.string "{JPN}こうかん できますよ$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "{JPN}どの しょうひんに しますか?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "{JPN}では {STR_VAR_1}{STR_VAR_2}で\n"
	.string "{JPN}よろしいですね?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC:
	.string "{JPN}ありがとうございます!\n"
	.string "{JPN}パソコンに おくって おきますね$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "{JPN}コインが たりませんね$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "{JPN}{STR_VAR_1}を おく\n"
	.string "{JPN}ばしょが ありませんね$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "{JPN}あ そうですか?\n"
	.string "{JPN}コインを ためてから\l"
	.string "{JPN}また きてくださいね$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "{JPN}では {STR_VAR_1}で\nよろしいですね?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "{JPN}はい どうぞ!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "{JPN}あら これいじょう もてませんね$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "{JPN}まちがえて おなじ にんぎょうを\n"
	.string "{JPN}2つ かってしまいました\p"
	.string "{JPN}ひとつ いりませんか?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "{JPN}はい どうぞ!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "{JPN}え?\n"
	.string "{JPN}ほしいけど いまは いらない?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "{JPN}まあ そんなこと いわないで!\n"
	.string "{JPN}これを あげますよ!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "{JPN}ほしい しょうひんが あるんだけど\n"
	.string "{JPN}だいとうりょうが でないんだ$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "{JPN}ぼうや ここで あそぶなら\n"
	.string "{JPN}コインケースが いるぞ\p"
	.string "{JPN}となりの おねえさんが\n"
	.string "{JPN}もってたと おもうぞ! いってみな!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "{JPN}つきも ながくは つづかないからな\n"
	.string "{JPN}これは おおすぎるよ\l"
	.string "{JPN}コインを あげるよ!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "{JPN}キンセツには だれでも\n"
	.string "{JPN}たのしめる ものが あるね\p"
	.string "{JPN}わたしには ゲームコーナーがね$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "{JPN}ルーレットの テーブルは\n"
	.string "{JPN}それぞれ レートが ちがうよ.\p"
	.string "{JPN}テーブルを えらぶまえに\n"
	.string "{JPN}コインを かくにんしてね.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "{JPN}ここにいると じかんを\n"
	.string "{JPN}わすれてしまうなあ.\lしごとに もどらないと.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "{JPN}ゲームコーナーで あそぶには\n"
	.string "{JPN}コインが ひつようだよ.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "{JPN}この ルーレットは   \n"
	.string "{JPN}なかなか きびしいですよ.\p"
	.string "{JPN}かつも まけるも\nうんしだいです.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "{JPN}スロットでは さいだい 3まいの\n"
	.string "{JPN}コインが つかえるよ.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "{JPN}7で ぴったり とめるのは\n"
	.string "{JPN}とても むずかしいんだ.\p"
	.string "{JPN}リールタイムの ボーナスゲームで\n"
	.string "{JPN}7で とまると コインが もらえるよ.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "{JPN}スロットの じょうほうを\n"
	.string "{JPN}おしえて あげますね.\p"
	.string "{JPN}かみなりマークを ためるほど\n"
	.string "{JPN}リールタイムの かいすうが\l"
	.string "{JPN}ふえるんですよ.\p"
	.string "{JPN}5かいの リールタイムが\n"
	.string "{JPN}さいだいですが   \p"
	.string "{JPN}つうじょうボーナス 4かい\n"
	.string "{JPN}そのあと ビッグボーナスが\l"
	.string "{JPN}でることも あるんです.\pぜんぶで 660まいの\nコインが てにはいりますが\lかなり むずかしいですよ.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "{JPN}コインケースが ないと\n"
	.string "{JPN}あそべないよ.$"

