MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_ROD, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROD
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_ROD, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "{JPN}やまの ゆたかな ふんいきが\n"
	.string "{JPN}ぼくの ちょうのうりょくを\l"
	.string "{JPN}たかめてくれた!\p"
	.string "{JPN}きみの ような こどもが...\nかてる ゆめを みるのかい?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "{JPN}じこあわれみに おぼれる...$"
MtPyre_3F_Text_WilliamPostBattle:
	.string "{JPN}ちょうのうりょくは かくじつに\n"
	.string "{JPN}すうばい つよくなったのに...$"
MtPyre_3F_Text_KaylaIntro:
	.string "{JPN}あはははは!\p"
	.string "{JPN}ここは こどもの くるところ\n"
	.string "{JPN}じゃないよ  とくに きみは!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "{JPN}みごとに まけちゃった...$"
MtPyre_3F_Text_KaylaPostBattle:
	.string "{JPN}これは まだまだ しゅぎょうが\n"
	.string "{JPN}たりない ってことね...\p"
	.string "{JPN}ちょうじょうを めざして\n"
	.string "{JPN}がんばらなくちゃ...\p"
	.string "{JPN}がんばれ わたし!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "{JPN}なぜ ここに きたの?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "{JPN}すごいわね!\n"
	.string "{JPN}あなたは とても とくべつな\nトレーナーよ.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "{JPN}もう この よに いない ポケモン\n"
	.string "{JPN}いま きみと いっしょの ポケモン\p"
	.string "{JPN}そして しょうらい であう\n"
	.string "{JPN}ポケモンたちも...\p"
	.string "{JPN}みんな ひとしく たいせつな そんざい\n"
	.string "{JPN}それを わすれないで ほしいの$"

MtPyre_3F_Text_GabrielleRegister:
	.string "{JPN}きみの ポケモンたちが\n"
	.string "{JPN}もっと せいちょうしたとき みてみたいわ...\n"
	.string "{JPN}ポケナビを みせて もらえる?$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "{JPN}あら あなたね...\p"
	.string "{JPN}せいちょうした ポケモンたちを\n"
	.string "{JPN}みせに きてくれたの?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "{JPN}すばらしいわ!\n"
	.string "{JPN}あなたは とくべつな ひとね.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "{JPN}もう この よに いない ポケモン\n"
	.string "{JPN}いま きみと いっしょの ポケモン\p"
	.string "{JPN}そして しょうらい であう\n"
	.string "{JPN}ポケモンたちも...\p"
	.string "{JPN}みんな ひとしく たいせつな そんざい\n"
	.string "{JPN}それを おぼえていて くれたのね$"

