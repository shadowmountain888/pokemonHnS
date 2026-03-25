BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "{JPN}なんだよ きみは?\p"
	.string "{JPN}みてのとおり いそがしいんだ\n"
	.string "{JPN}ようじは あとに してくれよ$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "{JPN}ん?\n"
	.string "{JPN}きみは つよそうな トレーナーだな\p"
	.string "{JPN}へへへ...\n"
	.string "{JPN}ちょっと はなしが あるんだ\p"
	.string "{JPN}ここに なかまが あつまって\n"
	.string "{JPN}バトルフロンティアで ちょっとした\l"
	.string "{JPN}ゲームを やってるんだよ\p"
	.string "{JPN}ルールは かんたんさ\p"
	.string "{JPN}まず バトルフロンティアの\n"
	.string "{JPN}しせつを ひとつ えらぶ\p"
	.string "{JPN}それから みんなで べつべつの\n"
	.string "{JPN}トレーナーを えらんで その\l"
	.string "{JPN}しせつに ちょうせんしてる やつに\l"
	.string "{JPN}バトルポイントを かける\p"
	.string "{JPN}いちばん せいせきの いい\n"
	.string "{JPN}トレーナーに かけた やつが\l"
	.string "{JPN}プールの バトルポイントを\l"
	.string "{JPN}ぜんぶ もらえる しくみだ\pかんたんだろ?\nそれで だな...$"
BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルタワーの シングルバトル\l"
	.string "{JPN}ルームに ちょうせんする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルタワーの ダブルバトル\l"
	.string "{JPN}ルームに ちょうせんする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルタワーの マルチバトル\l"
	.string "{JPN}ルームに ちょうせんする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルドームの シングルバトル\l"
	.string "{JPN}トーナメントに さんかする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルドームの ダブルバトル\l"
	.string "{JPN}トーナメントに さんかする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルファクトリーの バトル\l"
	.string "{JPN}スワップ シングルトーナメントに\p"
	.string "{JPN}さんかする トレーナーだ\n"
	.string "{JPN}でも いままで そんな かちめの\lある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルファクトリーの バトル\l"
	.string "{JPN}スワップ ダブルトーナメントに\p"
	.string "{JPN}さんかする トレーナーだ\n"
	.string "{JPN}でも いままで そんな かちめの\lある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルパレスの シングルバトル\l"
	.string "{JPN}ホールに ちょうせんする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルパレスの ダブルバトル\l"
	.string "{JPN}ホールに ちょうせんする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルアリーナの セット KO\l"
	.string "{JPN}トーナメントに さんかする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルパイクの バトルチョイスに\l"
	.string "{JPN}さんかする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "{JPN}おれが さがしてるのは\n"
	.string "{JPN}バトルピラミッドの バトルクエストに\l"
	.string "{JPN}さんかする トレーナーだ\p"
	.string "{JPN}でも いままで そんな かちめの\n"
	.string "{JPN}ある トレーナーには であってない$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "{JPN}きみにも とくが あるように するよ\n"
	.string "{JPN}どうだい?\l"
	.string "{JPN}おれの かわりに そのイベントに\pでてくれないかい?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "{JPN}よし かんぺきだ\n"
	.string "{JPN}それで... きみの バトルポイント\l"
	.string "{JPN}ちょっと かしてくれないか?\p"
	.string "{JPN}しんぱい するなよ あとで\n"
	.string "{JPN}かならず おれいは するから$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "{JPN}よし よし!\n"
	.string "{JPN}いくら かしてくれる?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "{JPN}だめだめだめ!\n"
	.string "{JPN}バトルポイントが たりないよ!\p"
	.string "{JPN}ふざけて みんなの じかんを\n"
	.string "{JPN}むだにするのは やめてくれよ!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "{JPN}へへへ! ありがとう!\n"
	.string "{JPN}さあ いってこい!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "{JPN}バトルタワーの シングルバトル\n"
	.string "{JPN}ルームに いそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\l"
	.string "{JPN}おたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "{JPN}バトルタワーの ダブルバトル\n"
	.string "{JPN}ルームに いそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\l"
	.string "{JPN}おたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "{JPN}バトルタワーの マルチバトル\n"
	.string "{JPN}ルームに いそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\l"
	.string "{JPN}おたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "{JPN}バトルドームの シングルバトル\n"
	.string "{JPN}トーナメントに いそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\l"
	.string "{JPN}おたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "{JPN}バトルドームの ダブルバトル\n"
	.string "{JPN}トーナメントに いそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\l"
	.string "{JPN}おたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "{JPN}バトルファクトリーの バトル\n"
	.string "{JPN}スワップ シングルトーナメントに\l"
	.string "{JPN}iそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\lおたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "{JPN}バトルファクトリーの バトル\n"
	.string "{JPN}スワップ ダブルトーナメントに\l"
	.string "{JPN}iそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\lおたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "{JPN}バトルパレスの シングルバトル\n"
	.string "{JPN}ホールに いそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\l"
	.string "{JPN}おたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "{JPN}バトルパレスの ダブルバトル\n"
	.string "{JPN}ホールに いそいで いくんだ!\p"
	.string "{JPN}ぜったい かたなきゃ だめだぞ!\n"
	.string "{JPN}チャンスを ふいにするなよ!\l"
	.string "{JPN}おたがいの みらいが かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "{JPN}バトルアリーナの\n"
	.string "{JPN}セットKOトーナメントに\l"
	.string "{JPN}いそいで!\p"
	.string "{JPN}ぜったいに かたなきゃ\n"
	.string "{JPN}だめなの!\lチャンスを のがさないで!\pわたしたち ふたりの\nみらいが かかってるの!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "{JPN}バトルパイクの\n"
	.string "{JPN}バトルチョイスに\l"
	.string "{JPN}いそいで!\p"
	.string "{JPN}ぜったいに かたなきゃ\n"
	.string "{JPN}だめなの!\lチャンスを のがさないで!\pわたしたち ふたりの\nみらいが かかってるの!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "{JPN}バトルピラミッドの\n"
	.string "{JPN}バトルクエストに\l"
	.string "{JPN}いそいで!\p"
	.string "{JPN}ぜったいに かたなきゃ\n"
	.string "{JPN}だめなの!\lチャンスを のがさないで!\pわたしたち ふたりの\nみらいが かかってるの!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "{JPN}あ きみか...\n"
	.string "{JPN}いい ちょうせんだったな...\p"
	.string "{JPN}ざんねんだが きみの\n"
	.string "{JPN}バトルポイントは かえせない...\p"
	.string "{JPN}これも べんきょうだと おもって\n"
	.string "{JPN}つぎは がんばろうぜ!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "{JPN}あー!\n"
	.string "{JPN}こんにちは チャンピオン!\p"
	.string "{JPN}やっぱり できると\n"
	.string "{JPN}おもってたわ!\l"
	.string "{JPN}ふたりとも だいしょうり!\p"
	.string "{JPN}バトルポイントを\n"
	.string "{JPN}おかえしするわね\lもちろん おまけつきで!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{JPN}{PLAYER}は\n"
	.string "{JPN}{STR_VAR_1}バトルポイントを\lてにいれた!$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "{JPN}また ちょうせんするときは\n"
	.string "{JPN}わたしのことも\lおもいだしてね!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "{JPN}きょうみないの?!\n"
	.string "{JPN}そんなに びびらないで\lちょうせんしなさいよ!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "{JPN}あ...$"
BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "{JPN}また まちがった トレーナーに\n"
	.string "{JPN}かけちまった!\p"
	.string "{JPN}ほかの みんなみたいに ふつうに\nバトルした ほうが いいのかな...$"
BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "{JPN}あの トレーナー...\p"
	.string "{JPN}うまいけど きんちょうしやすくて\n"
	.string "{JPN}バトルドームでは いきのこれないな...$"
BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "{JPN}きゃはは!\n"
	.string "{JPN}かちめを みれば\lわかるのよ!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "{JPN}あの トレーナーたち...\n"
	.string "{JPN}なにを やってるんだ?\l"
	.string "{JPN}ちょうせん すべきだろうに$"
