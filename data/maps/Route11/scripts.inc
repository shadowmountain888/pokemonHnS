Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end


Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_Text_Engineer:
	.string "{JPN}きのうえを のぼっている\n"
	.string "{JPN}へんな ポケモンを みたんだ\l"
	.string "{JPN}でも マンキーじゃ なかったよ...$"

Route11_Text_YoungsterOwenSeen:
	.string "{JPN}ポケモンしょうぶに\n"
	.string "{JPN}ずるは ないんだ!\pこうせいどうどうと いこうぜ!$"

Route11_Text_YoungsterOwenBeaten:
	.string "{JPN}えっ? どうして こうなったの?$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "{JPN}ほこりを もって こうせい\n"
	.string "{JPN}doudouと たたかったぞ\p"
	.string "{JPN}ぜんぜん こうかいしてない$"

Route11_Text_YoungsterJasonSeen:
	.string "{JPN}くさむらで たんパンを はくと\n"
	.string "{JPN}ちょっと かゆくて くすぐったい$"

Route11_Text_YoungsterJasonBeaten:
	.string "{JPN}あいやー! ふみつぶされた!$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "{JPN}くさむらで もっと ポケモンを\n"
	.string "{JPN}つかまえるつもりなんだ$"

Route11_Text_PsychicHermanSeen:
	.string "{JPN}...$"
Route11_Text_PsychicHermanBeaten:
	.string "{JPN}...$"
Route11_Text_PsychicHermanAfterBattle:
	.string "{JPN}...\p"
	.string "{JPN}めを とじてたのに まけちゃった...$"
Route11_Text_PsychicFidelSeen:
	.string "{JPN}みえるよ...\p"
	.string "{JPN}きみの すべてが みえる...$"
Route11_Text_PsychicFidelBeaten:
	.string "{JPN}きみの ちからは よそくできなかった...$"
Route11_Text_PsychicFidelAfterBattle:
	.string "{JPN}しんねんの つよさ...\p"
	.string "{JPN}きみは ポケモンを しんじているから\n"
	.string "{JPN}つよいんだ$"

Route11_Text_Sign:
	.string "{JPN}11ばん どうろ$"

