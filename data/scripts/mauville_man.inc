MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "{JPN}わし グッズこうかんオヤジ\n"
	.string "{JPN}わしと グッズの こうかん する?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "{JPN}そう...\n"
	.string "{JPN}わし ざんねん...$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "{JPN}でも きみとは このまえ\n"
	.string "{JPN}グッズの こうかん したよね$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "{JPN}これ わしが もってる グッズ\n"
	.string "{JPN}なにか ほしいの あったら いってね$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "{JPN}ほしい グッズ ないの?\n"
	.string "{JPN}わし ざんねん...$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "{JPN}それは {STR_VAR_1}さんが\n"
	.string "{JPN}つかってた グッズ だよ\p"
	.string "{JPN}これに するかい?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "{JPN}...って きみ グッズ\n"
	.string "{JPN}ひとつも もってない じゃん!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "{JPN}じゃあ こうかんに だしてくれる\n"
	.string "{JPN}グッズを えらんで!$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "{JPN}こうかん して くれないの?\n"
	.string "{JPN}わし ざんねん...$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "{JPN}きみ {STR_VAR_2}が いっぱいで\n"
	.string "{JPN}もう もてないよ$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "{JPN}じゃあ わしの {STR_VAR_3}と\n"
	.string "{JPN}きみの {STR_VAR_2}を こうかんするよ?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "{JPN}きみ いま そのグッズ かざってるね\n"
	.string "{JPN}かざってる グッズは こうかん できないよ$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "{JPN}じゃあ こうかん!\l"
	.string "{JPN}きみの パソコンに\n"
	.string "{JPN}グッズを おくっておくよ$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "{JPN}ああ! ごめん!\n"
	.string "{JPN}それ とっても レアな グッズ だから\l"
	.string "{JPN}こうかん できないんだ!\p"
	.string "{JPN}ほかに ほしい グッズ ある?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "{JPN}わし でんせつおやじ\n"
	.string "{JPN}でんせつの トレーナーの はなし するよ\p"
	.string "{JPN}わしの ハナシ ききたい?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "{JPN}そう...\n"
	.string "{JPN}わし ざんねん...$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "{JPN}わしが しってる でんせつは これだけ\n"
	.string "{JPN}どの でんせつが ききたい?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "{JPN}でも わし...\n"
	.string "{JPN}でんせつの トレーナーの はなし\l"
	.string "{JPN}なにも しらない\p"
	.string "{JPN}どこかに でんせつに のこる\n"
	.string "{JPN}トレーナーは いないかなあ$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "{JPN}...え!!!\p"
	.string "{JPN}きみ {STR_VAR_1}かい も\n"
	.string "{JPN}{STR_VAR_2} の!?\p"
	.string "{JPN}...ううむ それは すごい!\n"
	.string "{JPN}あたらしい でんせつの はじまりだ!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "{JPN}これより もっとすごい\n"
	.string "{JPN}でんせつを もってる トレーナー\l"
	.string "{JPN}どこかに いない かなあ...$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "{JPN}...きみ トレーナー?\p"
	.string "{JPN}だったら なにか でんせつっぽい はなし\n"
	.string "{JPN}きかせてよ$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "{JPN}ところで...\n"
	.string "{JPN}まだ でんせつ ききたい?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "{JPN}...うーん ものたりない なあ\p"
	.string "{JPN}もっと すごい はなしを\n"
	.string "{JPN}きかせて ほしいなあ$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "{JPN}もっと たくさんの ひとに\n"
	.string "{JPN}でんせつの トレーナーの はなし\l"
	.string "{JPN}きいて ほしいなあ$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "{JPN}レポートを かきまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "{JPN}レポートを かいた$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}{STR_VAR_1}かいも\n"
	.string "{JPN}レポートを かいた らしい!\p"
	.string "{JPN}{STR_VAR_3}ほど ようじん ぶかい\n"
	.string "{JPN}トレーナーは いない だろう!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "{JPN}りゅうこう はっしん トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "{JPN}りゅうこうを つくった$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}{STR_VAR_1}かいも\n"
	.string "{JPN}りゅうこうを うみだした らしい!\p"
	.string "{JPN}{STR_VAR_3}こそが つぎつぎと\n"
	.string "{JPN}ホウエンの りゅうこうを うみだしている!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "{JPN}きのみを うえまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "{JPN}きのみを うえた$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}{STR_VAR_1}かいも\n"
	.string "{JPN}きのみを うめた そうだ!\p"
	.string "{JPN}{STR_VAR_3}は でんせつの\n"
	.string "{JPN}きのみ ずき だな!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "{JPN}じてんしゃ だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "{JPN}じてんしゃを こうかんした$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}じてんしゃを こうかんした そうだ!\p"
	.string "{JPN}{STR_VAR_3}は よほどの\n"
	.string "{JPN}じてんしゃ だいすき トレーナー だな!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "{JPN}インタビューに こたえまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "{JPN}インタビューに こたえた$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}インタビューを うけた そうだ!\p"
	.string "{JPN}{STR_VAR_3}は とても\n"
	.string "{JPN}ちゅうもく される トレーナー だろう!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "{JPN}しょうぶ だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "{JPN}しょうぶ した$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ポケモン しょうぶを した そうだ!\p"
	.string "{JPN}{STR_VAR_3}は トレーナーを みると\n"
	.string "{JPN}しょうぶ せずに おれない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "{JPN}つかまえまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "{JPN}ポケモンを つかまえた$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}ひき もの\n"
	.string "{JPN}ポケモンを つかまえた そうだ!\p"
	.string "{JPN}{STR_VAR_3}こそ でんせつの\n"
	.string "{JPN}ポケモン つかまえ じょうず だ!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "{JPN}つりまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "{JPN}ポケモンを つった$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}ひき もの\n"
	.string "{JPN}ポケモンを つった そうだ!\p"
	.string "{JPN}{STR_VAR_3}こそ でんせつの\n"
	.string "{JPN}つり めいじん だ!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "{JPN}タマゴを あたため つづけた トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "{JPN}タマゴを かえした$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}{STR_VAR_1}こ もの タマゴを\n"
	.string "{JPN}かえした そうだ!\p"
	.string "{JPN}{STR_VAR_3}こそ でんせつの\n"
	.string "{JPN}タマゴ あたため トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "{JPN}しんか させまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "{JPN}ポケモンを しんか させた$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}ひきもの\n"
	.string "{JPN}ポケモンを しんか させたそうだ!\p"
	.string "{JPN}{STR_VAR_3}こそ さいこうの\n"
	.string "{JPN}ポケモン しんか マスターだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "{JPN}ポケモンセンター だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "{JPN}ポケモンセンターで かいふくした$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ポケモンセンターで かいふく したのだ!\p"
	.string "{JPN}{STR_VAR_3}ほど ポケモンセンターが\n"
	.string "{JPN}すきな トレーナーも いない だろう!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "{JPN}さとがえり だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "{JPN}じぶんの いえで かいふくした$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}じぶんの いえで かいふく したのだ!\p"
	.string "{JPN}{STR_VAR_3}ほど さとがえりが\n"
	.string "{JPN}すきな トレーナーも いないだろう!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "{JPN}サファリゾーンに いりびたった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "{JPN}サファリゾーンに はいった$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}サファリゾーンに はいった そうだ!\p"
	.string "{JPN}{STR_VAR_3}は サファリゾーンでは\n"
	.string "{JPN}やせいの ちが さわぐ トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "{JPN}いあいぎりを しまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "{JPN}いあいぎり した$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}いあいぎりを つかった そうだ!\p"
	.string "{JPN}{STR_VAR_3}は いあいぎりが\n"
	.string "{JPN}すきで しょうがない トレーナー なのだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "{JPN}いわを くだかずに おれない トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "{JPN}いわくだき した$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}いわくだきを つかった そうだ!\p"
	.string "{JPN}{STR_VAR_3}は いわを みたら\n"
	.string "{JPN}くだかずに おれない トレーナー なのだ!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "{JPN}ひっこし だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "{JPN}ひっこし した$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ひみつきちを ひっこし したそうだ!\p"
	.string "{JPN}{STR_VAR_3}は ひっこしが\n"
	.string "{JPN}とっても すきな トレーナー なのだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "{JPN}はねまくり トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "{JPN}はねるを つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}はねるを つかった らしい!\p"
	.string "{JPN}{STR_VAR_3}は はねる のが\n"
	.string "{JPN}とっても すきな トレーナー なのだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "{JPN}あきらめない トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "{JPN}わるあがき した$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}わるあがきを した らしい!\p"
	.string "{JPN}{STR_VAR_3}は どんな じょうきょう でも\n"
	.string "{JPN}けっして あきらめない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "{JPN}スロットの めいじん$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "{JPN}スロットで おおあたり した$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}スロットで おおあたり した らしい!\p"
	.string "{JPN}{STR_VAR_3}は スロットマシンを\n"
	.string "{JPN}しりつくして いる トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "{JPN}ルーレットの めいじん$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "{JPN}ルーレットを れんぞくで あてた$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ルーレットを れんぞくで あてた らしい!\p"
	.string "{JPN}{STR_VAR_3}は はっきり いって\n"
	.string "{JPN}ルーレットを みきっている トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "{JPN}バトルタワーの ちょうせんしゃ$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "{JPN}バトルタワーに ちょうせん した$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}バトルタワーに いどんだ そうだ!\p"
	.string "{JPN}{STR_VAR_3}は バトルタワーに\n"
	.string "{JPN}こだわりを もっている トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "{JPN}ブレンド だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "{JPN}ポロックを つくった$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}{STR_VAR_1}かいも\n"
	.string "{JPN}ポロックを つくった そうだ!\p"
	.string "{JPN}{STR_VAR_3}に きのみブレンダーを\n"
	.string "{JPN}つかわせたら みぎに でるものは ないな!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "{JPN}コンテスト だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "{JPN}コンテストに さんか した$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}{STR_VAR_1}かいも\n"
	.string "{JPN}コンテストに さんか した そうだ!\p"
	.string "{JPN}{STR_VAR_3}は じぶんの ポケモンを\n"
	.string "{JPN}ひとに みせるのが だいすき なんだろう!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "{JPN}コンテストの たつじん$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "{JPN}コンテストで ゆうしょう した$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}コンテストで ゆうしょう した そうだ!\p"
	.string "{JPN}{STR_VAR_3}は とてつも ない\n"
	.string "{JPN}コンテスト マスター だろう!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "{JPN}かいもの だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "{JPN}かいものを した$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}おみせで かいものを した らしい!\p"
	.string "{JPN}{STR_VAR_3}は おみせに はいると\n"
	.string "{JPN}ついつい かいもの する トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "{JPN}ダウジング だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "{JPN}ダウジングマシンを つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ダウジングマシンを つかった らしい!\p"
	.string "{JPN}{STR_VAR_3}は\n"
	.string "{JPN}さがしものが だいすきな トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "{JPN}あめに ふられた トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "{JPN}あめに ふられた$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}あめで ずぶぬれに なった らしい!\p"
	.string "{JPN}{STR_VAR_3}は みずも したたる\n"
	.string "{JPN}いい トレーナーっていう かんじ だな!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "{JPN}ずかんで しらべまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "{JPN}ずかんを みた$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ずかんを みた そうだ!\p"
	.string "{JPN}{STR_VAR_3}は ずかんで ポケモンを\n"
	.string "{JPN}しらべるのが だいすきな トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "{JPN}リボンを たくさん あつめた トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "{JPN}リボンを もらった$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}リボンを もらった らしい!\p"
	.string "{JPN}{STR_VAR_3}は リボンを あつめるのが\n"
	.string "{JPN}とても だいすきな トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "{JPN}だんさを とびおりまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "{JPN}だんさを とびおりた$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}だんさを とびおりた らしい!\p"
	.string "{JPN}{STR_VAR_3}は だんさを みると\n"
	.string "{JPN}とびおりずに おれない トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "{JPN}でんせつの テレビ ウォッチャー$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "{JPN}テレビを みた$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}テレビを みた らしい!\p"
	.string "{JPN}{STR_VAR_3}は\n"
	.string "{JPN}テレビ だいすき トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "{JPN}じかんを きに する トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "{JPN}とけいを みた$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}とけいを みた らしい!\p"
	.string "{JPN}{STR_VAR_3}は じかんを きに する\n"
	.string "{JPN}きちょうめんな トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "{JPN}ポケモンくじに あたりまくった トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "{JPN}ポケモンくじで あたった$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ポケモンくじで あたった らしい!\p"
	.string "{JPN}{STR_VAR_3}は ポケモンを こうかん する\n"
	.string "{JPN}ともだちが とても おおい トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "{JPN}そだてやを つかいこなす トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "{JPN}そだてやに ポケモンを あずけた$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}そだてやに あずけた らしい!\p"
	.string "{JPN}{STR_VAR_3}は とにかく そだてまくる\n"
	.string "{JPN}モーレツな トレーナーに ちがいない!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "{JPN}ロープウェイ だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "{JPN}ロープウェイに のった$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}ロープウェイに のった らしい!\p"
	.string "{JPN}{STR_VAR_3}は うえに したにと\n"
	.string "{JPN}おおいそがしの トレーナーだな!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "{JPN}おんせんに かよいづめの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "{JPN}おんせんに はいった$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "{JPN}{STR_VAR_3}という\n"
	.string "{JPN}トレーナーの はなし だが...\p"
	.string "{JPN}なんと {STR_VAR_1}かいも\n"
	.string "{JPN}おんせんに はいった らしい!\p"
	.string "{JPN}{STR_VAR_3}は きっと\n"
	.string "{JPN}おはだが ツルツルの トレーナー だろう!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "{JPN}わし メルヘンおやじ\n"
	.string "{JPN}とても いい はなし するよ\p"
	.string "{JPN}わしの ハナシ ききたい?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "{JPN}そう...\n"
	.string "{JPN}わし ざんねん...$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "{JPN}あと おもったんだけどさ...$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "{JPN}そのぐらい かな...\p"
	.string "{JPN}また はなし しようね!\n"
	.string "{JPN}ばいばい!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "{JPN}わし シンガーソングおやじ\n"
	.string "{JPN}わしの うた きいてくれる?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "{JPN}そう...\n"
	.string "{JPN}わし ざんねん...$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "{JPN}あぁ いい うた だなぁ\n"
	.string "{JPN}ほかの ひとにも きかせて みたいなあ$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "{JPN}どう? わしの うた?\p"
	.string "{JPN}でも ちょっと かしが きにいらない\p"
	.string "{JPN}だから きみ ちょっと かえてくれる?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "{JPN}そう...\n"
	.string "{JPN}わし ざんねん...$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "{JPN}ありがとう!\n"
	.string "{JPN}じゃあ うたって みるぞ!$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "{JPN}こんな かんじで いいの?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "{JPN}よし わかった!\n"
	.string "{JPN}しばらく このうたを うたって みるよ!$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "{JPN}わし ナウイおやじ\n"
	.string "{JPN}いまどきの ナウイことば おしえるよ$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "{JPN}でも きみには このまえ おしえたよね\p"
	.string "{JPN}こんどは ほかの ひとに おしえたいなぁ$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "{JPN}でも きみ ことば たくさん しってるね\n"
	.string "{JPN}おしえること ぜんぜん ないよ$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "{JPN}きみ {STR_VAR_1}って\n"
	.string "{JPN}ことば しってる?\p"
	.string "{JPN}いみ? それはね...\n"
	.string "{JPN}おとうさんか おかあさんに きいてみて$"
