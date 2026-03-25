SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "{JPN}ナツメ: あなたが くることは\n"
	.string "{JPN}わかっていました...\p"
	.string "{JPN}3ねんまえに あなたが\n"
	.string "{JPN}やってくる げんしょうを\n"
	.string "{JPN}みたのです\p"
	.string "{JPN}わたしの バッジが\n"
	.string "{JPN}ほしいのですね\p"
	.string "{JPN}たたかいは すきでは\n"
	.string "{JPN}ありませんが リーダーとして\l"
	.string "{JPN}ふさわしいと みとめた\lひとに バッジを さしあげる\lのが つとめです\pあなたが のぞむなら\nわたしの ちょうのうりょくを\nおみせしましょう!$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "{JPN}ナツメ: あなたの ちから...\p"
	.string "{JPN}わたしが みとおした\n"
	.string "{JPN}いじょうです...\p"
	.string "{JPN}みらいを かんぜんに\n"
	.string "{JPN}よそくする ことは\n"
	.string "{JPN}できないのかも しれませんね...\pわかりました あなたの かちです\nゴールドバッジを\nさしあげましょう$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{JPN}{PLAYER}は ゴールドバッジを てにいれた!$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "{JPN}ナツメ: ゴールドバッジは\n"
	.string "{JPN}あなたの せんざいのうりょくを\n"
	.string "{JPN}ひきだします...\p"
	.string "{JPN}あなたの ちからを\n"
	.string "{JPN}せいかくに よそく\n"
	.string "{JPN}できませんでしたが\l"
	.string "{JPN}これだけは たしかです\pあなたは ゆうめいで\nあいされる チャンピオンに\nなるでしょう!$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "{JPN}ナツメ: あなたの ポケモンへの\n"
	.string "{JPN}あいが わたしの\l"
	.string "{JPN}ちょうのうりょくを\l"
	.string "{JPN}うわまわりました...\n"
	.string "{JPN}あいの ちからも ひとつの\nちょうのうりょく なのかも\nしれませんね...$"
SaffronCity_Gym_Text_SabrinaRematch:
	.string "{JPN}ナツメ: ああ カントーの チャンピオンですね.\p"
	.string "{JPN}あなたの きせきを かんじていました.\p"
	.string "{JPN}ちからが ものすごく せいちょう していますね.\p"
	.string "{JPN}いまでも あなたの オーラを かんじます.\p"
	.string "{JPN}わたしと さいせんを してみませんか?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "{JPN}ナツメ: あなたの ポケモンへの\n"
	.string "{JPN}あいが またしても\l"
	.string "{JPN}わたしの ちょうのうりょくを\lうわまわりました...$"
SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "{JPN}あなたが たおした みんなの\n"
	.string "{JPN}ちからが わたしに やどっている!$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "{JPN}つよい... つよすぎます...$"
SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "{JPN}あなたの ちからの みなもとは なんなの?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "{JPN}サイコパワーとは\n"
	.string "{JPN}こころの ちからなのだ!$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "{JPN}きみの こころのほうが\n"
	.string "{JPN}わたしより つよかった!$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "{JPN}きみは わざだけでなく\n"
	.string "{JPN}こころも つよくしたのだな.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "{JPN}ふふふふ... はっきりと\n"
	.string "{JPN}みえます\pあなたの こころの おくが\nみえるのです!$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "{JPN}こころを よんでいたのに\nまけてしまいました...$"
SaffronCity_Gym_Text_MediumDorisAfter:
	.string "{JPN}しまった! あなたに まけるって\n"
	.string "{JPN}よげんを していたのを わすれてた.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "{JPN}となりの かくとうどうじょうは\n"
	.string "{JPN}むかし このまちの ジムだったんだ.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "{JPN}まったく あいてに\nなりませんでした...$"
SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "{JPN}かくとうどうじょうの しはん\n"
	.string "{JPN}カラテキングは ナツメに\l"
	.string "{JPN}かんぜんに やられちゃったよ.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "{JPN}よお みらいの チャンピオン!\p"
	.string "{JPN}きみほど じゅくれんした\n"
	.string "{JPN}トレーナーなら エスパータイプの\l"
	.string "{JPN}ポケモンの たいしょほうは\l"
	.string "{JPN}せつめい ふようだろうな?\p"
	.string "{JPN}きみには おおいに きたい してるぞ!\p"
	.string "{JPN}がんばれよ!$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "{JPN}また すばらしい たたかいだった!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "{JPN}ヤマブキ ポケモンジム\n"
	.string "{JPN}リーダー: ナツメ\p"
	.string "{JPN}かった トレーナー:\n"
	.string "{JPN}グリーン レッド$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "{JPN}ヤマブキ ポケモンジム\n"
	.string "{JPN}リーダー: ナツメ\p"
    .string "{JPN}かった トレーナー:\n"
	.string "{JPN}グリーン レッド {PLAYER}$"
