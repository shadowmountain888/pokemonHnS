ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisherNew, MSGBOX_NPC
	giveitem ITEM_TM_SLUDGE_BOMB
	setflag FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "{JPN}ういーっ！ひっく..まちやがれ！\n"
	.string "{JPN}わしのはなしをきけ！\p"
	.string "{JPN}こうみえてもむかしは\n"
	.string "{JPN}ポケモンをつかまえるのが\l"
	.string "{JPN}うまかったんじゃ！\p"
	.string "{JPN}しんじてくれるかの？$"
ViridianCity_Text_CoffeeGramps_Believed:
	.string "{JPN}そうじゃろそうじゃろ\n"
	.string "{JPN}うんうん$"
ViridianCity_Text_CoffeeGramps_Doubted:
	.string "{JPN}なにをこわっぱが！\p"
	.string "{JPN}わしがもうすこしわかけりゃ\n"
	.string "{JPN}おてほんをみせてやったのにな$"
ViridianCity_Text_GrampsNearGym:
	.string "{JPN}このジムにはリーダーが\n"
	.string "{JPN}おらんかったのだが..\p"
	.string "{JPN}さいきんマサラのわかものが\n"
	.string "{JPN}リーダーになったそうじゃ\p"
	.string "{JPN}..はて？\n"
	.string "{JPN}いまはるすかの？$"
ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "{JPN}ジムリーダーと\n"
	.string "{JPN}たたかうのかね?\p"
	.string "{JPN}がんばるんじゃよ.\nうんが ひつようじゃからな.$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "{JPN}...zzzzz...\p"
	.string "{JPN}ふわあ!\p"
	.string "{JPN}たいようのなかで うとうと\n"
	.string "{JPN}してしまったようじゃ.\p"
	.string "{JPN}なに? だれかににてるじゃと?\pしらんのう.ほれ これを\nもっていくがよい.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "{JPN}...zzzzz...$"
ViridianCity_Text_DreamEaterFisher:
	.string "{JPN}ふあー！\n"
	.string "{JPN}ひなたぼっこしてて\l"
	.string "{JPN}ねむってしまった！\p"
	.string "{JPN}..へんなゆめをみた\n"
	.string "{JPN}スリープがゆめをくっていた！\l"
	.string "{JPN}..およ？ぼくいつのまにか\l"
	.string "{JPN}わざマシンもってるけど？\p"
	.string "{JPN}うーん\n"
	.string "{JPN}きみがわるい！\l"
	.string "{JPN}これきみにあげる！$"
ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "{JPN}わざマシン85のなかみは..\n"
	.string "{JPN}ゆめくいだよ..\l"
	.string "{JPN}..ぐう..$"
ViridianCity_Text_Youngster:
	.string "{JPN}トキワのもりには\n"
	.string "{JPN}みえないどうぐがいっぱい\l"
	.string "{JPN}おちているってはなしだよ！$"
ViridianCity_Text_Sign:
	.string "{JPN}トキワシティ\p"
	.string "{JPN}とわに みどりの らくえん$"

ViridianCity_Text_GymSign:
	.string "{JPN}トキワシティポケモンジム\n"
	.string "{JPN}リーダー..\l"
	.string "{JPN}あとはもじがよめない！$"
ViridianCity_Text_WelcomeSign:
	.string "{JPN}セキエイこうげんいりぐちのまち\n"
	.string "{JPN}トキワシティへようこそ！$"
ViridianCity_Text_TrainerHouseSign:
	.string "{JPN}ここはトレーナーハウス\n"
	.string "{JPN}つわもののつどうばしょ$"