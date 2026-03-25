SootopolisCity_Mart_MapScripts::
	.byte 0

SootopolisCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SootopolisCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SootopolisCity_Mart_Pokemart:
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_NONE
	release
	end

SootopolisCity_Mart_EventScript_FatMan::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_FatManNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_FatManNoLegendaries
	msgbox SootopolisCity_Mart_Text_TooScaryOutside, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_FatManNoLegendaries::
	msgbox SootopolisCity_Mart_Text_PPUpIsGreat, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_Mart_Text_DidSomethingAwaken, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_Mart_Text_FullRestoreItemOfDreams, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_Text_PPUpIsGreat:
	.string "{JPN}ポイントアップは さいこうだ!\p"
	.string "{JPN}ポケモンの わざの ポイント \n"
	.string "{JPN}つまり PPを あげてくれるんだ!$"

SootopolisCity_Mart_Text_TooScaryOutside:
	.string "{JPN}なに...\n"
	.string "{JPN}なにが おこってるの?\p"
	.string "{JPN}ほんとうは しりたいけど\n"
	.string "{JPN}そとに でるには こわすぎるよ$"

SootopolisCity_Mart_Text_FullRestoreItemOfDreams:
	.string "{JPN}かいふくのくすりを しってるかい?\p"
	.string "{JPN}HPを かんぜんかいふく!\n"
	.string "{JPN}じょうたいいじょうも ぜんぶ なおす!\p"
	.string "{JPN}まさに ゆめの どうぐだよ!$"

SootopolisCity_Mart_Text_DidSomethingAwaken:
	.string "{JPN}このてんき...\n"
	.string "{JPN}なにかが めざめたのかしら?$"

