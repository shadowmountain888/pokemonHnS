.equ LOCALID_WANDAS_BF, 1
.set LOCALID_BRINEY, 5
.set LOCALID_GRUNT, 6
.set LOCALID_PEEKO, 7
.equ LOCALID_WANDA, 10

RusturfTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RusturfTunnel_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 4, RusturfTunnel_EventScript_ClearTunnelScene
	map_script_2 VAR_GARBAGEVAR, 5, RusturfTunnel_EventScript_ClearTunnelScene
	.2byte 0

RusturfTunnel_OnTransition:
	callnative SetTimeBasedEncounters
	call_if_eq VAR_GARBAGEVAR, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
	end

RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
	setobjectxyperm LOCALID_PEEKO, 13, 4
	setobjectxyperm LOCALID_GRUNT, 13, 5
	return

RusturfTunnel_EventScript_Wanda::
	lock
	faceplayer
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_AlreadySpokenTo::
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_ClearTunnelScene::
	lockall
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
	releaseall
	end

RusturfTunnel_EventScript_BoyfriendApproachWanda1::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda2::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda3::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend1::
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend2::
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend3::
	return

RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
	closemessage
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
	waitmovement 0
	return

RusturfTunnel_EventScript_WandasBoyfriendNotice::
	playse SE_PIN
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_WandaExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandaExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerWatchWandaExit:
	delay_8
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused2:
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused3:
	walk_up
	walk_in_place_faster_down
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend:
	walk_right
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BoyfriendFaceRight:
	walk_up
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
	walk_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda1:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

RusturfTunnel_EventScript_TunnelBlockagePos1::
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_TunnelBlockagePos2::
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_TunnelBlockagePos3::
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_AquaGruntBackUp::
	lockall
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
	waitmovement 0
	copyobjectxytoperm LOCALID_GRUNT
	copyobjectxytoperm LOCALID_PEEKO
	setvar VAR_GARBAGEVAR, 3
	releaseall
	end

RusturfTunnel_Movement_GruntAndPeekoBackUp:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RusturfTunnel_EventScript_Grunt::
	lock
	faceplayer
	callnative RemoveFollowingPokemon
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TREVOR, RusturfTunnel_Text_GruntDefeat
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_GOODS
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_GRUNT
	delay 50
	addobject LOCALID_BRINEY
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
	waitmovement 0
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
	applymovement LOCALID_BRINEY, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyExit
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_PeekoExit
	waitmovement 0
	removeobject LOCALID_BRINEY
	removeobject LOCALID_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_GARBAGEVAR, 4
	setvar VAR_GARBAGEVAR, 1
	setflag FLAG_GARBAGEFLAG
	callnative UpdateFollowingPokemon
	release
	end

RusturfTunnel_Movement_PushPlayerAsideForGrunt:
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_PlayerMoveAsideForBriney:
	walk_down
	walk_in_place_faster_up
	step_end

RusturfTunnel_Movement_GruntEscape:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_BrineyExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_Movement_PlayerWatchBrineyExit:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko2:
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_PeekoExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

RusturfTunnel_Text_ComeAndGetSome:
	.string "{JPN}なんだ かかってくるのか?\n"
	.string "{JPN}それなら かかってこい!$"

RusturfTunnel_Text_Peeko:
	.string "{JPN}ピーコ: ぴい ぴひょー!$"

RusturfTunnel_Text_GruntIntro:
	.string "{JPN}ぐらあ  くそったれめ!\p"
	.string "{JPN}じんしつの ポケモンなんて\n"
	.string "{JPN}やくに たたなかったぜ!\p"
	.string "{JPN}しかも この どんづまりの\n"
	.string "{JPN}トンネルに にげこんじまった!\p"
	.string "{JPN}おい! おまえ!\n"
	.string "{JPN}おれと しょうぶ したいのか?$"

RusturfTunnel_Text_GruntDefeat:
	.string "{JPN}うおおおお!おれの はんざいしゃ\n"
	.string "{JPN}じんせいも ゆきづまりだ!$"

RusturfTunnel_Text_GruntTakePackage:
	.string "{JPN}まったく おもしろくねえ...\p"
	.string "{JPN}ボスは かんたんな しごとだって\n"
	.string "{JPN}いったのによ.\p"
	.string "{JPN}デボンから にもつを\n"
	.string "{JPN}ぬすんでくるだけでいいってな.\p"
	.string "{JPN}ちっ!\n"
	.string "{JPN}そんなに ほしけりゃ かえしてやるよ!$"

RusturfTunnel_Text_PeekoGladToSeeYouSafe:
	.string "{JPN}ピーコ!\n"
	.string "{JPN}ぶじで よかった!$"

RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
	.string "{JPN}ピーコが たすかったのは\n"
	.string "{JPN}きみの おかげじゃ!\p"
	.string "{JPN}わしは ハギろうじんと いう.\n"
	.string "{JPN}きみは?\p"
	.string "{JPN}... ... ... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ... ... ...\p"
	.string "{JPN}ほほう  {PLAYER}くんか!\n"
	.string "{JPN}ほんとうに ありがとう!\p"
	.string "{JPN}なにか こまったことが あったら\n"
	.string "{JPN}えんりょなく はなしかけておくれ!\p"
	.string "{JPN}ふだんは トウカのもりの ちかくの\n"
	.string "{JPN}うみべの いえに いるからの.\n"
	.string "{JPN}さあ ピーコ  いえに\n"
	.string "{JPN}かえろうかね.\pピーコ: ピヒョー!$"

RusturfTunnel_Text_WhyCantTheyKeepDigging:
	.string "{JPN}... ...\p"
	.string "{JPN}なぜ ほりつづけられないのか?\n"
	.string "{JPN}がんばんが かたすぎるのか?\p"
	.string "{JPN}シダケタウンの むこうで\n"
	.string "{JPN}あいしいひとが まっている...\p"
	.string "{JPN}もし カナシダと シダケタウンが\n"
	.string "{JPN}この トンネルで つながれば\l"
	.string "{JPN}まいにち あいに いけるのに...\p"
	.string "{JPN}でも これじゃあ...\n"
	.string "{JPN}どうすれば いいんだ?$"

RusturfTunnel_Text_ToGetToVerdanturf:
	.string "{JPN}カナシダから シダケタウンに\n"
	.string "{JPN}いくには ムロタウンを とおって\l"
	.string "{JPN}キンセツと カイナを とおらないと...$"
RusturfTunnel_Text_YouShatteredBoulderTakeHM:
	.string "{JPN}おお!みちを ふさいでいた\n"
	.string "{JPN}いわを くだいてくれたのか.\p"
	.string "{JPN}かんしゃの きもちを こめて \n"
	.string "{JPN}この ひでんマシンを きみに あげよう.$"

RusturfTunnel_Text_ExplainStrength:
	.string "{JPN}その ひでんマシンには かいりきが\n"
	.string "{JPN}はいっている.\p"
	.string "{JPN}きんりょく じまんの ポケモンが\n"
	.string "{JPN}おぼえれば おおきな いわでも\lうごかせるように なるぞ.$"

RusturfTunnel_Text_WandaReunion:
	.string "{JPN}ワンダ!\n"
	.string "{JPN}これで いつでも あえるね!\p"
	.string "{JPN}ワンダ: そうですね...うれしいです.\n"
	.string "{JPN}わたしの いえで やすんでください.$"

RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
	.string "{JPN}この いわの むこうがわに...\n"
	.string "{JPN}かれが いるの.\n"
	.string "{JPN}かれは... わたしに あうために\n"
	.string "{JPN}トンネルを ほってるんじゃない.\n"
	.string "{JPN}みんなの ために あらあらしい\n"
	.string "{JPN}てで いっしょうけんめい はたらいてる.$"

RusturfTunnel_Text_MikeIntro:
	.string "{JPN}やまの おとこを マウンテンマンと\n"
	.string "{JPN}いうだろう?\p"
	.string "{JPN}じゃあ なぜ やまに いる ポケモンを\n"
	.string "{JPN}マウンテンポケモンと よばないんだ?$"

RusturfTunnel_Text_MikeDefeat:
	.string "{JPN}おれの ポケモンが...\n"
	.string "{JPN}ちからつきちまった...$"
RusturfTunnel_Text_MikePostBattle:
	.string "{JPN}ここは ポケモンを まもるために\n"
	.string "{JPN}かいはつを ちゅうしした らしいな.\l"
	.string "{JPN}いい はなしじゃないか!$"

