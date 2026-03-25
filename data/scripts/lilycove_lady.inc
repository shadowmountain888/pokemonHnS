.set LOCALID_LILYCOVE_LADY, 4
.set LOCALID_LADYS_MON, 5

LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady::
	special Script_GetLilycoveLadyId
	switch VAR_RESULT
	case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
	case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
	case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFavorLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem::
	special BufferFavorLadyItemName
	special BufferFavorLadyPlayerName
	specialvar VAR_RESULT, DidFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_FavorLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem::
	specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem::
	specialvar VAR_RESULT, IsFavorLadyThresholdMet
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize::
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, FavorLadyGetPrize
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize::
	special SetFavorLadyState_Complete
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetQuizLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz::
	specialvar VAR_RESULT, GetQuizAuthor
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_LADY, LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz::
	specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz::
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz::
	special ClearQuizLadyPlayerAnswer
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
	goto_if_eq VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER, LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState::
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion::
	special QuizLadyShowQuizQuestion
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer::
	special QuizLadyGetPlayerAnswer
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse::
	special SetQuizLadyState_Complete
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsQuizAnswerCorrect
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse::
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse::
	special BufferQuizCorrectAnswer
	special BufferQuizPrizeName
	playse SE_FAILURE
	delay 10
	playse SE_FAILURE
	msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
	msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize::
	specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize::
	setvar VAR_0x8005, 0
	special BufferQuizPrizeItem
	special SetQuizLadyState_Complete
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
	special SetQuizLadyState_GivePrize
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz::
	special QuizLadyPickNewQuestion
	msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_QuizLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
	special ClearQuizLadyQuestionAndAnswer
	special ClearQuizLadyPlayerAnswer
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion::
	fadescreen FADE_TO_BLACK
	special QuizLadySetCustomQuestion
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
	end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz::
	special QuizLadyTakePrizeForCustomQuiz
	special QuizLadyRecordCustomQuizData
	special QuizLadySetWaitingForChallenger
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
	msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseForContestLady
	waitstate
	goto_if_eq VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
	goto_if_ne VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
	special SetContestLadyGivenPokeblock
	special GetContestLadyMonSpecies
	goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
	waitmovement 0
	delay 60
	applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	delay 120
	waitmoncry
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock::
	applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
	waitmovement 0
	delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
	waitmovement 0
	delay 60
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon:
	face_right
	delay_8
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady:
	face_left
	delay_8
	step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown:
	face_down
	step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer:
	face_player
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon::
	specialvar VAR_RESULT, GetContestLadyCategory
	special Script_BufferContestLadyCategoryAndMonName
	special GetContestLadyMonSpecies
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_COOL, LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_BEAUTY, LilycoveCity_PokemonCenter_1F_EventScript_Skitty
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_CUTE, LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_SMART, LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_TOUGH, LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
	end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady:
	.string "{JPN}わたし　おねだり　おねえさん......$"

LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing:
	.string "{JPN}わたし　さいきん\n"
	.string "{JPN}{STR_VAR_1}した　ものに　むちゅうなの......$"

LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime:
	.string "{JPN}あら......\n"
	.string "{JPN}このまえは　どうも......$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing:
	.string "{JPN}まえにね......\n"
	.string "{JPN}{STR_VAR_3}さん　だった　かしら......\p"
	.string "{JPN}{STR_VAR_1}　だからって\n"
	.string "{JPN}{STR_VAR_2}を　くれたのよ\p"
	.string "{JPN}だけど　ちっとも\n"
	.string "{JPN}{STR_VAR_1}じゃ　なかったのよ!$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing:
	.string "{JPN}まえにね　{STR_VAR_3}さんが\n"
	.string "{JPN}とても　{STR_VAR_1}な　{STR_VAR_2}を\l"
	.string "{JPN}わたしに　くれたの\p"
	.string "{JPN}すごく　たいせつに　してるのよ$"

LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing:
	.string "{JPN}ねえ......　もし　よかったら\n"
	.string "{JPN}あなたの　もってる　{STR_VAR_1}な　もの\l"
	.string "{JPN}わたしに　わけて　くれない　かしら?$"

LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe:
	.string "{JPN}......ほんと?　なにを　いただけるの?$"

LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye:
	.string "{JPN}あっ　そう......\n"
	.string "{JPN}じゃあ　さよならね......$"

LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare:
	.string "{JPN}あら......　いただけないの?$"

LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt:
	.string "{JPN}えっ......\n"
	.string "{JPN}{STR_VAR_2}って　{STR_VAR_1}?\p"
	.string "{JPN}......へえぇ　そうなの　かしらねぇ......\p"
	.string "{JPN}とりあえず　ありがとう......\n"
	.string "{JPN}きっと　たいせつに　するわね......$"

LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis:
	.string "{JPN}まぁ......\p"
	.string "{JPN}なかなか　{STR_VAR_1}な　{STR_VAR_2}ね\n"
	.string "{JPN}すてき　じゃない......　うっとり　するわ......\p"
	.string "{JPN}ありがとう......\n"
	.string "{JPN}たいせつに　するわね......$"

LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis:
	.string "{JPN}......す　す　すっ\p"
	.string "{JPN}すっごーいっ!\n"
	.string "{JPN}なんて　{STR_VAR_1}!　{STR_VAR_1}なのっ!\p"
	.string "{JPN}ここまで　{STR_VAR_1}な　{STR_VAR_2}が\n"
	.string "{JPN}よのなかに　あるなんて!\p"
	.string "{JPN}ありがとう!\p"
	.string "{JPN}いっしょう　わたしの\n"
	.string "{JPN}たからものに　するわ!$"

LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn:
	.string "{JPN}すてきな　ものを　くれた　おれいに\n"
	.string "{JPN}とっておきの　プレゼントを　あ·げ·る!\l"
	.string "{JPN}だいじにして　ちょうだいね......$"

LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt:
	.string "{JPN}あら　もちきれない　じゃないの......\p"
	.string "{JPN}どうぐを　せいり　してから\n"
	.string "{JPN}また　いらっしゃい......$"

LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady:
	.string "{JPN}あたし　クイズ　おねえさん!\n"
	.string "{JPN}クイズ　だーいすき!$"

LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz:
	.string "{JPN}あれっ?\p"
	.string "{JPN}いまは　あなたの　かんがえた　クイズに\n"
	.string "{JPN}チャレンジする　ひとを　さがしてるの!\l"
	.string "{JPN}だから　また　こんどね!$"

LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger:
	.string "{JPN}いま　{STR_VAR_1}さんの　かんがえた　クイズに\n"
	.string "{JPN}こたえて　くれる　ひとを　さがしてるの!$"

LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge:
	.string "{JPN}せいかい　したら\n"
	.string "{JPN}しょうひんも　あるよー!\l"
	.string "{JPN}あなた　チャレンジ　して　みない?$"

LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer:
	.string "{JPN}......　......　......　......\n"
	.string "......　......　......　......$"

LilycoveCity_PokemonCenter_1F_Text_HowBoringBye:
	.string "{JPN}つまんないの!　バイバイ!$"

LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit:
	.string "{JPN}えっー!　あきらめちゃうの?$"

LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime:
	.string "{JPN}また　チャレンジ　してねー!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRight:
	.string "{JPN}すっごい!　せいかい!\n"
	.string "{JPN}きゃー!　あなたって　センス　あるねー!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize:
	.string "{JPN}クイズ　せいかい　おめでとー!\n"
	.string "{JPN}{STR_VAR_1}さん　からの\l"
	.string "{JPN}ごほうびが　ありまーす!$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY:
	.string "{JPN}{STR_VAR_1}は\n"
	.string "{JPN}{STR_VAR_2}を　もらった!$"

LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp:
	.string "{JPN}あれー?　どうぐが　いっぱい　みたいだよ!\n"
	.string "{JPN}バッグを　せいり　してから　また　きてね!$"

LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs:
	.string "{JPN}うーん......　は·ず·れ!\n"
	.string "せいかいは　{STR_VAR_3}でした!$"

LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize:
	.string "{JPN}ざんねん　でしたー!\p"
	.string "{JPN}クイズ　せいかいの　しょうひんの\n"
	.string "{JPN}{STR_VAR_1}は\l"
	.string "{JPN}おねえさんが　もらっちゃいまーす!$"

LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz:
	.string "{JPN}ねえ!　ねえ!　あなたも\n"
	.string "{JPN}クイズ　つくって　みない?$"

LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime:
	.string "{JPN}そっか......\n"
	.string "{JPN}じゃあー　また　こんどね!$"

LilycoveCity_PokemonCenter_1F_Text_PickYourPrize:
	.string "{JPN}じゃあー　まず\n"
	.string "{JPN}クイズに　せいかいした　ひとに\l"
	.string "{JPN}あげる　しょうひんを　きめてね!\p"
	.string "{JPN}ただし　クイズに　チャレンジした　ひとが\n"
	.string "{JPN}こたえを　はずしちゃった　ときは\l"
	.string "{JPN}おねえさんが　しょうひん　もらっちゃうよ!\l"
	.string "{JPN}ちゅうい　してね!$"

LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize:
	.string "{JPN}しょうひんを　きめないと\n"
	.string "{JPN}クイズは　できないよ!\l"
	.string "{JPN}つくるの　やめちゃうの?$"

LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz:
	.string "{JPN}すてきな　しょうひんだね!\p"
	.string "{JPN}じゃあ　つぎに　クイズの\n"
	.string "{JPN}もんだいと　こたえを　かんがえてね!$"

LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion:
	.string "{JPN}クイズの　もんだい　つくるの　やめる?$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer:
	.string "{JPN}クイズの　こたえ　きめるの　やめる?$"

LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger:
	.string "{JPN}おつかれさまー!\p"
	.string "{JPN}すてきな　クイズが　できたね!\p"
	.string "{JPN}さっそく　チャレンジ　してくれる　ひとを\n"
	.string "{JPN}さがしに　いって　くるね!$"

LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady:
	.string "{JPN}あたし　コンテスト　おねえさん!\n"
	.string "{JPN}コンテスト　だいすきー!$"

LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock:
	.string "{JPN}このまえは　ポロック　ありがとー!$"

LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality:
	.string "{JPN}こっちは　おともだちの　{STR_VAR_1}だよ!\n"
	.string "{JPN}とーっても　{STR_VAR_2}い　のよ!\p"
	.string "{JPN}でもねー　もっと　もっと\n"
	.string "{JPN}{STR_VAR_2}く　なると　おもうんだー!$"

LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase:
	.string "{JPN}だから　おねがいー!\p"
	.string "{JPN}あなたの　ポロックー　ひとつで　いいから\n"
	.string "{JPN}あたしたちに　ちょうだい!\p"
	.string "{JPN}......　って　あれー?\n"
	.string "{JPN}あなた　ポロックケース　もってないじゃん?\l"
	.string "{JPN}しかたないなー　じゃあ　また　こんどねー!$"

LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock:
	.string "{JPN}だから　おねがい!\p"
	.string "{JPN}あなたの　ポロック　ひとつで　いいから\n"
	.string "{JPN}あたしたちに　ちょうだい!$"

LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock:
	.string "{JPN}えー!　ポロック　くれないの?$"

LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate:
	.string "{JPN}ちぇっ!　けちー!$"

LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock:
	.string "{JPN}わーい!　やったー!\p"
	.string "{JPN}さっそく　たべさせて　みよーっと!$"

LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks:
	.string "{JPN}......なんか　ぜんぜん\n"
	.string "{JPN}かわってない　ような......\p"
	.string "{JPN}うーん......\p"
	.string "{JPN}まあ　いっか!\n"
	.string "{JPN}どうも　ありがとー$"

LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks:
	.string "{JPN}わーっ!　すっごく　よろこんでるよー!\p"
	.string "{JPN}それに　{STR_VAR_1}の　{STR_VAR_2}さに\n"
	.string "{JPN}みがきが　かかった　みたい!\l"
	.string "{JPN}どうも　ありがとー!$"

LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests:
	.string "{JPN}うーん......\p"
	.string "{JPN}そろそろ　コンテストに\n"
	.string "{JPN}さんかして　みようかなー?\p"
	.string "{JPN}もしも　どこかで　あたし　たちを\n"
	.string "{JPN}みかけたら　ぜったい　おうえん　してねー!$"

LilycoveCity_PokemonCenter_1F_Text_Zigzagoon:
	.string "{JPN}{STR_VAR_1}: ぐうぐぅ!$"

LilycoveCity_PokemonCenter_1F_Text_Kecleon:
	.string "{JPN}{STR_VAR_1}: いぎぎぎぃ!!$"

LilycoveCity_PokemonCenter_1F_Text_Poochyena:
	.string "{JPN}{STR_VAR_1}: バアーゥン　......$"

LilycoveCity_PokemonCenter_1F_Text_Pikachu:
	.string "{JPN}{STR_VAR_1}: ぴっか!$"

LilycoveCity_PokemonCenter_1F_Text_Skitty:
	.string "{JPN}{STR_VAR_1}: うみゅぁぁぁん!!$"
