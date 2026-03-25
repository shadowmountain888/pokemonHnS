AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1::
	clearflag FLAG_GARBAGEFLAG
	return

AquaHideout_B1F_EventScript_ShowElectrode2::
	clearflag FLAG_GARBAGEFLAG
	return

AquaHideout_B1F_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_SCOTT, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_SEAN, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_SID, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt7::
	trainerbattle_single TRAINER_STEPHEN, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro:
	.string "{JPN}おれたちの\n"
	.string "{JPN}アジトのひみつを しりたけりゃ\pおれに かたなきゃ だめだぜ!$"

AquaHideout_B1F_Text_Grunt2Defeat:
	.string "{JPN}ぜんぜん かてないよ...$"
AquaHideout_B1F_Text_Grunt2PostBattle:
	.string "{JPN}おれたちの アジトの ひみつ?\p"
	.string "{JPN}そうだなあ...\n"
	.string "{JPN}おくのほうに せんすいかんが\l"
	.string "{JPN}あるってことかな!\p"
	.string "{JPN}でも いまごろは...\nけけけけけ...$"
AquaHideout_B1F_Text_Grunt3Intro:
	.string "{JPN}ねんりょう つみこみ よし!\n"
	.string "{JPN}りょこうちゅうの おやつも よし!\p"
	.string "{JPN}あとは じゃまな やつを\n"
	.string "{JPN}たおすだけだ!$"

AquaHideout_B1F_Text_Grunt3Defeat:
	.string "{JPN}ひどい めに あったぜ!$"

AquaHideout_B1F_Text_Grunt3PostBattle:
	.string "{JPN}フン!\n"
	.string "{JPN}これも さくせんの うちだ!\p"
	.string "{JPN}おれの にんむは きみを\nあしどめする ことだったんだ!$"

AquaHideout_B1F_Text_Grunt5Intro:
	.string "{JPN}はあ... アジトの みはりって\n"
	.string "{JPN}つまんねえんだよ.\lあいてしてやるよ.$"

AquaHideout_B1F_Text_Grunt5Defeat:
	.string "{JPN}はあ...\n"
	.string "{JPN}あ まけちまった...$"
AquaHideout_B1F_Text_Grunt5PostBattle:
	.string "{JPN}あまり さわぎすぎると\n"
	.string "{JPN}ほかの アクアだんの メンバーに\nつかまっちゃうぞ.$"

AquaHideout_B1F_Text_Grunt7Intro:
	.string "{JPN}おい!\n"
	.string "{JPN}そこの きみ!\p"
	.string "{JPN}アクアだんの ふくと\n"
	.string "{JPN}マグマだんの ふく\pどっちが かっこいいと おもう?$"

AquaHideout_B1F_Text_Grunt7Defeat:
	.string "{JPN}かっこよく まけたぜ...$"
AquaHideout_B1F_Text_Grunt7PostBattle:
	.string "{JPN}かっこいい ふくを きてれば\n"
	.string "{JPN}まけても きまって みえるだろ?$"
