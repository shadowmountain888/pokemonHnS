EcruteakCity_House2_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "{JPN}ほう！ポケモンといっしょに\n"
	.string "{JPN}たんけんのたびをしているのか\p"
	.string "{JPN}たんけんといえばたからさがし！\n"
	.string "{JPN}そうおもうだろ？$"
Ecruteak_Text_ItemfinderTrueSpirit:
	.string "{JPN}おお！\n"
	.string "{JPN}おとこのロマンがわかってるな\p"
	.string "{JPN}きにいった！\n"
	.string "{JPN}これをもっていきな！$"
Ecruteak_Text_ItemfinderExplanation:
	.string "{JPN}みえなくてもあちこちに\nどうぐがおちているんだ\pダウジングマシンをつかって\nちかくにアイテムがあるかしらべろ\pせいかくなばしょはわからないから\nじぶんでさがすんだぞ\pそうそう！エンジュのやけたとうにも\nアイテムがあるってきいたぜ$"
Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "{JPN}..そうか\n"
	.string "{JPN}まあひとそれぞれだ$"
EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	msgbox Ecruteak_Text_ItemFinderMan, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "{JPN}エンジュシティは とても\n"
	.string "{JPN}ふるい まちなんだ.\l"
	.string "{JPN}なんせだいも まえから れきしを\lこんな ほんで つたえて\lきたんだからね.$"

Ecruteak_Text_HistoryBook:
	.string "{JPN}エンジュのれきし..\p"
	.string "{JPN}よんでみますか？$"
Ecruteak_Text_TwoTowers:
	.string "{JPN}エンジュには2つのとうがあり\n"
	.string "{JPN}それぞれポケモンが\l"
	.string "{JPN}まいおりるばしょでした\p"
	.string "{JPN}ですがとうがもえていらい\n"
	.string "{JPN}ポケモンをみかけなくなった..\l"
	.string "{JPN}そうつたえられています\p"
	.string "{JPN}つづきをよみますか？$"
Ecruteak_Text_ThreeMon:
	.string "{JPN}またエンジュには\n"
	.string "{JPN}まちのまわりをかけめぐる\l"
	.string "{JPN}ポケモンたちがいました\p"
	.string "{JPN}それぞれ\n"
	.string "{JPN}かみなりほのおみずの\l"
	.string "{JPN}うまれかわりといわれてました\p"
	.string "{JPN}ですがじぶんたちの\n"
	.string "{JPN}つよすぎるちからをもてあまし\l"
	.string "{JPN}あちこちのくさむらを\l"
	.string "{JPN}かぜのようにかけぬけていた..\l"
	.string "{JPN}そうつたえられています$"
