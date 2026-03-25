MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_CINDY, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "{JPN}せんせい...\n"
	.string "{JPN}ぼくのせいちょうを\nみまもっていてください!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "{JPN}せんせい...\n"
	.string "{JPN}おゆるしください!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "{JPN}ぼくがじょうたつするまで\n"
	.string "{JPN}ここにねむるせんせいは\nほんとうのやすらぎを\nえることはないでしょう...$"
