.set FOUND_FIRST_SWITCH, FLAG_TEMP_1
.set SWITCH1_ID,         VAR_0x8004
.set SWITCH2_ID,         VAR_0x8005
.set TRASH_CAN_ID,       VAR_0x8008

.set CHECK_VISITOR_STATE, 6
.set TYPE, VAR_0x8003
.set ARGUMENT, VAR_0x8004

VermilionCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_Return::
	end

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_EventScript_Gregory::
	trainerbattle_single TRAINER_GREGORY VermilionGym_Text_GentlemanGregorySeen, VermilionGym_Text_GentlemanGregoryBeaten
	msgbox VermilionGym_Text_GentlemanGregoryAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT VermilionGym_Text_GuitaristVincentSeen, VermilionGym_Text_GuitaristVincentBeaten
	msgbox VermilionGym_Text_GuitaristVincentAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Horton::
	trainerbattle_single TRAINER_HORTON VermilionGym_Text_JugglerHortonSeen, VermilionGym_Text_JugglerHortonBeaten
	msgbox VermilionGym_Text_JugglerHortonAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_Surge_Defeated
	msgbox VermilionGym_Text_LtSurgeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LTSURGE, VermilionGym_Text_LtSurgeWinLoss
	message VermilionGym_Text_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VermilionGym_Text_ThunderBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE11_GET
	setflag FLAG_DEFEATED_VERMILION_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers
	checkitem ITEM_TM_THUNDERBOLT
	call_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_GiveThunderstone
	call_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_GiveTM
	clearflag FLAG_HIDE_PLANT_SURGE
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GiveThunderstone::
	msgbox VermilionGym_Text_LtSurgeThunderstone, MSGBOX_DEFAULT
	giveitem ITEM_THUNDER_STONE
	return
VermilionCity_Gym_EventScript_GiveTM::
	msgbox VermilionGym_Text_LtSurgeTm, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	return

VermilionCity_Gym_EventScript_Surge_Defeated::
	msgbox VermilionGym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionGym_Text_LtSurgeIntro:
	.string "{JPN}マチス: おい ちびっこ!\p"
	.string "{JPN}たいしたもんだな.\p"
	.string "{JPN}おれに ちょうせんするなんて\n"
	.string "{JPN}あたまが わるいが\l"
	.string "{JPN}どきょうは あるぜ!\p"
	.string "{JPN}でんきタイプの ポケモンなら\n"
	.string "{JPN}おれが ナンバーワンだ!\p"
	.string "{JPN}せんじょうで いちども\n"
	.string "{JPN}まけたことは ない.\p"
	.string "{JPN}せんそうで てきを やっつけた\nように きみも やっつけて\lやる!$"

VermilionGym_Text_LtSurgeWinLoss:
	.string "{JPN}マチス: ぐあああ! つよいな!\p"
	.string "{JPN}よし ぼうず.\nオレンジバッジを やる!$"

VermilionGym_Text_ReceivedThunderBadge:
	.string "{JPN}{PLAYER}は オレンジバッジを\nもらった!$"

VermilionGym_Text_ThunderBadgeInfo:
	.string "{JPN}マチス: オレンジバッジは\n"
	.string "{JPN}ポケモンの すばやさを\l"
	.string "{JPN}あげるぜ.\p"
	.string "{JPN}おれに かったあかしだ.\p"
	.string "{JPN}ほこりを もって つけろよ!$"

VermilionGym_Text_LtSurgeTm:
	.string "{JPN}それと この わざマシンも\n"
	.string "{JPN}やる. せんそうで やくに\lたったからな!$"

VermilionGym_Text_LtSurgeThunderstone:
	.string "{JPN}それと この いしも やる.\n"
	.string "{JPN}ほんものの かみなりの ちから\nが あるぜ!$"


VermilionGym_Text_LtSurgePostBattle:
	.string "{JPN}マチス: おい ぼうず!\n"
	.string "{JPN}まだ がんばってるか?\p"
	.string "{JPN}おれと ポケモンも\nまだまだ げんえきだぜ!$"

VermilionGym_Text_SurgeRematch:
	.string "{JPN}マチス: なんと きみは\n"
	.string "{JPN}カントーチャンピオンに!\p"
	.string "{JPN}たいしたもんだ ぼうず!\n"
	.string "{JPN}でも おれは まけんぞ!\p"
	.string "{JPN}もう いっかい しょうぶ\nしないか?$"

VermilionGym_Text_SurgeRematchDefeat:
	.string "{JPN}マチス: ぐあああ! まだまだ\n"
	.string "{JPN}つよいじゃないか!$"

VermilionGym_Text_GentlemanGregorySeen:
	.string "{JPN}マチスたいちょうを たおしに\n"
	.string "{JPN}きたのか?\pそうは させん!$"

VermilionGym_Text_GentlemanGregoryBeaten:
	.string "{JPN}マチスたいちょう もうしわけ\n"
	.string "{JPN}ありません!$"

VermilionGym_Text_GentlemanGregoryAfter:
	.string "{JPN}わたしが ぐんたいに いたとき\n"
	.string "{JPN}マチスたいちょうに いのちを\lすくわれたのです.$"

VermilionGym_Text_GuitaristVincentSeen:
	.string "{JPN}マチスたいちょうが でんき\n"
	.string "{JPN}ポケモンでの わたしの のうりょく\l"
	.string "{JPN}を みとめてくれた.\pきみに かてると おもうか?$"

VermilionGym_Text_GuitaristVincentBeaten:
	.string "{JPN}うう ショックだ!$"

VermilionGym_Text_GuitaristVincentAfter:
	.string "{JPN}かあちゃんに しごとを\n"
	.string "{JPN}やめるなって いわれたけど\l"
	.string "{JPN}そっちでも うまく いって\l"
	.string "{JPN}ないんだよね.$"

VermilionGym_Text_JugglerHortonSeen:
	.string "{JPN}きみを たおしてやる!\n"
	.string "{JPN}ビリビリに してやるぜ!$"

VermilionGym_Text_JugglerHortonBeaten:
	.string "{JPN}ぐわあああ!ちからで\nまけてしまった...$"
VermilionGym_Text_JugglerHortonAfter:
	.string "{JPN}おれにかったからって\n"
	.string "{JPN}ちょうしにのるなよ...\p"
	.string "{JPN}マチスたいちょうは\nつよいぞ$"

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "{JPN}よう!\n"
	.string "{JPN}みらいの チャンピオン!\p"
    .string "{JPN}マチスには あだなが あるんだ.\p"
	.string "{JPN}でんきにんげんって よばれて\n"
    .string "{JPN}いるぜ!\p"
	.string "{JPN}でんきポケモンの エキスパート\n"
    .string "{JPN}なんだ.\p"
	.string "{JPN}ひこう みずタイプは でんき\n"
    .string "{JPN}タイプに よわいぞ.\p"
	.string "{JPN}mひまも きをつけろよ.\p"
    .string "{JPN}マチスは とても しんちょうだ.\p"
	.string "{JPN}じぶんを とじこめてるから\n"
    .string "{JPN}かんたんには あえないぜ.$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "{JPN}ふう! でんげきてきな\n"
	.string "{JPN}たたかいだったな!\p"
	.string "{JPN}こっちまで どきどき したぜ.$"

VermilionCity_Gym_Text_GymStatue::
    .string "{JPN}クチバ ポケモンジム\n"
	.string "{JPN}ジムリーダー:マチス\p"
	.string "{JPN}しょうりした トレーナー:\n"
	.string "{JPN}グリーン レッド$"


VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "{JPN}クチバ ポケモンジム\n"
	.string "{JPN}ジムリーダー:マチス\p"
    .string "{JPN}しょうりした トレーナー:\n"
	.string "{JPN}グリーン レッド {PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "{JPN}だめ!\n"
	.string "{JPN}ごみしか ないよ.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "{JPN}おや! ごみのしたに スイッチが!\n"
	.string "{JPN}おしてみよう!\p"
    .string "{JPN}だい1の でんきじょうが\nはずれた!$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "{JPN}だい2の でんきじょうが\n"
	.string "{JPN}はずれた!\nじどうドアが あいた!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "{JPN}だめ!\n"
	.string "{JPN}ごみしか ないよ.\p"
    .string "{JPN}あ!\n"
	.string "{JPN}でんきじょうが リセットされた!$"

