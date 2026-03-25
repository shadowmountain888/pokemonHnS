MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "{JPN}おれは きみと けんかする\n"
	.string "{JPN}つもりは ないんだ!\lめいれいに したがってるだけさ!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "{JPN}まけたけど...$"
MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "{JPN}しんじられないものを\n"
	.string "{JPN}ほりだしたんだ!\n"
	.string "{JPN}そして あおいたまも てにいれた!\p"
	.string "{JPN}あとは ボスが...\nふふふ... ふわはははは!$"
MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "{JPN}あつさが だめなんだ もしかして\n"
	.string "{JPN}アクアだんに はいるべきだった\nかもしれないな...$"
MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "{JPN}やっぱり ぼくは マグマだんに\n"
	.string "{JPN}むいてないかもしれないな...$"
MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "{JPN}こんな ところに いて\n"
	.string "{JPN}うみが こいしく ならないのか?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "{JPN}ここでは ときどき しんどうが\n"
	.string "{JPN}きこえるんだ\p"
	.string "{JPN}かざんが ゆれてるのかな?\n"
	.string "{JPN}それとも グラ...\p"
	.string "{JPN}わっ!\nいや いや なんでもない!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "{JPN}きみは ねつい バトラーだな.\n"
	.string "{JPN}かざんの ように!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "{JPN}たまたま きみが かっただけで\n"
	.string "{JPN}そんなこと どうでも いいんだ.\p"
	.string "{JPN}マグマだんの もくてきは\n"
	.string "{JPN}もうすぐ たっせい されるのさ!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "{JPN}なかまの ひとりが マグマのしるしを\n"
	.string "{JPN}なくして あわててたんだ...\p"
	.string "{JPN}ちょっと まって!\n"
	.string "{JPN}それを みつけたのは きみか?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "{JPN}しんじるのが むずかしいよ...$"
MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "{JPN}われわれの けいかくは\n"
	.string "{JPN}しっぱいに おわりそうな\nきが してきたよ...$"
