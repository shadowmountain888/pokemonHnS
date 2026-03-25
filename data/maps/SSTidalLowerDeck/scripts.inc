SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "{JPN}あーあ!こんなに ひろい\n"
	.string "{JPN}ばしょを そうじするのに\l"
	.string "{JPN}うんざりで くたくただよ!\pちょっと バトルしない?$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "{JPN}おとうと まけちゃった!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "{JPN}おれたちは\n"
	.string "{JPN}クリーンアップブラザーズ!\p"
	.string "{JPN}あにが せんざいを まいて\nおとうとが ごしごし\lこするんだ!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "{JPN}ここは ふねの いちばん\n"
	.string "{JPN}したの ぶぶんだよ.\l"
	.string "{JPN}ひろくて じゅうぶんだから\nポケモンバトルも だいじょうぶ!$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "{JPN}あにさん まけちゃった!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "{JPN}ぼくたちは\n"
	.string "{JPN}クリーンアップブラザーズ!\p"
	.string "{JPN}あにが せんざいを まいて\nおとうとが ごしごし\lこするんだ!$"

