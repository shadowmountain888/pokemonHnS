FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "{JPN}だれも しんじてくれないけど\n"
	.string "{JPN}おおきな ポケモンを そらで\n"
	.string "{JPN}みたんだ.\p"
	.string "{JPN}そいつは くねくねしながら\n"
	.string "{JPN}131ばんどうろの ほうに\n"
	.string "{JPN}とんでいった.\p"
	.string "{JPN}ところで... スンスン...\nきみ... なんか こげくさい\nにおいが するね.\pかざんにでも いってたの?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "{JPN}ポケモンジムに いきたいんだけど\n"
	.string "{JPN}なにかが みちを ふさいでる.\p"
	.string "{JPN}120ばんどうろで\n"
	.string "{JPN}トレーニングした かいが\nないなあ...$"
FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "{JPN}じまんのポケモンを\n"
	.string "{JPN}つれてきたぞ.\lこんどこそナギを\nたおしてやる!$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "{JPN}つちが あめみずを すいこんで\n"
	.string "{JPN}きが そのみずを のんで\n"
	.string "{JPN}そだつんだ...\p"
	.string "{JPN}みずと つちが あるから\nこのキナギタウンが あるんだね.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "{JPN}このまちは きのうえに\n"
	.string "{JPN}たてられた いえからなる.\p"
	.string "{JPN}そういう せいかつの\n"
	.string "{JPN}せいか みんな けんこうで\n"
	.string "{JPN}げんきいっぱいだ.\p"
	.string "{JPN}わしも 30さい\nわかがえった きぶんじゃ!$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "{JPN}きのうえでの せいかつは\n"
	.string "{JPN}いいものよ.\p"
	.string "{JPN}でも ときどき むしポケモンが\n"
	.string "{JPN}まどから はいってくるの.\lほんとうに びっくりするわ.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "{JPN}こうかんすると しんかする\n"
	.string "{JPN}ポケモンが いるって\nきいたことがあるよ!$"

FortreeCity_Text_SomethingUnseeable:
	.string "{JPN}みえない なにかが\nじゃまを している.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "{JPN}みえない なにかが\n"
	.string "{JPN}じゃまを している.\pデボンスコープを\nつかいますか?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{JPN}{PLAYER}は デボンスコープを\n"
	.string "{JPN}つかった.\p"
	.string "{JPN}みえなかった ポケモンの\n"
	.string "{JPN}すがたが あらわれた!\pおどろいた ポケモンは\nにげていった!$"

FortreeCity_Text_CitySign:
	.string "{JPN}ヒワマキシティ\n"
	.string "{JPN}しぜんと たわむれる\l"
	.string "{JPN}こずえのまち$"

FortreeCity_Text_GymSign:
	.string "{JPN}ヒワマキシティ ポケモンジム\n"
	.string "{JPN}ジムリーダー: ナギ\p"
	.string "{JPN}せかいへ はばたく\n"
	.string "{JPN}とりつかい$"
