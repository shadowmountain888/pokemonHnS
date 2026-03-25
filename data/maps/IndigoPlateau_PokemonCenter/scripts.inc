.set LOCALID_NURSE, 1
.set LOCALID_INDIGOPLATEAU_ABRA, 6

IndigoPlateau_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_PokemonCenter_OnFrame 
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Pokecenter_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 0, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 2, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 3, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 4, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 5, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 6, IndigoPlateau_PokemonCenter_Enter
	.2byte 0

IndigoPlateau_PokemonCenter_Enter::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setvar VAR_LEAGUE_STATE, 1
	end

IndigoPlateau_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	end


IndigoPlateau_EventScript_Cooltrainer::
	msgbox IndigoPlateau_Text_CooltrainerM, MSGBOX_NPC
	end

IndigoPlateau_EventScript_BlackBelt::
	msgbox IndigoPlateau_Text_Blackbelt, MSGBOX_NPC
	end

IndigoPlateau_EventScript_ShigyNinja::
	msgbox IndigoPlateau_Text_ShigyNinja, MSGBOX_NPC
	end

IndigoPlateau_Text_ShigyNinja:
	.string "{JPN}ここまで きてくれて\n"
	.string "{JPN}おめでとう!\p"
	.string "{JPN}も ここで たくさんの\n"
	.string "{JPN}トレーナーを みてきたけど\l"
	.string "{JPN}みんな すばらしく ユニークだよ\p"
	.string "{JPN}ここまで きた きみを\n"
	.string "{JPN}ほこりに おもうべきだ!\pさあ がんばって!$"

IndigoPlateau_Text_Blackbelt:
	.string "{JPN}ポケモンリーグは いまのところ\n"
	.string "{JPN}あたらしい ちょうせんしゃを\l"
	.string "{JPN}うけつけて いません\pまた あとで きてください$"

IndigoPlateau_Text_CooltrainerM:
    .string "{JPN}ポケモンリーグでは してんのうに\n"
	.string "{JPN}ためされることに なるよ\p"
    .string "{JPN}ぜんいん たおさなきゃ ダメ\n"
	.string "{JPN}まけたら さいしょから やりなおしだ!$"

IndigoPlateau_EventScript_Silver::
	lock
	faceplayer 
	goto_if_set FLAG_DAILY_BEAT_SILVER, IndigoPlateau_EventScript_SilverBeat
	msgbox IndigoPlateau_Text_RivalEntrance1, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, IndigoPlateau_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, IndigoPlateau_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, IndigoPlateau_Silver_Battle_Chikorita
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BEAT_SILVER
	release
	end

IndigoPlateau_EventScript_SilverBeat::
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Text_RivalEntrance1:
    .string "{JPN}まて\p"
	.string "{JPN}いま ポケモンリーグに\n"
    .string "{JPN}ちょうせんするつもりか?\p"
	.string "{JPN}そうは いかないぜ\p"
    .string "{JPN}おれの ちょう きたえあげた\n"
	.string "{JPN}ポケモンが きみを やっつけてやる\p"
    .string "{JPN}{PLAYER}!\n"
	.string "{JPN}しょうぶだ!$"

IndigoPlateau_Text_RivalWin:
    .string "{JPN}...\p"
	.string "{JPN}わかった... まけた...$"
IndigoPlateau_Text_RivalAfter:
    .string "{JPN}...くそ... やっぱり かてない...\p"
	.string "{JPN}おれは... おれは もっと\n"
	.string "{JPN}ポケモンの ことを かんがえないと...\p"
	.string "{JPN}ふん! まけるなよ!$"

IndigoPlateau_EventScript_Psychic::
	lock
	faceplayer
	msgbox IndigoPlateau_Text_TeleportGuy1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_EventScript_PsychicTeleport
	msgbox IndigoPlateau_Text_TeleportGuyNo, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_EventScript_PsychicTeleport::
	msgbox IndigoPlateau_Text_TeleportGuyYes, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playbgm MUS_HG_NEW_BARK, TRUE
	delay 60
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	applymovement2 LOCALID_INDIGOPLATEAU_ABRA, IndigoPLateau_Movement_Abra
	waitmovement 0
	fadescreen FADE_TO_WHITE
	warpteleport MAP_NEW_BARK_TOWN, 20, 12
	release
	end
	
IndigoPLateau_Movement_Abra:
	jump_in_place_right
	jump_in_place_right
	step_end

IndigoPlateau_EventScript_Abra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	msgbox IndigoPlateau_Text_Abra, MSGBOX_DEFAULT
	waitmoncry
	release
	end

IndigoPlateau_Text_TeleportGuy1:
    .string "{JPN}ああ! してんのうに ちょうせん\n"
	.string "{JPN}するのかい? じゅんびは だいじょうぶ?\p"
    .string "{JPN}もっと しゅぎょうが ひつようなら\n"
	.string "{JPN}わたしの アブラが てだすけするよ\p"
    .string "{JPN}テレポートで いえまで おくってくれる\p"
	.string "{JPN}いま おうちに かえる?$"

IndigoPlateau_Text_TeleportGuyYes:
    .string "{JPN}よし よし. あたまのなかで\n"
	.string "{JPN}じぶんの いえを そうぞうして...$"
IndigoPlateau_Text_TeleportGuyNo:
    .string "{JPN}そうか そうか がんばってくれ!$"

IndigoPlateau_Text_Abra:
    .string "{JPN}ケーシィ: アーブラ...$"
