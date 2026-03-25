.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

LilycoveCity_OnTransition:
	callnative SetTimeBasedEncounters
	setflag FLAG_VISITED_SAFFRON_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_GARBAGEFLAG
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_GymSign::
	msgbox LilycoveCity_Text_GymSign, MSGBOX_SIGN
	end

LilycoveCity_Text_GymSign:
	.string "{JPN}ハイパートレーニングジム.\p"
	.string "{JPN}ポケモンのかのうせいを\n"
	.string "{JPN}かんたんにさいだいげん!$"

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_GARBAGEFLAG
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "{JPN}ハルカ: あ {PLAYER}くん?\n"
	.string "{JPN}おかいものにきたの?\p"
	.string "{JPN}わたし にんぎょうとポスターを\n"
	.string "{JPN}たくさんかっちゃった.\p"
	.string "{JPN}もちろん ポケモンもたくさん\n"
	.string "{JPN}つかまえて ちゃんとそだてて\l"
	.string "{JPN}るのよ.\p"
	.string "{JPN}でも {PLAYER}くんが ちゃんと\n"
	.string "{JPN}ポケモンをそだててるか\l"
	.string "{JPN}しんぱいなの.\p"
	.string "{JPN}しょうぶしよ! {PLAYER}くんの\nポケモンをみせてよ!$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "{JPN}ハルカ: あら どうして? {PLAYER}くん ポケモンを\n"
	.string "{JPN}そだててないの?\p"
	.string "{JPN}トレーナーとしては\n"
	.string "{JPN}ちょっとだめね...$"
LilycoveCity_Text_MayBattleMe:
	.string "{JPN}ハルカ: さあ しょうぶしよ!\n"
	.string "{JPN}あなたのポケモンをみせて!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "{JPN}ハルカ: わたしがそだてたポケモンは\n"
	.string "{JPN}{PLAYER}くんのポケモンには\lまけないわよ!$"

LilycoveCity_Text_MayDefeat:
	.string "{JPN}... ... ... ... ... ... ... ...\p"
	.string "{JPN}103ばんどうろで あなたと\n"
	.string "{JPN}たたかったこと おぼえてるの\p"
	.string "{JPN}{PLAYER}くん.\p"
	.string "{JPN}あのたたかいが きっかけで\n{PLAYER}くんは つよくなったのね?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "{JPN}ハルカ: もうすぐミシロタウンに\n"
	.string "{JPN}かえろうとおもってるの.\p"
	.string "{JPN}ポケモンもそれなりにつかまえて\n"
	.string "{JPN}ポケモンずかんもじゅんちょう\l"
	.string "{JPN}だから パパにみせにかえるのよ.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{JPN}{PLAYER}くんは どうするの?\p"
	.string "{JPN}ジムバッジをぜんぶあつめて\n"
	.string "{JPN}ポケモンリーグにちょうせんする?\p"
	.string "{JPN}{PLAYER}くんがバッジあつめを\n"
	.string "{JPN}してるあいだ わたしは\l"
	.string "{JPN}ポケモンずかんをがんばるわ.\l"
	.string "{JPN}あなたよりさきにかんせいさせる!\pじゃあね!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{JPN}{PLAYER}くんは どうするの?\n"
	.string "{JPN}ポケモンリーグにちょうせんする?\p"
	.string "{JPN}それとも ポケモンずかんを\n"
	.string "{JPN}かんせいさせる?\p"
	.string "{JPN}しょうぶではまけたけど\n"
	.string "{JPN}ポケモンずかんはわたしが\l"
	.string "{JPN}さきにかんせいさせるからね!\p"
	.string "{JPN}じゃあね!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{JPN}{PLAYER}くんは どうするの?\n"
	.string "{JPN}バトルフロンティアにちょうせん?\p"
	.string "{JPN}それとも ポケモンずかんを\n"
	.string "{JPN}かんせいさせる?\p"
	.string "{JPN}しょうぶではまけたけど\n"
	.string "{JPN}ポケモンずかんはわたしが\l"
	.string "{JPN}さきにかんせいさせるからね!\p"
	.string "{JPN}じゃあね!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "{JPN}ユウキ: おお {PLAYER}じゃないか.\p"
	.string "{JPN}オヤジのおつかいでね.\n"
	.string "{JPN}べつににんぎょうはかわないよ.\p"
	.string "{JPN}それはそうと ひさしぶりだな.\p"
	.string "{JPN}どっちがポケモンをうまく\n"
	.string "{JPN}そだてたか しょうぶしないか?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "{JPN}ユウキ: どうした?\n"
	.string "{JPN}じしんがないのか?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "{JPN}ユウキ: どっちがポケモンを\n"
	.string "{JPN}うまくそだてたか しょうぶしないか?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "{JPN}ユウキ: でも きみには\n"
	.string "{JPN}まけないぞ {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "{JPN}ふん...\n"
	.string "{JPN}ずいぶん そだてたじゃないか\p"
	.string "{JPN}ちょっと しゃくだな...\n"
	.string "{JPN}ぼくのほうが トレーナーとして\lさきに はじめたのに...$"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "{JPN}ユウキ: ぼくは...\n"
	.string "{JPN}ミシロタウンに かえるつもりだ\p"
	.string "{JPN}とうちゃんの ポケモンずかんの\n"
	.string "{JPN}てつだいを しているんだ\l"
	.string "{JPN}なかなか できてきたから\lみせに いかなくちゃ$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{JPN}{PLAYER}は どうするんだ?\p"
	.string "{JPN}ジムバッジを ぜんぶ あつめて\n"
	.string "{JPN}ポケモンリーグに ちょうせん?\p"
	.string "{JPN}ぼくも そうしようかな...\p"
	.string "{JPN}まあ がんばれよ!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{JPN}{PLAYER} きみはどうするんだ?\n"
	.string "{JPN}そのつよさなら ポケモンリーグに\l"
	.string "{JPN}ちょうせんするのか?\p"
	.string "{JPN}へっ おれだって ポケモンを\n"
	.string "{JPN}もうちょっときたえれば\l"
	.string "{JPN}{PLAYER}よりつよくなるさ.\p"
	.string "{JPN}まあ がんばれよ!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{JPN}{PLAYER} きみはどうするんだ?\n"
	.string "{JPN}バトルフロンティアにちょうせん?\p"
	.string "{JPN}それともポケモンずかんを\n"
	.string "{JPN}かんせいさせるのか?\p"
	.string "{JPN}そのつよさなら\n"
	.string "{JPN}バトルフロンティアを\l"
	.string "{JPN}かんがえてもいいんじゃないか.\p"
	.string "{JPN}へっ おれだってポケモンを\n"
	.string "{JPN}もうちょっときたえれば\l"
	.string "{JPN}{PLAYER}よりつよくなるさ.\p"
	.string "{JPN}おれもバトルフロンティアに\n"
	.string "{JPN}いってみようかな.\pまあ がんばれよ!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "{JPN}ふふふ...\p"
	.string "{JPN}きょうも ひみつのアジトに\n"
	.string "{JPN}ぶっしんを はこんだぜ...\p"
	.string "{JPN}だ だれだ おまえは!?\n"
	.string "{JPN}ひとりごとを いってただけだ!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "{JPN}おれは ただの したっぱだから\n"
	.string "{JPN}ボスが なにを かんがえているか\l"
	.string "{JPN}しらないけど...\p"
	.string "{JPN}アクアだんの いちいんだから\n"
	.string "{JPN}おおきな しごとが できるぞ!\p"
	.string "{JPN}だ だれだ おまえは!?\nひとりごとを いってただけだ!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "{JPN}おい きみ!\p"
	.string "{JPN}いりえのほらあなには\n"
	.string "{JPN}ちかづいちゃだめだ!\p"
	.string "{JPN}なぜって? りゆうなんていらない!\nおとながいってるんだから\lいうことをきけ!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "{JPN}このせかいぜんぶが\n"
	.string "{JPN}アクアだんのものになったら\l"
	.string "{JPN}ポケモンたちにとっても\lしあわせなせかいになるだろうな.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "{JPN}それ! ホエルコ!\n"
	.string "{JPN}みずのなかからとびだせ!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "{JPN}は? なにかよう?\p"
	.string "{JPN}おれたちのくんれんの\n"
	.string "{JPN}じゃまになるから\lどっかいってくれる?$"

LilycoveCity_Text_ContestHallInTown:
	.string "{JPN}このまちには\n"
	.string "{JPN}ポケモンコンテストかいじょうが\l"
	.string "{JPN}あるんだ.\p"
	.string "{JPN}つまり ぜんこくから\n"
	.string "{JPN}よくそだったポケモンが\lやってくるってことだ!\pこころがおどるなあ!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "{JPN}まちのはしっこのいりえにある\n"
	.string "{JPN}あやしいほらあな みたことある?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "{JPN}コンテストにでるために\n"
	.string "{JPN}ポケモンにあたらしいわざを\l"
	.string "{JPN}おぼえさせるんだ.\p"
	.string "{JPN}ひでんマシンのわざを\nわすれさせるために\lわすれオヤジのところにいくよ.$"

LilycoveCity_Text_ImFromKanto:
	.string "{JPN}わたし カントーちほうから\n"
	.string "{JPN}きました\p"
	.string "{JPN}ホウエンちほうは みずと みどりが\n"
	.string "{JPN}うつくしくて すてきですね\p"
	.string "{JPN}あれ? ちょっと まって...\p"
	.string "{JPN}この ちいきにしか いない\nめずらしい ポケモンが いるかも?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "{JPN}アクアだんがいりえで\n"
	.string "{JPN}ホエルコのくんれんをしてるんだ.\p"
	.string "{JPN}あいつらがじゃまで\n"
	.string "{JPN}ふねをうみにだせないよ!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "{JPN}おい しってるか?\p"
	.string "{JPN}だれかがアクアだんを\n"
	.string "{JPN}おいはらってくれたんだ!\p"
	.string "{JPN}おかげでホエルコがいりえから\n"
	.string "{JPN}いなくなって ふねを\lだせるようになったよ.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "{JPN}うみべの やどやで なみおとを\n"
	.string "{JPN}ききながら のんびり ひるねを\l"
	.string "{JPN}していたら...\p"
	.string "{JPN}だれかに ポケモンを\n"
	.string "{JPN}ぬすまれちゃった!\pはんにんは だれだ?\nアクアだん? アクアだんなのか?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "{JPN}いなくなった ポケモンが...\n"
	.string "{JPN}いつのまにか もどってきてた!$"

LilycoveCity_Text_ImArtDealer:
	.string "{JPN}わたしは びじゅつしょうにん\n"
	.string "{JPN}です\p"
	.string "{JPN}とくに かいがなどの びじゅつひんを\n"
	.string "{JPN}うりかいしています\p"
	.string "{JPN}ここの びじゅつかんには\nすばらしい さくひんが あると\lききました...$"
LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "{JPN}われわれが としをとって\n"
	.string "{JPN}しわだらけに なっても\l"
	.string "{JPN}うみは いつまでも わかく\l"
	.string "{JPN}いのちの かがやきに あふれて\lいるのじゃ...\pふぉほほ ふぉほほほほ...$"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "{JPN}60ねんまえに しゅじんに\n"
	.string "{JPN}ここで プロポーズされました\l"
	.string "{JPN}うみは いまも かわらず\l"
	.string "{JPN}うつくしいままです\pむふふふ むふふふふふ...$"
LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "{JPN}うん このいりえのへんな\n"
	.string "{JPN}ほらあな しってるかい?\p"
	.string "{JPN}あれはしぜんにできたものだったが\n"
	.string "{JPN}アクアだんのやつらがやってきて\l"
	.string "{JPN}かいぞうしたんだ.\p"
	.string "{JPN}じぶんたちのことを\n"
	.string "{JPN}しぜんあいのアクアだん\l"
	.string "{JPN}なんていってるが!\p"
	.string "{JPN}やってることといってることが\nぜんぜんちがうじゃないか!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "{JPN}いりえの ほらあな...\p"
	.string "{JPN}さいしょは きがつかなかったけど\n"
	.string "{JPN}いまは からっぽね\p"
	.string "{JPN}アクアだんの やつら\n"
	.string "{JPN}もう いなくなったのね$"

LilycoveCity_Text_CitySign:
	.string "{JPN}ミナモシティ\p"
	.string "{JPN}だいちがおわり\n"
	.string "{JPN}うみがはじまるまち$"

LilycoveCity_Text_ContestHallSign:
	.string "{JPN}ポケモン コンテスト ホール\n"
	.string "{JPN}トレーナーの あつまるばしょ!$"

LilycoveCity_Text_MotelSign:
	.string "{JPN}コーブ リリー モーテル\p"
	.string "{JPN}みなとまち リリーコーブの\n"
	.string "{JPN}コーブ リリーを よろしく.$"

LilycoveCity_Text_MuseumSign:
	.string "{JPN}リリーコーブ びじゅつかん\p"
	.string "{JPN}ポケモン めいさくひんの\n"
	.string "{JPN}てんじかい かいさいちゅう!$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "{JPN}リリーコーブ びじゅつかん\p"
	.string "{JPN}{PLAYER}の ポケモンコレクション\n"
	.string "{JPN}てんじかい かいさいちゅう!$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "{JPN}リリーコーブシティ みなと\p"
	.string "{JPN}フェリー だいちょう まるは\n"
	.string "{JPN}カイナシティで けんぞうちゅう.\p"
	.string "{JPN}まもなく うんこう よていです.$"
	.string ""

LilycoveCity_Text_HarborSign:
	.string "{JPN}リリーコーブシティ みなと\p"
	.string "{JPN}フェリー だいちょう まるで\n"
	.string "{JPN}たのしい ふなたびを どうぞ.$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "{JPN}ポケモントレーナー ファンクラブ\p"
	.string "{JPN}かんばんに トレーナーの なまえが\n"
	.string "{JPN}いっぱい かいてある...$"
LilycoveCity_Text_DepartmentStoreSign:
	.string "{JPN}リリーコーブ デパート\p"
	.string "{JPN}すてきな しょうひんと\n"
	.string "{JPN}ときめきが いっぱい!\p"
	.string "{JPN}ほしい ものが きっと\n"
	.string "{JPN}みつかる ばしょです!$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "{JPN}わすれおやじの いえ\p"
	.string "{JPN}いらない ポケモンの わざを\nわすれさせます.$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "{JPN}きみは きのみブレンダーという\n"
	.string "{JPN}マシンを しってるかい?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "{JPN}みんなで きょうりょくして\n"
	.string "{JPN}はやく まわさないと だめなんだ.\p"
	.string "{JPN}はやく まわせば まわすほど\n"
	.string "{JPN}いい {POKEBLOCK}が つくれるらしいよ.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "{JPN}それは {POKEBLOCK}という\n"
	.string "{JPN}おかしを つくる マシンなんだ.\p"
	.string "{JPN}いい {POKEBLOCK}を ポケモンに あげると\n"
	.string "{JPN}コンディションが すごく よくなるよ.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "{JPN}うみの どこかに とうが\n"
	.string "{JPN}あるって きいた ことが あるよ.\n"
	.string "{JPN}そらのはしらって いうんだって.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "{JPN}131ばんすいどうの あたりに\n"
	.string "{JPN}たかい とうを みかけたんだ\p"
	.string "{JPN}あれは もしかして...?$"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "{JPN}わたしたち しんこんりょこうで\n"
	.string "{JPN}ここに きたばかりなの.\p"
	.string "{JPN}たまたま そらの たかい ところを\n"
	.string "{JPN}ドラゴンタイプの ポケモンが\n"
	.string "{JPN}とんでるのを みたのよ.\p"
	.string "{JPN}ホウエンちほうには そんな\nかっこいい ポケモンが すんでるの?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "{JPN}しんこんりょこうで できるだけ\n"
	.string "{JPN}たくさん めずらしい ポケモンを\n"
	.string "{JPN}みる やくそくを したんです.\p"
	.string "{JPN}ついて すぐに めずらしい\n"
	.string "{JPN}ポケモンが みれて うれしかった!\pほんとうに しあわせです!$"
