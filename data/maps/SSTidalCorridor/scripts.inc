.set LOCALID_SAILOR, 1
.set LOCALID_SCOTT, 5

SSTidalCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_OnFrame
	.byte 0

SSTidalCorridor_OnFrame:
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_ScottScene
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT, SSTidalCorridor_EventScript_DepartSlateportForLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE, SSTidalCorridor_EventScript_DepartLilycoveForSlateport
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_RIGHT, SSTidalCorridor_EventScript_HalfwayToLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_LEFT, SSTidalCorridor_EventScript_ArrivedInSlateport
	.2byte 0

SSTidalCorridor_EventScript_DepartSlateportForLilycove::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_DepartLilycoveForSlateport::
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_HalfwayToSlateport::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ArrivedInLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInLilycove, MSGBOX_DEFAULT
	return

SSTidalCorridor_EventScript_ReachedStepCount::
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_HalfwayToLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_ArrivedInSlateport
	end

SSTidalCorridor_EventScript_HalfwayToLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ProgessCruiseAfterBed::
	switch VAR_SS_TIDAL_STATE
	case SS_TIDAL_DEPART_SLATEPORT, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_HALFWAY_LILYCOVE, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_DEPART_LILYCOVE, SSTidalRooms_EventScript_HalfwayToSlateport
	case SS_TIDAL_HALFWAY_SLATEPORT, SSTidalRooms_EventScript_ArrivedInSlateport
	return

SSTidalCorridor_EventScript_Briney::
	msgbox SSTidalCorridor_Text_BrineyWelcomeAboard, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox SSTidalCorridor_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_Cabin1Sign::
	msgbox SSTidalCorridor_Text_Cabin1, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin2Sign::
	msgbox SSTidalCorridor_Text_Cabin2, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin3Sign::
	msgbox SSTidalCorridor_Text_Cabin3, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin4Sign::
	msgbox SSTidalCorridor_Text_Cabin4, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_ExitSailor::
	lock
	faceplayer
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE, SSTidalCorridor_EventScript_ExitLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT, SSTidalCorridor_EventScript_ExitSlateport
	msgbox SSTidalCorridor_Text_CanRestInCabin2, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_ExitLilycove::
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_ExitSlateport::
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_HideSnatchGiver::
	setflag FLAG_GARBAGEFLAG
	return

SSTidalCorridor_EventScript_Porthole::
	lockall
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	msgbox SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_LookThroughPorthole::
	special LookThroughPorthole
	waitstate
	end

SSTidalCorridor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_EnjoyYourCruise
	call SSTidalCorridor_EventScript_CheckIfTrainersDefeated
	msgbox SSTidalCorridor_Text_VisitOtherCabins, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_EnjoyYourCruise::
	msgbox SSTidalCorridor_Text_EnjoyYourCruise, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_CheckIfTrainersDefeated::
	goto_if_not_defeated TRAINER_PHILLIP, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEONARD, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_GRUNT_26, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_MICAH, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_THOMAS, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEA_AND_JED, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_GARRET, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_NAOMI, SSTidalCorridor_EventScript_TrainerNotDefeated
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
	goto SSTidalCorridor_EventScript_EnjoyYourCruise
	return

SSTidalCorridor_EventScript_TrainerNotDefeated::
	return

SSTidalCorridor_EventScript_ScottScene::
	lockall
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SSTidalCorridor_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SSTidalCorridor_Movement_PlayerWatchScottExit
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorMoveForScott
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottExit
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_SCOTT
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorReturn
	waitmovement 0
	delay 30
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
	releaseall
	end

SSTidalCorridor_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSTidalCorridor_Movement_ScottExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SSTidalCorridor_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

SSTidalCorridor_Movement_SailorMoveForScott:
	delay_16
	walk_right
	walk_right
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_left
	step_end

SSTidalCorridor_Movement_SailorReturn:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

SSTidalCorridor_Text_ScottBattleFrontierInvite:
	.string "{JPN}エニシダ: やあやあ!\n"
	.string "{JPN}{PLAYER}くん {PLAYER}くん!\p"
	.string "{JPN}ちょっと ようじが あって\n"
	.string "{JPN}おりなきゃ いけないんだが\l"
	.string "{JPN}あえて うれしいよ!\p"
	.string "{JPN}おめでとう リーグチャンピオン!\p"
	.string "{JPN}きみのような ひとを\n"
	.string "{JPN}しょうたい したい ばしょが\l"
	.string "{JPN}あるんだ.\p"
	.string "{JPN}それは...\n"
	.string "{JPN}バトルフロンティア!\p"
	.string "{JPN}どんな ばしょかって?\n"
	.string "{JPN}みれば わかるよ!\p"
	.string "{JPN}せんちょうには\n"
	.string "{JPN}はなしを つけてある.\p"
	.string "{JPN}こんどの フェリーで\n"
	.string "{JPN}バトルフロンティアに\l"
	.string "{JPN}iけるはずだ.\pじゃあ {PLAYER}くん \nバトルフロンティアで\lまってるからな!$"

SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage:
	.string "{JPN}このふねは はやいながれを\n"
	.string "{JPN}つきすすむように つくられています.\p"
	.string "{JPN}わたしたちとの ふなたびを\n"
	.string "{JPN}たのしんでください.\lふねのなかを じゆうに\nたんけんしてくださいね.$"

SSTidal_Text_HopeYouEnjoyVoyage:
	.string "{JPN}わたしたちのふねでの たびを\n"
	.string "{JPN}たのしんでください.$"

SSTidal_Text_MadeLandInSlateport:
	.string "{JPN}カイナシティに とうちゃくしました.\n"
	.string "{JPN}ごじょうせん ありがとうございました.$"

SSTidal_Text_MadeLandInLilycove:
	.string "{JPN}ミナモシティに とうちゃくしました.\n"
	.string "{JPN}ごじょうせん ありがとうございました.$"

SSTidalCorridor_Text_CanRestInCabin2:
	.string "{JPN}りくちに つくまで まだまだ\n"
	.string "{JPN}じかんが かかりそうですね.\p"
	.string "{JPN}もしよろしければ きゃくしつで\n"
	.string "{JPN}おやすみください.あなたのきゃくしつは\l"
	.string "{JPN}2ごうしつです.\p"
	.string "{JPN}そこのベッドは やわらかくて\nふかふかですよ.\lわたしが ほしょうします!$"

SSTidalCorridor_Text_WeveArrived:
	.string "{JPN}とうちゃくしました!$"

SSTidalCorridor_Text_VisitOtherCabins:
	.string "{JPN}ほかのきゃくしつも のぞいて\n"
	.string "{JPN}みてください.\l"
	.string "{JPN}ふなたびに あきた トレーナーたちが\nバトルを もとめていますよ.$"

SSTidalCorridor_Text_EnjoyYourCruise:
	.string "{JPN}クルーズを おたのしみください!$"

SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole:
	.string "{JPN}まるまどの むこうに\n"
	.string "{JPN}ちへいせんが ひろがっています.$"

SSTidalCorridor_Text_BrineyWelcomeAboard:
	.string "{JPN}ハギろうじん: ようこそ {PLAYER}くん!\p"
	.string "{JPN}SS.アクアごうの\n"
	.string "{JPN}めいよせんちょうに なったのじゃ!\p"
	.string "{JPN}せんちょうハギと よんでくれ!\n"
	.string "{JPN}いちど ひきたいしたが {JPN}この\l"
	.string "{JPN}りっぱな ふねを みたとき...\p"
	.string "{JPN}ふなのりの たましいが\n"
	.string "{JPN}めざめてしまったのじゃ!$"

SSTidalCorridor_Text_Peeko:
	.string "{JPN}ピーコ: ぴひょ ぴひょひょ...$"
SSTidalCorridor_Text_Cabin1:
	.string "{JPN}1ごうしつ$"

SSTidalCorridor_Text_Cabin2:
	.string "{JPN}2ごうしつ$"

SSTidalCorridor_Text_Cabin3:
	.string "{JPN}3ごうしつ$"

SSTidalCorridor_Text_Cabin4:
	.string "{JPN}4ごうしつ$"
