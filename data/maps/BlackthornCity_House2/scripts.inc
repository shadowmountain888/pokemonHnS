BlackthornCity_House2_MapScripts::
	.byte 0

BlackthornCity_House2_EventScript_Emy::
	lock
	faceplayer
	goto_if_set FLAG_BLACKTHORN_NPC_TRADE_COMPLETED, BlackthornCity_House2_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MR_MIME
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BlackthornCity_House2_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BlackthornCity_House2_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_House2_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BlackthornCity_House2_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BlackthornCity_House2_Text_MonYouTakeCare, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_BLACKTHORN_NPC_TRADE_COMPLETED
	releaseall
	end

BlackthornCity_House2_EventScript_DeclineTrade::
	msgbox BlackthornCity_House2_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BlackthornCity_House2_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_TradeCompleted::
	msgbox BlackthornCity_House2_Text_After, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_Text_YouWillTradeWontYou:
	.string "{JPN}わたしポケモンをあつめてるの！\n{STR_VAR_1}もってる？\pわたしの{STR_VAR_2}と\nこうかんしない？$"
BlackthornCity_House2_Text_MonYouTakeCare:
	.string "{JPN}やったー！{STR_VAR_1}を\nゲットしたわ！\p{STR_VAR_2}をよろしくね！$"
BlackthornCity_House2_Text_ThisIsntAMon:
	.string "{JPN}えーと.それは\n{STR_VAR_1}じゃないわね$"
BlackthornCity_House2_Text_YouWontTradeMe:
	.string "{JPN}こうかんしてくれないの？\n"
	.string "{JPN}えーっ..がっかり..$"
BlackthornCity_House2_Text_After:
	.string "{JPN}こんにちは！わたしの\nバリヤードげんきにしてる？$"