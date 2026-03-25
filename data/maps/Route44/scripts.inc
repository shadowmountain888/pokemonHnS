Route44_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
    .string "{JPN}うわあ!\p"
	.string "{JPN}ニョロモを にがしちゃったじゃ\n"
    .string "{JPN}ないか!\nどうしてくれるんだ?$"

Route44_Text_FisherWilton1Beaten:
    .string "{JPN}まあ わすれてくれ$"

Route44_Text_FisherWiltonHugePoliwag:
    .string "{JPN}にげられた あの ニョロモ...\n"
	.string "{JPN}でかかったなあ.\p"
    .string "{JPN}ぜったい 16フィートは\n"
	.string "{JPN}あったぞ!$"

Route44_Text_FisherEdgarSeen:
    .string "{JPN}つれなくなるまで つりを する\p"
	.string "{JPN}たたかえなくなるまで バトルを\n"
    .string "{JPN}する\p"
	.string "{JPN}それが おれと ポケモンとの\nかんけいだ$"

Route44_Text_FisherEdgarBeaten:
    .string "{JPN}うーん... これは おかしいな.$"
Route44_Text_FisherEdgarAfter:
    .string "{JPN}100しょう 101はい だ\p"
	.string "{JPN}しばらく バトルは やめておく$"

Route44_Text_BirdKeeperVance1Seen:
    .string "{JPN}でんせつの とりポケモンに\n"
	.string "{JPN}ついて しってるかい?$"

Route44_Text_BirdKeeperVance1Beaten:
    .string "{JPN}ふう! きみは つよいな$"

Route44_Text_BirdKeeperVanceBirds:
    .string "{JPN}フリーザー サンダー ファイヤーが\n"
	.string "{JPN}3びきの でんせつの とりポケモンだ\p"
    .string "{JPN}ほかにも でんせつの とりが\n"
	.string "{JPN}いるって きいたことがあるよ$"

Route44_Text_PsychicPhilSeen:
    .string "{JPN}ぜったいに かつぞ!$"

Route44_Text_PsychicPhilBeaten:
    .string "{JPN}うわあ... しょうげきてきな\nまけかただ...$"
Route44_Text_PsychicPhilAfter:
    .string "{JPN}しんねんを もつことが\n"
	.string "{JPN}たいせつなんだ$"

Route44_Text_PokemaniacZachSeen:
    .string "{JPN}めずらしい ポケモンの ためなら\n"
	.string "{JPN}なんでも するぞ!$"

Route44_Text_PokemaniacZachBeaten:
    .string "{JPN}うう きみの ポケモンは\n"
	.string "{JPN}とても みりょくてきだ$"

Route44_Text_PokemaniacZachAfter:
    .string "{JPN}いつもと ちがう いろの ポケモンは\n"
	.string "{JPN}かちが あるんだ\p"
    .string "{JPN}え? そんなことないって?$"

Route44_Text_CooltrainermAllenSeen:
    .string "{JPN}みただけで きみが いい\n"
	.string "{JPN}トレーナーだって わかるよ\p"
    .string "{JPN}おれは ポケモンが とくいで\n"
	.string "{JPN}きみも そうだって みえる$"

Route44_Text_CooltrainermAllenBeaten:
    .string "{JPN}ちっ! かんぺきに まけだ$"

Route44_Text_CooltrainermAllenAfter:
    .string "{JPN}わあ たくさん バッジを もってる\n"
	.string "{JPN}ね\p"
    .string "{JPN}どうりで つよいわけだ\p"
	.string "{JPN}エンジュジムの マツバは まだ\n"
    .string "{JPN}しゅぎょうちゅう かな?\pおれ こてんぱんに やられたよ$"

Route44_Text_CooltrainerfCybilSeen:
    .string "{JPN}つよそうね\n"
	.string "{JPN}いい トレーナーは ほんのうてきに\n"
    .string "{JPN}つよい あいてを さがすのよ$"

Route44_Text_CooltrainerfCybilBeaten:
    .string "{JPN}だめ! これじゃあ ぜんぜん\nだめよ$"

Route44_Text_CooltrainerfCybilAfter:
    .string "{JPN}たくさんの バトルを けいけん\n"
	.string "{JPN}して みんな つよくなるのよ\p"
    .string "{JPN}たくさん たたかって いまの\n"
	.string "{JPN}わたし エリートに なったの$"

Route44_Text_Sign1:
    .string "{JPN}44ばんどうろ\n"
	.string "{JPN}こおりのぬけみち さき$"

Route44_Text_Sign2:
    .string "{JPN}ここは44ばんどうろ\n"
	.string "{JPN}ひがしフスベシティ$"
