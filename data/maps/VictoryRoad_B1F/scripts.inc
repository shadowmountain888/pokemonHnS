VictoryRoad_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_PRYCE_1, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "{JPN}ポケモンリーグに\n"
	.string "{JPN}ちかづいてるって\n"
	.string "{JPN}おもうと...\pあがっちゃうなあ...$"
VictoryRoad_B1F_Text_SamuelDefeat:
	.string "{JPN}なにも できなかった...$"
VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "{JPN}ポケモンリーグが\n"
	.string "{JPN}また とおくなった...\nがっかりだよ...$"
VictoryRoad_B1F_Text_ShannonIntro:
	.string "{JPN}ポケモンリーグをかちぬくには\n"
	.string "{JPN}ポケモンからのしんらいが\l"
	.string "{JPN}ひつようよ$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "{JPN}あなたたちのかんけいは\n"
	.string "{JPN}たしかなしんらいでむすばれてる$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "{JPN}いつもいっしょにいることで\n"
	.string "{JPN}ポケモンとトレーナーのあいだに\lしんらいがそだつのよ$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "{JPN}ここはゴールじゃないわ\n"
	.string "{JPN}ポケモンリーグへのとおりみち\lにすぎないのよ$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "{JPN}そのちょうしよ!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "{JPN}きっとだいじょうぶ!\n"
	.string "{JPN}あなたのポケモンたち\lやるきまんまんね!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "{JPN}わたしのポケモンは\n"
	.string "{JPN}うちゅうてきに\lいあつかんがあるぞ!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "{JPN}きみのようなひとに\nあったことがない$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "{JPN}たたかいのそとでも\n"
	.string "{JPN}きみときみのポケモンから\l"
	.string "{JPN}しんじられないパワーをかんじる$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "{JPN}おっけー きにしないで!\n"
	.string "{JPN}リラックスして\lらくにいこうよ!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "{JPN}おお!\n"
	.string "{JPN}すばらしい!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "{JPN}たしかにここはチャンピオンロード\p"
	.string "{JPN} でも いままでのみちのりと\n"
	.string "{JPN}そんなにかわらないよ\p"
	.string "{JPN} さいごまで\n"
	.string "{JPN}たのしんでいこうね!$"

