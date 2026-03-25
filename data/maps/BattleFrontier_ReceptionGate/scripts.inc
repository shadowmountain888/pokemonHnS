.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_VISITED_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "{JPN}はじめてですか?\n"
	.string "{JPN}こちらへどうぞ!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "{JPN}ポケモンバトルの さいぜんせん!\n"
	.string "{JPN}バトルフロンティアへ ようこそ!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "{JPN}はじめてのおきゃくさまには\n"
	.string "{JPN}フロンティアパスを はっこう\l"
	.string "{JPN}しております\p"
	.string "{JPN}バトルフロンティア すべての\n"
	.string "{JPN}しせつで ごりようください\pどうぞ!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{JPN}{PLAYER}は\n"
	.string "{JPN}フロンティアパスを てにいれた!$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{JPN}{PLAYER}は トレーナーカードを\n"
	.string "{JPN}フロンティアパスに セットした!$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "{JPN}バトルフロンティアを\n"
	.string "{JPN}おたのしみください!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "{JPN}???: おや これは?\n"
	.string "{JPN}あたらしいトレーナーかね?$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "{JPN}ガイド: あ! エニシダさん!\n"
	.string "{JPN}おつかれさまです!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "{JPN}わたしは エニシダ いつも\n"
	.string "{JPN}ゆうのうなトレーナーを\l"
	.string "{JPN}さがしているんだ\p"
	.string "{JPN}きみは そのにおいがするね!\n"
	.string "{JPN}なまえを きかせてもらえるかな?\p"
	.string "{JPN}ほう {PLAYER}くんか!\p"
	.string "{JPN}ジョウトから きたのか?\n"
	.string "{JPN}ずいぶん とおくからだね!\p"
	.string "{JPN}ここに きてくれて\n"
	.string "{JPN}ほんとうに うれしいよ!\p"
	.string "{JPN}じかんを かけて\n"
	.string "{JPN}あちこち みてまわってくれ\p"
	.string "{JPN}もちろん バトルの しんずいも\n"
	.string "{JPN}あじわってほしい\p"
	.string "{JPN}わたしの へやも あるから\nじかんが あったら たちよってくれ$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "{JPN}バトルフロンティア かくしせつの\n"
	.string "{JPN}ごあんないを しております$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "{JPN}どちらに ついて しりたいですか?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "{JPN}バトルフロンティアの シンボルとも\n"
	.string "{JPN}いえる きょだいなタワーです\p"
	.string "{JPN}シングル ダブル マルチ\n"
	.string "{JPN}リンクマルチバトルの\l"
	.string "{JPN}4つの バトルルームが あります$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "{JPN}バトルドームは おおきなたまごの\n"
	.string "{JPN}ような かたちをした けんぶつです\p"
	.string "{JPN}バトルトーナメントという\n"
	.string "{JPN}イベントが かいさいされます\p"
	.string "{JPN}バトルトーナメントは\n"
	.string "{JPN}シングルと ダブルバトルの\l"
	.string "{JPN}2つの コースが あります$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "{JPN}バトルパレスは バトルフロンティア\n"
	.string "{JPN}みぎがわにある あかいけんぶつです\p"
	.string "{JPN}シングルと ダブルバトル\n"
	.string "{JPN}2つの バトルホールが あります$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "{JPN}バトルアリーナは\n"
	.string "{JPN}バトルフロンティア ちゅうおう\l"
	.string "{JPN}みぎがわの どうじょうふうけんぶつです\p"
	.string "{JPN}バトルアリーナでは\n"
	.string "{JPN}セットKOトーナメントという\lイベントが おこなわれます$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "{JPN}バトルファクトリーは\n"
	.string "{JPN}いちばん てまえにある\l"
	.string "{JPN}おおきなけんぶつです\p"
	.string "{JPN}バトルスワップという\n"
	.string "{JPN}イベントが かいさいされます\p"
	.string "{JPN}バトルスワップは シングルと\n"
	.string "{JPN}ダブルバトルの 2つのコースが\lあります$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "{JPN}バトルパイクは バトルフロンティア\n"
	.string "{JPN}ちゅうおう ひだりがわの\l"
	.string "{JPN}ポケモンのような かたちのけんぶつです\p"
	.string "{JPN}バトルチョイスという\n"
	.string "{JPN}イベントが かいさいされます$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "{JPN}バトルピラミッドは\n"
	.string "{JPN}きょだいな ピラミッドです\p"
	.string "{JPN}バトルクエストという\n"
	.string "{JPN}イベントが かいさいされます$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "{JPN}ランキングホールは\n"
	.string "{JPN}バトルタワーの ちかくに あります\p"
	.string "{JPN}バトルフロンティアの さまざまな\n"
	.string "{JPN}ちょうせんで のこされた\l"
	.string "{JPN}トレーナーたちの すばらしい\l"
	.string "{JPN}きろくを みることが できます$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "{JPN}こうかんサービスコーナーは\n"
	.string "{JPN}バトルタワーの ちかくに あります\p"
	.string "{JPN}バトルフロンティアで かせいだ\n"
	.string "{JPN}バトルポイントを\l"
	.string "{JPN}すてきな しょうひんと\lこうかんできます$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "{JPN}バトルフロンティア かくしせつの\n"
	.string "{JPN}ちょうせんに きょうつうする\l"
	.string "{JPN}きほんルールを せつめいします$"
	.string ""

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "{JPN}なにに ついて しりたいですか?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "{JPN}バトルフロンティア かくしせつの\n"
	.string "{JPN}ちょうせんには ノーマルと\l"
	.string "{JPN}ハードの 2つのコースが あります$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "{JPN}ノーマルコースが オープンしました!\n"
	.string "{JPN}すべての ポケモンが レベル50に\l"
	.string "{JPN}なります\p"
	.string "{JPN}このコースは バトルフロンティアでの\n"
	.string "{JPN}バトルの にゅうもんレベルです\p"
	.string "{JPN}まずは このコースに\nちょうせんしてみてください$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "{JPN}ハードコースが オープンしました!\n"
	.string "{JPN}すべての ポケモンが レベル50に\l"
	.string "{JPN}なります\p"
	.string "{JPN}このコースは けいけんゆたかな\n"
	.string "{JPN}トレーナーのための\l"
	.string "{JPN}より こうどなちょうせんです\pほんとうの ちょうせんを もとめる\nかたは このコースを おすすめします!$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "{JPN}じつは どんなしゅるいの ポケモンでも\n"
	.string "{JPN}すべての しせつで ちょうせん\l"
	.string "{JPN}できるんです.\p"
	.string "{JPN}ただし タマゴや とくていの\n"
	.string "{JPN}ポケモンは さんか できません.\p"
	.string "{JPN}ちょうせんに ひつような ポケモンの\n"
	.string "{JPN}かずは しせつによって ちがいます.\p"
	.string "{JPN}でも すべての しせつで おなじ\n"
	.string "{JPN}しゅるいの ポケモンを 2ひき いじょう\lつかうことは きんしされています.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "{JPN}バトルフロンティアの しせつで\n"
	.string "{JPN}ちょうせんする ばあい ポケモンは\l"
	.string "{JPN}おなじ どうぐを もたせられません.\p"
	.string "{JPN}ちょうせんに さんかする ポケモン\n"
	.string "{JPN}ぜんぶが ちがう どうぐを もって\l"
	.string "{JPN}いることを かくにんしてください.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "{JPN}わたしが フロンティアパスの\nあんないを いたします.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "{JPN}どちらについて おしりに\nなりたいですか?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "{JPN}バトルフロンティアには 7つの\n"
	.string "{JPN}しせつが あります.\p"
	.string "{JPN}のうりょくを みとめられた\n"
	.string "{JPN}トレーナーは かくしせつから\l"
	.string "{JPN}シンボルを もらえることが あります.\p"
	.string "{JPN}シンボルを かくとくするには\n"
	.string "{JPN}ほかの トレーナーを れんしょうしたり\l"
	.string "{JPN}イベントで なんどもかつ ひつようが\l"
	.string "{JPN}あるかもしれません.\p"
	.string "{JPN}シンボルを かくとくするのは\nかんたんでは ありません.\lがんばって ください!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "{JPN}フロンティアパスに 1かいの\n"
	.string "{JPN}バトルを きろく できます.\p"
	.string "{JPN}ともだちと おこなった バトルを\n"
	.string "{JPN}きろく することが できます.\p"
	.string "{JPN}または バトルパイクと\n"
	.string "{JPN}バトルピラミッドを のぞく\l"
	.string "{JPN}バトルフロンティアで おこなった\l"
	.string "{JPN}バトルを きろく できます.\p"
	.string "{JPN}バトルが おわったあとに\n"
	.string "{JPN}きろくするかどうか えらべます.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "{JPN}バトルポイントは バトルフロンティア\n"
	.string "{JPN}で すばらしい たたかいを した\l"
	.string "{JPN}トレーナーに あたえられる ほうしゅう\l"
	.string "{JPN}です.\p"
	.string "{JPN}バトルポイントは こうかん\n"
	.string "{JPN}サービスコーナーで しょうひんと\lこうかん できます.$"

