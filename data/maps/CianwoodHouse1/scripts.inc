CianwoodHouse1_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "{JPN}アサギからきたの？\n"
	.string "{JPN}とちゅう4つのしまがあったでしょ\l"
	.string "{JPN}なかにうみのかみさまがいるそうよ$"
CianwoodCity_Text_BellTowerStory:
	.string "{JPN}ぎんいろのはねをもっていると\n"
	.string "{JPN}あえるっていいつたえきいたわ\p"
	.string "{JPN}きっとじぶんと\n"
	.string "{JPN}おなじかおりがするからね$"
CianwoodCity_Text_WhirlIslandsStory:
	.string "{JPN}しまのまわりのうずは\n"
	.string "{JPN}うみのかみさまがつくりだしてるって\l"
	.string "{JPN}いいつたえきいたことあるよ\p"
	.string "{JPN}とくべつなわざでもおぼえてないと\n"
	.string "{JPN}さきにすすめないんじゃないかなぁ$"
CianwoodCity_Text_ClearBellReaction:
	.string "{JPN}おお!きみは\n"
	.string "{JPN}クリアベルを てにいれたのか?\p"
	.string "{JPN}わしのむかしからの ゆめが...\n"
	.string "{JPN}そうか...\p"
	.string "{JPN}やってくれたのじゃな...\n"
	.string "{JPN}...\l"
	.string "{JPN}...きこえるぞ!\p"
	.string "{JPN}かぜにのって スズのとう の\n"
	.string "{JPN}ほうこうから きこえてくる\l"
	.string "{JPN}ベルの おとが...$"

CianwoodCity_Text_TidalBellReaction:
	.string "{JPN}おお!きみは\n"
	.string "{JPN}タイダルベルを てにいれたのか?\p"
	.string "{JPN}わしのむかしからの ゆめが...\n"
	.string "{JPN}そうか...\p"
	.string "{JPN}やってくれたのじゃな...\n"
	.string "{JPN}...\l"
	.string "{JPN}...きこえるぞ!\p"
	.string "{JPN}うみかぜにのって\n"
	.string "{JPN}うずまきじま の ほうこうから\l"
	.string "{JPN}きこえてくる ベルの おとが...$"
