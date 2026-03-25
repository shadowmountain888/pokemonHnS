Route25_BillsHouse_MapScripts::
	.byte 0


@VAR_BILLS_GRANDPA

Route25_BillsHouse_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_BILLS_GRANDPA, 1, Route25_BillsHouse_EventScript_Gramps_Spinda
	goto_if_eq VAR_BILLS_GRANDPA, 2, Route25_BillsHouse_EventScript_Gramps_Roselia
	goto_if_eq VAR_BILLS_GRANDPA, 3, Route25_BillsHouse_EventScript_Gramps_Lotad
	goto_if_eq VAR_BILLS_GRANDPA, 4, Route25_BillsHouse_EventScript_Gramps_Growlithe
	goto_if_eq VAR_BILLS_GRANDPA, 5, Route25_BillsHouse_EventScript_Gramps_Pichu
	goto_if_eq VAR_BILLS_GRANDPA, 6, Route25_BillsHouse_EventScript_Gramps_ShownAll
	msgbox Route25_BillsHouse_Text_GrandpaIntro, MSGBOX_DEFAULT
	setvar VAR_BILLS_GRANDPA, 1
	goto Route25_BillsHouse_EventScript_Gramps_Spinda

Route25_BillsHouse_EventScript_Gramps_Declined::
	msgbox Route25_BillsHouse_Text_YouDontHaveIt, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_WrongMon::
	msgbox Route25_BillsHouse_Text_WrongPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Spinda::
	msgbox Route25_BillsHouse_Text_Spinda, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	@ Store selected slot in VAR_0x800A
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	@ Get the species of the selected Pokémon
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	@ Check if it's Spinda
	goto_if_ne VAR_RESULT, SPECIES_SPINDA, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_SPINDA
	setvar VAR_TEMP_0, ITEM_EVERSTONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Roselia::
	msgbox Route25_BillsHouse_Text_Roselia, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_ROSELIA, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_ROSELIA
	setvar VAR_TEMP_0, ITEM_LEAF_STONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Lotad::
	msgbox Route25_BillsHouse_Text_Lotad, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_LOTAD, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_LOTAD
	setvar VAR_TEMP_0, ITEM_DEEP_SEA_TOOTH
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Growlithe::
	msgbox Route25_BillsHouse_Text_Growlithe, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_GROWLITHE, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
	setvar VAR_TEMP_0, ITEM_SUN_STONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Pichu::
	msgbox Route25_BillsHouse_Text_Pichu, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_PICHU, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_PICHU
	setvar VAR_TEMP_0, ITEM_DEEP_SEA_SCALE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_ShownAll::
	msgbox Route25_BillsHouse_Text_ShownAll, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Correctmon::
	msgbox Route25_BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0
	call_if_eq VAR_TEMP_0, ITEM_LEAF_STONE, Route25_BillsHouse_EventScript_Gramps_ExtraLeafStones
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route25_BillsHouse_Text_ComeAgain, MSGBOX_DEFAULT
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_ExtraLeafStones::
	additem VAR_TEMP_0
	additem VAR_TEMP_0
	return

Route25_BillsHouse_Test::
	givemon SPECIES_SPINDA, 10
	givemon SPECIES_LOTAD, 10
	givemon SPECIES_ROSELIA, 10
	givemon SPECIES_GROWLITHE, 10
	givemon SPECIES_PICHU, 10
	end

Route25_BillsHouse_Text_GrandpaIntro:
	.string "{JPN}ん?きみ マサキを しってるのかい?\n"
	.string "{JPN}あれは わしの まごじゃよ.\p"
	.string "{JPN}あいつは ジョウトちほうに いる.\n"
	.string "{JPN}パソコンの しごとをしてるから\l"
	.string "{JPN}わしが るすばんしてるんじゃ.$"

Route25_BillsHouse_Text_Spinda:
	.string "{JPN}まごの マサキから きいたんじゃが\n"
	.string "{JPN}ランダムな もようで おおわれた\l"
	.string "{JPN}ポケモンが いるそうじゃな.$"

Route25_BillsHouse_Text_Roselia:
	.string "{JPN}ああ まごが いってたんじゃが\n"
	.string "{JPN}てくびから はなが さいている\l"
	.string "{JPN}みどりいろの ポケモンがいるとか.$"

Route25_BillsHouse_Text_Lotad:
	.string "{JPN}あたまに おおきな はすの はっぱを\n"
	.string "{JPN}のせた みずポケモンを\l"
	.string "{JPN}しってるかの?\n"
	.string "{JPN}セキチクの サファリゾーンに\n"
	.string "{JPN}iるって きいたことがあるんじゃ.\p"
	.string "{JPN}ぜひとも みてみたいもんじゃ.$"

Route25_BillsHouse_Text_Growlithe:
	.string "{JPN}マサキが はなしてくれたんじゃが\n"
	.string "{JPN}トレーナーに とても ちゅうじつな\l"
	.string "{JPN}ポケモンがいるそうじゃ.\p"
	.string "{JPN}よく ほえるらしいのう.$"

Route25_BillsHouse_Text_Pichu:
	.string "{JPN}とても にんきの たかい ポケモンを\n"
	.string "{JPN}しってるかの?\p"
	.string "{JPN}きいろい からだに あかい ほっぺの\n"
	.string "{JPN}ポケモンじゃ.\p"
	.string "{JPN}しんかするまえの すがたを\n"
	.string "{JPN}みてみたいもんじゃのう.$"

Route25_BillsHouse_Text_AskToSeeMon:
	.string "{JPN}もし そのポケモンを もってるなら\n"
	.string "{JPN}みせてもらえるかの?$"

Route25_BillsHouse_Text_ExcitedToSee:
	.string "{JPN}みせてくれるのかい?\n"
	.string "{JPN}なんて やさしいんじゃ!$"

Route25_BillsHouse_Text_YouDontHaveIt:
	.string "{JPN}もっていないの?\n"
	.string "{JPN}ざんねんだなあ...$"
Route25_BillsHouse_Text_ShownPokemon:
	.string "{JPN}ああ これが {STR_VAR_1}かの?\p"
	.string "{JPN}なんて かわいいんじゃ!\n"
	.string "{JPN}ありがたいことじゃ.$"

Route25_BillsHouse_Text_Appreciation:
	.string "{JPN}ありがとう!\p"
	.string "{JPN}これは わしからの\n"
	.string "{JPN}おれいじゃ.$"

Route25_BillsHouse_Text_ComeAgain:
	.string "{JPN}また いつでも きてくれい.$"

Route25_BillsHouse_Text_ShownAll:
	.string "{JPN}たくさんの かわいいポケモンを\n"
	.string "{JPN}みせてくれて ありがとう.\p"
	.string "{JPN}とても たのしかったぞ.\n"
	.string "{JPN}ながいき してよかったのう.$"
	.string ""

Route25_BillsHouse_Text_WrongPokemon:
	.string "{JPN}ん?\n"
	.string "{JPN}それは わしが きいてた\n"
	.string "{JPN}ポケモンとは ちがうようじゃ.$"


