Route30_House_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "{JPN}きたのみちをたどっていくと\n"
	.string "{JPN}ポケモンじいさんのいえが\l"
	.string "{JPN}みえるよ.\p"
	.string "{JPN}でもそのまえに\n"
	.string "{JPN}きのみについておしえてあげよう!\p"
	.string "{JPN}ポケモンはきのみをたべると\n"
	.string "{JPN}げんきになるんだ.\p"
	.string "{JPN}バトルちゅうにもっているきのみを\n"
	.string "{JPN}たべることもできるよ.\p"
	.string "{JPN}きのみはヒワダタウンのガンテツが\n"
	.string "{JPN}ボールにかえてくれるんだ.\pはい.ひとつあげよう!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "{JPN}きのきをしらべてきのみをさがそう.\n"
	.string "{JPN}すうじかんごにまたはえてくるよ.$"
