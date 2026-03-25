.set LOCALID_DAYCARE_LADY, 1

Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "{JPN}わしは そだてやの おじいさんだ.\p"
	.string "{JPN}トレーナーの だいじな\n"
	.string "{JPN}ポケモンを あずかっているよ.\p"
	.string "{JPN}ポケモンを あずけたければ\n"
	.string "{JPN}かみさんに はなしかけてくれ.$"

Route117_Text_DoYouWantEgg:
	.string "{JPN}おお きたか!\p"
	.string "{JPN}おまえさんの ポケモンを\n"
	.string "{JPN}あずかっていたら おどろいたぞ!\p"
	.string "{JPN}ポケモンが タマゴを もっていた!\p"
	.string "{JPN}どこから きたか わからんが\n"
	.string "{JPN}ポケモンが もっていたんだ.\p"
	.string "{JPN}もらうかね?$"

Route117_Text_YourMonIsDoingFine:
	.string "{JPN}おお きたか! げんきかね.\n"
	.string "{JPN}おまえさんの {STR_VAR_1}は げんきだよ.$"

Route117_Text_IllKeepIt:
	.string "{JPN}そうか もらっていくよ.\n"
	.string "{JPN}ありがとう!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "{JPN}てもちが いっぱいだ...\n"
	.string "{JPN}あきを つくってから きてくれ.$"

Route117_Text_ReceivedEgg:
	.string "{JPN}{PLAYER}は そだてやの おじいさん\n"
	.string "{JPN}から タマゴを もらった.$"

Route117_Text_TakeGoodCareOfIt:
	.string "{JPN}たいせつに そだててくれよ.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "{JPN}ところで おまえさんの {STR_VAR_1}は\n"
	.string "{JPN}ほかの トレーナーの\l"
	.string "{JPN}{STR_VAR_2}の {STR_VAR_3}と\n"
	.string "{JPN}なかよくしていたぞ.\p"
	.string "{JPN}メールを もらっていた\n"
	.string "{JPN}かもしれんのう.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "{JPN}ポケモンを ひきとりたければ\n"
	.string "{JPN}かみさんに はなしかけてくれ.$"

Route117_Text_YourMonsAreDoingFine:
	.string "{JPN}おお きたか! おまえさんの\n"
	.string "{JPN}{STR_VAR_1}と {STR_VAR_2}は げんきだよ.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "{JPN}ほんとうに もらっていいのかい?\n"
	.string "{JPN}タマゴ いらないかい?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "{JPN}わたしは そだてやの おばあさん.\p"
	.string "{JPN}ポケモンを おあずかりしますよ.\p"
	.string "{JPN}あずけますか?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "{JPN}どの ポケモンを\n"
	.string "{JPN}あずけますか?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "{JPN}はい {STR_VAR_1}を\n"
	.string "{JPN}しばらく あずかりますね.\p"
	.string "{JPN}あとで むかえにきてね.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "{JPN}ポケモンは 2ひきまで あずかれます.\n"
	.string "{JPN}もう 1ぴき あずけますか?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "{JPN}おじいさんが さがしていましたよ.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "{JPN}そう. じゃあ\n"
	.string "{JPN}またきてね.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "{JPN}おかねが たりないよ...$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "{JPN}もう 1ぴきも\n"
	.string "{JPN}ひきとりますか?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "{JPN}じゃあ\n"
	.string "{JPN}またきてね.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "{JPN}あら きたのね.\n"
	.string "{JPN}ポケモンたちは げんきよ!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "{JPN}{STR_VAR_1}は レベルが\n"
	.string "{JPN}{STR_VAR_2} あがりましたよ.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "{JPN}てもちが いっぱいですよ.\n"
	.string "{JPN}あきを つくってきてね.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "{JPN}どの ポケモンを ひきとりますか?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "{JPN}{STR_VAR_1}を ひきとるには\n"
	.string "{JPN}¥{STR_VAR_2} かかりますよ.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "{JPN}はい!\n"
	.string "{JPN}ポケモンを おかえしします.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{JPN}{PLAYER}は そだてやの おばあさん\n"
	.string "{JPN}から {STR_VAR_1}を ひきとった.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "{JPN}あら? ポケモンが\n"
	.string "{JPN}1ぴきしか いないの.\p"
	.string "{JPN}また こんどにしましょう.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "{JPN}ポケモンを ひきとりますか?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "{JPN}その ポケモンを あずけたら\n"
	.string "{JPN}たたかえなくなっちゃうよ?\p"
	.string "{JPN}また こんどにしましょう.$"

Text_EggHatchHuh:
	.string "{JPN}あれ?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "{JPN}あら?\n"
	.string "{JPN}ちょっと まってね.\p"
	.string "{JPN}その ポケモンを あずけたら\n"
	.string "{JPN}1ぴきしか いなくなるよ.\p"
	.string "{JPN}もう すこし つかまえてから\n"
	.string "{JPN}きたほうが いいよ.$"
