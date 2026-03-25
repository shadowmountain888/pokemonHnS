.set LOCALID_DAYCARE_LADY, 1

Route34_DayCare_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf2::
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf3::
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf4::
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_SIGN
	end

Route34_DayCare_Text_Bookshelf1:
	.string "{JPN}じしょだ!\p"
	.string "{JPN}{PLAYER}は てきとうな\n"
	.string "{JPN}ページを ひらいた.\p"
	.string "{JPN}あかちゃん\n"
	.string "{JPN}めいし. ようじ または\l"
	.string "{JPN}にゅうじの いみ.\p{PLAYER}は じしょを\nしまった.$"

Route34_DayCare_Text_Bookshelf2:
	.string "{JPN}ポケモンの ほんだ!\p"
	.string "{JPN}{PLAYER}は ほんを\n"
	.string "{JPN}ぱらぱら めくった.\p"
	.string "{JPN}すべての ページに\n"
	.string "{JPN}ポケモンって かいてある\l"
	.string "{JPN}みたいだ.\p{PLAYER}は ほんを\nしまった.$"

Route34_DayCare_Text_Bookshelf3:
	.string "{JPN}たんごれんそうの ほんだ!\p"
	.string "{JPN}{PLAYER}は ほんを\n"
	.string "{JPN}ぱらぱら めくった.\p"
	.string "{JPN}ピチュー  かわいい\l"
	.string "{JPN}ピィ  かわいい\l"
	.string "{JPN}ププリン  うた\l"
	.string "{JPN}バルキー  かくとう\l"
	.string "{JPN}ムチュール  こおり\l"
	.string "{JPN}エレキッド  でんき\l"
	.string "{JPN}ブビィ  ほのお\p"
	.string "{JPN}{PLAYER}は ほんを\nしまった.$"

Route34_DayCare_Text_Bookshelf4:
	.string "{JPN}ポケモンの とくせいの ほんだ!\p"
	.string "{JPN}{PLAYER}は ほんを\n"
	.string "{JPN}ぱらぱら めくった.\p"
	.string "{JPN}ピチュー  せいでんき\l"
	.string "{JPN}ピィ  メロメロボディ\l"
	.string "{JPN}ププリン  メロメロボディ\l"
	.string "{JPN}バルキー  こんじょう\l"
	.string "{JPN}ムチュール  どんかん\l"
	.string "{JPN}エレキッド  せいでんき\l"
	.string "{JPN}ブビィ  ほのおのからだ\p"
	.string "{JPN}{PLAYER}は ほんを\nしまった.$"

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	setvar VAR_0x8005, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_OBTAIN_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
	.string "{JPN}ぼくは そだてやふうふの\n"
	.string "{JPN}むすこです.\n"
	.string "{JPN}トレーナーの ポケモンと\n"
	.string "{JPN}いっしょに ふしぎなタマゴが\l"
	.string "{JPN}みつかったんですが\l"
	.string "{JPN}そのひとは いらないって...\pあなたに さしあげたいのですが...\nでも ちゃんと そだててくれるか\lどうやって しんじればいいのか...$"

Route34_DayCare_Text_ClerkNoRoom:
	.string "{JPN}それに ポケモンを\n"
	.string "{JPN}もてないみたいですし.$"

Route34_DayCare_Text_ClerkQuestion:
	.string "{JPN}しつもんに こたえてください.\n"
	.string "{JPN}この ふしぎなタマゴについて\lどう おもいますか?$"

Route34_DayCare_Text_Rejection:
	.string "{JPN}うーん この タマゴは\n"
	.string "{JPN}あなたには むいてないみたい.\p"
	.string "{JPN}ポケモンの いくじに ついて\n"
	.string "{JPN}じゅうぶん べんきょうしていない\l"
	.string "{JPN}ひとに だいじな タマゴを\lわたすのは むせきにんです!$"

Route34_DayCare_Text_ReceivedOddEgg:
	.string "{JPN}{PLAYER}は ふしぎなタマゴを\nうけとった!$"

Route34_DayCare_Text_TakeCare:
	.string "{JPN}やっぱり あなたが\n"
	.string "{JPN}ぴったりの トレーナーでした.\lだいじに そだててくださいね!$"

Route34_DayCare_Text_ClerkAfter:
	.string "{JPN}ここでは よく タマゴを\n"
	.string "{JPN}みかけます.\p"
	.string "{JPN}でも あの タマゴは\n"
	.string "{JPN}なにか ちがってました.$"

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
	.string "{JPN}メタモン: メタ!$"

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
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
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "{JPN}わたしが そだてやの\n"
	.string "{JPN}おじいさんじゃ.\p"
	.string "{JPN}トレーナーの だいじな ポケモンを\n"
	.string "{JPN}あずかって そだてておるよ.\p"
	.string "{JPN}ポケモンを そだててほしければ\nつまと はなしてくれ.$"

Route34_Text_DoYouWantEgg:
	.string "{JPN}おお きみか!\p"
	.string "{JPN}きみの ポケモンを そだてていて\n"
	.string "{JPN}おどろいたことがあるんじゃ!\p"
	.string "{JPN}なんと ポケモンが タマゴを\n"
	.string "{JPN}もっていたんじゃよ!\p"
	.string "{JPN}どうやって できたのか\n"
	.string "{JPN}わからないが ポケモンが\lもっていたんじゃ.\pほしいじゃろう?$"

Route34_Text_YourMonIsDoingFine:
	.string "{JPN}おお きみか! げんきそうじゃな.\n"
	.string "{JPN}きみの {STR_VAR_1}は\lげんきに しておるよ.$"

Route34_Text_IllKeepIt:
	.string "{JPN}そうか それなら\n"
	.string "{JPN}わしが あずかっておこう.\lありがたいのう!$"

Route34_Text_YouHaveNoRoomForIt:
	.string "{JPN}もちものが いっぱいです...\n"
	.string "{JPN}ばしょを あけてから きてください$"

Route34_Text_ReceivedEgg:
	.string "{JPN}{PLAYER}は そだてやの\n"
	.string "{JPN}おじいさんから タマゴを\lうけとった!$"

Route34_Text_TakeGoodCareOfIt:
	.string "{JPN}だいじに そだてるんじゃよ.$"

Route34_Text_FriendlyWithOtherTrainersMon:
	.string "{JPN}ところで きみの {STR_VAR_1}じゃが\n"
	.string "{JPN}{STR_VAR_2}の {STR_VAR_3}と\l"
	.string "{JPN}なかよく しておったようじゃ.\p"
	.string "{JPN}てがみを もらっているのも\n"
	.string "{JPN}みかけたぞい.$"

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
	.string "{JPN}ポケモンを ひきとりたければ\n"
	.string "{JPN}つまと はなしてくれ.$"

Route34_Text_YourMonsAreDoingFine:
	.string "{JPN}おお きみか! きみの {STR_VAR_1}と\n"
	.string "{JPN}{STR_VAR_2}は げんきに\lしておるよ.$"

Route34_Text_IWillKeepDoYouWantIt:
	.string "{JPN}ほんとうに わしが\n"
	.string "{JPN}あずかっておくぞ.\lこれが ほしいんじゃな?$"

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "{JPN}わたしが そだてやの\n"
	.string "{JPN}おばあさんです.\p"
	.string "{JPN}ポケモンを そだてることが\nできますよ.\nポケモンを そだてましょうか?$"

Route34_DayCare_Text_WhichMonShouldWeRaise:
	.string "{JPN}どの ポケモンを\n"
	.string "{JPN}そだてましょうか?$"

Route34_DayCare_Text_WellRaiseYourMon:
	.string "{JPN}はい {STR_VAR_1}を しばらく\n"
	.string "{JPN}そだてておきますね.\p"
	.string "{JPN}また とりに きてください.$"

Route34_DayCare_Text_WeCanRaiseOneMore:
	.string "{JPN}わたしたちは あなたの\n"
	.string "{JPN}ポケモンを 2ひき そだてられるの\lもう 1ぴき あずけますか?$"

Route34_DayCare_Text_HusbandWasLookingForYou:
	.string "{JPN}しゅじんが あなたを\nさがしてましたよ$"

Route34_DayCare_Text_FineThenComeAgain:
	.string "{JPN}あら そうですか\n"
	.string "{JPN}また いらしてくださいね$"

Route34_DayCare_Text_NotEnoughMoney:
	.string "{JPN}おかねが たりません...$"
Route34_DayCare_Text_TakeOtherOneBackToo:
	.string "{JPN}もう 1ぴきの ポケモンも\n"
	.string "{JPN}つれて かえりますか?$"

Route34_DayCare_Text_ComeAgain:
	.string "{JPN}そうですか\n"
	.string "{JPN}また いらしてくださいね$"

Route34_DayCare_Text_GoodToSeeYou:
	.string "{JPN}あら あなたね! げんきそうで\n"
	.string "{JPN}よかった あなたの ポケモンも\lげんきいっぱいよ!$"

Route34_DayCare_Text_YourMonHasGrownXLevels:
	.string "{JPN}あなたの {STR_VAR_1}は\n"
	.string "{JPN}レベルが {STR_VAR_2} あがったわ$"

Route34_DayCare_Text_YourTeamIsFull:
	.string "{JPN}あなたの てもちポケモンが\n"
	.string "{JPN}いっぱいね ばしょを つくってから\lまた きてくださいな$"

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
	.string "{JPN}どちらの ポケモンを\nつれて かえりますか?$"

Route34_DayCare_Text_ItWillCostX:
	.string "{JPN}{STR_VAR_1}を つれて かえるなら\n"
	.string "{JPN}{STR_VAR_2}えん いただくわ$"

Route34_DayCare_Text_HeresYourMon:
	.string "{JPN}ありがとう!\n"
	.string "{JPN}はい あなたの ポケモンよ$"

Route34_DayCare_Text_TookBackMon:
	.string "{JPN}{PLAYER}は そだてやのおばさんから\n"
	.string "{JPN}{STR_VAR_1}を つれて かえった$"

Route34_DayCare_Text_YouHaveJustOneMon:
	.string "{JPN}あら? でも あなた ポケモンが\n"
	.string "{JPN}1ぴきしか いないじゃない\p"
	.string "{JPN}また こんど いらしてね$"

Route34_DayCare_Text_TakeYourMonBack:
	.string "{JPN}ポケモンを つれて\nかえりますか?$"

Route34_DayCare_Text_WhatWillYouBattleWith:
	.string "{JPN}その ポケモンを あずけたら\n"
	.string "{JPN}なにで たたかうの?\p"
	.string "{JPN}また こんど いらしてね$"

Route34_DayCare_Text_YoullBeLeftWithJustOne:
	.string "{JPN}あら?\n"
	.string "{JPN}ちょっと まってね\p"
	.string "{JPN}その ポケモンを あずけたら\n"
	.string "{JPN}あなた 1ぴきしか のこらないわよ\p"
	.string "{JPN}もう すこし つかまえてからの\n"
	.string "{JPN}ほうが いいんじゃない?$"
