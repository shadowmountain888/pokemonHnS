LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_GARBAGEFLAG, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GARBAGEFLAG
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "{JPN}ハーブショップへ いらっしゃい!\n"
	.string "{JPN}こうかてきで やすい くすりの\nおみせ だよ!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "{JPN}フエンタウンで ハーブの くすりを\n"
	.string "{JPN}みに きてくれたのかい?\p"
	.string "{JPN}なかなか かんしんだねえ.\p"
	.string "{JPN}きみが きにいったよ!\nこれを あげよう!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "{JPN}いま あげた もくたんは\n"
	.string "{JPN}ハーブくすり づくりに つかうんだ.\p"
	.string "{JPN}ポケモンに もたせても\n"
	.string "{JPN}すばらしい こうかが あるよ.\p"
	.string "{JPN}ほのおタイプの わざの\n"
	.string "{JPN}いりょくを つよめてくれるんだ.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "{JPN}ハーブの くすりは とても\n"
	.string "{JPN}よく きくんだけどね.\l"
	.string "{JPN}ポケモンに きらわれちゃうんだ.\lものすごく にがいんだろうねえ!$"

