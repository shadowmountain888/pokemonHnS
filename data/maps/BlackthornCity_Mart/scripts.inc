BlackthornCity_Mart_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "{JPN}フレンドリィショップでかえないけど\n"
	.string "{JPN}げんきのかたまりをあたえると\l"
	.string "{JPN}ひんしのポケモンもふっかつだ！\p"
	.string "{JPN}ただしパワーポイントは\n"
	.string "{JPN}かいふくしないからようちゅうい！$"
BlackthornMart_Text_BlackBelt:
	.string "{JPN}ゴールドスプレーは\n"
	.string "{JPN}よわいポケモンをよせつけない\p"
	.string "{JPN}かずあるスプレーのなかで\n"
	.string "{JPN}いちばんながもちするんだ！$"