MtMortar_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "{JPN}おお!\p"
	.string "{JPN}わたしが からてキング!\n"
	.string "{JPN}くらやみで ひとり しゅぎょう\l"
	.string "{JPN}しているのじゃ!\p"
	.string "{JPN}おぬし! わたしと しょうぶ\nするのじゃ!\nうおおおおお!$"

MountMortar4_Text_KiyoWin:
	.string "{JPN}うわあああああ!\n"
	.string "{JPN}まけたのじゃ!$"

MountMortar4_Text_KiyoTyrogueReward:
	.string "{JPN}わ... わたしのまけじゃ...\p"
	.string "{JPN}しゅぎょうが たりんかった\n"
	.string "{JPN}のじゃ...\p"
	.string "{JPN}しかし まけは まけじゃ.\n"
	.string "{JPN}みとめるのじゃ.\p"
	.string "{JPN}わたしに かったあかしに\n"
	.string "{JPN}めずらしい かくとうタイプの\l"
	.string "{JPN}ポケモンを やろう.$"

MountMortar4_Text_ReceiveTyrogue:
	.string "{JPN}{PLAYER}は バルキーを\nてに いれた!$"

MountMortar4_Text_KiyoGotTyrogue:
	.string "{JPN}バルキーは かくとうタイプ\n"
	.string "{JPN}じゃ.\p"
	.string "{JPN}もっと つよいポケモンに\n"
	.string "{JPN}しんかするのじゃ.\p"
	.string "{JPN}がんばって そだてるのじゃよ.\n"
	.string "{JPN}わたしも しゅぎょうを\lつづけるのじゃ.\pでは さらばじゃ!$"

MountMortar4_Text_KiyoFullParty:
	.string "{JPN}てもちが いっぱいじゃ!$"
