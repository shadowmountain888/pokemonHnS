.set LOCALID_STORE_WHITNEY, 4

GoldenrodCity_DepartmentStore_6F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "{JPN}{PLAYER}ちゃん！こんなところで\nあうなんて！\pわたしミルタンクの\nものをかいにきたの\pまたしょうぶしたいなら\nかくとうどうじょうにきてね！$"
GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MACHOP
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "{JPN}ボクポケモンあつめてるんだ！\n"
	.string "{JPN}キミはスリープをもってる？\p"
	.string "{JPN}ボクのワンリキーと\n"
	.string "{JPN}こうかんしようよ？$"
GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "{JPN}やったあ！{STR_VAR_1}を\nてにいれたよ！\p{STR_VAR_2}げんきでね！$"
GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "{JPN}ええっとちがうとおもう\nそれは{STR_VAR_1}じゃないよ$"
GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "{JPN}とりかえてくれないの？\n"
	.string "{JPN}ちぇっがっかりだなあ..$"
GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "{JPN}やあっ！\n"
	.string "{JPN}ボクととりかえたワンリキー\l"
	.string "{JPN}げんき？$"

GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
	.string "{JPN}ラッキーチャンネルきいてる？\pかちたいならできるだけ\nたくさんのひととポケモン\lこうかんしていろんな\lばんごうをあつめるといいって\pでもこうかんはまえほど\nかんたんじゃないのよね$"
GoldenrodDeptStore_Text_6FSuperNerd:
    .string "{JPN}つかれたときはじどうはんばいきの\n"
	.string "{JPN}のみものが1ばん！\l"
	.string "{JPN}ポケモンものみものだいすきなんだ$"
GoldenrodDeptStore_Text_6FDirectory:
    .string "{JPN}おかいものにつかれたら\n"
	.string "{JPN}6かい..いこいのひろば$"