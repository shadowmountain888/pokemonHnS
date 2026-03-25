MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "{JPN}げんきのかけらは すばらしいよ!\p"
	.string "{JPN}ひんしの ポケモンに つかうと\n"
	.string "{JPN}ポケモンが げんきになるんだ.\p"
	.string "{JPN}でも きをつけて.げんきのかけらは\n"
	.string "{JPN}わざの PPは かいふくしないよ.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "{JPN}マックスむしよけは よわい ポケモンを\n"
	.string "{JPN}ぜんぶ よせつけないよ.\p"
	.string "{JPN}すべての むしよけスプレーの なかで\nいちばん ながもち するんだ.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "{JPN}ネットボールと ダイブボールは\n"
	.string "{JPN}トクサネでしか つくられない\n"
	.string "{JPN}めずらしい ポケボールなんだ.\p"
	.string "{JPN}ネットボールは むしタイプと\n"
	.string "{JPN}みずタイプの ポケモンに こうかてき.\p"
	.string "{JPN}ダイブボールは うみの そこにいる\nポケモンに いちばん よくきくよ.$"

