.set LOCALID_MOVE_DELETER, 1
.set LOCALID_MOVE_RELEARNER, 2

BlackthornCity_House3_MapScripts::
	.byte 0

BlackthornCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox BlackthornCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "{JPN}うーん..\nああわしはわざわすれじじいじゃ\pポケモンのわざを\nわすれさせることができる\pわすれさせてほしいのか？$"
BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "{JPN}どのポケモンにするんだ？$"
BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "{JPN}ふむ..そして\n"
	.string "{JPN}どのわざをわすれさせるんだ？$"
BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{JPN}なぬ？そのポケモンはひとつしか\n"
	.string "{JPN}わざをおぼえとらんよ？$"
BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "{JPN}ふむ..そして\n"
	.string "{JPN}どのわざをわすれさせるんだ？$"
BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "{JPN}だいせいこうだ！\p"
	.string "{JPN}きみのポケモンは\n"
	.string "{JPN}{STR_VAR_1}をわすれおったぞ！$"
BlackthornCity_MoveDeletersHouse_Text_ComeAgain:
	.string "{JPN}わざをわすれさせたくなったら\n"
	.string "{JPN}わしのことおもいだしておくれよ！$"
BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "{JPN}なぬ？それはタマゴだからな\n"
	.string "{JPN}なにもわざをおぼえとらんよ..$"
BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "{JPN}ほほう！\p{STR_VAR_1}はなみのりを\nわすれたがらないようじゃな$"
BlackthornCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	faceplayer
	specialvar VAR_RESULT, IsRandomMovesActivated
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer
	goto_if_set FLAG_TEMP_1, BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp:
	.string "{JPN}ごめん..ちからになれないよ$"
BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "{JPN}ぼくはわざおしえおやじだ\pポケモンがおぼえるわざを\nすべてしっていて\lおしえることができるんだ\pきみのポケモンにも\nわざをおしえられるよ\pハートのウロコをくれれば\nやってあげよう$"
BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "{JPN}ピキーン！\n"
	.string "{JPN}それはハートのウロコ！\p"
	.string "{JPN}わざをおもいださせていいんだね？$"
BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "{JPN}どのポケモンにするの？$"
BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "{JPN}どのポケモンに\n"
	.string "{JPN}わざをおぼえさせるのじゃ？$"
BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "{JPN}ごめん..\pそのポケモンにおしえられる\nわざはないみたいだ$"
BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{JPN}{STR_VAR_1}はおれいに\n"
	.string "{JPN}ハートのウロコを1まいあげた！$"
BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "{JPN}おもいださせたいわざがあったら\n"
	.string "{JPN}ハートのウロコもってきて！$"
BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "{JPN}えっ？タマゴにおしえられる\nわざなんてひとつもないよ$"