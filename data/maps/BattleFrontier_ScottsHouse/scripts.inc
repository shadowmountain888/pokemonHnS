.set LOCALID_SCOTT, 1

BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "{JPN}エニシダ: やあ こんにちは!\n"
	.string "{JPN}ようこそ!\p"
	.string "{JPN}へへへ... せまくて\n"
	.string "{JPN}すまないね.\p"
	.string "{JPN}さて {PLAYER}くん \n"
	.string "{JPN}あらためて バトルフロンティア\l"
	.string "{JPN}へ ようこそ!\pこれは ぼくの ゆめが\nかなったんだ.\lながい ながい としつきを\lかけて ついに かたちに\lできたんだよ.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "{JPN}ふりかえって みると\n"
	.string "{JPN}ほんとうに ながい\l"
	.string "{JPN}たびだったなあ...\p"
	.string "{JPN}つよい トレーナーを さがす\n"
	.string "{JPN}たびに ひとりで いえを\l"
	.string "{JPN}でたんだ.\pこれを げんじつに するのに\nどれだけの どりょくと\lじかんが かかったか\lだれも そうぞう できない\lだろうね.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "{JPN}でも それは むかしの はなし.\n"
	.string "{JPN}いまさら きにしても しかたない!\p"
	.string "{JPN}きみには ここで こころゆくまで\n"
	.string "{JPN}バトルを たのしんでほしいんだ.\p"
	.string "{JPN}{PLAYER}くん これを もっていって\n"
	.string "{JPN}くれ.おたがい たびで であった\l"
	.string "{JPN}きねんに な.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{JPN}{PLAYER}は\n"
	.string "{JPN}{STR_VAR_1}BP てにいれた!$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "{JPN}エニシダ: バトルポイントは\n"
	.string "{JPN}フロンティアパスで かくにんできる.\p"
	.string "{JPN}バトルフロンティアで かつやく\n"
	.string "{JPN}するほど バトルポイントが\l"
	.string "{JPN}たまっていくぞ.\p"
	.string "{JPN}バトルポイントは アイテムと\n"
	.string "{JPN}こうかんするなど じゆうに\lつかってくれ.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "{JPN}きみの かつやくを きたいしてるぞ!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "{JPN}エニシダ: トレーナーは みんな\n"
	.string "{JPN}それぞれ ちがう じんせいを\l"
	.string "{JPN}あゆんでいる.\p"
	.string "{JPN}でも バトルに なれば\n"
	.string "{JPN}そんなことは かんけいない.\p"
	.string "{JPN}みんな おなじなんだ!\p"
	.string "{JPN}だれもが びょうどうな バトルの\n"
	.string "{JPN}じゅんすいさが すきなんだ.\p"
	.string "{JPN}だから せかいじゅうを まわって\n"
	.string "{JPN}ほんきで バトルする トレーナーを\lさがして ここに よんでるのさ.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "{JPN}エニシダ: フロンティアブレーンに\n"
	.string "{JPN}あったことは あるかい?\p"
	.string "{JPN}もっと いえば シンボルを\n"
	.string "{JPN}てにいれたことは あるか?\p"
	.string "{JPN}フロンティアブレーンたちは\n"
	.string "{JPN}おれが えらんだ さいきょうの\l"
	.string "{JPN}トレーナーたちだ.\p"
	.string "{JPN}でも きみの つよさを みたら\nかれらも おどろくと おもうぞ!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "{JPN}エニシダ: きみは バトルの\n"
	.string "{JPN}くんれんだけじゃ ないよね?\p"
	.string "{JPN}たしか ポケモンずかんの\n"
	.string "{JPN}かんせいも めざしていた\l"
	.string "{JPN}はずだね.\p"
	.string "{JPN}じつはね...\p"
	.string "{JPN}バトルフロンティアの\n"
	.string "{JPN}どこかで やせいの ポケモンに\lであうかも しれないよ...\lふふふ!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "{JPN}エニシダ: バトルフロンティアは\n"
	.string "{JPN}たのしんでいるかい?\p"
	.string "{JPN}...ちょっと まって...\n"
	.string "{JPN}おお!\p"
	.string "{JPN}きみの フロンティアパス!\n"
	.string "{JPN}ぎんの シンボルを\l"
	.string "{JPN}ぜんぶ あつめたんだね!\p"
	.string "{JPN}すばらしいよ!\n"
	.string "{JPN}やっぱり きみは つよいね!\p"
	.string "{JPN}ふつうなら こんなことは\n"
	.string "{JPN}しないんだけど\l"
	.string "{JPN}とくべつな ときだからね!\p"
	.string "{JPN}これを きみに あげよう.\nきっと やくに たてて\lくれるだろう.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "{JPN}エニシダ: バトルフロンティアの\n"
	.string "{JPN}すべてを たのしんでいる\l"
	.string "{JPN}かな?\p"
	.string "{JPN}...ちょっと まって...\n"
	.string "{JPN}ああ しんじられない!\p"
	.string "{JPN}きみの フロンティアパス!\n"
	.string "{JPN}きんの シンボルを\l"
	.string "{JPN}ぜんぶ あつめたんだね!\p"
	.string "{JPN}これは すごすぎる!\n"
	.string "{JPN}やっぱり きみは\l"
	.string "{JPN}すばらしいよ!\p"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}{PLAYER} これを\nうけとって くれ!\pぼくの プレゼントの\nかちを きっと\lわかって くれると\lおもうよ!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "{JPN}おれには つよい トレーナーを\n"
	.string "{JPN}みきわめる さいのうが あるんだ.\p"
	.string "{JPN}きみを ここに つれてきて\n"
	.string "{JPN}ほんとうに よかったよ!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "{JPN}きのみぶくろが\n"
	.string "{JPN}いっぱいの ようだな.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "{JPN}エニシダ: おお! きみの うわさを\n"
	.string "{JPN}きいたぞ! バトルタワーでの\l"
	.string "{JPN}かつやく ぶりをな!\p"
	.string "{JPN}50にん いじょうの トレーナーを\n"
	.string "{JPN}れんぱしたって?\pそいつは すげえ!\nこれを うけとってくれ!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "{JPN}エニシダ: おおお! きみの うわさを\n"
	.string "{JPN}きいたぞ! バトルタワーでの\l"
	.string "{JPN}あっとうてきな つよさをな!\p"
	.string "{JPN}100にん いじょうの トレーナーを\n"
	.string "{JPN}れんぱしたって?\pとんでもなく すばらしい!\nぜったい これを もらってくれ!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "{JPN}これからも もっと すごい\n"
	.string "{JPN}かつやくを きたいしてるぞ!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "{JPN}おっと もちものが いっぱいなら\n"
	.string "{JPN}あとで とりに きてくれ.$"

