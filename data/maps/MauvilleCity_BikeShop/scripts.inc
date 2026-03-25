MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	msgbox MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_GetAcroBike
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_GetMachBike
	@waitmessage
	@multichoice 21, 8, MULTI_BIKE, TRUE
	@switch VAR_RESULT
	@case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	@case 1, MauvilleCity_BikeShop_EventScript_GetMachBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike2, MSGBOX_DEFAULT
	@giveitem ITEM_MACH_BIKE
	@goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	release
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_NPC
	@goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	@goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "{JPN}おお おお なんと\n"
	.string "{JPN}げんきな おきゃくさんじゃ!\p"
	.string "{JPN}わしか? わしは ライデルという\n"
	.string "{JPN}この じてんしゃやの てんしゅじゃ$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "{JPN}ライデル: きみの ランニングシューズ...\n"
	.string "{JPN}ずいぶん よごれて いるね.\p"
	.string "{JPN}とおく から やって きたのかい?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "{JPN}ライデル: そうか そうか\p"
	.string "{JPN}それなら わしの じてんしゃは\n"
	.string "{JPN}いらんということじゃな$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike2:
	.string "{JPN}ライデル: そうか そうか\p"
	.string "{JPN}まあ きみの じゆうじゃ$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "{JPN}ライデル: ふーむ ふーむ... ... ... ... ...\p"
	.string "{JPN}ミシロから ずっと\n"
	.string "{JPN}あるいて きたって いうのかい?\p"
	.string "{JPN}なんと まあ!\n"
	.string "{JPN}とんでもなく とおいじゃないか!\p"
	.string "{JPN}わしの じてんしゃが あれば\n"
	.string "{JPN}かぜの ここちよさを かんじながら\l"
	.string "{JPN}どこへでも らくに いけるのに!\p"
	.string "{JPN}そうだ!\n"
	.string "{JPN}じてんしゃを あげよう!\p"
	.string "{JPN}ああ ちょっと まって!\p"
	.string "{JPN}じてんしゃには にしゅるい\n"
	.string "{JPN}あることを いいわすれて いた!\p"
	.string "{JPN}マッハじてんしゃと\n"
	.string "{JPN}ダートじてんしゃが あるんじゃ!\p"
	.string "{JPN}マッハじてんしゃは からだで\n"
	.string "{JPN}かぜを かんじたい ひとよう!\p"
	.string "{JPN}ダートじてんしゃは テクニカルな\n"
	.string "{JPN}のりかたを このむ ひとよう!\p"
	.string "{JPN}そして いちばん すごいのは?\p"
	.string "{JPN}ダートも マッハも ひとつの\n"
	.string "{JPN}じてんしゃなんじゃ! オールインワン!\p"
	.string "{JPN}それで じてんしゃが ほしいかい?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{JPN}{PLAYER}は マッハじてんしゃを\nえらんだ$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{JPN}{PLAYER}は じてんしゃを てにいれた$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "{JPN}ライデル: あたらしい じてんしゃを\n"
	.string "{JPN}たのしんでくれい!\p"
	.string "{JPN}ライデル: Rボタンを おせば\nじてんしゃの モードが かわるぞ$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "{JPN}ライデル: じてんしゃは\n"
	.string "{JPN}たのしんでおるか?\p"
	.string "{JPN}ライデル: Rボタンを おせば\n"
	.string "{JPN}じてんしゃの モードが かわるぞ$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "{JPN}ライデル: よし わかった!\n"
	.string "{JPN}じてんしゃを こうかん してやろう!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{JPN}{PLAYER}は マッハじてんしゃを\n"
	.string "{JPN}ダートじてんしゃと こうかんした$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{JPN}{PLAYER}は ダートじてんしゃを\n"
	.string "{JPN}マッハじてんしゃと こうかんした$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "{JPN}ライデル: よい よい!\n"
	.string "{JPN}きにいって くれて うれしいぞ!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "{JPN}おや? わしが やった じてんしゃは\n"
	.string "{JPN}どうしたんじゃ?\p"
	.string "{JPN}ああ そうか パソコンに\n"
	.string "{JPN}あずけておるんじゃな\p"
	.string "{JPN}パソコンから だして くれれば\n"
	.string "{JPN}こうかん してやるぞ!\p"
	.string "{JPN}きみの ぼうけんに かぜが\nふくことを いのっておるよ!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "{JPN}わたしは ここで はたらきながら\n"
	.string "{JPN}じてんしゃの べんきょうを してます\p"
	.string "{JPN}じてんしゃの のりかたが わからない\n"
	.string "{JPN}ときは おくに せつめいしょが\l"
	.string "{JPN}ありますよ$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "{JPN}マッハじてんしゃの せつめいしょです\p"
	.string "{JPN}どの ページを よみますか?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "{JPN}じてんしゃは じゅうじキーを おした\n"
	.string "{JPN}ほうこうに すすみます\p"
	.string "{JPN}はしりだすと だんだん\n"
	.string "{JPN}スピードが でてきます\p"
	.string "{JPN}とまるときは じゅうじキーを\n"
	.string "{JPN}はなします そうすると とまります\pほかの ページも よみますか?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "{JPN}マッハじてんしゃは スピードが でますが\n"
	.string "{JPN}きゅうに とまれません\p"
	.string "{JPN}カーブを まがるのが\n"
	.string "{JPN}すこし むずかしいです\p"
	.string "{JPN}カーブの すこしまえで\n"
	.string "{JPN}じゅうじキーを はなして\l"
	.string "{JPN}スピードを おとしましょう\pほかの ページも よみますか?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "{JPN}ホウエンちほうには ちいさな\n"
	.string "{JPN}すなの さかが あります\p"
	.string "{JPN}やわらかい すなで ふつうでは\n"
	.string "{JPN}のぼることが できません\p"
	.string "{JPN}でも マッハじてんしゃが あれば\n"
	.string "{JPN}すなの さかを かけのぼれます\p"
	.string "{JPN}ほかの ページも よみますか?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "{JPN}ダートじてんしゃの せつめいしょです\p"
	.string "{JPN}どの ページを よみますか?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "{JPN}のっているときに Bボタンを おすと\n"
	.string "{JPN}まえの タイヤが あがります\p"
	.string "{JPN}まえの タイヤを あげたまま\n"
	.string "{JPN}じゅうじキーで はしれます\p"
	.string "{JPN}この ぎじゅつを ウィリーと\n"
	.string "{JPN}いいます\pほかの ページも よみますか?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "{JPN}Bボタンを おしつづけると\n"
	.string "{JPN}じてんしゃが その ばで\l"
	.string "{JPN}とびはねることが できます\p"
	.string "{JPN}この ぎじゅつを バニーホップと\n"
	.string "{JPN}いいます\pとびはねながら はしることも\nできます\pほかの ページも よみますか?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "{JPN}Bボタンと じゅうじキーを\n"
	.string "{JPN}どうじに おすと ジャンプします\p"
	.string "{JPN}じゅうじキーを よこに おすと\n"
	.string "{JPN}よこに ジャンプします\p"
	.string "{JPN}うしろに おすと ジャンプしながら\n"
	.string "{JPN}むきが かわります\p"
	.string "{JPN}ほかの ページも よみますか?$"

