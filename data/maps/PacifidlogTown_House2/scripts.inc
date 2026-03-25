PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	goto_if_set FLAG_FINITE_TMS, PacifidlogTown_House2_EventScript_FanClubYoungerBrotherFinite
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_FanClubYoungerBrotherFinite::
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturnFinite
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustrationFinite
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturnFinite::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	checkitem ITEM_TM27
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House2_EventScript_GiveReturnDone
	giveitem ITEM_TM27
	@goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveReturnDone::
	msgbox PacifidlogTown_House2_Text_GiveReturnDone, MSGBOX_NPC
	release
	end

PacifidlogTown_House2_Text_GiveReturnDone:
	.string "{JPN}あら もう もっていますね.$"

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustrationFinite::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	checkitem ITEM_TM21
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House2_EventScript_GiveReturnDone
	giveitem ITEM_TM21
	@goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "{JPN}えーへん!\p"
	.string "{JPN}わたしは ポケモンだいすきクラブの\n"
	.string "{JPN}いちばん えらい かいちょうの\l"
	.string "{JPN}おとうとです.\p"
	.string "{JPN}ここで ポケモンと いっしょに\n"
	.string "{JPN}きゅうかを たのしんでおります \lはい そのとおりです.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "{JPN}あっ!\n"
	.string "{JPN}きみの ポケモン...$"
PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "{JPN}あなたを とても したって\n"
	.string "{JPN}いますね.\p"
	.string "{JPN}こんなに かわいくて なついている\nポケモンには このわざマシンが\lぴったりでしょう ね?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "{JPN}うーん...\n"
	.string "{JPN}わるくは ないけど よくも\n"
	.string "{JPN}ないね.\p"
	.string "{JPN}きみが トレーナーとして\nもっと どりょくしないと\nだめだよ.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "{JPN}きょうあくな かおを していますね.\p"
	.string "{JPN}こんな おそろしい ポケモンには\n"
	.string "{JPN}このわざマシンが ぴったりです.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "{JPN}ポケモンが あなたを すきなら\n"
	.string "{JPN}おんがえしの いりょくが あがり\n"
	.string "{JPN}ます.\p"
	.string "{JPN}きらっているなら やつあたりの\nいりょくが あがります.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "{JPN}おお そうそう.あと {STR_VAR_1}にちほどで\n"
	.string "{JPN}いいわざマシンが てにはいる\n"
	.string "{JPN}よていです.\p"
	.string "{JPN}そのときに また きてください.\n"
	.string "{JPN}あなたの ポケモンに あった\lわざマシンを さしあげましょう.$"

PacifidlogTown_House2_Text_Rurii:
	.string "{JPN}ルリリ:ルリー.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "{JPN}トレーナーに とても\n"
	.string "{JPN}なついているようですね.$"

PacifidlogTown_House2_Text_Rururi:
	.string "{JPN}ルリリ:ルルリ!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "{JPN}トレーナーのことを あまり\n"
	.string "{JPN}すいてないようですね.$"

