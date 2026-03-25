@ NOTE: Route 109's sail to Dewford script references local IDs from Dewford's map.
@  These are labeled in DewfordTown/scripts.inc

Route109_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

Route109_EventScript_StartDepartForDewford::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE109, 0
	applymovement LOCALID_BRINEY_R109, Route109_Movement_BrineyEnterBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_R109
	switch VAR_FACING
	case DIR_SOUTH, Route109_EventScript_EnterBoatSouth
	case DIR_WEST, Route109_EventScript_EnterBoatWest
	case DIR_EAST, Route109_EventScript_EnterBoatEast
	end

Route109_EventScript_EnterBoatSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerEnterBoatSouth
	waitmovement 0
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_EnterBoatEast::
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerEnterBoatEast
	waitmovement 0
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_EnterBoatWest::
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerEnterBoatWest
	waitmovement 0
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_DoSailToDewford::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_R109, Route109_Movement_SailToDewford
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_SailToDewford
	waitmovement 0
	delay 50
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerExitBoat
	waitmovement 0
	addobject LOCALID_BOAT_DEWFORD
	clearflag FLAG_GARBAGEFLAG
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
	addobject LOCALID_BRINEY_DEWFORD
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_BRINEY_DEWFORD, Route109_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	hideobjectat LOCALID_BOAT_R109, MAP_ROUTE109
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_GARBAGEVAR, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
	release
	end

Route109_Movement_SailToDewford:
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_fast_down
	walk_fast_down
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
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

Route109_Movement_PlayerEnterBoatSouth:
	walk_down
	walk_down
	step_end

Route109_Movement_PlayerExitBoat:
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_right
	step_end

Route109_Movement_PlayerEnterBoatEast:
	walk_right
	walk_down
	step_end

Route109_Movement_PlayerEnterBoatWest:
	walk_left
	walk_down
	step_end

Route109_Movement_BrineyEnterBoat:
	walk_down
	step_end

Route109_Movement_BrineyExitBoat:
	walk_down
	walk_in_place_faster_left
	step_end

Route109_EventScript_MrBriney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route109_EventScript_HaveNotDeliveredDevonGood
	goto Route109_EventScript_DeliveredDevonGoods
	end

Route109_EventScript_HaveNotDeliveredDevonGood::
	message Route109_Text_BrineySailToDewfordQuestion
	msgbox Route109_Text_BrineySailToDewfordQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route109_EventScript_StayHere
	goto Route109_EventScript_SailToDewford
	end

Route109_EventScript_DeliveredDevonGoods::
	message Route109_Text_BrineyWhereAreWeBound
	waitmessage
	multichoicedefault 21, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route109_EventScript_SailToDewford
	case 1, Route109_EventScript_ChoseNotToSail
	case MULTI_B_PRESSED, Route109_EventScript_ChoseNotToSail
	end

Route109_EventScript_SailToDewford::
	msgbox Route109_Text_BrineyDewfordItIs, MSGBOX_DEFAULT
	closemessage
	goto Route109_EventScript_StartDepartForDewford
	end

Route109_EventScript_StayHere::
	msgbox Route109_Text_BrineyDeliverDevonGoods, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_ChoseNotToSail::
	msgbox Route109_Text_BrineyTellMeWhenYouNeedToSail, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_SeashoreHouseGirl::
	msgbox Route109_Text_ChillAtMyPapasSpot, MSGBOX_NPC
	end

Route109_EventScript_SandCastleBoy::
	lock
	faceplayer
	msgbox Route109_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route109_EventScript_SoftSandGirl::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_AlreadyReceivedSoftSand
	msgbox Route109_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_SOFT_SAND
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_RECEIVED_SOFT_SAND
	release
	end

Route109_EventScript_AlreadyReceivedSoftSand::
	msgbox Route109_Text_WereGoingToMakeBigCastle, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route109_EventScript_Woman::
	msgbox Route109_Text_LittleKidsDartAround, MSGBOX_NPC
	end

Route109_EventScript_OldMan::
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
	end

Route109_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox Route109_Text_ZigzagoonCry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route109_EventScript_SeashoreHouseSign::
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
	end

Route109_EventScript_TrainerTipsSign::
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
	end

Route109_EventScript_David::
	trainerbattle_single TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated
	msgbox Route109_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Alice::
	trainerbattle_single TRAINER_ALICE, Route109_Text_AliceIntro, Route109_Text_AliceDefeated
	msgbox Route109_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated
	msgbox Route109_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Edmond::
	trainerbattle_single TRAINER_EDMOND, Route109_Text_EdmondIntro, Route109_Text_EdmondDefeated
	msgbox Route109_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Route109_EventScript_RickyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_RickyRematch
	msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_RickyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route109_Text_RickyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICKY_1
	release
	end

Route109_EventScript_RickyRematch::
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_RickyRematchIntro, Route109_Text_RickyRematchDefeated
	msgbox Route109_Text_RickyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Route109_EventScript_LolaRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_LolaRematch
	msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_LolaRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route109_Text_LolaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA_1
	release
	end

Route109_EventScript_LolaRematch::
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_LolaRematchIntro, Route109_Text_LolaRematchDefeated
	msgbox Route109_Text_LolaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Austina::
	trainerbattle_single TRAINER_CODY, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated
	msgbox Route109_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Gwen::
	trainerbattle_single TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated
	msgbox Route109_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER, Route109_Text_CarterIntro, Route109_Text_CarterDefeated
	msgbox Route109_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Paul::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_PaulIntro, Route109_Text_PaulDefeated, Route109_Text_PaulNotEnoughPokemon
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Mel::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_MelIntro, Route109_Text_MelDefeated, Route109_Text_MelNotEnoughPokemon
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Chandler::
	trainerbattle_single TRAINER_GRUNT_11, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated
	msgbox Route109_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Hailey::
	trainerbattle_single TRAINER_BUGSY_2, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Elijah::
	trainerbattle_single TRAINER_MARVIN, Route109_Text_ElijahIntro, Route109_Text_ElijahDefeated
	msgbox Route109_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Text_BrineyLandedInSlateportDeliverGoods:
	.string "{JPN}ハギろうじんじいさん: おう!\n"
	.string "{JPN}カイナシティに ついたぞい!\p"
	.string "{JPN}キャプテン クスノキの ところに\n"
	.string "{JPN}デボンのにもつを とどけるんじゃろ?$"

Route109_Text_BrineySailToDewfordQuestion:
	.string "{JPN}ハギろうじんじいさん: デボンのにもつを\n"
	.string "{JPN}とどけるんじゃなかったかのう?\p"
	.string "{JPN}ムロタウンに もどるかい?$"
	.string ""

Route109_Text_BrineyDewfordItIs:
	.string "{JPN}ハギろうじんじいさん: ムロタウンじゃな!\p"
	.string "{JPN}いかりを あげるぞい!\n"
	.string "{JPN}ピーコちゃん しゅっぱつじゃ!$"

Route109_Text_BrineyDeliverDevonGoods:
	.string "{JPN}ハギろうじんじいさん: それなら\n"
	.string "{JPN}デボンのにもつを とどけておくれ\lわしは ここで まっとるからのう$"

DewfordTown_Text_BrineyLandedInSlateport:
	.string "{JPN}ハギろうじんじいさん: おう!\n"
	.string "{JPN}カイナシティに ついたぞい!\p"
	.string "{JPN}また ふねに のりたくなったら\n"
	.string "{JPN}いつでも こえを かけておくれ!$"

Route109_Text_BrineyWhereAreWeBound:
	.string "{JPN}ハギろうじんじいさん: おう!\n"
	.string "{JPN}おまえさんの ためなら\l"
	.string "{JPN}いつでも うみに でるぞい!\pさあ ともよ どこに いくかのう?$"

Route109_Text_BrineyTellMeWhenYouNeedToSail:
	.string "{JPN}ハギろうじんじいさん: また ふねに\n"
	.string "{JPN}のりたくなったら いつでも\lこえを かけておくれ!$"

Route109_Text_ChillAtMyPapasSpot:
	.string "{JPN}よう トレーナー!\n"
	.string "{JPN}あつくて たまらないときも\l"
	.string "{JPN}つめたく なっちゃったときも\l"
	.string "{JPN}とうちゃんの みせで やすんでこう!$"

Route109_Text_LittleKidsDartAround:
	.string "{JPN}ちいさなこどもたちって\n"
	.string "{JPN}すばやくはしりまわるのね...\p"
	.string "{JPN}ちょっとでもめをはなしたら\n"
	.string "{JPN}だめなのよ.とってもつかれるわ.\p"
	.string "{JPN}うちのこたちはポケモンと\nいっしょだから\nだいじょうぶだとおもうけど...$"
Route109_Text_SandCastleTakingLongTime:
	.string "{JPN}すなの おしろづくり\n"
	.string "{JPN}じかんが かかるなあ$"

Route109_Text_YouCanHaveThis:
	.string "{JPN}これ あげる!$"

Route109_Text_WereGoingToMakeBigCastle:
	.string "{JPN}はまべの すなを ぜんぶ あつめて\n"
	.string "{JPN}おおきな おしろを つくるんだ!\p"
	.string "{JPN}そして ぼくたちが おうさまと\n"
	.string "{JPN}おうひさまに なるんだよ\p"
	.string "{JPN}きみは けらいに してあげる$"

Route109_Text_ZigzagoonPicksUpLitter:
	.string "{JPN}このあたりのみずは\n"
	.string "{JPN}きれいなのよ.\p"
	.string "{JPN}でも ときどきジグザグマに\n"
	.string "{JPN}かいがんのごみをひろわせてるの.\p"
	.string "{JPN}よごれたみずがあめになって\n"
	.string "{JPN}かわにまざって\n"
	.string "{JPN}のみものになるでしょ...\pうみをよごしたら\nけっきょくじぶんたちに\nかえってくるのよ.$"

Route109_Text_ZigzagoonCry:
	.string "{JPN}ジグザグマ: ググウ?$"

Route109_Text_SeashoreHouseSign:
	.string "{JPN}なぎさハウス\p"
	.string "{JPN}あつい すなはまで あつい しょうぶ!\n"
	.string "{JPN}あつい トレーナーの ための ばしょ!$"

Route109_Text_TrainerTipsSign:
	.string "{JPN}トレーナーのこつ\p"
	.string "{JPN}おなじ レベルの ポケモンでも\n"
	.string "{JPN}のうりょくが ちがうことがある\p"
	.string "{JPN}トレーナーに そだてられた ポケモンは\n"
	.string "{JPN}やせいより つよくなると いわれている$"
