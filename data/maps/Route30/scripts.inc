.set LOCALID_ROUTE_30_JOEY, 6

Route30_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 30
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "{JPN}ポケモンじいさんのいえ$"
Route30_Text_UseTackle:
	.string "{JPN}いけっコラッタ！\p"
	.string "{JPN}たいあたりっ！！$"
Route30_Text_ThisIsABigBattle:
	.string "{JPN}なんだよ？\n"
	.string "{JPN}だいじなしょうぶなんだ！\l"
	.string "{JPN}むこうにいっててよ！$"
Route30_Text_YoungsterJoey1Seen:
	.string "{JPN}いま まけちゃったから\n"
	.string "{JPN}もっと ポケモンを\l"
	.string "{JPN}さがしてるんだ.\p"
	.string "{JPN}まて! きみ よわそうだな!\nさあ しょうぶだ!$"

Route30_Text_YoungsterJoey1Beaten:
	.string "{JPN}あー! また まけちゃった!\n"
	.string "{JPN}ちくしょう!$"

Route30_Text_YoungsterJoey1After:
	.string "{JPN}もっと ポケモンが いないと\n"
	.string "{JPN}つよく なれないのかな?\p"
	.string "{JPN}いや! この こだけで\n"
	.string "{JPN}がんばるんだ!$"

Route30_Text_YoungsterMikeySeen:
	.string "{JPN}きみ ポケモントレーナー\n"
	.string "{JPN}でしょ?\p"
	.string "{JPN}なら しょうぶしなくちゃ!$"

Route30_Text_YoungsterMikeyBeaten:
	.string "{JPN}おかしいなあ.\n"
	.string "{JPN}まえは かったのに.$"

Route30_Text_YoungsterMikeyAfter:
	.string "{JPN}いい トレーナーになるのは\n"
	.string "{JPN}ほんとに たいへんだ.\p"
	.string "{JPN}ほかの ひととも しょうぶして\n"
	.string "{JPN}つよく なるんだ.$"

Route30_Text_BugCatcherDonSeen:
	.string "{JPN}むしポケモンの かわりに\n"
	.string "{JPN}トレーナーを みつけたぞ!$"

Route30_Text_BugCatcherDonBeaten:
	.string "{JPN}うーん! つよすぎるよ!$"

Route30_Text_BugCatcherDonAfter:
	.string "{JPN}ポケモンを つかまえてる\n"
	.string "{JPN}あいだに モンスターボールが\l"
	.string "{JPN}なくなっちゃったよ.\pもっと かっておくべき\nだったなあ...$"
Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "{JPN}ポケモンじいさんの いえ?\n"
	.string "{JPN}もう ちょっと さきだよ.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "{JPN}みんな しょうぶを たのしんで\n"
	.string "{JPN}るよ!\p"
	.string "{JPN}きみも やってみなよ!$"

Route30_Text_CooltrainerF:
	.string "{JPN}わたしトレーナーじゃないわよ\p"
	.string "{JPN}でもトレーナーどうし\n"
	.string "{JPN}しせんがあうのは\l"
	.string "{JPN}しょうぶしようってサインなのよね$"
Route30_Text_Sign:
	.string "{JPN}ここは30ばんどうろ\n"
	.string "{JPN}みなみヨシノシティ$"
Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "{JPN}ここをまっすぐ！\n"
	.string "{JPN}ポケモンじいさんのいえ$"
Route30_Text_MrPokemonsHouseSign:
	.string "{JPN}ポケモンじいさんのいえ$"
Route30_Text_TrainerTips:
	.string "{JPN}おとくなけいじばん！\p"
	.string "{JPN}ひとのポケモン\n"
	.string "{JPN}とったらどろぼう！\p"
	.string "{JPN}モンスターボールはやせいの\n"
	.string "{JPN}ポケモンにだけなげつけよう！$"
Route30_Text_YoungsterJoeyGiveHPUp:
	.string "{JPN}また まけちゃった...\n"
	.string "{JPN}きみって つよいんだね!\p"
	.string "{JPN}そうそう わすれるところ\n"
	.string "{JPN}だったよ.\l"
	.string "{JPN}これ きみに あげる.\p"
	.string "{JPN}これを つかって もっと\n"
	.string "{JPN}つよくなってよ!\pぼくも つよくなるからさ.$"

Route30_Text_Elm_Disaster:
	.string "{JPN}ウツギはかせ: も もしもし?\n"
	.string "{JPN}{PLAYER}くんかい? たいへんだ!\p"
	.string "{JPN}えーっと その とても\n"
	.string "{JPN}ひどいことが おこったんだ!\p"
	.string "{JPN}どうしよう... それが...\n"
	.string "{JPN}あああ...\pすぐに もどってきてくれ!$"


Route30_Text_Poliwag:
	.string "{JPN}ニョロモ: ニョロ ニョロー!$"
