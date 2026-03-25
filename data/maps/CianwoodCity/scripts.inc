.set LOCALID_CIANWOOD_SUICUNE, 1
.set LOCALID_CIANWOOD_EUSINE, 2
.set LOCALID_CIANWOOD_CHUCKSWIFE, 6

CianwoodCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CianwoodCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CianwoodCity_EventScript_InitializeSuicune
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CianwoodCity_RemoveEusine::
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	end

CianwoodCity_OnFrame::
	map_script_2 VAR_GETFLY, 1, CianwoodCity_EventScript_Flytrigger
	.2byte 0

CianwoodCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CIANWOOD_CITY
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

CianwoodCity_EventScript_InitializeSuicune::
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 2, CianwoodCity_EventScript_InitializeNothing
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_InitializeNothing::
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_Flytrigger::
	lock
	playse SE_PIN
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, CianwoodCity_Movement_ChucksWife
	waitmovement 0
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
	closemessage
	setvar VAR_GETFLY, 2
	release
	end

CianwoodCity_Movement_ChucksWife:
	walk_left
	walk_left
	walk_up
	walk_left
	face_up
	step_end

CianwoodCity_EventScript_Test::
	lock
	random 2
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	release
	end

CianwoodCity_EventScript_ChucksWife::
	lock
	faceplayer
	checkitem ITEM_HM_FLY
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_ChucksWifeAlreadyHasFly
	msgbox CianwoodCity_Text_ChucksWifeEasierToFly, MSGBOX_DEFAULT
	goto_if_set FLAG_BADGE05_GET, CianwoodCity_EventScript_ChucksWifeGiveFly
	msgbox CianwoodCity_Text_ChucksWifeBeatChuck, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeGiveFly::
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeAlreadyHasFly::
	msgbox CianwoodCity_Text_ChucksWifeChubby, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_ChucksWifeEasierToFly:
	.string "{JPN}あのうみをわたってきたの？\n"
	.string "{JPN}それはたいへんだったでしょ\p"
	.string "{JPN}ポケモンがそらをとぶわざを\n"
	.string "{JPN}おぼえていればらくなんだけど..$"
CianwoodCity_Text_ChucksWifeBeatChuck:
	.string "{JPN}ジムバッジがないとつかえないのよ\n"
	.string "{JPN}あなたこのまちのジムリーダーに\l"
	.string "{JPN}かったらまたいらっしゃい\l"
	.string "{JPN}いいものをあげるから$"
CianwoodCity_Text_ChucksWifeGiveHM:
	.string "{JPN}それはタンバのジムバッジ！\p"
	.string "{JPN}じゃあこのひでんマシンを\n"
	.string "{JPN}もっていくといいわ$"
CianwoodCity_Text_ChucksWifeFlySpeech:
	.string "{JPN}そらをとぶをおぼえさせると\n"
	.string "{JPN}いままでいったばしょに\l"
	.string "{JPN}いっしゅんでいけるようになるわ$"
CianwoodCity_Text_ChucksWifeChubby:
	.string "{JPN}ふふふうちのだんな\n"
	.string "{JPN}あなたにまけたからとっくんね\p"
	.string "{JPN}いいのよさいきん\n"
	.string "{JPN}おなかたるんできてたから$"
CianwoodCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Youngster:
	.string "{JPN}そらをとぶわざがつかえると\n"
	.string "{JPN}アサギシティにもすぐいけるよね！$"
CianwoodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokefanM:
	.string "{JPN}まちのきたにあるいわをくだくと\n"
	.string "{JPN}いろんなものがでてくるんだわ\p"
	.string "{JPN}いわをこわしたきゃ\n"
	.string "{JPN}ポケモンにいわくだきを\l"
	.string "{JPN}させりゃあいいんだわ$"
CianwoodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Lass:
	.string "{JPN}ジムリーダーのシジマさん\n"
	.string "{JPN}かくとうポケモンきたえるのに\l"
	.string "{JPN}じぶんがあいてしてあげるのよ$"
CianwoodCity_EventScript_SuicuneTrigger::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune3
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	delay 30
	playbgm MUS_HG_EUSINE, TRUE
	clearflag FLAG_HIDE_CIANWOOD_EUSINE
	addobject LOCALID_CIANWOOD_EUSINE
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine1
	waitmovement 0
	delay 55
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine2
	waitmovement 0 
	msgbox CianwoodCity_Text_EusineSuicune, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EUSINE, CianwoodCity_Text_EusineBeaten
	playbgm MUS_HG_EUSINE, TRUE
	msgbox CianwoodCity_Text_EusineAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine3
	waitmovement 0
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setflag FLAG_HIDE_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 2
	setvar VAR_CIANWOOD_CITY_STATE, 2
	fadedefaultbgm
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, CianwoodCity_EventScript_DoneJohtoSuicune
	release
	end

CianwoodCity_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

CianwoodCity_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	face_down
	step_end

CianwoodCity_Movement_Suicune2:
	jump_down
	jump_2_down
	jump_right
	face_up
	step_end

CianwoodCity_Movement_Suicune3:
	jump_2_down
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

CianwoodCity_Movement_Eusine1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	step_end

CianwoodCity_Movement_Eusine2:
	face_up
	walk_up
	walk_up
	step_end

CianwoodCity_Movement_Eusine3:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CianwoodCity_Text_EusineSuicune:
	.string "{JPN}よう{PLAYER}\p"
	.string "{JPN}いまの..\n"
	.string "{JPN}スイクンじゃなかったか？\p"
	.string "{JPN}ちょっとしかみえなかったが\n"
	.string "{JPN}うみのうえをスイクンが\l"
	.string "{JPN}はしっていったようにみえたぜ..\p"
	.string "{JPN}スイクンはうつくしくてりりしい\p"
	.string "{JPN}しかもものすごいはやさで\n"
	.string "{JPN}まちやみちをかけめぐる\p"
	.string "{JPN}すばらしい\p"
	.string "{JPN}わたしももっとちかくで\n"
	.string "{JPN}スイクンをみてみたいのだが..\p"
	.string "{JPN}よし！\p"
	.string "{JPN}トレーナーであるきみとたたかって\n"
	.string "{JPN}わたしもスイクンにみとめてもらう\p"
	.string "{JPN}さっそくしょうぶだ！\n"
	.string "{JPN}いくぞ{PLAYER}！$"
CianwoodCity_Text_EusineBeaten:
	.string "{JPN}くやしいが\nきみのかちだ..$"
CianwoodCity_Text_EusineAfter:
	.string "{JPN}すごいぜ{PLAYER}！\p"
	.string "{JPN}スイクンがきみのようすを\n"
	.string "{JPN}うかがっていたわけが\l"
	.string "{JPN}すこしわかったきがするよ..\p"
	.string "{JPN}とにかくわたしはこのまま\n"
	.string "{JPN}スイクンをさがしつづけてみる\p"
	.string "{JPN}きみとはまたどこかで\n"
	.string "{JPN}あうかもしれないなじゃあ！$"
CianwoodCity_EventScript_CitySign::
	lock
	msgbox CianwoodCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_Sign:
	.string "{JPN}ここは タンバシティ\pあらなみよせる うみのまち$"
CianwoodCity_EventScript_GymSign::
	lock
	msgbox CianwoodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_GymSign:
	.string "{JPN}タンバシティポケモンジム\n"
	.string "{JPN}リーダーシジマ\l"
	.string "{JPN}うなるこぶしでかたるおとこ$"
CianwoodCity_EventScript_Pharmacy::
	lock
	msgbox CianwoodCity_Text_PharmacySign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_PharmacySign:
	.string "{JPN}ここはタンバくすりや\p"
	.string "{JPN}そうぎょう500ねん\n"
	.string "{JPN}くすりのそうだんまっております$"
CianwoodCity_EventScript_CaveSign::
	lock
	msgbox CianwoodCity_Text_Safari, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_EventScript_Engineer::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Safari:
	.string "{JPN}がけっぷちのほらあな\nサファリゾーンへのみち$"
CianwoodCity_Text_Engineer:
	.string "{JPN}このみちは こうじちゅうです\nあたらしいサファリゾーンの\lじゅんびをしているのです！$"