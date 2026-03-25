.set LOCALID_NURSE, 1

AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "{JPN}きみのポケモンは\nひでんわざをおぼえているか？\pひでんわざはポケモンが\nきぜつしてもつかえるのじゃ$"
AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "{JPN}マサキがつくった\nポケモンあずかりシステムじゃ\pマサキのパソコンは\nひとつのボックスに30ひきまで\nポケモンをあずけられるぞ$"
AzaleaPokecenter_Text_FishingGuru:
	.string "{JPN}マサキがつくった\n"
	.string "{JPN}ポケモンあずかりシステムは\p"
	.string "{JPN}ひとつのボックスにポケモンを\n"
	.string "{JPN}30ひきまであずけられるぞ！$"
AzaleaPokecenter_Text_PokefanF:
	.string "{JPN}きのみってしってる？\pなかみをくりぬいて\nとくべつなしかけをつけるの\pそうすればポケモンを\nつかまえられるのよ\pモンスターボールができるまえは\nみんなきのみをつかってたの$"