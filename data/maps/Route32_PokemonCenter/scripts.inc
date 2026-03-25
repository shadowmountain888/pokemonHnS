.set LOCALID_NURSE, 1

Route32_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "{JPN}ここは つりの めいしょ\n"
	.string "{JPN}だからな.\p"
	.string "{JPN}つりを している ひとを\n"
	.string "{JPN}みかけたか?\pきみは どうだい?\pわたしの つりざおを\nひとつ もらわないか?$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "{JPN}へへ  それは よかった.\p"
	.string "{JPN}これで きみも つりしだな!$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "{JPN}つりは さいこうだぞ!\p"
	.string "{JPN}うみでも かわでも みずが\n"
	.string "{JPN}あれば つりざおを ためして\nみるんだな.$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "{JPN}あらら\n"
	.string "{JPN}そりゃざんねんだねえ$"
Route32_Pokecenter_Text_FishingGuruAfter:
	.string "{JPN}よお  ぼうず.\nつりの ちょうしは どうだい?$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "{JPN}うーんポケモンに\n"
	.string "{JPN}なにもたせるかまよっちゃうな\p"
	.string "{JPN}こうげきりょくをつよくする\n"
	.string "{JPN}どうぐにしようかな$"
