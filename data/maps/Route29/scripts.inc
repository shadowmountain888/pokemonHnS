Route29_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "{JPN}Aボタンか Bボタンで\nひょうじを やめられるよ$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "{JPN}ポケモンは くさむらに\n"
	.string "{JPN}かくれて いるんじゃ.\lいつ とびだして くるか\nわからんのう...$"
Route29_Text_OldMan2:
	.string "{JPN}きみのこと なんかいか\n"
	.string "{JPN}みたことが あるのう\p"
	.string "{JPN}なんびきの ポケモンを\n"
	.string "{JPN}つかまえたのかな?\pポケモンの つかまえかたを\nおしえて やろうか?$"

Route29_Text_OldManExplanation:
	.string "{JPN}まず ポケモンを よわらせてから\n"
	.string "{JPN}のほうが つかまえやすいぞい\p"
	.string "{JPN}それから バッグから ボールを\n"
	.string "{JPN}なげるんじゃ! どのボールでもよい\p"
	.string "{JPN}もっと しりたければ\n"
	.string "{JPN}キキョウシティの\l"
	.string "{JPN}トレーナーズスクールに いけ!\p"
	.string "{JPN}そこの せいとたちは\nポケモンの ことを よく しっとるぞ$"

Route29_Text_OldManDeclined:
	.string "{JPN}そうか それなら いいじゃろう\p"
	.string "{JPN}いろんな ルートを まわって\n"
	.string "{JPN}いろんな ポケモンを さがすのじゃ\p"
	.string "{JPN}ポケモンずかんで どこに いるかも\n"
	.string "{JPN}わかるからの!\p"
	.string "{JPN}もっと しりたければ\n"
	.string "{JPN}キキョウシティの\l"
	.string "{JPN}トレーナーズスクールに いけ!\p"
	.string "{JPN}せいとたちは ポケモンの ことを\nよく しっとるぞ$"

Route29_Text_Youngster:
	.string "{JPN}よお\n"
	.string "{JPN}おまえのポケモンげんき？\p"
	.string "{JPN}ポケモンがよわってきて\n"
	.string "{JPN}たたかわせたくないときは\l"
	.string "{JPN}なるべくくさむらをよけて\l"
	.string "{JPN}あるいたほうがいいよ$"
Route29_Text_Lass:
	.string "{JPN}そこにだんさがあるじゃない？\p"
	.string "{JPN}とびおりるのはこわいけど\n"
	.string "{JPN}くさむらをあるかずに\l"
	.string "{JPN}ワカバまでいけるのよね！$"
Route29_Text_Girl:
	.string "{JPN}ちょっとひとやすみしたいから\n"
	.string "{JPN}レポートかいてんだよ$"
Route29_Text_Boy_WaitingForDay:
	.string "{JPN}ひるしかでないポケモン\n"
	.string "{JPN}つかまえるためここでまってんだ$"
Route29_Text_Boy_WaitingForNight:
	.string "{JPN}よるしかでないポケモン\n"
	.string "{JPN}つかまえるためここでまってんだ$"
Route29_Text_MeetTuscany:
	.string "{JPN}タスカニー: はじめまして ですわね?\p"
	.string "{JPN}わたくし ようびきょうだいの\n"
	.string "{JPN}タスカニーと もうします\p"
	.string "{JPN}わたくしの すきな ようびを\n"
	.string "{JPN}あてて くださったら\lプレゼントを さしあげますわ$"

Route29_Text_TuscanyNope:
	.string "{JPN}ざんねん! ちがいますわ!$"

Route29_Text_TuscanyGivesGift:
	.string "{JPN}せいかい! はじめまして の\n"
	.string "{JPN}しるしに シルクのスカーフを\l"
	.string "{JPN}さしあげますわ$"

Route29_Text_TuscanyGaveGift:
	.string "{JPN}タスカニー: とても すてきでしょう?\p"
	.string "{JPN}ノーマルタイプの わざの\n"
	.string "{JPN}いりょくが あがりますのよ\p"
	.string "{JPN}きっと やくに たちますわ$"
	.string ""

Route29_Text_TuscanyTuesday:
	.string "{JPN}タスカニー: わたくしの あね\n"
	.string "{JPN}モニカには あったこと ありまして?\p"
	.string "{JPN}おとうと の ウェズリーは\n"
	.string "{JPN}いかがかしら?\p"
	.string "{JPN}わたくしは 7にん きょうだいの\n3ばんめ ですの$"

Route29_Text_Sign1:
	.string "{JPN}29ばん どうろ\p"
	.string "{JPN}ヨシノシティ - ワカバタウン$"

