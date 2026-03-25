MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "{JPN}ここは わたしたち ドラゴン\n"
	.string "{JPN}つかいが しゅぎょうする ばしょだ.\p"
	.string "{JPN}チャンピオンも おとずれる.\n"
	.string "{JPN}どれだけ とくべつな ばしょか\nわかるだろう?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "{JPN}ぐぬう!\n"
	.string "{JPN}こんなに つよいとは おもわなかった!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "{JPN}さきの みちは まだまだ\n"
	.string "{JPN}ながく きびしい.\p"
	.string "{JPN}いつになったら わたしと ポケモンは\nさいきょうに なれるのだろうか?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "{JPN}きみの ちからを もっと しりたい.\n"
	.string "{JPN}ポケナビに とうろくさせてくれ.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "{JPN}であってから わたしたちは\n"
	.string "{JPN}いちばんを めざして きたえた.\p"
	.string "{JPN}どれだけ つよくなったか\n"
	.string "{JPN}みせてくれ!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "{JPN}ぐぬう!\n"
	.string "{JPN}こんなに つよいとは おもわなかった!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "{JPN}きみは あきらかに ポケモンの\n"
	.string "{JPN}しゅぎょうを つづけているな.\p"
	.string "{JPN}きみが つよい かぎり わたしも\n"
	.string "{JPN}もっと つよくなれる!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "{JPN}ジョン: わたしたちは いつも\n"
	.string "{JPN}ふたりで ポケモンバトルを\l"
	.string "{JPN}してきました. じしんが あります.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "{JPN}ジョン: おやおや.\n"
	.string "{JPN}まけてしまいました つまよ.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "{JPN}ジョン: わたしたちは けっこん\n"
	.string "{JPN}して 50ねんに なります.\p"
	.string "{JPN}そういえば つまとの バトルでは\n"
	.string "{JPN}いちども かったことが ありません.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "{JPN}ジョン: おお わかい トレーナー!\p"
	.string "{JPN}わたしたちと バトルしますか?\n"
	.string "{JPN}そうなら もっと ポケモンを\nつれてきて ください.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "{JPN}ジョン: わかい トレーナーよ\n"
	.string "{JPN}また きかいが あったら\nバトルして くれませんか?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "{JPN}ジェイ: わたしたちは けっこん\n"
	.string "{JPN}して 50ねんに なります.\p"
	.string "{JPN}ふうふの きずなは ぜったいに\n"
	.string "{JPN}きれることは ありません.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "{JPN}ジェイ: あらあら.\n"
	.string "{JPN}まけてしまいました おっとさん.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "{JPN}ジェイ: けっこんして ごじゅうねん...\p"
	.string "{JPN}けんかを したときは いつも\n"
	.string "{JPN}ポケモンしょうぶで かいけつしたのう...$"
MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "{JPN}ジェイ: まあまあ わかい\n"
	.string "{JPN}トレーナーね.\p"
	.string "{JPN}わたしたちと バトルするなら\n"
	.string "{JPN}もっと ポケモンを つれてきて\nちょうだい.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "{JPN}ジョン: わたしたちは いつも\n"
	.string "{JPN}ふたりで ポケモンバトルを\l"
	.string "{JPN}してきました. じしんが あります.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "{JPN}ジョン: おやおや.\n"
	.string "{JPN}まけてしまいました つまよ.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "{JPN}ジョン: けっこんして ごじゅうねん...\p"
	.string "{JPN}ふりかえってみれば あいぼうと\n"
	.string "{JPN}まいにち しょうぶの あけくれじゃった...$"
MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "{JPN}ジョン: おお わかい トレーナー!\p"
	.string "{JPN}わたしたちと バトルしますか?\n"
	.string "{JPN}そうなら もっと ポケモンを\nつれてきて ください.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "{JPN}ジェイ: わたしたちは けっこん\n"
	.string "{JPN}して 50ねんに なります.\p"
	.string "{JPN}ずっと ささえあって つよく\n"
	.string "{JPN}なってきました.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "{JPN}ジェイ: あらあら.\n"
	.string "{JPN}まけてしまいました おっとさん.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "{JPN}ジェイ: けっこんして ごじゅうねん...\n"
	.string "{JPN}いろいろな ことが あったのう.\p"
	.string "{JPN}これからも いっしょに\n"
	.string "{JPN}たのしい おもいでを つくりたいものじゃ.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "{JPN}ジェイ: まあまあ わかい\n"
	.string "{JPN}トレーナーね.\p"
	.string "{JPN}わたしたちと バトルするなら\n"
	.string "{JPN}もっと ポケモンを つれてきて\nちょうだい.$"

