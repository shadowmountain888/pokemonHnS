.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_STEVEN_REMATCH, MeteorFalls_StevensCave_EventScript_StevenRematch
	goto_if_set FLAG_DEFEATED_RED, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RED
	setflag FLAG_SIDNEY_REMATCH
	setflag FLAG_PHOEBE_REMATCH
	setflag FLAG_GLACIA_REMATCH
	setflag FLAG_DRAKE_REMATCH
	setflag FLAG_WALLACE_REMATCH
	release
	end

MeteorFalls_StevensCave_EventScript_StevenRematch::
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst2, MSGBOX_DEFAULT
	setflag FLAG_SYS_SET_BATTLE_BGM
	setvar VAR_TEMP_F, MUS_HG_VS_CHAMPION
	trainerbattle_no_intro TRAINER_STEVEN2, MeteorFalls_StevensCave_Text_StevenDefeat2
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue2, MSGBOX_DEFAULT
	clearflag FLAG_STEVEN_REMATCH
	goto_if_unset FLAG_ARCEUS_EGG_GIVE MeteorFalls_StevensCave_EventScript_StevenArceusEvent
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEvent::
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent1, MSGBOX_DEFAULT
	setflag FLAG_ARCEUS_EGG_GIVE
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_ARCEUS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeteorFalls_StevensCave_EventScript_StevenArceusEventToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeteorFalls_StevensCave_EventScript_StevenArceusEventToPC
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEventToParty::
	call Common_EventScript_GetGiftMonPartySlot
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent2, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEventToPC::
	call Common_EventScript_TransferredToPC
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent2, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ArceusEvent1:
	.string "{JPN}それと...いわをほっていたときに\n"
	.string "{JPN}みつけたものを\l"
	.string "{JPN}きみにあげたいんだ.\p"
	.string "{JPN}ふしぎなたまごなんだ.\p"
	.string "{JPN}\n"
	.string "{JPN}かれこれなんしゅうかんも\n"
	.string "{JPN}もちあるいているんだが\lかえらないんだよ.\pきみのほうがぼくよりも\nうでのいいトレーナーだから\lかえせるかもしれないね.$"

MeteorFalls_StevensCave_Text_ArceusEvent2:
	.string "{JPN}いわのあいだにたまごをうんで\n"
	.string "{JPN}いってしまうポケモンって\l"
	.string "{JPN}なんだろうね...\p"
	.string "{JPN}もしかしてこだいの\nポケモンなのかな?\pふふふ...だれにも\nわからないさ...$"
MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "{JPN}ダイゴ:おお {PLAYER}くん.\n"
	.string "{JPN}ぼくをここでみつけるなんて\l"
	.string "{JPN}すごいじゃないか.\p"
	.string "{JPN}きみはもしかして...ぼくのことを\n"
	.string "{JPN}ただのいしマニアだと\l"
	.string "{JPN}おもっているのかい?\p"
	.string "{JPN}いや そんなことはないよね.\p"
	.string "{JPN}\n"
	.string "{JPN}トクサネうちゅうセンターで\n"
	.string "{JPN}いっしょにたたかったじゃないか.\p"
	.string "{JPN}ぼくのうでまえは\nよくわかっているはずだ.\pよし {PLAYER}くん ほんきで\nちょうせんしてくるなら\lおぼえごをしたほうがいいぞ!$"

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst2:
	.string "{JPN}ダイゴ: おお やあ {PLAYER}{KUN}.\p"
	.string "{JPN}もどってきたんだね.ミクリから\n"
	.string "{JPN}きみが かれと してんのう ぜんいんを\l"
	.string "{JPN}また たおしたって きいたよ.すごいね!\p"
	.string "{JPN}ぼくも つよくなったんだ.また\n"
	.string "{JPN}ほんきで しょうぶしてもらえるかい?\p"
	.string "{JPN}よし {PLAYER}{KUN} いくぞ!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "{JPN}きみは...\n"
	.string "{JPN}こんなにつよくなっていたとは\lおもわなかった...$"
MeteorFalls_StevensCave_Text_StevenDefeat2:
	.string "{JPN}きみは...\n"
	.string "{JPN}もうだれもきみをこえることは\lできないだろう.$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "{JPN}ダイゴ:そういえば デボンの\n"
	.string "{JPN}カナシダトンネルで\l"
	.string "{JPN}はじめてであったときから\p"
	.string "{JPN}きみはいつかチャンピオンに\n"
	.string "{JPN}なるだろうとかんじていたんだ.\p"
	.string "{JPN}ぼくのよそうはたいてい\n"
	.string "{JPN}あたるんだよ.\p"
	.string "{JPN}それで これからどこへ\n"
	.string "{JPN}いくつもりだい?\p"
	.string "{JPN}...\n"
	.string "{JPN}...\p"
	.string "{JPN}ふふふ こんなのはどうだい?\p"
	.string "{JPN}\nしてんのうに\nもういちどちょうせんして\lみるといい.かなりつよくなった\nそうだぞ.どうおもう?$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue2:
	.string "{JPN}ダイゴ:そういえば デボンの\n"
	.string "{JPN}カナシダトンネルで\l"
	.string "{JPN}はじめてであったときから\p"
	.string "{JPN}きみはいつかぼくよりも\n"
	.string "{JPN}つよくなるだろうとかんじていた.\p"
	.string "{JPN}ぼくのよそうはたいてい\n"
	.string "{JPN}あたるんだよ.\p"
	.string "{JPN}それで これからどこへ\n"
	.string "{JPN}いくつもりだい?\p"
	.string "{JPN}...\n...\pふふふ それはぼくにも\nわからないよ.$"
