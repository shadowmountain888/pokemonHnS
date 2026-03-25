.set LOCALID_AZALEA_TOWN_KURT_BEFORE, 1
.set LOCALID_AZALEA_TOWN_KURT, 3

AzaleaTown_KurtsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
	end

AzaleaTown_KurtsHouse_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
	.2byte 0

AzaleaTown_KurtsHouse_EventScript_KurtBefore::
	lock
	faceplayer
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	setvar VAR_AZALEA_TOWN_STATE, 2
	release
	end

AzaleaTown_KurtsHouse_EventScript_PlayerMove::
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl2::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5

	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl3::
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl4::
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_Girl5::
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_FAST_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	setvar VAR_AZALEA_TOWN_STATE, 4
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
	return

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
	msgbox KurtsHouse_Text_KurtAskYouHaveAnApricorn, MSGBOX_DEFAULT
	closemessage
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
AzaleaTown_KurtsHouse_EventScript_Kurt2::
	multichoice 20, 0, MULTI_KURT_BALLS, FALSE
	switch VAR_RESULT
	case 0, AzaleaTown_KurtsHouse_EventScript_Kurt_Love
	case 1, AzaleaTown_KurtsHouse_EventScript_Kurt_Lure
	case 2, AzaleaTown_KurtsHouse_EventScript_Kurt_Friend
	case 3, AzaleaTown_KurtsHouse_EventScript_Kurt_Heavy
	case 4, AzaleaTown_KurtsHouse_EventScript_Kurt_Moon
	case 5, AzaleaTown_KurtsHouse_EventScript_Kurt_Fast
	case 6, AzaleaTown_KurtsHouse_EventScript_Kurt_Level
	case 7, AzaleaTown_KurtsHouse_EventScript_KurtCancel
	case MULTI_B_PRESSED, AzaleaTown_KurtsHouse_EventScript_KurtCancel
	closemessage

AzaleaTown_KurtsHouse_EventScript_Kurt_Love::
	closemessage
	bufferitemname STR_VAR_1, ITEM_PECHA_BERRY
	checkitem ITEM_PECHA_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_LOVE_BALL, 5
	removeitem ITEM_PECHA_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Lure::
	closemessage
	bufferitemname STR_VAR_1, ITEM_RAWST_BERRY
	checkitem ITEM_RAWST_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_LURE_BALL, 5
	removeitem ITEM_RAWST_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Friend::
	closemessage
	bufferitemname STR_VAR_1, ITEM_CHERI_BERRY
	checkitem ITEM_CHERI_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_FRIEND_BALL, 5
	removeitem ITEM_CHERI_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Heavy::
	closemessage
	bufferitemname STR_VAR_1, ITEM_ORAN_BERRY
	checkitem ITEM_ORAN_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_HEAVY_BALL, 5
	removeitem ITEM_ORAN_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Moon::
	closemessage
	bufferitemname STR_VAR_1, ITEM_CHESTO_BERRY
	checkitem ITEM_CHESTO_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_MOON_BALL, 5
	removeitem ITEM_CHESTO_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Fast::
	closemessage
	bufferitemname STR_VAR_1, ITEM_ASPEAR_BERRY
	checkitem ITEM_ASPEAR_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_FAST_BALL, 5
	removeitem ITEM_ASPEAR_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Level::
	closemessage
	bufferitemname STR_VAR_1, ITEM_PERSIM_BERRY
	checkitem ITEM_PERSIM_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_LEVEL_BALL, 5
	removeitem ITEM_PERSIM_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_DontHaveBerry::
	msgbox KurtsHouse_Text_KurtThatsALetdown, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
	
AzaleaTown_KurtsHouse_EventScript_KurtCancel::
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GS_BALL
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	waitse
	playse SE_M_PETAL_DANCE
	waitse
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
	waitmovement 0
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 8
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
KurtsHouse_Text_BallAnyway:
	.string "{JPN}とにかく\nボールをつくってあげようか？$"
AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	closemessage
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	closemessage
	end

AzaleaTownKurt_Movement_Look_Around:
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	delay_8
	face_left
	step_end

AzaleaTownKurt_Movement_Making_Ball:
	face_up
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	step_end

AzaleaTown_KurtsHouse_Movement_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KurtsHouse_Text_KurtGetStarted:
	.string "{JPN}ガンテツさっそくはじめるぞい！$"
KurtsHouse_Text_KurtMakingBallsMustWait:
	.string "{JPN}おうおまえはだれや？\p"
	.string "{JPN}そうか{PLAYER}いうんか\n"
	.string "{JPN}ボールをつくってほしいんか？\l"
	.string "{JPN}わるいがそれどころちゃうんや\p"
	.string "{JPN}ロケットだんしってるか？\n"
	.string "{JPN}いやしらなくてもええ\l"
	.string "{JPN}はなしをすすめるぞ\p"
	.string "{JPN}ロケットだんいうのは\n"
	.string "{JPN}ポケモンをむりやりわるさにつかう\l"
	.string "{JPN}ろくでもないれんちゅうや\p"
	.string "{JPN}3ねんまえに\n"
	.string "{JPN}かいさんしたはずなんやが..\p"
	.string "{JPN}とにかくそいつらが\n"
	.string "{JPN}いどでヤドンのシッポを\l"
	.string "{JPN}きってはうりさばいとるんや\p"
	.string "{JPN}だからわしがいって\n"
	.string "{JPN}ちとこらしめたるんや！\p"
	.string "{JPN}よーし！まってろヤドン！\n"
	.string "{JPN}おとこガンテツがたすけたるぞ！$"
KurtsHouse_Text_KurtHonoredToMakeBalls:
	.string "{JPN}ガンテツおお{PLAYER}よ！\pイドのいどでのかつやくぶり\nまさにヒーローじゃったな！\pきにいったぞい！\nおまえのようなトレーナーに\nボールをつくれるとは\pこうえいじゃ！\nこれしかないがもっていけ！$"
KurtsHouse_Text_KurtBallsFromApricorns:
	.string "{JPN}わしはぼんぐりつかって\n"
	.string "{JPN}とくせいのボールをつくっとる\p"
	.string "{JPN}そこいらのぼんぐりのきをしらべ\n"
	.string "{JPN}みをあつめてくるとええぞ\l"
	.string "{JPN}そしたらわしがボールつくったる$"
KurtsHouse_Text_KurtAskYouHaveAnApricorn:
	.string "{JPN}おおっ\n"
	.string "{JPN}ぼんぐりもっとるやないか！\l"
	.string "{JPN}よっしゃボールつくったるわ！$"
KurtsHouse_Text_KurtThatsALetdown:
	.string "{JPN}ガンテツ{STR_VAR_1}が5こないぞい！$"
KurtsHouse_Text_KurtJustFinishedYourBall:
	.string "{JPN}おお{PLAYER}か\n"
	.string "{JPN}いまなボールができたばかりや\l"
	.string "{JPN}もっていくがええぞ！$"
KurtsHouse_Text_KurtTurnedOutGreat:
	.string "{JPN}かいしんのできじゃ！\p"
	.string "{JPN}それでつかまえられるかどうか\n"
	.string "{JPN}ポケモンとしょうぶしてみい！$"
KurtsHouse_Text_KurtWhatIsThat:
	.string "{JPN}な..なんじゃそれは？\pみたことがないのう..\pモンスターボールのようじゃが\nべつのもののようじゃ..\pちょっとしらべてみよう$"
KurtsHouse_Text_KurtImCheckingItNow:
	.string "{JPN}いましらべておるところじゃ$"
KurtsHouse_Text_KurtAhHaISee:
	.string "{JPN}あーはー！わかったぞい！それで..$"
KurtsHouse_Text_KurtThisBallStartedToShake:
	.string "{JPN}{PLAYER}よ！\pこのボールがしらべとるあいだに\nゆれはじめたんじゃ！\pなにかあるにちがいない！$"
KurtsHouse_Text_Kurt_Whatwasthat:
	.string "{JPN}いまのおとはなんじゃ！？\nそとにようすをみにいこう！$"
KurtsHouse_Text_GranddaughterSlowpokeGone:
	.string "{JPN}ヤドンいなくなっちゃった..\n"
	.string "{JPN}どうしよう..\l"
	.string "{JPN}わるいひとにつれさられたの？$"
KurtsHouse_Text_GranddaughterLonely:
	.string "{JPN}おじいちゃんどこいったの..？\n"
	.string "{JPN}あたしさみしいよう..$"
KurtsHouse_Text_GranddaughterSlowpokeBack:
	.string "{JPN}おとうさんにもらった\n"
	.string "{JPN}あたしのヤドンかえってきた！\l"
	.string "{JPN}シッポもまたはえてくるの！$"
KurtsHouse_Text_GranddaughterDad:
	.string "{JPN}おとうさんシルフってかいしゃで\n"
	.string "{JPN}あたらしいモンスターボールの\l"
	.string "{JPN}けんきゅうしてるの\p"
	.string "{JPN}そのあいだあたしは\n"
	.string "{JPN}おじいちゃんとヤドンとおるすばん$"
KurtsHouse_Text_GranddaughterHelp:
	.string "{JPN}わたしもおじいちゃんの\nおてつだいをするの！\pいいボールをつくるから\nまっててね！$"
KurtsHouse_Text_GranddaughterFun:
	.string "{JPN}ボールづくりはたのしいよ！$"
KurtsHouse_Text_GranddaughterSound:
	.string "{JPN}いまのおとって\nウバメのもりからかしら？？？？$"
KurtsHouse_Text_Forest:
	.string "{JPN}ウバメのもりはもうみにいったか？\nなんだかざわざわしているぞ$"
KurtsHouse_Text_Slowpoke:
	.string "{JPN}...やあん？$"
KurtsHouse_Text_OakPhoto:
	.string "{JPN}..わかいころのオーキドはかせ？$"
KurtsHouse_Text_CelebiStatue:
	.string "{JPN}もりのかみさまをまつってある$"