.set LOCALID_NURSE, 1

MahoganyTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANYTOWN
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "{JPN}ヤナギさんはポケモンと50ねん\n"
	.string "{JPN}つきあっているつわものだ！\p"
	.string "{JPN}それに..みてのとおり\n"
	.string "{JPN}こおりついたこのジムで\l"
	.string "{JPN}ひとびとをふるえあがらせる\l"
	.string "{JPN}こうげきをしかけてくるぞ！\p"
	.string "{JPN}こおらされるかくごはいいか？\p"
	.string "{JPN}おっとちがった！\n"
	.string "{JPN}こおりにまけないように\l"
	.string "{JPN}あついとうしをもやしているか！？$"
MahoganyTown_PokemonCenter_Text_Youngster:
    .string "{JPN}ヤナギさんもすごいが\n"
	.string "{JPN}かったおまえもすごかったぞ！\p"
	.string "{JPN}ねんれいをこえた\n"
	.string "{JPN}あついバトルだったぜ！$"
MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "{JPN}チョウジタウンポケモンジム$"