Route43_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
    .string "{JPN}ぼくは ポケモンが だいすきだ!\p"
	.string "{JPN}だから はじめたんだし これからも\n"
    .string "{JPN}ポケモンを あつめつづけるよ!$"

Route43_Text_PokemaniacBenBeaten:
    .string "{JPN}どうして こんなことを するんだ?$"

Route43_Text_PokemaniacBenAfter:
    .string "{JPN}ポケモン いがいに すきなものは\n"
	.string "{JPN}なにかって?\p"
    .string "{JPN}ラジオの マリーちゃんだよ きっと\n"
	.string "{JPN}かわいいんだろうなあ!$"

Route43_Text_PokemaniacBrentSeen:
    .string "{JPN}おい! きみ めずらしい\n"
	.string "{JPN}ポケモン もってる?$"

Route43_Text_PokemaniacBrentBeaten:
    .string "{JPN}ああ かわいそうな ぼくの\nポケモンたち!$"

Route43_Text_PokemaniacBrentAfter:
    .string "{JPN}めずらしい ポケモンを 1ぴきでも\n"
	.string "{JPN}もてれば うれしいんだけどなあ$"

Route43_Text_PokemaniacRonSeen:
    .string "{JPN}しんじられるかい?\p"
	.string "{JPN}{RIVAL}って やつが ぼくの\n"
    .string "{JPN}ポケモンを ばかにしたんだ!\p"
	.string "{JPN}くそう! ぼくの ポケモンは\nすごいんだぞ!$"

Route43_Text_PokemaniacRonBeaten:
    .string "{JPN}ぼくの ニドキング よく\nがんばったよな!$"

Route43_Text_PokemaniacRonAfter:
    .string "{JPN}ひとそれぞれ ちがう タイプの\n"
	.string "{JPN}ポケモンを すきになっていいんだ\p"
    .string "{JPN}ポケモンは いちばん つよいのを\n"
	.string "{JPN}もつだけじゃ ないんだよ$"

Route43_Text_FisherMarvinSeen:
    .string "{JPN}さいきん ちょうしが わるいんだ\p"
	.string "{JPN}たぶん つかってる どうぐが\n"
    .string "{JPN}わるいんだろうな\pきぶんてんかんに しょうぶしよう!$"

Route43_Text_FisherMarvinBeaten:
    .string "{JPN}まけちゃったけど きぶんは\nよくなったよ$"

Route43_Text_FisherMarvinAfter:
    .string "{JPN}ガンテツの ルアーボールが\n"
	.string "{JPN}つりあげた ポケモンには さいこうだ\p"
    .string "{JPN}ハイパーボールより ずっと\n"
	.string "{JPN}こうかてきなんだ$"

Route43_Text_CamperSpencerSeen:
    .string "{JPN}ぼくの ポケモンと いろんなことが\n"
	.string "{JPN}できて とても たのしいよ!$"

Route43_Text_CamperSpencerBeaten:
    .string "{JPN}まけるのは ちっとも\nたのしくないよ...$"
Route43_Text_CamperSpencerAfter:
    .string "{JPN}いかりのみずうみで なにが\n"
	.string "{JPN}おこってるんだろう?\pそこで キャンプする よていだったのに$"

Route43_Text_PicnickerTiffanySeen:
    .string "{JPN}あなたも いかりのみずうみに\n"
	.string "{JPN}いくの?\pちょっと あそんでいかない?$"

Route43_Text_PicnickerTiffanyBeaten:
    .string "{JPN}あそびすぎちゃった!$"

Route43_Text_PicnickerTiffanyWantsPicnic:
    .string "{JPN}ポケモンと いっしょに\n"
	.string "{JPN}ピクニックしてるの\pいっしょに どう?$"

Route43_Sign1:
    .string "{JPN}43ばんどうろ\p"
	.string "{JPN}いかりのみずうみ - チョウジタウン$"

Route43_Sign2:
    .string "{JPN}43ばんどうろ\p"
	.string "{JPN}いかりのみずうみ - チョウジタウン$"

Route43_TrainerTips:
    .string "{JPN}トレーナーの こころえ\p"
	.string "{JPN}ポケモンは タイプによって\n"
    .string "{JPN}とくいふとくいが あります\p"
	.string "{JPN}タイプが ちがえば レベルの\n"
    .string "{JPN}たかい ポケモンでも まけることが\p"
	.string "{JPN}じぶんの ポケモンの タイプに\n"
    .string "{JPN}つよいもの よわいものを おぼえよう$"
