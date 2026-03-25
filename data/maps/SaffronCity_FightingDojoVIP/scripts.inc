SaffronCity_FightingDojoVIP_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_FALKNER_2, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BUGSY_2, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_WHITNEY_2, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MORTY_2, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CHUCK_2, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JASMINE_2, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_PRYCE_2, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CLAIR_2, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BROCK, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MISTY, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_LTSURGE, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_ERIKA, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JANINE, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLAINE, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLUE, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
	.string "{JPN}ハッサム: シー ザー!$"

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
	.string "{JPN}ミルタンク: モーーーー!$"

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
	.string "{JPN}ニョロゾ: ニョロ ニョロ!$"

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
	.string "{JPN}ジュゴン: ゴーーーーン!$"

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
	.string "{JPN}ハガネール: グラーーーンク!$"

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
	.string "{JPN}キングドラ: ドラーーー...$"

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
	.string "{JPN}イワーク: オーーーニクス!$"

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
	.string "{JPN}スターミー: ヒャーーー!$"

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
	.string "{JPN}ウツボット: ブリーーー!$"

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
	.string "{JPN}ベトベトン: ムーーーク...$"

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
	.string "{JPN}ユンゲラー: ユンゲラー!$"

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
	.string "{JPN}ブーバー: マグマーーー!$"

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
	.string "{JPN}ライチュウ: ライ チュウ!$"

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Machamp:
	.string "{JPN}カイリキー: マー チャンプ!$"

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
	.string "{JPN}たすけてー!$"

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
	.string "{JPN}かくとうどうじょう VIPラウンジ$"

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
	.string "{JPN}してんのうに かったんだね!\n"
	.string "{JPN}おめでとう!\p"
	.string "{JPN}ぼくは ひこうタイプの\n"
	.string "{JPN}ポケモンを もっと きたえたよ.\p"
	.string "{JPN}また そらの ちからに\n"
	.string "{JPN}ちょうせん してみる?$"

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
	.string "{JPN}わあ... また まけちゃった.\p"
	.string "{JPN}もっと きびしく\n"
	.string "{JPN}しゅぎょうして\lさいきょうの とりつかいに\lなってやる!$"

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
	.string "{JPN}すごいね! きみは ジョウトちほうの\n"
	.string "{JPN}チャンピオンに なったんだね!\p"
	.string "{JPN}きみの じつりょくは\n"
	.string "{JPN}ほんとうに すばらしいよ!\p"
	.string "{JPN}ぼくは けんきゅうに\n"
	.string "{JPN}いそがしかったんだ.\p"
	.string "{JPN}あたらしい はっけんを\nみせて あげる.\nさいせんしない?$"

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
	.string "{JPN}すごいや きみは\n"
	.string "{JPN}エキスパートトレーナー\l"
	.string "{JPN}だね.\p"
	.string "{JPN}ぼくの けんきゅうは\nまだ かんぜんじゃ\lないようだ...$"
SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
	.string "{JPN}あ! きみね!\p"
	.string "{JPN}わあ ジョウトちほうの\n"
	.string "{JPN}チャンピオンに なったの?\p"
	.string "{JPN}きみって ほんとうに\n"
	.string "{JPN}すごいのね!\pきみが どのくらい つよいか\nみて みたいの.\nさいせんしない?$"

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
	.string "{JPN}うわああああん!\p"
	.string "{JPN}うわああああん!\p"
	.string "{JPN}...グスッ ヒック...\nいじわる!$"
SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
	.string "{JPN}おお ジョウトちほうの\n"
	.string "{JPN}チャンピオンよ! よく きたな.\p"
	.string "{JPN}きみは ちからと わざを\n"
	.string "{JPN}しめしたが ぜんかいの\l"
	.string "{JPN}たたかい いらい せいちょう\l"
	.string "{JPN}したか?\p"
	.string "{JPN}わたしは ゴーストタイプの\n"
	.string "{JPN}ポケモンと くんれんしていた.\p"
	.string "{JPN}きみが ふたたび かげを\n"
	.string "{JPN}のりこえられるか みてみよう.\nさいせんしないか?$"

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
	.string "{JPN}わたしは まだまだ\n"
	.string "{JPN}いたらない...\p"
	.string "{JPN}あなたは わたしよりも\n"
	.string "{JPN}ずっと たくさんの ことを\lみてきている.\pうらやましいですよ...$"
SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
	.string "{JPN}わはははっ! ジョウトちほうの\n"
	.string "{JPN}チャンピオン!\p"
	.string "{JPN}また きたのか!\p"
	.string "{JPN}きみの じつりょくが あがったのが\nわかるぞ!\pどちらが つよいか みてみるか?$"

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
	.string "{JPN}なに? え? まけた? また?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
	.string "{JPN}...おめでとう \n"
	.string "{JPN}ジョウト チャンピオン.\p"
	.string "{JPN}あなたは とても\n"
	.string "{JPN}つよくなった...\p"
	.string "{JPN}わたしも せいちょう\n"
	.string "{JPN}したでしょうか.\pそれを ためして\nみませんか?\pわたしと さいせんを\nしませんか?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
	.string "{JPN}...あなたのほうが\n"
	.string "{JPN}わたしよりも\l"
	.string "{JPN}すぐれた トレーナーです.\pぎじゅつでも やさしさでも.$"

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
	.string "{JPN}おお ジョウトちほうの\n"
	.string "{JPN}チャンピオンよ!\p"
	.string "{JPN}きみの じつりょくは\n"
	.string "{JPN}たしかに すばらしい.\p"
	.string "{JPN}かんしんしたよ.\p"
	.string "{JPN}だが いまでも\n"
	.string "{JPN}おたがいから まなぶ ことは\l"
	.string "{JPN}おおい.\p"
	.string "{JPN}わたし ヤナギ\nふゆの トレーナーには\pまだ いくつかの おくのては\nのこっている.\nさいせんしないか?$"

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
	.string "{JPN}ああ またしても きみの\n"
	.string "{JPN}じつりょくに かんしんしたよ.\p"
	.string "{JPN}つよい いしを もつ きみなら\n"
	.string "{JPN}じんせいの しょうがいを\l"
	.string "{JPN}すべて のりこえられるだろう.$"

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
	.string "{JPN}やったのね?\p"
	.string "{JPN}きみは いま ジョウトちほうの\n"
	.string "{JPN}チャンピオンよ.\p"
	.string "{JPN}きみは つよさを しょうめい\n"
	.string "{JPN}したけど また わたしと\l"
	.string "{JPN}たたかえるかしら?\n"
	.string "{JPN}りゅうつかいとして わたしは\n"
	.string "{JPN}youryokuを だしきらない.\pこんどは ちがうわ.\nさいせんしない?$"

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
	.string "{JPN}わたしが まけた?\p"
	.string "{JPN}また?\p"
	.string "{JPN}しんじられない.きっと\n"
	.string "{JPN}なにか まちがいが\lあるはず...$"
SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
	.string "{JPN}タケシ: やあ {PLAYER}!\p"
	.string "{JPN}きみがカントーチャンピオンに\n"
	.string "{JPN}なったってきいたよ.\p"
	.string "{JPN}すごいじゃないか!\p"
	.string "{JPN}きっともっとつよくなってる\n"
	.string "{JPN}んだろうね.\pぼくともういちど\nたたかってくれるかい?$"

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
	.string "{JPN}タケシ: きみの ポケモンは\n"
	.string "{JPN}またしても ぼくの\liわのような ぼうぎょを\lつきやぶった...$"
SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
	.string "{JPN}カスミ: わあ カントーチャンピオンに\n"
	.string "{JPN}なったのね!\p"
	.string "{JPN}すごいわ! ずいぶんと\n"
	.string "{JPN}せいちょうしたのね {PLAYER}.\p"
	.string "{JPN}でもわたしもまけてないわよ.\p"
	.string "{JPN}もういちどたたかってくれる?$"

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
	.string "{JPN}カスミ: あなたって\nほんとうに つよいのね...$"
SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
	.string "{JPN}マチス: おお カントーチャンピオンに\n"
	.string "{JPN}なったのか!\p"
	.string "{JPN}たいしたもんだぜ こぞう!\n"
	.string "{JPN}でもオレはまだまだだぜ!\n"
	.string "{JPN}もういっかいやってやろうか?$"

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
	.string "{JPN}マチス: がああ! おまえはまだまだ\n"
	.string "{JPN}つよいぜ!$"

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
	.string "{JPN}エリカ: あら こんにちは.\p"
	.string "{JPN}まあ チャンピオンさま!\p"
	.string "{JPN}またおあいできてうれしいわ.\n"
	.string "{JPN}たびはとってもすてきだった\n"
	.string "{JPN}でしょうね.\n"
	.string "{JPN}チャンピオンでもちょうせんは\n"
	.string "{JPN}たのしいものですわ.\nわたしともういちど\nたたかってくださる?$"

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
	.string "{JPN}まけるというのは\n"
	.string "{JPN}くやしいものですね..\p"
	.string "{JPN}でもつよいかたがいるということは\n"
	.string "{JPN}はげみにもなります$"
SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
	.string "{JPN}ナツメ: ああ チャンピオンね.\p"
	.string "{JPN}あなたのもどりをかんじてたわ.\p"
	.string "{JPN}あなたのちからはとてつもなく\n"
	.string "{JPN}せいちょうしたのね.\n"
	.string "{JPN}いまでもあなたのオーラを\nかんじるわ.\nわたしともういちど\nたたかってくれる?$"

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
	.string "{JPN}ナツメ: あなたの ポケモンへの\n"
	.string "{JPN}あいじょうが またしても\l"
	.string "{JPN}わたしの サイコパワーを\lうわまわった...$"
SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
	.string "{JPN}フフフ...\p"
	.string "{JPN}すごいじゃない!\p"
	.string "{JPN}あなた いまや\n"
	.string "{JPN}チャンピオンなのね!\p"
	.string "{JPN}ほこらしいわ! でも\n"
	.string "{JPN}yoすこし youryou\nしてくれるとは\lおもわないで.\pわたしと さいせんしない?$"

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
	.string "{JPN}アンズ: あなたは やっぱり\n"
	.string "{JPN}つよいわね!\p"
	.string "{JPN}かんぜんに あなたの\nかちよ...$"
SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
	.string "{JPN}カツラ: おお!\p"
	.string "{JPN}カントーチャンピオンに\n"
	.string "{JPN}なったのじゃな!\p"
	.string "{JPN}もえるのう!\p"
	.string "{JPN}おまえのうでまえは\n"
	.string "{JPN}いちりゅうじゃ.\n"
	.string "{JPN}ワシはいつでもたたかいは\nだいかんげいじゃ.\nもういちどたたかってくれるか?$"

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
	.string "{JPN}カツラ: おまえのうでまえは\n"
	.string "{JPN}ほんとうにねついのう!\p"
	.string "{JPN}ワシのぼうぎょをやきつくして\n"
	.string "{JPN}しまったわい.$"

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
	.string "{JPN}グリーン: おお チャンピオンか!\p"
	.string "{JPN}ずいぶんとせいちょうしたな.\n"
	.string "{JPN}オレもそのタイトルをもって\n"
	.string "{JPN}たんだぜ.でもてかげんはしない.\n"
	.string "{JPN}そのちからをたもてるか\n"
	.string "{JPN}みせてもらおうか.\nもういちどたたかってくれるか?$"

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
	.string "{JPN}グリーン: なんだって?\p"
	.string "{JPN}どうしてまたまけちまったんだ?$"

