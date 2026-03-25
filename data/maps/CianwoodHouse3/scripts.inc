CianwoodHouse3_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "{JPN}た.たいへんなことに！\pきみとおなじくらいのとしで\nするどいめをしたかみのながい\lやつがやってきたんだ\pおどされてだいじなポケモンを\nとられてしまった！\pまだひとつのこってるけど\nまたもどってきたらどうしよう\pきみはつよそうだ\nしばらくおれのポケモンを\lあずかってくれないか？$"
CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "{JPN}じぶんのポケモンって\n"
	.string "{JPN}ひとにみせたくなるよね！\p"
	.string "{JPN}キキョウのともだちに\n"
	.string "{JPN}ぼくがそだてたポケモン\l"
	.string "{JPN}みせてあげたいな..$"
CianwoodCity_Text_ManiacGotShuckle:
	.string "{JPN}このまちのポケモンジムは\n"
	.string "{JPN}あらくれものばかり！\p"
	.string "{JPN}そばにいるとオレまで\n"
	.string "{JPN}ふっとばされそうだ\p"
	.string "{JPN}だからここでアドバイス\n"
	.string "{JPN}ジムリーダーがつかうのは\l"
	.string "{JPN}かくとうポケモン！\p"
	.string "{JPN}だったらこっちは\n"
	.string "{JPN}エスパーポケモンでまどわしてやれ！\l"
	.string "{JPN}あいてがパワーをはっきするまえに\l"
	.string "{JPN}たおしてやるんだ！\p"
	.string "{JPN}それから..\n"
	.string "{JPN}ジムリーダーのシジマは\l"
	.string "{JPN}たきでのしゅぎょうにむちゅうだ！\p"
	.string "{JPN}なんとかしてたきをとめないと\n"
	.string "{JPN}いくらはなしかけても\l"
	.string "{JPN}きみのこえはきこえやしない！$"
CianwoodCity_Text_ManiacPartyFull:
	.string "{JPN}あなたにもついっぱいよ$"
CianwoodCity_Text_ManiacIfHeComesBack:
	.string "{JPN}あれ？もしかしてきみ..\n"
	.string "{JPN}ポケモン1ひきしかもってないの？\l"
	.string "{JPN}それじゃこまるでしょー\p"
	.string "...\p"
	.string "{JPN}よーし！\n"
	.string "{JPN}ぼくのメノクラゲをあげる！\p"
	.string "{JPN}ちょっとつかまえすぎちゃってね\n"
	.string "{JPN}にがそうかとおもってたやつだから\l"
	.string "{JPN}えんりょはいらないよ！$"
CianwoodCity_Text_ManiacHowsdoing:
	.string "{JPN}メノクラゲに\n"
	.string "{JPN}ニックネームをつけますか？$"
CianwoodCity_Text_ManiacAskReturn:
	.string "{JPN}{PLAYER}は\n"
	.string "{JPN}メノクラゲをもらった！$"
CianwoodCity_Text_ManiacThankYou:
	.string "{JPN}ありがとう!$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "{JPN}おい おれのポケモンを\nもってないじゃないか$"
CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "{JPN}わたしの ポケモンが\n"
	.string "{JPN}きみを きにいったようだ.\p"
	.string "{JPN}よし  きみが もっていなさい.\pでも やさしく してくれよ!$"

CianwoodCity_Text_ManiacRobbed:
	.string "{JPN}あれ？なんかへんだ$"
CianwoodCity_Text_ManiacRobbed2:
	.string "{JPN}ああ だめだめ...\n"
	.string "{JPN}それじゃあ どろぼうに\nあったのと おなじだよ.$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "{JPN}ポケモンにとって しあわせとは\n"
	.string "{JPN}やさしく してくれるひとと\nいっしょに いることなんだ.$"

CianwoodCity_Text_ManiacLastMon:
	.string "{JPN}ポケモンをかえしてもらったら\nきみはバトルでなにを\nつかうんだ？$"
CianwoodCity_Text_ManiacReturnedMon:
	.string "{JPN}{PLAYER}はツボツボをかえした$"