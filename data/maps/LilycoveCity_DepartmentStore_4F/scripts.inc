LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "{JPN}うーん...\p"
	.string "{JPN}こうげきわざ...\n"
	.string "{JPN}それとも ぼうぎょわざ...\p"
	.string "{JPN}どの わざマシンの わざを\n"
	.string "{JPN}ポケモンに おぼえさせるかは\nかんたんに きめられないなあ...$"
LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "{JPN}わざマシンには いろんな\n"
	.string "{JPN}しゅるいが あるのね\p"
	.string "{JPN}カタログで よんだけど\n"
	.string "{JPN}50しゅるいも あるんだって$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "{JPN}いろんな わざマシンを\n"
	.string "{JPN}ぜんぶ ほしいけど\pポケモンは 4つの わざしか\nおぼえられないのよね$"

