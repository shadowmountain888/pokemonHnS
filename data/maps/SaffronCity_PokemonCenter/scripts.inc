.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "{JPN}ジョウトちほうの\n"
	.string "{JPN}ポケモンセンターって\l"
	.string "{JPN}どんなかんじなの?\p"
	.string "{JPN}ああ そうなのね.\n"
	.string "{JPN}カントーちほうのと\l"
	.string "{JPN}あまりかわらないのね.\pそれなら あんしんして\nジョウトちほうに\lいけるわ!$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "{JPN}たまたま いわやまトンネルを\n"
	.string "{JPN}とおって きたんだ.\p"
	.string "{JPN}はつでんしょで なにか\n"
	.string "{JPN}さわぎが あったみたいだな.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "{JPN}ハナダに へんな どうくつが\n"
	.string "{JPN}あるんだ.\p"
	.string "{JPN}プロの やまおとことして\nたんけんすべきだが \lあそこは おれでも こわいよ.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "{JPN}シルフカンパニーの ほんしゃと\n"
	.string "{JPN}リニアの えき.\l"
	.string "{JPN}ヤマブキの みどころだね!$"
