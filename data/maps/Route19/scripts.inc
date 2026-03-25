Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_Text_SwimmermHaroldSeen:
	.string "{JPN}よなかの うみで およいだ\n"
	.string "{JPN}ことは あるかい?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "{JPN}ぶくぶく...$"
Route19_Text_SwimmermHaroldAfterBattle:
	.string "{JPN}よるの うみは まっくろに\n"
	.string "{JPN}なって のみこまれそうに\nなるんだ$"

Route19_Text_SwimmermTuckerSeen:
	.string "{JPN}はあ はあ... あと... すこしで...\p"
	.string "{JPN}フスベに... とうちゃく...$"
Route19_Text_SwimmermTuckerBeaten:
	.string "{JPN}おぼれちゃう!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "{JPN}かのじょと いっしょに\n"
	.string "{JPN}フスベまで およぐって... はあ...$"
Route19_Text_SwimmerfDawnSeen:
	.string "{JPN}よわむしは だいきらい!$"

Route19_Text_SwimmerfDawnBeaten:
	.string "{JPN}およぎなら まけないのに...$"
Route19_Text_SwimmerfDawnAfterBattle:
	.string "{JPN}フスベから ふたごじままで\n"
	.string "{JPN}およぐのは かんたんよ...\p"
	.string "{JPN}まったく かれしったら\n"
	.string "{JPN}なさけないったら ありゃしない!$"

Route19_Text_SwimmermJeromeSeen:
	.string "{JPN}およぎ? ぼくは へたくそ\n"
	.string "{JPN}なんだ\p"
	.string "{JPN}あさい ところで バシャ\nバシャ してるだけさ$"

Route19_Text_SwimmermJeromeBeaten:
	.string "{JPN}かてると おもったのに$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "{JPN}およぎは へたでも うみが\n"
	.string "{JPN}だいすきなんだ$"

Route19_Text_Fisher1:
	.string "{JPN}すまない この みちは\n"
	.string "{JPN}こうじちゅうで とおれない\p"
	.string "{JPN}グレンとうに いきたいなら\n"
	.string "{JPN}マサラタウンから みなみに\n"
	.string "{JPN}いくといいよ$"

Route19_Text_Kingler:
	.string "{JPN}キングラー: キーーーーーーッ$"

Route19_Text_Fisher1_RocksCleared:
	.string "{JPN}あせかいちゃった およぎに\nいこう!$"

Route19_Text_Fisher2:
	.string "{JPN}やれやれ キングラーが\n"
	.string "{JPN}かいがんを ふさいでいるよ$"

Route19_Text_FisherBefore:
	.string "{JPN}キングラーが いなくなるまで\n"
	.string "{JPN}つりは おあずけだな$"

Route19_Text_Fisher2_RocksCleared:
	.string "{JPN}キングラーが やっと\n"
	.string "{JPN}いなくなった!\pやっと つりが できるぞ$"

Route19_Text_Sign:
	.string "{JPN}19ばん すいどう\p"
	.string "{JPN}セキチクシティ - ふたごじま$"

Route19_Text_CarefulSwimmingSign:
	.string "{JPN}ふたごじまへ およいで いく\n"
	.string "{JPN}かたは きをつけて ください\p"
	.string "{JPN}セキチク けいさつ$"

