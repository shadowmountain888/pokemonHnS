.set LOCALID_NURSE, 1

VioletCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, VioletCity_PokemonCenter_EventScript_AideNoRoom
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, VioletCity_PokeCenter_Text_ElmsAideFullParty
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "{JPN}{PLAYER}くん\nおひさしぶりです！\pウツギはかせにたのまれて\nきみをさがしていました\pせんせいからまた\nおねがいがあるそうです\pポケモンのタマゴを\nうけとってくれますか？$"
VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "{JPN}{PLAYER}くん\nおひさしぶりです！\pウツギはかせにたのまれて\nきみをさがしていました\pせんせいからまた\nおねがいがあるそうです\pポケモンのタマゴを\nうけとってくれますか？\pあ まって..てもちに\nばしょをつくってください$"
VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "{JPN}ポケモンはタマゴのなかで\nせいちょうしないと\nうまれないことがわかりました\pほかのげんきなポケモンと\nいっしょでないと\nかえらないようです\p{PLAYER}くん きみしか\nたよれるひとはいないんです$"
VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "{JPN}あ それからこれも\nタマゴがかえったときに\nやくだつかもしれません$"
VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "{JPN}あ だめですね ポケモンが\nいっぱいでそれいじょう\nつれあるけません\pタマゴのばしょをつくるまで\nここでまっています$"
VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "{JPN}で でも..ウツギはかせが\nきみにって..$"
VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "{JPN}ポケモンがかいふくしてるあいだ\nほんをよむのがすきなんだ$"
VioletCity_PokeCenter_Text_MobileAdapter:
	.string "{JPN}さっきアサギシティのともだちと\nつうしんでたたかったんだ\pモバイルアダプタをつなげば\nとおくのともだちとも\lつうしんできるよ$"
VioletCity_PokeCenter_Text_GameboyKid:
	.string "{JPN}マサキってひとが\nポケモンのパソコンをつくったんだ$"
VioletCity_PokeCenter_Text_Gentleman:
	.string "{JPN}それは やく 3ねんまえの\n"
	.string "{JPN}ことじゃった.\p"
	.string "{JPN}ロケットだんが ポケモンを\n"
	.string "{JPN}つかって わるいことを\n"
	.string "{JPN}しておったのじゃ.\pじゃが せいぎが かった.\nひとりの わかいしょうねんが\nやつらを やっつけたのじゃ.$"

VioletCity_PokeCenter_Text_Youngster:
	.string "{JPN}ポケモンはかしこい\nみとめないトレーナーにはしたがわない\pジムバッジがないと\nいうことをきいてくれないんだ$"