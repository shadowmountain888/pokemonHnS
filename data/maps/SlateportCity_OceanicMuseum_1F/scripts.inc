.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_ITEM_GARBAGEFLAG
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "{JPN}かいようはくぶつかんへ\n"
	.string "{JPN}ようこそ.\p"
	.string "{JPN}にゅうじょうりょうは 50えん\nです.\nにゅうじょうしますか?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "{JPN}ごゆっくり おたのしみ\nください.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "{JPN}あれ? もうしわけありませんが\n"
	.string "{JPN}おかねが たりないようですね.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "{JPN}あれ? さっき はいっていった\n"
	.string "{JPN}グループの かたですね?\p"
	.string "{JPN}あなただけ おくれてますよ.\n"
	.string "{JPN}はやく みんなに おいつかないと!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "{JPN}われら アクアだんは\n"
	.string "{JPN}みんなの ためにいるのだ!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "{JPN}ここに あつまれって\n"
	.string "{JPN}いわれたから きたけど...\p"
	.string "{JPN}ボスが いないじゃないか!$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "{JPN}ここの ものを ぬすんだら\n"
	.string "{JPN}かねもちに なれるかな?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "{JPN}ここで おぼえたことを\n"
	.string "{JPN}わるいことに つかえるかも...$"
SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "{JPN}カナズミで しっぱいしなければ\n"
	.string "{JPN}こんなところに いなかったのに!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "{JPN}50えん なくて うけつけの\n"
	.string "{JPN}ひとを とおすのに\nじかんが かかったよ.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "{JPN}うみのことを べんきょうして\n"
	.string "{JPN}バトルに いかしたいんだ.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "{JPN}うみを みると\n"
	.string "{JPN}ドキドキしちゃう!\p"
	.string "{JPN}わたしにとって クスノキかんちょうは\n"
	.string "{JPN}あこがれの ひとなの!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "{JPN}うみは おわりなく ひろくて\n"
	.string "{JPN}そこも しれない...\p"
	.string "{JPN}まだ しらない ポケモンが\n"
	.string "{JPN}たくさん いるはずだ$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "{JPN}うみの ポケモンが ほしいなあ.\p"
	.string "{JPN}だっこしたら つめたくて\n"
	.string "{JPN}きもちよさそう.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "{JPN}ひいい!\n"
	.string "{JPN}なんで きみが ここに!?\p"
	.string "{JPN}ぼく? まえに きみに\n"
	.string "{JPN}やられた アクアだんの\l"
	.string "{JPN}メンバーだよ おぼえてない?\l"
	.string "{JPN}カナシダトンネルで!\p"
	.string "{JPN}これを とって!\nゆるして くれよ!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "{JPN}その わざマシンは ぼくより\n"
	.string "{JPN}きみの ほうが にあうよ.\p"
	.string "{JPN}もう にどと あいたくないな!\n"
	.string "{JPN}ワハハハ!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "{JPN}えーん!\n"
	.string "{JPN}これを とって にがして よ!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "{JPN}ガラスの ようきの なかで\n"
	.string "{JPN}あおい えきたいが まわってる.\p"
	.string "{JPN}かぜを つかって じんこうてきに\n"
	.string "{JPN}うずしおを つくる じっけんです$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "{JPN}ガラスの ようきの なかで\n"
	.string "{JPN}あかい ボールが あがったり\n"
	.string "{JPN}さがったり している.\p"
	.string "{JPN}ボールの ふりょくを りようして\nたきを さいげんする じっけんです$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "{JPN}かいていの つちの サンプルだ.\p"
	.string "{JPN}ながい あいだに いきものの\n"
	.string "{JPN}しがいが かいていに つもって\l"
	.string "{JPN}ちそうを つくります.\p"
	.string "{JPN}この ちそうを ちょうさすると\n"
	.string "{JPN}むかしのことが わかります$"
	.string ""

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "{JPN}はまべの すなの サンプルだ.\p"
	.string "{JPN}やまの いしが かわで ながされ\n"
	.string "{JPN}けずられて こまかく なります.\p"
	.string "{JPN}それが つぶになって はまべの\n"
	.string "{JPN}すなと なるのです$"
	.string ""

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "{JPN}かいよう ミニちしき 1\n"
	.string "{JPN}なぜ うみは あおいの?\p"
	.string "{JPN}ひかりは いろいろな いろで\n"
	.string "{JPN}できています.\p"
	.string "{JPN}ひかりが みずを とおるとき\n"
	.string "{JPN}たいていの いろは きえます.\p"
	.string "{JPN}でも あおい ひかりだけは のこり\nうみが あおく みえるのです$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "{JPN}かいよう ミニちしき 2\n"
	.string "{JPN}なぜ うみは しょっぱいの?\p"
	.string "{JPN}かいすいには ナトリウムと\n"
	.string "{JPN}えんその イオンが とけています.\p"
	.string "{JPN}これらの イオンは いわから\n"
	.string "{JPN}でてきて あめに はこばれて\l"
	.string "{JPN}うみへ ながれます.\p"
	.string "{JPN}とけた しおの のうどが たかくて\nうみが しょっぱいのです$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "{JPN}うみのミニちしき 3\n"
	.string "{JPN}うみと りくちでは どちらが\n"
	.string "{JPN}ひろいでしょうか?\p"
	.string "{JPN}ちきゅうの やく70%は うみで\n"
	.string "{JPN}のこりが りくちです.\p"
	.string "{JPN}つまり うみは りくちの\n2ばいいじょうの おおきさなのです.$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "{JPN}なみうった もようの ある\n"
	.string "{JPN}かせきだ.\p"
	.string "{JPN}かいていの つちが しおの\n"
	.string "{JPN}ながれで けずられます.\p"
	.string "{JPN}ながれる かいすいが つちに\n"
	.string "{JPN}ちいさな やまと たにを つけます.\p"
	.string "{JPN}この つちが かせきになったものを\nリップルマークと よびます$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "{JPN}ガラスの なかで へんな きかいが\n"
	.string "{JPN}まわって いる\p"
	.string "{JPN}なにかの ふかさを はかる\n"
	.string "{JPN}きかいかな...$"
