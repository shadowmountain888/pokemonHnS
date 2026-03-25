VioletCity_TrainerSchool_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "{JPN}わたしゲームボーイせだいじゃないけど\nポケモンゲームだいすき！\pむかしのゲームはけいけんちかせぐのに\nやせいポケモンとたくさん\lたたかわないといけなかった\pでもあたらしいゲームのがくしゅうそうちは\nポケモンのレベルあがりすぎちゃう\pこのゲームのがくしゅうそうちは\nちょうどいいレベルになるように\lバランスちょうせいしてあるの\lたたかうかいすうでちょっとかわるけど\pでんとうてきな1-4せだいたいけんなら\nがくしゅうそうちをオフにして\lげんだいてきたいけんなら\lがくしゅうそうちをオンにして\pあなたがすきなようにあそんで！$"
VioletCity_TrainerSchool_Text_EarlIntro:
	.string "{JPN}ジョバンニでーす！\n"
	.string "{JPN}ポケモンはすばらしーですね！\p"
	.string "{JPN}ワタシつよくなるため\n"
	.string "{JPN}いろいろおしえまーす\p"
	.string "{JPN}なにしりたい？\n"
	.string "{JPN}どうすればつよくなるか\l"
	.string "{JPN}しりたいですか？$"
VioletCity_TrainerSchool_Text_Teacher:
	.string "{JPN}あるポケモンはよわくはじまって\nつよくなるのにほかより\lたくさんけいけんちがひつようです\pたとえばヨーギラスはよわいですが\nさいしゅうてきにつよい\lバンギラスになります\lそのかわりけいけんちがたくさんひつよう\pそのようなポケモンは\nけんしんなトレーナーだけが\lそだてるべきでしょう$"
VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "{JPN}それではーワタシが\n"
	.string "{JPN}おしえてあげましょー！\p"
	.string "{JPN}しょうぶのときには\n"
	.string "{JPN}ポケモンリストのいちばんうえ\l"
	.string "{JPN}つまりつれあるいているポケモンが\l"
	.string "{JPN}さいしょにとびだしまーす！\p"
	.string "{JPN}リストのじゅんばんかえると\n"
	.string "{JPN}しょうぶがゆうりになるかもねー！\p"
	.string "{JPN}ほかにもききたいですか？$"
VioletCity_TrainerSchool_Text_TeachMore:
	.string "{JPN}ではーポケモンの\n"
	.string "{JPN}じょーずなたたかいかた\l"
	.string "{JPN}しりたいですか？$"
VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "{JPN}それではーワタシが\n"
	.string "{JPN}おしえてさしあげましょー！\p"
	.string "{JPN}しょうぶのときいちどでも\n"
	.string "{JPN}かおをだせばそのポケモンは\l"
	.string "{JPN}けいけんちがもらえまーす！\p"
	.string "{JPN}よわいポケモンを\n"
	.string "{JPN}つれあるきにしておいて\l"
	.string "{JPN}しょうぶがはじまったら\l"
	.string "{JPN}すぐにこうたい！\p"
	.string "{JPN}これでよわいポケモンも\n"
	.string "{JPN}ぐんぐんそだつねー！\p"
	.string "{JPN}ほかにもききたいですか？$"
VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "{JPN}おーあなたゆうとうせい！\n"
	.string "{JPN}おしえることないねー\p"
	.string "{JPN}つかまえたポケモンと\n"
	.string "{JPN}なかよくしてくださいですねー！$"
VioletCity_TrainerSchool_Text_Youngster1:
	.string "{JPN}まえはつうしんこうかんでしか\nしんかしないとおもわれてたポケモンも\pレベルアップでしんかするよ\nゴーリキーとゴローンは\pレベル38でしんか\nユンゲラーとゴーストは\pレベル42でしんかする\pメタルコートなどのアイテムも\nもたせてレベルアップすれば\pとくていのポケモンを\nしんかさせることができる$"
VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "{JPN}そのちいきにでるちゅうもくポケモンは\nフィールドでみることができる！\pでもルートをひるとよる\nりょうほうたしかめてね！$"
VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "{JPN}ジョウトちほうのきのみは\nかいふくとボールづくりにいい\pカントーちほうのきのみは\nポケモンののうりょくさげるのにいい\pカントーのどうじょうは\nポケモンのこじんのうりょくあげてくれる$"
VioletCity_TrainerSchool_Text_Youngster2:
	.string "{JPN}きをつけろよ\nあいてのトレーナーはタイプそうせいの\lいいチームをつかってくるから\lもっときびしいたびになるぞ$"
VioletCity_TrainerSchool_Text_Blackboard:
	.string "{JPN}こくばんにはポケモンの\nひでんマシンについてかいてある\pひでんマシンはいちどかいほうすれば\nおしえなくてもつかえる$"
VioletCity_TrainerSchool_Text_Notebook:
	.string "{JPN}このこのノートだ..\p"
	.string "{JPN}ポケモンは\n"
	.string "{JPN}モンスターボールでつかまえて\l"
	.string "{JPN}どうじに6ひきもちあるける\p"
	.string "{JPN}つづきもよむ？$"
VioletCity_TrainerSchool_Text_Notebook1:
	.string "{JPN}モンスターボールをなげるときは\n"
	.string "{JPN}ポケモンのわざで\l"
	.string "{JPN}どくとかやけどとかにすると\l"
	.string "{JPN}つかまえやすい！\p"
	.string "{JPN}つづきもよむ？$"
VioletCity_TrainerSchool_Text_Notebook2:
	.string "{JPN}ほかにもポケモンのわざで\n"
	.string "{JPN}こんらんするときがある\p"
	.string "{JPN}こんらんすると\n"
	.string "{JPN}たまにまちがえて\l"
	.string "{JPN}じぶんをこうげきしてしまう\p"
	.string "{JPN}いちどでもせんとうからはなれると\n"
	.string "{JPN}もとにもどる..\p"
	.string "{JPN}つづきもよむ？$"
VioletCity_TrainerSchool_Text_Notebook3:
	.string "{JPN}そうしてつかまえたポケモンを\n"
	.string "{JPN}そだててたたかわせるひとを\l"
	.string "{JPN}ポケモントレーナーという\p"
	.string "{JPN}トレーナーのもくひょうは\n"
	.string "{JPN}かくちのポケモンジムにいる\l"
	.string "{JPN}つよいトレーナーにかつこと！\p"
	.string "{JPN}つづきは..\n"
	.string "{JPN}まっしろだ！$"
VioletCity_TrainerSchool_Text_StickerMachine:
	.string "{JPN}このすごいマシンは\nデータをシールにプリントする！$"