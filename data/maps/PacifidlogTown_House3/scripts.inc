PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "{JPN}みてくれよ この{STR_VAR_2}を!\p"
	.string "{JPN}たんじょうびの きねんに\n"
	.string "{JPN}きのう つかまえた {STR_VAR_2}だ!\p"
	.string "{JPN}おお きみも ほしそうだな!\n"
	.string "{JPN}なんたって ちょうきちょうだからな!\p"
	.string "{JPN}よし こうしよう\n"
	.string "{JPN}{STR_VAR_1}と こうかんしてくれるなら\nかんがえてもいいぞ$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "{JPN}おお これが {STR_VAR_1}か?\p"
	.string "{JPN}{STR_VAR_2}に にているけど\n"
	.string "{JPN}どこか びみょうに ちがうな\p"
	.string "{JPN}ありがとう!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "{JPN}だめ だめ だめ!\n"
	.string "{JPN}ほんものの {STR_VAR_1}じゃないと\nこうかん できないよ!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "{JPN}あれ? やっぱり\n"
	.string "{JPN}こうかん やめるのか?\p"
	.string "{JPN}そうか べつに むりに\n"
	.string "{JPN}こうかんしたいわけじゃないからな$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "{JPN}じぶんで さがしに いくことも\n"
	.string "{JPN}できるけど...\p"
	.string "{JPN}でも ほんとうは べつの\n"
	.string "{JPN}トレーナーが つかまえた\nタツベイが ほしかったんだ...$"
PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "{JPN}それって ポケモンずかん?\p"
	.string "{JPN}たくさんの いろんな\n"
	.string "{JPN}ポケモンに あえたんだろうな?\p"
	.string "{JPN}ぼくも きみの ようになりたいよ$"

