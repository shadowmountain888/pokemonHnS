Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "{JPN}ああ! きょうも いい てんきだなあ!$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "{JPN}はれてるのに びしょぬれ\nだよ...$"
Route3_Text_FirebreatherOtis_AfterBattle:
	.string "{JPN}あめが ふると ひを\n"
	.string "{JPN}つけるのが たいへんなんだ...$"
Route3_Text_YoungsterWarren_Seen:
	.string "{JPN}うーん... どうしたら\nいいのか わからない...$"
Route3_Text_YoungsterWarren_Beaten:
	.string "{JPN}やっぱり まけちゃった...$"
Route3_Text_YoungsterWarren_AfterBattle:
	.string "{JPN}きみは つよそうだったから\p"
	.string "{JPN}\nたたかうのが こわかったんだ...$"
Route3_Text_YoungsterJimmy_Seen:
	.string "{JPN}おれは かぜのように はやく はしれるんだ!$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "{JPN}ふきとばされちゃった!$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "{JPN}おれは いちねんじゅう たんパンなんだ.\p"
	.string "{JPN}それが おれの ファッション!$"

Route3_Text_FirebreatherBurt_Seen:
	.string "{JPN}さあさあ みていってよ!$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "{JPN}あちち! あついよ!$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "{JPN}カントーで いちばんの\n"
	.string "{JPN}ファイヤーブレサーは ぼくさ\p"
	.string "{JPN}\nでも トレーナーとしては\nいまいちだけどね...$"
Route3_Text_MtMoonSquareSign:
	.string "{JPN}おつきみやま ひろば\p"
	.string "{JPN}かいだんを のぼってね.$"

