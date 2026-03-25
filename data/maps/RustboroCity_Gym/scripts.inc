RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_VIOLET_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_GARBAGEVAR, 1
	addvar VAR_GARBAGEVAR, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	goto_if_set FLAG_FINITE_TMS, RustboroCity_Gym_EventScript_GiveRockTombFinite
	msgbox RustboroCity_Gym_Text_ExplainRockTombInfinite, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GiveRockTombFinite::
	msgbox RustboroCity_Gym_Text_ExplainRockTomb MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}よお!ちょうしは どうだい?\p"
	.string "{JPN}きいてくれよ ともだち!\n"
	.string "{JPN}チャンピオンに なりたくないか?\p"
	.string "{JPN}おれは トレーナーじゃないけど\n"
	.string "{JPN}かちかたなら おしえられるぜ!\p"
	.string "{JPN}よし きまりだな! いっしょに\n"
	.string "{JPN}ポケモンチャンピオンを めざそう!\p"
	.string "{JPN}トレーナーの しごとは ジムバッジを\n"
	.string "{JPN}あつめることだろう?\p"
	.string "{JPN}でも ジムリーダーは つよいぞ!\p"
	.string "{JPN}そこで おれの でばんだ!\n"
	.string "{JPN}せんもんてきな アドバイスをするぜ!\p"
	.string "{JPN}ジムリーダーの ツツジは いわタイプ\n"
	.string "{JPN}ポケモンの つかいてだ.\p"
	.string "{JPN}いわタイプは とても かたいが\n"
	.string "{JPN}みずタイプや くさタイプのわざは\l"
	.string "{JPN}にがてなんだ.\p"
	.string "{JPN}ジムリーダーに かったら\n"
	.string "{JPN}また あいにきてくれよ.\p"
	.string "{JPN}よし がんばれ!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}わあ! なんて すばらしい\n"
	.string "{JPN}しょうり だった!\n"
	.string "{JPN}ぼくの おうえんが きいたんだ!\p"
	.string "{JPN}すごいぞ!\n"
	.string "{JPN}トレーナーカードを みてみろ!\p"
	.string "{JPN}きみが もらった ストーンバッジが\n"
	.string "{JPN}ちゃんと きろく されてるはずだ!\p"
	.string "{JPN}つまり...\p"
	.string "{JPN}きみは チャンピオンへの\n"
	.string "{JPN}かいだんを のぼりはじめた\nってことだ!\pきもちいいだろうなあ!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "{JPN}ジムトレーナーを なめるなよ!\n"
	.string "{JPN}なんで おれたちが つよいか\lおしえてやる!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "{JPN}きみの つよさに まけちゃった...$"
RustboroCity_Gym_Text_JoshPostBattle:
	.string "{JPN}いわタイプの おそろしい ちからを\n"
	.string "{JPN}まだ みてないな!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "{JPN}おれに かてなきゃ ツツジには\n"
	.string "{JPN}ぜったい かてないぞ!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "{JPN}うわあ! きみには のうりょくが\nあるな!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "{JPN}ツツジは おれより なんばいも\n"
	.string "{JPN}つよいんだ.\p"
	.string "{JPN}きをつけたほうが いいぞ!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "{JPN}まちなかでも かんけいないぞ!\p"
	.string "{JPN}おれの いわポケモンには あばれる\n"
	.string "{JPN}ばしょが ひつようなんだ!$"
	.string ""

RustboroCity_Gym_Text_MarcDefeat:
	.string "{JPN}うわあ うわあ!\n"
	.string "{JPN}ちょうせんしゃは きょうてきだ!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "{JPN}リーダーには あたまが さがるよ.\p"
	.string "{JPN}わかい としで いわタイプを えらぶ\n"
	.string "{JPN}なんて あたまがよくて センスが\lあるからな.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "{JPN}こんにちは.わたしは カナズミジム\n"
	.string "{JPN}リーダーの ツツジです.\p"
	.string "{JPN}トレーナーズスクールで まなんだ\n"
	.string "{JPN}ことを たたかいで いかすために\l"
	.string "{JPN}ジムリーダーに なりました.\p"
	.string "{JPN}どのような ポケモンで どのように\n"
	.string "{JPN}たたかうのか みせていただけ\lますか?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "{JPN}そう...\n"
	.string "{JPN}わたしの まけ...\p"
	.string "{JPN}まだまだ べんきょうしなくちゃ\n"
	.string "{JPN}いけない ことが たくさん\n"
	.string "{JPN}あるみたいね...\p"
	.string "{JPN}わかったわ\p"
	.string "{JPN}ポケモンリーグの きそくで\n"
	.string "{JPN}ジムリーダーに かった\l"
	.string "{JPN}トレーナーには これを わたすの\p"
	.string "{JPN}ポケモンリーグ こうにんの\nストーンバッジを うけとってね$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{JPN}{PLAYER}は ツツジから\n"
	.string "{JPN}ストーンバッジを もらった!$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "{JPN}ストーンバッジは あなたの ポケモンの\n"
	.string "{JPN}こうげきりょくを たかめます.\p"
	.string "{JPN}また たたかいいがいでも ひでんマシン\n"
	.string "{JPN}いあいぎりを つかえるように\l"
	.string "{JPN}なります.\pこれも おもちください.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "{JPN}その わざマシン39ごうには\n"
	.string "{JPN}がんせきふうじが はいっています.\p"
	.string "{JPN}いしを おとして ダメージを あたえ\n"
	.string "{JPN}すばやさも さげるわざです.\p"
	.string "{JPN}わざマシンを つかうと すぐに\n"
	.string "{JPN}ポケモンに わざを おぼえさせ\l"
	.string "{JPN}られます.\n"
	.string "{JPN}わざマシンは いちどしか つかえ\nないので よくかんがえて つかって\lください.$"

RustboroCity_Gym_Text_ExplainRockTombInfinite:
	.string "{JPN}その わざマシン39ごうには\n"
	.string "{JPN}がんせきふうじが はいっています.\p"
	.string "{JPN}いしを おとして ダメージを あたえ\n"
	.string "{JPN}すばやさも さげるわざです.\p"
	.string "{JPN}わざマシンを つかうと すぐに\n"
	.string "{JPN}ポケモンに わざを おぼえさせ\l"
	.string "{JPN}られます.\n"
	.string "{JPN}わざマシンは なんどでも つかえる\nので たのしんでください.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "{JPN}あなたは とても つよいので ほかの\n"
	.string "{JPN}ジムリーダーにも ちょうせん\l"
	.string "{JPN}するべきです.\p"
	.string "{JPN}おおくの トレーナーと たたかえば\nいろいろなことを まなべるでしょう.$"

RustboroCity_Gym_Text_GymStatue:
	.string "{JPN}カナズミシティ ポケモンジム$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "{JPN}カナズミシティ ポケモンジム\p"
	.string "{JPN}ツツジに みとめられた トレーナー:\n"
	.string "{JPN}{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ピッ!\p"
	.string "{JPN}ツツジ: もしもし {PLAYER}?\n"
	.string "{JPN}カナズミシティの ツツジよ\p"
	.string "{JPN}トウキから きいたけど すごい\n"
	.string "{JPN}いきおいで トレーナーの\l"
	.string "{JPN}ランクを あげてるのね\p"
	.string "{JPN}わたしが きみに かてないなんて\n"
	.string "{JPN}おもいたくないの\p"
	.string "{JPN}わたしの ジムを きたえなおして\n"
	.string "{JPN}きみに また ちょうせん\l"
	.string "{JPN}してもらえるように するわ\p"
	.string "{JPN}そのとき きみも たのしみに\n"
	.string "{JPN}していてくれるといいな!\p"
	.string "{JPN}... ... ... ... ... ...\n... ... ... ... ... ガチャ!$"
RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "{JPN}ジムリーダー ツツジを\n"
	.string "{JPN}ポケナビに とうろく した.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "{JPN}ツツジ: また おあいできて\n"
	.string "{JPN}とても うれしいです.\l"
	.string "{JPN}わたし ジムリーダーの ツツジです.\p"
	.string "{JPN}ぜんかい あってから わたしたちは\n"
	.string "{JPN}たくさんの たたかいを けいけん\l"
	.string "{JPN}したでしょうね.\pどのくらい つよくなったか\nみせてもらいましょう.\lたたかいましょう!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "{JPN}くう...\n"
	.string "{JPN}また まけちゃった...$"
RustboroCity_Gym_Text_RoxannePostRematch:
	.string "{JPN}ツツジ: ポケモンバトルについては\n"
	.string "{JPN}まだまだ まなぶことが たくさん\l"
	.string "{JPN}あります.\n"
	.string "{JPN}そのことが わかるからこそ\nたたかいが もっと すきに\lなるのです!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "{JPN}ツツジ: また あえて うれしいわ\n"
	.string "{JPN}わたし ここの ジムリーダーの\l"
	.string "{JPN}ツツジよ\p"
	.string "{JPN}まえに あってから\n"
	.string "{JPN}おたがい たくさんの たたかいを\l"
	.string "{JPN}けいけん したでしょうね\n"
	.string "{JPN}どれだけ つよくなったか\n"
	.string "{JPN}みてみたいわ...\p"
	.string "{JPN}あら...\n"
	.string "{JPN}ポケモンが 1ぴきしか\lいないのね?\pもう 1ぴき いじょう つれて\nまた きてちょうだい$"
