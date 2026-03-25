BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_TreeckoDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_TorchicDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_MudkipDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TreeckoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTreeckoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TREECKO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TorchicDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTorchicDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TORCHIC_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MudkipDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMudkipDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MUDKIP_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_EonTicket
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_MysticTicket
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_AuroraTicket
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_OldMap
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brace
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Upgrade
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_EonTicket::
	checkitem ITEM_EON_TICKET, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmEonTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_EON_TICKET
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MysticTicket::
	checkitem ITEM_MYSTIC_TICKET, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMysticTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 96
	setvar VAR_0x8009, ITEM_MYSTIC_TICKET
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_AuroraTicket::
	checkitem ITEM_AURORA_TICKET, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAuroraTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 96
	setvar VAR_0x8009, ITEM_AURORA_TICKET
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_OldMap::
	checkitem ITEM_OLD_SEA_MAP, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmOldMap, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 96
	setvar VAR_0x8009, ITEM_OLD_SEA_MAP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brace::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrace, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 4
	setvar VAR_0x8009, ITEM_MACHO_BRACE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Upgrade::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmUpgrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_UP_GRADE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
	.string "{JPN}そのアイテムは もう もってるよ$"

BattleFrontier_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "{JPN}やあ! ふしぎなこうかんを\n"
	.string "{JPN}さがしてるのかい?\l"
	.string "{JPN}いまは すべての ポケモンセンター\nにあるよ がんばって!$"

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "{JPN}いらっしゃいませ こちらは\n"
	.string "{JPN}こうかんサービスコーナーです\p"
	.string "{JPN}あつめた バトルポイントを\n"
	.string "{JPN}すてきな しょうひんと こうかん\n"
	.string "{JPN}します\pこの リストから しょうひんを\nえらんでください$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "{JPN}この リストから しょうひんを\nえらんでください$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTreeckoDoll:
	.string "{JPN}キッスポスターを えらびましたね\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTorchicDoll:
	.string "{JPN}キッスクッションを えらびましたね\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMudkipDoll:
	.string "{JPN}ムチュールにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "{JPN}トゲピーにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "{JPN}ニャースにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "{JPN}ピッピにんぎょうを えらびましたね\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "{JPN}メタモンにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "{JPN}ヒノアラシにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "{JPN}チコリータにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "{JPN}ワニノコにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "{JPN}ラプラスにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "{JPN}カビゴンにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "{JPN}フシギバナにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "{JPN}リザードンにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "{JPN}カメックスにんぎょうを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmEonTicket:
	.string "{JPN}むげんのチケットを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMysticTicket:
	.string "{JPN}しんぴのチケットを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAuroraTicket:
	.string "{JPN}オーロラチケットを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmOldMap:
	.string "{JPN}ふるいかいずを えらびましたね\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrace:
	.string "{JPN}きょうせいギプスを\n"
	.string "{JPN}えらびましたね よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmUpgrade:
	.string "{JPN}アップグレードを えらびましたね\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "{JPN}ひかりのこなを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "{JPN}しろいハーブを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "{JPN}せんせいのツメを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "{JPN}メンタルハーブを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "{JPN}こだわりハチマキを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "{JPN}おうじゃのしるしを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "{JPN}きあいのハチマキを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "{JPN}ピントレンズを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "{JPN}たべのこしを えらびましたね.\n"
	.string "{JPN}よろしいですか?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "{JPN}ありがとうございます!\n"
	.string "{JPN}おうちのパソコンに おくりますね.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "{JPN}こちらが しょうひんです!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "{JPN}もうしわけございません...\n"
	.string "{JPN}バトルポイントが\nたりません...$"
BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "{JPN}もうしわけございません...\n"
	.string "{JPN}パソコンが\nいっぱいのようです...$"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "{JPN}もうしわけございません...\n"
	.string "{JPN}もつスペースが\nありません...$"
BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "{JPN}ありがとうございました.\p"
	.string "{JPN}バトルポイントが たまりましたら\n"
	.string "{JPN}また きてくださいね.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "{JPN}あー すてきねえ!\n"
	.string "{JPN}わたしも ほしいなあ!\l"
	.string "{JPN}かわいい クッション!\l"
	.string "{JPN}おおきな ぬいぐるみ!\l"
	.string "{JPN}ちいさな ぬいぐるみ!\n"
	.string "{JPN}ぜんぶ ほしいわあ!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "{JPN}ママに まかせなさい!\p"
	.string "{JPN}あなたが ほしいものなら\n"
	.string "{JPN}なんでも てにいれてあげるわよ!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "{JPN}ここの どうぐが てにはいれば\n"
	.string "{JPN}わたしの ポケモンも つよくなる.\p"
	.string "{JPN}きっと つよくなるさ!\n"
	.string "{JPN}まちがいないね!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "{JPN}はあ?\n"
	.string "{JPN}なにを じろじろ みてるのよ?\p"
	.string "{JPN}わたしの ぬいぐるみを\n"
	.string "{JPN}そんなふうに みるのは やめてよ.\p"
	.string "{JPN}ほしいなら じぶんで てにいれなさい!\n"
	.string "{JPN}そうよね ムチュール?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "{JPN}しってる?\p"
	.string "{JPN}バトルしせつで きろくを のばすと\n"
	.string "{JPN}もらえる バトルポイントが\l"
	.string "{JPN}どんどん ふえていくのよ.$"

BattleFrontier_ExchangeServiceCorner_Text_TreeckoDollDesc::
	.string "{JPN}キモリの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_TorchicDollDesc::
	.string "{JPN}アチャモの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_MudkipDollDesc::
	.string "{JPN}ミズゴロウの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "{JPN}トゲピーの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "{JPN}ニャースの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "{JPN}ピッピの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "{JPN}メタモンの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "{JPN}ヒノアラシの ぬいぐるみ.\n"
	.string "{JPN}マットや つくえに かざれる.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "{JPN}チコリータの にんぎょう.\n"
	.string "{JPN}マットや つくえに かざろう.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "{JPN}ワニノコの にんぎょう.\n"
	.string "{JPN}マットや つくえに かざろう.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "{JPN}おおきな にんぎょう.\n"
	.string "{JPN}マットや つくえに かざろう.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "{JPN}ポケモン 1ひきの\n"
	.string "{JPN}こうげきりょくを あげる.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "{JPN}ポケモン 1ひきの\n"
	.string "{JPN}とくこうを あげる.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "{JPN}ポケモン 1ひきの\n"
	.string "{JPN}ぼうぎょりょくを あげる.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "{JPN}ポケモン 1ひきの\n"
	.string "{JPN}とくぼうを あげる.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "{JPN}ポケモン 1ひきの\n"
	.string "{JPN}すばやさを あげる.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "{JPN}ポケモン 1ひきの\nHPを あげる.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "{JPN}もたせると たたかいのあいだ\n"
	.string "{JPN}HPが すこしずつ かいふくする.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "{JPN}もたせると さがった のうりょくを\n"
	.string "{JPN}もとに もどす.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "{JPN}もたせると たまに\n"
	.string "{JPN}さきに こうげきできる.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "{JPN}もたせると メロメロじょうたいを\n"
	.string "{JPN}かいふくする.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "{JPN}もたせると ひかりで あいてのめいちゅうりつを\n"
	.string "{JPN}さげる.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "{JPN}わざの いりょくが あがるが\n"
	.string "{JPN}おなじわざしか だせなくなる.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "{JPN}もたせると こうげきしたとき\n"
	.string "{JPN}あいてを ひるませることがある.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "{JPN}もたせると たまに\n"
	.string "{JPN}ひんしを ふせぐことがある.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "{JPN}もたせると きゅうしょに\n"
	.string "{JPN}あたりやすくなる.$"

EventScript_DoWonderTrade::
	goto_if_set FLAG_UNLIMITIED_WONDERTRADE, EventScript_DoWonderTradeStartNoLimit
	goto_if_unset FLAG_WONDERTRADE_FIRSTIME, EventScript_FirstTimeWonderRandomizer
	special CheckIfRandomizerIsActive
	goto_if_unset FLAG_WT_ENABLED_RANDOMIZER, EventScript_DoWonderTradeStart
	special CheckIfChallengesAreActive
	goto_if_set FLAG_WONDERTRADE3, EventScript_NoMoreForToday
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallenges
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade	
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_DoWonderTradeStart:
	goto_if_unset FLAG_BADGE05_GET, EventScript_WTNotActiveYet
	msgbox EventScript_DoWonderTrade_Text_Welcome, MSGBOX_DEFAULT
	closemessage
	special CheckIfChallengesAreActive
	goto_if_set FLAG_WONDERTRADE3, EventScript_NoMoreForToday
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallenges
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade	
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_WTChallenges::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_WTChallengesCancel
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade	
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_WTChallengesCancel::
	msgbox EventScript_DoWonderTrade_Text_Challenges, MSGBOX_DEFAULT
	closemessage
	end

EventScript_WTNotActiveYet::
	msgbox EventScript_DoWonderTrade_Text_FiveBadges, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeFirstTrade::
	setflag FLAG_WONDERTRADE1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveFirstTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveFirstTrade::
	clearflag FLAG_WONDERTRADE1
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeSecondTrade::
	setflag FLAG_WONDERTRADE2
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveSecondTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveSecondTrade::
	clearflag FLAG_WONDERTRADE2
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeThirdTrade::
	setflag FLAG_WONDERTRADE3
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveThirdTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveThirdTrade::
	clearflag FLAG_WONDERTRADE3
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeStartNoLimit::
	goto_if_unset FLAG_WONDERTRADE_FIRSTIME, EventScript_FirstTimeWonderUnlimited
	goto_if_unset FLAG_BADGE05_GET, EventScript_WTNotActiveYet
	special CheckIfChallengesAreActive
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallengesUnlimited
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveThirdTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_WTChallengesUnlimited::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_WTChallengesCancel
	return

EventScript_DoWonderTradeTrade::
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge EventScript_End
	copyvar VAR_0x8005, VAR_0x8004
	special CreateWonderTradePokemon
	special DoInGameTradeScene
	waitstate
	special ForceSaveGame
	waitstate
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_NoMoreForToday::
	msgbox EventScript_NoMoreForToday_Text, MSGBOX_DEFAULT
	closemessage
	end

EventScript_FirstTimeWonderRandomizer::
	msgbox EventScript_FirstTimeWonder_Text, MSGBOX_DEFAULT
	setflag FLAG_WONDERTRADE_FIRSTIME
	closemessage
	end

EventScript_FirstTimeWonderUnlimited::
	msgbox EventScript_FirstTimeWonder_Text_Unlimited, MSGBOX_DEFAULT
	setflag FLAG_WONDERTRADE_FIRSTIME
	closemessage
	end

EventScript_End::
	end

EventScript_DoWonderTrade_Text_Welcome:
	.string "{JPN}ポケモンセンターの\n"
	.string "{JPN}ふしぎなこうかん ステーションへ\l"
	.string "{JPN}ようこそ!\p"
	.string "{JPN}ふしぎなこうかんに だす\nポケモンを えらんでください.$"

EventScript_NoMoreForToday_Text:
	.string "{JPN}あっ! きょうの\n"
	.string "{JPN}3かいの こうかんは\l"
	.string "{JPN}もう つかっているみたいですね.\pまた あした きてください!$"

EventScript_FirstTimeWonder_Text:
	.string "{JPN}こんにちは トレーナーさん!\p"
	.string "{JPN}あら ふしぎなこうかんシステムを\n"
	.string "{JPN}つかうのは はじめてですか?\p"
	.string "{JPN}ふしぎなこうかんは デボンコーポが\n"
	.string "{JPN}かいはつした とくめい こうかん\l"
	.string "{JPN}システムです.\p"
	.string "{JPN}えらんだ ポケモンを だれかに おくり\n"
	.string "{JPN}そのひとも べつの ポケモンを\l"
	.string "{JPN}あなたに おくります.\p"
	.string "{JPN}おたがいに どんな ポケモンが\n"
	.string "{JPN}くるかは わかりません.\p"
	.string "{JPN}それが ふしぎなこうかんの\n"
	.string "{JPN}たのしさです! あ サーバーの\l"
	.string "{JPN}ふたんを へらすため\p"
	.string "{JPN}いちにち さんかいまでと\n"
	.string "{JPN}なっています.\pすてきな ふしぎなこうかんを\nたのしんでくださいね!$"

EventScript_FirstTimeWonder_Text_Unlimited:
	.string "{JPN}こんにちは トレーナーさん!\p"
	.string "{JPN}あら ふしぎなこうかんシステムを\n"
	.string "{JPN}つかうのは はじめてですか?\p"
	.string "{JPN}ふしぎなこうかんは デボンコーポが\n"
	.string "{JPN}かいはつした とくめい こうかん\l"
	.string "{JPN}システムです.\p"
	.string "{JPN}えらんだ ポケモンを だれかに おくり\n"
	.string "{JPN}そのひとも べつの ポケモンを\l"
	.string "{JPN}あなたに おくります.\p"
	.string "{JPN}おたがいに どんな ポケモンが\n"
	.string "{JPN}くるかは わかりません.\p"
	.string "{JPN}それが ふしぎなこうかんの\n"
	.string "{JPN}たのしさです!\p"
	.string "{JPN}すてきな ふしぎなこうかんを\nたのしんでくださいね!$"

EventScript_DoWonderTrade_Text_Done:
	.string "{JPN}すてきな ふしぎなこうかんでしたね!$"
	.string ""

EventScript_DoWonderTrade_Text_Challenges:
	.string "{JPN}チャレンジモードが ゆうこうに\n"
	.string "{JPN}なっているようですね.\l"
	.string "{JPN}ポケモンリーグの あとで また\nきてください.$"

EventScript_DoWonderTrade_Text_FiveBadges:
	.string "{JPN}ざんねんながら ふしぎなこうかん\n"
	.string "{JPN}システムは まだ どうさして\l"
	.string "{JPN}iません.\pまた あとで きてくださいね.$"
