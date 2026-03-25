MagmaHideout_3F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_3F_1R_OnTransition
	.byte 0

MagmaHideout_3F_1R_OnTransition:
	goto_if_set FLAG_UNLOCK_DOGS, MagmaHideout_3F_1R_SwitchToModern
	end

MagmaHideout_3F_1R_SwitchToModern::
	setmaplayoutindex LAYOUT_MAGMA_HIDEOUT_3F_1R_MODERN
	goto_if_set FLAG_DEFEATED_ENTEI, MagmaHideout_End
	goto MagmaHideout_Entei_CryStrong
	end

MagmaHideout_Entei_CryStrong::
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	release
	end

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "{JPN}なんで おれが こんな\n"
	.string "{JPN}ばんをしなきゃ いけないんだ?\p"
	.string "{JPN}ひだりみみが あつくて\nたまらないよ!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "{JPN}I'm getting heat exhaustion...$"
MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "{JPN}このマグマだらけの かざんで\n"
	.string "{JPN}フードを かぶってるのって\nへんだと おもわない?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "{JPN}おれたちは リーダーの\n"
	.string "{JPN}すばらしい ゆめを かなえるために\n"
	.string "{JPN}なかまに なったんだ!\p"
	.string "{JPN}おまえが アクアだんの\n"
	.string "{JPN}やつだろうが ただの ガキだろうが\n"
	.string "{JPN}かんけいない!\pおれたちの じゃまを して\nただで すむと おもうなよ!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "{JPN}くそっ!\n"
	.string "{JPN}おまえ ぜんぜん しんようできない!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "{JPN}いいか よく きけ\n"
	.string "{JPN}マグマだんが ただしいんだ!\p"
	.string "{JPN}アクアだんの いうことなんか\n"
	.string "{JPN}きくな! あいつらの うそに\nだまされるな!$"

