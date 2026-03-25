Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_NewFisher:
	.string "{JPN}きをつけろ このみずには\n"
	.string "{JPN}きょうぼうなやつがすんでいる.$"

Route12_Text_FisherMartinSeen:
	.string "{JPN}がまんづよさがつりと\n"
	.string "{JPN}ポケモンりょうほうのかぎだ.$"

Route12_Text_FisherMartinBeaten:
	.string "{JPN}ぐわああ!$"

Route12_Text_FisherMartinAfterBattle:
	.string "{JPN}つりには せっかちすぎる\nせいかくなんだ...$"
Route12_Text_FisherStephenSeen:
	.string "{JPN}ラジオをききながらつりを\n"
	.string "{JPN}していると とてもらくな\l"
	.string "{JPN}きもちになるよ.$"

Route12_Text_FisherStephenBeaten:
	.string "{JPN}ばかなラジオがきをちらした!$"

Route12_Text_FisherStephenAfterBattle:
	.string "{JPN}カントーのラジオばんぐみを\n"
	.string "{JPN}ちぇっくしたかい?ここでは\l"
	.string "{JPN}いろんなばんぐみがきけるよ.$"

Route12_Text_FisherBarneySeen:
	.string "{JPN}わたしたちのにちじょうせいかつで\n"
	.string "{JPN}もっともたいせつなものはなんだ?$"

Route12_Text_FisherBarneyBeaten:
	.string "{JPN}こたえはつぎにでてくるよ!$"

Route12_Text_FisherBarneyAfterBattle:
	.string "{JPN}でんきがにちじょうせいかつで\n"
	.string "{JPN}もっともたいせつなものだと\l"
	.string "{JPN}おもうよ.\p"
	.string "{JPN}そうでなければ はつでんしょが\n"
	.string "{JPN}こしょうしたときに ひとびとが\l"
	.string "{JPN}あんなにさわがなかった\l"
	.string "{JPN}はずだからね.$"

Route12_Text_FisherKyleSeen:
	.string "{JPN}おぼえているかい?$"

Route12_Text_FisherKyleBeaten:
	.string "{JPN}おぼえているのかい?$"

Route12_Text_FisherKyleAfterBattle:
	.string "{JPN}つりざおに ポケモンが\n"
	.string "{JPN}かかったときの てごたえ...\p"
	.string "{JPN}つりしにとっては\n"
	.string "{JPN}それが いちばんの よろこびさ$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "{JPN}12ばんどうろ\p"
	.string "{JPN}きたへ シオンタウン$"

Route12_Text_FishingSpotSign:
	.string "{JPN}つりスポット$"

