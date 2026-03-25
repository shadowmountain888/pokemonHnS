Route31_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_TORMENT
	msgbox Route31_Text_DescribeNightmare, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "{JPN}くらやみのほらあな..\n"
	.string "{JPN}ポケモンがあたりを\l"
	.string "{JPN}あかるくするわざをつかえたらなあ\l"
	.string "{JPN}なかをしらべてやるのに$"
Route31_Text_BugCatcherWade1_Seen:
	.string "{JPN}ポケモンを たくさん\n"
	.string "{JPN}つかまえたんだ.\lきみと バトルしよう!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "{JPN}あーあー...$"
Route31_Text_BugCatcherWade1_After:
	.string "{JPN}ポケモンを 6ひき もっていても\n"
	.string "{JPN}つかまえることが できるよ.\p"
	.string "{JPN}つかまえると じどうてきに\n"
	.string "{JPN}ボックスに おくられるんだ.$"

Route31_Text_SleepyMan:
	.string "{JPN}うーんムニャムニャ..\p"
	.string "{JPN}ポケモンさがしであるきすぎた\n"
	.string "{JPN}あしはいたいしねむたいし..\p"
	.string "{JPN}ぼくがやせいのポケモンだったら\n"
	.string "{JPN}つかまりやすいじょうたいだ..\l"
	.string "{JPN}ぐう..スヤスヤ..$"
Route31_Text_SleepyManGotMail:
	.string "{JPN}...zzz... ん?\p"
	.string "{JPN}なんだって? わたしに\n"
	.string "{JPN}メールを もってきたの?$"

Route31_Text_SleepyManFail:
	.string "{JPN}...zzz...$"
Route31_Text_HandOverMailMon:
	.string "{JPN}{PLAYER}はメールをもった\n"
	.string "{JPN}ポケモンをわたした！$"
Route31_Text_ReadingMail:
	.string "{JPN}えーっと...\p"
	.string "{JPN}とどけてくれて\n"
	.string "{JPN}ありがとう.\p"
	.string "{JPN}ともだちは いいやつだし\n"
	.string "{JPN}きみも いいひとだね!\p"
	.string "{JPN}わたしも なにか\n"
	.string "{JPN}おれいを したいよ!\p"
	.string "{JPN}そうだ! これを\n"
	.string "{JPN}きみに あげよう!$"

Route31_Text_DescribeNightmare:
	.string "{JPN}この わざマシンには いちゃもん\n"
	.string "{JPN}が はいってる.\p"
	.string "{JPN}あいてを イライラさせて\n"
	.string "{JPN}おなじ わざを つづけて\l"
	.string "{JPN}つかえなくする\pいやらしい わざなんだ.$"

Route31_Text_WrongMail:
	.string "{JPN}これはぼくあての\n"
	.string "{JPN}メールじゃないみたい..\p"
	.string "{JPN}ぐぅ..$"
Route31_Text_MissingMail:
	.string "{JPN}どうして この ポケモンが\n"
	.string "{JPN}とくべつなんだ?\pメールを もってないじゃないか.$"

Route31_Text_DeclinedToHandOverMail:
	.string "{JPN}なんだって? なにも\n"
	.string "{JPN}いらないって?$"

Route31_Text_CantTakeLastMon:
	.string "{JPN}その ポケモンを もらったら\n"
	.string "{JPN}きみは\p"
	.string "{JPN}バトルで なにを つかうんだ?$"
	.string ""

Route31_Text_Youngster:
	.string "{JPN}くらやみのほらあなで\n"
	.string "{JPN}いいポケモンつかまえた！\p"
	.string "{JPN}こいつをきたえて\n"
	.string "{JPN}キキョウのジムリーダー\l"
	.string "{JPN}ハヤトにしょうぶをいどむぜ！$"
Route31_Text_Sign:
	.string "{JPN}31ばんどうろ\p"
	.string "{JPN}キキョウシティ - ヨシノシティ$"

Route31_Text_DarkCaveSign:
	.string "{JPN}ここはくらやみのほらあな$"