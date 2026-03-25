Route40_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "{JPN}みずにはいるまえには\n"
	.string "{JPN}じゅんびうんどうが ひつようだ.\p"
	.string "{JPN}それが きほんだよ.$"

Route40_Text_SwimmermSimonBeaten:
	.string "{JPN}まいった! まけだ!$"

Route40_Text_SwimmermSimonAfter:
	.string "{JPN}タンバシティは\n"
	.string "{JPN}ここから かなりとおいぞ.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "{JPN}きみは わかくて\n"
	.string "{JPN}げんきそうだな!\p"
	.string "{JPN}ポケモンに のるんじゃなくて\nおよごうぜ!$"

Route40_Text_SwimmermRandallBeaten:
	.string "{JPN}あーあ.まけちゃった...$"
Route40_Text_SwimmermRandallAfter:
	.string "{JPN}すいえいは ぜんしんうんどうに\n"
	.string "{JPN}なるから けんこうてきだよ.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "{JPN}タンバシティに いくの?\p"
	.string "{JPN}\n"
	.string "{JPN}ちょっと しょうぶしない?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "{JPN}まけちゃった!$"

Route40_Text_SwimmerfElaineAfter:
	.string "{JPN}およぎなら あなたより\n"
	.string "{JPN}うまいとおもうわ. そうよ!$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "{JPN}うきわなんて いらないの.\p"
	.string "{JPN}うみの ポケモンに\n"
	.string "{JPN}つかまってるから!$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "{JPN}うう  めがまわる!$"

Route40_Text_SwimmerfPaulaAfter:
	.string "{JPN}こうやって うかんでいると\n"
	.string "{JPN}なみが はこんでくれるの.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "{JPN}ここからは みえないけれど\n"
	.string "{JPN}タンバシティは うみのむこうよ.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "{JPN}ふねで アサギシティに きて\n"
	.string "{JPN}けしきを みたり ふんいきを\l"
	.string "{JPN}あじわったりしてるの.\p"
	.string "{JPN}みなとまちだから\n"
	.string "{JPN}おおきなまちとは ちがうかんじ.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "{JPN}トレーナーズスクールには\n"
	.string "{JPN}iったことある?\p"
	.string "{JPN}つよいトレーナーたちが\n"
	.string "{JPN}もう たくさんあつまってると\l"
	.string "{JPN}おもうよ.\p"
	.string "{JPN}でも きみは バッジを\nたくさんもってるから\lだいじょうぶだよ.$"

Route40_Text_Monica:
	.string "{JPN}モニカ: はじめまして.\n"
	.string "{JPN}わたし ようびきょうだいの\l"
	.string "{JPN}モニカよ.\p"
	.string "{JPN}わたしのすきな ようびが\nなにか あててみて!$"

Route40_Text_MonicaGivesGift:
	.string "{JPN}せいかい!\p"
	.string "{JPN}ともだちのしるしに\n"
	.string "{JPN}プレゼントがあるの!$"

Route40_Text_MonicaGaveGift:
	.string "{JPN}モニカ: ひこうタイプのわざの\n"
	.string "{JPN}いりょくを あげるどうぐよ.\p"
	.string "{JPN}とりの ポケモンに\n"
	.string "{JPN}mたせてあげて.$"

Route40_Text_MonicaMonday:
	.string "{JPN}モニカ: わたしの きょうだいは\n"
	.string "{JPN}あちこちに いるのよ.\p"
	.string "{JPN}みんなを さがしてみて!$"
	.string ""

Route40_Text_MonicaNotMonday:
	.string "{JPN}モニカ: きょうは\n"
	.string "{JPN}げつようびじゃないみたい.\lざんねんだなあ...$"
Route40_Text_MonicaNope:
	.string "{JPN}それは ちがうわ.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
