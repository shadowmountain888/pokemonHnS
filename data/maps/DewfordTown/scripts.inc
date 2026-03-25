@ Sailing to and from Dewford uses local IDs from different maps
@ e.g. Route 104's sail to Dewford script references local IDs from Dewford's map
@ All of these local IDs are labeled here
.equ LOCALID_BRINEY_DEWFORD, 2
.equ LOCALID_BOAT_DEWFORD, 4

.equ LOCALID_BOAT_R109, 1
.equ LOCALID_BRINEY_R109, 2

.equ LOCALID_BOAT_R104, 7
.equ LOCALID_BRINEY_R104, 8

DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DewfordTown_OnTransition:
	callnative SetTimeBasedEncounters
	setflag FLAG_VISITED_AZALEA_TOWN
	end

DewfordTown_EventScript_Briney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_ReturnToPetalburgPrompt
	message DewfordTown_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_ChoosePetalburg
	case 1, DewfordTown_EventScript_ChooseSlateport
	case 2, DewfordTown_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect
	end

DewfordTown_EventScript_ChoosePetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	release
	end

DewfordTown_EventScript_ChooseSlateport::
	msgbox DewfordTown_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToSlateport
	release
	end

DewfordTown_EventScript_CancelSailSelect::
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_ReturnToPetalburgPrompt::
	msgbox DewfordTown_Text_SetSailBackToPetalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_SailBackToPetalburg
	msgbox DewfordTown_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailBackToPetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail2, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	end

DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	end

DewfordTown_EventScript_GiveOldRod::
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_HowsFishing::
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_FishingExcellent::
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_FishingNotSoGood::
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailToPetalburg::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToPetalburg
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	setvar VAR_GARBAGEVAR, 2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	copyvar VAR_GARBAGEVAR, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_SailToSlateport::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToSlateport
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToSlateport
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatSlateport
	waitmovement 0
	setobjectxyperm LOCALID_BRINEY_R109, 21, 26
	addobject LOCALID_BRINEY_R109
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109, 0
	applymovement LOCALID_BRINEY_R109, DewfordTown_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_GARBAGEFLAG
	addobject LOCALID_BOAT_R109
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateportDeliverGoods
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateport
	closemessage
	copyvar VAR_GARBAGEVAR, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109
	copyobjectxytoperm LOCALID_BRINEY_R109
	release
	end

DewfordTown_EventScript_LandedSlateportDeliverGoods::
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_LandedSlateport::
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

DewfordTown_Movement_SailToPetalburg:
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_SailToSlateport:
	walk_right
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_PlayerBoardBoat:
	walk_right
	walk_up
	step_end

DewfordTown_Movement_ExitBoatPetalburg:
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_ExitBoatSlateport:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

DewfordTown_Movement_BrineyBoardBoat:
	walk_up
	step_end

DewfordTown_Movement_BrineyExitBoat:
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
	end

DewfordTown_EventScript_ConfirmTrendyPhrase::
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_RejectTrendyPhrase::
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
	end

DewfordTown_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_CancelNewTrendyPhrase::
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_PhraseNotTrendyEnough::
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_TinyIslandCommunity:
	.string "{JPN}ムロタウンは ちいさな\n"
	.string "{JPN}しまの コミュニティだよ.\l"
	.string "{JPN}なにかが りゅうこうすると\lみんな すぐに とびつくんだ.$"

DewfordTown_Text_TownSign:
	.string "{JPN}ムロタウンタウン\n"
	.string "{JPN}あおいうみの ちいさなしま$"

DewfordTown_Text_GymSign:
	.string "{JPN}ムロタウンタウン ポケモンジム\n"
	.string "{JPN}ジムリーダー: トウキ\l"
	.string "{JPN}かくとうの おおなみ!$"

DewfordTown_Text_HallSign:
	.string "{JPN}ムロタウンホール\n"
	.string "{JPN}みんなの じょうほう こうかんじょ!$"

Route104_Text_LandedInDewfordDeliverLetter:
	.string "{JPN}ミスター ハギろうじん: おーい!\n"
	.string "{JPN}ムロタウンに つついたぞー!\p"
	.string "{JPN}さて きみは その てがみを\n"
	.string "{JPN}とどけにいくんじゃったな... ダイゴに!$"

DewfordTown_Text_SetSailBackToPetalburg:
	.string "{JPN}ミスター ハギろうじん: てがみは\n"
	.string "{JPN}とどけたのかね?\p"
	.string "{JPN}それとも ペタルブルグへ\n"
	.string "{JPN}もどるつもりかね?$"

DewfordTown_Text_PetalburgWereSettingSail2:
	.string "{JPN}ミスター ハギろうじん: ペタルブルグじゃな!\p"
	.string "{JPN}いかりを あげろー!\n"
	.string "{JPN}ピーコ, しゅっこうだ あいしいやつよ!$"

DewfordTown_Text_GoDeliverIllBeWaiting:
	.string "{JPN}ミスター ハギろうじん: それじゃあ てがみを\n"
	.string "{JPN}とどけてくるがよい. わしは まっているから.$"

DewfordTown_Text_BrineyLandedInDewford:
	.string "{JPN}ミスター ハギろうじん: おーい!\n"
	.string "{JPN}ムロタウンに つついたぞー!\p"
	.string "{JPN}いつでも また ふねを だしたく\n"
	.string "{JPN}なったら いってくれい!$"

DewfordTown_Text_WhereAreWeBound:
	.string "{JPN}ミスター ハギろうじん: おーい!\n"
	.string "{JPN}きみのためなら いつでも うみに でるぞ!\p"
	.string "{JPN}さて ともよ, どこへ いくんじゃ?$"

DewfordTown_Text_PetalburgWereSettingSail:
	.string "{JPN}ミスター ハギろうじん: ペタルブルグかね?\p"
	.string "{JPN}いかりを あげろー!\n"
	.string "{JPN}ピーコ, しゅっこうだ あいしいやつよ!$"

DewfordTown_Text_SlateportWereSettingSail:
	.string "{JPN}ミスター ハギろうじん: カイナかね?\p"
	.string "{JPN}いかりを あげろー!\n"
	.string "{JPN}ピーコ, しゅっこうだ あいしいやつよ!$"

DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
	.string "{JPN}ミスター ハギろうじん: いつでも また\n"
	.string "{JPN}ふねを だしたくなったら いってくれい!$"

DewfordTown_Text_GettingItchToFish:
	.string "{JPN}ここは ゆうめいな つりスポットなんだ.\n"
	.string "{JPN}つりを したくなってきたかい?$"

DewfordTown_Text_GiveYouOneOfMyRods:
	.string "{JPN}いいじゃないか! その きもちが\n"
	.string "{JPN}きにいったよ!\p"
	.string "{JPN}つりざおを ひとつ あげよう.$"

DewfordTown_Text_ThrowInFishingAdvice:
	.string "{JPN}それに おまけとして つりの\n"
	.string "{JPN}こつも おしえてあげよう!\p"
	.string "{JPN}まず みずに むかって\n"
	.string "{JPN}つりざおを つかうんだ.\p"
	.string "{JPN}きもちを しゅうちゅうして...\n"
	.string "{JPN}あたりが きたら つりざおを\n"
	.string "{JPN}ひくんだ.\p"
	.string "{JPN}ときには すぐに つれることも\n"
	.string "{JPN}あるが おおきな えものの ばあいは\l"
	.string "{JPN}つりざおを ひく タイミングを\l"
	.string "{JPN}あわせて ひきあげるんだ.\p"
	.string "{JPN}それに つりの れんぞくを\n"
	.string "{JPN}つづけていると いろちがいの\l"
	.string "{JPN}ポケモンに であうかもしれない.\p"
	.string "{JPN}つりの れんぞくとは やせいの\n"
	.string "{JPN}ポケモンを たおして あたらしく\l"
	.string "{JPN}つりを はじめることだ.\p"
	.string "{JPN}にげるか きぜつしてしまうと\nつりの れんぞくは とぎれるぞ!$"

DewfordTown_Text_ThatsTooBadThen:
	.string "{JPN}あ, そうなのか?\n"
	.string "{JPN}それは ざんねんだな.$"

DewfordTown_Text_HowsYourFishing:
	.string "{JPN}よー!\n"
	.string "{JPN}つりの ちょうしは どうだい?$"

DewfordTown_Text_GreatHaulInSomeBigOnes:
	.string "{JPN}そうか! それは いいな!\n"
	.string "{JPN}おおきいのを つりあげろよ!$"

DewfordTown_Text_FishingAdvice:
	.string "{JPN}おお きにするなよ!\n"
	.string "{JPN}つりの こつを おしえてやろう.\p"
	.string "{JPN}まず みずに むかって\n"
	.string "{JPN}つりざおを つかうんだ.\p"
	.string "{JPN}きもちを しゅうちゅうして...\n"
	.string "{JPN}あたりが きたら つりざおを\n"
	.string "{JPN}ひくんだ.\p"
	.string "{JPN}ときには すぐに つれることも\n"
	.string "{JPN}あるが おおきな えものの ばあいは\l"
	.string "{JPN}つりざおを ひく タイミングを\l"
	.string "{JPN}あわせて ひきあげるんだ.\p"
	.string "{JPN}それに つりの れんぞくを\n"
	.string "{JPN}つづけていると いろちがいの\l"
	.string "{JPN}ポケモンに であうかもしれない.\p"
	.string "{JPN}つりの れんぞくとは やせいの\n"
	.string "{JPN}ポケモンを たおして あたらしく\l"
	.string "{JPN}つりを はじめることだ.\p"
	.string "{JPN}にげるか きぜつしてしまうと\nつりの れんぞくは とぎれるぞ!$"

DewfordTown_Text_XIsTheBiggestHappeningThingRight:
	.string "{JPN}おれは いまどきで はやってて\n"
	.string "{JPN}トレンディなものが すきなんだ.\p"
	.string "{JPN}いつも チェックしてるぜ.\p"
	.string "{JPN}きいたか? この あたらしい\n"
	.string "{JPN}{STR_VAR_1}について?\p"
	.string "{JPN}そうだろ!\n"
	.string "{JPN}もちろん しってるよな!\p"
	.string "{JPN}つまりさ\n"
	.string "{JPN}{STR_VAR_1}って...\l"
	.string "{JPN}いちばん ホットで クールなんだ!\p"
	.string "{JPN}きみの すんでるところでも\n"
	.string "{JPN}{STR_VAR_1}が\lいちばん はやってるだろ?$"

DewfordTown_Text_TellMeWhatsNewAndIn:
	.string "{JPN}えー?\n"
	.string "{JPN}それって いまいち りゅうこうしてないの?\p"
	.string "{JPN}それじゃあ おしえてよ,\n"
	.string "{JPN}いま なにが あたらしくて いけてるの?$"

DewfordTown_Text_OfCourseIKnowAboutThat:
	.string "{JPN}えっ?\n"
	.string "{JPN}{STR_VAR_2}?\p"
	.string "{JPN}... ...\p"
	.string "{JPN}...あー... そうそう! そのとおり!\n"
	.string "{JPN}もちろん しってたよ! ずっとね!\p"
	.string "{JPN}もちろん そのことは しってるさ!\n"
	.string "{JPN}{STR_VAR_2}だろ?\p"
	.string "{JPN}そう それそれ そこにある!\n"
	.string "{JPN}{STR_VAR_2}って\l"
	.string "{JPN}さいこうに クールじゃない?\p"
	.string "{JPN}いちばん ヒップなものだよ.\n"
	.string "{JPN}おれが しらないわけないだろ?\p"
	.string "{JPN}{STR_VAR_1}...\n"
	.string "{JPN}それって もう ふるいんだよ.\p"
	.string "{JPN}いまは {STR_VAR_2}が\n"
	.string "{JPN}じだいに あってて バイタルだよ!$"

DewfordTown_Text_XHuhIThinkYIsCool:
	.string "{JPN}うーん...\n"
	.string "{JPN}{STR_VAR_2}かあ?\p"
	.string "{JPN}でも こじんてきには\n"
	.string "{JPN}{STR_VAR_1}の\l"
	.string "{JPN}ほうが ほんとうに クールだと\lおもうんだけどな.$"

DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
	.string "{JPN}もし あたらしい りゅうこうを\n"
	.string "{JPN}きいたら おしえてくれよな!$"

DewfordTown_Text_YeahDefinitionOfInRightNow:
	.string "{JPN}そうそう! そのとおりだ!\p"
	.string "{JPN}{STR_VAR_1}こそが いま\n"
	.string "{JPN}いけてるの ていぎだよな.$"
