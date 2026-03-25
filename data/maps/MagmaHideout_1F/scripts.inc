MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	goto_if_set FLAG_DEFEATED_ENTEI, MagmaHideout_End
	goto_if_set FLAG_UNLOCK_DOGS, MagmaHideout_Entei_CryFaint
	end

MagmaHideout_Entei_CryFaint::
	playmoncry SPECIES_ENTEI, CRY_MODE_FAINT
	release
	end

MagmaHideout_End::
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_RICHARDO, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "{JPN}マグマだんの てんこのとき\n"
	.string "{JPN}ならんだ じゅんばんで だいじな\l"
	.string "{JPN}ばんにんの しごとが きまるんだ\p"
	.string "{JPN}だから おれは こんな すみっこに\n"
	.string "{JPN}いるんだ\lいつも てんこに おくれるからな!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "{JPN}いつも くんれんに\n"
	.string "{JPN}おくれちゃうんだよ!\p"
	.string "{JPN}よわっちいって いわれても\nしかたないかな...$"
MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "{JPN}よーし これからは\n"
	.string "{JPN}もうちょっと がんばって\nみるよ...$"
MagmaHideout_1F_Text_Grunt2Intro:
	.string "{JPN}われらの ボスが えんとつやまを\n"
	.string "{JPN}ほれと いったから ほって ほって\p"
	.string "{JPN}ほっていたら とんでもないものを\n"
	.string "{JPN}はっけんしちまったんだ!\p"
	.string "{JPN}なにを みつけたって?\p"
	.string "{JPN}ふはははは!\n"
	.string "{JPN}おれに かったら おしえてやるぜ!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "{JPN}あああ!\n"
	.string "{JPN}やられた!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "{JPN}やっぱり おしえてやらないぜ\n"
	.string "{JPN}むこうに いけば わかるからな!\p"
	.string "{JPN}サプライズは さいごまで とって\n"
	.string "{JPN}おいたほうが いいだろ?$"

