MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_PRYCE_2, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}よう ちょうしはどうだい \n"
	.string "{JPN}チャンピオンめざしの{PLAYER}!\p"
	.string "{JPN}ここのジムリーダーは\n"
	.string "{JPN}エスパータイプのポケモンを\l"
	.string "{JPN}つかってくるぞ.\p"
	.string "{JPN}かくとうタイプやどくタイプの\n"
	.string "{JPN}ポケモンでいどんだら\l"
	.string "{JPN}ひどいダメージをうけるぞ!\p"
	.string "{JPN}それに すばらしい\n"
	.string "{JPN}れんけいこうげきで\l"
	.string "{JPN}せめてくるからな.\p"
	.string "{JPN}かちたいなら きみのポケモンとの\nきずながどれだけつよいか\lみせつけてやれ!がんばれ!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}うわあ きみはすごいな!\n"
	.string "{JPN}すばらしいトレーナーだ!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "{JPN}バトルはこころのつよさで\n"
	.string "{JPN}きまる!よわいこころでは\lかてない!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "{JPN}まけた!\n"
	.string "{JPN}またこころをきたえなおすぞ!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "{JPN}まよいのあるものはまける.\n"
	.string "{JPN}それがきみへのけいこくだ.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "{JPN}きみのさいのうを\nみせてもらおう!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "{JPN}きみはすばらしいさいのうを\nもっているな!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "{JPN}せかいに てんさいが いるとすれば\n"
	.string "{JPN}わたしたちの ジムリーダーですよ!\p"
	.string "{JPN}しかし あなたは かれらよりも\n"
	.string "{JPN}さいのうが あるかもしれません...$"
MossdeepCity_Gym_Text_BlakeIntro:
	.string "{JPN}ふふふふ... わたしが ねんりきで\n"
	.string "{JPN}モンスターボールを うかせます!\p"
	.string "{JPN}うるるるるるーーー!\n"
	.string "{JPN}... ... ... ... ... ... ...\p"
	.string "{JPN}ときどき しっぱいします...$"
MossdeepCity_Gym_Text_BlakeDefeat:
	.string "{JPN}ぼくのポケモンバトルのうでも\n"
	.string "{JPN}ちょうしがわるいや!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "{JPN}モンスターボールは おもすぎて\n"
	.string "{JPN}ねんりきで もてませんでした...\p"
	.string "{JPN}でも このほこりは...\n"
	.string "{JPN}ふーーーーーーー!\p"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}いや ずるしてません!\nふいてません! ほんとうです!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "{JPN}わたしにまけても じぶんを\n"
	.string "{JPN}せめないでよね.\p"
	.string "{JPN}きみがよわいんじゃなくて \n"
	.string "{JPN}わたしがつよすぎるのよ!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "{JPN}きみのほうがつよすぎるわ!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "{JPN}まけてもおちこまないわよ.\n"
	.string "{JPN}もっとしゅぎょうするだけよ.\p"
	.string "{JPN}まえむきにかんがえる それが\n"
	.string "{JPN}わたしのとりえなの!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "{JPN}みえます...\n"
	.string "{JPN}あなたの みらいが みえます...\p"
	.string "{JPN}わたしに かてれば あなたの\n"
	.string "{JPN}みらいを おしえてあげます!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "{JPN}こうさんします!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "{JPN}あなたは わたしたちの ジムリーダーと\n"
	.string "{JPN}はげしい たたかいを するでしょう...\n"
	.string "{JPN}けっかは...\n"
	.string "{JPN}わたしの くちからは いえません!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "{JPN}あなたが あるいてきた みち...\n"
	.string "{JPN}あなたが けいけんした こと...\n"
	.string "{JPN}まなんだ すべてを かけて\n"
	.string "{JPN}かかってらっしゃい!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "{JPN}きみはえいこうのみちを\nあゆんできたのね!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "{JPN}どりょくした ひとには\n"
	.string "{JPN}あかるい みらいが まっています\p"
	.string "{JPN}なまけた ひとには\n"
	.string "{JPN}ぜつぼうしか のこりません\n"
	.string "{JPN}じごうじとく です...$"
MossdeepCity_Gym_Text_SylviaIntro:
	.string "{JPN}いのちをかけても このバトルに\n"
	.string "{JPN}かってみせる!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "{JPN}あなたが することは...\n"
	.string "{JPN}わたしを おびえさせます...$"
MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "{JPN}よくも わたしに かったわね...\n"
	.string "{JPN}なにか ひどいことが おこっても\n"
	.string "{JPN}わたしの せいじゃないからね...$"
MossdeepCity_Gym_Text_NateIntro:
	.string "{JPN}ほほほ.\p"
	.string "{JPN}エスパータイプのねばりづよさを\n"
	.string "{JPN}おしえてあげましょう.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "{JPN}おお!これは!\n"
	.string "{JPN}きみのバトルスタイルは\lすばらしい!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "{JPN}ぼ... ぼくは まけても\n"
	.string "{JPN}どんなに ひどくても きにしないよ$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "{JPN}かんぜんにひどい おそろしい\n"
	.string "{JPN}じかんをみせてあげる!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "{JPN}い いやああああ!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "{JPN}きみのげんきがうつりそう!\n"
	.string "{JPN}はやくとおくにいって!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "{JPN}わしはぜんせいきかもしれんが \n"
	.string "{JPN}あなどらないほうがよいぞ.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "{JPN}ああ きみはわかさの\n"
	.string "{JPN}ちからにあふれておる!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "{JPN}きみのわかいちからには\n"
	.string "{JPN}かなわなかったようじゃ.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "{JPN}さいごまではいかせないわ!\n"
	.string "{JPN}わたしがいるかぎりは!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "{JPN}どうしてそんなに\n"
	.string "{JPN}ばかみたいにつよいの?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "{JPN}ふん!つよくても エスパータイプ\n"
	.string "{JPN}にはむいてないわね!\p"
	.string "{JPN}きみのたたかいかたは\nなんだかやばんよ!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "{JPN}うおおおお!おれの ちょう\n"
	.string "{JPN}ポケモン こうげきりょくを\lあじわってみろ!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "{JPN}うおお!\n"
	.string "{JPN}まけた!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "{JPN}よし!つぎは とくべつな\n"
	.string "{JPN}さいきょう ポケモンぱわーを\lかいはつするぞ!$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "{JPN}フウ: ひひひ... おどろいた?\n"
	.string "{JPN}ラン: ふふふ... おどろいた?\p"
	.string "{JPN}フウ: ジムリーダーが ふたりいるなんて\n"
	.string "{JPN}ラン: ジムリーダーが ふたりいるなんて\p"
	.string "{JPN}フウ: わたしたち ふたごなの!\n"
	.string "{JPN}ラン: わたしたち ふたごなの!\n"
	.string "{JPN}フウ: はなさなくても わかるの...\n"
	.string "{JPN}ラン: おたがいが なにを...\n"
	.string "{JPN}フウ: かんがえているか...\n"
	.string "{JPN}ラン: こころで つうじあえるの!\n"
	.string "{JPN}フウ: わたしたちの れんけい...\n"
	.string "{JPN}ラン: あなたに やぶれるかしら?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "{JPN}フウ: なんですって?! わたしたちの...\n"
	.string "{JPN}ラン: れんけいが やぶられた!\n"
	.string "{JPN}フウ: しかたないわ あなたの かちよ\n"
	.string "{JPN}ラン: みとめて これを あげるわ$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{JPN}{PLAYER}は フウと ランから\n"
	.string "{JPN}マインドバッジを もらった!$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "{JPN}フウ:マインドバッジは ポケモンの\n"
	.string "{JPN}とくこう と とくぼうを たかめる\l"
	.string "{JPN}こうかが あるんだ\p"
	.string "{JPN}ラン:それに バトルがいでも\n"
	.string "{JPN}ひでんわざ ダイビングが\lつかえるようになるよ\pフウ:これも もっていってくれ$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "{JPN}フウ: その わざマシン04には...\n"
	.string "{JPN}ラン: めいそうが はいってるの!\n"
	.string "{JPN}フウ: とくこうを あげて...\n"
	.string "{JPN}ラン: とくぼうも あげるのよ!\n"
	.string "{JPN}フウ: エスパータイプの ポケモンには...\n"
	.string "{JPN}ラン: ぴったりの わざよ!\n"
	.string "{JPN}... ... ... ... ... ...$"
MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "{JPN}ジムリーダー フウ と ランを\n"
	.string "{JPN}ポケナビに とうろくした!$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "{JPN}フウ:きみと ポケモンの きずなは\n"
	.string "{JPN}ぼくたち ふたごの きずなより\l"
	.string "{JPN}ずっと つよいようだ\p"
	.string "{JPN}ラン:きみは もっと つよくなる!\n"
	.string "{JPN}たたかったから わかるよ$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "{JPN}フウ: ひひひ... おどろいた?\n"
	.string "{JPN}ラン: ジムリーダーが ふたりいるなんて\n"
	.string "{JPN}フウ: あら あなた たたかえるのが\n"
	.string "{JPN}ラン: ひとびきしか いないのね\p"
	.string "{JPN}フウ: それじゃ たたかえないわ!\n"
	.string "{JPN}ラン: わたしたちに ちょうせんするなら\n"
	.string "{JPN}もっと ポケモンを つれてきて$"

MossdeepCity_Gym_Text_GymStatue:
	.string "{JPN}トクサネシティ ポケモンジム$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "{JPN}トクサネシティ ポケモンジム\p"
	.string "{JPN}ラン と フウ こうにん\n"
	.string "{JPN}トレーナー:{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "{JPN}フウ: ポケモン...\n"
	.string "{JPN}ラン: ポケモン...\n"
	.string "{JPN}フウ: パーティーの くみあわせで...\n"
	.string "{JPN}ラン: たたかいかたが かわるのね\n"
	.string "{JPN}フウ: でも わたしは...\n"
	.string "{JPN}ラン: でも わたしは...\p"
	.string "{JPN}フウ: いつでも ランと いっしょよ!\n"
	.string "{JPN}ラン: いつでも フウと いっしょよ!\n"
	.string "{JPN}フウ: わたしたちの れんけい...\n"
	.string "{JPN}ラン: なんどでも みせてあげる!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "{JPN}フウ: あなたと あなたの ポケモン...\n"
	.string "{JPN}ラン: まるで きょうだいみたいね!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "{JPN}フウ:きみに たおされても\n"
	.string "{JPN}ぼくたちは まけない!\p"
	.string "{JPN}ラン:だって ふたりで\n"
	.string "{JPN}いつも ささえあってるから!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "{JPN}フウ: また きたのね...\n"
	.string "{JPN}ラン: また きたのね...\p"
	.string "{JPN}フウ: さいせんを しに\n"
	.string "{JPN}ラン: さいせんを しに\n"
	.string "{JPN}フウ: でも...\n"
	.string "{JPN}ラン: わたしたちとの しあいに...\p"
	.string "{JPN}フウ: ポケモンを ひとびきしか!\n"
	.string "{JPN}ラン: ポケモンを ひとびきしか!\n"
	.string "{JPN}フウ: すくなくとも ふたひきは\n"
	.string "{JPN}ラン: つれてきて もらわないと$"
