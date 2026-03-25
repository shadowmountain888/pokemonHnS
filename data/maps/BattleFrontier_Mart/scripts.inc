.set LOCALID_OLD_WOMAN, 2
.set LOCALID_SECOND_CLERK, 5
.set LOCALID_TM_CLERK, 6

BattleFrontier_Mart_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_Mart_OnTransition
	.byte 0

BattleFrontier_Mart_OnTransition::
	call_if_set FLAG_FINITE_TMS, BattleFrontier_Mart_TMClerkCheck
	call_if_unset FLAG_FINITE_TMS, BattleFrontier_Mart_HideTMClerk
	call_if_unset FLAG_DEFEATED_RED, BattleFrontier_Mart_HideSecondClerk
	call_if_set FLAG_DEFEATED_RED, BattleFrontier_Mart_ShowSecondClerk
	end

BattleFrontier_Mart_TMClerkCheck::
	call_if_unset FLAG_DEFEATED_RED, BattleFrontier_Mart_HideTMClerk
	call_if_set FLAG_DEFEATED_RED, BattleFrontier_Mart_ShowTMClerk
	end

BattleFrontier_Mart_HideTMClerk::
	setflag FLAG_FINITE_TMS_CLERK
	removeobject LOCALID_TM_CLERK
	return

BattleFrontier_Mart_ShowTMClerk::
	clearflag FLAG_FINITE_TMS_CLERK
	addobject LOCALID_TM_CLERK
	return

BattleFrontier_Mart_HideSecondClerk::
	setflag FLAG_FRONTIER_SECOND_CLERK
	removeobject LOCALID_SECOND_CLERK
	return

BattleFrontier_Mart_ShowSecondClerk::
	clearflag FLAG_FRONTIER_SECOND_CLERK
	addobject LOCALID_SECOND_CLERK
	return

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_SAFARI_BALL
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_PP_UP
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTMs:
	.2byte ITEM_TM01
	.2byte ITEM_TM02
	.2byte ITEM_TM03
	.2byte ITEM_TM04
	.2byte ITEM_TM05
	.2byte ITEM_TM06
	.2byte ITEM_TM07
	.2byte ITEM_TM08
	.2byte ITEM_TM09
	.2byte ITEM_TM11
	.2byte ITEM_TM12
	.2byte ITEM_TM18
	.2byte ITEM_TM19
	.2byte ITEM_TM22
	.2byte ITEM_TM23
	.2byte ITEM_TM26
	.2byte ITEM_TM28
	.2byte ITEM_TM30
	.2byte ITEM_TM31
	.2byte ITEM_TM33
	.2byte ITEM_TM34
	.2byte ITEM_TM36
	.2byte ITEM_TM37
	.2byte ITEM_TM39
	.2byte ITEM_TM40
	.2byte ITEM_TM41
	.2byte ITEM_TM42
	.2byte ITEM_TM44
	.2byte ITEM_TM45
	.2byte ITEM_TM46
	.2byte ITEM_TM47
	.2byte ITEM_TM48
	.2byte ITEM_TM49
	.2byte ITEM_TM50
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "{JPN}まごの つきそいで\n"
	.string "{JPN}ここに きたんじゃ.\p"
	.string "{JPN}せっかくだから おみやげでも\n"
	.string "{JPN}かって いこうかのう.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "{JPN}あなた これどうおもう?\n"
	.string "{JPN}すてきなプレゼントに\l"
	.string "{JPN}ならないかしら?\p"
	.string "{JPN}タ...ウ...リ...ン?\nおいしそうなひびきね?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "{JPN}バトルフロンティアの\n"
	.string "{JPN}しせつは たいてい\l"
	.string "{JPN}せんとうちゅうの どうぐしようが\p"
	.string "{JPN}きんしなんだよね.\p"
	.string "{JPN}その ルールのおかげで\nもともと むずかしいのに\lもっと たいへんに なってるよ!$"

