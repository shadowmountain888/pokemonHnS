SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "{JPN}えーへん!わたしが\n"
	.string "{JPN}ポケモンだいすきクラブの\l"
	.string "{JPN}かいちょうです!\p"
	.string "{JPN}かいちょうですから もちろん\n"
	.string "{JPN}いちばんえらいのです!\p"
	.string "{JPN}ポケモンをそだてることに\n"
	.string "{JPN}かんしては だれにもまけません!\p"
	.string "{JPN}では ポケモンコンテストに\n"
	.string "{JPN}ついてせつめいしましょう.\p"
	.string "{JPN}ポケモンをせかいにひろく\n"
	.string "{JPN}みせるイベントなのです!\p"
	.string "{JPN}しかし とおくのまちで\n"
	.string "{JPN}ひらかれるので ひんぱんには\l"
	.string "{JPN}さんかできません.\p"
	.string "{JPN}そのため ここにあつまって\nポケモンをじまんしあったり \lほかのひとのをみせてもらったり\lしているのです.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "{JPN}ポケモンコンテストに\n"
	.string "{JPN}さんかしたトレーナーの\l"
	.string "{JPN}ポケモン...\lそれをみてみたいものじゃ$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "{JPN}おお! きみはポケモン\n"
	.string "{JPN}コンテストにさんかした\l"
	.string "{JPN}ことがあるのじゃな!\p"
	.string "{JPN}ぜひとも! きみがそだてた\n"
	.string "{JPN}ポケモンをしらべさせて\l"
	.string "{JPN}くれんか!\p"
	.string "{JPN}ほかのトレーナーがそだてた\n"
	.string "{JPN}ポケモンをみるのが\l"
	.string "{JPN}なによりもたのしいのじゃ!\p"
	.string "{JPN}あいじょうこめてそだてられた\n"
	.string "{JPN}ポケモンのしあわせそうな\l"
	.string "{JPN}ひょうじょう...\p"
	.string "{JPN}そのポケモンをそだてあげた\n"
	.string "{JPN}トレーナーのやさしいめ...\p"
	.string "{JPN}かんがえるだけで むねが\n"
	.string "{JPN}いっぱいになってしまうのう!\pおお! しつれいした!\nながながとはなしてしまって!\pさあ! きみのポケモンが\nどれほどせいちょうしたか\lみせてくれ!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "{JPN}あなたのポケモンの\n"
	.string "{JPN}ちょうしはどうですか?\lしんささせてください.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "{JPN}ふむふむ...\n"
	.string "{JPN}なるほどのう...$"
SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "{JPN}うーむ... わるくはないが\n"
	.string "{JPN}よいともいえんのう...\p"
	.string "{JPN}きみトレーナーが もっと\n"
	.string "{JPN}どりょくしてそだてるのじゃ!\p"
	.string "{JPN}たとえば ポロックを\n"
	.string "{JPN}もっとあげてみては\lどうじゃろう?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "{JPN}おお これは...\p"
	.string "{JPN}きみのポケモンは よくそだって\n"
	.string "{JPN}おるので ほうびをあげよう\l"
	.string "{JPN}とおもったのじゃが...\p"
	.string "{JPN}ざんねん バッグにスペースが\nないようじゃな$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "{JPN}あなたの{STR_VAR_1}は\n"
	.string "{JPN}じつにすばらしくそだって\l"
	.string "{JPN}いますね!\l"
	.string "{JPN}りっぱなポケモンです!\p"
	.string "{JPN}ですが!これをつかえば\nもっとよくそだつでしょう!\lそのとおりです!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "{JPN}ポケモンにそのあかいスカーフを\n"
	.string "{JPN}もたせてください.\p"
	.string "{JPN}そのポケモンのかっこよさを\nみんながにんしきするでしょう!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "{JPN}ポケモンにそのあおいスカーフを\n"
	.string "{JPN}もたせてください.\p"
	.string "{JPN}うつくしさがいまより\nずっときわだつでしょう!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "{JPN}ポケモンにそのピンクのスカーフを\n"
	.string "{JPN}もたせてください.\p"
	.string "{JPN}ポケモンのかわいらしさが\nもっとひきだされるでしょう!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "{JPN}ポケモンにそのみどりのスカーフを\n"
	.string "{JPN}もたせてください.\p"
	.string "{JPN}ポケモンのかしこさが\nこうじょうするでしょう!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "{JPN}ポケモンにそのきいろいスカーフを\n"
	.string "{JPN}もたせてください.\p"
	.string "{JPN}ポケモンのたくましさが\nずっとアップするでしょう!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "{JPN}もうしわけありませんが \n"
	.string "{JPN}あげるものがありません!\l"
	.string "{JPN}なにもないのです!\p"
	.string "{JPN}なんといっても あなたは\n"
	.string "{JPN}どうぐにたよらずに\lポケモンをそだてるさいのうに\lめぐまれているのですから!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "{JPN}トレーナーをあいしている\n"
	.string "{JPN}ポケモンをみるのがだいすきです.\p"
	.string "{JPN}ポケモンはトレーナーのきもちに\n"
	.string "{JPN}とてもびんかんなのです.\p"
	.string "{JPN}ポケモンをあいじょうをもって\n"
	.string "{JPN}たいせつにそだてれば \l"
	.string "{JPN}ポケモンもあなたをあいするように\l"
	.string "{JPN}なります.\pポケモンがあなたをあいするように\nなったら ぜひみせにきてください.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "{JPN}あなたのポケモンは\n"
	.string "{JPN}ほんとうにあなたをしたって\l"
	.string "{JPN}いますね.\pあなたのようなやさしい\nトレーナーに だいすきクラブ\lからプレゼントです!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "{JPN}ポケモンはトレーナーのきもちに\n"
	.string "{JPN}とてもびんかんなのです.\p"
	.string "{JPN}ポケモンをあいじょうをもって\n"
	.string "{JPN}たいせつにそだてれば \lポケモンもあなたをあいするように\lなります.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "{JPN}ポケモンをたたかいで\n"
	.string "{JPN}ひんぱんにきぜつさせていると \l"
	.string "{JPN}ポケモンはうらみをいだくように\l"
	.string "{JPN}なります.\p"
	.string "{JPN}そのうち トレーナーを\n"
	.string "{JPN}しんらいしなくなるでしょう.\pつまり あなたのことを\nけっしてすきになりません.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "{JPN}ポケモンはどうぐをつかわれるのを\n"
	.string "{JPN}よろこぶのでしょうか?\p"
	.string "{JPN}わたしのポケモンは\n"
	.string "{JPN}タウリンをあげたとき\lとてもよろこんでいました.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "{JPN}エネコ: ふにゃあああ...$"
SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "{JPN}ジグザグマ: キュウウ...$"
SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "{JPN}マリルリ:マリマリ?$"

