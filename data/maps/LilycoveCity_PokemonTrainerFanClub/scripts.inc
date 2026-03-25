.set LOCALID_LASS, 1
.set LOCALID_MAN, 2
.set LOCALID_POKEFAN_M, 3
.set LOCALID_LITTLE_GIRL, 4
.set LOCALID_NINJA_BOY, 5
.set LOCALID_BOY, 6
.set LOCALID_WOMAN, 7
.set LOCALID_EXPERT_F, 8

LilycoveCity_PokemonTrainerFanClub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
	.byte 0

	@ See field_specials.c for a breakdown of the Fan Club and its variables

LilycoveCity_PokemonTrainerFanClub_OnFrame:
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer
	applymovement LOCALID_MAN, LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer
	waitmovement 0
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
	releaseall
	end

LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer:
	delay_8
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer:
	jump_in_place_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_faster_down
	step_end

LilycoveCity_PokemonTrainerFanClub_OnTransition:
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 2, LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special TryLoseFansFromPlayTime
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer::
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer::
	setflag FLAG_GARBAGEFLAG
	return

@ Set up the fan club TV show, if the player has at least 5 fans in the club
@ Rather than counting up, 1 is subtracted from the total for each member not a fan of the players
LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow::
	setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	goto_if_ge VAR_0x8005, 5, LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan::
	subvar VAR_0x8005, 1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow::
	special TryPutTrainerFanClubOnAir
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_LASS, 7, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_POKEFAN_M, 3, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_LITTLE_GIRL, 7, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_NINJA_BOY, 5, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_BOY, 5, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_MAN, 8, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_WOMAN, 3, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_EXPERT_F, 8, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting::
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Man::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Lass::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Boy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer::
	lock
	faceplayer
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
	end

@ The interviewer doesnt count as an individual fan club member
@ Instead they always ask about whoever the Lass would be interested in, if not the player
LilycoveCity_PokemonTrainerFanClub_EventScript_Interview::
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
	special InterviewBefore
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
	copyvar VAR_0x800A, VAR_0x8006
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	message LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_0x8004, FANCLUB_MEMBER1
	switch VAR_RESULT
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	copyvar VAR_0x8006, VAR_0x800A
	copyvar VAR_0x8005, VAR_RESULT
	special PutFanClubSpecialOnTheAir
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
	release
	end

@ Shouldnt be reached
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2::
	end

LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer:
	.string "{JPN}おお! すごい!\n"
	.string "{JPN}{PLAYER}じゃないか!$"

LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan:
	.string "{JPN}うわさを きいたよ!\n"
	.string "{JPN}きみって つよいんだってね?\p"
	.string "{JPN}ここでは いつも だれが いちばん\n"
	.string "{JPN}つよい トレーナーか ろんそうしてるんだ\p"
	.string "{JPN}それで きみの うわさを きいて\n"
	.string "{JPN}ぼくは きみの ファンになったよ!\p"
	.string "{JPN}これからも つよい トレーナーと\n"
	.string "{JPN}たたかい つづけてくれよな\p"
	.string "{JPN}そうすれば きみの あつい バトルを\n"
	.string "{JPN}もっと みることが できるからね\p"
	.string "{JPN}そうすれば ほかの ひとたちも\n"
	.string "{JPN}きみの すごさが わかるはずだ\n"
	.string "{JPN}おぼえておいてくれ {PLAYER}!\n"
	.string "{JPN}ぼくは きみを おうえんしてるぞ!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin:
	.string "{JPN}よう {PLAYER}!\n"
	.string "{JPN}きみこそ かってほしい やつだ!$"

LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest:
	.string "{JPN}ほかの やつらは きみが\n"
	.string "{JPN}さいきょうだって しらないんだ!\p"
	.string "{JPN}そうだろう {PLAYER}?\n"
	.string "{JPN}こんじょうを みせつけてやれ!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary:
	.string "{JPN}いいたくないけど みんなが\n"
	.string "{JPN}はなしてる トレーナーって\l"
	.string "{JPN}{STR_VAR_1} まちがいないよね!\p"
	.string "{JPN}あの トレーナーの ちから...\n"
	.string "{JPN}ふつうじゃ ないよ$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen:
	.string "{JPN}Darn it... I've been telling people\n"
	.string "{JPN}that {STR_VAR_1} is the best now...\p"
	.string "{JPN}But no one wants to listen...$"
LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer:
	.string "{JPN}つよい あたらしい トレーナーの\n"
	.string "{JPN}うわさを きいてるんだ\p"
	.string "{JPN}そのトレーナーは ジムリーダーまで\n"
	.string "{JPN}たおしてるって はなしだよ\p"
	.string "{JPN}その あたらしい トレーナーに\n"
	.string "{JPN}ついて なにか しってるかい?$"

LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou:
	.string "{JPN}おお!\n"
	.string "{JPN}{PLAYER}!\p"
	.string "{JPN}がんばれ!\n"
	.string "{JPN}きみを おうえんしてるぞ!$"

LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan:
	.string "{JPN}はあ...\n"
	.string "{JPN}トウキ...\p"
	.string "{JPN}あっ いや! ちがう!\n"
	.string "{JPN}そうじゃない! ちがうんだ!\p"
	.string "{JPN}おれは きみの ファンだ!\p"
	.string "{JPN}だから がんばって!\n"
	.string "{JPN}やるんだ!$"

LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly:
	.string "{JPN}しかたないよ おれは トウキ\n"
	.string "{JPN}しか すきになれない...$"
LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly:
	.string "{JPN}だれも トウキの みりょくを\n"
	.string "{JPN}わかってくれない...\p"
	.string "{JPN}もう いいよ!\p"
	.string "{JPN}おれ ひとりでも トウキを\n"
	.string "{JPN}おうえんし つづけるから!$"

LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly:
	.string "{JPN}なんと いわれても ぼくの\n"
	.string "{JPN}だいすきな トレーナーは\l"
	.string "{JPN}ムロじまの ジムリーダー トウキだ!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather:
	.string "{JPN}きみは おとうさんを\n"
	.string "{JPN}すべてのめんで こえたんだ!\p"
	.string "{JPN}ぼくが いうんだから\n"
	.string "{JPN}まちがいないよ!$"

LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling:
	.string "{JPN}じょうきょうが わるくなっても\n"
	.string "{JPN}きみの おとうさんは あきらめなかった\p"
	.string "{JPN}これは ほんとうの ことだ\p"
	.string "{JPN}まけても あきらめるな!\n"
	.string "{JPN}たたかい つづけるんだ!$"

LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman:
	.string "{JPN}センリは もっと つよくて\n"
	.string "{JPN}かりすまもあって しょーまんしっぷ\l"
	.string "{JPN}もあったんだよ\p"
	.string "{JPN}みんなが きみは つよいって\n"
	.string "{JPN}いっても...\p"
	.string "{JPN}とうさんと くらべたら まだまだ\nみちのりは ながいね$"

LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent:
	.string "{JPN}きみは センリと おなじような\n"
	.string "{JPN}いふうを かもしだしはじめてる\p"
	.string "{JPN}でも きみと センリの あいだには\n"
	.string "{JPN}けっていてきな ちがいが ある\p"
	.string "{JPN}それが なにかは いえない\n"
	.string "{JPN}きみじしんで みつけるしかないんだ$"

LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers:
	.string "{JPN}ここにいる みんな ポケモンバトルの\n"
	.string "{JPN}おおファンなんだ\p"
	.string "{JPN}だれが いちばん つよい トレーナーか\n"
	.string "{JPN}ぎろんしてるんだよ\p"
	.string "{JPN}きみが ゆうめいになったら\n"
	.string "{JPN}きみの ファンになるかもしれないね!$"

LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer:
	.string "{JPN}わあああ! {PLAYER}だ!\n"
	.string "{JPN}ほんものだ!\p"
	.string "{JPN}おねがい あくしゅして あくしゅ!$"

LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou:
	.string "{JPN}ぼくは いつでも {PLAYER}を\n"
	.string "{JPN}おうえんするよ! いつでも!\n"
	.string "{JPN}{PLAYER}が まけるのは\n"
	.string "{JPN}みたくないんだ\n"
	.string "{JPN}だって {PLAYER}は ほんとうに\n"
	.string "{JPN}ほんとうに つよいって しってるから!$"

LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool:
	.string "{JPN}{STR_VAR_1}って ほんとうに\n"
	.string "{JPN}かっこいいよね...\pみんなも そう おもうよね!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe:
	.string "{JPN}{STR_VAR_1}は ほんとうに\n"
	.string "{JPN}かっこいいと おもわない?\p"
	.string "{JPN}ひとりでも ぼくは だいすきな\n"
	.string "{JPN}トレーナーを おうえんし つづけるよ$"

LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat:
	.string "{JPN}わたしの すきな トレーナーは...\p"
	.string "{JPN}かっこよくて...\p"
	.string "{JPN}つよくて...\p"
	.string "{JPN}とても やさしい...\p"
	.string "{JPN}そんな トレーナーが いたらな...$"
LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou:
	.string "{JPN}うわあ! {PLAYER}だ!\n"
	.string "{JPN}すげー!\n"
	.string "{JPN}おおきくなったら {PLAYER}みたいに\n"
	.string "{JPN}つよくなりたいな!$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou:
	.string "{JPN}たとえ わたし ひとりでも...\n"
	.string "{JPN}いつでも {PLAYER}だけを\l"
	.string "{JPN}おうえん するからね!\p"
	.string "{JPN}{PLAYER}を しんじてるから!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool:
	.string "{JPN}{STR_VAR_1}って すっごく\n"
	.string "{JPN}かっこいい...\nあこがれの ひとと あくしゅ\lしたいな$"

LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan:
	.string "{JPN}たとえ わたし ひとりでも...\p"
	.string "{JPN}{STR_VAR_1}の ファンを\n"
	.string "{JPN}やめない!\p"
	.string "{JPN}{STR_VAR_1}は\n"
	.string "{JPN}まけたこと ないって きいたから!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll:
	.string "{JPN}{PLAYER}!\n"
	.string "{JPN}きみは やっぱり すごいや!\n"
	.string "{JPN}はじめて きみを みたときから\n"
	.string "{JPN}きみは すごいと おもってたんだ\n"
	.string "{JPN}ぼくの めに くるいは なかったよ$"

LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner:
	.string "{JPN}ほかの やつらなんて どうでもいい\n"
	.string "{JPN}ぼくは きみの みかただ!\n"
	.string "{JPN}しんぱいしないで いつものように\n"
	.string "{JPN}バトルすれば いいんだよ$"

LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne:
	.string "{JPN}きみも けっこう いい トレーナーだと\n"
	.string "{JPN}おもうよ\p"
	.string "{JPN}でも いまは {STR_VAR_1}が\n"
	.string "{JPN}ナンバーワンだと おもうんだ\n"
	.string "{JPN}これは ぼくの いけんだから\n"
	.string "{JPN}あまり きに しないでくれ$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer:
	.string "{JPN}わあ きみは ほんとうに つよいね\n"
	.string "{JPN}{STR_VAR_1}より つよいかも\p"
	.string "{JPN}でも {STR_VAR_1}には ぼくが\n"
	.string "{JPN}hituyouなんだ\p"
	.string "{JPN}ぼくが {STR_VAR_1}を おうえん\nしなかったら だれがするの?$"

LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind:
	.string "{JPN}きみのおかげで きが かわったよ!\n"
	.string "{JPN}きみは つよいんだね?\n"
	.string "{JPN}どうやって そんなに つよく\n"
	.string "{JPN}なったのか おしえてくれる?$"

LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation:
	.string "{JPN}きびしい じょうきょうほど\n"
	.string "{JPN}きみは みりょくてきに たたかう\n"
	.string "{JPN}つぎの バトルが たのしみだ!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout:
	.string "{JPN}さいきん はなしだいの トレーナーの\n"
	.string "{JPN}なかで {STR_VAR_1}が だんとつだ\n"
	.string "{JPN}その つよさは ふつうじゃない\n"
	.string "{JPN}きみも いいせんいってるけど\n"
	.string "{JPN}{STR_VAR_1}とは かくが ちがうね$"

LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger:
	.string "{JPN}きみって ほんとうに にんき\n"
	.string "{JPN}あるんだね...\p"
	.string "{JPN}つよいし ポケモンにも やさしい\n"
	.string "{JPN}だれも きみを ばかには できない\p"
	.string "{JPN}でも わたしは {STR_VAR_1}を\n"
	.string "{JPN}しんじてるの\p{STR_VAR_1}の ほうが ぜったい\nつよい! まちがいない!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive:
	.string "{JPN}きみって...\p"
	.string "{JPN}すごいね!$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth:
	.string "{JPN}きみの ほんとうの かちは ぼくだけが\n"
	.string "{JPN}みとめれば じゅうぶんだ\n"
	.string "{JPN}ほかの やつらには きみのなかに\n"
	.string "{JPN}ひめられた ちからは わからないだろう$"

LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential:
	.string "{JPN}そう きみの めには つよさが\n"
	.string "{JPN}みえる\p"
	.string "{JPN}しかし!\p"
	.string "{JPN}きみは まだ じぶんの\nかのうせいに きづいていない$"

LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength:
	.string "{JPN}たしかに きみは とてつもなく\n"
	.string "{JPN}つよい\p"
	.string "{JPN}でも!\n"
	.string "{JPN}わたしには わかるの...\p"
	.string "{JPN}その つよさは まだ ほんとうの\n"
	.string "{JPN}つよさじゃ ないって!\p"
	.string "{JPN}ほんとうの つよさは...!\n"
	.string "{JPN}... ...\p"
	.string "{JPN}じつは わたしも よく\nわからない$"
