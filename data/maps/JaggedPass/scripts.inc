.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	callnative SetTimeBasedEncounters
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	callnative SetTimeBasedEncounters
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_TERRELL, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_KAZU, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAZU
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_KAZU, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_NAOKO, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NAOKO
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_NAOKO, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_COLETTE, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "{JPN}えんとつやまの でこぼこみち...\p"
	.string "{JPN}これこそ ぼくが ずっと\n"
	.string "{JPN}もとめていた やまなんだ.\p"
	.string "{JPN}この でこぼこした かんじが...\n"
	.string "{JPN}ぼくの こころを ゆさぶるんだ!$"

JaggedPass_Text_EricDefeat:
	.string "{JPN}まけて くやしい!$"

JaggedPass_Text_EricPostBattle:
	.string "{JPN}たしかに ポケモンしょうぶでは\n"
	.string "{JPN}まけてしまった...\p"
	.string "{JPN}でも やまへの あいじょうなら\nきみには まけないぞ!$"

JaggedPass_Text_DianaIntro:
	.string "{JPN}ここは きがるな ハイキング\n"
	.string "{JPN}コースじゃ ないよ.\nピクニックには むかないね.$"

JaggedPass_Text_DianaDefeat:
	.string "{JPN}あーあ だめ!\n"
	.string "{JPN}じめんが でこぼこすぎて...$"
JaggedPass_Text_DianaPostBattle:
	.string "{JPN}しってる?\p"
	.string "{JPN}この でこぼこな みちを\n"
	.string "{JPN}じてんしゃで のぼる ひとも\nいるんだって.$"

JaggedPass_Text_DianaRegister:
	.string "{JPN}また この へんに くることは\n"
	.string "{JPN}ある? もし もどってきたら\nさいせんしょう したいな.$"

JaggedPass_Text_DianaRematchIntro:
	.string "{JPN}ピクニックは どこでも たのしい.\n"
	.string "{JPN}ポケモンと おなじだね!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "{JPN}じめんが でこぼこ すぎるから\n"
	.string "{JPN}まけちゃった!$"

JaggedPass_Text_DianaPostRematch:
	.string "{JPN}まけたことは わすれて\n"
	.string "{JPN}でこぼこな ハイキングを\nたのしむよ.$"

JaggedPass_Text_EthanIntro:
	.string "{JPN}ギザギザやまは あるきにくいな.\n"
	.string "{JPN}でも くんれんには いいばしょだ.$"

JaggedPass_Text_EthanDefeat:
	.string "{JPN}あしばを さがしている あいだに\n"
	.string "{JPN}しょうぶが おわって\nしまったよ...$"
JaggedPass_Text_EthanPostBattle:
	.string "{JPN}ダートじてんしゃが あれば\n"
	.string "{JPN}だんさを とべるのに.$"

JaggedPass_Text_EthanRegister:
	.string "{JPN}この でこぼこに なれたら\n"
	.string "{JPN}ぜったい かつよ!\p"
	.string "{JPN}ポケナビに とうろく してくれる?$"

JaggedPass_Text_EthanRematchIntro:
	.string "{JPN}でこぼこに なれたよ.\n"
	.string "{JPN}いまは うたいながら のぼってる.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "{JPN}この でこぼこした じめんでの\n"
	.string "{JPN}しょうぶは やっぱり\nむずかしいな...$"
JaggedPass_Text_EthanPostRematch:
	.string "{JPN}キンセツシティの ライデルさんから\n"
	.string "{JPN}アクロじてんしゃを\nかりるべきだったかな...$"
JaggedPass_Text_GruntIntro:
	.string "{JPN}わー!\n"
	.string "{JPN}なにを してるんだ?\p"
	.string "{JPN}おれが こんなところで\n"
	.string "{JPN}なにを してるかって?\pおまえには かんけいないだろ?$"

JaggedPass_Text_GruntDefeat:
	.string "{JPN}ぐううう...\p"
	.string "{JPN}すぐに アジトに にげこめば\n"
	.string "{JPN}よかった...$"
JaggedPass_Text_GoWhereverYouWant:
	.string "{JPN}わかった わかった!\n"
	.string "{JPN}おまえが つよいことは みとめる!\p"
	.string "{JPN}おれのことは きにするな.\n"
	.string "{JPN}どこでも すきなところに いけ!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "{JPN}おお! この いわが\n"
	.string "{JPN}マグマのしるしに はんのうして\nゆれている!$"

JaggedPass_Text_JulioIntro:
	.string "{JPN}あいやー! やまを いっきに\n"
	.string "{JPN}かけおりるなんて こわすぎるよ!$"

JaggedPass_Text_JulioDefeat:
	.string "{JPN}からだが ばらばらに\nなりそうだよ...$"
JaggedPass_Text_JulioPostBattle:
	.string "{JPN}じてんしゃが はねすぎて\n"
	.string "{JPN}おしりが いたくなったよ...$"
JaggedPass_Text_AutumnIntro:
	.string "{JPN}まいにち この やまに のぼってる.\n"
	.string "{JPN}じしんは あるよ!$"

JaggedPass_Text_AutumnDefeat:
	.string "{JPN}うーん...\n"
	.string "{JPN}なにが いけなかったのかな?$"

JaggedPass_Text_AutumnPostBattle:
	.string "{JPN}ここから すこし のぼったところの\n"
	.string "{JPN}へんな かたちの いわは なんだろう?$"

