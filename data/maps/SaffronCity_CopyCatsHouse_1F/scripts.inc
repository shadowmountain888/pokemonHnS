SaffronCity_CopyCatsHouse_1F_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "{JPN}むすめは ひとの まねを\n"
	.string "{JPN}するのが すきでね.\p"
	.string "{JPN}そのせいで みんなから\nものまねむすめって\nよばれてるんだよ.$"

CopycatsHouse1F_Text_PokefanF:
	.string "{JPN}うちの むすめは じこちゅう\n"
	.string "{JPN}なんです...\pともだちも すくないし...$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "{JPN}さいきん おとこのこから\n"
	.string "{JPN}もらった ポケにんぎょうを\n"
	.string "{JPN}なくしちゃって...\p"
	.string "{JPN}3ねんまえに もらったものを\n"
	.string "{JPN}なくしてから ものまねが\nじょうずになったんです...$"
CopycatsHouse1F_Text_Blissey:
	.string "{JPN}ハピナス: はぴなーす!$"
