.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_GARBAGEFLAG
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_THEO, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_TERU, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "{JPN}いんせきに ひめられた ちから...\p"
	.string "{JPN}この きかいで その ちからを\n"
	.string "{JPN}ぞうふくさせれば えんとつやまの\l"
	.string "{JPN}かざんかつどうが いっきに...\p"
	.string "{JPN}そのエネルギーが かこうの おくで\n"
	.string "{JPN}せいちょうして...\l"
	.string "{JPN}ふふふ...$"
MtChimney_Text_MaxieIntro:
	.string "{JPN}マツブサ: ん?\n"
	.string "{JPN}きみは だれだ?\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}アオギリが こぼしていたな\n"
	.string "{JPN}チームアクアの じゃまを する\l"
	.string "{JPN}こどもが いると\p"
	.string "{JPN}きみのことだったのか\p"
	.string "{JPN}ふん! われわれ チームマグマの\n"
	.string "{JPN}じゃまを するつもりか?\p"
	.string "{JPN}いいか よく きけ\n"
	.string "{JPN}むかし いきものたちは だいちを\l"
	.string "{JPN}つかって くらし そだった\p"
	.string "{JPN}だから だいちこそが すべて!\n"
	.string "{JPN}すべての ゆりかごなのだ!\p"
	.string "{JPN}だからこそ チームマグマは\n"
	.string "{JPN}りくちの かくだいに ささげている\p"
	.string "{JPN}それは ひとるいと ポケモンの\n"
	.string "{JPN}さらなる はってんの ため!\p"
	.string "{JPN}そのために この やまに ねむる\n"
	.string "{JPN}ちからが ひつようなのだ...\p"
	.string "{JPN}おっと! きみに そこまで\n"
	.string "{JPN}おしえる ひつようは なかった\p"
	.string "{JPN}だが かまわん!\n"
	.string "{JPN}われわれの いだいな けいかくに\l"
	.string "{JPN}てを だした けっかを おしえてやる!$"

MtChimney_Text_MaxieDefeat:
	.string "{JPN}なんだと?!\p"
	.string "{JPN}このマツブサが\nゆだんしたというのか?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "{JPN}マツブサ: だが もう じゅうぶんだ\n"
	.string "{JPN}こんかいは ひいてやろう\p"
	.string "{JPN}だが これで チームマグマを\n"
	.string "{JPN}みおさめだとは おもうな\p"
	.string "{JPN}ふふふ...\p"
	.string "{JPN}いんせきが なくても あの たまさえ\n"
	.string "{JPN}てに いれれば... ふふふ...$"
MtChimney_Text_TabithaIntro:
	.string "{JPN}へへへ!\p"
	.string "{JPN}ここまで やってきたのか!\p"
	.string "{JPN}だが おそすぎたな!\n"
	.string "{JPN}りゅうせいのたきから いんせきを\l"
	.string "{JPN}ボスに とどけたからな!$"

MtChimney_Text_TabithaDefeat:
	.string "{JPN}へへへ...\p"
	.string "{JPN}ぼくが まけても リーダーが\n"
	.string "{JPN}あれを めざませば...$"
MtChimney_Text_TabithaPostBattle:
	.string "{JPN}ボス! はやく!\n"
	.string "{JPN}いんせきのエネルギーを!$"
	.string ""
MtChimney_Text_Grunt2Intro:
	.string "{JPN}おれたち マグマだんは\n"
	.string "{JPN}みんなのために がんばってるんだ.\p"
	.string "{JPN}アイツのちからで とちが ふえれば\n"
	.string "{JPN}すむばしょも ふえるだろ.\p"
	.string "{JPN}みんな よろこぶぞ!$"

MtChimney_Text_Grunt2Defeat:
	.string "{JPN}え?\n"
	.string "{JPN}まけたって どういうことだ?$"

MtChimney_Text_Grunt2PostBattle:
	.string "{JPN}ボスは いってる.\n"
	.string "{JPN}みんなが しあわせになるって.\p"
	.string "{JPN}なのに なんで みんな\n"
	.string "{JPN}じゃまするんだ?$"

MtChimney_Text_Grunt1Intro:
	.string "{JPN}とちが ふえれば おれも\n"
	.string "{JPN}でっかい いえが もてるぞ!\p"
	.string "{JPN}ようがんを かためた うえに\nたてるんだ!$"

MtChimney_Text_Grunt1Defeat:
	.string "{JPN}おおきな いえの ゆめが...$"
MtChimney_Text_Grunt1PostBattle:
	.string "{JPN}きみみたいな こどもは\n"
	.string "{JPN}なみあそびでも してろ!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "{JPN}うざい チームアクア...\n"
	.string "{JPN}いつも けいかくを じゃまして!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "{JPN}いんせきには すごい\nパワーが つまってるんだ!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "{JPN}じゃまするなよ!\p"
	.string "{JPN}おれたちは みんなのために\n"
	.string "{JPN}アイツを めざめさせようと\nしてるんだ!$"

MtChimney_Text_AquasNameSimilar:
	.string "{JPN}おれたちは マグマだん!\p"
	.string "{JPN}あいつらは アクアだん!\p"
	.string "{JPN}にたような なまえを つかうなんて\n"
	.string "{JPN}むかつくぜ!$"

MtChimney_Text_DouseThemInFire:
	.string "{JPN}そうだ!\n"
	.string "{JPN}かえんで やっつけろ!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "{JPN}もっと とちを ふやしつづけるぞ!$"

MtChimney_Text_Bufoh:
	.string "{JPN}ぶふぉー!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "{JPN}アオギリ: くそっ {PLAYER}!\n"
	.string "{JPN}やってくると おもったぜ!\p"
	.string "{JPN}マグマだんの きちがいじみた\n"
	.string "{JPN}やつらの こうどうを みろ!\p"
	.string "{JPN}あいつらは ぬすんだ いんせきの\n"
	.string "{JPN}パワーを かざんに そそごうと\n"
	.string "{JPN}してる!\p"
	.string "{JPN}そんなことを すれば\nかざんが ふんかするぞ!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "{JPN}アオギリ: ぐぬぬ...\p"
	.string "{JPN}マツブサを とめたいが\n"
	.string "{JPN}それどころじゃない!\p"
	.string "{JPN}3にんも あいてに していたら\n"
	.string "{JPN}てが まわらないぞ!$"

MtChimney_Text_ArchieThankYou:
	.string "{JPN}アオギリ: {PLAYER}!\n"
	.string "{JPN}ありがとう!\p"
	.string "{JPN}きみの おかげで チームマグマの\n"
	.string "{JPN}はかいてきな けいかくを そしできた!\p"
	.string "{JPN}だが... きみは...\n"
	.string "{JPN}どちらの みかたなんだ?\p"
	.string "{JPN}ああ どうでも いいことだ\n"
	.string "{JPN}われわれは けいかいを つづけ\n"
	.string "{JPN}チームマグマを おいつづける\p"
	.string "{JPN}{PLAYER} また あうだろう!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "{JPN}ちくしょう... チームマグマの ほうが\n"
	.string "{JPN}かずが おおい!\nついていけないぞ!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "{JPN}とちが ふえたら みずタイプの\n"
	.string "{JPN}ポケモンの すみかが へっちゃう!$"

MtChimney_Text_MagmasNameSimilar:
	.string "{JPN}おれたちは アクアだん!\p"
	.string "{JPN}あいつらは マグマだん!\p"
	.string "{JPN}こんがらがるような なまえを\n"
	.string "{JPN}つかうなんて はらたつぜ!$"

MtChimney_Text_Bushaa:
	.string "{JPN}ぶしゃー!$"

MtChimney_Text_LavaCookiesJust200:
	.string "{JPN}マグマクッキーは やまじの\n"
	.string "{JPN}めいぶつですよ.\p"
	.string "{JPN}たべてみませんか?\nたった 200えんです.$"

MtChimney_Text_ThankYouDear:
	.string "{JPN}ありがとう ございます!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "{JPN}あら おかねが たりませんね.$"
	.string ""

MtChimney_Text_OhFineThen:
	.string "{JPN}そうですか.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "{JPN}いんせきが ふしぎな きかいに\n"
	.string "{JPN}セットされている...\p"
	.string "{JPN}きかいは いんせきに エネルギーを\n"
	.string "{JPN}ためこんでいる ようだ$"

MtChimney_Text_RemoveTheMeteorite:
	.string "{JPN}いんせきが ふしぎな きかいに\n"
	.string "{JPN}セットされている...\p"
	.string "{JPN}いんせきを とりはずしますか?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{JPN}{PLAYER}は ふしぎな きかいから\n"
	.string "{JPN}いんせきを とりはずした.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{JPN}{PLAYER}は いんせきを\n"
	.string "{JPN}そのままにしておいた.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "{JPN}この ふしぎな きかい...\n"
	.string "{JPN}まったく はんのうが ない$"

MtChimney_Text_RouteSign:
	.string "{JPN}{DOWN_ARROW} ギザギザのみち\n"
	.string "{JPN}フエンタウン さき$"

MtChimney_Text_ShelbyIntro:
	.string "{JPN}おんせんに はいって\n"
	.string "{JPN}つかれた からだを いやしてきた.\l"
	.string "{JPN}いまは ちからが みなぎってるぞ!$"

MtChimney_Text_ShelbyDefeat:
	.string "{JPN}あら まあ.\n"
	.string "{JPN}なんて すてきなの!$"

MtChimney_Text_ShelbyPostBattle:
	.string "{JPN}まあ まあ まけて しまいました.\n"
	.string "{JPN}もう エキスパートとは なのれませんね?$"

MtChimney_Text_ShelbyRegister:
	.string "{JPN}ありがとう おこさま.たのしかったです.\n"
	.string "{JPN}まご と たたかっているようで.\p"
	.string "{JPN}また さいせんの ために\n"
	.string "{JPN}あいに きてください.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "{JPN}あなたが ポケモンたちの こころと\n"
	.string "{JPN}ひとつに なることが できれば\l"
	.string "{JPN}すばらしいことが できるでしょう.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "{JPN}あら まあ.\n"
	.string "{JPN}なんて すてきなの!$"

MtChimney_Text_ShelbyPostRematch:
	.string "{JPN}あなたの こころが ポケモンたちの\n"
	.string "{JPN}こころと ひとつに なったのでしょう.$"

MtChimney_Text_MelissaIntro:
	.string "{JPN}わたし もえあがってるのよ ベイビー.\n"
	.string "{JPN}がまんできない! たたかわなくちゃ!$"

MtChimney_Text_MelissaDefeat:
	.string "{JPN}うー それは もえるような\nあつい しあいだった!$"

MtChimney_Text_MelissaPostBattle:
	.string "{JPN}えんとつやまの ねつが\n"
	.string "{JPN}わたしを あつくするの ベイビー!$"

MtChimney_Text_SheilaIntro:
	.string "{JPN}ついに えんとつやまに ついた!\n"
	.string "{JPN}ポケモンを たたかわせたい!$"

MtChimney_Text_SheilaDefeat:
	.string "{JPN}きみの たたかいかた...\n"
	.string "{JPN}えんとつやまの ふんかみたい!$"

MtChimney_Text_SheilaPostBattle:
	.string "{JPN}いったとおり やっと えんとつやまに\n"
	.string "{JPN}きたんだ ちょっと けんぶつ\l"
	.string "{JPN}するだけじゃ もったいない...\p"
	.string "{JPN}バトルして おみやげに クッキーも\n"
	.string "{JPN}かっていこう$"

MtChimney_Text_ShirleyIntro:
	.string "{JPN}おんせんに はいってから\n"
	.string "{JPN}ちょうしが いいの!\l"
	.string "{JPN}ぜったい かつと おもう!$"

MtChimney_Text_ShirleyDefeat:
	.string "{JPN}きゃー!\n"
	.string "{JPN}みずから でると さむくなっちゃう.$"

MtChimney_Text_ShirleyPostBattle:
	.string "{JPN}また おんせんに はいらなくちゃ.\n"
	.string "{JPN}いっしょに はいる?\p"
	.string "{JPN}じょうだんよ!$"

MtChimney_Text_SawyerIntro:
	.string "{JPN}ここは すばらしい やまだ!\n"
	.string "{JPN}あつい ひとたちが たくさんいる!$"

MtChimney_Text_SawyerDefeat:
	.string "{JPN}おお きみも ほんとうの\nねつけつかんだ!$"

MtChimney_Text_SawyerPostBattle:
	.string "{JPN}ちほうの ひとたちと フエンおんせんに\n"
	.string "{JPN}はいらなくちゃな!$"

MtChimney_Text_SawyerRegister:
	.string "{JPN}きみのような ちいさな ひのたまが\n"
	.string "{JPN}すきだ.ポケナビに とうろくさせて.$"

MtChimney_Text_SawyerRematchIntro:
	.string "{JPN}この あたりの あつい ひとたちに\n"
	.string "{JPN}かこまれて しあわせだ.まけないぞ!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "{JPN}やれやれ きみは まえと おなじ\n"
	.string "{JPN}ねつけつかんだな!$"

MtChimney_Text_SawyerPostRematch:
	.string "{JPN}じっさい ここは ほんとうに あついな.\n"
	.string "{JPN}この あたりには あつすぎる ふくだ.$"

