Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "{JPN}トレーナーどうしが であったら\n"
	.string "{JPN}まずは バトルだよね!$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "{JPN}Awww... I've got a losing record...$"
Route1_Text_SchoolboyDanny_AfterBattle:
	.string "{JPN}トレーナーどうしが であったら\n"
	.string "{JPN}バトルするのは あたりまえだよ!$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "{JPN}あなた! バトルしない?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "{JPN}Down and out...$"
Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "{JPN}つよいのね.\p"
	.string "{JPN}きっと いっしょうけんめい\n"
	.string "{JPN}くんれんしたのね.$"

Route1_Text_Sign:
	.string "{JPN}1ばん どうろ\p"
	.string "{JPN}マサラタウン - トキワシティ$"
