.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_TODD, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TOM, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_GARBAGEFLAG
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_GARBAGEFLAG
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "{JPN}はい? クスノキをおさがしでしたら\n"
	.string "{JPN}わたしですが.\p"
	.string "{JPN}あ! それはデボンの ダイゴさんに\n"
	.string "{JPN}ちゅうもんしていた ぶひんですね!\p"
	.string "{JPN}ありがとう! すばらしい!\n"
	.string "{JPN}これで たんけんの じゅんびが\lできます!$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "{JPN}へへへ ちょっとまった!\n"
	.string "{JPN}その ぶひんは いただくぜ!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "{JPN}クスノキせんちょうな なに?\n"
	.string "{JPN}きみたちは だれだ?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "{JPN}おれたちは アクアだん!\p"
	.string "{JPN}ボスが その ぶひんを\n"
	.string "{JPN}ほしがってるんだ!\lごちゃごちゃ いわずに わたせ!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "{JPN}うわあああ!\n"
	.string "{JPN}こどもに まけた!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "{JPN}ああ なんてこった...\n"
	.string "{JPN}ボスがおこるぞ...$"
SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "{JPN}ちっ なさけない やつめ!\n"
	.string "{JPN}おれが あいてを してやる!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "{JPN}なに?!\n"
	.string "{JPN}おれも まけた!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "{JPN}どうする? ぶひんが\n"
	.string "{JPN}てにはいらなかったら やばいぞ!\p"
	.string "{JPN}ちくしょう こんな がきに\n"
	.string "{JPN}じゃまされるとは おもわなかった!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "{JPN}ぶひんを うばうのに なにを\n"
	.string "{JPN}てまどってるかと おもえば\l"
	.string "{JPN}たった ひとりの こどもに\lてこずってるのか!$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "{JPN}われわれは アクアだん \n"
	.string "{JPN}うみを あいしているのだ!\p"
	.string "{JPN}そして わたしは アクアだんの\n"
	.string "{JPN}リーダー アオギリだ!\p"
	.string "{JPN}なぜ われわれの じゃまを\n"
	.string "{JPN}するのだ?\p"
	.string "{JPN}...まさか! きさまは!\n"
	.string "{JPN}マグマだんの ひとりでは?\p"
	.string "{JPN}まて それは おかしい.\n"
	.string "{JPN}かっこうが ちがうじゃないか.\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}ポケモン ひと... すべての\n"
	.string "{JPN}いのちは うみに たよっている.\p"
	.string "{JPN}だから アクアだんは\n"
	.string "{JPN}うみの かくだいに ささげているのだ.\p"
	.string "{JPN}どうだ? われわれの していることは\n"
	.string "{JPN}すばらしい じぎょうだと おもわないか.\p"
	.string "{JPN}ああ いいだろう...\n"
	.string "{JPN}きみは まだ わかすぎて\l"
	.string "{JPN}われわれの こうけつな もくてきを\l"
	.string "{JPN}りかい できない.\p"
	.string "{JPN}しかし けいこくしておく.\n"
	.string "{JPN}こんど われわれの けいかくの\l"
	.string "{JPN}じゃまを することなど かんがえるな.\pその けっか きみに\nたかい だいしょうを はらわせるぞ!\pそれを わすれるな!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "{JPN}クスノキせんちょう: きみは...\n"
	.string "{JPN}ああ そうか {PLAYER}くんだね...\p"
	.string "{JPN}とにかく きけんな じょうきょう\n"
	.string "{JPN}だった! たすけてくれて ありがとう!\p"
	.string "{JPN}そうそう デボンから ぶひんを\n"
	.string "{JPN}もってきてくれた ことも\lわすれるところだった!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "{JPN}クスノキせんちょうおっと!\n"
	.string "{JPN}じかんが ない!\p"
	.string "{JPN}かいていたんけんに でかけなければ\n"
	.string "{JPN}ならないのです.\p"
	.string "{JPN}ありがとう! でも もう\n"
	.string "{JPN}いかなければ!\p"
	.string "{JPN}よろしければ しせつを みてまわって\n"
	.string "{JPN}くださいね.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "{JPN}ここで ふねの もけいを みたよ.\p"
	.string "{JPN}ムロタウンの ちかくの\n"
	.string "{JPN}すてられたふねを おもいだした...$"
SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "{JPN}はくぶつかんの なかを\n"
	.string "{JPN}はしりまわっては だめよ!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "{JPN}わあ せんすいかんって すごい!\n"
	.string "{JPN}のってみたいなあ!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "{JPN}すいしつサンプル1と\n"
	.string "{JPN}かいてある.\p"
	.string "{JPN}うみは つながっているけど\n"
	.string "{JPN}ちいきによって みずが ちがうようだ.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "{JPN}すいしつサンプル2と\n"
	.string "{JPN}かいてある.\p"
	.string "{JPN}かいすいの しおからさも\n"
	.string "{JPN}ちいきによって ちがうのかな?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "{JPN}ゴムボールが ふくらんだり\n"
	.string "{JPN}ちぢんだり している.\p"
	.string "{JPN}うみでは みず じたいの おもさが\n"
	.string "{JPN}あつりょくと なる.\p"
	.string "{JPN}あさい うみでは あつりょくは\n"
	.string "{JPN}それほど つよくない.\p"
	.string "{JPN}しかし ふかい うみでは\n"
	.string "{JPN}せまい ばしょでも すうまんトンの\l"
	.string "{JPN}あつりょくが かかることがある$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "{JPN}ホウエンちほうの もけい\p"
	.string "{JPN}\n"
	.string "{JPN}ホウエンちほうの\n"
	.string "{JPN}ちいさな ジオラマだ.\pミシロタウンは どこにあるんだろう?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "{JPN}かいすいの ながれについての\n"
	.string "{JPN}てんじだ.\p"
	.string "{JPN}かいていちかくでは おんどや\n"
	.string "{JPN}えんぶんなどの ちがいによって\lみずが ながれている$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "{JPN}かいすいの ながれについての\n"
	.string "{JPN}てんじだ.\p"
	.string "{JPN}かいめんちかくでは かぜによって\nうごく かいりゅうが ながれている$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "{JPN}きゃくせん ダイドウごう\p"
	.string "{JPN}クスノキぞうせんじょで\n"
	.string "{JPN}けんせつちゅうの ふねの\lしゅくしゃく もけい$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "{JPN}せんすいかん エクスプローラー1\p"
	.string "{JPN}こうせいのうな\n"
	.string "{JPN}かいていたんけん せんすいかんの\lもけい$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "{JPN}せんすいポッド\p"
	.string "{JPN}かいていたんけんようの\n"
	.string "{JPN}コンパクトな むじんポッドの\lもけい$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "{JPN}サントアンヌごう\p"
	.string "{JPN}せかい いっしゅうする\n"
	.string "{JPN}ごうかきゃくせんの もけい$"

