FuchsiaCity_House1_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_BillsOlderSister::
	msgbox FuchsiaCity_House1_Text_BillsOlderSister, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_Youngster::
	msgbox FuchsiaCity_House1_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_BillsOlderSister:
	.string "{JPN}うちのおじいさん\n"
	.string "{JPN}ハナダのみさきにある\l"
	.string "{JPN}マサキちゃんのいえに\l"
	.string "{JPN}あそびにいってるの$"
FuchsiaCity_House1_Text_Youngster:
	.string "{JPN}サイクリングロードで\n"
	.string "{JPN}のろのろうごきまわる\l"
	.string "{JPN}へんなポケモンをみたよ！$"
