LakeOfRage_House1_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
    .string "{JPN}...おまえは はるか とおくから\n"
	.string "{JPN}きたのじゃな...\p"
    .string "{JPN}ここで わしは めいそうを している.\n"
	.string "{JPN}わしの なかで あたらしい ちからが\n"
    .string "{JPN}めざめたのじゃ.\pその ちからを おまえの ポケモンに\nわけてやろう.これを うけとるのじゃ\nこどもよ.$"

HiddenPowerGuy_Text_Explanation:
    .string "{JPN}みえるかい?それが めざめるパワーだ!\p"
	.string "{JPN}ポケモンの ひめられた ちからを\n"
    .string "{JPN}ひきだして こうげきするのさ.\p"
	.string "{JPN}おぼえておきなさい:その タイプと\n"
    .string "{JPN}いりょくは つかう ポケモンに\nよって きまるのだ.$"

HiddenPowerGuy_Text_Meditating:
    .string "{JPN}わしは めいそうちゅうじゃ...$"
