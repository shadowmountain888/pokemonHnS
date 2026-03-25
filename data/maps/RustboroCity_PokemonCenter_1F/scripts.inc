.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo::
	msgbox RustboroCity_PokemonCenter_1F_ProbopassEvo_Text, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo_Text:
	.string "{JPN}ノーズパスは しんかすると\n"
	.string "{JPN}いわと はがねタイプに\l"
	.string "{JPN}タイプが かわるんだよ.\p"
	.string "{JPN}でも しんかするには つよい\n"
	.string "{JPN}じりょくの あるばしょで\l"
	.string "{JPN}ばくろしないと だめなんだ.\p"
	.string "{JPN}ホウエンちほうでは そんな\n"
	.string "{JPN}ばしょを みつけるのは\l"
	.string "{JPN}むずかしいから かがくしゃが\l"
	.string "{JPN}かみなりのいしを もたせると\l"
	.string "{JPN}じぶんの じりょくが 2ばいに\l"
	.string "{JPN}なって しんかしやすくなる\l"
	.string "{JPN}ことを はっけんしたんだって!\pかみなりのいしって いったい\nなにで できてるんだろうね.$"

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "{JPN}わたしの ポケモンは むじゃきな\n"
	.string "{JPN}せいかくで ともだちのは\l"
	.string "{JPN}ようきな せいかくなの.\p"
	.string "{JPN}ポケモンにも せいかくがあるなんて\nほんとうに おもしろいわね!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "{JPN}にんげんと おなじで ポケモンにも\n"
	.string "{JPN}おすと めすが いるのよ.\p"
	.string "{JPN}でも どこが ちがうのか だれも\n"
	.string "{JPN}わからないみたいね.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "{JPN}となりの おじさんが ひでんマシンを\n"
	.string "{JPN}くれたんだ!\p"
	.string "{JPN}それで ポケモンに ほそい きを\nきる いあいぎりを おしえたよ.$"

