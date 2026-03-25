PokemonLeague_KarensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "{JPN}カリン: また あなたね.\p"
	.string "{JPN}わたしの しんねんを\n"
    .string "{JPN}わすれていないでしょうね:\p"
	.string "{JPN}ほんとうの つよさは\n"
    .string "{JPN}ポケモンとの しんらいから\l"
	.string "{JPN}うまれるの.\p"
    .string "{JPN}まえに あったときから\n"
	.string "{JPN}わたしと ポケモンたちの\l"
    .string "{JPN}きずなは もっと ふかく\l"
	.string "{JPN}なったわ.\p"
    .string "{JPN}けっして きれない きずなで\n"
	.string "{JPN}むすばれた チームと\lたたかう じゅんびは いい?\pあなたの ポケモンとの\nきずなの ちからを\lみせて ちょうだい.$"

PokemonLeague_KarensRoom_Text_Before:
    .string "{JPN}わたしは してんのうの\n"
	.string "{JPN}カリンよ.\p"
    .string "{JPN}あなたが {PLAYER}?\n"
	.string "{JPN}おもしろいじゃない.\p"
    .string "{JPN}わたしは あくタイプの\n"
	.string "{JPN}ポケモンが だいすきなの.\p"
    .string "{JPN}あらくて たくましい\n"
	.string "{JPN}すがたに みりょくを\l"
    .string "{JPN}かんじるのよ.\lそして つよいしね.\nかてると おもう?\nたのしませて ちょうだい.\pいくわよ.$"

PokemonLeague_KarensRoom_Text_Beaten:
    .string "{JPN}なかなか やるじゃない.\n"
	.string "{JPN}そういう トレーナーが\lすきよ.$"

PokemonLeague_KarensRoom_Text_Defeat:
    .string "{JPN}つよい ポケモン.\p"
	.string "{JPN}よわい ポケモン.\p"
    .string "{JPN}それは にんげんの\n"
	.string "{JPN}かってな かんがえよ.\p"
    .string "{JPN}ほんとうに うでの いい\n"
	.string "{JPN}トレーナーなら すきな\l"
    .string "{JPN}ポケモンで かつべきよ.\p"
	.string "{JPN}あなたの やりかたが\n"
    .string "{JPN}すきよ. だいじなことを\lりかいしているのね.\pいきなさい--\nチャンピオンが まっているわ.$"

