GoldenrodCity_BillsHouse_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
	.string "{JPN}マサキやあ{PLAYER}！おねがいが\nあるんだこのイーブイをもらって\pぼくがシステムのしごとをしている\nあいだにあずかったんだ\pだれかがせわをしないといけないが\nぼくはそとにでるのがにがてで..\p{PLAYER}いっしょにあそんで\nくれるかな？$"
BillHouse_Text_CountingOnYou:
    .string "{JPN}さすがやな\n"
	.string "{JPN}よっだいとうりょう！\l"
	.string "{JPN}にくいねーッ\p"
	.string "{JPN}ほなたのんだで\n"
	.string "{JPN}だいじにかわいがったりや！$"
BillHouse_Text_ReceivedEevee:
    .string "{JPN}{PLAYER}は\n"
	.string "{JPN}イーブイをもらった！$"
BillHouse_Text_EeveeMayEvolve:
	.string "{JPN}マサキウツギはかせによると\nイーブイはあたらしいしんかを\nするかもしれないそうだよ$"
BillHouse_Text_PartyFull:
    .string "{JPN}ってあかんがな\n"
	.string "{JPN}それいじょうポケモンもてへんやん$"
BillHouse_Text_NoEevee:
    .string "{JPN}そーかいな..$"
BillHouse_Text_PopWontWork:
	.string "{JPN}マサキおやじはしごとをしない\nいちにちじゅうあそんでばかりで\pほんとうにあたまがいたいよ..$"
BillHouse_Text_MomBeforeEcruteak:
    .string "{JPN}あらあなたポケモンあつめてるの\n"
	.string "{JPN}わたしのむすこも\l"
	.string "{JPN}ポケモンにくわしいのよ\p"
	.string "{JPN}マサキっていうんだけど\n"
	.string "{JPN}いまエンジュのポケモンセンターに\l"
	.string "{JPN}よばれていったわ$"
BillHouse_Text_MomAfterEcruteak:
	.string "{JPN}しゅじんはむかしポケモンマニア\nとよばれていたのよ\pマサキはおとうさんににたのね$"
BillHouse_Text_SisterUsefulNumber:
    .string "{JPN}あなたポケモントレーナー？\p"
	.string "{JPN}だったらーあたしが\n"
	.string "{JPN}すてきなでんわばんごう\l"
	.string "{JPN}おしえてあげようか？$"
BillHouse_Text_RecordedBillsNumber:
	.string "{JPN}{PLAYER}はマサキのでんわばんごうを\nポケギアにとうろくした！$"
BillHouse_Text_SisterRefusedNumber:
    .string "{JPN}パソコンでポケモンをあずかる\n"
	.string "{JPN}システムをつくったの\l"
	.string "{JPN}あたしのおにいちゃんなの\p"
	.string "{JPN}あなたにマサキにいちゃんの\n"
	.string "{JPN}でんわばんごうをとうろく\l"
	.string "{JPN}してあげようとおもったのにぃ$"
BillHouse_Text_SisterPhoneFull:
	.string "{JPN}これいじょうでんわばんごうは\nとうろくできません$"
BillHouse_Text_SisterStorageSystem:
    .string "{JPN}パソコンでポケモンをあずかる\n"
	.string "{JPN}システムをつくったの\l"
	.string "{JPN}あたしのおにいちゃんなの！$"
