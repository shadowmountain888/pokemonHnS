PokemonLeague_KogasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_2, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "{JPN}コガ: ふわははははは!\p"
	.string "{JPN}もどってきたな \n"
    .string "{JPN}ゆうかんな ちょうせんしゃよ.\p"
	.string "{JPN}わしの にんじゃの わざは\n"
    .string "{JPN}さらに みがかれた.\p"
	.string "{JPN}あたらしい きょうあくな\n"
    .string "{JPN}わなが まっているぞ.\p"
	.string "{JPN}どく ねむり \nそして それいじょう...\nかくごしろ!\pふわははははは!\pきさまの せいちょうを\nみせてみよ!$"

PokemonLeague_KogasRoom_Text_Before:
    .string "{JPN}ふぁははははは!\p"
	.string "{JPN}してんのうの キョウじゃ.\p"
    .string "{JPN}わしは かげに いきる にんじゃ!\p"
	.string "{JPN}ふくざつな たたかいかたで\n"
    .string "{JPN}おまえを まどわし ほろぼそう!\p"
	.string "{JPN}こんらん すいみん どく...\p"
	.string "{JPN}わしの きょうあくな わざの\n"
	.string "{JPN}えじきに なるがよい!\p"
    .string "{JPN}ふぁははははは!\p"
	.string "{JPN}ポケモンは ただの ちからだけでは\n"
    .string "{JPN}ない それを みせてやろう!$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "{JPN}あっ!\n"
	.string "{JPN}きさまは じぶんの かちを\nしょうめいした!$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "{JPN}わしは きさまに\n"
	.string "{JPN}ありったけの ちからを\n"
    .string "{JPN}つくした.\p"
	.string "{JPN}だが わしの どりょくは\n"
    .string "{JPN}しっぱいに おわった.\n"
	.string "{JPN}わざを みがかねば.\pつぎの へやに いき \nきさまの のうりょくを\nためしてみよ!$"
