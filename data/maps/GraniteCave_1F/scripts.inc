GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "{JPN}おい きみ.\n"
	.string "{JPN}このさきは ひどく くらいぞ.\l"
	.string "{JPN}たんけんするのは たいへんだ.\p"
	.string "{JPN}\n"
	.string "{JPN}さっき とおっていった やつ...\n"
	.string "{JPN}ダイゴとか いったかな.\p"
	.string "{JPN}\n"
	.string "{JPN}かれは フラッシュを つかえるから\n"
	.string "{JPN}daijoubuだとおもうが...\p"
	.string "{JPN}\nわれわれ ハイカーは であった\nひとを たすけるのが モットーだ.\p\nはい これを きみに わたそう.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "{JPN}かばんに ひでんマシンが あって\n"
	.string "{JPN}おぼえられる ポケモンが いれば\l"
	.string "{JPN}フラッシュが つかえるよ.\p"
	.string "{JPN}おしえる ひつようは ないんだ.\p"
	.string "{JPN}でも つかうには ムロジムの\n"
	.string "{JPN}ジムバッジが いるよ.\p"
	.string "{JPN}どうくつの やみを あかるく\nてらして くれるんだ.$"
