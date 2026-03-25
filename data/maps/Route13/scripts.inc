Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route13_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route13_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX Route13_Text_PokefanmAlexSeen, Route13_Text_PokefanmAlexBeaten
	msgbox Route13_Text_PokefanmAlexAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA Route13_Text_PokefanmJoshuaSeen, Route13_Text_PokefanmJoshuaBeaten
	msgbox Route13_Text_PokefanmJoshuaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY Route13_Text_BirdKeeperPerrySeen, Route13_Text_BirdKeeperPerryBeaten
	msgbox Route13_Text_BirdKeeperPerryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Bret::
	trainerbattle_single TRAINER_BRET Route13_Text_BirdKeeperBretSeen, Route13_Text_BirdKeeperBretBeaten
	msgbox Route13_Text_BirdKeeperBretAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY Route13_Text_HikerKennySeen, Route13_Text_HikerKennyBeaten
	msgbox Route13_Text_HikerKennyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_Text_PokefanmAlexSeen:
	.string "{JPN}わたしの おうさまポケモンの\nまえに ひれふすがよい!$"

Route13_Text_PokefanmAlexBeaten:
	.string "{JPN}How... How dare you mock royalty!$"
Route13_Text_PokefanmAlexAfterBattle:
	.string "{JPN}だれでも いつかは おうさまに\n"
	.string "{JPN}なりたいと おもうものでしょう?$"

Route13_Text_PokefanmJoshuaSeen:
	.string "{JPN}にひひ! わたしの ピカチュウだんと\n"
	.string "{JPN}バトルしてみない?$"

Route13_Text_PokefanmJoshuaBeaten:
	.string "{JPN}ピ ピカチュウ!$"

Route13_Text_PokefanmJoshuaAfterBattle:
	.string "{JPN}きみは たくさんの ポケモンを\n"
	.string "{JPN}もってるみたいだけど\l"
	.string "{JPN}やっぱり ピカチュウが さいこうよ.$"

Route13_Text_BirdKeeperPerrySeen:
	.string "{JPN}すばやさこそが とりポケモンの\n"
	.string "{JPN}かぎとなる のうりょくだ.$"

Route13_Text_BirdKeeperPerryBeaten:
	.string "{JPN}You beat me with your speed...$"
Route13_Text_BirdKeeperPerryAfterBattle:
	.string "{JPN}きみの ポケモンは すばらしく\n"
	.string "{JPN}よく きたえられているな.$"

Route13_Text_BirdKeeperBretSeen:
	.string "{JPN}わたしの ポケモンを みてくれ!\n"
	.string "{JPN}この いろどりと はねの\l"
	.string "{JPN}うつくしさを!$"

Route13_Text_BirdKeeperBretBeaten:
	.string "{JPN}ちぇっ! まだまだ だった!$"

Route13_Text_BirdKeeperBretAfterBattle:
	.string "{JPN}ていねいに せわを すると\n"
	.string "{JPN}ポケモンは よろこぶのです.$"

Route13_Text_HikerKennySeen:
	.string "{JPN}イワヤマトンネルに いって\n"
	.string "{JPN}イワークを つかまえよう かな.$"

Route13_Text_HikerKennyBeaten:
	.string "{JPN}I lost...$"
Route13_Text_HikerKennyAfterBattle:
	.string "{JPN}ちけいは ぜんぜん かわらない\n"
	.string "{JPN}ように みえるが\p"
	.string "{JPN}じっさいは すこしずつ\n"
	.string "{JPN}かわっているんだよ.$"

Route13_Text_TrainerTips:
	.string "{JPN}トレーナーの こころえ\p"
	.string "{JPN}みろ! あそこだ かんばんの\n"
	.string "{JPN}ひだりがわを.$"

Route13_Text_Sign:
	.string "{JPN}13ばんどうろ\p"
	.string "{JPN}きたへ サイレンスブリッジ$"

Route13_Text_DirectionsSign:
	.string "{JPN}きたへ シオンタウン\p"
	.string "{JPN}にしへ セキチクシティ$"

