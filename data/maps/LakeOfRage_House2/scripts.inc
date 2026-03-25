LakeOfRage_House2_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "{JPN}いかりのみずうみは じつは\n"
	.string "{JPN}ギャラドスが あばれて\l"
    .string "{JPN}できた クレーターなんじゃ.\p"
	.string "{JPN}クレーターに あめみずが\n"
    .string "{JPN}たまって みずうみに\l"
	.string "{JPN}なったんじゃよ.\p"
    .string "{JPN}これは ワシの ひいひい\n"
	.string "{JPN}じいちゃんから つたわる\l"
	.string "{JPN}はなしじゃ.\pむかしは そこで げんきな\nコイキングが つれたんじゃが...\pいったい なにが おこって\nおるのか わからんのう.$"

LakeOfRage_House2_Text_MenInBlack:
    .string "{JPN}くろいふくをきた おとこたちが\n"
	.string "{JPN}きてから みずうみが おかしいんだ$"

LakeOfRage_House2_Text_LastMon:
    .string "{JPN}さいごの ポケモンは\n"
	.string "{JPN}もらえないよ!$"

LakeOfRage_House2_Text_WorldsLargest:
    .string "{JPN}いかりのみずうみが もとどおりに\n"
	.string "{JPN}なったんだ\p"
    .string "{JPN}コイキングたちも もどってきた\p"
	.string "{JPN}せかいいち おおきな コイキングを\n"
    .string "{JPN}てにいれる ゆめが かなうかも\p"
	.string "{JPN}じつは... きみが くれる\n"
	.string "{JPN}コイキング1ぴきに 2000えん\lきょだいコイキングなら 10まんえん\nはらうよ!$"

LakeOfRage_House2_Text_ForMe:
	.string "{JPN}それで... わたしに コイキングを\n"
	.string "{JPN}くれるかい?$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "{JPN}おお コイキングを もってるね!\n"
	.string "{JPN}どのくらい おおきいか みせて$"

LakeOfRage_House2_Text_BigPayout:
    .string "{JPN}わあ! これは すばらしい!\p"
	.string "{JPN}ぼうしを ぬがせてもらうよ!\p"
    .string "{JPN}これは ちょっとした\n"
	.string "{JPN}おれいだ$"

LakeOfRage_House2_Text_Bonus:
    .string "{JPN}きろくが だいじなんだ\p"
	.string "{JPN}これは ボーナスだと\nおもってくれ!$"

LakeOfRage_House2_Text_TooShort:
    .string "{JPN}おお! これは すばらしい!\p"
	.string "{JPN}...と いいたいところじゃが\n"
	.string "{JPN}もっと おおきいのを みた\l"
	.string "{JPN}ことが あるんじゃよ.\pまあ それなりの かちは\nあるじゃろう.$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "{JPN}なんだって? それは\nコイキングじゃないじゃないか!$"

LakeOfRage_House2_Text_Refused:
    .string "{JPN}おお... ワシに みせられる\n"
	.string "{JPN}ほど よいものは つれな\lかったのか? またこんどじゃな.$"
