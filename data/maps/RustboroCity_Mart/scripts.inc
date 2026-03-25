RustboroCity_Mart_MapScripts::
	.byte 0

RustboroCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartBasic
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartExpanded
	end

RustboroCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

RustboroCity_Mart_EventScript_PokemartBasic::
	pokemart RustboroCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Basic:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_PokemartExpanded::
	pokemart RustboroCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Expanded:
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_PokefanF::
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_Boy::
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_BugCatcher::
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
	end

RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish:
	.string "{JPN}まひなおしと どくけしを\n"
	.string "{JPN}かっているんだ.\p"
	.string "{JPN}トウカのもりで\n"
	.string "{JPN}キノココにであったときの\lためにね.$"

RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead:
	.string "{JPN}ぼくのポケモンが しんかしたんだ.\n"
	.string "{JPN}HPがたくさんになったよ.\p"
	.string "{JPN}ふつうのキズぐすりじゃなくて\n"
	.string "{JPN}いいキズぐすりをかったほうが\lいいかな.$"

RustboroCity_Mart_Text_GettingEscapeRopeJustInCase:
	.string "{JPN}あなぬけのひもを かっておくんだ.\n"
	.string "{JPN}どうくつでまいごになったときの\l"
	.string "{JPN}ために.\p"
	.string "{JPN}つかえばいりぐちまで\nもどれるからね.$"

