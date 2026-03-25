PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "{JPN}シバ: おかえりなさい\n"
	.string "{JPN}わかいせんし よ\p"
    .string "{JPN}きびしいくんれんをつんで\n"
	.string "{JPN}わたしたちは つよくなった\p"
    .string "{JPN}がんせきのような わたしの\n"
	.string "{JPN}いしは さらに かたくなった\p"
    .string "{JPN}さらに たいへんな ちょうせんを\n"
	.string "{JPN}うけるじゅんびは できているか\p"
    .string "{JPN}きみの くんれんのせいかを\n"
	.string "{JPN}みせてもらおう\p"
    .string "{JPN}ほーはー!$"

PokemonLeague_BrunosRoom_Text_Before:
    .string "{JPN}わたしは してんのうの\n"
	.string "{JPN}シバだ\p"
    .string "{JPN}わたしたちの かのうせいを\n"
	.string "{JPN}しんじているので\l"
    .string "{JPN}いつも きょくげんまで\n"
	.string "{JPN}くんれんしている\p"
    .string "{JPN}そうやって つよくなったのだ\p"
	.string "{JPN}わたしたちの ちからに\n"
    .string "{JPN}たえられるか\p"
	.string "{JPN}ほう? きみには おそれがない\nけつだんしているな\lせんとうに ぴったりだ!\nじゅんびは いいか {PLAYER}?\nわたしたちの あっとうてきな\nちからに ひざまずくのだ!\pほーはー!$"

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "{JPN}なぜだ? どうして\nまけたのだ?$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "{JPN}まけてしまった いじょう\n"
	.string "{JPN}なにもいうけんりはない...\p"
	.string "{JPN}つぎのちょうせんしゃの\nところへいくがよい!$"
