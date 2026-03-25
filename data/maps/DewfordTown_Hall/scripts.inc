.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "{JPN}はやってるのは なんって?\n"
	.string "{JPN}そりゃあ\n"
	.string "{JPN}{STR_VAR_1}だよ!\p"
	.string "{JPN}{STR_VAR_1}なしの\nせいかつなんて\nかんがえられないね!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "{JPN}はやってるのは なんって?\n"
	.string "{JPN}そりゃあ\n"
	.string "{JPN}{STR_VAR_1}だよ!\p"
	.string "{JPN}でも ちょっと\nあきてきちゃったな.\pつぎの おおブームを\nさがさなくちゃ.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "{JPN}ポケモンに\n"
	.string "{JPN}{STR_VAR_1}について\l"
	.string "{JPN}おしえてるんだけど\p"
	.string "{JPN}うまく いかないんだ.\pちょっと むずかしすぎるのかな.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "{JPN}いま ナウでトレンディーな\n"
	.string "{JPN}{STR_VAR_1}を\n"
	.string "{JPN}べんきょうしてるんだ.\p"
	.string "{JPN}{STR_VAR_1}と\n"
	.string "{JPN}{STR_VAR_2}のあいだに\lふかい つながりがあるって\lほんとう?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "{JPN}おお!\n"
	.string "{JPN}やっぱり かんは あたってた!\p"
	.string "{JPN}ナウでハプニングに\n"
	.string "{JPN}ちかづいたぞ!\nいやっほー!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "{JPN}なんと!\n"
	.string "{JPN}そうなのか!\p"
	.string "{JPN}としよりには\n"
	.string "{JPN}りゅうこうについていくのは\nたいへんじゃのう!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "{JPN}この{STR_VAR_1}の\n"
	.string "{JPN}はなし...\l"
	.string "{JPN}テレビばんぐみに なってない?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "{JPN}うみの むこうでは...\p"
	.string "{JPN}{STR_VAR_1}は\n"
	.string "{JPN}もっと にんきなの?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "{JPN}わたし こうしき\n"
	.string "{JPN}{STR_VAR_1}\l"
	.string "{JPN}グッズを あつめてるの.\p"
	.string "{JPN}こうしき\n"
	.string "{JPN}{STR_VAR_1}にんぎょうに...\p"
	.string "{JPN}こうしき {STR_VAR_1}\n"
	.string "{JPN}ブランドの ふく...\p"
	.string "{JPN}それに こうしきライセンス\n"
	.string "{JPN}{STR_VAR_1}\l"
	.string "{JPN}えほんも あるのよ.\p"
	.string "{JPN}うふふ ぜんぶ わたしのもの!\n"
	.string "{JPN}あなたには なにも あげないから!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "{JPN}よい{STR_VAR_1}と\n"
	.string "{JPN}わるい{STR_VAR_1}の\l"
	.string "{JPN}みわけかた...\p"
	.string "{JPN}{STR_VAR_1}と\n"
	.string "{JPN}ポケモンの\l"
	.string "{JPN}かんけい...\p"
	.string "{JPN}やくだつ\n"
	.string "{JPN}{STR_VAR_1}...\p"
	.string "{JPN}{STR_VAR_1}についての\n"
	.string "{JPN}ほんで ぎっしりだね.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "{JPN}だいめいは\n"
	.string "{JPN}{STR_VAR_1}の\nさけびだよ.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "{JPN}だいめいは\n"
	.string "{JPN}{STR_VAR_1}の\nえみだよ.$"

DewfordTown_Hall_Text_LastTrend:
	.string "{JPN}だいめいは\n"
	.string "{JPN}さいごの {STR_VAR_1}.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "{JPN}だいめいは\n"
	.string "{JPN}{STR_VAR_1}の たんじょう.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "{JPN}{STR_VAR_1}を みたんだ!\n"
	.string "{JPN}すっげー かっこよかった!\p"
	.string "{JPN}いまいちばん\n"
	.string "{JPN}ホットなものだね!\p"
	.string "{JPN}さいこーだった!\nほんものだったよ!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "{JPN}いえいえいえ だめですよ.\p"
	.string "{JPN}あなたが みたという\n"
	.string "{JPN}{STR_VAR_1}は\l"
	.string "{JPN}にせものです.\p"
	.string "{JPN}ほんものは もっと...\n"
	.string "{JPN}なんというか...\l"
	.string "{JPN}シャープで メロウなんです!\p"
	.string "{JPN}ああ まあいいでしょう.\nおどろきですよ!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "{JPN}ねえ きいて! {STR_VAR_1}の\n"
	.string "{JPN}テーマソングを つくったんだ.\p"
	.string "{JPN}{STR_VAR_1}は\n"
	.string "{JPN}いま ほんとうに にんきだからね.\n"
	.string "{JPN}よし きいてくれ!\n"
	.string "{JPN}... ...\p"
	.string "{JPN}ああ!\n"
	.string "{JPN}{STR_VAR_1}!\p"
	.string "{JPN}すてきな\n"
	.string "{JPN}{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "{JPN}... ...\p"
	.string "{JPN}きみ {STR_VAR_1}に\n"
	.string "{JPN}てを だす まえに\l"
	.string "{JPN}うたの れんしゅうを したほうが\l"
	.string "{JPN}よいのではないかな.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "{JPN}ところで さっきのはなしだけど\n"
	.string "{JPN}しまで みんなで あつまって\l"
	.string "{JPN}{STR_VAR_1}パーティーを\l"
	.string "{JPN}かいさい しようよ.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "{JPN}おお! すばらしい あいでぃあだ!\p"
	.string "{JPN}だれが いちばん\n"
	.string "{JPN}{STR_VAR_1}が\l"
	.string "{JPN}とくいか きまるね!\l"
	.string "{JPN}てんさいてきだ!\p"
	.string "{JPN}きょうから ぼくらの せいかつは\n"
	.string "{JPN}{STR_VAR_1}が\nちゅうしんだ!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "{JPN}でも おもうんだけど...\p"
	.string "{JPN}{STR_VAR_1}って\n"
	.string "{JPN}たんなる りゅうこうから\l"
	.string "{JPN}にちじょうせいかつの いちぶに\l"
	.string "{JPN}なったと おもわない?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "{JPN}すみません?\n"
	.string "{JPN}そんなに なんですって?\p"
	.string "{JPN}でも たしかに\n"
	.string "{JPN}{STR_VAR_1}は\l"
	.string "{JPN}おきても ねても\l"
	.string "{JPN}あたまから はなれないですね.\p"
	.string "{JPN}あなたこそ\n"
	.string "{JPN}{STR_VAR_1}\l"
	.string "{JPN}はかせですよ!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "{JPN}きみと ぼくが チームをくめば\n"
	.string "{JPN}{STR_VAR_1}のことでは\l"
	.string "{JPN}むてきになれるよ!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "{JPN}そのとおりだ!\n"
	.string "{JPN}{STR_VAR_1}\n"
	.string "{JPN}コンビの たんじょうだ!\p"
	.string "{JPN}いいかんじじゃないか?\n"
	.string "{JPN}はっはっは!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "{JPN}ぼくにとって ヘドロばくだんが\n"
	.string "{JPN}にんきの ちょうじょうだね.\n"
	.string "{JPN}それが いちばんさ.\p"
	.string "{JPN}え? ヘドロばくだんを\n"
	.string "{JPN}しらないって?\p"
	.string "{JPN}それは かわいそうだ.\nひとつ あげよう.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "{JPN}ヘドロばくだんが だいすき.\p"
	.string "{JPN}でも\n"
	.string "{JPN}{STR_VAR_1}を\n"
	.string "{JPN}おぼえた ポケモンも\nいいよね.$"

