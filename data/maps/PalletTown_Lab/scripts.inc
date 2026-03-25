PalletTown_Lab_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_PALLETTOWN_LABSTATE, 2
	release
	end

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "{JPN}ポケモンずかんの ちょうしは\nどうじゃ?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "{JPN}おお{PLAYER}くん！\n"
	.string "{JPN}こんなとおいところまで\l"
	.string "{JPN}よくきてくれたね！\p"
	.string "{JPN}どうじゃ？\n"
	.string "{JPN}カントーのトレーナーたちも\l"
	.string "{JPN}てごわいだろう！$"
PalletTown_Lab_Text_OakLabGoodbye:
	.string "{JPN}ちかくまできたら\n"
	.string "{JPN}またかおをみせてくれ$"
PalletTown_Lab_Text_OakOpenMtSilver:
	.string "{JPN}オーキド: おお! それは\n"
	.string "{JPN}すばらしい!\p"
	.string "{JPN}カントーちほうの ジムの\n"
	.string "{JPN}バッジを あつめたのじゃな!\l"
	.string "{JPN}よく やった!\p"
	.string "{JPN}わしの みたては ただしかった\n"
	.string "{JPN}ようじゃな.\p"
	.string "{JPN}そうじゃ {PLAYER}よ.\n"
	.string "{JPN}シロガネやまに いけるよう\l"
	.string "{JPN}てはいを してやろう.\p"
	.string "{JPN}シロガネやまは おおくの\n"
	.string "{JPN}やせいポケモンが すんでいる\l"
	.string "{JPN}おおきな やまじゃ.\p"
	.string "{JPN}ふつうの トレーナーには\n"
	.string "{JPN}きけんすぎるので たちいり\l"
	.string "{JPN}きんしなのじゃが\l{PLAYER}なら れいがいじゃ.\pセキエイこうげんに いくのじゃ.\nそこから シロガネやまに\lいくことが できるぞ.$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "{JPN}おや？\n"
	.string "{JPN}まだカントーのバッジを\l"
	.string "{JPN}あつめていないようじゃな\p"
	.string "{JPN}カントーのジムリーダーたちも\n"
	.string "{JPN}ジョウトにまけずおとらず\l"
	.string "{JPN}きょうてきぞろい！\p"
	.string "{JPN}もちろんきみは\n"
	.string "{JPN}ちょうせんしてみるよな？$"
PalletTown_Lab_Text_OakYesKantoBadges:
	.string "{JPN}カントーのバッジも\n"
	.string "{JPN}あつまってきているようじゃな！\p"
	.string "{JPN}たいへんだろうが\n"
	.string "{JPN}このけいけんはきっと\l"
	.string "{JPN}{PLAYER}くんのちからとなる！\p"
	.string "{JPN}すべてあつめおえたら\n"
	.string "{JPN}またあそびにきなさい\l"
	.string "{JPN}わしからプレゼントをあげよう！\p"
	.string "{JPN}{PLAYER}くん\n"
	.string "{JPN}しっかりがんばるんじゃぞ！$"
PalletTown_Lab_Text_OaksAssistant1:
	.string "{JPN}はかせの ポケモンこうざは\n"
	.string "{JPN}カントーちほうでは\l"
	.string "{JPN}ほうそうされて いないんです.\pざんねんです... ききたいのに.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "{JPN}{PLAYER}さんが\n"
	.string "{JPN}ずかんをつくってくれてるので\l"
	.string "{JPN}はかせのけんきゅうが\l"
	.string "{JPN}はかどってますよ！$"
PalletTown_Lab_Text_OaksAssistant3:
	.string "{JPN}だれにも いわないで くださいね.\n"
	.string "{JPN}オーキドはかせの ポケモンこうざ\lって なまほうそうじゃ\lないんですよ.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "{JPN}パソコンに でんしメールが\n"
	.string "{JPN}とどいている.\p"
	.string "{JPN}...\p"
	.string "{JPN}オーキドはかせ けんきゅうの\n"
	.string "{JPN}ちょうしは いかがですか?\p"
	.string "{JPN}わたしは あいかわらず\n"
	.string "{JPN}がんばっています.\p"
	.string "{JPN}{PLAYER}が かなり\n"
	.string "{JPN}ゆうめいに なったと\nききました.\pとても うれしく\nおもいます.\pワカバタウンの ウツギより 8-)$"
