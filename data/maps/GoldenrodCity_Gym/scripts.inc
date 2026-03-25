.set LOCALID_GOLDENROD_CITY_GYM_BRIDGET, 6

GoldenrodCity_Gym_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "{JPN}コガネシティポケモンジム$"
GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "{JPN}コガネシティポケモンジム\p"
	.string "{JPN}ジムリーダーアカネ\nにんていトレーナー!\l{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
	.string "{JPN}アカネ: はーい!\nうちがアカネちゃーん!!\p"
	.string "{JPN}...ってあんた\nさっきラジオとうにおったひと?\l"
	.string "{JPN}トレーナーさんやったんやね\p"
	.string "{JPN}みんなポケモンしてるやん?\nうちもはじめたら\l"
	.string "{JPN}もーめっちゃかわいーて!\p"
	.string "{JPN}え?うちにちょうせんするの?\nゆうとくけどうち\lめっちゃつよいでー!\p$"
GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
	.string "{JPN}アカネ: うう...\p"
	.string "{JPN}...うわーん!!\nひどいよひどいよ!!\p"
	.string "{JPN}むきになんないでよ!!\nもおこどもなんやから...$"
GoldenrodCity_Gym_Text_WhitneyYouMeanie:
	.string "{JPN}アカネ: わーん!!\p"
	.string "{JPN}わーん!!\p"
	.string "{JPN}...ぐっすんひっぐ\n...ひどいわー!!$"
GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
	.string "{JPN}アカネ: ...ぐすん\p"
	.string "{JPN}なに?まだなんかあんの?\nああバッジ?\p"
	.string "{JPN}ごめんわすれてた\nはいレギュラーバッジ\lこれがほしいんやろ!\p$"
GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
	.string "{JPN}{PLAYER}はアカネから\nレギュラーバッジをもらった!$"
GoldenrodCity_Gym_Text_WhitneyPlainBadge:
	.string "{JPN}アカネ: レギュラーバッジがあると\nたたかってないときでも\l"
	.string "{JPN}かいりきのわざがつかえるんよ\p"
	.string "{JPN}あとはこれもあげる!\p$"
GoldenrodCity_Gym_Text_WhitneyAttract:
	.string "{JPN}アカネ: なかみはメロメロゆーて\nポケモンのみりょくを\l"
	.string "{JPN}さいだいげんにつかうわざやねん\lかわいーうちにぴったしやろ?\p"
	.string "{JPN}あそや!\p"
	.string "{JPN}ここからきたにある\nしぜんこうえんのとなりに\l"
	.string "{JPN}ポケスロンゆーきょうぎじょうが\lオープンしたんやて!\p"
	.string "{JPN}あんたそんだけ\nポケモンつかうのうまいんやから\l"
	.string "{JPN}いってみたほうがええよ?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
	.string "{JPN}アカネ: ふう!\nないたらすっきりしたわ!\p"
	.string "{JPN}ほなまたあそびにおいでーな!\nバイバイ!$"
GoldenrodCity_Gym_Text_WhitneyRematch:
	.string "{JPN}あ！あなたね！\pわあージョウトちほうの\nチャンピオンになったのね？\pほんとうにすごいわ！\pあなたのつよさをみてみたい\nの！さいせんしない？$"
GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "{JPN}わーん！！\p"
	.string "{JPN}わーん！！\p"
	.string "{JPN}..ぐっすんひっぐ\n"
	.string "{JPN}..ひどいわー！！$"
GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "{JPN}うちの ポケモンの\n"
	.string "{JPN}かわいい みために\n"
    .string "{JPN}だまされちゃ だめよ.\pあなたを やっつけるから!$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "{JPN}くそー... よわいとおもってたのに...$"
GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "{JPN}うちの ポケモンは\nわたしのこと かわいいって\nおもってくれてるかしら?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
	.string "{JPN}わたしはつよいポケモンより\nかわいいポケモンがすき！\pでもつよくてかわいい\nポケモンももってるのよ！$"
GoldenrodCity_Gym_Text_LassBridgetBeaten:
	.string "{JPN}あらあらあら！$"
GoldenrodCity_Gym_Text_LassBridgetAfter:
	.string "{JPN}アカネさんにかとうとしてる\nんだけど..へこんじゃう\pでもだいじょうぶ！まけても\nつぎはがんばるわ！$"
GoldenrodCity_Gym_Text_BridgetWhitneyCries:
	.string "{JPN}あーあアカネちゃん\nなかしちゃったのね\p"
	.string "{JPN}だいじょうぶ!\nしばらくしたらなきやむから\l"
	.string "{JPN}まけるといつもないちゃうのよ\p$"
GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
	.string "{JPN}あらかわいいトレーナーね！\pきにいったけどてかげんは\nしないわよ！$"
GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
	.string "{JPN}えーっと..あらもうおわり？$"
GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
	.string "{JPN}わたしにかつなんてじょうず\nなのね！がんばって！$"
GoldenrodCity_Gym_Text_BeautySamanthaSeen:
	.string "{JPN}ぜんりょくでこないと\nやられちゃうわよ！$"
GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
	.string "{JPN}だめ！ああニャースごめんね！$"
GoldenrodCity_Gym_Text_BeautySamanthaAfter:
	.string "{JPN}ニャースにはどんなタイプにも\nたいこうできるわざをおしえたのに.$"
GoldenrodCity_Gym_Text_GymGuide:
	.string "{JPN}おーす!\nみらいのチャンピオン!\p"
	.string "{JPN}このジムは\nノーマルタイプポケモンの\lつかいてがあつまっている!\p"
	.string "{JPN}たたかわせるなら\nかくとうタイプの\lポケモンがおすすめだな!$"
GoldenrodCity_Gym_Text_GymGuideWin:
	.string "{JPN}かったか?それはよかった!\nおれはおんなのこにみとれていたよ$"
