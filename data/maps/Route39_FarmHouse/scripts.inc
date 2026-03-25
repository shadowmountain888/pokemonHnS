Route39_FarmHouse_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "{JPN}オラのミルタンク\n"
	.string "{JPN}ミルクをださなくなってんだー\p"
	.string "{JPN}オラんちのミルクはゆうめいだ\n"
	.string "{JPN}みんなのみてえいってるのにのー\p"
	.string "{JPN}オレンのみをいっぱいたべさせりゃ\n"
	.string "{JPN}げんきになって\l"
	.string "{JPN}おいしいミルクをたくさん\l"
	.string "{JPN}だしてくれるんだけどもな$"
Route39_Text_FarmerMBuyMilk:
	.string "{JPN}ぼくじょうじまんの\n"
	.string "{JPN}モーモーミルクはいらんかー？\p"
	.string "{JPN}ポケモンにのませりゃ\l"
	.string "{JPN}たいりょくかいふくってもんだ！\p"
	.string "{JPN}いまならいっぽん500¥だー$"
Route39_Text_FarmerMGotMilk:
	.string "{JPN}たっぷりのんでくれー！$"
Route39_Text_FarmerMNoMoney:
	.string "{JPN}あややおかねがたりないねー！$"
Route39_Text_FarmerMNoRoom:
	.string "{JPN}あややにもつがいっぱいだなー！$"
Route39_Text_FarmerMNoSale:
	.string "{JPN}いらんかー？\n"
	.string "{JPN}じゃまたきてくれなー$"
Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "{JPN}もう いっぽん いかが?$"

Route39_Text_GotMilk:
	.string "{JPN}{PLAYER}は モーモーミルクを\nてにいれた!$"

Route39_Text_FarmerMMilking:
	.string "{JPN}んじゃちちしぼりでもはじめっかー$"
Route39_Text_FarmerFInTrouble:
	.string "{JPN}うちのミルクは\n"
	.string "{JPN}カントーにもしゅっかしてるんだ\p"
	.string "{JPN}だからミルタンクが\n"
	.string "{JPN}おいしいミルクだしてくれんと\l"
	.string "{JPN}オラたちもこまるんだー$"
Route39_Text_FarmerFHealedMiltank:
	.string "{JPN}ミルタンクが\n"
	.string "{JPN}おいしいミルクだしはじめたのは\l"
	.string "{JPN}あんたのおかげだー\p"
	.string "{JPN}これあんたにやるよ\n"
	.string "{JPN}うけとってくれー$"
Route39_Text_FarmerFSnatchSpeech:
	.string "{JPN}それは よこどりよ.\p"
	.string "{JPN} とっても トリッキーな わざで\n"
	.string "{JPN}あいての わざを つかう ちょくぜんに\l"
	.string "{JPN}よこどり しちゃうのよ.\p"
	.string "{JPN} もし ふくすうの ポケモンが\n"
	.string "{JPN}よこどりを つかうと いちばん\l"
	.string "{JPN}おそい ポケモンだけが わざを\l"
	.string "{JPN}よこどり できるの.\p"
	.string "{JPN} うまく つかいなさいね.\nタイミングが すべてよ.$"
