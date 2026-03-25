MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "{JPN}おれはリーダーのいうこと\n"
	.string "{JPN}ぜんぶわかるけどさあ...\p"
	.string "{JPN}ちょうこだいポケモンを\n"
	.string "{JPN}ほりおこしたり\l"
	.string "{JPN}ひとのいんせきをうばったり...\p"
	.string "{JPN}ちょっとやりすぎじゃない?\n"
	.string "{JPN}きみはどうおもう?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "{JPN}ああ どこか まちがった\n"
	.string "{JPN}ことを してるんじゃないかな.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "{JPN}きみに まけて あたまが\n"
	.string "{JPN}すっきりしたよ.\p"
	.string "{JPN} ボスに あったら \nぼくらの やってることについて\nきいてみるつもりだ.$"

