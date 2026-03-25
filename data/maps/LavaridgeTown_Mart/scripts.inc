LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "{JPN}プラスパワーを つかうと\n"
	.string "{JPN}せんとうちゅう ポケモンの\l"
	.string "{JPN}すばやさが あがるよ.\p"
	.string "{JPN}そうすれば せんせいこうげきが\nできて ゆうりになるね!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "{JPN}えんとつやまの やまちょうには\n"
	.string "{JPN}そこでしか かえない\l"
	.string "{JPN}めいぶつが あるんだよ.\pポケモンに あげれば\nだいよろこび するよ.$"

