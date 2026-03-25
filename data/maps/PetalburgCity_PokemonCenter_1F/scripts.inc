.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "{JPN}あのパソコンベースの\n"
	.string "{JPN}ポケモンボックスシステム...\p"
	.string "{JPN}つくったひとって\n"
	.string "{JPN}かがくしゃのてんさいに\nちがいないよ!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "{JPN}わたしの ポケモンが\n"
	.string "{JPN}オレンのみを たべたら\lHPが かいふくしたの!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "{JPN}ポケモンには いろんな\n"
	.string "{JPN}タイプが あるのよ\p"
	.string "{JPN}どのタイプにも つよいところと\n"
	.string "{JPN}よわいところが あるの\p"
	.string "{JPN}ポケモンの タイプによって\nバトルが かんたんだったり\lむずかしかったり するのよ$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "{JPN}たとえば あなたの キモリは\n"
	.string "{JPN}くさタイプね\p"
	.string "{JPN}みずタイプや じめんタイプに\n"
	.string "{JPN}つよいのよ\p"
	.string "{JPN}でも ほのおタイプの\n"
	.string "{JPN}ポケモンには よわいの$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "{JPN}たとえば あなたの アチャモは\n"
	.string "{JPN}ほのおタイプね\p"
	.string "{JPN}くさタイプや むしタイプに\n"
	.string "{JPN}つよいのよ\p"
	.string "{JPN}でも みずタイプの\n"
	.string "{JPN}ポケモンには よわいの$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "{JPN}たとえば あなたの ミズゴロウは\n"
	.string "{JPN}みずタイプね\p"
	.string "{JPN}ほのおタイプに つよいのよ\p"
	.string "{JPN}でも くさタイプや でんきタイプの\n"
	.string "{JPN}ポケモンには よわいの$"

