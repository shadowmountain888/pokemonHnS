Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_BikerRileySeen:
	.string "{JPN}おい きみ!ジョウトちほう\nから きたんだな?$"

Route17_Text_BikerRileyBeaten:
	.string "{JPN}うわあ つよいじゃないか!$"

Route17_Text_BikerRileyAfterBattle:
	.string "{JPN}ちょうしに のるなよ \nジョウトの やつめ!$"

Route17_Text_BikerJoelSeen:
	.string "{JPN}わあ.かっこいい\nじてんしゃだな!$"

Route17_Text_BikerJoelBeaten:
	.string "{JPN}でも きみは かっこいいだけじゃ\nないんだな...$"
Route17_Text_BikerJoelAfterBattle:
	.string "{JPN}おれは かっこよく みえるけど\n"
	.string "{JPN}よわいから ほんとうは\n"
	.string "{JPN}かっこよくないんだ.\pもっと きたえなくちゃ...$"
Route17_Text_BikerGlennSeen:
	.string "{JPN}おい!スピードしょうぶ\nしないか?$"

Route17_Text_BikerGlennBeaten:
	.string "{JPN}うひゃあ!すごい\nパワーだ!$"

Route17_Text_BikerGlennAfterBattle:
	.string "{JPN}りょうてばなしは\n"
	.string "{JPN}サイクリングロードで\nかっこいいと されるんだ.$"

Route17_Text_BikerCharlesSeen:
	.string "{JPN}おれたちは きょうふしらずの\nハイウェイスターさ!$"

Route17_Text_BikerCharlesBeaten:
	.string "{JPN}ぐわあああ!クラッシュだ!$"

Route17_Text_BikerCharlesAfterBattle:
	.string "{JPN}むぼうな うんてんは\n"
	.string "{JPN}じこの もと!\nきを つけろよ!$"

