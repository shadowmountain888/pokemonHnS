.set LOCALID_ROUTE24_WOMAN, 4
.set LOCALID_ROUTE24_MAN, 3
.set LOCALID_ROUTE24_GRUNT, 1

Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 10, 28
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 10, 29
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 FLAG_HIDE_CERULEAN_CAPE_ROCKET, Common_Movement_QuestionMark
	delay 50
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "{JPN}おい こぞう! おれは ロケットだん\n"
	.string "{JPN}みたいな やつ だぜ!\p"
	.string "{JPN}べつの くにから きた \n"
	.string "{JPN}トレーナー ばんいち だ!\p"
	.string "{JPN}かんがえた でんき とめれば\n"
	.string "{JPN}ここの ひとたち おおあわて!\p"
	.string "{JPN}ひみつの にんむ だから\n"
	.string "{JPN}おしえて やらない!\p"
	.string "{JPN}でも! おまえに かてば\n"
	.string "{JPN}おとこ として ひみつを\l"
	.string "{JPN}おしえて やる.\p"
	.string "{JPN}おい こぞう! バトル はじまり\nだ!$"

Route24_Text_RocketBeaten:
	.string "{JPN}ぎゃー! いや いや いや \n"
	.string "{JPN}しんじられない!\p"
	.string "{JPN}とても つよい だな! おれは\n"
	.string "{JPN}おまえに あわない!$"

Route24_Text_RocketAfter:
	.string "{JPN}よし.ひみつ おしえて やるか?\n"
	.string "{JPN}マシンぶひん ぬすんで \l"
	.string "{JPN}ハナダの ジムに かくした.\p"
	.string "{JPN}みずの なかに いれた.ジムの\n"
	.string "{JPN}ちゅうおうの みずを さがせ.\p"
	.string "{JPN}でも おれを わすれるな!\n"
	.string "{JPN}ロケットだん かならず\n"
	.string "{JPN}かたきを とる.\p"
	.string "{JPN}ジョウトから くる おれの\n"
	.string "{JPN}なかま そうだ.ふくしゅう\l"
	.string "{JPN}する つもりだ.$"

Route24_Text_RocketDisappears:
	.string "{JPN}...\p"
	.string "{JPN}なんですって? ロケットだんが\n"
	.string "{JPN}ばいばい あ ごーごー?\l"
	.string "{JPN}こわれたって いうの?\p"
	.string "{JPN}あーあ! これからぼくは\n"
	.string "{JPN}なにを すればいいのかな?$"



Route24_Text_Woman:
	.string "{JPN}すてきな ながめ ですね.$"
Route24_Text_Man:
	.string "{JPN}いちにちじゅう ここに いても\nいいな.$"

Route24_Text_WomanRocket:
	.string "{JPN}だれも わたしを おさない!$"
Route24_Text_ManRocket:
	.string "{JPN}だれも ぼくの かのじょを\nおさない!$"

Route24_Text_WomanAfterRocket:
	.string "{JPN}あれは なんだった の?$"
Route24_Text_ManAfterRocket:
	.string "{JPN}あれは ロケットだん だった?$"
