MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "{JPN}こわいものが だいすきなの...\n"
	.string "{JPN}びょうきみたいに...\p"
	.string "{JPN}ここにいると...\n"
	.string "{JPN}こわくて ふるえちゃう...$"
MtPyre_4F_Text_TashaDefeat:
	.string "{JPN}まけるのは きらい...$"
MtPyre_4F_Text_TashaPostBattle:
	.string "{JPN}おそろしいものが みたいの...\n"
	.string "{JPN}はなれられない...\p"
	.string "{JPN}いて...\n"
	.string "{JPN}わたしと いっしょにいて?$"

