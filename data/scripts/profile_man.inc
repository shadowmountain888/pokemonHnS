ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "{JPN}トレーナーさん たちの\n"
	.string "{JPN}プロフィールを あつめるのが\l"
	.string "{JPN}しゅみ なんだけど...$"

ProfileMan_Text_MayISeeYourProfile:
	.string "{JPN}どうかな? きみの プロフィール\n"
	.string "{JPN}ぼくに おしえて もらえないかな?$"

ProfileMan_Text_EasyChatExplanation:
	.string "{JPN}プロフィールは すきな ことばを\n"
	.string "{JPN}4つ くみあわせて つくるんだよ!\p"
	.string "{JPN}これから ぼくが\n"
	.string "{JPN}てきとうな 4つの ことばで つくった\l"
	.string "{JPN}プロフィールを みせるから\p"
	.string "{JPN}きみは その ことばを\n"
	.string "{JPN}すきなものに いれかえて\l"
	.string "{JPN}きみだけの プロフィールに してね!\p"
	.string "{JPN}えらべる ことばは\n"
	.string "{JPN}すごく たくさん あるから\l"
	.string "{JPN}グループに わかれて いるんだ\l"
	.string "{JPN}ポケモン とか せいかつ とか しゅみ...\l"
	.string "{JPN}という ぐあいにね!\p"
	.string "{JPN}だから まずは\n"
	.string "{JPN}グループを えらんで...\l"
	.string "{JPN}そのあとに えらんだ グループの\l"
	.string "{JPN}ことばが いくつも でてくるから\l"
	.string "{JPN}そこから すきな ことばを\l"
	.string "{JPN}みつけてね!$"

ProfileMan_Text_LetsSeeItThen:
	.string "{JPN}やった! ありがとう!\n"
	.string "{JPN}じゃ さっそく きかせてよ!$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "{JPN}そんなあ...\p"
	.string "{JPN}きみの プロフィールは さぞかし\n"
	.string "{JPN}すてきだと おもうんだけど なぁ...$"

ProfileMan_Text_NotIntoItRightNow:
	.string "{JPN}あれ? いまは きが のらないんだね?\p"
	.string "{JPN}だったら いつでも いいよ!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "{JPN}こんにちは\n"
	.string "{JPN}えがおの すてきな トレーナーさん!$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "{JPN}きみの あたらしい プロフィールを\n"
	.string "{JPN}おしえて くれるのかな?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "{JPN}やった! ありがとう!\p"
	.string "{JPN}じゃあ まえにも まして\n"
	.string "{JPN}すてきな やつを きたい してるよ!$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "{JPN}いまの ままが いいんだね?\p"
	.string "{JPN}そうだよね とても すてきな\n"
	.string "{JPN}プロフィール だもの!$"

ProfileMan_Text_FantasticProfile:
	.string "{JPN}すっ すばらしい!\p"
	.string "{JPN}まさに きみ そのもの って かんじの\n"
	.string "{JPN}すてきな プロフィール!\p"
	.string "{JPN}これを きいた ひとは\n"
	.string "{JPN}だれもが きみの とりこに なるだろうね!\p"
	.string "{JPN}どうも ありがとう!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "{JPN}あら?\n"
	.string "{JPN}ひみつの あいことばを しってるの!\p"
	.string "{JPN}じゃあ きみも ふしぎな\n"
	.string "{JPN}イベントクラブの なかまだね!$"
