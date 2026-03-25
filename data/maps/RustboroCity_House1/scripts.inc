RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "{JPN}え? わたしの ポケモンが\n"
	.string "{JPN}かわいいって?\p"
	.string "{JPN}そんなの あたりまえよ.\p"
	.string "{JPN}\n"
	.string "{JPN}でも どうしても ほしいなら\n"
	.string "{JPN}こうかん してあげる.\p{STR_VAR_1}と わたしの\n{STR_VAR_2}を こうかんするわ.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "{JPN}えへへ...\n"
	.string "{JPN}わたしの ポケモンを\nよろしく おねがいします$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "{JPN}え? それって {STR_VAR_1}じゃ\n"
	.string "{JPN}ないでしょ.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "{JPN}あ いやなら いいですよ.\n"
	.string "{JPN}でも わたしの ポケモン\nかわいいんですよ...$"
RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "{JPN}どんな ポケモンでも あいじょうを\n"
	.string "{JPN}かけて そだてれば かわいくなるの.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "{JPN}いろんな ばしょに いろんな\n"
	.string "{JPN}ポケモンと ひとが いるのよ.\p"
	.string "{JPN}それが おもしろくて あちこち\n"
	.string "{JPN}たびを してるの.$"

