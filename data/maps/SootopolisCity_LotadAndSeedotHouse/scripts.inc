SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_PLURAL, 1
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_PLURAL, 1
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_SINGLE, 1
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_SINGLE, 1
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "{JPN}ポケモンの タネボーって\n"
	.string "{JPN}しってる?\n"
	.string "{JPN}ルネシティでは ほとんど\n"
	.string "{JPN}みかけないんだ.\p"
	.string "{JPN}ぼくは おおきな タネボーが\n"
	.string "{JPN}だいすきなんだ.\n"
	.string "{JPN}おおきければ おおきいほど\n"
	.string "{JPN}いいんだよ!\p"
	.string "{JPN}でも おとうとは ハスボーの\n"
	.string "{JPN}ほうが おおきいって いうんだ.\pそんなの おかしいよ.\nタネボーの ほうが\nぜったい おおきいはずだよ!\pあれ? きみ タネボーを\nもってるの?\nお おねがい!\nみせてくれる?$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{JPN}{STR_VAR_2} {STR_VAR_1}!\n"
	.string "{JPN}うわあ! これは おおきいね!\p"
	.string "{JPN}おとうとが みた おおきな\n"
	.string "{JPN}ハスボーに かてるかも\n"
	.string "{JPN}しれないよ!\p"
	.string "{JPN}みせてくれて ありがとう.\nこれは おれいだよ!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{JPN}{PLAYER}は キズぐすりを\nもらった!$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "{JPN}あれ?\n"
	.string "{JPN}バッグが いっぱいだよ.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{JPN}{STR_VAR_2} {STR_VAR_1}ですか?\p"
	.string "{JPN}うーん... これよりも おおきな\n"
	.string "{JPN}タネボーを みたことが\lありますねえ.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "{JPN}おお これは なかなか...\n"
	.string "{JPN}でも タネボーじゃ ありませんね!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "{JPN}おおきな タネボーは\n"
	.string "{JPN}もっていませんか?\l"
	.string "{JPN}ざんねんです...\p"
	.string "{JPN}おおきな タネボーを てにいれたら\nぜひ みせに きてください.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "{JPN}れきしじょう さいだいの\n"
	.string "{JPN}タネボー!\n"
	.string "{JPN}{STR_VAR_2}の {STR_VAR_3}-{STR_VAR_1}\n"
	.string "{JPN}きょだいだ!\pハスボーより おおきな\nタネボーを ずっと\nみたかったんだ!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "{JPN}ポケモンの ハスボーって\n"
	.string "{JPN}しってる?\n"
	.string "{JPN}ルネシティでは めったに\n"
	.string "{JPN}みかけないの.\p"
	.string "{JPN}わたし おおきな ハスボーが\n"
	.string "{JPN}だいすきなの!\p"
	.string "{JPN}おにいちゃんは タネボーの\n"
	.string "{JPN}ほうが おおきいって いうの.\p"
	.string "{JPN}でも それは まちがいよ!\nだれでも しってるけど\nハスボーの ほうが ずっと\nおおきいのよ.\pあら? あなた ハスボーを\nもってるの?\nお おねがい! みせて!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{JPN}{STR_VAR_2} {STR_VAR_1}!\n"
	.string "{JPN}すごーい! おおきいのね!\p"
	.string "{JPN}おにいちゃんが みた\n"
	.string "{JPN}きょだいな タネボーより\n"
	.string "{JPN}おおきいかも しれないわ.\p"
	.string "{JPN}みせてくれて ありがとう!\nこれは おれいよ!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{JPN}{PLAYER}は キズぐすりを\nもらった!$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "{JPN}あら?\n"
	.string "{JPN}バッグが いっぱいね.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{JPN}{STR_VAR_2} {STR_VAR_1}ですか?\p"
	.string "{JPN}うーん... これよりも おおきな\n"
	.string "{JPN}ハスボーを みたことが\lありますねえ.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "{JPN}あら これは すてきね!\n"
	.string "{JPN}でも ハスボーじゃ ないわ!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "{JPN}おおきな ハスボーは\n"
	.string "{JPN}もっていませんか?\l"
	.string "{JPN}がっかりです...\p"
	.string "{JPN}おおきな ハスボーを てにいれたら\nぜひ みせに きてください!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "{JPN}れきしじょう さいだいの\n"
	.string "{JPN}ハスボー!\n"
	.string "{JPN}{STR_VAR_2}の {STR_VAR_3}-{STR_VAR_1}\n"
	.string "{JPN}きょだいよ!\pタネボーより おおきな\nハスボーを ずっと\nみたかったの!$"
