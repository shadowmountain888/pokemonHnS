AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "{JPN}きみはスーパーボールを\nかうことができるのか？\pオレはモンスターボールしか\nかえないんだ\pジムバッジをもらうと\nもっといろんなどうぐが\lかえるようになるらしいな！\pガンテツさんにとくべつな\nボールをつくってほしいよ$"
AzaleaMart_Text_BugCatcher:
	.string "{JPN}スーパーボールをつかえば\n"
	.string "{JPN}モンスターボールよりも\l"
	.string "{JPN}ポケモンをつかまえやすくなるよ\p"
	.string "{JPN}でもばあいによっては\n"
	.string "{JPN}ガンテツさんのボールが1ばんだね$"
