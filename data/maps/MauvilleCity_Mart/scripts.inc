MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
	.string "{JPN}ポケモンの のうりょくを\n"
	.string "{JPN}いちじてきに あげる どうぐが\n"
	.string "{JPN}あるんだよ.\p"
	.string "{JPN}せんとうちゅうに つかう ものは\n"
	.string "{JPN}プラスパワーや ディフェンダーと\n"
	.string "{JPN}かかな...\pほかにも おなじような ものが\nあると おもうよ.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
	.string "{JPN}とくていの わざを つかうか \n"
	.string "{JPN}それとも どうぐを つかうか...\p"
	.string "{JPN}トレーナーの はんだんが\n"
	.string "{JPN}せんとうの けっかを きめるんだと\nおもうよ.$"

