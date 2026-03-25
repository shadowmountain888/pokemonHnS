MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_NARD, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "{JPN}なに なに なに?\p"
	.string "{JPN}ここには マグマだんの\n"
	.string "{JPN}メンバーしか はいれない\n"
	.string "{JPN}はずなのに!\p"
	.string "{JPN}でも きみは マグマだんの\n"
	.string "{JPN}ユニフォームを きていない...\p"
	.string "{JPN}あやしいやつだ!\nしょうぶだ!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "{JPN}あいたた...\n"
	.string "{JPN}マグマだんいんとしての\nプライドが...$"
MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "{JPN}もし さむけが するなら\n"
	.string "{JPN}マグマだんに はいるべきだ$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "{JPN}ちょっと まて!\p"
	.string "{JPN}おれが だまって\n"
	.string "{JPN}とおしてくれると おもうか?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "{JPN}うわあ!\n"
	.string "{JPN}まいったよ!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "{JPN}そのまま みのがして\n"
	.string "{JPN}おけば よかったかも\nしれない...$"
MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "{JPN}あはっ!\n"
	.string "{JPN}しんにゅうしゃだ!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "{JPN}ぐらあああ!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "{JPN}もう まけちゃったよ\p"
	.string "{JPN}ほんとうに ぐるぐる はしり\n"
	.string "{JPN}まわる ひつようが あるのか?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "{JPN}おお おお!\n"
	.string "{JPN}しんにゅうしゃだ!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "{JPN}ぶつぶつ...$"
MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "{JPN}じつは せんとうは\nそんなに とくいじゃ\nないんだ...$"
