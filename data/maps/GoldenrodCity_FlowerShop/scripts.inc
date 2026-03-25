.set LOCALID_MINT_CLERK, 3

GoldenrodCity_FlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_FlowerShop_OnTransition
	.byte 0

GoldenrodCity_FlowerShop_OnTransition::
	call_if_unset FLAG_MINTS_ENABLED, GoldenrodCity_FlowerShop_HideMintClerk
	call_if_set FLAG_MINTS_ENABLED, GoldenrodCity_FlowerShop_ShowMintClerk
	end

GoldenrodCity_FlowerShop_HideMintClerk::
	goto_if_set FLAG_SYS_GAME_CLEAR, GoldenrodCity_FlowerShop_ShowMintClerkPostgame
	setflag FLAG_MINTS_CLERK
	removeobject LOCALID_MINT_CLERK
	return

GoldenrodCity_FlowerShop_ShowMintClerkPostgame::
	clearflag FLAG_MINTS_CLERK
	addobject LOCALID_MINT_CLERK
	end

GoldenrodCity_FlowerShop_ShowMintClerk::
	clearflag FLAG_MINTS_CLERK
	addobject LOCALID_MINT_CLERK
	return

GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "{JPN}プルプルきのことのことを\n"
	.string "{JPN}おねえちゃんにはなしたら\n"
	.string "{JPN}きけんだっていわれちゃった\p"
	.string "{JPN}アカネちゃんにかてば\n"
	.string "{JPN}すいとうをかしてくれるかな..$"
GoldenrodCity_FlowerShop_Text_Owner1:
	.string "{JPN}あのね36ばんどうろに\n"
	.string "{JPN}ふしぎなきがはえてるらしいの\p"
	.string "{JPN}なんでもみずをかけたら\n"
	.string "{JPN}おどりだすらしいって..\p"
	.string "{JPN}あっ！ダメダメ！\p"
	.string "{JPN}そりゃうちははなやさんですから\n"
	.string "{JPN}じょうろぐらいありますけど\l"
	.string "{JPN}あぶなくてかしてあげられないわよぉ\p"
	.string "{JPN}そうねえ..\n"
	.string "{JPN}コガネのジムリーダーにかてたら\l"
	.string "{JPN}かしてあげてもいいけど..$"
GoldenrodCity_FlowerShop_Text_Owner2:
	.string "{JPN}あのね36ばんどうろに\n"
	.string "{JPN}ふしぎなきがはえてるらしいの\p"
	.string "{JPN}なんでもみずをかけたら\n"
	.string "{JPN}おどりだすらしいって..\p"
	.string "{JPN}あらそれは\n"
	.string "{JPN}コガネのジムバッジ！\p"
	.string "{JPN}あなたあのアカネちゃんを\n"
	.string "{JPN}たおしちゃったの！？\p"
	.string "{JPN}だったらしんぱいなさそうね\n"
	.string "{JPN}このゼニガメじょうろをかして..\l"
	.string "{JPN}ううんあげちゃうわ！$"
GoldenrodCity_FlowerShop_Text_Owner3:
	.string "{JPN}ふしぎなきがはえてるのは\n"
	.string "{JPN}36ばんどうろよ\p"
	.string "{JPN}くれぐれもきをつけてね！$"
GoldenrodCity_FlowerShop_Text_Owner4:
    .string "{JPN}ラララララララ\n"
	.string "{JPN}たーっぷりおみずをあげるわよ$"
GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
	.string "{JPN}わあ！アカネちゃんにかったの？\nすごいね！$"
GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
	.string "{JPN}やっぱりポケモンだったのね！$"