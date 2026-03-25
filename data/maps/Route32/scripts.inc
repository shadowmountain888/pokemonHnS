.set LOCALID_ROUTE32_BALDINGMAN, 1
.set LOCALID_SLOWPOKETAIL_MAN, 14


Route32_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Potion::
	finditem ITEM_POTION
	end
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "{JPN}かーっ！！\n"
	.string "{JPN}またれいーっ！！$"
Route32_Text_CooltrainerM_AideIsWaiting:
	.string "{JPN}{PLAYER}とはおぬしのことだな？\n"
	.string "{JPN}おぬしをさがしとる\l"
	.string "{JPN}メガネのおとこがおったぞ\p"
	.string "{JPN}フレンドリィショップで\n"
	.string "{JPN}おぬしをまっているだろう\l"
	.string "{JPN}いってみなさい！$"
Route32_Text_CooltrainerM_SproutTower:
	.string "{JPN}シントウに いったことは\n"
	.string "{JPN}あるかい?\n"
	.string "{JPN}キキョウシティに いったら\p"
	.string "{JPN}\n"
	.string "{JPN}そこで しゅぎょうすることに\nなるんだ.\pトレーナーの きほんだからね.\p\nシントウに いってみなよ!$"

Route32_Text_CooltrainerM_VioletGym:
	.string "{JPN}ポケモンジムにはいったのか？\n"
	.string "{JPN}ポケモンジムによって\l"
	.string "{JPN}おのれとポケモンをきたえる\p"
	.string "{JPN}トレーナーのじょうしきではないか\n"
	.string "{JPN}いってみなさい！$"
Route32_Text_CooltrainerM_HaveThisSeed:
	.string "{JPN}うむいいポケモンをつれておる\n"
	.string "{JPN}それもこれもキキョウで\l"
	.string "{JPN}いろいろきたえたからだろう\p"
	.string "{JPN}とくにポケモンジムでの\n"
	.string "{JPN}しゅぎょうはためになったはず\p"
	.string "{JPN}よし！キキョウにきたきねんだ\n"
	.string "{JPN}これをもっていきなさい\p"
	.string "{JPN}ポケモンにもたせると\n"
	.string "{JPN}くさタイプのわざのいりょくが\l"
	.string "{JPN}あがるというしろものだ！$"
Route32_Text_CooltrainerM_Experiences:
	.string "{JPN}キキョウでのけいけんは\n"
	.string "{JPN}そなたのたびにやくだつであろう$"
Route32_Text_SlowpokeTailOffer:
	.string "{JPN}うまくてえいようまんてんの\n"
	.string "{JPN}おいしいシッポはいらない？\p"
	.string "{JPN}いまならたったの100まんえん\n"
	.string "{JPN}どうかうでしょ？$"
Route32_Text_ThoughtKidsLoaded:
	.string "{JPN}おかねたりないぞ！\p"
	.string "{JPN}ちっ！さいきんのこどもは\n"
	.string "{JPN}かねもちだとおもってたが..$"
Route32_Text_RefusedSlowpokeTail:
	.string "{JPN}いらないのか！\n"
	.string "{JPN}じゃああっちいった！いった！$"
Route32_Text_FisherJustin_Seen:
	.string "{JPN}うわあ!\p"
	.string "{JPN}\nさかなを にがしちゃったじゃないか!$"

Route32_Text_FisherJustin_Beaten:
	.string "{JPN}ざっぱーん!$"

Route32_Text_FisherJustin_After:
	.string "{JPN}おちついて しずかに...\n"
	.string "{JPN}つりと ポケモンの しんずい\nは おなじなんだ$"

Route32_Text_FisherRalph1_Seen:
	.string "{JPN}つりも ポケモンも\n"
	.string "{JPN}りょうほう とくいなんだ.\p"
	.string "{JPN}\nこどもには まけないぞ!$"

Route32_Text_FisherRalph1_Beaten:
	.string "{JPN}ちっ! あせり\n"
	.string "{JPN}すぎたな...$"
Route32_Text_FisherRalph1_After:
	.string "{JPN}つりは いっしょうの\n"
	.string "{JPN}しゅみだよ.\p"
	.string "{JPN}\nポケモンは いっしょうの\nともだちだ!$"

Route32_Text_FisherHenry_Seen:
	.string "{JPN}おれの ポケモンは\nとれたてだぞ!$"

Route32_Text_FisherHenry_Beaten:
	.string "{JPN}はねる?$"

Route32_Text_FisherHenry_After:
	.string "{JPN}とれたての ポケモンは\n"
	.string "{JPN}よく そだてた ポケモンに\nかなわないなあ.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "{JPN}きみ はじめて みるね.\n"
	.string "{JPN}つよいと おもってるのかい?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "{JPN}つよいなあ!$"

Route32_Text_YoungsterAlbert_After:
	.string "{JPN}ぼくは すきな ポケモンで\n"
	.string "{JPN}さいきょうを めざすんだ.\p"
	.string "{JPN}\n"
	.string "{JPN}みんなと おなじような\nつよい ポケモンは つかわない.$"

Route32_Text_YoungsterGordon_Seen:
	.string "{JPN}くさむらで いい ポケモンを\n"
	.string "{JPN}みつけたんだ!\p"
	.string "{JPN}\nこれなら やってくれるよ!$"

Route32_Text_YoungsterGordon_Beaten:
	.string "{JPN}ちくしょう.かてると\nおもったのに.$"

Route32_Text_YoungsterGordon_After:
	.string "{JPN}くさむらって べたべた\n"
	.string "{JPN}するものが いっぱいだ.$"

Route32_Text_CamperRoland_Seen:
	.string "{JPN}その ひとみ...\nきょうみぶかいな$"
Route32_Text_CamperRoland_Beaten:
	.string "{JPN}あらら\n"
	.string "{JPN}そりゃざんねんだねえ$"
Route32_Text_CamperRoland_After:
	.string "{JPN}バトルしたくないなら\n"
	.string "{JPN}めを あわせないことだ.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "{JPN}うんうん そうそう\n"
	.string "{JPN}それでね...\p"
	.string "{JPN}えっ? しょうぶ?\nでんわちゅうなの\nしかたないわね\nてっとりばやくやりましょ$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "{JPN}ああ! はらがたつわ!$"
	.string ""

Route32_Text_PicnickerLiz1_After:
	.string "{JPN}たのしく おしゃべり\nしてたのに.$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "{JPN}そのバッジ! キキョウシティの\n"
	.string "{JPN}バッジだ!\nハヤトに かったのか?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "{JPN}じぶんの よわさが\nわかったよ.$"

Route32_Text_BirdKeeperPeter_After:
	.string "{JPN}キキョウシティの ジムで\n"
	.string "{JPN}もう いちど しゅぎょうしよう.$"

Route32_Text_RoarIntro:
	.string "{JPN}うおおおっ！\p"
	.string "{JPN}ほえるとみんなにげだすけど\n"
	.string "{JPN}きみはきてくれたあああっ！\l"
	.string "{JPN}かんどうだあああっ！\l"
	.string "{JPN}これをもっていってよおおおっ！$"
Route32_Text_RoarOutro:
	.string "{JPN}うおおおっ！\n"
	.string "{JPN}なかみはほえる！\l"
	.string "{JPN}ほえるとポケモンもにげだすよ$"
Route32_Text_MeetFrieda:
	.string "{JPN}フリーダ: やっほー!\p"
	.string "{JPN}\n"
	.string "{JPN}わたし ようびきょうだいの\n"
	.string "{JPN}フリーダよ! よろしく!\p"
	.string "{JPN}\nわたしの すきな ようびを\nあててくれたら\nごほうびを あげる!$"

Route32_Text_FriedaGivesGift:
	.string "{JPN}どくバリを あげる!$"

Route32_Text_FriedaGaveGift:
	.string "{JPN}フリーダ: どくタイプの わざを\n"
	.string "{JPN}おぼえた ポケモンに\n"
	.string "{JPN}もたせてね.\p"
	.string "{JPN}\n"
	.string "{JPN}お!\p"
	.string "{JPN}\nすごいわよ!\p\nどくの わざが びっくりするほど\nつよくなるの!$"

Route32_Text_FriedaFriday:
	.string "{JPN}フリーダ: やっほー! きみは\n"
	.string "{JPN}なんようびが すき?\p"
	.string "{JPN}\n"
	.string "{JPN}わたしは きんようび!\n"
	.string "{JPN}ぜったい きんようびよ!\p\nきみも すてきだと\nおもわない?$"

Route32_Text_FriedaNope:
	.string "{JPN}フリーダ: それじゃないわ!$"

Route32_Text_Sign1:
	.string "{JPN}ここは32ばんどうろ\n"
	.string "{JPN}みなみヒワダタウン$"
Route32_Text_Sign2:
	.string "{JPN}アルフのいせき\n"
	.string "{JPN}ひがしがわいりぐち$"
Route32_Text_Sign3:
	.string "{JPN}このさきつながりのどうくつ$"