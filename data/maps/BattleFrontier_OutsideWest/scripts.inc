.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	callnative SetTimeBasedEncounters
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleFrontierOutsideWest_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
	waitstate
	release
	end

BattleFrontier_OutsideWest_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontierOutsideWest_Text_SailorReturn:
	.string "{JPN}クチバシティに もどりますか?$"

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer::
	msgbox BattleFrontier_OutsideWest_Text_Reparations, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer2::
	msgbox BattleFrontier_OutsideWest_Text_Reparations2, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer3::
	msgbox BattleFrontier_OutsideWest_Text_Reparations3, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer4::
	msgbox BattleFrontier_OutsideWest_Text_Reparations4, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman_Milotic::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILOTIC, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideWest_Text_Milotic, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "{JPN}ここは バトルドーム!\n"
	.string "{JPN}むてきの スーパースターへの みち!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "{JPN}ここは バトルファクトリー!\n"
	.string "{JPN}さいきょうの ポケモンを さがせ!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "{JPN}ここは バトルパイク!\n"
	.string "{JPN}3つの みちから ひとつを えらべ!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "{JPN}ここは バトルタワーです.\p"
	.string "{JPN}トレーナーたちが さいこうに\n"
	.string "{JPN}そだてた ポケモンで\lトーナメントを おこないます.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "{JPN}こんにちは ふねに のられますか?\n"
	.string "{JPN}ふなのりけんを みせて ください.$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{JPN}{PLAYER}は チケットを\n"
	.string "{JPN}もっていない...\p"
	.string "{JPN}もうしわけございません.\p"
	.string "{JPN}ふねに のるには チケットが\nひつようです.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{JPN}{PLAYER}は ふなのりけんを みせた!\p"
	.string "{JPN}かんぺき! これで だいじょうぶ!\p"
	.string "{JPN}どちらに いかれますか?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "{JPN}カイナシティ ですね!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "{JPN}ミナモシティ ですね!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "{JPN}また いつでも ごりようください!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "{JPN}ふねに のって しゅっぱつを\n"
	.string "{JPN}おまち ください.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "{JPN}では どちらに いかれますか?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "{JPN}ぼくは ともだちの なかで\n"
	.string "{JPN}いちばん つよいんだ.\l"
	.string "{JPN}でも ここでは...\lやくに たたない!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "{JPN}バトルタワーに いきたいんだけど\n"
	.string "{JPN}バトルフロンティアの ちずを\l"
	.string "{JPN}もってるのに みつからない.\p"
	.string "{JPN}ここは ひろすぎるよ!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "{JPN}ここに ついたら すぐに\n"
	.string "{JPN}チャレンジしたかったんだ.\p"
	.string "{JPN}でも とちゅうで\n"
	.string "{JPN}ふなよいしちゃって...\nうええええ...$"
BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "{JPN}だれでも ここに これる\n"
	.string "{JPN}ってわけじゃ ないんだよ?\p"
	.string "{JPN}つよいと みとめられた\n"
	.string "{JPN}トレーナーだけが つれてこられる.\p"
	.string "{JPN}だから おおくの トレーナーは\n"
	.string "{JPN}バトルフロンティアを しらない.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "{JPN}おい あにき...\p"
	.string "{JPN}ポケモンを もってなくても\n"
	.string "{JPN}チャレンジできるのかな?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "{JPN}ええと...\n"
	.string "{JPN}だいじょうぶだとおもうよ.\p"
	.string "{JPN}たぶん...\p"
	.string "{JPN}でも あの こわい おおきな\n"
	.string "{JPN}ひとが いってたろ?\nポケモンを かしてやる!って$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "{JPN}あれが バトルファクトリーね.\n"
	.string "{JPN}つよい ポケモンを かりられるの.\p"
	.string "{JPN}でも きになるのよね.\n"
	.string "{JPN}だれが あの ポケモンを そだててるの?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "{JPN}バトルパイクは セビパーが\n"
	.string "{JPN}いるから こわいよ...\p"
	.string "{JPN}で でも はるばる きたから\n"
	.string "{JPN}ぜんぶ せいはするんだ!\n"
	.string "{JPN}...ぶるぶる...$"
BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "{JPN}じゃんけんしよう!\n"
	.string "{JPN}じゃんけんぽん!\p"
	.string "{JPN}... ... ... ... ... ...$"
BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "{JPN}やった! かった!\n"
	.string "{JPN}バトルパイクに ちょうせんするわ!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "{JPN}あーあ...\n"
	.string "{JPN}まけちゃった.\p"
	.string "{JPN}きょうは ついてないな.\n"
	.string "{JPN}バトルパイクの チャレンジは\l"
	.string "{JPN}あしたに しよう.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "{JPN}なぜか わからないけど\n"
	.string "{JPN}バトルより つりを えらぶのは\l"
	.string "{JPN}ぼくだけだとおもうんだ.\p"
	.string "{JPN}え? ここでは つれない?\n"
	.string "{JPN}がっかりだなあ...$"
BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "{JPN}きょうは なにがあっても\n"
	.string "{JPN}シンボルを とるまで\lたたかいつづけるぞ.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "{JPN}おや? バトルドームに\n"
	.string "{JPN}ちょうせんしに いくのかい?\p"
	.string "{JPN}おたがい がんばって\n"
	.string "{JPN}いつか たたかおう.$"
	.string ""

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "{JPN}おじいちゃん こっちよ!\n"
	.string "{JPN}バトルドームは ここ!\l"
	.string "{JPN}がんばって おじいちゃん!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "{JPN}ああ ここが バトルドームじゃな?\n"
	.string "{JPN}しんし なんかに まけんぞ!\p"
	.string "{JPN}しかし いりぐちは どこじゃ?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "{JPN}ここには すこしまえまで\n"
	.string "{JPN}なにも なかったのに.\p"
	.string "{JPN}でも いまは みてよ この りっぱさ!\n"
	.string "{JPN}かあさんを つれてこよう.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "{JPN}やっと バトルフロンティアに\n"
	.string "{JPN}ついたぞ!\p"
	.string "{JPN}みためも じつりょくも\n"
	.string "{JPN}ちゅうもくの まとだ!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "{JPN}むしゃむしゃ...\p"
	.string "{JPN}この ひろばは つよいひとで\n"
	.string "{JPN}いっぱいだね.\p"
	.string "{JPN}むしゃむしゃ...$"
BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "{JPN}ばりばり むしゃ...\p"
	.string "{JPN}さっき バトルパイクで\n"
	.string "{JPN}ねえちゃんに あったんだ.\p"
	.string "{JPN}すごく おこりっぽい\n"
	.string "{JPN}こわい めをしてた.\p"
	.string "{JPN}ばりばり むしゃ...\p"
	.string "{JPN}ねえちゃんが おこって\n"
	.string "{JPN}たべるのを やめなさい!\n"
	.string "{JPN}って ぼこぼこに された.\n"
	.string "{JPN}ほんとうに こわかったよ.\p"
	.string "{JPN}ばりばり むしゃ...$"
BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "{JPN}はあ? なにを いってるのよ!\n"
	.string "{JPN}それって なんでもないじゃない!\p"
	.string "{JPN}わたしが おうえんしたとき\n"
	.string "{JPN}めが あって スパークしたのよ!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "{JPN}なんですって?!\n"
	.string "{JPN}ぶーっ!\p"
	.string "{JPN}それって わたしの となりに\n"
	.string "{JPN}すわってたから でしょ!\p"
	.string "{JPN}ドームエースが こっちを\n"
	.string "{JPN}みたのは わたしの おうえんが\lうるさかったからよ!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "{JPN}あー うるさい!\n"
	.string "{JPN}しずかに しなさい!\n"
	.string "{JPN}にわか ファンは ジムリーダーでも\n"
	.string "{JPN}おうえん してなさい!\p"
	.string "{JPN}ドームエースは わたしのもの!\n"
	.string "{JPN}わたしだけの アイドルよ!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "{JPN}あそこで けんかしてる\n"
	.string "{JPN}ひとたち...\p"
	.string "{JPN}しんじられないけど まえは\n"
	.string "{JPN}トレーナーで つよかったんだ.\p"
	.string "{JPN}すごく つよくて ゆうめいだった.\p"
	.string "{JPN}でも トーナメントで ある\n"
	.string "{JPN}トレーナーに ぼろまけした.\p"
	.string "{JPN}あまりにも ひどくまけて\n"
	.string "{JPN}そのトレーナーの ファンになった.\p"
	.string "{JPN}いまは ただの ファンで\n"
	.string "{JPN}まいにち バトルドームで\l"
	.string "{JPN}おうえんしてるんだ.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "{JPN}すうしゅうかんまえまで\n"
	.string "{JPN}バトルフロンティアに\n"
	.string "{JPN}ほらあながあったんだ!\p"
	.string "{JPN}なかには しっぽのながい\n"
	.string "{JPN}めずらしい ポケモンがいた!\p"
	.string "{JPN}でも さいきん きゅうに\n"
	.string "{JPN}ほらあなが くずれちゃって...\p"
	.string "{JPN}あのかわいそうな いきものたちは\nどうなったんだろう...$"
BattleFrontier_OutsideWest_Text_Reparations:
    .string "{JPN}きをつけて!\p"
	.string "{JPN}バトルフロンティアの したの\n"
    .string "{JPN}どうくつが さっき くずれたんだ.\p"
	.string "{JPN}もういちど おこらないように\n"
    .string "{JPN}こうぞうを ほきょうしてるよ.\n"
	.string "{JPN}しゅうりが おわるまで もくせいの\n"
    .string "{JPN}はしを つかって うごいてくれ.$"

BattleFrontier_OutsideWest_Text_Reparations2:
    .string "{JPN}あしもとに きをつけて!\p"
	.string "{JPN}どうくつの ほうかいで できた\n"
    .string "{JPN}ひがいを なおしてるところだ.\p"
	.string "{JPN}この もくせいの はしは\n"
    .string "{JPN}いちじてきだから ちゅういしてね!$"

BattleFrontier_OutsideWest_Text_Reparations3:
    .string "{JPN}うう... きょうも しゅうり.\n"
	.string "{JPN}ほらあなが くずれて たいへんだ.\p"
    .string "{JPN}しごとが おわるまで\n"
	.string "{JPN}この ささえが もってくれれば\nいいけど.$"

BattleFrontier_OutsideWest_Text_Reparations4:
    .string "{JPN}この ワンリキーと カイリキーは\n"
	.string "{JPN}しゅうりの おおきな たすけだよ!\p"
    .string "{JPN}かれらが いなかったら ほうかい\n"
	.string "{JPN}あとの さいけんちくは\nえいえんに かかっただろうね!$"

BattleFrontier_OutsideWest_Text_Milotic:
	.string "{JPN}ミロカロス: みろーっ!$"
