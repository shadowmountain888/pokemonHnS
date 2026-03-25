.set LOCALID_RICH_BOY, 1
.set LOCALID_GENTLEMAN, 2
.set LOCALID_SCIENTIST, 3
.set LOCALID_STEVEN, 4
@ Grunt names numbered like their Trainer values (which are for the full Space Center)
.set LOCALID_GRUNT_6, 5
.set LOCALID_GRUNT_5, 6
.set LOCALID_GRUNT_7, 7
.set LOCALID_TABITHA, 8
.set LOCALID_MAXIE, 9

MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition:
	setflag FLAG_ROCKETHIDEOUT2_BATTLE
	call_if_eq VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
	call_if_eq VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians::
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm LOCALID_SCIENTIST, 5, 3
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_RICH_BOY, 3, 2
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_GENTLEMAN, 1, 3
	setobjectmovementtype LOCALID_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts::
	setobjectxyperm LOCALID_GRUNT_6, 11, 2
	setobjectxyperm LOCALID_GRUNT_7, 15, 2
	setobjectxyperm LOCALID_GRUNT_5, 13, 4
	return

MossdeepCity_SpaceCenter_2F_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_PlayerExit:
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WILTON, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
	applymovement LOCALID_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_YOSHI, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
	applymovement LOCALID_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ZACH, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
	applymovement LOCALID_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
	waitmovement 0
	setvar VAR_GARBAGEVAR, 2
	copyobjectxytoperm LOCALID_GRUNT_6
	copyobjectxytoperm LOCALID_GRUNT_7
	copyobjectxytoperm LOCALID_GRUNT_5
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto_if_eq VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	goto_if_lt VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto_if_eq VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	goto_if_lt VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto_if_eq VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	goto_if_lt VAR_GARBAGEVAR, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
	release
	end

@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt7::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt5::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Tabitha::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Maxie::
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_Steven::
	lockall
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_NOT_EFFECTIVE
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth::
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_StevenFight:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth:
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt

MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle::
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_LANCE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 60
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_GARBAGEVAR, 3
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setvar VAR_GARBAGEVAR, 3
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	removeobject LOCALID_GRUNT_6
	removeobject LOCALID_GRUNT_7
	removeobject LOCALID_GRUNT_5
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAXIE
	setobjectxy LOCALID_SCIENTIST, 5, 6
	turnobject LOCALID_SCIENTIST, DIR_SOUTH
	setobjectxy LOCALID_GENTLEMAN, 11, 8
	turnobject LOCALID_GENTLEMAN, DIR_NORTH
	setobjectxy LOCALID_RICH_BOY, 6, 2
	turnobject LOCALID_RICH_BOY, DIR_NORTH
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
	fadescreen FADE_FROM_BLACK
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_GARBAGEFLAG
	removeobject LOCALID_STEVEN
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_GARBAGEFLAG
	removeobject LOCALID_SCIENTIST
	setobjectxyperm LOCALID_SCIENTIST, 5, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
	addobject LOCALID_SCIENTIST
	fadescreen FADE_FROM_BLACK
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer::
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth::
	turnobject LOCALID_STEVEN, DIR_NORTH
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest::
	turnobject LOCALID_STEVEN, DIR_EAST
	return

MossdeepCity_SpaceCenter_2F_EventScript_MaxieTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_ARIANA_1, 0, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
	end

MossdeepCity_SpaceCenter_2F_EventScript_TabithaTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_ARCHER_1, 0, MossdeepCity_SpaceCenter_Text_TabithaDefeat, MossdeepCity_SpaceCenter_Text_TabithaDefeat
	end

MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
	call_if_eq VAR_RESULT, FEMALE, MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall::
	pokenavcall MatchCall_Text_MayRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall::
	pokenavcall MatchCall_Text_BrendanRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets:
	.string "{JPN}トクサネは はれのひが\n"
	.string "{JPN}おおくて かぜも あんていしてる\p"
	.string "{JPN}ロケットの だいしゃには\n"
	.string "{JPN}りそうてきな ばしょなんだ$"

MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel:
	.string "{JPN}なぜ マグマだんが\n"
	.string "{JPN}ロケットの ねんりょうを\nぬすみたがるんだろう?$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
	.string "{JPN}もうすこし わかかったら\n"
	.string "{JPN}うちゅうひこうしに なりたかったなあ...\p"
	.string "{JPN}いや... まだ おそくない!\n"
	.string "{JPN}やってみせる ぞ!$"

MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis:
	.string "{JPN}マグマだんに ねんりょうを\n"
	.string "{JPN}とられたら うちゅうに いけない!\p"
	.string "{JPN}こんな ひどいことを\n"
	.string "{JPN}ゆるすわけには いかない!$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
	.string "{JPN}いつか ふつうの ひとでも\n"
	.string "{JPN}うちゅうに いけるように なったら\lいいのになあ...$"
MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace:
	.string "{JPN}マグマだん...\n"
	.string "{JPN}かれらも うちゅうに いきたいのかな?$"

MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn:
	.string "{JPN}なにを かんがえてるんだ?\p"
	.string "{JPN}3たい1で ふりなのに\n"
	.string "{JPN}まだ たたかうつもりか?$"

MossdeepCity_SpaceCenter_2F_Text_GoodAnswer:
	.string "{JPN}いいこたえだ!\n"
	.string "{JPN}それが かしこいひとの\nすることだ!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro:
	.string "{JPN}むこうみずな やつだな!\n"
	.string "{JPN}よし おれが さきに いくぞ!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat:
	.string "{JPN}まけた!\n"
	.string "{JPN}でも!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro:
	.string "{JPN}あんしんするのは まだはやい!\n"
	.string "{JPN}つぎは おれだ!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat:
	.string "{JPN}おれも まけた!\n"
	.string "{JPN}でも!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro:
	.string "{JPN}きゅうけいしたいだろうが\n"
	.string "{JPN}そうは いかせないぜ!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat:
	.string "{JPN}きゅうけいすれば よかった...\n"
	.string "{JPN}そうすれば よかったのに...$"
MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle:
	.string "{JPN}3にんも いるのに\n"
	.string "{JPN}こんな ざまとは...$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle:
	.string "{JPN}おれたち 3にんとも まけるなんて...\n"
	.string "{JPN}いつもより みっつも ひどい ありさまだ!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle:
	.string "{JPN}おれたち リーダーの\n"
	.string "{JPN}やくに たってるのかな?$"

MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou:
	.string "{JPN}へへへ!\p"
	.string "{JPN}ねんりょうを とりに きたのに\n"
	.string "{JPN}また じゃまされるとは!\p"
	.string "{JPN}おまえも じゃまするなら\n"
	.string "{JPN}いっしょに かたづけてやる!$"

MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere:
	.string "{JPN}マツブサ: どけ!\n"
	.string "{JPN}じゃまするな!$"

MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel:
	.string "{JPN}ダイゴ: マグマだん...\p"
	.string "{JPN}ロケットねんりょうを ぬすんで\n"
	.string "{JPN}なにを するつもりだ?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano:
	.string "{JPN}マツブサ: ふふふ... そんなに\n"
	.string "{JPN}きになるなら おしえてやろう\p"
	.string "{JPN}このねんりょうを すべて\n"
	.string "{JPN}えんとつやまに うちこむのだ!\p"
	.string "{JPN}グラードンが いなくなった いまとなっては\n"
	.string "{JPN}あんな やまは ようなしだからな!\p"
	.string "{JPN}ねんりょうの ちからで かざんを\n"
	.string "{JPN}だいふんかさせてやる!\p"
	.string "{JPN}すさまじいことに なるぞ!$"

MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle:
	.string "{JPN}ダイゴ: {PLAYER}くん!\n"
	.string "{JPN}てつだってくれるのか?\p"
	.string "{JPN}いっしょに たたかおう!\n"
	.string "{JPN}じゅんびは いいか?$"

MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly:
	.string "{JPN}ダイゴ: それなら いそいで!\n"
	.string "{JPN}はやく じゅんびしてくれ!$"

MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand:
	.string "{JPN}わたしが ほしいのは...\n"
	.string "{JPN}ただ だいちを ひろげたいだけなのだ...$"
MossdeepCity_SpaceCenter_Text_TabithaDefeat:
	.string "{JPN}ボスと いっしょです...$"
MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided:
	.string "{JPN}マツブサ: かざんの だいふんかは\n"
	.string "{JPN}しっぱいした...\p"
	.string "{JPN}グラードンを めざめさせても\n"
	.string "{JPN}せいぎょできなかった...\p"
	.string "{JPN}だいちを ひろげるという もくひょうは\n"
	.string "{JPN}まちがっていたのか?\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}もし...\n"
	.string "{JPN}もし われわれ マグマだんが\l"
	.string "{JPN}まちがっているなら...\l"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}アクアだんの うみを ひろげるという\nmくひょうも どうよう に まちがって\lいるのでは ないだろうか?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp:
	.string "{JPN}マツブサ: わかった...\n"
	.string "{JPN}ねんりょうは あきらめよう...\p"
	.string "{JPN}もっと じゅうような ことを\n"
	.string "{JPN}しらべなければ ならないようだ...$"
MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome:
	.string "{JPN}ダイゴ: ふう きんちょうしたよ\n"
	.string "{JPN}{PLAYER}くん ありがとう\p"
	.string "{JPN}えんじょしてくれた おれいに\n"
	.string "{JPN}きみに あげたいものがある\p"
	.string "{JPN}このあと おれのいえに\n"
	.string "{JPN}きてくれないか\p"
	.string "{JPN}あ そうそう おれは\n"
	.string "{JPN}カナズミシティには すんでない\nこのしまに すんでるんだ$"
