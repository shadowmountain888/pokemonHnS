LavenderTown_RadioStation_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "{JPN}いらっしゃいませ!\n"
	.string "{JPN}このフロアは じゆうに\lみてまわってくださいね$"

LavenderTown_RadioStation_Text_Officer:
	.string "{JPN}すみませんが いちかいしか\n"
	.string "{JPN}けんがく できません\p"
	.string "{JPN}ジョウトの ラジオとうが\n"
	.string "{JPN}あくのそしきに のっとられて\l"
	.string "{JPN}いらい けいびを きびしく\l"
	.string "{JPN}しているのです$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "{JPN}このラジオとうでは たくさんの\n"
	.string "{JPN}ひとが いっしょうけんめい\l"
	.string "{JPN}はたらいています\p"
	.string "{JPN}きっと みんな よいばんぐみを\nつくろうと がんばっているの\lでしょうね$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "{JPN}ああ だめだ だめだ!\p"
	.string "{JPN}はつでんしょが とまってしまって\n"
	.string "{JPN}ばんぐみが ほうそう できない!\p"
	.string "{JPN}この ほうそうきょくを たちあげる\n"
	.string "{JPN}ために どれだけ くろうしたか\l"
	.string "{JPN}しらないのに\p"
	.string "{JPN}わたしは もう おしまいだ!$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "{JPN}ああ! きみが はつでんしょの\n"
	.string "{JPN}もんだいを かいけつした\l"
	.string "{JPN}{PLAYER}くんか?\p"
	.string "{JPN}きみの おかげで わたしは\n"
	.string "{JPN}しごとを うしなわずに すんだ\p"
	.string "{JPN}ほんとうに きみは\n"
	.string "{JPN}いのちのおんじんだよ!\pおれいに これを うけとって\nくれ$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{JPN}{PLAYER}は\n"
	.string "{JPN}ラジオバージョンアップを\lてにいれた!$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "{JPN}それが あれば カントうちほうの\n"
	.string "{JPN}ラジオばんぐみが きけるように\l"
	.string "{JPN}なるよ\pがはははは!$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "{JPN}やあ!\p"
	.string "{JPN}ぼくは スーパー おんがく\nディレクターだよ!\p$"
	.string "{JPN}え? きみの ラジオでは\n"
	.string "{JPN}ぼくの おんがくが きけない?\p"
	.string "{JPN}かくちょうカードを てにいれたら\n"
	.string "{JPN}きけるように なるよ!\l"
	.string "{JPN}ぜひ てにいれてね!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "{JPN}やあ!\p"
	.string "{JPN}ぼくは スーパー おんがく\n"
	.string "{JPN}ディレクターだよ!\p"
	.string "{JPN}でんぱに のせて おくりだす\n"
	.string "{JPN}うつくしい メロディーの せきにんしゃ\l"
	.string "{JPN}なんだ\pカタイことは いわずに\nラジオから おんがくを\lキャッチしてね!$"

LavenderTown_RadioStation_Text_Directory:
	.string "{JPN}1F うけつけ 2F えいぎょう\p"
	.string "{JPN}3F じんじ 4F せいさく\p"
	.string "{JPN}5F しゃちょうしつ$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "{JPN}ポケモンを げんきに!\n"
	.string "{JPN}ポケモンのふえの やさしい\l"
	.string "{JPN}メロディー 20チャンネル$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "{JPN}わあ! ポケモンの CDや\n"
	.string "{JPN}ビデオが ぎっしり!\p"
	.string "{JPN}ここが しりょうしつ\n"
	.string "{JPN}なんですね$"

