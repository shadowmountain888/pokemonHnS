FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ONIX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "{JPN}うおおおおおお! ひつようなんだ!\n"
	.string "{JPN}どうしても {STR_VAR_1} が\l"
	.string "{JPN}ほしいんだよ!\p"
	.string "{JPN}そのためなら なんでもするぞ!\p"
	.string "{JPN}\p"
	.string "{JPN}...あー... きいた?\n"
	.string "{JPN}こころのそこからの さけびを?\p"
	.string "{JPN}きいてくれたなら きみの\n"
	.string "{JPN}{STR_VAR_1} を ぼくの {STR_VAR_2} と\pこうかん してくれるよね?\nべつの ちいきから きた\pちょうレアな ポケモンだよ!$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "{JPN}おお そうそう いいね!\p"
	.string "{JPN}{STR_VAR_1} ようこそ!\n"
	.string "{JPN}{STR_VAR_2} げんきでね!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "{JPN}えーっと いや ちがうと\n"
	.string "{JPN}おもうよ.\nそれは{STR_VAR_1}じゃない.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "{JPN}だめ?こうかんしてくれない\n"
	.string "{JPN}の?\nこんなにきもちをつたえたのに?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "{JPN}いまからバルビートを\n"
	.string "{JPN}ちょうつよくするんだ!\p"
	.string "{JPN}きみもプラスルをつよく\nそだててくれよ!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "{JPN}ほかの ひとと ポケモンを\n"
	.string "{JPN}こうかんする ということは...\p"
	.string "{JPN}じぶんの おもいでを\nほかの ひとと こうかんする\pのと おなじ ことなんだよ$"

FortreeCity_House1_Text_Zigzagoon:
	.string "{JPN}ジグザグマ:グモモー?$"

