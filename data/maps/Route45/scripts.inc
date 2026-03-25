Route45_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "{JPN}なんでも かかってこい!\p"
	.string "{JPN}きみの ポケモンが ちゃんと\n"
    .string "{JPN}そだてられてるか みせてもらおう!$"

Route45_Text_HikerErikBeaten:
    .string "{JPN}あー まけちゃった!$"

Route45_Text_HikerErikAfter:
    .string "{JPN}フスベシティの こおりのぬけみちに\n"
	.string "{JPN}もどって もっと しゅぎょうするよ$"

Route45_Text_HikerMichaelSeen:
    .string "{JPN}よう! きみは げんきだな! でも\n"
	.string "{JPN}しってるか?\p"
    .string "{JPN}げんきさでは おれの ほうが\n"
	.string "{JPN}うえなんだぜ!$"

Route45_Text_HikerMichaelBeaten:
    .string "{JPN}おれの ポケモンの げんきが\nたりなかった!$"

Route45_Text_HikerMichaelAfter:
    .string "{JPN}おとこ マックスアップが\n"
	.string "{JPN}だいすきなんだ! うまい!\p"
    .string "{JPN}ポケモンの ぶんまで のんじゃう!\pやめられないんだ!$"

Route45_Text_HikerParrySeen:
    .string "{JPN}おれの ポケモンは パワーまんてん!$"

Route45_Text_HikerParryBeaten:
    .string "{JPN}わはははは! おれの まけだー!$"

Route45_Text_HikerParryAfter:
    .string "{JPN}おれは あんまり あたまが\n"
	.string "{JPN}よくないんだ\p"
    .string "{JPN}だから パワーで つっぱしるのさ!$"


Route45_Text_HikerTimothySeen:
    .string "{JPN}なぜ やまに のぼるのか?\p"
	.string "{JPN}そこに やまが あるからだ\p"
    .string "{JPN}なぜ ポケモンを そだてるのか?\p"
	.string "{JPN}そこに ポケモンが いるからだ!$"

Route45_Text_HikerTimothyBeaten:
    .string "{JPN}まけ... それも あるんだな!$"
Route45_Text_HikerTimothyAfter:
    .string "{JPN}ポケモンと であったことが\n"
	.string "{JPN}じんせいで いちばんの しあわせだ$"

Route45_Text_HikerParryGivesIron:
    .string "{JPN}どうしても かつ ほうほうが\n"
	.string "{JPN}みつからない!\p"
    .string "{JPN}がんばれよ!\p"
	.string "{JPN}そうそう これを もってけ--\n"
    .string "{JPN}まえに あえなかった とき あげる\nはずだった プレゼントだ$"

Route45_Text_BlackbeltKenjiSeen:
    .string "{JPN}ひとりで ここで しゅぎょうしてた\p"
	.string "{JPN}おれの しゅぎょうの せいかを\nみるがいい!$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "{JPN}うわああああ!$"

Route45_Text_BlackbeltKenjiAfter:
    .string "{JPN}これは とくべつな しゅぎょうが\n"
	.string "{JPN}ひつようだな\p"
    .string "{JPN}やまごもりして ひとりで\nしゅぎょうしなければ$"

Route45_Text_BlackbeltKenjiMorning:
    .string "{JPN}ひるめしまえに もうちょっと\n"
	.string "{JPN}しゅぎょうするつもりだ$"

Route45_Text_BlackbeltKenjiNight:
    .string "{JPN}ひるめしで じゅうぶん やすんだ\p"
	.string "{JPN}これで また やるきまんまんだ!\n"
    .string "{JPN}また しゅぎょうするぞ!$"

Route45_Text_CooltrainermRyanSeen:
    .string "{JPN}ポケモンを そだてることについて\n"
	.string "{JPN}どう おもう?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "{JPN}きみを そんけいする$"

Route45_Text_CooltrainermRyanAfter:
    .string "{JPN}ポケモンを あいじょうをもって\n"
	.string "{JPN}そだててるのが わかるよ\n"
    .string "{JPN}きずいた きずなが きびしい じょうきょうで\n"
	.string "{JPN}きみを たすけてくれるだろう$"

Route45_Text_CooltrainerfKellySeen:
    .string "{JPN}きみの バトル せんりゃくは?\p"
	.string "{JPN}つよい わざを やみくもに つかうのは\n"
    .string "{JPN}ぐかしゃな ことよ$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "{JPN}いいわ わたしの まけ$"

Route45_Text_CooltrainerfKellyAfter:
    .string "{JPN}わたしは あまりにも つよすぎる\n"
	.string "{JPN}わざは すきじゃないの\n"
    .string "{JPN}かちたいけど ポケモンを\n"
	.string "{JPN}きずつけたくもないから$"

Route45_Text_CamperQuentinSeen:
    .string "{JPN}おれは ほんとうに ほんとうに\nつよいぞ!$"

Route45_Text_CamperQuentinBeaten:
    .string "{JPN}トレーナーヒルでは つよかったのに...$"
Route45_Text_CamperQuentinAfter:
    .string "{JPN}トレーナーヒルには いったことある?\p"
	.string "{JPN}そこでは ぜったい まけないんだけど...$"
Route45_Text_Sign:
    .string "{JPN}ここは45ばんどうろ\n"
	.string "{JPN}このさきマウンテンロード$"