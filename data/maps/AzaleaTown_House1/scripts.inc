AzaleaTown_House1_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "{JPN}まちからヤドンがいなくなった\p"
	.string "{JPN}うーんもりのかみさまが\n"
	.string "{JPN}おいかりなのか..？\p"
	.string "{JPN}なんにしろよくねえしらせかもな\n"
	.string "{JPN}こんなときはじっとしてるにかぎる$"
CharcoalKiln_Text_Boss2:
	.string "{JPN}ヤドンがもどってきた..$"
CharcoalKiln_Text_Boss3:
	.string "{JPN}ヤドンはもどってきたが..\p"
	.string "{JPN}こんどはわしのだいじな\n"
	.string "{JPN}カモネギがどこかいっちまってな\p"
	.string "{JPN}うちのみならいのやつが\n"
	.string "{JPN}ウバメのもりへさがしにいったが\l"
	.string "{JPN}ちっともかえってきやしねえ..\p"
	.string "{JPN}ったく！\n"
	.string "{JPN}しょうがねえやつだ！$"
CharcoalKiln_Text_Boss4:
	.string "{JPN}ロケットだんをおいはらい\n"
	.string "{JPN}ウバメのもりもおそれずにはいる\l"
	.string "{JPN}おまえさんのどきょうきにいった！\p"
	.string "{JPN}どうだ？わしらといっしょに\n"
	.string "{JPN}しゅぎょうしないか！$"
CharcoalKiln_Text_Apprentice1:
	.string "{JPN}どうしてヤドンいなくなったんだ\n"
	.string "{JPN}どこかあそびにいってるのかな？$"
CharcoalKiln_Text_Apprentice2:
	.string "{JPN}ヤドンがかえってきた！$"
CharcoalKiln_Text_Apprentice3:
	.string "{JPN}そういえばきみに\n"
	.string "{JPN}おれいをしてなかったっけ\p"
	.string "{JPN}これおれがやいたスミなんだ\n"
	.string "{JPN}ポケモンにもたせると\l"
	.string "{JPN}ほのおタイプのわざのいりょくが\l"
	.string "{JPN}あがるんだよ！$"
CharcoalKiln_Text_Apprentice4:
	.string "{JPN}ヤドンももどってきたし\n"
	.string "{JPN}カモネギもみつかった\l"
	.string "{JPN}きみかなりかっこいいね！$"
CharcoalKiln_Text_Farfetchd:
	.string "{JPN}くわー$"