CherrygroveCity_Mart_MapScripts::
	.byte 0

Cherrygrove_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Clerk2
	pokemart Cherrygrove_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_Youngster::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Bugcatcher2
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Cherrygrove_Pokemart_EventScript_Bugcatcher2::
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Clerk2::
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 3
Cherrygrove_Pokemart_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_NONE
	release
	end

Cherrygrove_Pokemart_Text_CooltrainerM:
	.string "{JPN}モンスターボールうりきれだって！\n"
	.string "{JPN}つぎにかえるのはいつかなあ$"
Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
	.string "{JPN}モンスターボールがかえる！\n"
	.string "{JPN}これでポケモンつかまえまくりだね$"
Cherrygrove_Pokemart_Text_Youngster:
	.string "{JPN}くさむらあるいてたら\n"
	.string "{JPN}むしポケモンにどくくらった！\p"
	.string "{JPN}しかもそのままあるいてたら\n"
	.string "{JPN}どんどんたいりょくへってった！\p"
	.string "{JPN}どくけしわすれないようにね$"
