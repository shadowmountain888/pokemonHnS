CeladonCity_Gym_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_ErikaExplainTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "{JPN}エリカ: こんにちは... いいおてんき\n"
	.string "{JPN}ですね? とても きもちがよくて...\p"
	.string "{JPN}ねむくなってしまいそう...\p"
	.string "{JPN}わたし エリカです タマムシジム\n"
	.string "{JPN}のリーダーをしています\p"
	.string "{JPN}...あら? ジョウトちほうから\n"
	.string "{JPN}いらっしゃったのですね...\p"
	.string "{JPN}まあ... しょうぶを いどみに\n"
	.string "{JPN}きたとは きがつきませんでした\p"
	.string "{JPN}わかりました でも まけませんよ$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "{JPN}エリカ: あら! まけてしまいました...\p"
	.string "{JPN}あなたって とても つよいのですね...\p"
	.string "{JPN}レインボーバッジを さしあげます...$"
CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{JPN}{PLAYER}は\nレインボーバッジを\nもらった!$"

CeladonCity_Gym_Text_ErikaExplainTM:
	.string "{JPN}エリカ: すばらしい しょうぶ\n"
	.string "{JPN}でした\p"
	.string "{JPN}かんどうしました どうぞ この\n"
	.string "{JPN}わざマシンを おうけとりください\p"
	.string "{JPN}ギガドレインです\p"
	.string "{JPN}あたえた ダメージの はんぶんを\n"
	.string "{JPN}じぶんの たいりょくにかえる\l"
	.string "{JPN}すてきな わざですよ\p"
	.string "{JPN}よろしければ つかってくださいね...$"
CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "{JPN}エリカ: まけるのは にがい\n"
	.string "{JPN}あじが のこりますね...\p"
	.string "{JPN}でも つよい トレーナーがいると\n"
	.string "{JPN}しると やるきが でてきます...$"
CeladonCity_Gym_Text_ErikaRematch:
	.string "{JPN}エリカ: あら こんにちは\p"
	.string "{JPN}\n"
	.string "{JPN}まあ! カントーちゃんぴおん!\p"
	.string "{JPN}\n"
	.string "{JPN}また おあいできて\n"
	.string "{JPN}とっても うれしいですわ\p"
	.string "{JPN}\nたびは きっと とても\nすてきだったでしょうね\p\nちゃんぴおんだって\nちゃれんじを たのしみますわ\p\nわたしと さいせんを\nしませんか?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "{JPN}エリカ: まだ まけるのは にがい\n"
	.string "{JPN}あじが のこりますね...\p"
	.string "{JPN}でも つよい トレーナーがいると\n"
	.string "{JPN}しると やるきが でてきます...$"
CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "{JPN}おんなのこだけの ジムって\n"
	.string "{JPN}めずらしいと おもう?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "{JPN}あー やだ!$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "{JPN}ちょっと ゆだんしちゃった\nそれだけよ!$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "{JPN}あ バトル? ちょっと\n"
	.string "{JPN}こわいけど いいよ!$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "{JPN}あ もう おわり?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "{JPN}わあ バッジが いっぱい\n"
	.string "{JPN}かてないはずよ!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "{JPN}この おはなを みてるの?\n"
	.string "{JPN}それとも わたしを?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "{JPN}いやなかんじ!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "{JPN}エリカさんみたいに\n"
	.string "{JPN}じょうひんになるには\nどうしたらいいの?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "{JPN}エリカさんが おしえてくれた\n"
	.string "{JPN}ポケモンの わざを\nみせてあげる!$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "{JPN}あー... まけちゃった...$"
CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "{JPN}エリカさんが かたきを\nとってくれるわ!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "{JPN}わたしたち エリカさんを\nまもるのよ!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "{JPN}かてなかった...$"
CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "{JPN}エリカさんは もっと\nもっと つよいのよ!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "{JPN}タマムシポケモンジム\n"
	.string "{JPN}リーダー: エリカ\p"
	.string "{JPN}\n"
	.string "{JPN}しょうりしゃ:\nグリーン アカ$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "{JPN}タマムシポケモンジム\n"
	.string "{JPN}リーダー: エリカ\p"
    .string "{JPN}\n"
	.string "{JPN}しょうりしゃ:\nグリーン アカ {PLAYER}$"
