.set LOCALID_ROCKETHIDEOUT3_LANCE, 3
.set LOCALID_ROCKETHIDEOUT3_DRAGONITE, 2
.set LOCALID_ROCKETHIDEOUT3_SILVER, 5
.set LOCALID_ROCKETHIDEOUT3_GIOVANNI, 16
.set LOCALID_ROCKETHIDEOUT3_PETREL, 15
.set LOCALID_ROCKETHIDEOUT3_MURKROW, 14
.set LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, 17

RocketHideout_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout_B3F_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B3F_OnLoad
	.byte 0

RocketHideout_B3F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_HideGate
	call_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_HidePetrel
	end
	
RocketHideout_B3F_HideGate::
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	return
RocketHideout_B3F_HidePetrel::
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	return

RocketHideout_B3F_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 6, RocketHideout_B3F_EventScript_LancePassword
	.2byte 0

RocketHideout_B3F_EventScript_LancePassword::
	lock
	delay 55
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_ExclamationMark
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_WalkRight1
	msgbox RocketHideout_B3F_Text_LanceGetPassword, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, RocketHideout_B3F_Movement_LanceLeave
	applymovement LOCALID_ROCKETHIDEOUT3_DRAGONITE, RocketHideout_B3F_Movement_DragoniteLeave
	waitmovement LOCALID_ROCKETHIDEOUT3_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT3_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 7
	release
	end

RocketHideout_B3F_Movement_LanceLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	delay_2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B3F_Movement_DragoniteLeave:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	delay_8
	delay_8
	walk_down
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

RocketHideout_B3F_Text_LanceGetPassword:
    .string "{JPN}ワタル: ボスのへやに はいるには\n"
	.string "{JPN}2つのあいことばが ひつようだ.\p"
    .string "{JPN}そのあいことばは ごくわずかな\n"
	.string "{JPN}ロケットだんしか しらない.\p"
    .string "{JPN}そこのロケットだんが しんせつに\n"
	.string "{JPN}おしえて くれたのだ.\p"
    .string "{JPN}{PLAYER} あいことばを\n"
	.string "{JPN}もらいに いこう.$"

RocketHideout_B3F_EventScript_RocketKO::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_B3FRocket, MSGBOX_DEFAULT
	release
	end

RocketHideout_B3F_Text_B3FRocket:
    .string "{JPN}ううう... マントのやつは\n"
	.string "{JPN}めちゃくちゃつよいぞ...$"

RocketHideout_B3F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 11
	release
	end

RocketHideout_B3F_Movement_MurkrowStairs1:
	jump_in_place_right
	jump_in_place_right
	step_end

RocketHideout_B3F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B3F_Trigger_Silver::
	lock
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	addobject LOCALID_ROCKETHIDEOUT3_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RocketHideout_B3F_Text_Rival, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverLeave
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	removeobject LOCALID_ROCKETHIDEOUT3_SILVER
	setvar VAR_MAHOGANY_TOWN_STATE, 8
	fadedefaultbgm
	release
	end

RocketHideout_B3F_Movement_SilverEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B3F_Movement_SilverLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B3F_EventScript_Door::
	lock
	goto_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_EventScript_DoorIsOpen
	goto_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_EventScript_OpenDoor
	msgbox RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword, MSGBOX_DEFAULT
	closemessage
	release
	end

RocketHideout_B3F_EventScript_OpenDoor::
	msgbox RocketHideout_B3F_Text_B3FLockedDoorOpenSesame, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	release
	end

RocketHideout_B3F_EventScript_DoorIsOpen::
	end

RocketHideout_B3F_EventScript_GruntF5::
	trainerbattle_single TRAINER_GRUNT_29 RocketHideout_B3F_Text_GruntF5Seen, RocketHideout_B3F_Text_GruntF5Beaten
	msgbox RocketHideout_B3F_Text_GruntF5After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_GRUNTF, RocketHideout_B3F_EventScript_IncrementPasswordGruntF
	end

RocketHideout_B3F_EventScript_IncrementPasswordGruntF::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_GRUNTF
	end

RocketHideout_B3F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_2 RocketHideout_B3F_Text_GruntM28Seen, RocketHideout_B3F_Text_GruntM28Beaten
	msgbox RocketHideout_B3F_Text_GruntM28After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_ETO, RocketHideout_B3F_EventScript_IncrementPasswordEto
	end

RocketHideout_B3F_EventScript_IncrementPasswordEto::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_ETO
	end

RocketHideout_B3F_EventScript_Ross::
	trainerbattle_single TRAINER_ROSS RocketHideout_B3F_Text_ScientistRossSeen, RocketHideout_B3F_Text_ScientistRossBeaten
	msgbox RocketHideout_B3F_Text_ScientistRossAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Mitch::
	trainerbattle_single TRAINER_MITCH RocketHideout_B3F_Text_ScientistMitchSeen, RocketHideout_B3F_Text_ScientistMitchBeaten
	msgbox RocketHideout_B3F_Text_ScientistMitchAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Item_IceHeal::
	finditem ITEM_ICE_HEAL
	end

RocketHideout_B3F_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end

RocketHideout_B3F_EventScript_Item_FullHeal::
	finditem ITEM_FULL_HEAL
	end

RocketHideout_B3F_EventScript_Item_GuardSpec::
	finditem ITEM_GUARD_SPEC
	end

RocketHideout_B3F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword:
    .string "{JPN}とびらが しまっている...\p"
	.string "{JPN}ふたつの あいことばが\nひつようだ.$"

RocketHideout_B3F_Text_B3FLockedDoorOpenSesame:
    .string "{JPN}とびらが しまっている...\p"
	.string "{JPN}{PLAYER}は ふたつの\n"
    .string "{JPN}あいことばを にゅうりょくした.\pとびらが ひらいた!$"

RocketHideout_B3F_Text_Rival:
	.string "{JPN}.........\p"
	.string "{JPN}こんどはこんなところを\nうろついてるのか\p"
	.string "{JPN}フフン!おまえそんなに\nロケットだんがすきなのかよ\p"
	.string "{JPN}...そんなことより\nあのマントのドラゴンつかい!\l"
	.string "{JPN}あいつはなにものなんだ?\p"
	.string "{JPN}オレのポケモンでも\nまったくはがたたなかった...\p"
	.string "{JPN}きょうまけたことはべつにいいさ\nもっとつよいポケモンを\l"
	.string "{JPN}てにいれることさえできれば\lあいつになんかまけやしない\p"
	.string "{JPN}それよりもきにいらないのは\nあのセリフ...\p"
	.string "{JPN}きみはポケモンへの\nあいとしんらいがたりないだと\p"
	.string "{JPN}そんななまぬるいこというやつに\nじぶんがまけたかとおもうと\l"
	.string "{JPN}はらがたってしかたない!\p"
	.string "{JPN}...フン!おまえの\nあいてなんかしてられるか!\p$"

@=======[PETREL]==============================================================================================================================

RocketHideout_B3F_EventScript_Giovanni::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_PetrelIntro, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, Common_Movement_QuestionMark
	delay 60
	msgbox RocketHideout_B3F_Text_PetrelDisbelief MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, RocketHideout_B3F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	removeobject LOCALID_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	addobject LOCALID_ROCKETHIDEOUT3_PETREL
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_Spin2
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWest
	msgbox RocketHideout_B3F_Text_PetrelReveal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_1, RocketHideout_B3F_Text_PetrelBeaten
	msgbox RocketHideout_B3F_Text_PetrelAfterBattle, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_LeaveEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_LeaveWest
	call_if_eq VAR_FACING, DIR_NORTH, RocketHideout_B3F_EventScript_LeaveEast
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_PETREL
	
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow1

	delay 120

	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEastMurkrow
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWestMurkrow

	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	msgbox RocketHideout_B3F_Text_MurkrowMimic, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow2
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW

	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	setvar VAR_ROCKET_PASSWORD, 3
	setvar VAR_MAHOGANY_TOWN_STATE, 9
	release
	end

RocketHideout_B3F_EventScript_FacingEastMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingWestMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingEast::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_WEST
	return

RocketHideout_B3F_EventScript_FacingWest::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_EAST
	return

RocketHideout_B3F_EventScript_FacingNorth::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_SOUTH
	return

RocketHideout_B3F_EventScript_LeaveEast::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveEast
	waitmovement 0
	return

RocketHideout_B3F_EventScript_LeaveWest::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveWest
	waitmovement 0
	return

RocketHideout_B3F_Movement_Murkrow1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	jump_in_place_right
	jump_in_place_left
	jump_in_place_down
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B3F_Movement_Murkrow2:
	jump_in_place_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	step_end

RocketHideout_B3F_Movement_LeaveEast:
	lock_facing_direction
	walk_slow_right
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end
RocketHideout_B3F_Movement_LeaveWest:
	lock_facing_direction
	walk_slow_left
	walk_slow_left
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B3F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Text_PetrelIntro:
	.string "{JPN}ぐっふっふっよくきたな\nきみが{PLAYER}か...\p"
	.string "{JPN}おや?\nわたしがだれかわからんかね?\p"
	.string "{JPN}サカキだよサカキさまだよ!\nぐわぁーっはっはーっ!\p$"

RocketHideout_B3F_Text_PetrelDisbelief:
	.string "{JPN}...あれ?\p"
	.string "{JPN}ぜんぜんにてない?\nサカキさまにみえない?\p"
	.string "{JPN}くっそーいっしょうけんめい\nれんしゅうしたのに!\p$"

RocketHideout_B3F_Text_PetrelReveal:
	.string "{JPN}ラムダ: おれはロケットだん\nかんぶのラムダだ!\p"
	.string "{JPN}おまえはどうせ\nかいでんぱはっせいそうちの\l"
	.string "{JPN}へやにしのびこむつもりだろう?\p"
	.string "{JPN}だがそうはいかないぜ!\p"
	.string "{JPN}なぜならあのへやは\nとくべつなキーワードで\lロックされているからな!\p"
	.string "{JPN}そのキーワードとは\nサカキさまばんざい!\p"
	.string "{JPN}ふふふあっさりバラしたので\nおどろいただろう?\p"
	.string "{JPN}だがキーワードなんかしられても\nぜんぜんへいきなのさ\p"
	.string "{JPN}なぜならあのドアはおれのこえで\nキーワードをいわないと\l"
	.string "{JPN}あかないようになってるからな!\p$"

RocketHideout_B3F_Text_PetrelBeaten:
    .string "{JPN}わたしは... なにも\n"
	.string "{JPN}できませんでした...\nジョバンニさま どうか\nおゆるしを...$"
RocketHideout_B3F_Text_PetrelAfterBattle:
	.string "{JPN}ラムダ: サカキさまは3ねんまえ\nロケットだんをかいさんさせて\l"
	.string "{JPN}すがたをけした...\p"
	.string "{JPN}だがきっとどこかでふっかつの\nチャンスをねらっているはず...\p"
	.string "{JPN}ふははは!\p"
	.string "{JPN}おまえなんかにまけたって\nいたくもかゆくもねーぞ!\p"
	.string "{JPN}なにしろおれのこえでなけりゃ\nかいでんぱはっせいそうちの\l"
	.string "{JPN}へやのドアはあけられないからな!\p$"

RocketHideout_B3F_EventScript_Murkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RocketHideout_B3F_Text_MurkrowSpeak1:
	.string "{JPN}ヤミカラス: サカキサマバンザイ!\p$"

RocketHideout_B3F_Text_MurkrowMimic:
	.string "{JPN}ヤミカラスがラムダのこえを\nそっくりにまねしている!\p"
	.string "{JPN}これはひょっとして...!?\p$"

RocketHideout_B3F_Text_Murkrow:
    .string "{JPN}ヤミカラス: あいことばは...\p"
	.string "{JPN}ハイル ジョバンニ.$"

RocketHideout_B3F_Text_GruntF5Seen:
    .string "{JPN}あいことばを しってるかって?\p"
	.string "{JPN}たぶんね.\p"
    .string "{JPN}でも よわっちいやつには\n"
	.string "{JPN}おしえてやらない!$"

RocketHideout_B3F_Text_GruntF5Beaten:
    .string "{JPN}わかった.やめる.おしえてやる.$"

RocketHideout_B3F_Text_GruntF5After:
    .string "{JPN}ボスのへやの あいことばは\n"
	.string "{JPN}ヤドンのしっぽ.\p"
    .string "{JPN}でも 2つのあいことばが\n"
	.string "{JPN}ないと いみないよ.$"

RocketHideout_B3F_Text_GruntM28Seen:
    .string "{JPN}ヒャックヒャックヒャック!\p"
	.string "{JPN}いどのときの やつだな!\p"
    .string "{JPN}また わたしに ちょうせん\n"
	.string "{JPN}するのか?\p"
    .string "{JPN}ハッ! きちがいじゃが\n"
	.string "{JPN}どきょうは ある!\p"
    .string "{JPN}けいこくしてやる.おれは\n"
	.string "{JPN}つよくなったぞ!\p"
    .string "{JPN}かてるなら ボスのへやの\nあいことばを おしえてやる!$"

RocketHideout_B3F_Text_GruntM28Beaten:
    .string "{JPN}ヒャックヒャックヒャック!\nつよいじゃないか!$"

RocketHideout_B3F_Text_GruntM28After:
    .string "{JPN}ひゃくひゃくひゃく!\p"
	.string "{JPN}ボスのへやの あいことば...\n"
	.string "{JPN}ええーっと ラッタの しっぽ\nだったと おもうぜ.$"
RocketHideout_B3F_Text_ScientistRossSeen:
    .string "{JPN}まえは シルフで はたらいてたが\n"
	.string "{JPN}いまは ロケットだんの けんきゅう\l"
    .string "{JPN}をやってる.\n"
	.string "{JPN}おせっかいな がきは\nこらしめてやる.$"

RocketHideout_B3F_Text_ScientistRossBeaten:
    .string "{JPN}たんじゅんな せんじゅつミスが\nはいぼくを まねいた...$"
RocketHideout_B3F_Text_ScientistRossAfter:
    .string "{JPN}ポケモンを きょうかさせる\n"
	.string "{JPN}でんぱしんごう...\p"
	.string "{JPN}じっけんは だいせいこうだ.\p"
	.string "{JPN}しょうしんは かくじつ.\n"
    .string "{JPN}このはいぼくなど\n"
	.string "{JPN}なんでもない.$"

RocketHideout_B3F_Text_ScientistMitchSeen:
    .string "{JPN}われわれの じっけんで ポケモンが\n"
	.string "{JPN}きずついても きにしない.$"

RocketHideout_B3F_Text_ScientistMitchBeaten:
    .string "{JPN}かんがえることは とくいだが\n"
	.string "{JPN}たたかいは にがてだ.$"

RocketHideout_B3F_Text_ScientistMitchAfter:
    .string "{JPN}でんぱしんごうの しゅつりょくを\n"
	.string "{JPN}あげて ぜんこくに\n"
    .string "{JPN}ほうそうすれば...\p"
	.string "{JPN}かんがえるだけで\nわくわくするな!$"
