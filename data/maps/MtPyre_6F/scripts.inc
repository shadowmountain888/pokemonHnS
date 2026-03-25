MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_GRUNT_8, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "{JPN}ここにいると...\n"
	.string "{JPN}ふしぎなちからが\nながれこんでくるの...$"
MtPyre_6F_Text_ValerieDefeat:
	.string "{JPN}ちからが\nひいていく...$"
MtPyre_6F_Text_ValeriePostBattle:
	.string "{JPN}きっとそのちからは\n"
	.string "{JPN}ここでねむっている\nポケモンたちのれいからね...$"
MtPyre_6F_Text_ValerieRegister:
	.string "{JPN}ふふふ... しょうぶには\n"
	.string "{JPN}まけちゃったけど...\n"
	.string "{JPN}こんなのうりょくがあるの...\p"
	.string "{JPN}あなたのポケナビに\nてをふれることなく...\nえいっ!$"
MtPyre_6F_Text_ValerieRematchIntro:
	.string "{JPN}あなたのうしろに...\n"
	.string "{JPN}なにかいるわ...$"
MtPyre_6F_Text_ValerieRematchDefeat:
	.string "{JPN}なにかがきえていった...$"
MtPyre_6F_Text_ValeriePostRematch:
	.string "{JPN}ここでねむっている\n"
	.string "{JPN}ポケモンたちは...\nときどきあそんでいるの...$"
MtPyre_6F_Text_CedricIntro:
	.string "{JPN}みちに まよって しまったのかい?\n"
	.string "{JPN}だいじょうぶだよ ぼくが いるから!$"

MtPyre_6F_Text_CedricDefeat:
	.string "{JPN}まよって いなかったのかい?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "{JPN}まよったトレーナーは\n"
	.string "{JPN}あわてててかてそうだと\n"
	.string "{JPN}おもったんだ.\pきたないてだし\nもうやらないよ...$"
